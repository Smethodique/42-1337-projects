
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
4. SSH Configuration
