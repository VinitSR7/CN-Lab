#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
int sock;      // client socket discriptor
int a,b,c,i;
unsigned int len;
char ch[3]="no", password[13], word[20], greetings[10], ser[10], rep[3], real[20];
char ch1[3];
char meaning[20];

struct sockaddr_in client;
if((sock=socket(AF_INET,SOCK_STREAM,0))==-1){  // client socket is created..
perror("socket: ");
exit(-1);
}

client.sin_family=AF_INET;
client.sin_port=htons(10000);        // initializing  socket  parameters 
client.sin_addr.s_addr=INADDR_ANY;
//inet_addr("127.0.0.1");
bzero(&client.sin_zero,0); //appending 8 byte zeroes to 'struct sockaddr_in', to make it equal in size with 'struct sockaddr'.. 


len=sizeof(struct sockaddr_in);
if((connect(sock,(struct sockaddr *)&client,len))==-1){  //conneting to client
perror("connect: ");
exit(-1);
}
while(1){
	cout << "Enter the Emp ID : ";
	scanf("%d", &a);
	cout << "Enter the type of leave :\n1.CL\n2.EL" << endl;
	scanf("%d", &b);
	cout << "Enter total leave: " << endl;
	scanf("%d", &c);
	//cout << b << endl;
	send(sock, &a, sizeof(a), 0);
	send(sock, &b, sizeof(b), 0);
	send(sock, &c, sizeof(c), 0);
	int el, cl;
	recv(sock, &cl, sizeof(cl), 0);
	recv(sock, &el, sizeof(el), 0);
	recv(sock, &b, sizeof(b), 0);
	cout << "Leaves left : 1. CL : " << cl << "  2. EL : " << el << endl; 
	if(b == 1) {
		cout << "leave granted" << endl;
	}
	else cout << "No any cl or el left" << endl;
	//cout << meaning << endl;
	/*if(strcmp(meaning, "no") == 0){
		cout << "Enter the word meaning : " << endl;
		scanf("%s", real);
		send(sock, real, sizeof(real), 0);
	}
	/*while(1){
		printf("Enter the password : ");
		scanf("%s", password);
		send(sock, &password, sizeof(password), 0);
		recv(sock, &a, sizeof(a), 0);
		if(a == 1) break;
		else continue;
	}
	printf("Password authenticated\n");
	scanf("%s", greetings);
	send(sock, &greetings, sizeof(greetings), 0);
	recv(sock, &ser, sizeof(ser), 0);
	printf("%s\n", ser);
	printf("Enter a word and a number :");
	scanf("%s", word);
	scanf("%d", &b);
	send(sock, &word, sizeof(word), 0);
	send(sock, &b, sizeof(b), 0);
	//printf("send to server word");
	recv(sock, &c, sizeof(c), 0);
	printf("The required character is  : %c", 'a'+c);*/

printf("\nTo exit...press 'no'\n");


scanf("%s",ch1);


if((i=strcmp(ch,ch1))==0){
close(sock);
exit(0);
}

}

}
