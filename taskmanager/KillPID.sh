#Will take PID from User.
#Confirm to kill it. And then will kill it.

sh OnlyPID.sh

echo -e "User provided a PID to kill a process on" `date` >> LOG

echo -e "Enter the PID to Confirm Killing : \c"
read UsrInput

grep -c $UsrInput < OnlyPID > ConfirmPID

set `cat ConfirmPID`
#echo $1

if [ $1 -eq 1 ]
then
kill $UsrInput
echo -e "\nProcess has been terminated\n"
echo -e "The process $8 with PID $1 was killed by the user on" `date` >> LOG
else
echo -e "\nPID Mismatch.\n"
echo -e "The entered invalid information on" `date` >> LOG
fi
