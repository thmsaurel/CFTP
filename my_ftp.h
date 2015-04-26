/******************************************************************************
name            : my_ftp.h
date            : 26 April 2015 
created by      : ldelaveau
last modified   : 26 April 2015 09:35:20 PM
last changes by : ldelaveau
******************************************************************************/

/*
 * Try to lauch the ftp client with the IP and username given.
 * By Default, Anonymous user is authorized
 *
 * param:    char *IP adress, char *username
 * return:   int 0 if it success
 *           Instead, the function returns:
 *           -1 : Connection time out
 *           -2 : wrong username
 *           .
 *           .
 *           .
*/ 

int lauch_ftp_client(char * ip, char *login);

/*
 * Try to lauch the ftp server. Port is not mandatory (def:25).
 *
 * param:    int port, if you don't want to use the default
 * return:   int 0 if it success
 *           Instead, the function returns:
 *           -1 : Can't open socket 
 *           -2 : Can't initialize the connection
 *           .
 *           .
 *           .
*/ 
int lauch_ftp_server(int port);
