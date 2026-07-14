FROM debian:bookworm

# on met a jour les paquets
# on installe mariadb et ses dependances
# on nettoire le cache pour eviter d alourdir l'image 
RUN apt update -y \
    && apt install mariadb-server -y \
    && apt clean -y \
    && rm -rf /var/lib/apt/lists/*

# on prepare le dossier que mariadb utilise au demarrage, sinon peut crash
# on donne les droits d execution a l utilisateur mysql pour le dossier de demarrage de mariadb
# mariadb tourne avec l'utilisateur mysql
RUN	mkdir -p /run/mysqld && \
	chown mysql:mysql /run/mysqld 

# je vais faire un script que dockerfile va excexuter
# Ce script doit créer avec MySQL le système de table
# on copie le script dans le container, a la racine du systeme de fichiers du container et on donne les droits d'execution
COPY ./tools/init_mariadb.sh /init_mariadb.sh 
RUN chmod +x /init_mariadb.sh

# supprime config -par defaut et ajoute la notre
RUN rm -rf /etc/mysql/mariadb.conf.d/default.conf
COPY ./conf/50-server.conf /etc/mysql/mariadb.conf.d/50-server.conf

# utilise port 3306 pour communiquer entre WP et mariadb
# ici on n ouvre pas le port, sert a titre informatif pour documenter le container
EXPOSE 3306

# le script se lance au demarrage du container, pas pendant le build
ENTRYPOINT ["/init_mariadb.sh"]
