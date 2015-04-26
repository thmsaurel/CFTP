#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>

int main (int argc, char ** argv)
{
	pid_t pid;
	char * msg="Bonjour";
	//char saisie[1024];
	int sd, bd, st, lenMsg, co;
    //int conv;
	struct in_addr ip;
	struct sockaddr_in my_sockaddr;

	if (argc != 3)
	{
		perror("Usage : ./a.out <IPv4> <port>");
		exit(EXIT_FAILURE);
	}

	//conv = inet_pton(AF_INET, argv[1], &ip);
	
	/*On remplit la structure pour bind)*/
	my_sockaddr.sin_family= AF_INET;
	my_sockaddr.sin_port = htons((short)atoi(argv[2]));
	my_sockaddr.sin_addr = ip;

	/*Récupe du pid*/
	pid = getpid();
	printf("pid : %ld\n", (long)pid);

	/*Création du socket*/
	sd = socket(AF_INET , SOCK_STREAM, 0);

	if (sd == -1)
	{
		perror("socket : ");
		exit(EXIT_FAILURE);
	}

	/*On bind le port*/

	bd = bind(sd, (struct sockaddr*)&my_sockaddr, sizeof(my_sockaddr));

	if (bd == -1)
	{
		perror("bind error : ");
		exit(EXIT_FAILURE);
	}	
	
	/*On initialise la connection*/

	co = connect(sd, (struct sockaddr*)&my_sockaddr, sizeof(my_sockaddr));

	if (co == -1)
	{
		perror("connect : ");
		exit(EXIT_FAILURE);
	}	

	//st = sendto(sd, "e", sizeof(char), 0, (struct sockaddr*)&my_sockaddr, sizeof(my_sockaddr));

	//msg = gets(saisie);
	while (strcmp(msg, "\0"))
	{
		/*On écrit ds le socket*/
		lenMsg = strlen(msg);
		st = sendto(sd, msg, lenMsg*sizeof(char), 0, (struct sockaddr*)&my_sockaddr, sizeof(my_sockaddr));

		if (st == -1)
		{
			perror("sendto : ");
			exit(EXIT_FAILURE);
		}

		//msg = gets(saisie);
	}	

	return EXIT_SUCCESS;
}


