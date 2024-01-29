
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
```bash

# Create monitoring script
nano monitoring.sh
# (Add the script : Born2BeRoot/monitoring.sh)
[path ](/Born2BeRoot/monitoring.sh)
# Make script executable
chmod +x monitoring.sh

# Schedule script to run every 10 minutes using cron
*/10 * * * * /path/to/monitoring.sh
```
