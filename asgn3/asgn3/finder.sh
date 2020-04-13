#!/bin/bash 

# Verify if a3config file is in the current directory and is executable
if [ ! -f a3config ]
then 
	echo "Error cannot find a3config"
	exit 1 # return an error code of 1 to specify that a3config files has not been found.
fi

# Else if a3config file exists, read variables from this file using source 
source a3config

# If either of the variables DIRNAME or EXTENSION is not present in a3config or their values are empty, display an error message
if [ -z $DIRNAME ] || [ ! $DIRNAME ] || [ ! $EXTENSION ] || [ -z $EXTENSION ] 
then 
	echo "Error DIRNAME and EXTENSION must be set" 
	exit 2 # return an error code of 2 to specify that DIRNAME and EXTENSION are empty or undefined
fi 

# If the directory mentionned in DIRNAME does not exist, throw an error message and terminate with a non zero exit code 
if [ ! -d $DIRNAME ] 
then
	echo "Error directory $DIRNAME does not exist"
	exit 3 
fi

# Locate files in the directory using grep 
files=`ls $DIRNAME | grep .$EXTENSION`

# If the script can't locate any files in the directory that have the expected extension, display a message and terminate with a zero exit code 
if [ ! "$files" ] || [ -z "$files" ] # if string is null or length is zero
then 
	echo "Unable to locate any files with extension $EXTENSION in $DIRNAME"
	exit 0	
fi

# Search for files with $EXTENSION in $DIRNAME
output=`ls $DIRNAME*.$EXTENSION`

# If the script is able to locate files in the directory, and the value of $SHOW is true , then it shoud list the names of the files along with the contents of each file and terminate with zero exit code
if [ "$SHOW" = "true" ] 
then 
	for path in $output
	do 
		echo "$path"
		cat $path
	done
	exit 0 # terminate with 0 exit code
fi

# If the script is able to locate files in the directory, but the value of SHOW is not set to true or is missing from a3config, then it should list the names of the files, but not display the contents of files and terminate with a zero exit code
if [ ! "$SHOW" ] || [ -z "$SHOW" ] || [ "$SHOW" != "true" ]  
then
	for path in $output
	do
		echo "$path"
	done
	exit 0 # terminate with 0 exit code
fi 

