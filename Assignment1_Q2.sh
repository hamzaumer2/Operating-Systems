#!/bin/bash

#HAMZA UMER FAROOQ - 200789
#BSCS-4-B  OS_ASSIGNMENT1

#Question 2


NOW_DT=$(date +"%m-%d-%Y")
NOW_TM=$(date +"%T")
echo "Select from Menu (1/2/3/4/e)"
echo
echo "ALL DATA WILL BE STORED IN A LOG FILE. Creating the log file"
touch logfile_Q2.txt
echo
echo "1. INPUT FILENAME AND INVERT PERMISSIONS AND DISPLAY"
echo "2. INPUT FILENAME AND SEARCH. THEN OUTPUT THE LINE IN WHICH THE STRING IS FOUND. IF dot(.) in string a character will fill its place"
echo "3. CREATE a NEW FILE and ADD CONTENTS OF CURRENT DIRECTORY TO THE NEWLY MADE FILE. INPUT (N) will be taken then it will split such that first N lines at even and last N at odd position"
echo "4. INPUT FILENAME and CHECK MODIFIED DATE. IF GREATER THAN 24hr then, change to current date and time. Display Output on terminal"
echo "e. Exit the program"
read option

case $option in

1)
	echo "" >> logfile.txt
	echo "Option $option Selected at date and time: $NOW_DT, $NOW_TM" >> logfile.txt
	echo "Enter Filename(without Extension) in current directory to check attributes: "
	read check_attrib
	echo "Enter Extension of Filename to check attributes: "
	read check_attrib2
	if [ -e $check_attrib.$check_attrib2 ]
	then
		echo "File Name is: $check_attrib.$check_attrib2" >> logfile.txt
		echo "FILE PERMISSIONS ARE: "
		 ls -l $check_attrib.$check_attrib2

			if [ -w $check_attrib.$check_attrib2 ]
				then chmod -w $check_attrib.$check_attrib2
				else chmod +w $check_attrib.$check_attrib2
			fi


			if [ -r $check_attrib.$check_attrib2 ]
				then chmod -r $check_attrib.$check_attrib2
				else chmod +r $check_attrib.$check_attrib2
			fi


			if [ -x $check_attrib.$check_attrib2 ]
				then chmod -x $check_attrib.$check_attrib2
				else chmod +x $check_attrib.$check_attrib2
			fi

echo "New Permissions are: "
ls -l $check_attrib.$check_attrib2
	echo "Permissions Changed!!" >> logfile.txt
	echo "Updated Permissions are: " ls -l >> logfile.txt


			else echo "FILE DOES NOT EXIST"
				echo "No File Exists by the name of $check_attrib.$check_attrib2" >> logfile.txt
			fi

;;

2)
	echo "" >> logfile.txt
	echo "Option $option Selected at date and time: $NOW_DT, $NOW_TM" >> logfile.txt
	echo "Enter Filename (NO EXTENSIONS) to search: "
	read check_filename
	echo "Enter Extension of File to search: "
	read check_filename2
	echo "Enter String to Search: "
	read check_string

if [ -e $check_filename.$check_filename2 ]
        then
		echo "File Name: $check_filename.$check_filename2" >> logfile.txt
		echo "String: $check_string" >> logfile.txt
		echo "Lines in which String was found: " >> logfile.txt
		grep "$check_string" $check_filename.$check_filename2 >> logfile.txt



	else
		echo "NO SUCH FILE EXISTS"
		echo "Filename $check_filename.$check_filename2 DOES NOT EXIST" >> logfile.txt
fi



;;

3)
	echo "" >> logfile.txt
	echo "Option $option Selected at date and time: $NOW_DT, $NOW_TM" >> logfile.txt
	echo "Creating Dummy File (dummy.txt)" ; touch dummy.txt
	echo "Enter Number of Lines to add to file dummy.txt" ; read N
	echo "Enter Number of lines to print(will take N*Even from top and N*Odd from Bottom): "
read line


touch dumpodd.txt
touch dumpeven.txt

awk 'NR % 2' * >> dumpeven.txt

head -n $line dumpeven.txt >> dummy.txt

awk 'NR % 2 == 1' * >> dumpodd.txt

tail -n $line dumpodd.txt >> dummy.txt
	echo "Dummy Created!!!"



	echo "Dummy.txt is creted and $N lines of each files copied in it" >> logfile.txt
;;
4)
	echo "" >> logfile.txt
	echo "Option $option Selected at date and time: $NOW_DT, $NOW_TM" >> logfile.txt

        echo "Enter File Name (WITHOUT EXTENSIONS)"
        read filetime
        echo "Enter File Extension"
        read filetime2
	if [ -e $filetime.$filetime2 ]
        	then

                	NT=86400
             		CT=$(date +%s)
			echo "DTM of File $file_time.$file_time2 is: " date -r $filetime.$filetime2 >> logfile.txt
               		FT=$(stat $filetime.$filetime2 -c %Y)
                	TimeDiff=$(expr $CT - $FT)

                	if [ $TimeDiff -gt $NT ]
                        	then
                                	echo "FILE is OLDER THAN 24hrs. CHANGING TIME TO CURR TIME"
					echo "Modified Date"
					touch $filetime.$filetime2

                        	else
                                	echo "FILE is made within 24hrs"
					echo "DID NOT MODIFY DATE" >> logfile.txt

                	fi
	else
		echo "NO FILE EXISTS"
		echo "FILE $filetime.$filetime2 DOES NOT EXIST" >> logfile.txt

	fi


;;
"e")
	echo "" >> logfile.txt
	echo "Option $option Selected at date and time: $NOW_DT, $NOW_TM" >> logfile.txt

;;
*)
	echo "" >> logfile.txt
	echo "INCORRECT OPTION SELECTED ($option) at date and time: $NOW_DT, $NOW_TM" >> logfile.txt
;;

esac
