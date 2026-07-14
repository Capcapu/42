*This project has been created as part of the 42 curriculum by csolari.*

# Inception

## Description

**Inception** is a system administration project focused on containerization using Docker.  
The goal is to set up a small infrastructure composed of multiple services, each running in its own container and orchestrated with Docker Compose.

The project includes:
- A **NGINX** container with TLS (HTTPS only)
- A **WordPress** container with PHP-FPM
- A **MariaDB** database container
- Persistent storage using Docker volumes
- Secure configuration using environment variables

The objective is to understand how to build, configure, and connect containers.

---

## Project Architecture

```bash
.
├── Makefile
├── README.md
├── USER_DOC.md
├── DEV_DOC.md
└── srcs
├── docker-compose.yml
├── .env (to complete)
└── requirements
├── mariadb
│ ├── conf
│ │ └── 50-server.conf
│ ├── Dockerfile
│ └── tools
│ └── init_mariadb.sh
├── nginx
│ ├── conf
│ │ └── nginx.conf
│ └── Dockerfile
└── wordpress
└── init_wordpress.sh
```


Each service is built from a custom **Dockerfile** based on a Debian image.

---

## Instructions

### Prerequisites

- Docker
- Docker Compose
- Make

We made a virtual machine for this projet in order to have sudo rights for the user, on the computer of the school.

### Installation & Setup

1. Clone the repository:
```bash
git clone git@vogsphere.42paris.fr:vogsphere/intra-uuid-dab139de-524c-4b71-a924-8e83af020f4b-7346469-csolari inception
cd inception
```

2. Configure environment variables:
Edit the .env file with your credentials:

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

4. Access the website:
open in browser : https://localhost

### Useful Commands

```bash
make all       # build and start containers
make up        # Start containers
make down      # Stop containers
make logs	   # show logs
make clean     # Remove containers and images
make fclean    # Full cleanup (including volumes)
make re        # Rebuild everything
```

## Technical Choices

### Virtual Machines vs Docker

A **virtual machine (VM)** is a fully emulated computer system that runs on top of a physical machine using a hypervisor. Each virtual machine includes its own complete operating system, along with all necessary system components such as the kernel, libraries, and graphical interface. This makes virtual machines highly isolated and flexible, but also heavy in terms of resource usage and slower to start.

**Docker**, on the other hand, is a containerization platform that allows applications to be packaged with their dependencies into isolated environments called containers. Unlike virtual machines, containers do not include a full operating system. Instead, they share the host system’s kernel and only contain what is strictly necessary to run the application. This makes them lightweight, fast, and easy to deploy.

One of the major advantages of Docker is that it solves a common problem developers face: an application that works perfectly on one machine but fails on another due to missing dependencies or configuration differences. By packaging the application and its environment into a container image, Docker ensures consistency across different systems. These images can be stored locally or shared, making it easy to reproduce the same environment anywhere.

While virtual machines already provide isolation, Docker improves efficiency by reducing overhead. A container can be seen as a lightweight alternative to a virtual machine, as it removes the need for a full operating system and focuses only on the application and its dependencies. 

---

### Secrets vs Environment Variables

There are multiple ways to manage sensitive data in a containerized environment. Environment variables are simple to use and are typically stored in a `.env` file, making them convenient for development. However, they are not fully secure, as they can be exposed inside the container.

Docker Secrets, on the other hand, provide a more secure approach by encrypting sensitive data and managing it separately from the container configuration. They are better suited for production environments where security is critical.

In this project, environment variables were used because they are easier to implement and sufficient for a development setup.

---

### Docker Network vs Host Network

Docker provides different networking modes to allow containers to communicate (host, bridge, none...). Using a Docker network creates an isolated environment where containers can interact with each other using their service names. This approach improves security and flexibility, as it prevents direct exposure to the host system.

The host network mode allows containers to share the host’s networking stack directly, which reduces isolation and can introduce security risks.

For this project, a custom Docker network is used to ensure proper communication between services while maintaining isolation from the host.

---

### Docker Volumes vs Bind Mounts

To persist data in Docker, volumes and bind mounts can be used. Docker volumes are managed directly by Docker and are designed to be persistent and portable across different environments. They are particularly well-suited for storing database data.

Bind mounts, in contrast, link a container directly to a specific directory on the host machine. While they are useful during development, they are less portable and depend on the host’s file structure.

In this project, Docker volumes are used to persist important data such as the database content and WordPress files, ensuring that data is not lost when containers are stopped or removed.


## Resources

### Documentation

Docker formation I followed:
- https://www.nicelydev.com/docker/

Docker documentation:
- https://docs.docker.com

Inception tutorial:
- https://tuto.grademe.fr/inception/

Debian versions:
- https://www.debian.org/releases/index.fr.html

MariaDB installation and setup:
- https://www.malekal.com/installer-mysql-mariadb-debian/

WordPress installation and setup:
- https://fr.wordpress.org/download/releases/
- https://www.linode.com/docs/guides/how-to-install-wordpress-using-wp-cli-on-debian-10/

Docker Volumes:
- https://docs.docker.com/engine/storage/volumes/

About PID1:
- https://www.bencat.dev/p/docker-gestion-du-pid-1-avec-tini/

About deamon processes:
- https://fr.wikipedia.org/wiki/Daemon_(informatique)

### Use of AI

AI tools were used in this project for:

- Debugging configuration issues (NGINX, WordPress, MariaDB)
- Making roadmap to understand the major step to follow (VM configuration)
- Writing the structure of documentation (including this README)

All configurations and implementations were tested and validated manually.

