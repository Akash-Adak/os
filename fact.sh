echo "enter a given number:"
read a

fact=1
while [ $a -gt 1 ]
do
fact=$((fact*a))
a=$((a-1))
done
echo "factorial of $a is : $fact "
