echo "enter size of array:"
read n
for((i=0;i<n;i++))
do
	read arr[$i]
done

min=${arr[0]}
max=${arr[0]}
for((i=0;i<n;i++))
do
	if [ $min -gt ${arr[$i]} ]
	then 
		min=${arr[$i]}
	fi
	if [ $max -lt ${arr[$i]} ]
	then
		max=${arr[$i]}
	fi
done
echo "maximum is : $max"
echo "minimum is : $min"
