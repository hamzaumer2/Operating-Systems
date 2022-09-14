rows=0
echo "Enter Size of Triangle: "
read size

while [ $rows -lt $size ]
do
for((i=rows;i>=0;i--))
do
echo -n "$i "
done
echo

rows=$((rows+1))
done
