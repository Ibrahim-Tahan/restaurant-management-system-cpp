#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

struct meal
{
	string burger;
	string side_meal;
	string drink;
	int price;
}
;

int count=0;
int number()
{
	count--;
	return count;
}

double currencyConv(int value, char to)
{
	double result;
		if(to=='$')
		{
			result=value/1496.11;
		}
		else if(to=='E')
		{
			result=value/1816.77;
		}
		else if(to=='P')
		{
			result=value/2104.68;
		}
		else
		{	
	    	cout<<"invalid conversion";
        }	
}

int RDG()
{
    srand((unsigned) time(0));
    int randomNumber;
    for (int index=0; index<1; index++) 
	{
        randomNumber= (rand()%10)+1;
        return randomNumber;
    }
}

int main()
{    
	fstream newfile;
	fstream file;
	
	ifstream mypass;
	mypass.open("Pass.txt",ios::in);
	string Pass;
	if(mypass.is_open())
	{
		while(getline(mypass,Pass))
		mypass.close();   
    }	
    
cout<<"To log in as user press 1\nTo log in as Admin press 0\n\n";//______________LOGIN

int Entry;
cout<<"How are you logging in??\nPlease enter a number: ";
cin >> Entry;

while (Entry <0 || Entry >1)
	{
		cout<<"RE-ENTER A NUMBER: ";
		cin>>Entry;
	}
	
	cout<<"\n\n";
	
        if(Entry==0)//__________________________________________________________ADMIN MODE
	{
        cout<<"Enter your Password to modify the meals: ";    
		string A;
	    cin>>A;

        while (A!=Pass)
    		{
				cout<<"Please re-enter your password: ";
				cin>>A;
			}  	    

			int Nmax;// Max nbr of meals
			cout<<"\nDear admin, enter the total number of meals in the menu: ";
            cin>>Nmax;
            Nmax+=1;
	    	meal M1 [Nmax];
	
            file.open("Prices.txt",ios::out);
			newfile.open ("McDonalds.txt",ios::out);
			
				for(int i=1 ; i<Nmax ; i++)
			{
		        cout<<"\nmeal Num: ";
		        cin>>i;
	            cout<<"main meal: ";
	            cin>>M1[i].burger;
	            cout<<"side meal: ";
	            cin>>M1[i].side_meal;
	            cout<<"drink: ";
	            cin>>M1[i].drink;
	            cout<<"Price: ";
	            cin>>M1[i].price;    
	            
            	newfile<<i<<":"<<M1[i].burger<<","<<M1[i].side_meal<<","<<M1[i].drink<<","<<M1[i].price<<"LBP.\n";
      
	        	file<<"\n";  
	        	file<<M1[i].price;  
			}
		
	    newfile.close();
		file.close();		
	}
	else if(Entry==1)//_________________________________________________________USER MODE
	{
		string list;
		newfile.open("McDonalds.txt",ios::in);
	
		if (!newfile)
	{
	    cout<<"Could not open file.\n";
        return 0;
    }
	while(!newfile.eof())
		{
			getline(newfile,list);
			cout<<list<<endl;//Display menu
		    count++;		
		}
	newfile.close();
	
	int nbrL=number();//number():number of lines in menu->number of meal
	nbrL+=1;//nbrL -> Number of line
	
	string input[nbrL];
	file.open("Prices.txt",ios::in);
    
	while (getline(file,*input))
	{
		for(int j=1; j<nbrL;j++)
		file>>input[j];//list of prices
	}
	
	int choice;
	int price=0;
	int Tprice=0;
	
	int answer;	
		do{
		cout<<"Enter the number of meal of your choice: ";
        cin>>choice;
    	stringstream degree(input[choice]);
	    degree>>price;// switch string to integer
	    
		while(choice<1 || choice>nbrL)
		{
			cout<<"Please re-enter your order: ";
			cin>>choice;
		}
		{
			Tprice+=price;		
			cout<<"The total price is: " <<Tprice<<"LBP\n";			
		}
		
		cout<<"\nWould you like to add anything else? press 1 to add to your order or press 0 to finish\n";
		cin>>answer;
		while (answer<0 || answer>1)
		{
			cout<<"Please Confirm. ";
			cin>>answer;
		}
	}
	while (answer==1);
	
	cout<<"\nIf your total reaches 300000 LBP we offer you a 10% discount on the full price\n";
	
	int total=Tprice;
	
	if(Tprice>300000)
	{
		int disc=0;
		disc=Tprice*0.1;
		total=Tprice-disc;
	}

    cout<<"\nThe full price is: "<<total<<"LBP\n"
	<<"If you want you can try your luck an guess a number between 1->10 for 10000LBP.\n"
	<<"If you are lucky you will get your order free of charge "
	<<"\nIf intrested press 1, If not press 0\n";
	int c;
	cin>>c;
	
	if (c==1)
		{
			int d=RDG();
			int e;
			total=total+10000;
			cout<<"Enter your lucky number(between 1->10): ";
			cin>>e;
			while(e<0 || e>10)
			{
				cout<<"Enter a number between 1->10: ";
				cin>>e;
			}
			if(e==d)
			{
				cout<<"CONGRATS YOUR ORDER IS FREE OF CHARGE";
				total=0;
				cout<<d;
			}
			else if(e!=d)
			{
				cout<<"Hard luck.";
				cout<<"\nThe number was :"<<d;
			}
		}
		
		cout<<"\nCheckout :"<<total<<"LBP";
	
	cout<<"\nYou can pay in LBP, $(dollar), E(euro) and P(pound)\nIf you want to convert to another currency press 1 if not press 0: ";
	int b;
	cin>>b;
	while (b<0 || b>1)
	{
		cout<<"Please confirm. ";
		cin>>b;
	}
	if(b==1)
	{
		char out;
		cout<<"enter the currency you want to convert to: "<<endl;
		cin>>out;
		cout<<"your Total is "<<out<<" "<<currencyConv(total,out);
	}
	
	cout<<"\nThank you for your visit!!";

}
  return 0;
}
