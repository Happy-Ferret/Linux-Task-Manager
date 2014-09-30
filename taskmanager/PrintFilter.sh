#This will print the running processes as returned by Filter.sh


sh Filter.sh > ProcessList

echo -e "The Total Number Of Processes : " `wc -l < ProcessList`
echo -e "\n"

printf "%-5s\t%-5s\t%-8s\t%-8s\t%-8s\t%-5s\t%-5s\t%-16s\t%-10s\n" "PID" "STAT" "VSZ" "RSS" "SZ" "%CPU" "%MEM" "Command" "User"

cat ProcessList

