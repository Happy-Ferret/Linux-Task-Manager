#This program shutdowns the machine.

echo -e "The User asked to ShutDown the system on" `date` >> LOG

shutdown -h 0
