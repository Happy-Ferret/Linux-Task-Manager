#Will calculate the Total VSZ

echo -e "User asked to get the total VSZ on" `date` >> LOG

sh SaveFilter.sh
ps axo vsize > TempVSZ

set `cat TempVSZ`
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

echo -e "\nThe Total Virtual Mem Size is : $count\n"
echo -e "The total Virtual Mem was $count, calculated on" `date` >> LOG
