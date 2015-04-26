/******************************************************************************
name            : my_ip.h
date            : 26 April 2015 
created by      : ldelaveau
last modified   : 26 April 2015 09:51:43 PM
last changes by : ldelaveau
******************************************************************************/

/*
 * This function will try to open a connection the the host 
 * identified by the IP and the port given in "type" mode, e.g
 * TCP or UDP.
 *
 * param:    char *IP adress, int port, char *type
 * return:   int 0 if it success
 *           Instead, the function returns:
 *           -1 : Connection time out
 *           -2 : wrong username
 *           .
 *           .
 *           .
*/
/* Je veux voir pour le retour, ptetre un struc sockaddr *, je dois y réfléchir*/.
int my_init_co(char *IP, int port, char *type);

/*
 * Send a packet by a opened socket identified by a  
 * identified by the IP and the port given in "type" mode, e.g
 * TCP or UDP.
 *
 * param:    char *IP adress, int port, char *type
 * return:   int 0 if it success
 *           Instead, the function returns:
 *           -1 : Connection time out
 *           -2 : wrong username
 *           .
 *           .
 *           .
*/
int my_send_packet(const struc sockaddr *adress, char *msg);
