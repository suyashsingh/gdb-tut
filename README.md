# Using gdb
![gdb logo](https://www.gnu.org/software/gdb/images/archer.svg)


## Compilation
The program needs to be compiled with debugging information so that gdb can use it. `-g` flag
should be specified.

`gcc -g source_file.c -o executable_file`


## Loading Executables
You can open gdb with the executable as a command line option: `gdb executable_file`,
or you can open gdb first and then specify which executable you want to load using the
file command: 
+ open `gdb` and then 

+ `file executable_file`


			
## General Commands
`run` - runs the program normally.

`print variable_name` - to print the value of the variable.

`continue` - to continue execution wheh gdb halts at a break point.


## Break Points
+ Add unconditional break point: 
	+ `break line_number`
	+ `break function_name`

+ Add conditional break point:
	+ `break line_number if some_valid_c_condition` eg. `break 7 if i == 0`

+ Adding condition to existing unconditional break points: 
	+ `condition break_point_number condition` eg: `condition 7 if value == 10`
+ Removing condition from a break point:
	+ Conditions can be removed from an exsisting breakpoint by `condition break_point_number`
+ Printing Break Points:
	+ `info break` will print all the break points. This will print all the watch points (special break points).
+ Enabling / Disabling Break Points:
	+ `disable break_point_number`
	+ `enable break_point_number`


## Watch Point
Watch point is a special type of break point. In case of break point we give the line number to break.
However in case of watch point you have an expression. When the expression is true the program execution halts.

`watch condition` eg `watch i == 0`

You can use both `info watch` and `info break` to see the available watch points. 

> `info break`will show both break points and watch points.


## Printing value of variables
`info locals`

`print variable_name`


## Step / Next
+ `step` command steps into a function.
+ `next` command steps over the function, i.e. next doesn't gets in the function. It will treat the function
as a single line and the execution will reach the next line after the function call.


## Core Dumps
Load the core dumps with: 

`gdb executable_file core_file` or `gdb executable_file -c core_file`. 

Now you can use the usual commands to debug the matter.

> By default core dumps might not be generated in your system. So you will have to enable them manually using `ulimit -c unlimited`, refer 
> this [stack overflow link](https://stackoverflow.com/questions/17965/how-to-generate-a-core-dump-in-linux-on-a-segmentation-fault#answer-32461658)

## Stack Trace
Each function and its variables are assigned frames. The current function will be assigned frame 0 which is also known as the **bottom frame**.

+ `bt` to print the stack - called as back trace

+ `frame` to check in which frame you are

+ `frame frame_number` to go to frame number say 1.

+ `up` to move up the stack frame

+ `down` to move down the stack frame


You can use all the usual commands that you would use to roam around.

eg. `info locals`, `print`, `info args`, `list`


## Misc
+ You can invoke shell commands from gdb. `shell command_name` eg. `shell date`
+ You can also alter the value of a variable using the set command. `set variable_name = value`


## Quit
To quit from gdb type: `quit` or just `q` and hit return.


## References
[Linux Software Debugging with gdb](https://www.ibm.com/developerworks/library/l-gdb/index.html)

