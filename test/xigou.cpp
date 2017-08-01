#include<iostream>
using namespace std;
class A{
public:
	A();
	 virtual ~A();//当用一个基类的指针去删除一个派生类的对象时，调用基类的析构函数时派生类的析构函数也会被调用 避免引起内存泄露 一般都会将基类的析构函数写为虚函数 
	 virtual void fun1(){//如果基类把一个函数声明为虚函数，则在派生类中该函数也是隐式的虚函数
		cout<< "AAAAA"<<endl;
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
	virtual void fun1(){
		cout<<"BBBBB"<<endl;
	}
	virtual void fun2(){
		cout<<"BBBBB2"<<endl;
	}
	void fun3(){
		cout<<"BBBBB3"<<endl;
	}
};
B::B(){
	cout<<"construct class B"<<endl;
}
B::~B(){
	cout<<"delete class B"<<endl;
}


int main(){
	//类a和类b的析构函数都是虚函数的情况下
	//a *a = new b();//输出construct class a construct class b
	//b *b = new b();//输出construct class a construct class b
	//a *c = new a();//输出construct class a 
	//delete a;//输出delete class b  delete class a
	//delete b;//输出delete class b  delete class a
	//delete c;//输出delete class a

	//类A的析构函数为虚函数
	A *a = new B();//输出construct class A construct class B
	B *b = new B();//输出construct class A construct class B
	A *c = new A();//输出construct class A 
	//动态绑定 使用基类的引用或者指针调用一个虚函数时将发生动态绑定  
	a->fun1();//输出BBBBB
	b->fun1();//输出BBBBB
	//a->fun2();//使用基类的指针访问派生类自己的虚函数会报错 错误  提示classA 没有fun3
	//a->fun3();错误  提示classA 没有fun3
	b->fun2();
	c->fun1();//输出AAAAA
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

	//
	return 1;

}