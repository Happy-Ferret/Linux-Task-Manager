#Will calculate the total Cpu Usage

echo -e "User asked to get the total Cpu Usage on" `date` >> LOG

sh SaveFilter.sh
ps axo pcpu > TempCpu

set `cat TempCpu`
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

echo -e "\nThe Total CPU Usage is : $count\n"
echo -e "The total Cpu Usage was $count, calculated on" `date` >> LOG
