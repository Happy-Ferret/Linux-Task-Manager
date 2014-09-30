#This will reboot the system

echo -e "The User asked to Reboot the system on" `date` >> LOG

reboot -f

