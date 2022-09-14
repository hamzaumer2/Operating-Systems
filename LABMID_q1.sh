#!/bin/bash

#HAMZA UMER
#BSCS-4-B
#LAB MID EXAM OS
#QUESTION 1

echo "ENTER FIRST NUMBER"
read n1
echo "ENTER SECOND NUMBER"
read n2
echo "ENTER OPERATOR WITHOUT BRACKETS"
echo "(*) FOR MULTIPLICATION"
echo "(/) FOR DIVISION"
echo "(!) FOR FACTORIAL"
read n0
fact=1
case "$n0" in

"*")
echo "PRODUCT OF THE TWO NUMBERS ($n1 * $n2) IS: $((n1*n2))"

;;

"/")
echo "RATIO OF THE TWO ($n1 / $n2) NUMBERS IS: $((n1/n2))"
;;

"!")
echo "!ctorial"


fact=1
for((i=2;i<=n1;i++)){
fact=$((fact*i))
}


echo "FACTORIAL OF $n1 is: $fact"

fact=1
for((i=2;i<=n2;i++)){
fact=$((fact*i))
}
echo "FACTORIAL OF $n2 is: $fact"

;;
*)
echo "INCORRECT OPTION SELECTED!!!!!"
;;
esac
