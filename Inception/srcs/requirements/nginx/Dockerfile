#FROM indique a Docker sur quel OS on souhaite faire tourner le conteneur
FROM debian:bookworm

#RUN indique a Docker quelle commande executer a la creation du container

# apt est un gestionnaire de paquets pour debian, il permet d'installer des logiciels et de les maintenir à jour
# on verifie et met a jour les paquets si necessaire
# -y repond YES aux messages de confirmation pour les installations
RUN apt update -y

#on installe les paquets necessaires pour faire tourner nginx
RUN apt install nginx -y 

############################################
# CREATION DU CERTIFICAT SSL POUR LE HTTPS
# on fait du TSL pour faire du https
# TSL (Transport Layer Security) est un protocole de securite qui permet de chiffrer les communications entre le client et le serveur, pour proteger les données contre les interceptions et les attaques

# openssl est l outil principal pour creer et gerer des certificats SSL
# comme les autres packages on l installe avec apt
RUN apt install openssl -y

# pour liberer les fichiers de cache telecharges par apt pendant l'installation des paquets
# ca libere de l'espace dans l'image et la rend plus legere
# apt clean supprime surtout les fichiers de cache telecharges 
# rm -rf /var/lib/apt/lists/* supprime les listes de paquets 
RUN apt clean -y \                    
    && rm -rf /var/lib/apt/lists/*      

# on cree un dossier (-p s'il n existe pas deja) le certificat et la cle de connexion securisee
RUN mkdir -p /etc/nginx/ssl

# on va generer un certificat ssl auto-signe pour notre serveur nginx, pour creer un certificat tsl/ssl
# req cree et traite les demandes de certificat, -x509 indique le type de certificat, ici auto-signe
# -nodes signifie que nous ne voulons pas de mot de passe pour la clé privée, comme le -y, on a une cle privee sans mot de passe
# on va utiliser out et keyout pour indiquer ou stocker le certificat et la cle de notre ssl
# -days 365 indique que le certificat sera valide pendant 365 jours
# -keyout spécifie le chemin pour la clé privée 
# -out spécifie le chemin pour le certificat
# -subj est une option qui permet de preremplir certaines informations du certificat, sans quoi on aurait un prompt a remplir dans notre execution de la commande
# on indique le pays (C), la region (ST), la localite (L), l'organisation (O), l'unite organisationnelle (OU), le nom commun (CN) et l'identifiant utilisateur (UID) pour notre certificat
RUN openssl req -x509 -nodes -days 365\
    -out /etc/nginx/ssl/nginx.crt \
    -keyout /etc/nginx/ssl/nginx.key \
    -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=csolari.42.fr/UID=csolari"

# -> notre certificat et notre clé sont maintenant crees automatiquement au demarrage du container, et stockes dans le dossier /etc/nginx/ssl

############################################

# on supprime le fichier de configuration par defaut de nginx, pour eviter les conflits avec notre propre configuration
RUN rm -rf /etc/nginx/http.d/default.conf

# on copie notre propre fichier de configuration nginx.conf dans le dossier de configuration de nginx, pour que nginx utilise notre configuration personnalisee
COPY conf/nginx.conf /etc/nginx/nginx.conf

# on cree ce dossier (-p s'il n'existe pas deja) où
# Nginx y stocke des fichiers d'execution temporaire, comme les fichiers de pid (process id) et les fichiers de socket pour la communication entre les processus de nginx
# si ce dossier n'existe pas nginx risque d'echouer au demarrage
RUN mkdir -p /var/run/nginx

# port pour communiquer avec internet
EXPOSE 443

# on lance nginx avec daemon off
# ca lancera nginx en premier plan pour que le container reste actif/ ne se stop pas, sinon le container se fermerait immediatement apres le lancement de nginx
# ENTRYPOINT indique a Docker quelle commande executer lorsque le container est lance, ici on lance nginx en mode foreground
# daemon off est une directive de nginx qui indique a nginx de ne pas se mettre en mode daemon (arriere plan) et de rester en premier plan, ce qui est necessaire pour que le container reste actif
CMD ["nginx", "-g", "daemon off;"]
