# !/bin/bash

echo "Enter an option" | tee -a "log.txt"
read option

if [ $option == 1 ]
then
	echo "Option: 1 selected at $(date)" | tee -a "log.txt"
	echo "Enter the file name" | tee -a "log.txt"
	read filename

	disp=$( ls -l $filename )

	echo ${disp:1:9}

	if [ ${disp:1:1} == "r" ]
	then 

		chmod u-r $filename
	else
		chmod u+r $filename

	fi

	if [ ${disp:2:1} == "w" ]
	then 
		chmod u-w $filename
	else
		chmod u+w $filename

	fi


	if [ ${disp:3:1} == "x" ]
	then 

		chmod u-x $filename
	else
		chmod u+x $filename

	fi

	if [ ${disp:4:1} == "r" ]
	then 

		chmod g-r $filename
	else
		chmod g+r $filename

	fi

	if [ ${disp:5:1} == "w" ]
	then 

		chmod g-w $filename
	else
		chmod g+w $filename

	fi


	if [ ${disp:6:1} == "x" ]
	then 

		chmod g-x $filename
	else
		chmod g+x $filename

	fi


	if [ ${disp:7:1} == "r" ]
	then 

		chmod o-r $filename
	else
		chmod o+r $filename

	fi

	if [ ${disp:8:1} == "w" ]
	then 

		chmod o-w $filename
	else
		chmod o+w $filename

	fi


	if [ ${disp:9:1} == "x" ]
	then 

		chmod o-x $filename
	else
		chmod o+x $filename

	fi
	disp=$( ls -l $filename )
	echo ${disp:1:9}
fi

if [ $option == 2 ]
then
	echo "Option: 2 selected at $(date)" | tee -a "log.txt"
	echo "Enter a file name" | tee -a "log.txt"
	read filename
	echo "Enter a string" | tee -a "log.txt"
	read strin
	
	grep $strin $filename
fi


if [ $option == 3 ]
then
	echo "Option: 3 selected at $(date)" | tee -a "log.txt"
	echo "enter the number of lines to read" | tee -a "log.txt"
	read num
	array=($(ls -p | grep -v /))
	
	touch dummy.txt
	filename=dummy.txt
	
	index=0
	for i in ${array[@]}
	do
	
		if [ $((index%2)) == 0 ]
		then
		
		   head -n $num $i >> $filename
		fi
		
		index=$(( $index + 1 ))
		
	done
	

	index=0
	
	for i in ${array[@]}
	do
	
		if [ $((index%2)) != 0 ]
		then
		
		  tail -n $num $i >> $filename
		  
		fi
		
		index=$(( $index + 1 ))
		
	done
	
fi


if [ $option == 4 ]
then
	echo "Option: 4 selected at $(date)" | tee -a "log.txt"
	echo "Enter a file name" | tee -a "log.txt"
	read filename
	echo "last modified date is" | tee -a "log.txt"
	date +%F -r $filename
	
	check=$(($(date +%s) - $(date +%s -r $filename)))
	if [ $check -gt 86400 ]
	then
	
		touch $filename
		echo "as the file was older, updated modified date is" | tee -a "log.txt"
		date +%F -r $filename
		
	fi
fi

if [ "$option" == "exit" ]
then
	exit 1
fi










