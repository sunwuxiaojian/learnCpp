#include<iostream>
using namespace std;
class A{
public:
	A();
	 virtual ~A();//����һ�������ָ��ȥɾ��һ��������Ķ���ʱ�����û������������ʱ���������������Ҳ�ᱻ���� ���������ڴ�й¶ һ�㶼�Ὣ�������������дΪ�麯�� 
	 virtual void fun1(){//��������һ����������Ϊ�麯���������������иú���Ҳ����ʽ���麯��
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
	//��a����b���������������麯���������
	//a *a = new b();//���construct class a construct class b
	//b *b = new b();//���construct class a construct class b
	//a *c = new a();//���construct class a 
	//delete a;//���delete class b  delete class a
	//delete b;//���delete class b  delete class a
	//delete c;//���delete class a

	//��A����������Ϊ�麯��
	A *a = new B();//���construct class A construct class B
	B *b = new B();//���construct class A construct class B
	A *c = new A();//���construct class A 
	//��̬�� ʹ�û�������û���ָ�����һ���麯��ʱ��������̬��  
	a->fun1();//���BBBBB
	b->fun1();//���BBBBB
	//a->fun2();//ʹ�û����ָ������������Լ����麯���ᱨ�� ����  ��ʾclassA û��fun3
	//a->fun3();����  ��ʾclassA û��fun3
	b->fun2();
	c->fun1();//���AAAAA
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

	//
	return 1;

}