# Bash login script

# Source global definitions 
if [ -f /usr/socs/Procfile ]
then 
	. /usr/socs/Profile
fi

# Display hostname when user logs in
echo "Welcome to `hostname`!" 

# Log number of login sessions user has on current host 
echo "You have `who | grep -c $USER` login sessions to this host."  

# Alias comp206 so that typing it executes cd ~/Projects/COMP206
alias comp206="cd ~/Projects/COMP206"

# Set shell's prompt to include username, hostname, current directory and time by setting the environment variable PS1 
export PS1="\u@\H[\t]:\w$"

# Execute fortune command to display any random quotes
echo `fortune`

# Additional feature: alias .. so that typing it executes "cd .." 
alias ..="cd .."
alias cx="chmod +x" # add an additional shortcut for giving executable permission to a file 

