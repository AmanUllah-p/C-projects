#include <iostream>
#include<unistd.h>
#include <conio.h>
using namespace std;
#include "intro.h"
#include "login.h"
intro b;
login l;
char ask;

struct I
{
	string name,ID,date,dep,td,ta,pnr,arrl,desl ;
	int fare;
	I *Ilink;
};

struct D
{
    string name,ID,date,dep,td,ta,pnr,arrl,desl;
	int fare;
	D *Dlink;
};


//---------------------------------------------------         CLASSES   ------------------------------------------------------------------------------------



class DOMESTIC                 //DOMESTIC CLASS 
{
       D *Dhead,*temp;
        
    
		public:
		
	     int  book();
	     int cancel();
	     int tc(string n);
	     void check();
         int display(); 	
         
			 DOMESTIC()
	    {
	    		Dhead=NULL;
		}
	 
};


class international           //INTERNATIONAL CLASS
{
	 I *Ihead,*temp;
		
			public :
		
		 int  book();
	     int cancel();
	     int tc(string n);
	     void check();
	     int display();
	
	   
	 	international()
			{
			Ihead=NULL;
			}   
	 
};
            
			
			//------------------------------------------------------------BOOK TICKET------------------------------------------------------------------
            
            
int DOMESTIC::  book()
{
	temp=NULL;
	temp=new D;
	temp->Dlink=NULL;
		int n,d,a,p;
		cout<<"\n\n\n\t     ********************************** DOMESTIC FLIGHT BOOKING ********************************************\n\n";
		cout<<"\n\t\t\t----------------------AVAILABLE BOOKINGS ARE FROM-----------------------\n\n";
		cout<<"\t\t\t           1) ISLAMABAD \t2) LAHORE \t 3) KARACHI \n\n\n\t\tCHOOSE DEPARTURE CITY -> ";
		n=getch();
		if (n!='1'&&n!='2'&&n!='3')
		{
			cout<<"\n\t\twrong choice \n";
			return 1;
		}
		cout<<"\n\t\tCHOOSE ARRIVAL CITY -> ";
		d=getch();
		 
		if (d!='1'&&d!='2'&&d!='3')
		{
			cout<<"\n\t\twrong choice \n";
			return 1;
		}
		if(n==d)
		{
			cout<<"\n\t\twrong choice \n";
			return 1;
		}
		if((d=='1'&&n=='2')||(d=='2'&&n=='1'))
		{
			cout<<"\n\n\t\t\t\tFLIGHTS ARE \n\n";
			cout<<"\n\t\t\t\tDEPARTURE \t\t    TIME\t\t\tRATE \n";
			cout<<"\n\t\t1) SHAHEEN AIRWAYS \t\t 11:00 AM\t 12:30 PM\t\t10,000\n";
			cout<<"\n\t\t2) QATAR AIRWAYS   \t\t 09::00AM\t 10:30 AM\t\t10,000\n";	
			cout<<"\n\n\t\t\tSELECT AIRPORT : ";a=getch();	
			switch(a)
			{
				 case '1':
				 	{
					 
                cout << "\n\t\tFlight selected : ";
                cout << "SHAHEEN AIRWAYS"<<endl;
                cout<<"\n\t\tPRICE IS 10,000";
                cout<<"\n\t\tPLEASE PAY ";cin>>p;
                if(p<10000)
                {
                	cout<<"\n\t\tTRANSECTION FAILED\n";
                	return 1;
				}
				else if(p>10000)
				cout<<"\n\t\tYPUR REMAINING AMOUNT IS :: "<<p-10000;
				cout<<"\n\t\tNAME -> ";
				cin.ignore();
				getline(cin,temp->name);
				cout<<"\n\t\tENTER ID -> ";
				cin>>temp->ID;
				cout<<"\n\t\tENTER DATE -> ";
				cin>>temp->date;
				cout<<"\n\t\tPNR -> ";
				cin>>temp->pnr;
				if(tc(temp->pnr)==1)
				return 1;
				cout<<"\n\t\tYOUR PNR NUM IS   "<<temp->pnr<<"  PLEASE REMEBER THIS NUM \n";
                temp->fare=p;
                temp->dep="SHAHEEN AIRWAYS";
                cout << "\t\tDeparture Time : 11:00 AM"<<endl;
                cout<<"\t\tArrival Time: 12:30 PM"<<endl;
                temp->td="11:00 AM"; 
                temp->ta="12:30 PM";
                break;
             
            }
          case '2':
                cout << "\n\t\tFlight selected:"<<endl;
                cout << "QATAR AIRWAYS"<<endl;
                cout<<"\n\t\tPRICE IS 10,000";
                cout<<"\n\t\tPLEASE PAY ";cin>>p;
                temp->fare=p;
                if(p<10000)
                {
                	cout<<"\n\t\tTRANSECTION FAILED\n";
                	return 1;
				}
				else if(p>10000)
				cout<<"\n\t\tYPUR REMAINING AMOUNT IS :: "<<p-10000;
				cout<<"\n\t\tNAME -> ";
				cin.ignore();
				getline(cin,temp->name);
					cout<<"\n\t\tENTER ID -> ";
				cin>>temp->ID;
				cout<<"\n\t\tENTER DATE -> ";
				cin>>temp->date;
					cout<<"\n\t\tPNR -> ";
				cin>>temp->pnr;
				if(tc(temp->pnr)==1)
				return 1;
				cout<<"\n\t\tYOUR PNR NUM IS "<<temp->pnr<<"  PLEASE REMEBER THIS NUM \n";
                temp->dep="QATAR AIRWAYS";
                cout << "\t\tDeparture Time : 09:00 AM "<<endl;
                cout<<"\t\tArrival Time: 10:30 AM"<<endl;
                temp->td="09:00 AM";
                temp->ta="10:30 AM";
                break;
                              default :
                	cout<<"\n wrong entry\n";
                	return 1;
	     }
	 }
		  if((d=='1'&&n=='3')||(d=='3'&&n=='1'))
		{
			cout<<"\n\t\t\t\t\tFLIGHTS ARE \n\n";
			cout<<"\n\t\t\t\tDEPARTURE \t\tTIME\t\t\tRATE \n";
			cout<<"\n\t\t1) SHAHEEN AIRWAYS \t\t 08:00 AM\t 12:00 PM\t15,000\n";
			cout<<"\n\t\t2) QATAR AIRWAYS   \t\t 11:00 AM\t 03:00 PM\t15,000\n";			
			cout<<"\n\n\t\tSELECT AIRPORT : ";a=getch();	
			switch(a)
			{
				 case '1':
                cout << "\n\t\tFlight selected : ";
                cout << "SHAHEEN AIRWAYS"<<endl;
                cout<<"\n\t\tPRICE IS 15,000";
                cout<<"\n\t\tPLEASE PAY ";cin>>p;
                if(p<15000)
                {
                	cout<<"\n\t\tTRANSECTION FAILED\n";
                	return 1;
				}
				else if(p>15000)
				cout<<"\n\t\tYPUR REMAINING AMOUNT IS :: "<<p-15000;
				cout<<"\n\t\tNAME -> ";
				cin.ignore();
				getline(cin,temp->name);
					cout<<"\n\t\tENTER ID -> ";
				cin>>temp->ID;
				cout<<"\n\t\tENTER DATE -> ";
				cin>>temp->date;
					cout<<"\n\t\tPNR -> ";
				cin>>temp->pnr;
				if(tc(temp->pnr)==1)
				return 1;
				cout<<"\t\tYOUR PNR NUM IS "<<temp->pnr<<"  PLEASE REMEBER THIS NUM \n";
                temp->fare=p;
                temp->dep="SHAHEEN AIRWAYS";
                cout <<"\t\tDeparture Time : 08:00 AM"<<endl;
                cout<<"\t\tArrival Time: 12:00 PM"<<endl;
                temp->td="08:00 AM"; 
                temp->ta="12:00 PM";
                break;
                         
          case '2':
                cout << "\n\t\tFlight selected : ";
                cout << "QATAR AIRWAYS"<<endl;
                cout<<"\n\t\tPRICE IS 15,000";
                cout<<"\n\t\tPLEASE PAY ";cin>>p;
                temp->fare=p;
                if(p<15000)
                {
                	cout<<"\n\t\tTRANSECTION FAILED\n";
                	return 1;
				}
				else if(p>15000)
				cout<<"\n\t\tYOUR REMAINING AMOUNT IS :: "<<p-15000;
				cout<<"\n\t\tNAME -> ";
				cin.ignore();
				getline(cin,temp->name);
					cout<<"\n\t\tENTER ID -> ";
				cin>>temp->ID;
				cout<<"\n\t\tENTER DATE -> ";
				cin>>temp->date;
					cout<<"\n\t\tPNR -> ";
				cin>>temp->pnr;
				if(tc(temp->pnr)==1)
				return 1;
				cout<<"\n\t\tYOUR PNR NUM IS "<<temp->pnr<<"  PLEASE REMEBER THIS NUM \n";
                temp->dep="QATAR AIRWAYS";
                cout <<"\t\tDeparture Time : 11:00 AM"<<endl;
                cout<<"\t\tArrival Time: 03:00 PM"<<endl;
                temp->td="11:00 AM";
                temp->ta="03:00 PM";
                break;	
                              default :
                	cout<<"\n wrong entry\n";
                	return 1;

		}
	}
		
		 if((d=='2'&&n=='3')||(d=='3'&&n=='2'))
		{
			cout<<"\n\t\t\t\t\tFLIGHTS ARE \n\n";
			cout<<"\n\t\t\t\tDEPARTURE \t\tTIME\t\t\t\tRATE \n";
			cout<<"\n\t\t1) SHAHEEN AIRWAYS \t\t 01:00 PM\t 04:00 PM\t\t13,999\n";
			cout<<"\n\t\t2) QATAR AIRWAYS   \t\t 09:00 AM\t 12:00 PM\t\t13,999\n";			
		    cout<<"\n\n\t\tSELECT AIRPORT : ";a=getch();	
			switch(a)
			{
				  case '1':
                cout <<"\n\t\tFlight selected : ";
                cout <<"SHAHEEN AIRWAYS"<<endl;
                cout<<"\n\t\tPRICE IS 13,999";
                cout<<"\n\t\tPLEASE PAY ";cin>>p;
                if(p<13999)
                {
                	cout<<"\n\t\tTRANSECTION FAILED\n";
                	return 1;
				}
				else if(p>13999)
				cout<<"\n\t\tYPUR REMAINING AMOUNT IS :: "<<p-13999;
				cout<<"\n\t\tNAME -> ";
				cin.ignore();
				getline(cin,temp->name);
					cout<<"\n\t\tENTER ID -> ";
				cin>>temp->ID;
				cout<<"\n\t\tENTER DATE -> ";
				cin>>temp->date;
					cout<<"\n\t\t PNR -> ";
				cin>>temp->pnr;
				if(tc(temp->pnr)==1)
				return 1;
				cout<<"\n\t\tYOUR PNR NUM IS -> "<<temp->pnr<<"<-PLEASE REMEBER THIS NUM \n";
                temp->fare=p;
                temp->dep="SHAHEEN AIRWAYS";
                cout << "\t\tDeparture Time : 01:00 PM"<<endl;
                cout<<"\t\tArrival Time: 04:00 PM"<<endl;
                temp->td="01:00 PM"; 
                temp->ta="09:00 PM";
             
          case '2':
                cout <<"\n\t\tFlight selected : ";
                cout <<"QATAR AIRWAYS"<<endl;
                cout<<"\n\t\tPRICE IS 13,999";
                cout<<"\n\t\tPLEASE PAY ";cin>>p;
                temp->fare=p;
                if(p<13999)
                {
                	cout<<"\n\t\tTRANSECTION FAILED\n";
                	return 1;
				}
				else if(p>13999)
				cout<<"\n\t\tYPUR REMAINING AMOUNT IS :: "<<p-13999;
				cout<<"\n\t\tNAME -> ";
				cin.ignore();
				getline(cin,temp->name);
					cout<<"\n\t\tENTER ID -> ";
				cin>>temp->ID;
				cout<<"\n\t\tENTER DATE -> ";
				cin>>temp->date;
					cout<<"\n\t\tPNR -> ";
				cin>>temp->pnr;
				if(tc(temp->pnr)==1)
				return 1;
				cout<<"\n\t\tYOUR PNR NUM IS  ->"<<temp->pnr<<"<- PLEASE REMEBER THIS NUM \n";
                temp->dep="QATAR AIRWAYS";
                cout << "\t\tDeparture Time : 09:00 AM"<<endl;
                cout<<"\t\tArrival Time: 12:00 PM"<<endl;
                temp->td="09:00 AM";
                temp->ta="12:00 PM";
                break;
                              default :
                	cout<<"\n wrong entry\n";
                	return 1;
            }
			}
        if(Dhead==NULL)
        Dhead=temp;
        else
        {
        	D *t=Dhead;
        	while(t->Dlink!=NULL)
        	t=t->Dlink;
        	t->Dlink=temp;
		}
		cout<<"\n\n\t\tTICKET BOOKED\n";
	
}

    int DOMESTIC::tc(string n)
    {
    		D *t;
		t=Dhead;
			while(t!=NULL)
			{
			if(t->pnr==n)
			{
				cout<<"\n\n\t\tTICKER ALREADY ISSUED\n";
				return 1;
				}
				t=t->Dlink;	
			}
			return 0;
	}
     
     
             // **********************************************FLIGHT CANCLATION********************************************
     int DOMESTIC::cancel()
	{
		cout<<"\n\n\n\t*********************************  DOMESTIC BOOKING CANCELLATION **************************************\n\n";
			D *t,*t1=NULL;
		int found=0;
		float pay;
		string n;
		t=Dhead;
		if(Dhead==NULL)
		{ cout<<"\n\t\tNO TICKET IS ISSUED\n";
		return 1;
	   }
			cout<<"\n\t\tENTER TICKET NUM -> ";
			cin>>n;
			while(t!=NULL)
			{
				
			if(t->pnr==n)
			{
				cout<<"\n\t\tTICKET FOUND ....!\n\n"<<t->pnr;
				cout<<"\n\t\tNAME IS        : "<<t->name;
				cout<<"\n\t\tAIRLINE        : "<<t->dep;
				cout<<"\n\t\tID             : "<<t->ID;
				cout<<"\n\t\tBOOKING DATE   : "<<t->date;
				cout<<"\n\t\tDPEARTURE TIME : "<<t->td;
				cout<<"\n\t\tARRIVAL TIME   : "<<t->ta;
				float f=(t->fare*0.05);
				cout<<"\n\n\t\tTICKET CANCELLING FEE IS 5% "<<f;
				cout<<"\n\t\tPLEASE PAY FULL AMOUNT TO CANCEL THE TOCKET : ";cin>>pay;
				if(pay<f) 
				{
					cout<<"\n\t\tTICKET NOT CANCEL DUE TO INSUFFICENT BALANCE\n\n\t\t\tTHANK  U!!";
					return 1;
				}
				
			        if(pay>f)
					cout<<"\n\t\tYOUR REMAINING AMOUNR IS :: "<<pay-f;
					
	            if(Dhead==t)
				{
					cout<<"\n\t\tTICKET CANCELLED\n";
					Dhead=Dhead->Dlink;
					return 0;
				}
					
						
				     	t1->Dlink=t->Dlink;
				delete t;
				cout<<"\n\t\tTICKET CANCELLED\n";
				found=1;
				break;
					
			}
				t1=t;
				t=t->Dlink;	
				
}
}
	// *********************************************************FLIGHT CHECK*****************************************************************
	void DOMESTIC::check() 
	{
		cout<<"\n\n\n\t********************************* FLIGHT BOOKING STATUS CHECK *****************************************\n\n";
		D *t;
		int found=0;
		string n;
		t=Dhead;
		if(Dhead==NULL)
		cout<<"\n\t\tNO TICKET IS ISSUED\n";
		else
		{
			cout<<"\n\t\tENTER TICKET NUM -> ";
			cin>>n;
			while(t!=NULL)
			{
			if(t->pnr==n)
			{
				cout<<"\n\t\tPNR NUMBER     : "<<t->pnr;
				cout<<"\n\t\tNAME IS        : "<<t->name;
				cout<<"\n\t\tAIRLINE        : "<<t->dep;
				cout<<"\n\t\tID             : "<<t->ID;
				cout<<"\n\t\tBOOKING DATE   : "<<t->date;
				cout<<"\n\t\tDPEARTURE TIME : "<<t->td;
				cout<<"\n\t\tARRIVAL TIME   : "<<t->ta;
				found=1;
				break;
				}
				t=t->Dlink;	
			}
			if(found==0)
			cout<<"\n\t\tNO BOOKING FOUND\n";
		}
	}
	
	int DOMESTIC::display()
	{
			cout<<"\n\n\n\t****************************** DOMESTIC COUSTOMER LIST *****************************************\n\n";
		D *t;
		int found=0,c=0;
		t=Dhead;
		if(Dhead==NULL)
		cout<<"\n\t\tNO TICKET IS ISSUED\n";
		else
		{
			while(t!=NULL)
			{
		        cout<<"\n\t\t\t\tCOUSTOMER -> "<<c+1<<" <- ";
				cout<<"\n\t\tPNR NUMBER     : "<<t->pnr;
				cout<<"\n\t\tNAME IS        : "<<t->name;
				cout<<"\n\t\tAIRLINE        : "<<t->dep;
				cout<<"\n\t\tID             : "<<t->ID;
				cout<<"\n\t\tBOOKING DATE   : "<<t->date;
				cout<<"\n\t\tDPEARTURE TIME : "<<t->td;
				cout<<"\n\t\tARRIVAL TIME   : "<<t->ta;
				found=1;
				t=t->Dlink;	
			}
			if(found==0)
			cout<<"\n\t\tNO BOOKING FOUND\n";
		}
		
	}
	//******************************************************INTERNATIONAl TICKET BOOK************************************************
	
	
	int international::  book()
{
	temp=NULL;
	temp=new I;
	temp->Ilink=NULL;
		int n,d,a,p;
		cout<<"\n\n\n\t     ******************************* INTERNATIONAL FLIGHT BOOKING ***************************************\n\n";
		cout<<"\n\t\t\t----------------------AVAILABLE BOOKINGS ARE FROM-----------------------\n\n";
		cout<<"\t\t\t           1) LONDON \t2) NEWYORK \t 3) PARIS \n\n\n\t\tCHOOSE DEPARTURE CITY -> ";
		n=getch();
		if (n!='1'&&n!='2'&&n!='3')
		{
			cout<<"\n\t\twrong choice \n";
			return 1;
		}
		cout<<"\n\t\tCHOOSE ARRIVAL CITY -> ";
		d=getch();
		 
		if (d!='1'&&d!='2'&&d!='3')
		{
			cout<<"\n\t\twrong choice \n";
			return 1;
		}
		if(n==d)
		{
			cout<<"\n\t\twrong choice \n";
			return 1;
		}
		if((d=='1'&&n=='2')||(d=='2'&&n=='1'))
		{
			cout<<"\n\n\t\t\t\tFLIGHTS ARE \n\n";
			cout<<"\n\t\t\t\tDEPARTURE \t\t    TIME\t\t\tRATE \n";
			cout<<"\n\t\t1) SHAHEEN AIRWAYS \t\t 03:00 AM\t 12:30 PM\t\t500 £\n";
			cout<<"\n\t\t2) QATAR AIRWAYS   \t\t 05:00 AM\t 02:30 PM\t\t520 £\n";	
			cout<<"\n\n\t\t\tSELECT AIRPORT : ";a=getch();	
			switch(a)
			{
				 case '1':
				 	{
					 
                cout << "\n\t\tFlight selected : ";
                cout << "SHAHEEN AIRWAYS"<<endl;
                cout<<"\n\t\tPRICE IS 500 £";
                cout<<"\n\t\tPLEASE PAY ";cin>>p;
                if(p<500)
                {
                	cout<<"\n\t\tTRANSECTION FAILED\n";
                	return 1;
				}
				else if(p>500)
				cin.ignore();
				cout<<"\n\t\tYPUR REMAINING AMOUNT IS :: "<<p-500;
				cout<<"\n\t\tNAME -> ";
				
				getline(cin,temp->name);
				cout<<"\n\t\tENTER ID -> ";
				cin>>temp->ID;
				cout<<"\n\t\tENTER DATE -> ";
				cin>>temp->date;
				cout<<"\n\t\tPNR -> ";
				cin>>temp->pnr;
				if(tc(temp->pnr)==1)
				return 1;
				cout<<"\n\t\tYOUR PNR NUM IS   "<<temp->pnr<<"  PLEASE REMEBER THIS NUM \n";
                temp->fare=p;
                temp->dep="SHAHEEN AIRWAYS";
                cout << "\t\tDeparture Time : 03:00 AM"<<endl;
                cout<<"\t\tArrival Time: 12:30 PM"<<endl;
                temp->td="03:00 AM"; 
                temp->ta="12:30 PM";
                break;
            }
          case '2':
                cout << "\n\t\tFlight selected:"<<endl;
                cout << "QATAR AIRWAYS"<<endl;
                cout<<"\n\t\tPRICE IS 520 £";
                cout<<"\n\t\tPLEASE PAY ";cin>>p;
                temp->fare=p;
                if(p<520)
                {
                	cout<<"\n\t\tTRANSECTION FAILED\n";
                	return 1;
				}
				else if(p>520)
				cout<<"\n\t\tYPUR REMAINING AMOUNT IS :: "<<p-520;
				cout<<"\n\t\tNAME -> ";
				cin.ignore();
				getline(cin,temp->name);
					cout<<"\n\t\tENTER ID -> ";
				cin>>temp->ID;
				cout<<"\n\t\tENTER DATE -> ";
				cin>>temp->date;
					cout<<"\n\t\tPNR -> ";
				cin>>temp->pnr;
				if(tc(temp->pnr)==1)
				return 1;
				cout<<"\n\t\tYOUR PNR NUM IS "<<temp->pnr<<"  PLEASE REMEBER THIS NUM \n";
                temp->dep="QATAR AIRWAYS";
                cout << "\t\tDeparture Time : 05:00 AM"<<endl;
                cout<<"\t\tArrival Time: 02:30 PM"<<endl;
                temp->td="05:00 AM";
                temp->ta="02:30 PM";
                break;
                              default :
                	cout<<"\n wrong entry\n";
                	return 1;
	     }
	 }
		  if((d=='1'&&n=='3')||(d=='3'&&n=='1'))
		{
			cout<<"\n\t\t\t\t\tFLIGHTS ARE \n\n";
			cout<<"\n\t\t\t\tDEPARTURE \t\tTIME\t\t\tRATE \n";
			cout<<"\n\t\t1) SHAHEEN AIRWAYS \t\t 08:00 AM\t 12:00 PM\t670 £\n";
			cout<<"\n\t\t2) QATAR AIRWAYS   \t\t 01:00 AM\t 06:00 AM\t685 £\n";			
			cout<<"\n\n\t\tSELECT AIRPORT : ";a=getch();	
			switch(a)
			{
				 case '1':
                cout << "\n\t\tFlight selected : ";
                cout << "SHAHEEN AIRWAYS"<<endl;
                cout<<"\n\t\tPRICE IS 670 £";
                cout<<"\n\t\tPLEASE PAY ";cin>>p;
                if(p<670)
                {
                	cout<<"\n\t\tTRANSECTION FAILED\n";
                	return 1;
				}
				else if(p>670)
				cout<<"\n\t\tYPUR REMAINING AMOUNT IS :: "<<p-670;
				cout<<"\n\t\tNAME -> ";
				cin.ignore();
				getline(cin,temp->name);
					cout<<"\n\t\tENTER ID -> ";
				cin>>temp->ID;
				cout<<"\n\t\tENTER DATE -> ";
				cin>>temp->date;
					cout<<"\n\t\tPNR -> ";
				cin>>temp->pnr;
				if(tc(temp->pnr)==1)
				return 1;
				cout<<"\t\tYOUR PNR NUM IS "<<temp->pnr<<"  PLEASE REMEBER THIS NUM \n";
                temp->fare=p;
                temp->dep="SHAHEEN AIRWAYS";
                cout <<"\t\tDeparture Time : 08:00 AM"<<endl;
                cout<<"\t\tArrival Time: 12:00 AM"<<endl;
                temp->td="08:00 AM"; 
                temp->ta="12:00 PM";
                break;
          case '2':
                cout << "\n\t\tFlight selected : ";
                cout << "QATAR AIRWAYS"<<endl;
                cout<<"\n\t\tPRICE IS 685 670 £";
                cout<<"\n\t\tPLEASE PAY ";cin>>p;
                temp->fare=p;
                if(p<685)
                {
                	cout<<"\n\t\tTRANSECTION FAILED\n";
                	return 1;
				}
				else if(p>685)
				cout<<"\n\t\tYOUR REMAINING AMOUNT IS :: "<<p-685;
				cout<<"\n\t\tNAME -> ";
				cin.ignore();
				getline(cin,temp->name);
					cout<<"\n\t\tENTER ID -> ";
				cin>>temp->ID;
				cout<<"\n\t\tENTER DATE -> ";
				cin>>temp->date;
					cout<<"\n\t\tPNR -> ";
				cin>>temp->pnr;
				if(tc(temp->pnr)==1)
				return 1;
				cout<<"\n\t\tYOUR PNR NUM IS "<<temp->pnr<<"  PLEASE REMEBER THIS NUM \n";
                temp->dep="QATAR AIRWAYS";
                cout <<"\t\tDeparture Time : 01:00 AM"<<endl;
                cout<<"\t\tArrival Time: 06:00 AM"<<endl;
                temp->td="01:00 AM";
                temp->ta="06:00 AM";
                break;	
                              default :
                	cout<<"\n wrong entry\n";
                	return 1;
		}
	}
		
		 if((d=='2'&&n=='3')||(d=='3'&&n=='2'))
		{
			cout<<"\n\t\t\t\t\tFLIGHTS ARE \n\n";
			cout<<"\n\t\t\t\tDEPARTURE \t\tTIME\t\t\t\tRATE \n";
			cout<<"\n\t\t1) SHAHEEN AIRWAYS \t\t 01:00 PM\t 07:00 PM\t\t 750 £\n";
			cout<<"\n\t\t2) QATAR AIRWAYS   \t\t 09:00 AM\t 03:00 PM\t\t 800 £\n";			
		    cout<<"\n\n\t\tSELECT AIRPORT : ";a=getch();	
			switch(a)
			{
				  case '1':
                cout <<"\n\t\tFlight selected : ";
                cout <<"SHAHEEN AIRWAYS"<<endl;
                cout<<"\n\t\tPRICE IS 750 £";
                cout<<"\n\t\tPLEASE PAY ";cin>>p;
                if(p< 750)
                {
                	cout<<"\n\t\tTRANSECTION FAILED\n";
                	return 1;
				}
				else if(p>750)
				cout<<"\n\t\tYPUR REMAINING AMOUNT IS :: "<<p-750;
				cout<<"\n\t\tNAME -> ";
				cin.ignore();
				getline(cin,temp->name);
					cout<<"\n\t\tENTER ID -> ";
				cin>>temp->ID;
				cout<<"\n\t\tENTER DATE -> ";
				cin>>temp->date;
					cout<<"\n\t\t PNR -> ";
				cin>>temp->pnr;
				if(tc(temp->pnr)==1)
				return 1;
				cout<<"\n\t\tYOUR PNR NUM IS -> "<<temp->pnr<<"<-PLEASE REMEBER THIS NUM \n";
                temp->fare=p;
                temp->dep="SHAHEEN AIRWAYS";
                cout << "\t\tDeparture Time : 01:00 PM"<<endl;
                cout<<"\t\tArrival Time: 07:00 PM"<<endl;
                temp->td="01:00 PM"; 
                temp->ta="07:00 PM";
                break;
          case '2':
                cout <<"\n\t\tFlight selected : ";
                cout <<"QATAR AIRWAYS"<<endl;
                cout<<"\n\t\tPRICE IS 800 £";
                cout<<"\n\t\tPLEASE PAY ";cin>>p;
                temp->fare=p;
                if(p<800)
                {
                	cout<<"\n\t\tTRANSECTION FAILED\n";
                	return 1;
				}
				else if(p>800)
				cout<<"\n\t\tYPUR REMAINING AMOUNT IS :: "<<p-800;
				cout<<"\n\t\tNAME -> ";
				cin.ignore();
				getline(cin,temp->name);
					cout<<"\n\t\tENTER ID -> ";
				cin>>temp->ID;
				cout<<"\n\t\tENTER DATE -> ";
				cin>>temp->date;
					cout<<"\n\t\tPNR -> ";
				cin>>temp->pnr;
				if(tc(temp->pnr)==1)
				return 1;
				cout<<"\n\t\tYOUR PNR NUM IS  ->"<<temp->pnr<<"<- PLEASE REMEBER THIS NUM \n";
                temp->dep="QATAR AIRWAYS";
                cout << "\t\tDeparture Time : 09:00 AM"<<endl;
                cout<<"\t\tArrival Time: 03:00 PM"<<endl;
                temp->td="09:00 AM";
                temp->ta="12:00 PM";
                break;
                              default :
                	cout<<"\n wrong entry\n";
                	return 1;
            }
			}
        if(Ihead==NULL)
        Ihead=temp;
        else
        {
        	I *t=Ihead;
        	while(t->Ilink!=NULL)
        	t=t->Ilink;
        	t->Ilink=temp;
		}
		cout<<"\n\n\t\tTICKET BOOKED\n";
	
}

	int international::cancel()
	{  
	     cout<<"\n\n\n\t********************************** FLIGHT BOOKING CANCELLATION ***************************************\n\n";
			I *t,*t1=NULL;
		int found=0;
		float pay;
		string n;
		t=Ihead;
		if(Ihead==NULL)
		{ cout<<"\n\t\tNO TICKET IS ISSUED\n";
		return 1;
	   }
			cout<<"\n\t\tENTER TICKET NUM -> ";
			cin>>n;
			while(t!=NULL)
			{
				
			if(t->pnr==n)
			{
				cout<<"\n\t\tTICKET FOUND ....!\n\n"<<t->pnr;
				cout<<"\n\t\tNAME IS        : "<<t->name;
				cout<<"\n\t\tAIRLINE        : "<<t->dep;
				cout<<"\n\t\tID             : "<<t->ID;
				cout<<"\n\t\tBOOKING DATE   : "<<t->date;
				cout<<"\n\t\tDPEARTURE TIME : "<<t->td;
				cout<<"\n\t\tARRIVAL TIME   : "<<t->ta;
				float f=(t->fare*0.05);
				cout<<"\n\n\t\tTICKET CANCELLING FEE IS 5% "<<f;
				cout<<"\n\t\tPLEASE PAY FULL AMOUNT TO CANCEL THE TOCKET : ";cin>>pay;
				if(pay<f) 
				{
					cout<<"\n\t\tTICKET NOT CANCEL DUE TO INSUFFICENT BALANCE\n\n\t\t\tTHANK  U!!";
					return 1;
				}
				
			        if(pay>f)
					cout<<"\n\t\tYOUR REMAINING AMOUNR IS :: "<<pay-f;
						if(Ihead==t)
				{
					cout<<"\n\t\tTICKET CANCELLED\n";
					Ihead=Ihead->Ilink;
					return 1;
				}
				     	t1->Ilink=t->Ilink;
				delete t;
				cout<<"\n\t\tTICKET CANCELLED\n";
				found=1;
				break;
					
			}
				t1=t;
				t=t->Ilink;	
				
}
              if(found==0)cout<<"\n\t\tNO TICKET IS ISSUED\n";
}	

	
	
	void international::check()
	{
		cout<<"\n\n\n\t****************************** INTERNATIONAL BOOKING STATUS CHECK ***************************************\n\n";
		I *t;
		int found=0;
		string n;
		t=Ihead;
		if(Ihead==NULL)
		cout<<"\n\t\tNO TICKET IS ISSUED\n";
		else
		{
			cout<<"\n\t\tENTER TICKET NUM -> ";
			cin>>n;
			while(t!=NULL)
			{
			if(t->pnr==n)
			{
				cout<<"\n\t\tPNR NUMBER     : "<<t->pnr;
				cout<<"\n\t\tNAME IS        : "<<t->name;
				cout<<"\n\t\tAIRLINE        : "<<t->dep;
				cout<<"\n\t\tID             : "<<t->ID;
				cout<<"\n\t\tBOOKING DATE   : "<<t->date;
				cout<<"\n\t\tDPEARTURE TIME : "<<t->td;
				cout<<"\n\t\tARRIVAL TIME   : "<<t->ta;
				found=1;
				break;
				}
				t=t->Ilink;	
			}
			if(found==0)
			cout<<"\n\t\tNO BOOKING FOUND\n";
		}
	}
	
	int international::tc(string n)
	{
	   	I *t;
		t=Ihead;
			while(t!=NULL)
			{
			if(t->pnr==n)
			{
				cout<<"\n\n\t\tTICKER ALREADY ISSUED\n";
				return 1;
				}
				t=t->Ilink;	
			}
			return 0;	
	}
	 
	int international::display()
	{
			cout<<"\n\n\n\t  ******************************International COUSTOMER LIST **************************************\n\n";
		I *t;
		int found=0,c=0;
		t=Ihead;
		if(Ihead==NULL)
		cout<<"\n\t\tNO TICKET IS ISSUED\n";
		else
		{
			while(t!=NULL)
			{
		        cout<<"\n\t\t\t\tCOUSTOMER -> "<<c+1<<" <- ";
				cout<<"\n\t\tPNR NUMBER     : "<<t->pnr;
				cout<<"\n\t\tNAME IS        : "<<t->name;
				cout<<"\n\t\tAIRLINE        : "<<t->dep;
				cout<<"\n\t\tID             : "<<t->ID;
				cout<<"\n\t\tBOOKING DATE   : "<<t->date;
				cout<<"\n\t\tDPEARTURE TIME : "<<t->td;
				cout<<"\n\t\tARRIVAL TIME   : "<<t->ta;
				found=1;
				t=t->Ilink;	
			}
			if(found==0)
			cout<<"\n\t\tNO BOOKING FOUND\n";
		}
	}
/**********************************************************CLASSES ENDS  HERE *************************************************/



int main()
{
 
        l.get();
        b.intr1();

	DOMESTIC d;international i;
	
	for(;;)
	{                        
	cout<<"\n\n\n\n\t\t\t\t         ************************ \n";
	cout<<"\t\t\t\t         Fligh Reservation System   \n";
	cout<<"\t\t\t\t         ************************\n\n\n";
	cout<<"\t\t1 : BOOK FLIGHT  \n";
	cout<<"\t\t2 : CANCEL FLIGHT \n";
	cout<<"\t\t3 : FLIGHT STATUS\n";
	cout<<"\t\t4 : LIST OF FLIGHTS BOOKED\n";
	cout<<"\t\t5 : EXIT \n";
	cout<<"\n\n\t\tOPTION   ->  ";
	ask=getch();
 	switch(ask)
	{
		case '1' :
			
				cout<<"\n\t\t1 : DOMESTIC \t\t\t2 : INTERNATIONAL \n\n\t\tOPTION -> ";
				ask=getch();
				switch(ask)
				{
					case '1':
						system("cls");
				        d.book();		
				        getch();
				        system("cls");
						break;
						case '2':
							system("cls");
							i.book();
							getch();
							system("cls");
							break;
							default:
								cout<<"\n\t\tinvalid option\n";
				}
			
			break;
			case '2' :
				
						cout<<"\n\t\t1 : DOMESTIC \t\t\t2 : INTERNATIONAL \n\n\t\tOPTION -> ";
				ask=getch();
				switch(ask)
				{
					case '1':
						system("cls");
						d.cancel();
						getch();
						system("cls");
						break;
						case '2':
						    system("cls");
							i.cancel();
							getch();
							system("cls");
							break;
							default:
								cout<<"\n\t\tinvalid option\n";
				}
			  
				break;
				case '3':
					
					
						cout<<"\n\t\t1 : DOMESTIC \t\t\t2 : INTERNATIONAL \n\n\t\tOPTION -> ";
			    	    ask=getch();
				        switch(ask)
				         {
					      case '1':
					      	system("cls");
					      	d.check();
					      	getch();
					      	system("cls");
					          break;
						      case '2':
						      	system("cls");
						      	i.check();
						      	getch();
						      	system("cls");
							      break;
							      default:
								      cout<<"\n\t\tinvalid option\n";
				             }
				    
					break;
					      case '4': 
					      	cout<<"\n\t\t1 : DOMESTIC \t\t\t2 : INTERNATIONAL \n\n\t\tOPTION -> ";
			    	    ask=getch();
				        switch(ask)
				         {
					      case '1':
					      	system("cls");
					      	d.display();
					      	getch();
					      	system("cls");
					          break;
						      case '2':
						      	system("cls");
						      	i.display();
						      	getch();
						      	system("cls");
							      break;
							      default:
								      cout<<"\n\t\tinvalid option\n";
								  }
								  break;
					case '5':
						system("Cls");
						cout<<"\n\n\n\n\n\n\n\n\t\t\t\tSPECIAL THANKS TO : ";sleep(1);cout<<"  -> MAM SUMMIYA <-\n\n";
						getch();
						exit(0);
						default :
							cout<<"\n\t\tinvalid option \n";
	}
   }
}
