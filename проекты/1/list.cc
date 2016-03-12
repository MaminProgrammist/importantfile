#include <iostream>
using namespace std;
struct element
{
	int number; // какие-то данные
	element *next;//закидываем в next адрес структуры element
};
struct List
{
	element *head;//закидываем в head адрес структуры element и считаем как начало
	List(): head(NULL) {}
	void PF(int x) // добавление в начало списка
	{
		element *p=new element;// создаём ячейку памяти с указателем для element
		p->number=x;// присваиваем значение х значению number в element(е)
		p->next=head;//присваиваем значению указателя next значение указателя head
		head=p;// теперь head указывает на выделенную нами структуру
		
	}
	void PE(int x)
	{
		element *p=new element;
		element *a=head;
		p->number=x;
		while(a!=NULL && a->next!=NULL)
		{
			a=a->next;
		}
		a->next=p;
		p->next=NULL;
	}
	void PM(int x, int y)
	{
		int i,test=0;
		element *p=new element;
		element *a=head;
		p->number=x;
		for(i=0;i<y;i++)
		{
			if(a!=NULL && a->next!=NULL)
			a=a->next;
			else {test++; break;}
		}
		if(test==0)
		{
			p->next=a->next;
			a->next=p;
		}
		else
		cout<<"Error"<<endl;
	}
	void DELF()
	{
		element *a=head;
		head=a->next;
		delete a;
	}	
	void DELM(int y)
	{
		int i,test=0;
		element *ass;
		element *a=head;
		for(i=0;i<y;i++)
		{
			if(a!=NULL && a->next!=NULL)
			a=a->next;
			else {test++; break;}
		}
		if(test!=0)
		cout<<"Error"<<endl;
		else
		{
			ass=a->next;
			a->next=ass->next;
			delete ass;
		}
	}
	void OUT()//вывод 
	{
		element *a=head;
		while(a!=NULL)
		{
			cout<<a->number<<endl;
			a=a->next;
		}
	}
	void DR()
	{
		element *a=head;
		element *ass;
		while(a!=NULL)
		{
			ass=a;
			a=a->next;
			delete ass;
		}
	}
	~List() 
	{
		element *a=head; 
		while(a!=NULL)
		{
			a=head; 
			head=head->next; 
			cout<<"deleted 1 element"<<endl; 
			delete a;
		}
	}
};

int main()
{
	List A;
	int x,i,n,a,y,ass=0;
	char test;
	cout<<"Start?"<<endl;
	cout<<"Y/N"<<endl;
	cin>>test;
	cout<<"-------------------------"<<endl;
	while(test=='Y' || test=='y')
 {
	if(ass!=1)
	{
		cout<<"Tape first element of the list: "<<endl;
		cin>>x;
		ass=1;
		A.PF(x);
		cout<<"-------------------------"<<endl;
	}
	cout<<"Tape '1' to put first element."<<endl;
	cout<<"Tape '2' to put last element."<<endl;
	cout<<"Tape '3' to put middle element."<<endl;
	cin>>a;
	cout<<"-------------------------"<<endl;
	if(a==1)
	{
		cout<<"How many numbers you need to add?"<<endl;
		cin>>n;
		cout<<"-------------------------"<<endl;
		cout<<"Please, tape elements:"<<endl;
			for(i=0;i<n;i++)
		{
			cin>>x;
			A.PF(x);
			cout<<"----"<<endl;
		}
	}
	else if(a==2)
	{
		cout<<"How many numbers you need to add?"<<endl;
		cin>>n;
		cout<<"-------------------------"<<endl;
		cout<<"Please, tape elements:"<<endl;
		for(i=0;i<n;i++)
		{
			cin>>x;
			A.PE(x);
			cout<<"----"<<endl;
		}
	} else
	if(a==3)
	{
		cout<<"How many numbers you need to add?"<<endl;
		cin>>n;
		cout<<"-------------------------"<<endl;
		for(i=0; i<n;i++)
		cout<<"Tape element:"<<endl;
		cin>>x;
		cout<<"Tape position:"<<endl;
		cin>>y;
		while(y<=0)
		{
		cout<<"WARNING"<<endl;
		cout<<"Wrong position!"<<endl;
		cout<<"Please, tape again:"<<endl;
		cin>>y;
		}
		if(y==1) A.PF(x);
		else
		{ y=y-2; A.PM(x,y);}
	}
	cout<<"-------------------------"<<endl;
	cout<<"Your list:"<<endl;
	A.OUT();
	cout<<"-------------------------"<<endl;
	
	cout<<"Is there anything you need to delete?"<<endl;
	cout<<"Y/N"<<endl;
	cin>>test;
	if(test=='Y' || test=='y')
	for(i=0;i<n;i++)
	{
		cout<<"How many numbers you need to delete?"<<endl;
		cin>>n;
		cout<<"-------------------------"<<endl;
		for(i=0;i<n;i++)
		{
			cout<<"Tape the position of element that needs to be removed."<<endl;
			cout<<"Tape position:"<<endl;
			cin>>y;
			cout<<"-------------------------"<<endl;
			if(y==1)
			A.DELF();
			else
			{
				while(y<=0)
				{
					cout<<"WARNING"<<endl;
					cout<<"Wrong position!"<<endl;
					cout<<"Please, tape again:"<<endl;
					cin>>y;
					cout<<"-------------------------"<<endl;
				}
				y=y-2;
				A.DELM(y);
			}
		cout<<"Your list:"<<endl;
		A.OUT();
		cout<<"-------------------------"<<endl;
		}
	}
	
	cout<<"Do you want to continue?"<<endl;
	cin>>test;
 }
	return 0;
}
