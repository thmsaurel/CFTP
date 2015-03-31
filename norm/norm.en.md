# C Norm

## Coding rules
A knowledge database to follow some good coding rules is available [here](https://www.securecoding.cert.org/confluence/display/c/CERT+C+Coding+Standard).

## Classic Rules
* A line, including comments, doesn't be greater than 80 columns.
* One instruction by line.
* A function core doesn't exceed 25 lines.
* A file can contains 5 functions.
* Every source file (```.c```, ```.h```, ```Makefile```) must begin by a header.
* It doesn't be any comments in function core.
* Comments must begin and finish in the same line.
* Every transitional lines must be align each others, and begin by ```**```

## HEADER
### "C" Files
~~~ c
/******************************************************************************
*
* File Name        : file.extension
* Created By       : FirstName Name
* Creation Date    : Month(String) {Day(int)}th  , Year(int)
* Last Changed By  : FirstName Name
* Last Change      : Month(String) {Day(int)}th  , Year(int) at {HOUR:MINUTES}
* Purpose          : description
*
*******************************************************************************/
~~~
### "Makefile" Files
~~~ gherkin
################################################################################
# File Name       : Makefile                                                   #
# Created By      : Firstname Name                                             #
# Creation Date   : Month(String) {Day(int)}th  , Year(int)                    #
# Last Changed By : Firstname Name                                             #
# Last Changed    : Month(String) {Day(int)}th  , Year(int) at {HOUR:MINUTES}  #
# Purpose         : Provides compilation automation to the project             #
#                  - all   : Compile all source presents in the directory      #
#                  - clean : Clean all objects and executable presents in the  #
#                                                             directory        #
#                  -<Custom Target > : Purpose                                 #
################################################################################
~~~

## "Makefile" Rules
~~~ gherkin
#### DEFAULT PARAMETERS ####
EXECUTABLE=<Output Executable Name> 
SOURCES=<Source1 Source2 .... SourceX>
CFLAGS=<OPT1 OPT2 ... OPTX> 
LDFLAGS=<OPT1 OPT2 ... OPTX> 
CC=<Compiler> 
OBJECTS=$(SOURCES:.c=.o)  

#### CUSTOM PARAMETERS ####
<NAME>(CAPS LOCK)=your parameters

#### DEFAULT TARGETS ####
all: $(EXECUTABLE)
    $(EXECUTABLE): $(OBJECTS)
    $(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

clean:
    rm $(OBJECTS) $(EXECUTABLE)

#### CUSTOM TARGET ####
<Action Name>:
    Action 1
    Action 2
    Action X
~~~
## "C" Rules
### Comments
* Any comments must be in english
* It's forbidden to write comment in function
* Any comments must be written before the function

~~~ c
/*
** Normal comment
** with many lines
*/

/* Normal comment with one line  */
~~~

### Variables
* Variables must be written in english and don't exceed 20 characters.
* Abbrevations can be used
* Each name must begins by a minuscule and doesn't contain any uppercase.
* On creation, variables must be initialized and instantied

~~~ c
/* On word */
int age = 20;
/* If a variable is more than one word long, you must to separate each with '_' */
int my_age = 20;
~~~

* if the variable is a constant (declared with #DEFINE), she must written in uppercase
* glabal variable must be precede by ```G_```.
* Variables must be declared on beginning of their used domain.

~~~ c
/* constant variable */
#DEFINE VAR_CONSTANT = 1;

/* global variable */
int G_size = 3;

int main(int argc, char *argv)
{
    /* function variable */
    int i = 0;
    while(i < 10)
    {
        /* loop variable */
        int size = write(1, i, sizeof(i));
    }
}
~~~

#### Exception
Variables used in ```for``` can be declared and instantied in the loop.

~~~ c
/* variable is declared in for instruction */
for(int i = O; i < 10; i ++)
{
    /* my code */
}
~~~

* For the pointers, the star must be collapse with the variable name.

~~~ c
char *string = "paul"
~~~
* struct are declared as variables

### Functions
* function name must be in english
* Tab are composed of 4 spaces
* Fobident to use :
    * Goto
    * Switch Case

~~~ c
/* in file_name.h */

int test_function(int i);

/* in file_name.c */

/*
 ** This is the function header
 */
int test_function (int i)
{
    write(1, i, sizeof(int));
}
~~~

