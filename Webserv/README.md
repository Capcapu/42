# Webserv - 42 School

Implémentation d'un serveur HTTP/1.1 en C++98 capable de gérer des requêtes HTTP, des CGI et des configurations personnalisées.

## 📋 Description

Création d'un serveur web from scratch avec:
- Protocole HTTP/1.1
- Multiplexage I/O (select/poll/epoll)
- Configuration via fichier `.conf`
- Support CGI (Common Gateway Interface)
- Gestion des méthodes GET, POST, DELETE
- Upload de fichiers
- Pages d'erreur personnalisées

## 🛠️ Compilation

```bash
make            # Crée l'exécutable webserv
make clean      # Nettoie les .o
make fclean     # Nettoie complètement
make re         # Recompile
```

## 📚 Utilisation

```bash
./webserv [config_file]
./webserv conf/default.conf
```

Si aucun fichier de configuration n'est fourni, utilise la configuration par défaut.

### Tester le serveur

```bash
# Lancer le serveur
./webserv conf/webserv.conf

# Dans un autre terminal
curl http://localhost:8080
curl -X POST http://localhost:8080/upload -d "data=test"
curl -X DELETE http://localhost:8080/file.txt

# Ou ouvrir dans un navigateur
firefox http://localhost:8080
```

## ⚙️ Configuration

Exemple de fichier `.conf`:

```nginx
server {
    listen 8080;
    server_name localhost;
    root www;
    index index.html;
    
    client_max_body_size 10M;
    
    error_page 404 /errors/404.html;
    error_page 500 /errors/500.html;
    
    location / {
        methods GET POST;
        autoindex on;
    }
    
    location /upload {
        methods POST;
        upload_path www/uploads;
    }
    
    location /cgi-bin {
        methods GET POST;
        cgi_extension .py .php;
        cgi_path /usr/bin/python3 /usr/bin/php;
    }
}
```

### Directives disponibles

- `listen` : Port d'écoute
- `server_name` : Nom du serveur
- `root` : Répertoire racine des fichiers
- `index` : Fichier par défaut
- `client_max_body_size` : Taille maximale du corps de requête
- `error_page` : Pages d'erreur personnalisées
- `methods` : Méthodes HTTP autorisées
- `autoindex` : Listing de répertoire
- `upload_path` : Dossier pour uploads
- `cgi_extension` : Extensions CGI supportées
- `cgi_path` : Chemins des interpréteurs CGI

## 🔑 Fonctionnalités

### Méthodes HTTP
- ✅ **GET** : Récupération de ressources
- ✅ **POST** : Envoi de données, upload
- ✅ **DELETE** : Suppression de ressources

### Multiplexage I/O
- Gestion de plusieurs connexions simultanées
- Utilisation de `select()`
- Non-bloquant

### CGI (Common Gateway Interface)
- Exécution de scripts (Python et Bash)
- Variables d'environnement CGI
- Gestion des entrées/sorties

### Autres
- Cookies
- Sessions
- Chunked transfer encoding
- Keep-alive

## 📂 Structure

```
Srcs/             # Code source C++
Includes/         # Headers
conf/             # Fichiers de configuration
www/              # Contenu web (HTML, CSS)
cgi-bin/          # Scripts CGI
```