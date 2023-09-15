#include<iostream>
#include <istream>
#include<fstream>
#include <stdlib.h>
#include<string.h>

using namespace std;

void login();
void registr();
void forgot();

 main()
{
	int choice;
	cout<<"**********LOGIN**********\n"<<endl;
	cout<<"1.Login"<<endl;
	cout<<"2.Register"<<endl;
	cout<<"3.Forgot credentials"<<endl; 
	cout<<"*Enter Your Choice*"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			login();
			break;
		case 2:
		    registr();
		    break;
		case 3:
		    forgot();
		    break;
		case 4:
		    cout<<"Thanks for using our page"<<endl;
			 break;
		default:
			 cout<<"Sorry wrong choice selected";
			 main();    
			
	}
}
void registr()
{
	string reguser,regpass;
	system("cls");
	cout<<"Enter Username :"<<endl;
	cin>>reguser;
	cout<<"Enter Password :"<<endl;
	cin>>regpass;
	
	ofstream reg("database.txt",ios::app);
	reg<<reguser<<' '<<regpass<<endl;
	system("cls");
	cout<<"Registration is successful"<<endl;
	main();
}
void login()
{
	int exist;
	string user,pass,u,p;
	system("cls");
	cout<<"Enter Username :"<<endl;
	cin>>user;
	cout<<"Enter Password :"<<endl;
	cin>>pass;
	
	ifstream input("database.txt");
	
	while(input>>u>>p)
	{
		if(u == user && p == pass)
		{
			exist = 1;
		}
	}
	input.close();
	if(exist == 1)
	{
		cout<<"Hello " <<user<< "We are glad that you join us"<<endl;
		cin.get();
		cin.get();
		main();
		
	}
	else
	{
		cout<<"Sorry,Login Error."<<endl;
		cin.get();
		cin.get();
		main();
	}
}
void forgot()
{
	int ch;
	system("cls");
	cout<<"Search your accout but username"<<endl;
	cout<<"Serch your accout using passowrd"<<endl;
	cout<<"Enter Prefrence"<<endl;
	cin>>ch;
	
	switch(ch)
	{
		case 1:
		{
			int ex = 0;
			string searchuser,su,sp;
			cout<<"Enter Remember Username :"<<endl;
			cin>>searchuser;
			
			ifstream searchu("database.txt");
			while(searchu>>su>>sp)
			{
				if(su == searchuser)
				{
					ex = 1;
					break;
				}
			}
			searchu.close();
			if(ex == 1)
			{
				cout<<"Hurray ! Your Account has been found"<<endl;
				cout<<"Your Password is "<<sp;
				cin.get();
				cin.get();
				main();
			}
			else
			{
				cout<<"Sorry your Account Has Not Been Found"<<endl;
				cin.get();
				cin.get();
				main(); 
			}
			break;
	}
			case 2:
			{
				int exi = 0;
				string searchpass,su2,sp2;
				cout<<"Enter Your Remember Password : "<<endl;
				cin>>searchpass;
				
				ifstream searchp("database.txt");
				while(searchp>>su2>>sp2)
				{
					if(sp2 == searchpass)
					{
						exi = 1;
					}
					searchp.close();
					if(exi == 1)
					{
						cout<<"Account Has Been Found "<<endl;
						cout<<"YOUR USERNAME IS :"<<su2;
						cout<<"YOUR PASSWORD IS :"<<sp2;
						cin.get();
						main(); 
					}
					break;
				}
			}
			case 3:
			{	
						main();
						break;
		    }
					default:
				{	
					cout<<"Sorry! you have given an invalid option"<<endl;
					cout<<"Press a key to try again"<<endl;
					cin.get();
					cin.get(); 
					forgot();
				}
				}

}


		


