#include<bits/stdc++.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

#define MAX 500
#define port 5200


void tobinary(int a[],char c) {
	int x=(int)c;

	cout<<x<<endl;

	for(int i=0;i<8;i++) {
		int y = (x&(1<<i));
		if(y) {
			a[i]=1;
		}

		else {
			a[i]=0;
		}
	}

}

void revprint(int a[],int n) {
	for(int i=n-1;i>=0;i--) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void fillmessageintocodes(int a[], int b[]) {
	for(int i=0;i<12;i++) {
		a[i]=-1;
	}

	for(int i=0;i<4;i++) {
		a[(1<<i)-1]=0;
	}

	int j=7;

	for(int i=11;i>=0;i--) {
		if(a[i]==-1) {
			a[i]=b[j];
			j--;
		}
	}
}


int main(){

	int clientSocket , serverSocket , receiveMsgSize;
	
	clientSocket = socket(AF_INET , SOCK_STREAM , 0);	// creating the socket
	
	if(clientSocket < 0){
		cout << "Creation of client socket failed" << endl;
		return 0;
	}
	
	struct sockaddr_in serverAddr , clientAddr;
	
	// providing socket with IP and port
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serverAddr.sin_port = htons(port);
	
	if(connect(clientSocket ,  (struct sockaddr*) & serverAddr , sizeof(serverAddr)) < 0){	// connecting to the receiver
		cout << "Connection Error..!" << endl;
		return 0;
	}
	else{
		cout << "Connection Established..!" << endl;
	}
	
	
	char c;
	cout<<"Enter the First letter of your name: ";
	cin>>c;

	int binary[8];
	tobinary(binary,c);

	cout<<"The entered message in binary is: ";
	revprint(binary,8);


	int codeword[12];
	fillmessageintocodes(codeword,binary);


	for(int i=0;i<4;i++) {
		int count=0;
		for(int j=0;j<12;j++) {
			if((j+1)&(1<<i)==1) {
				count+=codeword[j];
			}
		}
		codeword[(1<<i)-1] = count%2;
	}


	cout<<"Finally sent codeword: ";
	revprint(codeword,12);

	
	send(clientSocket , codeword , sizeof(codeword), 0); // sending the codeword
	
	//revprint(codeword,12);

	cout << "Message Sent Successfully...!" << endl;
	
	close(clientSocket);	// closing the socket
	
	return 0;
}














