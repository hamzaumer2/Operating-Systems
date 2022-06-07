#!/bin/bash
#HAMZA UMER FAROOQ - 200789

echo "ENTER A NUMBER TO CHECK IF ITS EVEN OR ODD"
read check

if [ `expr $check%2` == 0 ]; then echo "THE NUMBER GIVEN IS EVEN"
else echo "THE NUMBER IS ODD"

fi
