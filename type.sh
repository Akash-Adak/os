echo "eneter a character:"
read a

case $a in
	[[:lower:]]) echo "lowercase";;
	[[:upper:]]) echo "uppercase";;
	[0-9]) echo "digit";;
	*) echo "special symbol";;
esac
