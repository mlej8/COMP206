#!/bin/bash

# Check for correct number of arguments
if [[ $# -ne 2 ]]
then
	echo "Usage ./tarzan.sh filename tarfile"
	exit 1
fi

# Store arguments passed to the script
filename=$1 tarfile=$2

# Check if the tar file exists, else terminate.
if [[ ! -f $tarfile ]]
then
	echo "Error cannot find tar file $tarfile"
	exit 2
fi

# List the contents of the tar file and have grep search for filename.
files=`tar -t -f $tarfile | grep '/'${filename}'$'`

# Check if we found the file that was being serached and report the status.
if [[ -z "$files" ]]
then
	echo "$filename does not exist in $tarfile"
else
	echo "$filename exists in $tarfile"
fi
