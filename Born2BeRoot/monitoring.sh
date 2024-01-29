  GNU nano 7.2                                                 /usr/local/bin/monitoring.sh                                                           
#!/bin/bash
broadcast_message=""

printf -v broadcast_message "OS and Kernel Version: %s" "$(uname -a)\n"
broadcast_message+="Physical CPU(s): $(lscpu | grep "Socket(s):" | awk '{print $2}')\n"
broadcast_message+="Virtual CPU(s): $( lscpu | grep "CPU(s):" | awk '{print $2}' | sed -n "1p"
)\n"
broadcast_message+="Total Memory: $(free -m | grep "Mem" | awk '{print $2 "MB"}')\n"

mem_used=$(free -m | grep "Mem" | awk '{print $3 / $2 * 100 }')
broadcast_message+="Memory used/available:  $(free -m | grep "Mem" | awk '{print $7 , "MB"}') $(echo " $mem_used%" )  \n"
broadcast_message+="Disk Memory: $(df -h --total | grep "total" | awk '{print $2}')\n"
broadcast_message+="Disk Memory used: $( df -h --total | grep "total" | awk '{print $5}')\n"
broadcast_message+="CPU Utilization Rate: $(mpstat | grep "all" | awk '{print 100 - $13 "%"}')\n"
broadcast_message+="Last Reboot: $(uptime -s)\n"
broadcast_message+="LVM Status: $(lsmod | grep -q "^dm_mod" && echo "yes" || echo "no")\n"

tcp_connections=$(ss -t -a | grep -c ESTAB)
broadcast_message+="TCP Active Connections: $tcp_connections\n"

users_count=$(who | tail -n +2 | wc -l)
broadcast_message+="Users Using Server: $users_count\n"

ipv4_address=$(ip a | grep "inet" | awk '{print $2}' | sed -n '3p' | awk -F '/' '{print $1}')
mac_address=$(ip a | grep link/ether | awk '{print $2}')
broadcast_message+="IPv4 Address and MAC: $ipv4_address $mac_address\n"

sudo_count=$(journalctl -q _COMM=sudo | grep COMMAND | wc -l)
broadcast_message+="Commands Executed By Sudo: $sudo_count\n"

echo -e "$broadcast_message" | wall

