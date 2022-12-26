//EXPERIMENT NO.32

/*Pizza parlor accepting maximum M orders. Orders are served in first come first served 
basis. Order once placed cannot be cancelled. Write C++ program to simulate the system 
using circular queue using array*/
#include <iostream>
using namespace std;
#define size 3

class PizzaParlour
{
    int porder[size];
    int front,rear;
    public:
    PizzaParlour()
    {
     front=rear=-1;
    }
    int qfull()
    {
     if((front==0)&&(rear==(size-1))||(front==(rear+1)%size))
         return 1;
     else
         return 0;
    }
    int qempty()
    {
        if(front==-1)
            return 1;
        else
            return 0;
    }
    void AcceptOrder(int);
    void ServeOrder();
    void DisplayOrder();
};

void PizzaParlour::AcceptOrder(int item)
{
    if (qfull())
    {   
        cout<<"\nSorry!!";
        cout<<"\nNot accepting orders!";
    }
     else
     {
        if(front==-1)
        {
            front=rear=0;
        }
        else
        {
            rear=(rear+1)%size;
        }
        porder[rear]=item;
     }
}

void PizzaParlour::ServeOrder()
{
    if(front==-1)
    {
        cout<<"\nNo  more orders!";
    	return;
    }
     else
     {
     	cout<<"\nOrder No. "<<porder[front]<<" is processed.\n";
     	if(front==rear) 
     	{
     		front=rear=-1;
    	}
    	 else
    	{
    	 	front=(front+1)%size;
    	}
 }
}

void PizzaParlour::DisplayOrder()
 {
 	int i=0;
 	if(front==-1)
 	{
 		cout<<"\nNot accepting orders!";
 		return;
	 }
	 else
	 {
	 	cout<<"Order Id's :";
	 	for(i=front;i!=rear;i=((i+1)%size))
	 	{
	 		cout<<porder[i]<<"  ";
		 }
		 cout<<porder[rear];
	 }
 }

int main()
{
    PizzaParlour p1;
    int ch,k,n;
    do
    {
    cout<<"\n\nPIZZA PARLOUR";
     cout<<"\nMENU";
     cout<<"\n1.Accept order";
     cout<<"\n2.Display order";
     cout<<"\n3.Serve order";
     cout<<"\n4.Exit";
     cout<<"\nEnter your choice: ";
     cin>>ch;
     switch(ch)
     {
      case 1:cout<<"\nMENU";
             cout<<"\n1.Veg Exotic Pizza";
             cout<<"\n2.Veg Farmhouse Pizza";
             cout<<"\n3.Veg Paneer Cheeze Pizza";
             cout<<"\nEnter your order: ";
             cin>>k;
             p1.AcceptOrder(k);
             break;
      case 2:p1.DisplayOrder();
       break;

      case 3:p1.ServeOrder();
             break;
     }
    }while(ch!=4);
    cout<<"Exit!";
    return 0;
}
