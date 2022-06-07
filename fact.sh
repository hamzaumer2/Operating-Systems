#!/bin/bash
#HAMZA UMER FAROOQ-200789


echo "INPUT A NUMBER TO FIND ITS FACTORIAL"

read number
fact=1

#while [ $fact -ge 1 ]
#do
#fact=$((fact*num))
#number=$((number-1))
#done

for((i=2;i<=number;i++)){
fact=$((fact*i))
}

echo "FACTORIAL IS $fact"
