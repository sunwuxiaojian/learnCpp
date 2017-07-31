#include <iostream>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
#define PORT 502
using namespace std;
int tcpServer(){
	SOCKET socksvr = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(socksvr==INVALID_SOCKET){
	 return -1;
	}

	struct sockaddr_in svraddr = {0};
	svraddr.sin_family = AF_INET;//代表internet协议族
	svraddr.sin_port = htons(PORT);
	svraddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//此宏为0，当前机器上任意IP地址，也可以指定当前机的ip和端口。
	bind(socksvr,(struct sockaddr *)&svraddr,sizeof(svraddr));//指定名字，类型，长度。绑定套接字。
	listen(socksvr,SOMAXCONN);//第一个参数是套接字，第二个参数是等待连接队列的最大长度。
	printf("等候客户端.......\n");
	struct sockaddr_in clientaddr = {0};
	int nLen = sizeof(clientaddr);
	SOCKET sockclient = accept(socksvr,(struct sockaddr*)&clientaddr,&nLen);//建立连接函数
	printf("客户端已连接\n");
	CHAR szText[100] = {0};
	recv(sockclient,szText,100,0); //接收函数，一直处于侦听模式，等待服务器端发送数据的到来。
	printf("%s\n",szText);
	CHAR szSend[100] = "Hello Client";
	send(sockclient,szSend,sizeof(szSend),0);//发送函数。
	closesocket(sockclient);
	closesocket(socksvr);
	return 0;
}

int main1(){
	 //初始化socket库
    WSADATA wsa = {0}; //WinSockApi 取WSA+DATA组成套接字结构体
    WSAStartup(MAKEWORD(2,2),&wsa);
    //服务器
	tcpServer();
    //清理套接字资源
    WSACleanup();

	return 0;
}