#include <iostream>
using namespace std;
int f4;//�������
extern int f5;//��������
extern int f6=1;//�������
int  _add=0;
int reused =42;
int main2(){
	
	//std::cout<<"/*";
	//std::cout<<"*/";
	//std::cout<</*"*/"*/";
	//std::cout<</*"*/"/*"/*"*/;
	/*int a=0,b=0;
	while(cin>>b){
		a+=b;
	}
	cout<<a<<endl;*/
	////ͳ����������������м��� 
	//int current=0,count=0,value=0;
	//if(cin>>current){
	//	count++;
	//	while(cin>>value){
	//		if(current==value){
	//			count++;
	//		}
	//		else{
	//		cout<<current<<"�������ִ���Ϊ"<<count<<endl;
	//		current=value;
	//		count=1;
	//		}
	//	}
	//	cout<<current<<"�������ִ���Ϊ"<<count<<endl;
	//}
	//return 0;

	//bool b=42;
	//cout<<b<<endl;
	//int i=b;
	//cout<<i<<endl;
	//i=3.14;
	//cout<<i<<endl;
	//double pi=i;
	//cout<<pi<<endl;
	//unsigned char c=-1;
	//cout<<(int)c<<endl;
	//signed char c2=626;
	//cout<<(int)c2<<endl;	

	//unsigned u=10;
	//int u1=-40;
	//cout<<u1+u<<endl;//�����ʽ�����޷�������intʱ�����intת�����޷�����   �мɻ��ô����������޷�����

	unsigned u2=10;
	unsigned u3=42;
	cout<<u2-u3<<endl;//���ֵ���� ��Ϊunsigned�Ǹ� 
	cout<<u3-u2<<endl;//��ȷ

	int i=10;
	cout<<i-u2<<endl;
	cout<<u2-i<<endl;

	//for(unsigned u=10;u>=0;u--){
	//	cout<<u<<endl;//��ѭ��  ��ΪuΪunsigned ������<0
	//}

	//�����ĳ�ʼ�����Ǹ�ֵ  ��ʼ��ʱ�ڴ�������ʱ����һ����ʼֵ ����ֵ�ǰѵ�ǰ��ֵ����  ��һ����ֵ��� 

	int u5;//����ֵδ����ʼ��  ��Ϊ�˱�����main()��������  �κ��ں������ڲ����������ͱ�����������ʼ��  
	
	
	//�����������Ͷ���   ����һ�ζ��� �������  �����Ķ�������������ֻ�ܳ�����һ���ļ��� 
	extern int f1; //����
	//extern int f2=10; ���� �ں������ڲ���ʼ�������ı��� ����
	int f3=10; //���� 
	
	//��������Сд����
	int __nn=0;
	int _A=0;
	cout<<__nn<<_A<<endl;

	int unique =10;
	cout<<reused<<" "<<unique<<endl;//42 10
	int reused =40;
	cout<<reused<<" "<<unique<<endl;//40 10
	cout<< ::reused<<" "<<unique<<endl;//42 10  ::������� ����Ĭ�ϵ���������� 
	
	
	
	return 0;
}
