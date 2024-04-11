FROM debian:bullseye

RUN apt-get update -y && apt-get install -y mariadb-server-10.5 mariadb-client dumb-init \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

COPY ./conf/mariadb.conf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./tools/start_mariadb.sh /home

RUN mkdir -p /var/run/mysqld && chown -R mysql:mysql /var/run/mysqld && chmod 777 /var/run/mysqld && \
    chown -R mysql:mysql /var/log/mysql && chmod 777 /var/log/mysql

RUN chmod +x /home/start_mariadb.sh

ENTRYPOINT ["/usr/bin/dumb-init", "--", "/home/start_mariadb.sh"]