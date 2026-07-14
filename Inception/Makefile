NAME = Inception
COMPOSE = docker compose -f ./srcs/docker-compose.yml

all:
	$(COMPOSE) up -d --build

up:
	$(COMPOSE) up -d

down:
	$(COMPOSE) down

logs:
	$(COMPOSE) logs -f

clean:
	$(COMPOSE) down --rmi all

fclean: clean
	$(COMPOSE) down -v --rmi all --remove-orphans
	sudo rm -rf /home/csolari/data/mariadb/*
	sudo rm -rf /home/csolari/data/wordpress/*

re: fclean all

.PHONY: all up down logs clean fclean re