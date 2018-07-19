#include<iostream>
//iostream provides basic input and output services
#include<conio.h>
//It is a C header file use to modify MS_DOS 
#include<stdlib.h>
//It is general purpose standard library
#include<string.h>
//These header file contains classes which are going to use in exception handling
#include<fstream>
//This provide insertion operation
#include <windows.h>	//To use GUI we have included this header file
using namespace std;
struct player		
{
 char name[20];
 char pl_type[15];
 char team[10];
 float age;

};

fstream F;	//fstream is used to open both input and output F
player object;

void read()		//this read() function will read the data
{
 cout<<"Enter Player Name: ";
 //To take the input as Player Name
 cin>>object.name;
 //To print the Player name
 cout<<"Player Type: ";
 cin>>object.pl_type;
 cout<<"Enter Team: ";
 cin>>object.team;
 cout<<"Enter Age: ";
 cin>>object.age;

 F.open("database.txt",ios::app) ;		//This is F structure format for storing the data
 F.write((char*)&object,sizeof(object));
 F.close();
 
 
 MessageBox(0,"Age will be always in integer format", "Suggestion Box", MB_OK);	//message box code

}

void display()		//display() is a function this will display the data
{       //
 F.open("database.txt",ios::in);
 F.read((char*)&object,sizeof(object));

 while (F.eof()==0)
 {
  cout<<"Name: "<<object.name<<endl;
  cout<<"Type: "<<object.pl_type<<endl;
  cout<<"Team: "<<object.team<<endl;
  cout<<"Age: "<<object.age<<endl<<endl;

  F.read((char*)&object,sizeof(object));
 }
 F.close();

 getch();
}

void search()	//search() is the function this will search the record.
{       //
 float user;
 cout<<"Enter Age: ";
 cin>>user;
 F.open("database.txt",ios::in);
 F.read((char*)&object,sizeof(object));

 while (F.eof()==0)	//intilize condition
 {
  if (object.age==user)
  {
   cout<<"Name: "<<object.name<<endl;
   cout<<"Type: "<<object.pl_type<<endl;
   cout<<"Team: "<<object.team<<endl;
   cout<<"Age: "<<object.age<<endl<<endl;
  }

  F.read((char*)&object,sizeof(object));
 }
 F.close();

 getch();
}

void edit()
{     

 char user[15];
 cout<<"Enter Player Type: ";
 cin>>user;

 F.open("database.txt",ios::in|ios::out);
 F.read((char*)&object,sizeof(object));

 while (F.eof()==0)
 {
  if (strcmp(object.pl_type,user)==0)
  {
   cout<<"Name: "<<object.name<<endl;
   cout<<"Type: "<<object.pl_type<<endl;
   cout<<"Team: "<<object.team<<endl;
   cout<<"Age: "<<object.age<<endl<<endl;

   cout<<"\nEnter New Team: ";
   cin>>object.team;

   F.seekp(F.tellg()-sizeof(object));
   F.write((char*)&object,sizeof(object));
   cout<<"\n\nF Updated";
   break;
  }

  F.read((char*)&object,sizeof(object));
 }
 F.close();

 getch();
}


int main()		//main function
{
	

 int opt;

 while(1)
 {
  
  cout<<"\t**********	Welcome To Player Record Management System	********\n";
  cout<<"Press 1 to Enter Record\n";
  cout<<"Press 2 to Show All Record\n";
  cout<<"Press 3 to Search Record\n";
  cout<<"Press 4 to Exit\n";
  cout<<"\n\nPress Option: ";
  cin>>opt;

  switch (opt)
  {
   case 1:
    read();
    cout<<"\n\nRecord Entered\n";
    getch();
    break;
   case 2:
    display();
    break;
   case 3:
    search();
    break;
   case 4:
    exit(0);
  }
 }

}
