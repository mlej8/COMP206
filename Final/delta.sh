#! /bin/bash

# Shell script that accepts two directories as its input and then displays the names of files in each directory that have identical names but differ in the contents.

# Terminate if it is not passed exactly two arguments as input
if [ $# -ne 2 ]
then
    echo -e "Error $0 requires two directories as arguments.\nUsage $0 dir1 dir2"
    exit 1 # exit with error code 
fi

# Save positional arguments to readable variable names
dir1=$1
dir2=$2

# Verify if the two arguments are identical. 
if [ $dir1 = $dir2 ]
then
    echo -e "Error $0 requires two distinct directories as arguments.\nUsage $0 dir1 dir2"
    exit 2 # exit with error code 
fi

# Check if either of the arguments passed is not the name of a valid directory 
if [ ! -d $dir1 ] 
then
    echo -e "Error $0 requires valid directories as arguments.\n$dir1 is not a valid directory"
    exit 3 # exit with error code 
fi
if [ ! -d $dir2 ] 
then
    echo -e "Error $0 requires valid directories as arguments.\n$dir2 is not a valid directory"
    exit 3 # exit with error code 
fi

# iterate over every file of both directories
for file1 in `ls $dir1`
do
    # The script should also ignore any sub directories (as well as files under them) that are inside the original directories passed as its argument, e.g. only do it for valid files and not subdirectories
    if [ -f $dir1/$file1 ] # verify it is a valid file (not a directory) compare with all files in dir2    
    then 
        for file2 in `ls $dir2`
        do
            # verify if both files have the same name and that file2 is a valid file (not a directory)
            if [ -f $dir2/$file2 ] && [ $file1 = $file2 ]
            then
                # displays the names of files in each directory that have identical names but differ in their contents.
                if [ -n "`diff $dir1/$file1 $dir2/$file2`" ] # if the content is different (i.e. length of diff != 0), print the name of the file
                then 
                    echo $file1
                fi
            fi
        done 
    fi
done 
