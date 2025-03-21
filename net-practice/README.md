# NetPractice - Network Configuration Training

## Overview
NetPractice is an interactive project designed to deepen understanding of IP addressing, subnetting, and basic network configuration. This practical exercise simulates various network scenarios, challenging students to apply networking concepts to solve increasingly complex configurations.

## Learning Objectives
- Master IP addressing (IPv4) and subnetting principles
- Understand network masks and CIDR notation
- Configure routing tables and gateways
- Troubleshoot connectivity issues between network devices
- Apply theoretical networking knowledge to practical scenarios

## Project Structure
The project consists of 10 progressive levels, each presenting a unique network configuration challenge:

1. **Level 1**: Basic IP addressing
2. **Level 2-3**: Introduction to subnetting
3. **Level 4-5**: Network masks and connectivity
4. **Level 6-7**: Default gateways and routing
5. **Level 8-9**: Advanced routing configurations
6. **Level 10**: Complex network with multiple subnets

## Key Concepts

### IP Addressing
- IPv4 format: Four 8-bit numbers (octets) separated by dots
- Private IP ranges:
  - 10.0.0.0/8
  - 172.16.0.0/12
  - 192.168.0.0/16
- Special addresses:
  - Network address (first address in subnet)
  - Broadcast address (last address in subnet)
  - Loopback: 127.0.0.1

### Subnet Masks
- Used to divide IP addresses into network and host portions
- Common subnet masks:
  - 255.0.0.0 (/8)
  - 255.255.0.0 (/16)
  - 255.255.255.0 (/24)
  - 255.255.255.128 (/25)
  - 255.255.255.192 (/26)
  - 255.255.255.240 (/28)
  - 255.255.255.252 (/30)

### CIDR Notation
- Simplified way to express subnet masks
- Number after the slash indicates how many bits are used for the network portion
- Example: 192.168.1.0/24 (equivalent to mask 255.255.255.0)

### Routing
- Default route (0.0.0.0/0): Traffic to all networks not explicitly defined
- Gateway: Next hop for packets traveling outside the local network
- Route table: Defines where to send packets based on destination IP

## Tips for Success

### Calculating Subnets
1. Convert subnet mask to binary
2. Count the number of consecutive 1s (gives you CIDR notation)
3. Identify network bits vs. host bits
4. Calculate:
   - Network address: IP address AND subnet mask
   - Broadcast address: Network address OR (NOT subnet mask)
   - First usable host: Network address + 1
   - Last usable host: Broadcast address - 1
   - Number of usable hosts: 2^(32-prefix) - 2

### Example Calculations
For subnet 192.168.1.0/24:
- Subnet mask: 255.255.255.0
- Network address: 192.168.1.0
- Broadcast address: 192.168.1.255
- Usable IP range: 192.168.1.1 - 192.168.1.254
- Number of usable hosts: 254

### Troubleshooting Checklist
- Are devices on the same subnet?
- Is the gateway within the same subnet as the device?
- Are there conflicts between routes?
- Is the destination IP valid for the given subnet?
- Does the routing table have a path to the destination?

## Example Configurations

### Level 1 Configuration
```json
{"routes":{},"ifs":{"A1":{"ip":"104.97.23.13"},"B1":{},"C1":{},"D1":{"ip":"211.191.151.76"}}}
```
- Goal: Configure interfaces to allow communication between hosts

### Level 6 Configuration
```json
{"routes":{"Ar1":{"route":"default","gate":"98.226.40.228"},"Rr1":{"route":"default"},"Ir1":{"route":"98.226.40.228/24"}},"ifs":{"A1":{"mask":"255.255.255.128"},"R1":{"ip":"98.226.40.228"},"R2":{},"S1":{},"Somewhere on the Net":{},"I1":{}}}
```
- Goal: Configure subnet masks and default gateways

## References
- [IP Subnet Calculator](https://www.calculator.net/ip-subnet-calculator.html)
- [CIDR Chart](https://www.aelius.com/njh/subnet_sheet.html)
- [Practical Networking Fundamentals](https://www.pracnet.net/)

```

## Project Evaluation Criteria
- Correct configuration of all levels
- Understanding of networking concepts during evaluation
- Ability to explain the solutions implemented
- Knowledge of subnetting calculations and principles

---

*This project is part of the 42 School curriculum and aims to provide practical experience with networking concepts.*
