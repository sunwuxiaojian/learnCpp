#include <iostream>
using namespace std;

void main1(){
	char a[5]="abcd";
	char b[5]={'a','b','c','d','e'};
	char c[5]={'a','b','c','d'};
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
	cout<<strlen(a)<<sizeof(a)<<strlen(b)<<sizeof(b)<<endl;

	//�����м��������������
	/*ע�ͶԲ���Ƕ��ʹ��*/
	cout<<"********************"<<endl;
	int d=9,g=10;
	g=d+g;
	d=g-d;
	g=g-d;
	cout<<d<<" "<<g<<endl;

}