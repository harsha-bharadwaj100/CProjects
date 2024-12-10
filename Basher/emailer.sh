#!/bin/bash
email="dingdongx100@gmail.com"
subject="Alert"
message="Disk space is running low!"
echo "$message" | mail -s "$subject" "$email"