echo "enter alphabet:"
read a
case $a in 
	[aeiouAEIOU]) echo "vowel";;
	*) echo "consonent"
esac
