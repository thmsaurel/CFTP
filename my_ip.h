/******************************************************************************
name            : my_ip.h
date            : 26 April 2015 
created by      : ldelaveau
last modified   : 26 April 2015 09:51:43 PM
last changes by : ldelaveau
******************************************************************************/
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include"my_stdio.h"
/*
 * Socket struct addr initialized
*/
  struct sockaddr_in my_sockaddr;

/*
 * This function will try to open a connection the the host 
 * identified by the IP and the port given in "type" mode.
 * Types:
 *  - 0: SOCK_STREAM (TCP, Default)
 *  - 1: SOCK_DGRAM  (UDP)
 *  - 2: SOCK_SEQPACKET (see man 3 socket)
 *
 * param:    char *IP adress, short port, int type
 * return:   int socketDescriptor if it success
 *           Instead, the function returns:
 *           -1 : Connection time out
 *           -2 : wrong username
 *           .
 *           .
 *           .
*/
int my_init_co(char *IP, short port, int type);

/*
 * Send message in a packet by a opened socket.
 * Others informations are stored in sockaddr_in structure defined
 * in this file.
 * param:    int socket, char *msg (use struct sockaddr_in my_sockaddr)
 * return:   int 0 if it success
 *           Instead, the function returns:
 *           -1 : Connection time out
 *           -2 : wrong username
 *           .
 *           .
 *           .
*/
int my_send_packet(int socket, char *msg);
