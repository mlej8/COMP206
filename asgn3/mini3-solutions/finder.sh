#!/bin/bash

#	This script checks if files of a certain extension are present
# in a certain directory and then displays them.
# Uses a configuration script to locate the directory and extension

# Terminate if we cannot locate the config file.
if [[ -r a3config ]]
then
  . a3config
else
	echo "Error cannot find a3config"
	exit 1
fi

# DIRNAME and EXTENSION are mandatory variables.
#  terminate if they do not exist.
if [[ -z $DIRNAME || -z $EXTENSION ]]
then
	echo "Error DIRNAME and EXTENSION must be set"
	exit 2
fi

# Ensure that DIRNAME is pointing to a valid directory.
if [[ ! -d $DIRNAME ]]
then
	echo "Error directory $DIRNAME does not exist"
	exit 3
fi

# Status to check if we actually located files..
found=false
# Get the list of files.
FILES=`ls -d $DIRNAME/*.$EXTENSION 2>/dev/null`
# Iterate over the files and list them.
for f in $FILES
do
	if [[ -f $f ]]
	then
		found=true
		echo $f
		# Display the contents if we are asked to do so.
		if [[ "$SHOW" == true ]]
		then
			cat $f
		fi
	fi
done

# We did not find any file.
if [[ $found = false ]]
then
	echo "Unable to locate any files with extension $EXTENSION in $DIRNAME"
fi

# Terminate with success code.
exit 0
