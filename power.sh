echo "enter a number:"
read num

echo "enter power:"
read pow

res=$(echo " $num ^ $pow " |  bc)

echo " $num ^ $pow : $res "
