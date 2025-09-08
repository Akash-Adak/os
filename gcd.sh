echo "enter 1st:"
read a
echo "enter 2nd:"
read b
c=$a
if [ $b -lt $a ]
then 
	c=$b
fi

while [ $c -ne 0 ]
do
x=$(( a % c))
y=$(( b % c))

	if [ $x -eq 0 -a $y -eq 0 ]
	then 
		echo "gcd of  $a and $b is : $c "
		break;
	fi
c=$((c-1))
done


