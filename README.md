# Simple Shell Project 
 
This is a simple shell project created by Harrison Mwatoki and More Argwings Kodhek. 
 
## Compilation 
 
To compile the code, use the following command:
console
'gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh'
This will compile all the  *.c  files in the current directory and create an executable file named  hsh . 
 
To run the shell, use the following command:
console
./hsh
## Usage 
 
This simple shell project allows the user to enter commands just like a typical shell. The shell can handle built-in commands and external commands. 
 
The following built-in commands are included: 
 
-  exit : Exits the shell. 
-  env : Prints the environment. 
 
To run an external command, simply enter the name of the command followed by any arguments. For example:
console
ls -l /tmp
## Files 
 
The main source code is located in the following files: 
-  main.c : starting point 
-  loopshell.c : Contains the main shell logic.Runs a loop to take in commands
-  parse_args.c : Contains functions for parsing input. 
-  execute_command.c : Contains functions for executing commands. 
-  Find_command.c : function to find the command in the PATH
 
## Authors 
 
This simple shell project was created by Harrison Mwatoki and More Argwings Kodhek. This project is part of SWE bootcamp @ALX Africa. 