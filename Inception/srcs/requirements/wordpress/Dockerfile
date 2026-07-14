FROM debian:bookworm

# wget est un outil en ligne de commande pour telecharger des fichiers depuis internet, on va l'utiliser pour telecharger wordpress depuis son site officiel
# curl est un outil en ligne de commande pour transferer des données depuis ou vers un serveur

# on installe php pour wordpress aussi, et ses dependances : php-fpm et php-mysql.
# La plupart des fichiers wordpress sont en php
# PHP est un langage de programmation libre, principalement utilisé pour produire des pages Web dynamiques via un serveur HTTP, mais pouvant également fonctionner comme n'importe quel langage interprété de façon locale.

RUN apt update -y && apt install -y \
	wget \
	curl \
	php-fpm \
	php-mysql \
	php-curl \
	php-gd \
	php-xml \
	php-mbstring \
	php-zip \
	mariadb-client \
	&& apt clean -y \
    && rm -rf /var/lib/apt/lists/*

# WordPress a besoin d’une base de données pour fonctionner, du moins connaitre son mot de passe, son nom et son host.
# Tout cela se configure dans le fichier wp-config.php 
# installation de WP-CLI
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	&& chmod +x wp-cli.phar \
	&& mv wp-cli.phar /usr/local/bin/wp
				
# creation du dossier wordpress
RUN mkdir -p /var/www/html

# on copie le script d'initialisation
COPY ./tools/init_wordpress.sh /init_wordpress.sh
RUN chmod +x /init_wordpress.sh

# configuration PHP-FPM
COPY ./conf/www.conf /tmp/www.conf
RUN mv /tmp/www.conf /etc/php/8.2/fpm/pool.d/www.conf

# port uilise pas PHP-FPM
EXPOSE 9000

#lancement du script au demarrage du container
ENTRYPOINT ["/init_wordpress.sh"]