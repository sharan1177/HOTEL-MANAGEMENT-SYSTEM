#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
#include<stdlib.h>
#include<conio.h>
using namespace std;
void managerDisplaymenu();
void recieptionistDisplaymenu();
void shar();
class Employee
{
	protected:
    	string username,password;
	public:
   		virtual int login(string a,string b)=0;
};
class Recieptionist : public Employee 
{
	public:
    	int login(string a, string b);
};
class Manager : public Employee
{
	public:
    	int login(string a, string b);
};
class Room
{
	private:
		int nic,roomcategory,roomtype,roomno,roomprice;
    	string name,mobile,roomtypename,cat,typ;
	public:
    	void setReservationData(int c,string a,string b,int d,int e);
		void readdata(int a);
    	void displayReservation();
    	void Reservation();
    	void addroom(int a, int b, int c);
     	void deleteroom(int a);
     	void checkout();
};
void managerDisplaymenu()
{
    Room room1;
    int category,no,type,price,choice;
    system("cls");
	cout<<"\n\t\t\t------------------------------------------";
	cout<<"\n\t\t\t   ------------ Main Menu -------------";
	cout<<"\n\t\t\t      ------------------------------";
	cout<<"\n\t\t\t         -------------------------";
    cout<<"\n\n\t\t1.Add Rooms "<<endl;
    cout<<"\t\t2.Delete Rooms "<<endl;
    cout<<"\t\t3.View Rooms "<<endl;
    cout<<"\t\t4.View Reservation Details"<<endl;
    cout<<"\t\t5.Logout "<<endl;
    cout<<"\n\t\tEnter your choice : ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        system("cls");
       	cout<<"\n\nEnter Room No : ";
        cin>>no;
       	cout<<"\n\n\t1 - Ordinary"<<endl;
        cout<<"\t2 - Luxury"<<endl;
        cout<<"\t3 - Royal"<<endl;
        cout<<"\nEnter Room Category : ";
        cin>>category;
        cout<<"\n\n\t1 - Single"<<endl;
        cout<<"\t2 - Double"<<endl;
        cout<<"\t3 - Suit"<<endl;
        cout<<"\nEnter Room type     : ";
        cin>>type;
        room1.addroom(no,category,type);
        break;
        case 2:
        system("cls");
        cout<<"\n\t1 - Ordinary"<<endl;
        cout<<"\t2 - Luxuary"<<endl;
        cout<<"\t3 - Royal"<<endl;
        cout<<"\n\nEnter Room Category : ";
        cin>>category;
        room1.deleteroom(category);
        break;
        case 3:
        system("cls");
        cout<<"\n\t1 - Ordinary"<<endl;
        cout<<"\t2 - Luxuary"<<endl;
        cout<<"\t3 - Royal"<<endl;
        cout<<"\n\nEnter Room Category : ";
        cin>>category;
        room1.readdata(category);
        managerDisplaymenu();
        break;
        case 4:
        system("cls");
        room1.displayReservation();
        managerDisplaymenu();
        break;
        case 5:	shar();
        default:
        cout<<"\n\n\t\tInvalid Choice! Try again"<<endl<<endl;
        Sleep(2000);
        managerDisplaymenu();
    }
}
void recieptionistDisplaymenu()
{
    Room room1;
    int category,type,norooms,choice,roomcategory,roomtype,nic,noofrooms;
    string name,mobile;
    system("cls");
	cout<<"\n\t\t\t------------------------------------------";
	cout<<"\n\t\t\t   ------------ Main Menu -------------";
	cout<<"\n\t\t\t      ------------------------------";
	cout<<"\n\t\t\t         -------------------------";
    cout<<"\n\n\t\t1.Reserve a room "<<endl;
    cout<<"\t\t2.View Reservation Details"<<endl;
    cout<<"\t\t3.View Room Details "<<endl;
    cout<<"\t\t4.Genarate Bill"<<endl;
    cout<<"\t\t5.Logout "<<endl;
    cout<<"\n\t\tEnter your choice : ";
    cin>>choice;
    switch(choice)
    {
        case 1:
   		system("cls");
   		cout<<"\n\t\t*************** Reservation Details ****************** ";
    	cout<<"\nEnter the room number: ";
    	cin>>nic;
   		cout<<"\nEnter Name of the customer: ";
    	cin>>name;
    	cout<<"\nEnter Mobile no: ";
    	cin>>mobile;
    	cout<<"\nEnter The Room Category : ";
    	cin>>roomcategory;
    	cout<<"\nEnter The Room Type : ";
    	cin>>roomtype;
    	room1.setReservationData(nic,name,mobile,roomcategory,roomtype);
    	room1.Reservation();
        break;
        case 2:
        system("cls");
        room1.displayReservation();
        recieptionistDisplaymenu();
        break;
        case 3:
    	system("cls");
        cout<<"\n\t1 - Ordinary"<<endl;
        cout<<"\t2 - Luxuary"<<endl;
        cout<<"\t3 - Royal"<<endl;
        cout<<"\n\nEnter Room Category : ";
        cin>>category;
        room1.readdata(category);
        recieptionistDisplaymenu();
        break;
        case 4:
        room1.checkout();
        recieptionistDisplaymenu();
        break;
        case 5:	shar();
        default:
        cout<<"\n\n\t\tInvalid Choice! Try again"<<endl<<endl;
        Sleep(2000);
        recieptionistDisplaymenu();
    }
}
void shar()
{
	Manager man;
    Recieptionist rec;
    int usertype,choice,result;
    string username,password;
	do{
    system ("cls");
    cout<<"\n\t1 - Manager"<<endl;
    cout<<"\t2 - Receptionist\n"<<endl;
    cout << "Enter user type : ";
    cin>>usertype;
    if(usertype==1)
    {
    	cout<<"\nEnter username : ";
    	cin>>username;
    	cout<<"\nEnter password : ";
    	cin>>password;
    	result=man.login(username,password);
	}
	else if(usertype==2)
    {
        cout<<"\nEnter username : ";
        cin>>username;
        cout<<"\nEnter password : ";
        cin>>password;
    	result=rec.login(username,password);
    }
    else
    {
        cout<<"\n\t\t********* Invalid user type ***********"<<endl;
        cout<<endl<<endl<<"Press any key to go back";
   		getch();
        shar();
    }
 }while(result!=1); }
int Recieptionist::login(string a,string b)
{	
    if(a=="dsp"&&b=="1221")
    {
    	system("cls");
        cout<<"\n\n\n\n\t\t\t  ********* Login Successful ***********"<<endl;
        Sleep(1700);
    	recieptionistDisplaymenu();
        return 1;
    }
    else
    {	system("cls");
        cout<<"\n\n\n\n\t\t\t********* Invalid username or password ***********"<<endl;
        Sleep(1700);
    	return 0;
    }
}
int Manager::login(string a,string b)
{   
	if(a=="sharan"&&b=="1177")
    {
    	system("cls");
        cout<<"\n\n\n\n\t\t\t  ********* Login Successful ***********"<<endl;
        Sleep(1700);
		managerDisplaymenu();
    	return 1;
    }
    else
    {	system("cls");
        cout<<"\n\n\n\n\t\t\t********* Invalid username or password ***********"<<endl;
        Sleep(1700);
        return 0;
    }
}
void Room :: setReservationData(int c,string a,string b,int d,int e)
{
	nic=c;
    name=a;
    mobile=b;
    roomcategory=d;
    if(roomcategory==1)
        cat="Ordinary";
	else if(roomcategory==2)
		cat="Luxury";
	else
		cat="Royal";
    roomtype=e;
    if(roomtype==1)
        typ="Single";
	else if(roomtype==2)
		typ="Double";
	else
		typ="Suit";
}
void Room::readdata(int a)
{ 
	Room room1;
    if(a==1)
    {
  		ifstream file("ordinary.txt",ios::in);
		string display,display1;
    	file>>display>>display1;
    	if(file.is_open())
    	{
    		cout<<"Room Number\tRoom Type"<<endl;
        	while(!file.eof())
       		{
            	cout<<"\n"<<display<<"\t\t"<<display1<<endl;
            	file>>display>>display1;
       		}
    	}	
    	else
        	cout<<"Error"<<endl;
    	file.close();
    }
    else if(a==2)
    {
        ifstream file("luxuary.txt",ios::in);
    	string display,display1;
    	file>>display>>display1;
    	if(file.is_open())
    	{
    		cout<<"Room Number\tRoom Type"<<endl;
       		while(!file.eof())
        	{
            	cout<<"\n"<<display<<"\t\t"<<display1<<endl;
            	file>>display>>display1;
        	}
   		}
   		else
        	cout<<"Error"<<endl;
    	file.close();
    }
    else if(a==3)
    {
        ifstream file("royal.txt",ios::in);
    	string display,display1;
    	file>>display>>display1;
    	if(file.is_open())
    	{
    		cout<<"Room Number\tRoom Type"<<endl;
       		while(!file.eof())
        	{
        		cout<<"\n"<<display<<"\t\t"<<display1<<endl;
           		file>>display>>display1;
        	}
    	}
    	else
        	cout<<"Error"<<endl;
    	file.close();
    }
    else
    	cout<<"Invalid Category "<<endl;
    cout<<endl<<endl<<"Press Any key to go Main Menu"<<endl;
    getch();
}
void Room::displayReservation()
{	
	Room room1;
    ifstream file("ReservationRooms.txt",ios::in);
    string display,display1,display2,display3,display4;
    file>>display>>display1>>display2>>display3>>display4;
    cout<<"\n\tRoom Number\t\tName\t\tMobile No\t\tRoom Category\t\tRoom Type"<<endl<<endl;
    if(file.is_open())
    {
        while(!file.eof())
        {
        	cout<<"\t"<<display<<"\t\t\t"<<display1<<"\t\t"<<display2<<"\t\t"<<display3<<"\t\t"<<display4<<endl<<endl;
            file>>display>>display1>>display2>>display3>>display4;   
        }
    }
    else
    	cout<<"Error"<<endl;
    file.close();
    cout<<"\n\nPress any key to go Main Menu ";
    getch();
}
void Room :: Reservation()
{
	Room room1;
    ofstream file1("ReservationRooms.txt",ios::app);
    if(file1.is_open())
    {
        file1<<nic<<"\t"<<name<<"\t"<<mobile<<"\t"<<cat<<"\t"<<typ<<"\n";
       	cout<<"\nSuccessfully Reserved!"<<endl;
    }
    else
    	cout<<"Error";
    file1.close();
    cout<<"\nPress any key to go Main Menu ";
    getch();
    recieptionistDisplaymenu();
}
void Room :: addroom(int a, int b, int c)
{
	Room room1;
    roomno=a;
    roomcategory=b;
    roomtype=c;
    if(roomtype==1)
        roomtypename="Single";
    else if(roomtype==2)
        roomtypename="Double";
    else if(roomtype==3)
        roomtypename="Suit";
    else
    {
        cout<<"\n\t\tinvalid type "<<endl;
        cout<<"Press Any key to go Main Menu"<<endl;
        getch();
        managerDisplaymenu();
    }
    if(roomcategory==1)
    {
        ofstream file1("ordinary.txt",ios::app);
        file1<<roomno<<"\t"<<roomtypename<<"\n";
        cout<<"\nSuccessfully Added Room! "<<endl;
        file1.close();
    }
    else if(roomcategory==2)
    {
        ofstream file1("luxuary.txt",ios::app);
        file1<<roomno<<"\t"<<roomtypename<<"\n";
        cout<<"\nSuccessfully Added Room! "<<endl;
        file1.close();
    }
    else if(roomcategory==3)
    {
        ofstream file1("royal.txt",ios::app);
        file1<<roomno<<"\t"<<roomtypename<<"\n";
        cout<<"\nSuccessfully Added Room! "<<endl;
        file1.close();
    }
    else
        cout<<"\n\t\tinvalid category "<<endl;
    cout<<endl<<"Press Any key to go Main Menu"<<endl;
    getch();
    managerDisplaymenu();
}
void Room :: deleteroom(int a)
{
	Room room1;
    roomcategory=a;
    if(roomcategory==1)
    {
        ofstream file1("ordinary.txt");
        if(file1.is_open())
        {
            file1<<"\n";
        	cout<<"\n Deleted!"<<endl;
        }
        else
            cout<<"Error";
    }
    else if(roomcategory==2)
    {
        ofstream file1("luxuary.txt");
        if(file1.is_open())
        {
            file1<<"\n";
        	cout<<"\n Deleted!"<<endl;
        }
        else
            cout<<"Error";
    }
    else if(roomcategory==3)
    {
        ofstream file1("royal.txt");
        if(file1.is_open())
        {
            file1<<"\n";
        	cout<<"\n Deleted!"<<endl;
        }
        else
            cout<<"Error";
    }
    else
        cout<<"\nInvalid Room Category!"<<endl;
    cout<<"\n\nPress any key to go Main Menu ";
    getch();
    managerDisplaymenu();
}
int bill(int a,int b)
{
	if(a==1)
	{
		if(b==1)
			return 1000;
		else if(b==2)
			return 1500;
		else
			return 2000;
	}
	else if(a==2)
	{
		if(b==1)
			return 1500;
		else if(b==2)
			return 2000;
		else
			return 2500;
	}
	else
	{
		if(b==1)
			return 2000;
		else if(b==2)
			return 2500;
		else
			return 3000;
	}
}
void Room::checkout()
{
	int x,y,z;
	system("cls");
    cout<<endl<<"\nEnter Room Category : ";
    cin>>x;
    cout<<endl<<"\nEnter Room Type : ";
    cin>>y;
    cout<<endl<<"\nEnter Room Number : ";
    cin>>z;
    int result=bill(x,y);
    cout<<"\nRoom Number : "<<z<<"\nRoom Bill : "<<result;
    cout<<endl<<"Checked out";
    cout<<endl<<endl<<"Press Any key to go Main Menu"<<endl;
    getch();
}
int main()
{
	cout<<"\n\t\t\t         -------------------------";
	Sleep(100);
	cout<<"\n\t\t\t      ------------------------------";
	Sleep(100);
	cout<<"\n\t\t\t   ------------------------------------";
	Sleep(100);
	cout<<"\n\t\t\t------------------------------------------";
	Sleep(100);
	cout<<"\n\t\t\t\t* ";
	cout<<"HOTEL ";
	Sleep(250);
	cout<<"MANAGEMENT ";
	Sleep(250);
	cout<<"SYSTEM ";
	Sleep(100);
	cout<<"*";
	Sleep(100);
	cout<<"\n\t\t\t------------------------------------------";
	Sleep(100);
	cout<<"\n\t\t\t   ------------------------------------";
	Sleep(100);
	cout<<"\n\t\t\t      ------------------------------";
	Sleep(100);
	cout<<"\n\t\t\t         -------------------------";
	Sleep(600);
    char a= 177,b=219;
    cout<<"\n\n\t\t\tLoading...";
    cout<<"\n\n\t\t\t";
    for(int i=0;i<=40;i++)
        cout<<" " ;
      Sleep(70);
    cout<<"\r";
    cout<<"\t\t\t";
    for(int i=0;i<=40;i++)
    {
        cout<<b;
        Sleep(70);
    }
    shar();
    return 0;
}
