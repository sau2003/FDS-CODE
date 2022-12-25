/*Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set 
B of students like butterscotch ice-cream. Write C++ program to store two sets using 
linked list. compute and display
a) Set of students who like both vanilla and butterscotch
b) Set of students who like either vanilla or butterscotch or not both
c) Number of students who like neither vanilla nor butterscotch*/

#include<iostream>
using namespace std;
class node
{   
    public:
     int roll;
      class node *next;
};
class info
{        node *head1=NULL,*temp1=NULL,*head2=NULL,*temp2=NULL,*head=NULL,
         *temp=NULL,*h1=NULL,*head3=NULL,*temp3=NULL;
        int c,i,f,j,k;       
        public:   
            node*create();
            void insert();
            void SetU();
            void SetA();
            void SetB();
            void SetA_OR_SetB();
            void SetA_AND_SetB();
            void SetA_NOR_SetB();
            void OnlySetA();
            void OnlySetB();
            void display();               
} ;        
node *info::create()
{   node *p=new(class node);
     cout<<"Enter student RollNo :";
     cin>>c;
     p->roll=c;
     p->next=NULL;
     return  p;
  } 

  void info::insert()
  { 
       node *p=create();
   
     if(head==NULL)
     {    head=p;
     }
    else
    {      temp=head;
          while(temp->next!=NULL)
          {    temp=temp->next;   }
              temp->next=p;
     }        

   }
   void info::display()
   {  temp=head;
      while(temp->next!=NULL)
      { cout<<" "<<temp->roll;
        temp=temp->next;
      } cout<<" "<<temp->roll;
   }

   void info::SetU()
   {cout<<"Enter no of students :";
       cin>>k;
        head=NULL;
       for(i=0;i<k;i++)
       {    insert();
            h1=head;
           
       }cout<<"Set U:"; 
        display();
       head=NULL;
    }

    void info::SetA()
    {
       cout<<"Enter no of students who like Vanila :";
       cin>>k;
        head=NULL;
       for(i=0;i<k;i++)
       { insert();
         head1=head;
          
       } cout<<"Set A:";
        display();
        head=NULL;
     }

     void info::SetB()
     {
      cout<<"Enter no of students who like Butterscotch :";
       cin>>j;
       for(i=0;i<j;i++)
       { insert();
         head2=head;
        
       } cout<<"Set B:";
       display();
       head=NULL;
     }

     void info::SetA_OR_SetB()
{    cout<<"Students who like vanila or butterscotch :";
     temp1=head1;
     while(temp1!=NULL)
     {
       node *p=new(class node);
       p->roll=temp1->roll;
       p->next=NULL;     
     if(head3==NULL)
     {    head3=p;
     }
    else
    {      temp3=head3;
          while(temp3->next!=NULL)
          {    temp3=temp3->next;   }
              temp3->next=p;
     }
       
       temp1=temp1->next;
     }
     temp2=head2;
     while(temp2!=NULL)
     {    f=0;
         temp1=head1;
         while(temp1!=NULL)
         {
         if(temp2->roll==temp1->roll)
         { f=1;                   }
          temp1=temp1->next;
         }         
    
     if(f==0)
     {  
         node *p=new(class node);
       p->roll=temp2->roll;
       p->next=NULL;     
       if(head3==NULL)
        {    head3=p;
        }
       else
       {      temp3=head3;
          while(temp3->next!=NULL)
          {    temp3=temp3->next;   }
              temp3->next=p;
       }
  }
      temp2=temp2->next;     
     }
     temp3=head3;
      while(temp3->next!=NULL)
      { cout<<temp3->roll<<" ";
        temp3=temp3->next;
      } cout<<temp3->roll<<" ";
}

void info::OnlySetA()
{
       cout<<"\nStudents who like only vanila :";
       temp1=head1;
       while(temp1!=NULL)
       {  temp2=head2;
          f=0;
          while(temp2!=NULL)
          {   if(temp1->roll==temp2->roll)
              {  f=1;              }
               temp2=temp2->next;
          } 
         
          if(f==0)
          { cout<<temp1->roll<<" ";    }
             temp1=temp1->next;
        }
       
}

void info::OnlySetB()
{
    cout<<"\nStudents who like only Butterscotch :";
        temp2=head2;
       while(temp2!=NULL)
       {  temp1=head1;
          f=0;
          while(temp1!=NULL)
          {   if(temp2->roll==temp1->roll)
              {  f=1;              }
               temp1=temp1->next;
          } 
         
          if(f==0)
          { cout<<temp2->roll<<" ";    }
             temp2=temp2->next;
        }
       
            
}
void info::SetA_AND_SetB()
{
       cout<<"\nStudents who like both Vanila and Butterscotch :";
       temp1=head1;
       while(temp1!=NULL)
       { temp2=head2;
         while(temp2!=NULL)
         {  if(temp1->roll==temp2->roll)
             { cout<<temp1->roll<<" ";   }
              temp2=temp2->next;
          }
            
            temp1=temp1->next;
        }
        
}
 void info::SetA_NOR_SetB()
 {

    cout<<"\nStudents who like neither Vanila nor Butterscotch :";
    temp=h1;
       while(temp!=NULL)
       {  temp3=head3;
          f=0;
          while(temp3!=NULL)
          {   if(temp->roll==temp3->roll)
              {  f=1;              }
               temp3=temp3->next;
          } 
         
          if(f==0)
          { cout<<temp->roll<<" ";    }
             temp=temp->next;
        }
      
}
 
int main()
  { info s;
  int i;
   
          char ans = 'y';
       do{
          cout<<"\nMENU";
          cout<<"\n1.Total no of students";
          cout<<"\n2.Students who like vanila";
          cout<<"\n3.Students who like butterscotch";
          cout<<"\n4.Students who like vanila or butterscotch";
          cout<<"\n5.Display no of student who like only vanila";
          cout<<"\n6.Display no of student who like only butterscotch";
          cout<<"\n7.Display Set of students who like both vanilla and butterscotch  ";
          cout<<"\n8.Display number of students who like neither vanilla nor butterscotch";
          cout<<"\n\nEnter your choice :";
  
          cin>>i;
         switch(i)

         {        case 1:  s.SetU();
                                  break;
         
                  case 2:  s.SetA(); 
                                  break;

                  case 3:  s.SetB();
                                  break;

                  case 4:   s.SetA_OR_SetB();
                                  break;

                  case 5:   s.OnlySetA();
                                  break;

                  case 6:   s.OnlySetB();
                                  break;

                  case 7:   s.SetA_AND_SetB(); 
                                  break;

                  case 8:   s.SetA_NOR_SetB();
                                  break; 

                  default:  cout<<"\n unknown choice";
          }
            cout<<"\nDo you want to continue (y/n):";
            cin>>ans;
       
       }while(ans == 'y' ||ans == 'Y' );   

return 0;
}