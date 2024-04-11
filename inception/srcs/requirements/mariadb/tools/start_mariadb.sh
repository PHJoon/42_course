# #!/bin/sh

service mariadb start

# Wait for MariaDB to become ready
check_mariadb() {
    mysqladmin ping
}

until check_mariadb; do
    echo "Waiting for MariaDB to become ready..."
    sleep 1
done
echo "MariaDB is ready"

# Set root password, create database and users
echo 'Set root password'
mysql -uroot -p$MARIADB_ROOT_PASSWORD -e "set password for 'root'@'localhost' = password('$MARIADB_ROOT_PASSWORD');"
mysql -uroot -p$MARIADB_ROOT_PASSWORD -e "flush privileges;"

echo 'Create database and users'
mysql -uroot -p$MARIADB_ROOT_PASSWORD -e "create database if not exists $MARIADB_DATABASE;"

if mysql -uroot -p$MARIADB_ROOT_PASSWORD -e "select user from mysql.user;" | grep -q "$MARIADB_USER"; then
  mysql -uroot -p$MARIADB_ROOT_PASSWORD -e "drop user '$MARIADB_USER'@'%';"
fi
mysql -uroot -p$MARIADB_ROOT_PASSWORD -e "create user '$MARIADB_USER'@'%' identified by '$MARIADB_USER_PASSWORD';"
mysql -uroot -p$MARIADB_ROOT_PASSWORD -e "grant all privileges on $MARIADB_DATABASE.* to '$MARIADB_USER'@'%';"

mysql -uroot -p$MARIADB_ROOT_PASSWORD -e "flush privileges;"

echo 'Stop MariaDB'
sleep 1
service mariadb stop

echo "
*************************************
    MariaDB Container is ready 
*************************************
"

exec mariadbd --defaults-file=/etc/mysql/mariadb.cnf