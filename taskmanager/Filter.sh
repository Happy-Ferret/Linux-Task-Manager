#This script displays the file is the order specified below
#PID	STAT	VSZ	RSS	SZ	%CPU	%MEM	Command    User


set `ps axo pid,stat,vsize,rss,size,pcpu,%mem,comm,user`
shift 9

a="true"
while $a
do
 
printf "%-5s\t%-5s\t%-8s\t%-8s\t%-8s\t%-5s\t%-5s\t%-16s\t%-10s\n" $1 $2 $3 $4 $5 $6 $7 $8 $9

shift 9

if [ ! -n "$1" ]
then
a="false"
fi

done
