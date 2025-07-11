# os-project
made by
abeer mourtaja 220210406
Tasneem algazali 220211910
taghreed alqudwa 

#Shell definition 
#A shell is a command-line interpreter that enables Linux and Unix users to interact with #their operating systems using command-line interfaces. This type of program allows users to #effectively and directly communicate with their operating systems.


<help>

myshell supports the following commands:

    cd    clear      dir    echo  environ

    help  myshell  pause  pwd   quit   


An executable external file can also contain these commands. 
To view the entire user manual, type "help more". To see information about a specific function, type in:

"help help" ---see the function of 'help' command;

"help command" ---see the list of internal commands;

"help shell"---show more detail about this shell;

"help bat"---see  how the shell execute a batchfile;

"help i/o redirection"---learn about the i/o redirection;

"help background"---learn about the background mode; 

"help path"---see the format of filepath or dir path. 

#





<help shell>

To view more details about this shell;

The shell begins by taking input from the user through standard input, which is a file descriptor that represents anything entered on the command line. After displaying the prompt, the shell receives the input as a string, allowing it to move on to the next steps in the process.
The shell process involves the following steps:

   * interprets the input,

   * takes appropriate action, and

   * finally prompts for more input.
#

<help command> <help commands> <help internal command> <help internal commands>
To view a list of internal commands:
To access detailed usage information for each command, write "help [command]"
Example:  help cd

myshell supports the following commands:

    cd    clr      dir    echo  environ

    help  myshell  pause  pwd   quit   

#



<help bat> <help batchfile>


myshell is capable of obtaining its command line input from a batch file.
If myshell is invoked with a command line argument:

Example:   myshell test.bat

the batch file "test.bat" is assumed to contain a series of commands for the shell to execute. When the end of the file is reached, the shell will exit. If myshell is invoked without a command line argument, it will prompt the user for input through the display. For Additional information about myshell you can accessed by typing "help myshell".

#

<help i/o redirection> <help I/O Redirection> <help io redirection>

myshell supports redirecting both standard input (stdin) and standard output (stdout) through the use of input/output (I/O) redirection.

Example:   progName arg1 arg2 <inputFile > outputFile

This command will run the program " progName " with the arguments "arg1" and "arg2".
In this case, the standard input (stdin) file stream is replaced by " inputFile " and the standard output (stdout) file stream is replaced by " outputFile ".
The file can be specified using the full path, such as "/home/username/test.txt".
To learn more about the file path format, type "help path" for additional information.
Input redirection >>> stdin redirection, is supported for the internal command’s "cd", "dir", and "echo".
Output redirection >>> stdout redirection, is available for the internal command’s "dir", "environ", "echo", "help", and "pwd".


The file can be given by the full path as:

    /home/username/test.txt

As to the file path format, type "help path" to get more information.



Input redirection --i.e. stdin redirection-- is possible for the internal commands: cd, dir, echo.

Output redirection --i.e. stdout redirection-- is possible for the internal commands: dir, environ, echo, help, pwd.



<help redirection> 

   * when the redirection token is < then the inputfile is opened if it exists, or a "Path Error" wil be reported in the screen.

     e.g.      cd  <test.txt 

   * when the redirection token is > then the outputfile is created if it does not exist and truncated if it does.

    e.g.      ls   >test.txt

   * when the redirection token is >> then outputfile is created if it does not exist and appended to if it does.

     e.g.    environ  >>test.txt

Sometimes you can use more than one token to open several files as input or/and  output.

    e.g.   echo  <name.txt >names.txt

             dir  >name.txt >names.txt 

If the file can’t be opened due to a lack of read or write permission, an "Open Error" message will be displayed on the screen.

#


<help background execution> <help background>

To learn about the background mode;
Normally, when a command is executed, you have to wait for it to complete before entering another command. This can be time-consuming, especially when executing a batchfile. Background execution allows you to continue working while the command is being executed. To execute a command in the background, you can append an ampersand (&) to the end of the command line. myshell supports running programs in the background. When an ampersand is added at the end of the command line, the shell will return to the command line prompt immediately after launching the program. This allows you to continue working without waiting for the command to complete.

#

<help cd>
To change the current default directory to [directory].
Format:    cd [directory]

-- This command updates the PWD environment variable (which can be viewed using the "pwd"       command). For more information about the directory path, type "help path". If no    directory is specified as an argument, the current directory will be reported. If the    specified directory does not exist, a "Path Error" message will be displayed on the         screen,Additionally,you can specify a directory path written in a file as follows:
 Example:    cd <test.txt

The file can be specified using the full path, such as:
cd </home/username/test.txt

To learn more about the file path format, type "help path" for additional information.
#

<help clr> <help clear>

Format:    clr

or         clear

-- To clear the screen, no arguments are needed.

#


<help dir>

Format:    dir [directory] 

-- To list the contents of directory [directory]
Example: dir /home
The "dir" command is used to list the contents of directory [directory]. It is important to note that This command does not change the “cd” directory or the PWD environment variable. (which can be viewed using the "pwd" command). For more information about the directory path, type "help path". If no directory is specified as an argument, the contents of the current directory will be listed. If the specified directory does not exist, a "Path Error" message will be displayed on the screen

Moreover, you can use a directory path writen in a file as:

   e.g.   dir <a.txt

   And you can list the contents into a file or more than one file as:

   e.g.   dir >b.txt      or    dir >b.txt >c.txt

   The token ">" can be replaced by ">>", type "help redirection" to see the difference of ">" and ">>".

   You can use both input redirection and output redirection as:

   e.g.   dir <a.txt >b.txt >c.txt

   The file can be given by the full path as:

          dir </home/username/a.txt

   As to the file path format, type "help path" to get more information.

#



<help environ>

Format:    environ 

-- To list all the environment strings on the screen or more than one file as:

   e.g.   envieron     or     environ >b.txt     or    environ >b.txt >c.txt

   The token ">" can be replaced by ">>", type "help redirection" to see the difference of ">" and ">>".

   The file can be given by the full path as:

          /home/a.txt

   As to the file path format, type "help path" to get more information.

#



<help echo>

Format:    echo [comment]

-- it is used to display [comment] on the screen or in output files. And multiple spaces/tabs will be reduced to a single space.

   e.g.   echo hello    world

   The words "hello world" will display in the screen.

   [comment] can be multiple words either typed from keyboard or read from one or more input files.

   e.g.   echo <a.txt   or   echo <a.txt <b.txt

   And you can display or output the contents into one file or more than one file:

   e.g.   echo hello world >c.txt  or  echo hello world >c.txt >d.txt

   The token ">" can be replaced by ">>", type "help redirection" to see the difference of ">" and ">>".

   You can use both input redirection and output redirection:

   e.g.   echo <a.txt <b.txt  >c.txt >d.txt

   The file can be given by the full path as:

          echo </home/a.txt  >/home/b.txt

   As to the file path format, type "help path" to get more information.

#



<help help>

Format:    help   or    ? 

--  To view the detailed usage of a specific command:

   Example: help echo 

   Type "help command" to see the internal commands.

   And you can display  or output the help information into one file or more than one file as:

   e.g.    help dir >c.txt     or    help dir >c.txt >d.txt

   The token ">" can be replaced by ">>", type "help redirection" to see the difference of ">" and ">>".

   The file can be given by the full path as:

           help dir >/home/a.txt

   As to the file path format, type "help path" to get more information.

#



<help myshell>

Format:     myshell batchfile

or          myshell <batchfile

-- To keep reading and executing a line of commands from a batchfile.

   Example:     myshell test.bat

   where test.bat is a batchfile contains many lines of commands.



   You can display or output the execution results into one file or more than one file as:

   e.g.     myshell test.bat >c.txt      or    myshell test.bat >c.txt >d.txt

   The token ">" can be replaced by ">>", type "help redirection" to see the difference of ">" and ">>".

   The file can be given by the full path as:

   e.g.     myshell  </home/a.txt  >/home/username/b.txt

   As to the file path format, type "help path" to get more information.then put results in outputfile.

#



<help pause>

Format:     pause

-- it display the message "Press Enter to continue..." and temporarily suspends the operation of the shell until the 'Enter' key is pressed (ignore any intervening non-'Enter' input).

#



<help pwd>

Format:     pwd

-- To display the value of the PWD environment variable
Alternatively, you can use the "environ" command to list all the environment strings. To see more information about this command and how to use it, you can type "help environ". This will display the manual page for the command, which will provide more detailed information..

   You can display or output the execution results into one file or more than one file as:

   e.g.     pwd test.bat >c.txt      or    pwd test.bat >c.txt >d.txt

   The token ">" can be replaced by ">>", type "help redirection" to see the difference of ">" and ">>".

   The file can be given by the full path as:

   e.g.     pwd   >/home/a.txt

   As to the file path format, type "help path" to get more information.then put results in outputfile.

#



<help quit>  <help exit>

Format:    quit    or   exit  

-- To exit “myshell” No arguments are needed for this command just enter quit or exit.

#

<help path> <help ..> <help .> <help ~>
To view the format of a filepath or directory path

..   .  and ~ can be used in pathnames.
.. is a special directory notation that stands for the parent directory of the current working directory,
.  is a special directory notation that stands for the current working directory
~  is a special directory notation that stands for the home directory of the current user.

If the filename or directoryname contains a white space, type "\ " :

  e.g.   echo  <a\ b  ( display the contents of file "a b" )

Besides, there cannot be a white space in the path, or else a "Path Error" wil be reported in the screen.


******************************   thank you    ****************************************

#
