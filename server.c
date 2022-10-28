#include<stdio.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>

#define MAX 1024
#define PORT 8080

int main()
{
int sockfd , connfd1 , connfd2 , connfd3 , len1 , len2 , len3;

struct sockaddr_in servaddr, cli1, cli2, cli3;

sockfd = socket(AF_INET, SOCK_STREAM, 0);

if( sockfd == -1 )
{
printf("Socket Creation Falied...\n");
exit(0);
}

memset(&servaddr, 0, sizeof(servaddr));
memset(&cli1 , 0 , sizeof(cli1));
memset(&cli2 , 0 , sizeof(cli2));
memset(&cli3 , 0 , sizeof(cli3));

servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(PORT);

if( (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr) )) != 0 )
{
printf("Socket Bind Failed...\n");
exit(0);
}

if( (listen(sockfd,5))!=0)
{
printf("Listen Falied...\n");
exit(0);
}

len1 = sizeof(cli1);
len2 = sizeof(cli2);
len3 = sizeof(cli3);

connfd1 = accept( sockfd , (struct sockaddr *)&cli1, &len1 );
connfd2 = accept( sockfd , (struct sockaddr *)&cli2, &len2 );
connfd3 = accept( sockfd , (struct sockaddr *)&cli3, &len3 );

if( connfd1 < 0 )
{
printf("Server accept falied...\n");
exit(0);
}

if( connfd2 < 0 )
{
printf("Server accept falied...\n");
exit(0);
}

if( connfd3 < 0 )
{
printf("Server accept falied...\n");
exit(0);
}

int n=0;
char buffer[MAX];







//server will receive the number from clientA
int n1 = recv(connfd1, &n1, MAX, 0);

printf("Number from client A : %d \n\n",n1);









//server will send the number to clientB and clientC
send(connfd2, &n1 , sizeof(int) , 0);
send(connfd3, &n1, sizeof(int), 0);





//server will receive the numbers from clientB and clientC


//receive number from clientB
int num1 = recv(connfd2, &num1 , sizeof(int) , 0);


//send the number to clientA
send(connfd1 , &num1 , sizeof(int) , 0);


//receive the number from clientC
int num2 = recv(connfd3, &num2, sizeof(int) , 0);


//send the message to clientA
send(connfd1 , &num2 , sizeof(int) , 0);



//close(connfd1);
//close(connfd2);
//close(connfd3);
close(sockfd);
}






























