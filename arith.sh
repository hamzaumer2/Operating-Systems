#!/bin/bash
# HAMZA UMER FAROOQ - 200789

echo "ENTER FIRST NUMBER"

read N1

echo "ENTER OPERAND (+, -, x, /)"

read OP

echo "ENTER SECOND NUMBER"

read N2

if [ $OP =  "+" ]; then
output="Sum=$((N1+N2))"
echo $output

elif [ $OP = "-" ]; then
output="Difference=$((N1-N2))"
echo $output

elif [ $OP = "x" ]; then
output="Product=$((N1*N2))"
echo $output

elif [ $OP = "/" ]; then
output= "Ratio=$((N1/N2)), with remainder=$((N1%N2))"
echo $output

else output="INVALID OPERAND"
echo $output
fi

echo "INSERTING ALL THIS DATA INTO A FILE OUTPUT.txt"
touch OUTPUT.txt

echo $output > OUTPUT.txt

echo "DATA SUCCESSFULLY INSTERTED INTO THE FILE. DO YOU WANT TO VIEW IT?(Y/n)"
read data1

if [ $data1 = "Y" ]; then cat OUTPUT.txt
elif [ $data1 = "y" ]; then cat OUTPUT.txt
fi
