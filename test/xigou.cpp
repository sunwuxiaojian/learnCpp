#include<iostream>
using namespace std;
class A{
public:
	A();
	 virtual ~A();//当用一个基类的指针去删除一个派生类的对象时，调用基类的析构函数时派生类的析构函数也会被调用 避免引起内存泄露
	virtual void fun1(){
		cout<< "AAAAAA"<<endl;
	}
};
A::A(){
	cout<<"construct class A"<<endl;
}
A::~A(){
	cout<<"delete class A"<<endl;
}

class B:public A{
public:
	 B();
	virtual ~B();
	void fun2(){
		cout<<"BBBBB"<<endl;
	}
};
B::B(){
	cout<<"construct class B"<<endl;
}
B::~B(){
	cout<<"delete class B"<<endl;
}


int main(){
	//类A和类B的析构函数都是虚函数的情况下
	//A *a = new B();//输出construct class A construct class B
	//B *b = new B();//输出construct class A construct class B
	//A *c = new A();//输出construct class A 
	//delete a;//输出delete class B  delete class A
	//delete b;//输出delete class B  delete class A
	//delete c;//输出delete class A

	//类A的析构函数为虚函数
	A *a = new B();//输出construct class A construct class B
	B *b = new B();//输出construct class A construct class B
	A *c = new A();//输出construct class A 
	delete a;//输出  delete class A
	delete b;//输出delete class B  delete class A
	delete c;//输出delete class A

	////类B的析构函数为虚函数
	//A *a = new B();//输出construct class B
	//B *b = new B();//输出construct class A construct class B
	//A *c = new A();//输出construct class A 
	//delete a;//输出delete class B  delete class A
	//delete b;//输出delete class B  delete class A
	//delete c;//输出delete class A

	////两个类的析构函数都不是虚函数
	//A *a = new B();//输出construct class A construct class B
	//B *b = new B();//输出construct class A construct class B
	//A *c = new A();//输出construct class A 
	//delete a;//输出delete class A
	//delete b;//输出delete class B  delete class A
	//delete c;//输出delete class A

	return 1;

}