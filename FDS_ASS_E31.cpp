/*A double-ended queue (deque) is a linear list in which additions and deletions may be 
made at either end. Obtain a data representation mapping a deque into a one dimensional array. 
Write C++ program to simulate deque with functions to add and delete elements from either end 
of the deque.*/

/*#include<iostream>
using namespace std;
#define SIZE 5

class dequeue
{
    public:
    int a[10],front,rear,count;
    dequeue();
	void add_at_beg(int);
	void add_at_end(int);
	void delete_fr_front();
	void delete_fr_rear();
	void display();
};


dequeue::dequeue()
{
	front=-1;
	rear=-1;
	count=0;
}


void dequeue::add_at_beg(int item)
{
	int  i;
	if(front==-1)
	{
		front++;
		rear++;
		a[front]=item;
		count++;
	}
	else if(rear>=SIZE-1)
	{
		cout<<"\nInsertion is not possible,overflow!!!!";
	}
	else
	{
		for(i=count;i>=0;i--)
		{
			a[i]=a[i-1];
		}
		a[i]=item;
		count++;
		rear++;
	}
}



void dequeue::add_at_end(int item)
{

	if(front==-1)
	{
		front++;
		rear++;
		a[rear]=item;
		count++;
	}
	else if(rear>=SIZE-1)
	{
		cout<<"\nInsertion is not possible,overflow!!!";
		return;
	}
	else
	{
		a[++rear]=item;
	}


}



void dequeue::display()
{

	for(int i=front;i<=rear;i++)
	{
		cout<<a[i]<<" ";	}
}


void dequeue::delete_fr_front()
{
	if(front==-1)
	{
		cout<<"Deletion is not possible:: Dequeue is empty";
		return;
	}
	else
	{
		if(front==rear)
		{
			front=rear=-1;
			return;
		}
		cout<<"The deleted element is "<<a[front];
		front=front+1;
	}


}

void dequeue::delete_fr_rear()
{
	if(front==-1)
	{
		cout<<"Deletion is not possible:Dequeue is empty";
		return;
	}
	else
	{
		if(front==rear)
		{
			front=rear=-1;
		}
		cout<<"The deleted element is "<< a[rear];
		rear=rear-1;
	}


}



int main()
{
	int c,item;
	dequeue d1;

	do
	{
		cout<<"\n\n****DEQUEUE OPERATION****\n";
		cout<<"\n1-Insert at beginning";
		cout<<"\n2-Insert at end";
		cout<<"\n3_Display";
		cout<<"\n4_Deletion from front";
		cout<<"\n5-Deletion from rear";
		cout<<"\n6_Exit";
		cout<<"\nEnter your choice<1-6>:";
		cin>>c;

		switch(c)
		{
		case 1:
			cout<<"Enter the element to be inserted:";
			cin>>item;
			d1.add_at_beg(item);
			break;

		case 2:
			cout<<"Enter the element to be inserted:";
			cin>>item;
			d1.add_at_end(item);
			break;

		case 3:
			d1.display();
			break;

		case 4:
			d1.delete_fr_front();
			break;
		case 5:
			d1.delete_fr_rear();
			break;

		case 6:
			exit(1);
			break;

		default:
			cout<<"Invalid choice";
			break;
		}

	}while(c!=7);
	return 0;

}*/

#include<iostream> //Header Files
using namespace std;

char que[5];  //.......Double Ended Queue
int size = 5;  //.......Size of Queue
int front = -1; //.......Front End
int rear = -1;  //.......Rear End

int que_full() //.......To check Queue is Full 
{
   if (rear == size-1)
      return 1;
   else
      return 0;
}

int que_empty() //.......To check Queue is Empty
{
   if(front == rear == -1 || front == rear)
      return 1;
   else
      return 0;
}

void insert_AtRear(char job) //.......To Insert at Rear in DEQueue
{
   rear++;
   que[rear] = job;
}

void insert_AtFront(char job) //.......To Insert at Front in DEQueue
{ 
   que[front] = job;
   front--;
}
   
char del_AtFront()  //.......To Delete From Front From DEQueue
{
   char ch;
 
   front++;
   ch = que[front];
 
   return ch;
}

char del_AtRear()  //.......To Delete From Rear From DEQueue
{
   char ch;
 
   ch = que[rear];
   rear--;
 
   return ch;
}


void display()  //.......To Display Queue.
{
   cout<<"\n\n Front--->  ";
   for(int i = front+1;i <= rear;i++)
      cout<<"  "<<que[i];
   
   cout<<"  <---Rear"; 
}


int main()
{
     int choice;
     char job,ans;
   
     do
     {
     cout<<"\n\n ** Menu **";
     cout<<"\n\n 1. Insert at Rear in DEQueue";
     cout<<"\n\n 2. Delete From Front in DEQueue";
     cout<<"\n\n 3. Insert at Front in DEQueue";
     cout<<"\n\n 4. Delete From Rear in DEQueue"; 
     cout<<"\n\n 5. Display DEQueue"; 
                   
   
     cout<<"\n\n Enter your choice:  ";                       
     cin>>choice;
   
     switch(choice)
     {
        case 1: cout<<"\n\n Enter the Job:  ";
        cin>>job;
         insert_AtRear(job);
         break;

        case 2: cout<<"\n\n Deleted Job:  "<<del_AtFront();
         break;

        case 3: cout<<"\n\n Enter the Job:  ";
        cin>>job;
         insert_AtFront(job);
         break;

        case 4: cout<<"\n\n Deleted Job:  "<<del_AtRear();
         break;

        case 5: display();
         break;
         
        default: cout<<"\n\n Invalid choice.....!!!";
     }
     cout<<"\n\n Do u wanna continue ?? (y/n) : ";
     cin>>ans;
     }while(ans == 'y');
   
     cout<<"\n\n";
     return 0;
}  
