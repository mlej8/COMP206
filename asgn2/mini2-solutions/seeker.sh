#!/bin/bash

# We will use these shell variables to keep track of the options passed to the script.
displayfile=false
allfiles=false

# EXPLORE on your own !!
# Instead of the below code to check for options, explore getopts to do it in a more compact manner
#    https://www.shellscript.sh/tips/getopts/

# Check if we are passed an option.
#  Find the first option passed if any.
if [[ $1 =~ ^- ]]
then
	# -c option to display files is passed
	if [[ $1 = "-c" ]]
	then
		displayfile=true
	else
		# -a to include all matching files is passed.
		if [[ $1 = "-a" ]]
		then
			allfiles=true
		else # Not a valid option
			echo "Error $1 is an incorrect switch."
			echo "Usage ./seeker.sh [-c] [-a] pattern [path]"
			exit 1
		fi
	fi
	# First argument is processed, let us move to the second argument.
	shift 1
fi

# Same logic as above to look for a possible second option.
# Both code blocks can be combined and simplified using getopts or a loop.
if [[ $1 =~ ^- ]]
then
	if [[ $1 = "-a" ]]
	then
		allfiles=true
	else
		if [[ $1 = "-c" ]]
		then
			displayfile=true
		else
			echo "Error $1 is an incorrect switch."
			echo "Usage ./seeker.sh [-c] [-a] pattern [path]"
			exit 1
		fi
	fi
	shift 1
fi

# Make sure the search pattern is passed as an argument.
if [[ $# -eq 0 ]]
then
	echo "Error missing the pattern argument."
	echo "Usage ./seeker.sh [-c] [-a] pattern [path]"
	exit 2
fi

pattern=$1
shift 1

# Did we get any random arguments?
if [[ $# -gt 1 ]]
then
	echo "Error surplus arguments."
	echo "Usage ./seeker.sh [-c] [-a] pattern [path]"
	exit 3
fi

# Store current directory in the shell. If we are not passed a directory name to search under, we search in current directory.
dirpath=$PWD
if [[ $# -eq 1 ]]
then
  dirpath=$1
fi

# Check if the directory argument passed to the script is good.
if [[ ! -d $dirpath ]]
then
  echo "Error $dirpath is not a valid directory"
	exit 4
fi

# Find files that match the pattern.
files=`ls -d $dirpath/*${pattern}* 2>/dev/null`
foundfile=false

# Iterate over each file that was found.
for f in $files
do
	if [[ -f $f ]]
	then
		# If we are told to display file, then cat it.
		if [[ $displayfile = "true" ]]
		then
	  	echo ==== Contents of: $f ====
			cat $f
		else
	  	echo $f 
		fi
	# Means that we have found and reported at least one file that matches the pattern.
	foundfile=true
	fi

	# If we have to include only one file in the output, then terminate once we have found a file.
	if [[ $allfiles = "false" && $foundfile = "true" ]]
	then
	  exit 0
	fi
done

# No files turned up in our search.
if [[ $foundfile = "false" ]]
then
  echo "Unable to locate any files that has pattern "$pattern" in its name in $dirpath."
fi
# EXPLORE on your own !!
# Can you make use of the find command to re-write this script a lot more efficiently?
