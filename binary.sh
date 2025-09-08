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
s=0
e=$((n-1))
while [ $s -le $e ]
do
	mid=$(((s+e) / 2))
	if [ $search -eq ${arr[$mid]} ]
	then
		p=$((mid +1))
		break;
	elif [ $search -lt ${arr[$mid]} ]
	then
		e=$((mid -1))
	else
		s=$((mid+1))
	fi
done

if [ $p -eq -1 ] 
then
	echo " not founp"
else 
	echo " $search found at $p"
fi

