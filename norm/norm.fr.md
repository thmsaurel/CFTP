# Norme C

## Règles de codage
Une base de connaissances pour suivre quelques bonne règles de codage en C est disponible [ici](https://www.securecoding.cert.org/confluence/display/c/CERT+C+Coding+Standard).

## Règles classiques
* Une ligne, y compris pour les commentaires, ne doit pas excéder 80 colonnes.
* Une seule instruction par ligne.
* Une fonction ne doit pas excéder 25 lignes entre les accolades.
* Un fichier ne doit pas contenir plus de 5 fonctions
* Chaque fichier source (```.c```, ```.h```, ```Makefile```) doit commencer pas un header.
* Il ne doit pas y avoir de commentaires dans le corps des fonctions.
* Les commentaires sont commencés et terminés par une ligne seule.
* Toutes les lignes intermédiaires s'alignent entre elles, et commencent par ```**```

## HEADER
### Fichiers "C"
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
### Fichier "Makefile"
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

## Règles "Makefile"
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
## Règles C
### Commentaires
* Les commentaires doivent être en anglais
* Il est interdit d'écrire un commentaire dans une fonction
* Le commentaire doit être écrit avant la fonction concernée

~~~ c
/*
 ** Normal comment
 ** with many lines
 */

/* Normal comment with one line  */
~~~

### Variables
* Les variables doivent être écrites en langue anglaise et ne doivent pas excéder 20 caractères.
* Les abrévations peuvent être utilisées.
* Chaque nom de variable doit commencer par une minuscule, et ne contient pas de majuscules
* Lors de leur création, les variables doivent être initialisées et instanciées.

~~~ c
/* On word */
int age = 20;
/* If a variable is more than one word long, you must to separate each with '_' */
int my_age = 20;
~~~

* Si la variable est une constante (déclarée avec #DEFINE), elle doit être écrite en majuscules
* Les variables globales doivent être précédées d'un ```G_```.
* Les variables doivent être déclarées au début de leur domaine d'utilité

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

#### exception
les variables utilisées dans les ```for``` peuvent être déclarées et initialisées dans la boucle en elle même

~~~ c
/* variable is declared in for instruction */
for(int i = O; i < 10; i ++)
{
    /* my code */
}
~~~

* Pour les pointeurs, coller l'étoile au nom de la variable:

~~~ c
char *string = "paul"
~~~
* Les structures sont déclarées comme des variables.

### Fonctions
- Les noms de fonctions sont en anglais
- Une tabulation est composée de 4 espaces
- Interdit d'utiliser :
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

