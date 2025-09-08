echo "enter size of array:"
read n
echo "enter elements":
for((i=0;i<n;i++))
do
	read arr[$i]
done

echo "enter search element:"
read search 
p=-1
for((i=0;i<n;i++))
do
	if [ $search -eq   ${arr[$i]} ]
	then
		p=$((i+1))
		break;
	fi
done

if [ $p -eq -1 ] 
then
	echo " not foundp"
else 
	echo " $search found at $p"
fi

