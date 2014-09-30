# This script sorts the processes on the basis of the RSS
# This script would take the input from the ProcessList generated by SaveFilter.sh

sh SaveFilter.sh

echo -e "User asked to kill the process taking highest RSS on" `date` >> LOG

sort -n +3 -4 < ProcessList > KillRSS

set `tail -1 < KillRSS`

echo -e "Highest RSS taking process is $8 (PID = $1) created by User : $9\n"

echo -e "To confirm termination, enter the PID of the Process to Continue: \c"
read UsrInput

if [ $UsrInput = $1 ]
then
kill $1
echo -e "\nProcess has been terminated\n"
echo -e "The process $8 with PID $1 was killed by the user on" `date` >> LOG
else
echo -e "\nPID Mismatch.\n"
echo -e "The entered invalid information on" `date` >> LOG
fi

