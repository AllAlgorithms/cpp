#include<bits/stdc++.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<iostream>
#include<fstream>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>


using namespace std;

#define MAX 2048
#define port 5200


void flip(int &a) {
	a=!a;
}


void revprint(int codeword[],int n) {
	for(int i=n-1;i>=0;i--) {
		cout<<codeword[i]<<" ";
	}

	cout<<endl;
}

void decoded(int codeword[]) {

	int syndrome = 0;

	for(int i=0;i<4;i++) {
		int count=0;

		for(int j=0;j<12;j++) {
			if(((j+1)&(1<<i))) {
				count+=codeword[j];
			}
		}

		if(count%2==1) {
			syndrome+=(1<<i);
		}

	}

	cout<<"Syndrome : "<<syndrome<<endl;

	if(syndrome>=1) {
		cout<<"Hence flip bit "<<syndrome<<endl;
		flip(codeword[syndrome-1]);
	}


	int message[8];

	int j=7;
	for(int i=11;i>=0;i--) {
		if((i+1)!=1&&(i+1)!=2&&(i+1)!=4&&(i+1)!=8) {
			message[j--]=codeword[i];
		}
	}

	cout<<"Message : ";
	revprint(message,8);

	int x=0;
	for(int i=0;i<8;i++) {
		if(message[i]==1) {
			x+=(1<<i);
		}
	}

	char c = (char)(x);
	cout<<"Character: "<<c<<endl;

} 



int main(){

	int serverId = socket(AF_INET , SOCK_STREAM , 0); //creating a socket and assigning it to the socket handler
	if(serverId < 0){	// socket methode return -1 if the creation was not successful
		cout << "Socket creation has failed.";
		return 0;
	}
	
	struct sockaddr_in serverAddr , clientAddr;
	
	//specifying address and type for the server to operate under
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	int bindStatus = bind(serverId , (struct sockaddr*) & serverAddr , sizeof(serverAddr));
	
	if(bindStatus < 0){
		cout << "Socket binding has failed" << endl;
		return 0;
	}
	
	int listenStatus = listen(serverId , 5); //listen to the client while others are waiting in queue of size 5 
	
	if(listenStatus < 0){	// when queue is full listen fails
		cout << "Listner has failed" << endl;
		return 0;
	}
	
	cout << "...Waiting for connections \n\n";
	
	int codeword[12];	
	int clientSocketHandler;

	socklen_t len = sizeof(clientAddr);
	int connection;
	if((connection = accept(serverId , (struct sockaddr*) & clientAddr , &len)) < 0){
		cout << "Server didn't accept the request." << endl;
		return 0;
	}
	else{
		cout << "Server accepted the request. \n" << endl;
	}
	
	int rMsgSize = recv(connection , codeword , MAX , 0);
/*
	for(int i=0;i<12;i++) {
		cout<<codeword[i]<<" ";
	}*/

	cout<<"Choose how you want to recieve the message?"<<endl;
	cout<<"1) Recieve the original message. "<<endl;
	cout<<"2) Recieve message with defect. "<<endl;	

	int ch;
	cin>>ch;

	switch(ch) {
		case 1:{
			cout<<"Recieved Message: ";
			revprint(codeword,12);
			decoded(codeword);

			cout<<"Meesage Recieved Successfully...!"<<endl;
		} break;

		case 2: {
			int x = rand()%12;
			flip(codeword[x]);

			cout<<"Recieved Message: ";
			revprint(codeword,12);
			decoded(codeword);

			cout<<"Message Recieved Successfully...!"<<endl;
		} break;

		default : cout<<"Invalid Choice...!"<<endl;
	}
	
	
	close(serverId);
	return 0;
	
}
