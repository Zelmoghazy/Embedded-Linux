#!/bin/bash

# Log file to store the report
LOG_FILE="system_report.log"

# Function to log a section header
log_section() {
    echo -e "\n==================== $1 ====================" >> $LOG_FILE
}

# Function to log system information
log_info() {
    echo -e "$1" >> $LOG_FILE
}

# Start logging
echo "System Report - Generated on $(date)" > $LOG_FILE

# 1. System Uptime
log_section "System Uptime"
log_info "$(uptime)"

# 2. System Date and Time
log_section "System Date and Time"
log_info "$(date)"

# 3. Logged In Users
log_section "Logged In Users"
log_info "$(who)"

# 4. CPU Information
log_section "CPU Information"
log_info "$(lscpu)"

# 5. Memory Usage
log_section "Memory Usage"
log_info "$(free -h)"

# 6. Disk Usage
log_section "Disk Usage"
log_info "$(df -h)"

# 7. Mounted Filesystems
log_section "Mounted Filesystems"
log_info "$(mount | column -t)"

# 8. Network Interfaces and IP Addresses
log_section "Network Interfaces and IP Addresses"
log_info "$(ip -4 addr show)"

# 9. Active Network Connections
log_section "Active Network Connections"
log_info "$(netstat -tuln)"

# 10. Running Processes
log_section "Running Processes (Top 10 by Memory Usage)"
log_info "$(ps aux --sort=-%mem | head -n 11)"

# 11. System Load
log_section "System Load"
log_info "$(cat /proc/loadavg)"

# 12. Kernel Information
log_section "Kernel Information"
log_info "$(uname -a)"

# 13. Last 10 Syslog Entries (Assuming /var/log/syslog exists)
if [ -f /var/log/syslog ]; then
    log_section "Last 10 Syslog Entries"
    log_info "$(tail -n 10 /var/log/syslog)"
else
    log_section "Syslog"
    log_info "Syslog file not found."
fi

# 14. Last 10 dmesg Entries (Kernel ring buffer)
log_section "Last 10 dmesg Entries"
log_info "$(dmesg | tail -n 10)"

# 15. Firewall Status (ufw for Ubuntu systems)
log_section "Firewall Status (ufw)"
log_info "$(sudo ufw status)"

# Finish the report
echo -e "\nSystem report has been saved to $LOG_FILE"

