/******************************************************************************
name            : my_ip.c
date            :  4 May 2015 
created by      : ldelaveau
last modified   :  4 May 2015 10:26:57 PM
last changes by : ldelaveau
purpose         :My Internet Protocol set of functions
******************************************************************************/
#include"my_ip.h"
int my_init_co(char *IP, short port, int type){
  int res=0, sockDes=-1;
  struct in_addr ip;

  if(port < 1000 || port > 65535){
    my_puts("Warn: Given port out of range\n");
    exit(0);
  }
  res = inet_pton(AF_INET, IP, &ip);
  if (res!=1){
    my_puts("inet_pton failed\n");
    exit(-1);
  }
  my_sockaddr.sin_family= AF_INET;
  my_sockaddr.sin_port= htons(port);
  my_sockaddr.sin_addr= ip;
  sockDes=socket(AF_INET, type, 0);
  if(sockDes < 0){
    my_puts("ERROR: socket fails\n");
    exit(-2);
  }
  res = bind(sockDes, (struct sockaddr*)&my_sockaddr, sizeof(my_sockaddr));
  if(res < 0){
    my_puts("ERROR: bind fails\n");
    exit(-3);
  }
  res = connect(sockDes, (struct sockaddr*)&my_sockaddr, sizeof(my_sockaddr));
  if(res < 0){
    my_puts("ERROR: connect fails\n");
    exit(-4);
  }

  return sockDes;
}
