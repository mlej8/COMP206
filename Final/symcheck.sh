#! /bin/bash

# Bash shell script symcheck.sh accepts a textfile as its argument and prints whether a particular word is symmetric by using symword.c.

# The script should throw an appropriate usage message if it is not passed a filename argument.
if [ $# -ne 1 ]
then
    echo -e "Error: wrong usage.\nCorrect usage: $0 words.txt"
    exit 1 # exit with error code 
fi

# Use more readable variable name for positional arguments 
file=$1

# It should also throw an appropriate error message if it cannot find the filename passed as argument or is not a valid file
if [ ! -f $file ] 
then
    echo -e "Error: $file does not exist or is not a file.\nPlease enter a valid filename."
    exit 2 # exit with error code 
fi

# Assume the C file exists in the same directory, compile symword.c 
SRC="symword.c"
EXEC="symword.out"
gcc -o $EXEC $SRC 

# Give executable permission
chmod 777 $EXEC

# Iterate over all words in text file
for w in `cat $file | tr -d '\r'` # piping output of cat to remove carriage returns, e.g. '\r' because if we included '\r' the argument passed to symcheck.c would be i.e. level\r which is not symmetric but in fact it is.
do
    ./$EXEC $w
    if [ "$?" -eq 0 ]
    then 
        echo "$w is symmetric"
    else 
        echo "$w is not symmetric"
    fi
done
