#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include<ctype.h>
#include <unistd.h>

#include<bits/stdc++.h>
int main()
{
int network_socket;
network_socket=socket(AF_INET,SOCK_STREAM,0); // create socket(domain,type,protocol);

// Specifying address of socket to which client wants to connect

struct sockaddr_in server_address;
server_address.sin_family=AF_INET;
server_address.sin_port=htons(10000);
server_address.sin_addr.s_addr=INADDR_ANY;

// connect

int status=connect(network_socket,(struct sockaddr *)&server_address,sizeof(struct sockaddr_in));
if(status==-1)
	printf("\n connection error.....");

//reading data from server

char buffer[255];
int ch=0;

FILE *fp;
fp=fopen("download.txt","w");

int w;

read(network_socket,&w,sizeof(int));

while(ch!=w)
{
read(network_socket,buffer,255);
fprintf(fp,"%s ",buffer);
ch++;
}
/*char buffer[255];

FILE *fp;
int w=0;
char c;

fp=fopen("abc.txt","r");
while((c=getc(fp))!=EOF)
{
fscanf(fp,"%s",buffer);
if(isspace(c)||c=='\t')
w++;
}

write(network_socket,&w,sizeof(int));
rewind(fp);

char ch;
while(ch!=EOF)
{
fscanf(fp,"%s",buffer);
write(network_socket,buffer,255);
ch=fgetc(fp);
}
*/
printf("\nDownload.txt file downloaded successful.........\n");
//closing
close(network_socket);

return 0;

}


