volume = /home/hyungjpa/data
db_data = $(volume)/mariadb
wp_data = $(volume)/wordpress
mariadbImg = my-mariadb
wordpressImg = my-wordpress
nginxImg = my-nginx

up: build
	docker compose -f srcs/docker-compose.yaml up

setVolume:
	@if [ ! -d $(db_data) ]; then mkdir -p $(db_data); fi
	@if [ ! -d $(wp_data) ]; then mkdir -p $(wp_data); fi
	@echo "volume folder => $(volume)"

build: setVolume
	docker compose -f srcs/docker-compose.yaml build

stop:
	docker compose -f srcs/docker-compose.yaml stop

start:
	docker compose -f srcs/docker-compose.yaml start

down:
	docker compose -f srcs/docker-compose.yaml down

downVolume:
	docker compose -f srcs/docker-compose.yaml down -v

re: down all

imgClean:
	@if [ $(shell docker image ls | grep $(mariadbImg) | wc -l) -eq 1 ]; \
		then docker rmi $(mariadbImg):v1; fi
	@if [ $(shell docker image ls | grep $(wordpressImg) | wc -l) -eq 1 ]; \
		then docker rmi $(wordpressImg):v1; fi
	@if [ $(shell docker image ls | grep $(nginxImg) | wc -l) -eq 1 ]; \
		then docker rmi $(nginxImg):v1; fi

dataClean:
	sudo rm -rf /home/hyungjpa/data/*
	sudo rm -rf /home/hyungjpa/data/*

clean: downVolume imgClean

.PHONY: setVolume build all stop down downVolume re imgClean dataClean clean