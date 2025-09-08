echo "enter 1st no :"
read a
echo "enter 2nd no:"
read b
echo "enter 3rd no :"
read c

if [ $a -gt $b -a  $a -gt $c ]
then
	echo "$a is greater"
elif [ $b -gt $c ]
then 
	echo " $b is greater"
else 
	echo " $c is greater"
fi

