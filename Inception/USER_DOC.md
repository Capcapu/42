# User Documentation

## Overview

This document is intended for end users and administrators. It provides step-by-step instructions to run the Inception project, access the website and administration interface, manage configuration and credentials, and ensure that all services are operating correctly.

---

## Services provided

This project provides a small web infrastructure based on Docker.  
It includes the following services:

- **NGINX**: Acts as the web server and the entry point of the infrastructure. It handles incoming HTTP requests and redirects them to HTTPS using TLS encryption. It also serves static content and forwards dynamic requests to the WordPress container (PHP-FPM).

- **WordPress**: Provides the website application. It runs with PHP-FPM, which processes dynamic PHP requests received from NGINX. WordPress generates the web pages and interacts with the database to store and retrieve content such as posts, users, and settings.

- **MariaDB**: Serves as the relational database management system. It stores all the persistent data used by WordPress, including website content, user information, and configuration data. WordPress communicates directly with MariaDB to read and write this data.

All services run in separate containers and communicate through a Docker network.

---

## Starting and Stopping the Project

### Start the project

To build and start all services:

```bash
make
```

or manually

```bash
docker compose -f srcs/docker-compose.yml up --build -d
```

### Stop the project:

```bash
make down
```

Or manually

```bash
docker compose -f srcs/docker-compose.yml down
```

### Restart the project

```bash
make re
```

## Accessing the Website

Once the project is running, open your browser and go to:

https://localhost

⚠️ You may need to accept the self-signed SSL certificate.

---

## Accessing the WordPress Admin Panel

To access the administration interface:

https://localhost/wp-admin

Log in using the administrator credentials defined in the .env file.

---

## Managing Credentials

All credentials are stored in the .env file located in:

srcs/.env

This file contains:

- Database name, user, and passwords
- WordPress admin credentials
- Domain name

Example:

```env
DOMAIN_NAME=student.42.fr
DB_NAME=Inception
DB_USER=xxxxxx
DB_PASSWORD=xxxxxxx
DB_ROOT_PASSWORD=xxxxxxx
WP_TITLE=Inception
WP_ADMIN_USER=master
WP_ADMIN_EMAIL=master@example.com
WP_ADMIN_PASSWORD=xxxxxxxx
WP_USER_NAME=user
WP_USER_EMAIL=user@example.com
WP_USER_PASSWORD=xxxxxxxx
```

⚠️ WP_ADMIN_USER musn't contains "admin" or "Administrator", in any form.
⚠️ Do not share this file publicly.

---

## Checking Services Status

### Check running containers

```bash
docker ps
```

You should see:

- nginx container
- wordpress container
- mariadb container

### Check logs

```bash
make logs
```

or manually :

```bash
docker compose -f srcs/docker-compose.yml logs
```

Or for a specific service:

```bash
docker compose -f srcs/docker-compose.yml logs nginx
docker compose -f srcs/docker-compose.yml logs wordpress
docker compose -f srcs/docker-compose.yml logs mariadb
```

### Test website availability

Open in browser:

https://localhost

Or use curl:

```bash
curl -k https://localhost
```

---

## Troubleshooting

If the site is not accessible:

- Check containers with docker ps
- Check logs for errors

If login fails:
- Verify credentials in .env

If containers fail to start:
- Rebuild the project with:

```bash
make re
```