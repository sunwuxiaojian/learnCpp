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

	//不用中间变量交换两个数
	/*注释对不能嵌套使用*/
	cout<<"********************"<<endl;
	int d=9,g=10;
	g=d+g;
	d=g-d;
	g=g-d;
	cout<<d<<" "<<g<<endl;

}