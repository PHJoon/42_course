#!/bin/sh

sudo apt-get update -y
sudo apt-get install -y irssi inspircd tcpflow

sudo chown -R root:root /etc/inspircd/inspircd.conf
sudo mkdir /var/run/inspircd
sudo touch /var/run/inspircd/inspircd.pid
sudo chmod 777 /var/run/inspircd/inspircd.pid

# sudo inspircd --runasroot --nofork --dubug
# sudo irssi -c 127.0.0.1 -p 6667 -n nickname
# sudo tcpflow -i lo port 6667 -c