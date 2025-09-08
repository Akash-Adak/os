echo "enter 1st:"
read a
echo "enter 2nd:"
read b

echo "1.Addition"
echo "2.Substraction"
echo "3.Multiplication"
echo "4.Division"
echo "enter your choice:"
read choice
case $choice in
	1) echo "Addition is : `expr $a + $b ` " ;;
	2) echo "Substraction is: `expr $a - $b `" ;;
	3) echo "Multiplication is: `expr $a \* $b `";;
	4) echo "Division is : `expr $a / $b ` " ;;
	*) echo "invalid choice"
esac

