who | wc -l #NO OF ACTVE USERS

################################################
read FRUIT

case "$FRUIT" in
   "apple") echo "Apple pie is quite tasty." 
   ;;
   "banana") echo "I like banana nut bread." 
   ;;
   "kiwi") echo "New Zealand is famous for kiwi." 
   ;;
	*) echo "HUH??";;
esac

##################################################
a=0

while [ $a -lt 10 ]
do
   echo $a
   a=`expr $a + 1`
done

i=0

while [ $i -le 2 ]
do
  echo Number: $i
  ((i++))
done
###################################################

for i in {1..5}
do
   echo "Welcome $i times"
done

for i in {0..10..2}
  do 
     echo "Welcome $i times"
 done

###################################################


if [ $marks -ge 80 ]
then
  echo "Excellent"
 
elif [ $marks -ge 60 ]
then
  echo "Good"
 
else
  echo "Satisfactory"
fi
