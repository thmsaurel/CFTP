/*******************************************************************************
*
* File Name         : my_string.h
* Created By        : Thomas Aurel
* Creation Date     : January 15th, 2015
* Last Change       : January 18th, 2015 at 23:43:49
* Last Changed By   : Thomas Aurel
* Purpose           : string specific functions
*
*******************************************************************************/

/* my_string.c */

/**
 * Return the length of a string
 *
 * param:   char *str, the line to determine size
 * return:  int length, the line's length
 **/
int my_strlen(char *str);

/**
 * Concatenate two strings by appending the second to the first.
 * The null character (e.g '\0') is overwritten in the first string but added
 * it at the end of the second one.
 *
 * BE CARFUL, BUFFER OVERFLOW THEAT
 *
 * param:   char *s1, first string
 *          char *s2, second string
 * return:  the pointer on the first string whose is a concatenation of the
 * two param
 **/
char * my_strcat(char *s1, char *s2);

/**
 * Concatenate n bytes from the second string to the first one. '\0' is
 * overwritten in the first string. In all case, a null byte will end
 * the first string.
 *
 * BE CARFUL, BUFFER OVERFLOW THEAT
 *
 * param:   char *s1, first string
 *          char *s2, second string
 *          int n, the number of character of s2 to concatenate with s1
 * return:  the pointer on the first string whose is a concatenation of the
 * two param
 **/
char * my_strncat(char *s1, char *s2, int n);

/**
 * Copy the string pointed to by src (null byte included) to dest. dest must
 * be large enough.
 * BE CARFUL, BUFFER OVERFLOW THEAT
 *
 * param:   char *dest, first string
 *          char *src, second string
 * return: the pointer on dest
 **/
char * my_strcpy(char *s1, char *s2);

/**
 * Copy almost n bytes of the string pointed to by src to dest. dest must be
 * large enough. 
 * Warning!: If their is no null byte in the n copied bytes of src, the string
 * will be not null-terminated.
 * BE CARFUL, BUFFER OVERFLOW THEAT
 *
 * param:   char *dest, first string
 *          char *src, second string
 *          int n, the number of character of src to copy on dest
 * return:  the pointer on dest
 **/
char * my_strncpy(char *s1, char *s2, int n);

/* my_string.1.c */

/**
 * Transform string's characters into upper charaters
 *
 * param:   char *str, string
 * return:  return a upper string
 **/
char * my_strcapitalize(char *str);

/**
 * Compare two string. It returns an integer less than, equal to, or greater
 * than zero if s1 is found, respectively, to be less than, to match, or be
 * greater than s2.
 *
 *
 * param:   char *s1, char *s2
 * return:  int result 
 **/
int my_strcmp(char *s1, char *s2);

/**
 * The same that my_strcmp, but it compares almost n first bytes of the two
 * string s1 and s2.
 *
 * param:   char *s1, char *s2
 * return:  int result
 **/
int my_strncmp(char *s1, char *s2, int n);

/**
 * Attempt to read size-1 characters from stdin and stored it into the buffer
 * string. The null byte is added at the end of the buffer.
 *
 * param:   char *s1, char *s2
 * return:  char *string
 **/
char * my_gets(char *string, int size);
