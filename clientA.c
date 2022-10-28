#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>

#define MAX 1024
#define PORT 8080

int main()
{
int sockfd;
struct sockaddr_in servaddr, cli;

sockfd = socket(AF_INET, SOCK_STREAM, 0);

if(sockfd == -1)
{
printf("SOCKET CREATION FAILED\n");
exit(0);
}

memset( &servaddr, 0, sizeof(servaddr) );

servaddr.sin_family = AF_INET;
servaddr.sin_port = htons(PORT);
servaddr.sin_addr.s_addr = INADDR_ANY;

if( connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0 )
{
printf("Connection with the server failed...\n");
exit(0);
}


while(1)
{
int num;

printf("Enter the number to be sent to server : ");
scanf("%d",&num);


//client A sends the number to server
send( sockfd, &num, sizeof(int), 0);


//clientA receives first number from server
int res1;
int num1 = recv(sockfd, &res1, sizeof(int) , 0); 


if( res1 == 1 )
printf("Even number\n");

else
printf("Odd number \n");

int res2;
int num2 = recv(sockfd, &res2, sizeof(int), 0);

if(res2 == 1)
printf("Prime Number \n");

else
printf("Composite Number \n");

if(num == 0)
close(sockfd);
}



}
