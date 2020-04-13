#!/bin/bash

c=0 # tracks if contents of the file should be displayed (c=1) or not (c=0)
a=0 # indicates if output should include all matching files (a=1) or not (a=0)
path="." # indicates directory under which the script should look for files 

# Function that prints an error and usage message if proper arguments are not passed into the script.
usage() {
	
	echo -e "Error missing the pattern argument.\nUsage $0 [-c] [-a] pattern [path]"

}

# Function to exit and returns an error code 
exit_abnormal(){
	usage
	exit 1
}

while [ $# -ne 0 ]
do
	case "$1" in
		-c)
			c=1
			;;
		-a)
			a=1
			;;
		-?)
			exit_abnormal
			;;

		/*)
			path=$1
			;;
		*)
			pattern=$1
			;;
	esac
	shift
done

# Ensure that the script is passed propper arguments (i.e. pattern is passed as input to the script)
if [ ! "$pattern" ] # If no pattern variable has been passed, it would be null, therefore exit script
then
	exit_abnormal
fi

# If the directory passed as argument to the script does not exist, the script should display this fact
if [ ! -d "$path" ] # -d returns true if path exists and is a directory. If test returns false, print error message
then
	echo "Error $path is not a valid directory"
	exit 2
fi

# Query all results and concatenate output into one single string
result=`ls "$path" | grep "$pattern"`

# If script can't find any files with specified pattern in its name, it will display an error message
if [ ! "$result" ] # If the result is NULL
then
        echo "Unable to locate any files that has pattern $pattern in its name in $path."
	exit 2
fi 

# Format output depending on selected options
if [ "$c" -eq 1 ] && [ "$a" -eq 1 ]
then
	for i in $result
	do
		if [ "$path" = "." ] 
		then
			tmp="$PWD/$i"
		else
			tmp="$path/$i"
		fi
		echo -e "==== Contents of: $tmp ====\n`cat $tmp`"
	done
elif [ "$c" -eq 1 ]
then
	i="$(ls "$path" | grep "$pattern" | head -1)"
		if [ "$path" = "." ] 
		then 
			tmp="$PWD/$i"
	        else
			tmp="$path/$i"
	 	fi	      
		echo -e "==== Contents of: $tmp ====\n`cat $tmp`"
elif [ "$a" -eq 1 ] # When -a option is passed, include all the files that match the pattern
then
	for i in $result
	do 
		if [ "$path" = "." ]
		then
		        tmp="$PWD/$i"
		else	
			tmp="$path/$i"
		fi
		echo "$tmp"
	done
else # When -a option is not passed, include only one matching file in the output 
	tmp="$(ls "$path" | grep "$pattern" | head -1)"
	if [ "$path" = "." ] 
	then
		output="$PWD/$tmp"
	else
		output="$path/$tmp"
	fi
	echo "$output"
fi

exit 0
