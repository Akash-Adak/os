echo "enter size of arr:"
read n

echo "enter elements:"
for(( i=0;i<n;i++))
do
	read ar[$i]
done

echo "elements are:"
for((i=0;i<n;i++))
do
	echo "${ar[$i]}"
done
