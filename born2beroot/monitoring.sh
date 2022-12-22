printf "#Architecture: "
uname -a

printf "#CPU physical : " 
grep "physical id" /proc/cpuinfo | sort -u | wc -l

printf "#vCPU : "
grep processor /proc/cpuinfo | wc -l

free -m | grep Mem | awk '{printf "#Memory Usage: %d/%dMB (%.2f%%)\n", $3, $2, ($3/$2) * 100}'

df -h --total | grep total | awk '{printf "#Disk Usage: %d/%.2fGb (%d%%)\n", $3 * 1024, $2, ($3/$2) * 100}'

mpstat | awk 'NR==4 {printf "#CPU load: %.1f%%\n", 100-$13}'

who -b | awk '{printf "#Last boot: %s %s\n", $3, $4}'

lvscan | awk '{if($1=="ACTIVE") sum+=1; else sum+=0} END {if(sum==NR) print "#LVM use: yes"; else print "#LVM use: no"}'

netstat -t | awk 'NR>=3 {sum+=1} END {if(sum>0) printf "#Connections TCP : %d ESTABLISHED\n", sum; else printf "#Connections TCP : 0 UNESTABLISHED\n"}'

who | awk '{printf "#User log: %d\n", NR}'

hostname -I | awk '{printf "#Network: IP %s ", $1}'

ip link show | grep ether | awk '{printf "(%s)\n", $2}'

journalctl _COMM=sudo | grep COMMAND | awk 'NR>=1 {sum+=1} END {printf "#Sudo : %d cmd\n", sum}'
