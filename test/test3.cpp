#include <iostream>
#include <winsock2.h>

#pragma comment(lib,"ws2_32.lib")
#define PORT 502
using namespace std;

int TCPClient() {
    SOCKET  socketClient= socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    struct sockaddr_in addr={0};
    addr.sin_family=AF_INET;
    addr.sin_port=htons(PORT);
    addr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
    int iRetVal =connect(socketClient,(struct sockaddr *)&addr,sizeof(addr));
    if(SOCKET_ERROR==iRetVal){
        cout<<"connect failed!"<<endl;
        closesocket(socketClient);
        return -1;
    }
    printf("connect success!");
    char sendData[100]="hello server ";
    send(socketClient,sendData,sizeof(sendData),0);
    char recvData[100]={0};
    recv(socketClient,recvData,100,0);
    cout<<sendData<<endl;
    closesocket(socketClient);
    return 0;
}

int main(){
    WSADATA wsaData;
    if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0){
        cout<<"Failed to load winSock!"<<endl;
        return  -1;
    }
    TCPClient();
    WSACleanup();
    getchar();
    return 0;
}