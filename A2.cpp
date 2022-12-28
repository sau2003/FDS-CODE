#include <iostream>
#include<string.h>
using namespace std;
class stu_data
{
	public:
	int roll_no;
	char clas[10];

	long int cnt;
	char name[20];
	char div[4];
	char blood_grp[3];
	char DOB[20];
	static int count;


	void input();
	friend void display(stu_data & obj);

	stu_data()  //Constructor

	{
		roll_no=0;
		cout<<"\t------------------Constructor";
		roll_no=count;
		count++;
	}
	~stu_data()  //Destructor
	{
		cout<<"\nDestructor";
		cout<<"\nDestroying the object";
		count--;
	}
	stu_data(int roll_no)
	{
		this->roll_no=roll_no;
	}

	stu_data (stu_data & obj)
	{
		roll_no=obj.roll_no;
		strcpy(name,obj.name);
		strcpy(DOB,obj.DOB);
		strcpy(clas,obj.clas);
		//blood_grp=obj.blood_grp;
		strcpy(blood_grp,obj.blood_grp);
		//div=obj.div;
		strcpy(div,obj.div);
		cnt=obj.cnt;

		count++;
	}
};
	int stu_data :: count=0;
	void stu_data:: input()
	{
		cout<<"\n"<<"Enter the roll number of the student:";
		cin>>roll_no;

		cout<<"\n"<<"Enter the name of the student:";
		cin>>name;

		cout<<"\n"<<"Enter the date of birth of the student:";
		cin>>DOB;

		cout<<"\n"<<"Enter the blood group of the student:";
		cin>>blood_grp;

		cout<<"\n"<<"Enter the class of the student:";
		cin>>clas;

		cout<<"\n"<<"Enter the division of the student:";
		cin>>div;

		cout<<"\n"<<"Enter the contact of the student:";
		cin>>cnt;
		cout<<'\n*********************************';
	}
	void display(stu_data & obj)
	{
		cout<<"\n"<<obj.roll_no;
		cout<<"\t\t"<<obj.name;
		cout<<"\t"<<obj.DOB;
		cout<<"\t\t"<<obj.blood_grp;
		cout<<"\t"<<obj.clas;
		cout<<"\t"<<obj.div;
		cout<<"\t\t"<<obj.cnt;
			}

int main()
{

	stu_data d1;
	stu_data d2(d1);
	cout<<"----------------------------------------------------";
	cout<<"\n Enter the details of a student:"<<"\n";
	d1.input();

	cout<<"All data is as displayed below:"<<"\n";
	cout<<"\n***********************************************************************";
	cout<<"\nROLL NUMBER\tNAME\tDOB\tBLOOD GRP\tCLASS\tDIVISION\tCONTACT NUMBER";
	display(d1);
cout<<"\n***************************************************************************";

	int i,n;

	stu_data *d[50];
	cout<<"\nEnter how many student object do you want us to create?"<<"\n";
	cin>>n;

	for(i=0;i<n;i++)
	{
		d[i]= new stu_data();
	}

	for(i=0;i<n;i++)
	{
		d[i]->input();

	}


	for(i=0;i<n;i++)
	{
		cout<<"\nROLL NUMBER\tNAME\tDOB\tBLOOD GRP\tCLASS\tDIVISION\tCONTACT NUMBER";
		display(*d[i]);

	}


    //searching by roll no
	 cout<<"enter the roll number you wanted to search\n";
	 int z;
	 cin>>z;
	 for(int i=0;i<n;i++)
	 {
	 	if(s[i].roll_no==z)
	 	{
	 		display(*s[i]);
	 	}
	 }

	 	for(i=0;i<n;i++)
	 {
	 	delete (s[i]);
	 }


	return 0;
}
