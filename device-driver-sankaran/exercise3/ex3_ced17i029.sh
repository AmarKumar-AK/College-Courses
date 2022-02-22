 
TIMEFILE=./timefile.txt
url=https://github.com/AmarKumar-AK
# read -p "Enter the URL :- " url
echo "Webpage :- "$url
sleep_time=10
i=0
while [ $i -lt 10 ]
do
start_time=$(date)
wget -o log.txt -E $url
end_time=$(date)
echo "start_time: $start_time" >> $TIMEFILE
echo "end_time: $end_time" >> $TIMEFILE
echo "Downloaded" $(($i+1))"st time "
sleep $sleep_time
((i++))
done
