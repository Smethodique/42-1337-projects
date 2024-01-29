
# Project: Born2beRoot

## Introduction
This project involves setting up a secure and well-configured Linux system using either the latest stable version of Debian or Rocky Linux. The system configuration includes setting up encryption with LVM,
configuring firewalls, managing users, implementing a strong password policy, and creating a monitoring script.

## Prerequisites
- Virtualization software (e.g., VirtualBox)
- Debian or Rocky Linux ISO

## Getting Started

### 1. Choose the Operating System
- Select either Debian or Rocky Linux (latest stable version).

### 2. Installation
- Install the chosen operating system using the provided ISO.

### 3. System Configuration
#### For Debian:
```bash
# Update and upgrade system
sudo apt update && sudo apt upgrade -y

# Install AppArmor
sudo apt install apparmor

# Configure LVM and create encrypted partitions
# (Refer to project documentation for specific partitioning details)
```
### 4. SSH Configuration

```bash
#Configure SSH to run on port 4242
sudo nano /etc/ssh/sshd_config
# Change Port 22 to Port 4242

# Disable root login via SSH
sudo nano /etc/ssh/sshd_config
# PermitRootLogin no

# Restart SSH service
sudo systemctl restart sshd
```

### 5. Firewall Configuration
For Debian (using UFW):
```bash
# Install UFW
sudo apt install ufw

# Allow only port 4242
sudo ufw allow 4242
sudo ufw enable
```
### 6. User and Password Policies
```bash
# Create a new user with login ending with 42
sudo useradd -m -s /bin/bash [username]

# Add the user to user42 and sudo groups
sudo usermod -aG user42,sudo [username]

# Set strong password policy
sudo passwd --expire [username]
sudo chage -m 2 -W 7 -I 30 -d 2 [username]
```
### 7. Sudo Configuration
```bash
# Edit sudoers file
sudo visudo
Defaults	env_reset
Defaults	mail_badpass
Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
Defaults	logfile="/var/log/sudo.log"
Defaults	lecture="always"
Defaults	badpass_message="Password is wrong, please try again"
Defaults	passwd_tries=5
Defaults	insults
Defaults	log_input,log_output# Add the following line


%sudo   ALL=(ALL:ALL) ALL
```
### 8. Monitoring Script


# Create monitoring script
```bash
nano monitoring.sh
```
 (Add the script in monitoring.sh)
 
[ script path ](/Born2BeRoot/monitoring.sh)

Make script executable

```bash
chmod +x monitoring.sh
```

Schedule script to run every 10 minutes using cron
```bash
*/10 * * * * /path/to/monitoring.sh
```
### Bonus Part

Setting Up WordPress on Lighttpd with MariaDB and PHP

Step 1 – Install Lighttpd, MariaDB, and PHP
```bash
apt-get install mysql-server lighttpd php php-fpm php-mysql php-cli php-curl php-xml php-json php-zip php-mbstring php-gd php-intl php-cgi -y
apt-get remove apache2 -y
systemctl stop apache2
systemctl start lighttpd
systemctl enable lighttpd
```
Step 2 – Configure PHP-FPM to Work with Lighttpd
```bash

nano /etc/php/8.2/fpm/pool.d/www.conf
```
 Replace: listen = /run/php/php7.4-fpm.sock
 With: listen = 127.0.0.1:9000

nano /etc/lighttpd/conf-available/15-fastcgi-php.conf
 Replace: "bin-path" => "/usr/bin/php-cgi", "socket" => "/var/run/lighttpd/php.socket",
 With: "host" => "127.0.0.1", "port" => "9000"

lighty-enable-mod fastcgi
lighty-enable-mod fastcgi-php

systemctl restart lighttpd
systemctl restart php8.2fpm

# Step 3 – Create a Database for WordPress
```bash
mysql
```
 Run the following commands in MySQL shell:
```BASH
CREATE DATABASE wpdb;
GRANT ALL PRIVILEGES on wpdb.* TO 'wpuser'@'localhost' IDENTIFIED BY 'password';
FLUSH PRIVILEGES;
EXIT;
```
# Step 4 – Install WordPress
```bash
cd /var/www/html
wget https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz

cd wordpress
mv wp-config-sample.php wp-config.php
nano wp-config.php
```
 ##Configure database settings
```bash
chown -R www-data:www-data /var/www/html/wordpress
chmod -R 755 /var/www/html/wordpress
```
## Step 5: Configure Lighttpd for WordPress

 1. Create a directory for virtual host configuration files:
```bash

mkdir -p /etc/lighttpd/vhosts.d/
```
 2. Edit the Lighttpd configuration file:
```bash
nano /etc/lighttpd/lighttpd.conf
```
 3. Add mod_rewrite to the list of server modules:
```bash
server.modules = (
        "mod_access",
        "mod_alias",
        "mod_compress",
        "mod_redirect",
        "mod_rewrite",
)
```

4. Define the path for virtual host configurations:
```bash
include_shell "cat /etc/lighttpd/vhosts.d/*.conf"
```
Save and close the file.

 5. Create a new virtual host configuration file for WordPress:
```bash
$HTTP["host"] =~ "localhost" {
    server.document-root = "/var/www/html/wordpress"
    server.errorlog = "/var/log/lighttpd/wordpress-error.log"
}
```
```bash

systemctl restart lighttpd
```
### Step 6 – Access WordPress Dashboard
Open your browser and navigate to your WordPress site (e.g., http://localhodt) to complete the installation.

## BONUS PART 2 (Services)

This section is intended to be adaptable, enabling students to select any service to integrate into their operating system
such as FTP or backup service .... 
Nevertheless, it is crucial to emphasize that the utilization of Apache and Nginx is strictly forbiden in this particular context.
