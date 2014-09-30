#Will calculate the Total RSS

echo -e "User asked to get the total RSS on" `date` >> LOG

sh SaveFilter.sh
ps axo rss > TempRSS

set `cat TempRSS`
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

echo -e "\nThe Total RSS is : $count\n"
echo -e "The total RSS was $count, calculated on" `date` >> LOG
