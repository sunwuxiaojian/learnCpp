#include<iostream>
using namespace std;
class A{
public:
	A();
	 virtual ~A();//����һ�������ָ��ȥɾ��һ��������Ķ���ʱ�����û������������ʱ���������������Ҳ�ᱻ���� ���������ڴ�й¶
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
	//��A����B���������������麯���������
	//A *a = new B();//���construct class A construct class B
	//B *b = new B();//���construct class A construct class B
	//A *c = new A();//���construct class A 
	//delete a;//���delete class B  delete class A
	//delete b;//���delete class B  delete class A
	//delete c;//���delete class A

	//��A����������Ϊ�麯��
	A *a = new B();//���construct class A construct class B
	B *b = new B();//���construct class A construct class B
	A *c = new A();//���construct class A 
	delete a;//���  delete class A
	delete b;//���delete class B  delete class A
	delete c;//���delete class A

	////��B����������Ϊ�麯��
	//A *a = new B();//���construct class B
	//B *b = new B();//���construct class A construct class B
	//A *c = new A();//���construct class A 
	//delete a;//���delete class B  delete class A
	//delete b;//���delete class B  delete class A
	//delete c;//���delete class A

	////����������������������麯��
	//A *a = new B();//���construct class A construct class B
	//B *b = new B();//���construct class A construct class B
	//A *c = new A();//���construct class A 
	//delete a;//���delete class A
	//delete b;//���delete class B  delete class A
	//delete c;//���delete class A

	return 1;

}