#!/bin/sh
# -> c'est un shebang, qui dit au systeme quel interpreteur utiliser pour executer le script
# ici on utilise sh

# -> set -e fait quitter le script si une commande echoue
set -e

# on verifie que les variables d environnement indispensables sont bien definies
# -z verifie si une variable est vide, de longueur 0
if [ -z "$DB_NAME" ] || [ -z "$DB_USER" ] || [ -z "$DB_PASSWORD" ] || [ -z "$DB_ROOT_PASSWORD" ]; then
	echo "Error: DB_NAME, DB_USER, DB_PASSWORD and DB_ROOT_PASSWORD must be set."
	exit 1
fi

# on initialise MariaDB uniquement au premier lancement
# -d teste si un dossier existe
# si le dossier de donnees mariadb n es=xiste pas alors premiere execution
if [ ! -d "/var/lib/mysql/${DB_NAME}" ]; then
	echo "Initializing MariaDB database and users..."

	# creation des tables systeme MariaDB, la structure interne de mariadb
	# execute en tant qu'utilisateyur mysql
	# datadir definit ou stocker les donnees
	mysql_install_db --user=mysql --datadir=/var/lib/mysql

	# on demarre temporairement mariadb sans reseau  pour configurer la base en local(en background et on recupere le pid)
	mysqld --user=mysql --datadir=/var/lib/mysql --skip-networking &
	pid="$!"

	# on attend que MariaDB soit vraiment prete avant d executer du sql
	while ! mysqladmin ping --silent; do
		sleep 1
	done

	echo "Creating database and users..."

	# on configure la base, on lance mysql en mode script et on entre les commandes sql avec un heredoc
	# ALTER USER definit le mot de passe root
	# CREATE DATABASE on cree la base si elle nexiste pas
	# CREATE USER on cree un utilisateur et on autorise la connexion depuis n importe quelle IP ('%') -> necessaire pour WP
	# GRANT ALL PRI donne tous les droits sur la base
	# FLUSH PRI recharche les permissions immediatement
	mysql -u root << EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';			
CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\`;
CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO '${DB_USER}'@'%';
FLUSH PRIVILEGES;
EOF

	# on arrete l instance temporaire de mariadb proprement pour s assurer que tout est bien ecrit sur le disque
	mysqladmin -u root -p"${DB_ROOT_PASSWORD}" shutdown

	# on attend la fermeture complete du mariadb backgroung grace au pid recupere plus tot
	wait "$pid"
else
	# si le volume existe deja on ne refait pas l init sinon perte de donnees
	echo "MariaDB already initialized, skipping bootstrap SQL."
fi

# on relance mariadb au premier plan pour garder le conteneur vivant
# exec remplace le shell pas mysqld, mysqld devient pid 1
# bind adress autorisse les connexions ecternes pour WP
exec mysqld --user=mysql --datadir=/var/lib/mysql --bind-address=0.0.0.0