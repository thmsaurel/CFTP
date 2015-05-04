/******************************************************************************
name            : my_ftp.h
date            : 26 April 2015 
created by      : ldelaveau
last modified   : 26 April 2015 09:35:20 PM
last changes by : ldelaveau
******************************************************************************/

/*
 * Try to lauch the ftp client with the IP and username given in
 * the mode desribe by an int value:
 *  - 0 for passive mode
 *  - 1 for active mode (recommended)
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

int lauch_ftp_client(char * ip, char *login, int mode);

/*
 * Try to lauch the ftp server. Ports are not mandatory.
 * Here too you indicate the mode with an int:
 *  - 0 for passive mode
 *  - 1 for active mode (recommended)

 * To use default port, give 0.
 * Default ports: 20: Data
 *                21: Commands
 *
 * param:    int portData, 
 * return:   int 0 if it success
 *           Instead, the function returns:
 *           -1 : Can't open socket 
 *           -2 : Can't initialize the connection
 *           .
 *           .
 *           .
*/ 
int lauch_ftp_server(int port, int mode);
