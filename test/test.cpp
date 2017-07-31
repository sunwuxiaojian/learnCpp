#include <iostream> 
using namespace std;
void exchange1(int x,int y);
void exchange2(int *x,int *y);
void exchange3(int &x,int &y);
void find1(char array[],char search,char *pi);
void main0(){
	int a =10;
	int *p=&a;
	int *p1=p;
	cout<<p<<" "<<p1<<" "<<*p<<" "<<*p1<<" "<<&p<<" "<<&p1<<" "<<endl;

	int b =9;
	int *p2,*p3;
	p2=&b;
	p3=p2;
	*p3=a;
	cout<<*p2<<" "<<*p3<<endl;

	int  c,*pc;
	c=10;
	pc =&c;
	*pc=20;
	cout<<c<<endl;

	
	//遍历数组的四种方式  指针和数组名
	int array[5]={0,1,5,3,4};
	int *pa =array;
	for(int i=0;i<5;i++){
	   cout<<array[i]<<" ";
	}

	for(int i=0;i<5;i++){
		cout<<*(array+i)<<" ";
	}

	for(int i=0;i<5;i++){
		cout<<pa[i]<<" ";
	}

	for(int i =0;i<5;i++){
		cout<< *(pa+i)<<" ";
	}

	for(int i=0;i<5;i++){
		cout<<*(pa++)<<endl;
		//cout<<*(array++); //数组名和指针变量的区别 数组名为指针常量，值不能被修改
	}
	
	cout<<"*******************************"<<endl;
	int i1=30;
	int i2=40;
	const int * pp=&i1;//也可以写作int const *pp=&i1;
	pp=&i2;
	i2=80;
	//*pp=80;错误 因为被*pp被const修饰  为常量  不能被修改赋值 但是pp仍然为指针变量 能重新指向其他的地址 
	cout<<*pp<<endl;

	int * const pp1=&i1;
	//pp1=&i2; 错误 因为const修饰的是pp1 所以指针pp1为常量  不可重新指向其他地址
	*pp1 =50;
	cout<<i1<<endl;

	const int i3=40;
	//int *pi3=&i3;  错误 const int 的i3地址不能赋值给指针变量pi3，否则可以通过pi3修改i3的值 不合理
	int *pi3 =(int *) &i3;
	*pi3=8; //编译虽然通过 但是没有完成值的更改
	cout<<*pi3<<" "<<pi3<<" "<<&i3<<" "<<i3<<endl;

	//值传递  引用传递 指针传递 
	int m=2,n=3;
	//exchange1(m,n);//输出结果显示并没有完成交换 因为在值传递时 相当于把实参赋值给形参 之后所有的操作都是对形参变量进行操作
	//exchange2(&m,&n);//输出结果显示完成了交换
	exchange3(m,n);//输出结果显示完成了交换
	cout<<m<<" "<<n<<endl;

	//双指针
	char str[]="abcdefghijklmnopqrstuvwxyz";
	char search='d';
	char *pointer=0 ;
	find1(str,search,pointer);
}

//值传递
void exchange1(int x,int y){
		int temp;
		temp=x;
		x=y;
		y=temp;
		cout<<x<<" "<<y<<endl;
}
//指针传递（地址传递）
void exchange2(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
	cout<<*x<<" "<<*y<<endl;
}
//引用传递
void exchange3(int &x,int &y){
	int temp=x;
	x=y;
	y=temp;
	cout<<x<<" "<<y<<endl;
}

//此函数用于返回查找第一个字符串的地址 主要学习双指针的用法
void find1(char array[],char search,char* pi){
	for(int i=0;*(array+i)!=0;i++){
		if(*(array+i)==search){
			pi=array+i;
			break;
		}
		if(*(array+i)==0){
			pi=0;
			break;
		}
	}
	cout<<pi<<endl;
}


