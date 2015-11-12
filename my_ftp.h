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
 * param:    int portData, int mode
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
 * Initialize the ftp connection in active mode.
 * First, the client initiates the control channel (or command channel) from
 * a random port to the server port 20 (or the specific one defined by the user)
 * Then an authentication is done. If it failes, the command channel is closed.
 * For more informations:
 *  -https://en.wikipedia.org/wiki/File_Transfer_Protocol#Communication_and_data_transfer
 *  -http://www.ietf.org/rfc/rfc959.txt
 *
 * param: char *ip          => ip of the server
 *        char *login       => for the authentication 
 *          NOTE: pwd is asked directly to the user
 *        int *cmdDesSock   => ptr to the socket descriptor of the control
 *          channel
 *        struct sockaddr_in *p_ipInfo => ptr to the connection informations
 *          (ip, port, type of connection).
 *
*/
int ftp_client_active(char *ip, char *login, int *cmdDesSock, struct sockaddr_in *p_ipInfo);

/*
 * Send a command/response from a client to a server.
 *
 * params: 
 *        int sockDes                   => Socket descriptor
 *        char *command                 => Command or response to send
 *        char *input                   => Optional input string
 *        struct sockaddr_in *p_ipInfo  => Remote host IP info.
 * return: 
 *        int result                    => is it ok?
 *                                      0 YES
 *                                     -1 NO
*/

int ftp_send_cmd(int sockDes, char *command, char *input, struct sockaddr_in *p_ipInfo);
