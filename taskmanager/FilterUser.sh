#Filters the process on the basis of a specfic user

echo -e "The user asked to filter the processes on" `date` >> LOG

sh SaveFilter.sh

ps axo user > TempUserList

set `cat TempUserList`
shift 1

while true
do

	echo $1 >> UserList1

	shift 1

	if [ ! -n "$1" ]
	then
	break
	fi
done

cat UserList1 > UserListMain
rm UserList1

echo -e "\nEnter The Username To Filter: \c"
read UsrInput

grep -c $UsrInput < UserListMain > ConfirmList

set `cat ConfirmList`

if [ $1 -eq 0 ]
then
echo -e "The username entered was invalid. on" `date` >> LOG
echo -e "\nThe Username Is Invalid\n"
else
grep $UsrInput < ProcessList
echo -e "The processes were filtered for the following user $UsrInput on" `date` >> LOG
fi
