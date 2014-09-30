#Will calculate the Total Mem Usage

echo -e "User asked to get the total Mem Usage on" `date` >> LOG

sh SaveFilter.sh
ps axo %mem > TempMem

set `cat TempMem`
shift 1
count=0

while true
do

	a=$1
	count=`echo $count + $1 | bc`

	shift 1
	
	if [ ! -n "$1" ]
	then
	break
	fi
done

echo -e "\nThe Total %Mem Usage is : $count\n"
echo -e "The total %Mem Usage was $count, calculated on" `date` >> LOG
