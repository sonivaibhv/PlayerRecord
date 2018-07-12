#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include <windows.h>	//To use GUI we have included this header file
using namespace std;
struct player		
{
 char name[20];
 char reg[15];
 char team[10];
 float age;

};

fstream file;	//fstream is used to open both input and output file
player obj;

void read()		//this read() function will read the data
{
 cout<<"Enter Player Name: ";
 cin>>obj.name;
 cout<<"Player Type: ";
 cin>>obj.reg;
 cout<<"Enter Team: ";
 cin>>obj.team;
 cout<<"Enter Age: ";
 cin>>obj.age;

 file.open("database.txt",ios::app) ;		//This is file structure format for storing the data
 file.write((char*)&obj,sizeof(obj));
 file.close();
 
 MessageBox(0,"Age will be always in integer format", "Title", MB_OK);	//message box code

}

void display()		//display() is a function this will display the data
{       //clrscr();	
 file.open("database.txt",ios::in);
 file.read((char*)&obj,sizeof(obj));

 while (file.eof()==0)
 {
  cout<<"Name: "<<obj.name<<endl;
  cout<<"Type: "<<obj.reg<<endl;
  cout<<"Team: "<<obj.team<<endl;
  cout<<"Age: "<<obj.age<<endl<<endl;

  file.read((char*)&obj,sizeof(obj));
 }
 file.close();

 getch();
}

void search()	//search() is the function this will search the record.
{       //clrscr();
 float user;
 cout<<"Enter Age: ";
 cin>>user;
 file.open("database.txt",ios::in);
 file.read((char*)&obj,sizeof(obj));

 while (file.eof()==0)	//intilize condition
 {
  if (obj.age==user)
  {
   cout<<"Name: "<<obj.name<<endl;
   cout<<"Type: "<<obj.reg<<endl;
   cout<<"Team: "<<obj.team<<endl;
   cout<<"Age: "<<obj.age<<endl<<endl;
  }

  file.read((char*)&obj,sizeof(obj));
 }
 file.close();

 getch();
}

void edit()
{      //clrscr();

 char user[15];
 cout<<"Enter Player Type: ";
 cin>>user;

 file.open("database.txt",ios::in|ios::out);
 file.read((char*)&obj,sizeof(obj));

 while (file.eof()==0)
 {
  if (strcmp(obj.reg,user)==0)
  {
   cout<<"Name: "<<obj.name<<endl;
   cout<<"Type: "<<obj.reg<<endl;
   cout<<"Team: "<<obj.team<<endl;
   cout<<"Age: "<<obj.age<<endl<<endl;

   cout<<"\nEnter New Team: ";
   cin>>obj.team;

   file.seekp(file.tellg()-sizeof(obj));
   file.write((char*)&obj,sizeof(obj));
   cout<<"\n\nFile Updated";
   break;
  }

  file.read((char*)&obj,sizeof(obj));
 }
 file.close();

 getch();
}


int main()		//this is main function
{
	
 //clrscr();

 //file.open("c:\database.txt",ios::out);
 //file.close();
 int option;

 while(1)
 {
  //clrscr();
  cout<<"\t**********	Welcome To Player Record Management System	********\n";
  cout<<"Press 1 to Enter Record\n";
  cout<<"Press 2 to Show All Record\n";
  cout<<"Press 3 to Search Record\n";
  cout<<"Press 4 to Exit\n";
  cout<<"\n\nPress Option: ";
  cin>>option;

  switch (option)
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