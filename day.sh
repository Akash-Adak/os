echo "enter no of days:"
read total_days

year=`expr $total_days / 365 `

re=`expr $total_days % 365`

week=`expr $re / 7 `
day=`expr $re % 7 `

echo " year= $year , week =$week , day=$day"
