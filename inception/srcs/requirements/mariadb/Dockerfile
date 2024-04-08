FROM debian:bullseye

RUN apt-get update -y && apt-get install -y mariadb-server mariadb-client

COPY ./conf/mariadb.conf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./tools/start_mariadb.sh /home

RUN mkdir -p /var/run/mysqld && chown -R mysql:mysql /var/run/mysqld && chmod 777 /var/run/mysqld

RUN mkdir -p var/mysql && ln -s /tmp/mysql.sock var/mysql/mysql.sock

RUN chmod +x /home/start_mariadb.sh

ENTRYPOINT ["/bin/bash", "/home/start_mariadb.sh"]