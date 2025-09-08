echo "enter marks for operating system:"
read os
echo "enter marks for cloud computing:"
read cc
echo "enter number for data mining:"
read dm

total=$((os+cc+dm))
per=$((total * 100 /300))

if [ $per -ge 50 ]
then 
	echo "passed"
elif [ $per -ge 40 -a $per -lt 50 ]
then
	echo " Result withhold , appear for improvement exam"
else
	echo "failed"
fi
