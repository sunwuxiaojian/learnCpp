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

	
	//������������ַ�ʽ  ָ���������
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
		//cout<<*(array++); //��������ָ����������� ������Ϊָ�볣����ֵ���ܱ��޸�
	}
	
	cout<<"*******************************"<<endl;
	int i1=30;
	int i2=40;
	const int * pp=&i1;//Ҳ����д��int const *pp=&i1;
	pp=&i2;
	i2=80;
	//*pp=80;���� ��Ϊ��*pp��const����  Ϊ����  ���ܱ��޸ĸ�ֵ ����pp��ȻΪָ����� ������ָ�������ĵ�ַ 
	cout<<*pp<<endl;

	int * const pp1=&i1;
	//pp1=&i2; ���� ��Ϊconst���ε���pp1 ����ָ��pp1Ϊ����  ��������ָ��������ַ
	*pp1 =50;
	cout<<i1<<endl;

	const int i3=40;
	//int *pi3=&i3;  ���� const int ��i3��ַ���ܸ�ֵ��ָ�����pi3���������ͨ��pi3�޸�i3��ֵ ������
	int *pi3 =(int *) &i3;
	*pi3=8; //������Ȼͨ�� ����û�����ֵ�ĸ���
	cout<<*pi3<<" "<<pi3<<" "<<&i3<<" "<<i3<<endl;

	//ֵ����  ���ô��� ָ�봫�� 
	int m=2,n=3;
	//exchange1(m,n);//��������ʾ��û����ɽ��� ��Ϊ��ֵ����ʱ �൱�ڰ�ʵ�θ�ֵ���β� ֮�����еĲ������Ƕ��βα������в���
	//exchange2(&m,&n);//��������ʾ����˽���
	exchange3(m,n);//��������ʾ����˽���
	cout<<m<<" "<<n<<endl;

	//˫ָ��
	char str[]="abcdefghijklmnopqrstuvwxyz";
	char search='d';
	char *pointer=0 ;
	find1(str,search,pointer);
}

//ֵ����
void exchange1(int x,int y){
		int temp;
		temp=x;
		x=y;
		y=temp;
		cout<<x<<" "<<y<<endl;
}
//ָ�봫�ݣ���ַ���ݣ�
void exchange2(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
	cout<<*x<<" "<<*y<<endl;
}
//���ô���
void exchange3(int &x,int &y){
	int temp=x;
	x=y;
	y=temp;
	cout<<x<<" "<<y<<endl;
}

//�˺������ڷ��ز��ҵ�һ���ַ����ĵ�ַ ��Ҫѧϰ˫ָ����÷�
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


