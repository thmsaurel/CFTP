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
  int res=0, pid=-1, *cmdDesSock, *dataDesSock;
  char *input = (char *)malloc(FTP_MAX_SIZE_CMD*sizeof(char)), *msg;
  struct sockaddr_in ipInfo, *p_ipInfo;
  p_ipInfo = &ipInfo;

  if(input==NULL){
    my_puts("ERROR in lauch_ftp_cli: malloc failed\n");
    exit(-1);
  }

  if (mode == 1)
    res = ftp_client_active(ip,login,cmdDesSock,p_ipInfo);
  else if (mode == 0){
    my_puts("Passive mode for ftp not yet implemented.");
    my_puts("Swtich to active mode\n");
    res = ftp_client_active(ip,login,cmdDesSock,p_ipInfo);
    }

  if((pid=fork()) < 0){
    my_puts("Error: can't initialize ftp shell\n");
    exit(-1);
  }
  else if (pid == 0){
    msg=my_gets(input, FTP_MAX_SIZE_CMD);
    while (my_strcmp(msg,"exit")){
        res = my_send_packet(*cmdDesSock, input, p_ipInfo);
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

int lauch_ftp_server(int port, int mode){
  return 0;
}

int ftp_client_active(char *ip, char *login, int *cmdDesSock, struct sockaddr_in *p_ipInfo){
  int res =0, l_cmdDesSock=-2, l_dataDesSock=-1;
  char *passwd = (char *)malloc(21*sizeof(char)), *authMsg="(USER)";
  char *repSrv = (char *)malloc(3*sizeof(char));

  l_cmdDesSock = my_init_co(ip, 20, 0, p_ipInfo);
  if(res < 0){
    my_puts("Error in ftp_client_active: my_init_co failed\n");
    exit(-1);
  }
  my_printf("Password for %s (leave blank for anonymous): \n");
  passwd=my_gets(passwd, 21);
  res = ftp_send_cmd(l_cmdDesSock, "(USER)", login, p_ipInfo);
  if (res < 0){
    my_puts("Error: Can't send (USER) to the server\n");
    exit(-1);
  }
  res=0;
  while(res==0)
    res=recv(l_cmdDesSock,repSrv,3,0);
  if(res!=3 && (my_strcmp(repSrv,"331"))!=0){
    my_puts("Error: Incorrect answer from the server\n");
    exit(-2);
  }
  res = ftp_send_cmd(l_cmdDesSock, "(PASS)", passwd, p_ipInfo);
  if (res <0){
    my_puts("Error: Can't send (PASS) to the server\n");
    exit(-1);
  }
  res=0;
  while(res==0)
    res=recv(l_cmdDesSock,repSrv,3,0);
  if(res==3 && (my_strcmp(repSrv,"230"))==0)
    my_puts("Authentication succeed\n");
  else if(res==3 && (my_strcmp(repSrv,"430"))==0){
    my_puts("Error: Authentication failed: Bad username or password\n");
    exit(-3);
  }
  else{
    my_puts("Error: Incorrect answer from the server\n");
    exit(-3);
  }
  cmdDesSock=&l_cmdDesSock;
  return 0;
}
int ftp_send_cmd(int sockDes, char *command, char *input, struct sockaddr_in *p_ipInfo){
  int res=0;
  char *send_str = command;

  send_str=my_strcat(send_str,input);
  res=my_send_packet(sockDes, send_str, p_ipInfo);
  if (res <0){
    my_puts("Error while sending command: Failed to send command (USER)\n");
   return -1;
  }
  return 0;
}
