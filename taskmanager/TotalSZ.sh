#Will calculate the Total SZ

echo -e "User asked to get the total SZ on" `date` >> LOG

sh SaveFilter.sh
ps axo size > TempSZ

set `cat TempSZ`
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

echo -e "\nThe Total Page Size is : $count\n"
echo -e "The total Page Size was $count, calculated on" `date` >> LOG
