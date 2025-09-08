echo "enter size of array:"
read n

echo "enter elements:"
for((i=0;i<n;i++))
do
	read ar[$i]
done
echo "before reverse:"
for((i=0;i<n;i++))
do 
	echo "${ar[$i]}"
done

echo "after reverse:"
for((i=n-1;i>=0;i--))
do
	echo "${ar[$i]}"
done
