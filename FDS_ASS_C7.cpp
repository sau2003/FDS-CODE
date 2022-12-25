/*Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of Second, third and final year of department can be
 granted membership on request. Similarly one may cancel the membership of club. First node is reserved for president of club and last node 
 is reserved for secretary of club. Write C++ program to maintain club member‘s information using singly linked list. Store student PRN and 
 Name. Write functions to
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Display list in reverse order using recursion
e) Two linked lists exists for two divisions. Concatenate two lists.
-------------------------------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <string.h>
using namespace std;
class node
{
	friend class list;
	int prnno;
	char name[30];
	node *next;          //pointer to object
public:
	node(int d,char s[10])   //prametric constructor
	{
	prnno=d;
		strcpy(name,s);
		next=NULL;
	}
};
class list
{
	node *head;
public:
	list()
    {
		head=NULL;
    }
void display()
{
	node *ptr;
	ptr=head;
	cout<<"\n info is : \n";
	while(ptr!=NULL)
	{
		cout<<"\n"<<ptr->prnno;
		cout<<"\t"<<ptr->name;
		ptr=ptr->next;
	}
}
	void insertmember();
	void createmember();
	void insertpresident();
	void insertsecretary();
	void deletemember();
	void delete1();
	void deletesecretary();
	void deletepresident();
	void count();
	void concatinate(list,list);
};
void list::insertmember()
{
	int prnno;
	char name[30];
	node *ptr,*temp;
	cout<<"\n enter prnno : ";
	cin>>prnno;
	cout<<"\n enter name : ";
	cin>>name;
	temp=new node(prnno,name);  // memery allocation using new keyword
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}
void list::insertpresident()
{
	int prnno;
	char name[30];
		node *temp;
		cout<<"\n enter prnno : ";
		cin>>prnno;
		cout<<"\n enter name : ";
		cin>>name;
		temp=new node(prnno,name);
		temp->next=head;
		head=temp;
}
void list::insertsecretary()
{
	int prnno;
	char name[30];
			node *ptr,*temp;
			cout<<"\n enter prnno : ";
			cin>>prnno;
			cout<<"\n enter name : ";
			cin>>name;
			temp=new node(prnno,name);
			ptr=head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;
}
void list::createmember()
{
	int ch;
	char ans;
	do
	{
	cout<<"\n choose : ";
	cout<<"\n 1-member\n 2-secretary\n 3-president";
	cin>>ch;
	switch(ch)
	{
	case 1: insertmember();
		    break;
	case 2: insertsecretary();
		    break;
	case 3: insertpresident();
		    break;
	default:cout<<"invalid choice ! ";
		    break;
	}
	cout<<"\n insert more ?(y/n)";
	cin>>ans;
	}while(ans=='y');
}
void list::delete1()
{
		int ch;
		char ans;
		do
		{
		cout<<"\n choose : ";
		cout<<"\n 1-member\n 2-secretary\n 3-president";
		cin>>ch;
		switch(ch)
		{
		case 1:deletemember();
			   break;
		case 2:deletesecretary();
			   break;
		case 3:deletepresident();
			   break;
		default:cout<<"invalid choice ! ";
			    break;
		}
		cout<<"\n delete more ?(y/n)";
		cin>>ans;
		}while(ans=='y');
	}
void list::deletesecretary()
{
	node *ptr,*prev;
	ptr=head;
	while(ptr->next!=NULL)
	{
		prev=ptr;
		ptr=ptr->next;
	}
		prev->next=NULL;
		delete ptr;
	    cout<<"\n deleted";
}
void list::deletepresident()
{
	node *ptr;
		ptr=head;
		head=head->next;
		delete ptr;
		cout<<"\n deleted";
}
void list::deletemember()
{
	node *ptr,*prev;
	int p;
	cout<<"\n enter prnno. to delete : ";
	cin>>p;
			ptr=head;
			while(ptr->next!=NULL)
			{
				prev=ptr;
				ptr=ptr->next;
				if(ptr->prnno==p)
				  break;
			}
			if(ptr->next==NULL)
			{
				cout<<"\n data not found !";
			}
			else if(ptr->prnno==p)
			{
				prev->next=ptr->next;
				ptr->next=NULL;
				delete ptr;
				cout<<"\n deleted";
			}
}
void list::count()
{
	node *ptr;
	int cnt=0;
	ptr=head;
	while(ptr!=NULL)
	{
		cnt++;
		ptr=ptr->next;
	}
	cout<<"\n total no. of nodes is : "<<cnt;
}

void list::concatinate(list s1,list s2)
	{
	node *ptr;
	ptr=s1.head;
	while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=s2.head;
		s1.display();
	}
int main()
{
	int ch;
	char ans;
	list sll1,sll2,s1,s2;
	do
	{
		cout<<"\n enter your choice : ";
	    cout<<"\n 1-create member\n 2-display\n 3-delete member\n 4-no. of nodes\n 5-concatenate";
        cin>>ch;
switch(ch)
{
   case 1: sll1.createmember();
		   break;
   case 2: sll1.display();
		   break;
   case 3: cout<<"\n enter the nodes to be deleted in list : ";
		   sll1.delete1();
		   break;
   case 4: cout<<"\n no. of nodes is:";
		   sll1.count();
		   break;
   case 5:  sll2.createmember();
		   sll1.concatinate(sll1,sll2);
		   break;
   default: cout<<"\n invalid choice ! ";
		    break;
 }
		   cout<<"\n\n do you want to continue ?(y/n) ";
		   cin>>ans;
	}while(ans=='y');
	return 0;
}

