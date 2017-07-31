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
	svraddr.sin_family = AF_INET;//����internetЭ����
	svraddr.sin_port = htons(PORT);
	svraddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//�˺�Ϊ0����ǰ����������IP��ַ��Ҳ����ָ����ǰ����ip�Ͷ˿ڡ�
	bind(socksvr,(struct sockaddr *)&svraddr,sizeof(svraddr));//ָ�����֣����ͣ����ȡ����׽��֡�
	listen(socksvr,SOMAXCONN);//��һ���������׽��֣��ڶ��������ǵȴ����Ӷ��е���󳤶ȡ�
	printf("�Ⱥ�ͻ���.......\n");
	struct sockaddr_in clientaddr = {0};
	int nLen = sizeof(clientaddr);
	SOCKET sockclient = accept(socksvr,(struct sockaddr*)&clientaddr,&nLen);//�������Ӻ���
	printf("�ͻ���������\n");
	CHAR szText[100] = {0};
	recv(sockclient,szText,100,0); //���պ�����һֱ��������ģʽ���ȴ��������˷������ݵĵ�����
	printf("%s\n",szText);
	CHAR szSend[100] = "Hello Client";
	send(sockclient,szSend,sizeof(szSend),0);//���ͺ�����
	closesocket(sockclient);
	closesocket(socksvr);
	return 0;
}

int main1(){
	 //��ʼ��socket��
    WSADATA wsa = {0}; //WinSockApi ȡWSA+DATA����׽��ֽṹ��
    WSAStartup(MAKEWORD(2,2),&wsa);
    //������
	tcpServer();
    //�����׽�����Դ
    WSACleanup();

	return 0;
}