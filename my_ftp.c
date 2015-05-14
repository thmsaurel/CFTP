/******************************************************************************
name            : my_ftp.h
date            : 14 May 2015 
created by      : ldelaveau
last modified   : 14 May 2015 04:33:49 PM
last changes by : ldelaveau
purpose         : FTP main lib
******************************************************************************/
#include"my_ftp.h"

int lauch_ftp_client(char *ip, char *login, int mode){
  return 0;
}

int lauch_ftp_server(int port, int mode){
  return 0;
}

int launch_ftp_cli(int socket, struct sockaddr_in *ipInfo){
    int res=0, pid=-1;
    char *input = (char *)malloc(FTP_MAX_SIZE_CMD*sizeof(char)), *msg;

    if(input==NULL){
      my_puts("ERROR in lauch_ftp_cli: malloc failed\n");
      exit(-1);
    }
    if((pid=fork()) < 0){
      my_puts("Error: can't initialize ftp shell\n");
      exit(-1);
    }
    else if (pid == 0){
      msg=my_gets(input, FTP_MAX_SIZE_CMD);
      while (my_strcmp(msg,"exit")){
          res = my_send_packet(socket, input, ipInfo);
          if (res != 0)
            my_puts("Error in lauch_ftp_cli: failed to send packet\n");
          msg=my_gets(input, FTP_MAX_SIZE_CMD);
      }
    free(input);
    exit(0);
    }
    else{
      //Lisen => this process will handle server responses.
      wait(NULL);
    }
    return 0;
}
