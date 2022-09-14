# !/bin/bash

var1=$1
var2=$2

if [ "$var1" = "left" ]
then

	for (( row=1; row<=var2; row++ ))
	do  
		for (( col=1; col<=row; col++ ))
		do  
			echo -n "*"
		done
		echo 
	done

	for (( row=var2-1; row>=1; row-- ))
	do  
		for (( col=1; col<=row; col++ ))
		do  
			echo -n "*"
		done
		echo 
	done

elif  [ "$var1" = "right" ]
then
space=$(( $var2 - 1 ))
	for (( row=1; row<=var2; row++ ))
	do  
		for (( col=1; col<=space; col++ ))
		do  
			echo -n " "
		done
		for (( col=1; col<=row; col++ ))
		do  
			echo -n "*"
		done
		echo 
		space=$(( $space - 1 ))
	done
	
	space=1
		
	for (( row=var2-1; row>=1; row-- ))
	do  
		for (( col=1; col<=space; col++ ))
		do  
			echo -n " "
		done
		for (( col=1; col<=row; col++ ))
		do  
			echo -n "*"
		done
		echo 
		space=$(( $space + 1 ))
	done

elif  [ "$var1" = "full" ]
then

space=$(( $var2 - 1 ))
extra=0
	for (( row=1; row<=var2; row++ ))
	do  
		for (( col=1; col<=space; col++ ))
		do  
			echo -n " "
		done
		star=$(( $row + extra ))
		for (( col=1; col<=star; col++ ))
		do  
			echo -n "*"
		done
		echo 
		extra=$(( $extra + 1 ))
		space=$(( $space - 1 ))
	done
	
	space=1
	extra=$(( $var2 - 2 ))
		
	for (( row=var2-1; row>=1; row-- ))
	do  
		for (( col=1; col<=space; col++ ))
		do  
			echo -n " "
		done
		star=$(( $row + extra ))
		for (( col=1; col<=star; col++ ))
		do  
			echo -n "*"
		done
		echo 
		extra=$(( $extra - 1 ))
		space=$(( $space + 1 ))
	done
else 
	echo "Invalid Inpt Please run the program again"

fi
