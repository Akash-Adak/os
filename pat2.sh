echo "enter no:"
read n
a=1
for((i=n;i>=1;i--))
do
	for((j=1;j<=i;j++))
	do
		echo -n "$a"
		a=$((a+1))
	done
a=1
echo
done
