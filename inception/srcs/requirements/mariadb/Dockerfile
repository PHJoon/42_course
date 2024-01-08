FROM debian:buster

# ENV MYSQL_ROOT_PASSWORD=rootpw
# ENV MYSQL_USER=normal
# ENV MYSQL_PASSWORD=normalpw
# ENV MYSQL_DATABASE=wordpress_db

RUN apt-get update -y && apt-get upgrade -y && \
apt-get -y install mariadb-server

COPY ./conf/my.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./tools/start.sh /usr/start.sh

CMD ["/bin/bash", "/usr/start.sh"]

# ENTRYPOINT ["echo", "hello"]