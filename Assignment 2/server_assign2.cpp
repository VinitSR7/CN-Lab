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
#include<string>
using namespace std;

int main(){

int ssock,csock;      
 // creating server and clinet socket discriptor
int a,b,c;
char password[13], word[20], meaning[20], ser[10], rep[3], real[20];
unsigned int len;
//string word2, meaning2, req;

struct sockaddr_in server,client;   
// creating server & client socket object

if((ssock=socket(AF_INET,SOCK_STREAM,0))==-1){     
// creating socket
	perror("socket: ");
	exit(-1);
}

server.sin_family=AF_INET;
server.sin_port=htons(10000);       

// initializing server socket parameters..
server.sin_addr.s_addr=INADDR_ANY;

//inet_addr("127.0.0.1");
bzero(&server.sin_zero,0); 

//appending 8 byte zeroes to 'struct sockaddr_in', to make it equal in size with 'struct sockaddr'.. 


len=sizeof(struct sockaddr_in);

if((bind(ssock,(struct sockaddr *)&server,len))==-1){ 
 // binding port & IP  
	perror("bind error: ");
	exit(-1);
}

if((listen(ssock,5))==-1){     
// listening for client
	perror("listen error: ");                     
	exit(-1);
}


if((csock=accept(ssock,(struct sockaddr *)&client,&len))==-1){  
// accepting connectn
	perror("accept error: ");                         
	exit(-1);
}
while(1){
	while(1){
	/*map<string, string> m;
	ifstream infile;
	infile.open("words.txt");
	string line;
	char a[20], b[20];
	//string a, b;
	while(infile.is_open()){
		while(getline(infile, line)){
			sscanf(line.c_str(), "%s %s", a, b);
			m[a] = b;
		}
		infile.close();
	}
	cout << "map created" << endl;*/
	recv(csock, &word, sizeof(word), 0); 
	cout << "Word Received" << endl;
	int f = 0;
	ifstream infile;
	infile.open("words.txt");
	string line;
	char a[20], b[20];
	//string a, b;
	while(infile.is_open()){
		while(getline(infile, line)){
			sscanf(line.c_str(), "%s %s", a, b);
			if(strcmp(a, word) == 0){
				f = 1;
				strcpy(meaning, b);
				break;
			}
		}
		infile.close();
	}
	if(f == 1){
		cout << "sending meaning " << endl;
		send(csock, &meaning, sizeof(meaning), 0);
	}
	else{
		send(csock, &"no", sizeof("no"), 0);
		recv(csock, &real, sizeof(real), 0);
		ofstream outfile;
		outfile.open("words.txt", std::ios_base::app);
		string pp(real), kk(word);
		outfile << kk << " " << pp << endl;
	}
	
	//string word1(word);
	/*if(m.find(word) != m.end()){
		//meaning2 = m[word1];
		meaning = m[word];
		send(csoc, &meaning, sizeof(meaning), 0);
	}*/
	/*
	recv(csock, &greetings, sizeof(greetings), 0);
	send(csock, &"hello", sizeof("hello"), 0);
	recv(csock, &word, sizeof(word), 0);
	recv(csock, &b, sizeof(b), 0);
	int arr[26];
	int i=0, j = 0;
	while(i < 26) {arr[i] = 0; i+=1;}
	while(j < strlen(word)){
		arr[word[j]-'a']+=1;
		j+=1;
	}
	int id, mx = 0, flag = 0;
	j = 0;
	while(j < 26){
		if(arr[j] == b){
			flag = 1; break;
		}
		if(mx < arr[j]){
			mx = arr[j];
			id = j;
		}
		j+=1;*/
	}
	/*if(flag)
		send(csock, &j, sizeof(j), 0);
	else send(csock, &id, sizeof(id), 0);*/
	

}


close(ssock);









}
