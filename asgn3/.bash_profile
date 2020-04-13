# Bash login script

# Source global definitions 
if [ -f /usr/socs/Procfile ]
then 
	. /usr/socs/Profile
fi

# User specific aliases and functions 
echo "Welcome to `hostname`!" # Display hostname when user logs in 
echo "You have `who | grep $USER | wc -l` login sessions to this host." # Log number of login sessions user has on current host 

# Alias comp206 so that typing it executes cd ~/Projects/COMP206
alias comp206="cd ~/Projects/COMP206"

# Set shell's prompt to include username, hostname, current directory and time 
export PS1="\u@\H[\t]:\w$"

# Execute fortune command to display any random quotes
echo `fortune`

# Additional feature: alias .. so that typing it executes "cd .." 
alias ..="cd .."
alias cx="chmod +x" # add an additional shortcut for giving executable permission to a file 

