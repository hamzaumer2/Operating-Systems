#!/bin/bash

#HAMZA UMER FAROOQ - 200789
#BSCS-4-B  OS_ASSIGNMENT1

#Question 3


echo "PART A. "
sleep 2
echo "Going to Home Directory"; cd /home/$USER
echo "Listing files in /usr/share"; echo ; sleep 1 ; ls /usr/share



echo

echo "Part B. "
sleep 2

echo "GOING TO /usr/share " ; echo ; cd /usr/share
sleep 1
echo "Checking if we are here. " ; echo pwd
echo "Listing Files in current Directory AGAIN" ; echo ; sleep 2 ; ls
sleep 1
echo "NOW Listing Files in Directory (doc)" ; echo ; sleep 2 ; ls doc



echo

echo "Part C. "
sleep 2

echo "Listing files in Parent Directory: " ; echo ; sleep 2 ; ls ..
echo "Listing fiiles in one above Parent Directory: " ; echo ; sleep 2 ; ls ../..


echo

echo "Part D. "
sleep 2
echo "Tring the command (echo ~)" ; echo ; sleep 2 ; echo ~ ; echo ; echo "IT GIVES THE HOME DIRECTROY"


echo

echo "Part E. "
sleep 2
echo "Displaying Content of all (.txt) files in Home Directory" ; echo ; sleep 2 ; cat ~/*.txt

