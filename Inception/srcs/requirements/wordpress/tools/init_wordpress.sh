#!/bin/bash

# quitte des qu'une commande echoue
set -e

# on verifie que tout le necessaire est defini
# Les mots de passe DB sont définis dans les variables d'environnement
if [ -z "$DB_NAME" ] || [ -z "$DB_USER" ] || [ -z "$DB_PASSWORD" ] || [ -z "$DOMAIN_NAME" ] || [ -z "$WP_TITLE" ] || [ -z "$WP_ADMIN_USER" ] || [ -z "$WP_ADMIN_EMAIL" ] || [ -z "$WP_ADMIN_PASSWORD" ] || [ -z "$WP_USER_NAME" ] || [ -z "$WP_USER_EMAIL" ] || [ -z "$WP_USER_PASSWORD" ]; then
    echo "Error: Required environment variables DB_NAME, DB_USER, DB_PASSWORD, DOMAIN_NAME, WP_TITLE, WP_ADMIN_USER, WP_ADMIN_EMAIL, WP_ADMIN_PASSWORD, WP_USER_NAME, WP_USER_EMAIL, or WP_USER_PASSWORD are not set."
    exit 1
fi

# On construit l'url du site
WP_URL="https://${DOMAIN_NAME}"

# Preparation de PHP-FPM, on cree de directory et donne les droits a www-data, l'utilisateur standard
mkdir -p /run/php
chown www-data:www-data /run/php

# Test connexion a la base de donnees
# avec mysqladmin ping on teste si mariadb est prete
# -h mariadb pour le nom du service docker
# on ne veut pas que wordpress demarre avant la db
echo "Testing database connection..."
while ! mysqladmin ping -h"mariadb" -u"$DB_USER" -p"$DB_PASSWORD" --silent; do
    echo "Database connection test failed. Retrying..."
    sleep 2
done
echo "Database connection successful!"

# installe WordPress si pas present
if [ ! -f /var/www/html/wp-config.php ]; then
    echo "Setting up WordPress..."
	# telecharge wordpress (--allow root obligatoire en docker sinon refus)
    wp core download    --path=/var/www/html --allow-root

	# configuration de la connexion a la base. Cree wp-config.php, qui contient les acces a la db et la config wordpress
    wp config create    --path=/var/www/html --dbname=$DB_NAME --dbuser=$DB_USER --dbpass=$DB_PASSWORD --dbhost=mariadb --allow-root
	
	# installation du site. core install installe WP, cree tables db, admin, titre du site 
    wp core install     --path=/var/www/html --url="$WP_URL" --title="$WP_TITLE" --admin_user="$WP_ADMIN_USER" --admin_password="$WP_ADMIN_PASSWORD" --admin_email="$WP_ADMIN_EMAIL" --allow-root

	# creation de l'utilisateur secondaire
    wp user create      --path=/var/www/html "$WP_USER_NAME" "$WP_USER_EMAIL" --role=editor --user_pass="$WP_USER_PASSWORD" --allow-root

    echo "WordPress setup completed!"
else
    echo "WordPress already configured."
fi

# permissions sur les fichiers
chown -R www-data:www-data /var/www/html
chmod -R 755 /var/www/html

#configuration PHP_FPM pour ecouter sur le reseau (et non sur un socket local)
sed -i 's|^listen = .*|listen = 0.0.0.0:9000|' /etc/php/8.2/fpm/pool.d/www.conf

# lancement de PHP-FPM au premier plan (PID 1)
exec php-fpm8.2 -F