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
int my_strlen(char *str);
char * my_strcat(char *s1, char *s2);
char * my_strncat(char *s1, char *s2, int n);
char * my_strcpy(char *s1, char *s2);
char * my_strncpy(char *s1, char *s2, int n);

/* my_string.1.c */
char * my_strcapitalize(char *str);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int n);
