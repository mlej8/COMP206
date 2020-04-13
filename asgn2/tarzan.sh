#!/bin/bash

# Verify that script receives exactly two arguments
if [ $# -ne 2 ]
then	
	echo "Usage $0 filename tarfile" # If number of arguments passed to the script is not equal to two, throw an error message
	exit 1 # Exit program and return an error code 
fi

# Verify that tar file exists and is a regular file
if [ ! -f "$2" ] 
then
	echo "Error cannot find tar file $2" # If tar file is not found, throw an error message 
	exit 1 # Exit program and return an error code 
else
	# Execute the command to locate filename in the tar file. Store resuls in the result variable
	result=$(tar -tf $2 | grep -w $1)
	
	# If the result variable is null, then the file does not exist in the tar file, else it exists.
	if [ "$result" ]
	then 
		echo "$1 exists in $2"
	else 
		echo "$1 does not exist in $2"
	fi
fi

exit 0 # exit sayting there were no errors
