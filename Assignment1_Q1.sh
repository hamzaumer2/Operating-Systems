#!/bin/bash
#HAMZA UMER - 200789
#BSCS-4-B  OS_ASSIGNMENT1

#Question 1


echo "THIS PROGRAM WILL MAKE 3 PATTERNS USING A SINGLE INPUT"
echo
echo "LEFT, RIGHT, and COMPLETE DIAMOND"
echo

echo "ENTER SIZE OF REQUIRED DIAMOND PATTERNS: "
read size
echo
#for values from 1* till the given size*. PRINTS THE TOP HALF OF THE PATTERN



echo "Q1. Left Aligned Half Diamond"
echo

for((i=0;i<=$size;i++))
do
for((j=$((i-1));j>=0; j--))
do
echo -n "*"
done
echo ""
done

#for values from given size* till 1*. PRINTS THE BOTTOM HALF OF THE PATTERN

for((k=1;k<$size;k++))
do
for((l=$k;l<$size;l++))
do
echo -n "*"
done
echo  ""
done



sleep 3
echo ""
echo "Q2. Right Aligned Half Diamond"
echo ""

i=0
while [ $i -le $size ]
do
    k=$i
    while [ $k -le $size ]
    do
        echo -n " "
        k=$((k+1))
    done
    j=$i
    while [ $j -gt 0 ]
    do
        echo -n "*"
        j=$((j-1))
    done
    i=$((i+1))
    echo
done

i=0
while [ $i -le $size ]
do
    j=$i
    while [ $j -ge 0 ]
    do
        echo -n " "
        j=$((j-1))
    done

    k=$i
    while [ $k -lt $size ]
    do
        echo -n "*"
        k=$((k+1))
    done
    i=$((i+1))
    echo
done





sleep 3
echo ""
echo "Q3. Complete Diamond"
echo ""

for((i=1;i<=$size;i++))
do
   for((j=$size;j>=i;j--))
   do
   echo -n " "
   done
   for((c=1;c<=i;c++))
   do
   echo -n " *"
   done
echo ""
done

for((i=$((size-1));i>=1;i--))
do
   for((j=i;j<=$((size-1));j++))
   do
   if [ $j -eq $((size-1)) ]
   then
   echo -n " "
   fi
   echo -n " "
   done
   for((c=1;c<=i;c++))
   do
   echo -n " *"
done
echo ""
done
