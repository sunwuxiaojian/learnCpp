#include <iostream>
using namespace std;
int f4;//定义变量
extern int f5;//声明变量
extern int f6=1;//定义变量
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
	////统计连续输入的数字有几个 
	//int current=0,count=0,value=0;
	//if(cin>>current){
	//	count++;
	//	while(cin>>value){
	//		if(current==value){
	//			count++;
	//		}
	//		else{
	//		cout<<current<<"连续出现次数为"<<count<<endl;
	//		current=value;
	//		count=1;
	//		}
	//	}
	//	cout<<current<<"连续出现次数为"<<count<<endl;
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
	//cout<<u1+u<<endl;//当表达式中有无符号数和int时，会把int转换成无符号数   切忌混用带符号数和无符号数

	unsigned u2=10;
	unsigned u3=42;
	cout<<u2-u3<<endl;//输出值错误 因为unsigned非负 
	cout<<u3-u2<<endl;//正确

	int i=10;
	cout<<i-u2<<endl;
	cout<<u2-i<<endl;

	//for(unsigned u=10;u>=0;u--){
	//	cout<<u<<endl;//死循环  因为u为unsigned 不可能<0
	//}

	//变量的初始化不是赋值  初始化时在创建变量时赋予一个初始值 而赋值是把当前的值擦除  以一个新值替代 

	int u5;//变量值未被初始化  因为此变量在main()函数体内  任何在函数体内部的内置类型变量将不被初始化  
	
	
	//变量的声明和定义   可以一次定义 多次声明  变量的定义必须出现在且只能出现在一个文件中 
	extern int f1; //声明
	//extern int f2=10; 错误 在函数体内部初始化声明的变量 错误
	int f3=10; //定义 
	
	//变量名大小写敏感
	int __nn=0;
	int _A=0;
	cout<<__nn<<_A<<endl;

	int unique =10;
	cout<<reused<<" "<<unique<<endl;//42 10
	int reused =40;
	cout<<reused<<" "<<unique<<endl;//40 10
	cout<< ::reused<<" "<<unique<<endl;//42 10  ::域操作符 覆盖默认的作用域规则 
	
	
	
	return 0;
}
