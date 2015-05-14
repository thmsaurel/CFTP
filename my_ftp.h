/******************************************************************************
name            : my_ftp.h
date            : 26 April 2015 
created by      : ldelaveau
last modified   : 26 April 2015 09:35:20 PM
last changes by : ldelaveau
******************************************************************************/

#include<unistd.h>
#include<sys/wait.h>
#include"my_ip.h"
#include"my_string.h"

// Maximum size (in characters) of a FTP command
#define FTP_MAX_SIZE_CMD 128

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

 * To use default port, give 0 (custom not supported yet).
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

/*
 * Create FTP Command line and send commands to the server defined by:
 *      int socket
 *      struct sockaddr_in *ipInfo
 *
 * Type "exit" to quit the shell.
 *
 * params:    int socket, struct sockaddr_in *ipInfo
 * return:    int is_it_ok?, with 
 *              0  => OK
 *              -1 => Not Ok
 */
int launch_ftp_cli(int socket, struct sockaddr_in *ipInfo);
