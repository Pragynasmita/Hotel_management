#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

class customer
{
	int cid,stay,tramt;
	float tfamt,tevamt,gtotal;
	char cn[20],dob[15],g[10],id[25],cno[15],eid[20],nty[20],cd[15],cit[15],cod[15],cot[15];
	public:
		void info();
		void add();
		void search();
		void display();
		void modify();
		void room();
		void food();
		void event();
		void bill();
		void del();
}c;

void customer::add()
{
	system("cls");
	cout<<"====================ADD CUSTOMER RECORD====================\n\n";
	ofstream ofs("Hotel.txt",ios::app); //to write the info in the database file
	cout<<"1- Enter Customer ID : ";
	cin>>cid;
	cout<<"\n2- Enter Customer Name : ";
	fflush(stdin);
	gets(cn);
	cout<<"\n3- Enter Date of Birth : ";
	gets(dob);
	cout<<"\n4- Enter Gender : ";
	gets(g);
	cout<<"\n5- Enter Identification Proof(Adhaar/Voter ID/Pan card) : ";
	gets(id);
	cout<<"\n6- Enter Contact Number : ";
	fflush(stdin);
	gets(cno);
	cout<<"\n7- Enter Emai-Id : ";
	gets(eid);
	cout<<"\n8- Enter Nationality : ";
	gets(nty);
	cout<<"\n9- Enter Check-in Date : ";
	gets(cd);
	cout<<"\n10- Enter Check-in Time : ";
	gets(cit);
	cout<<"\n11- Enter Check-out Date : ";
	gets(cod);
	cout<<"\n12- Enter Check-out Time : ";
	gets(cot);
	ofs.write((char*)&c,sizeof(customer));
	cout<<"\n\nRecord Added Succesfully!!!";
	ofs.close();	
}

void customer::search()
{
	int cid1,flag=0;
	system("cls");
	cout<<"=======================SEARCH SECTION RECORD==================\n\n";
	ifstream ifs("hotel.txt");     //to read the info from the database file
	if(!ifs)
	{
		cout<<"\nFile not found :(";
		getch();
		exit(0);
	}
	cout<<"\nEnter Customer Id to Search : ";
	cin>>cid1;
	while(ifs.read((char*)&c,sizeof(customer)))
	{
		if(cid1==cid)
		{
			flag=1;
			cout<<"\nCustomer ID : "<<cid;
			cout<<"\nCustomer Name : "<<cn;
			cout<<"\nDate of Birth : "<<dob;
			cout<<"\nGender : "<<g;
			cout<<"\nIdentification Proof(Adhaar/Voter ID/Pan card) : "<<id;
			cout<<"\nContact Number : "<<cno;
			cout<<"\nEmail-ID : "<<eid;
			cout<<"\nNationality : "<<nty;
			cout<<"\nCheck-in Date : "<<cd;
			cout<<"\nCheck-in Time : "<<cit;
			cout<<"\nCheck-out Date : "<<cod;
			cout<<"\nCheck-out Time : "<<cot;
		}
	}
	if(flag==0)
	{
		cout<<"\nCustomer ID not found :("<<endl;
	}
	ifs.close();
}

void customer::display()
{
	system("cls");
	cout<<"========================DISPLAY ALL RECORDS SECTION===================\n\n";
	ifstream ifs("hotel.txt");
	if(!ifs)
	{
		cout<<"\nFile not found :(";
		getch();
		exit(0);
	}
	while(ifs.read((char*)&c,sizeof(customer)))
	{
		cout<<"\n------------------------------------------------------";
		cout<<"\nCustomer ID : "<<cid;
		cout<<"\nCustomer Name : "<<cn;
		cout<<"\nDate of Birth : "<<dob;
		cout<<"\nGender : "<<g;
		cout<<"\nIdentification Proof(Adhaar/Voter ID/Pan card) : "<<id;
		cout<<"\nContact Number : "<<cno;
		cout<<"\nEmail-ID : "<<eid;
		cout<<"\nNationality : "<<nty;
		cout<<"\nCheck-in Date : "<<cd;
		cout<<"\nCheck-in Time : "<<cit;
		cout<<"\nCheck-out Date : "<<cod;
		cout<<"\nCheck-out Time : "<<cot;
		if(tramt==0)
		{
			cout<<"\nRooms not alloted:";
		}
		else
		{
		cout<<"\nExpenditure on Rooms = "<<tramt;
	    }
	    if(tfamt==0)
	    {
	    	cout<<"\nFood Items not ordered";
		}
		else
		{
		cout<<"\nExpenditure on Food = "<<tfamt;
	    }
	    if(tevamt==0)
	    {
	    	cout<<"\nEvents not booked";
		}
		else
		{
		cout<<"\nExpenditure on Events = "<<tevamt;
	    }
	    if(gtotal==0)
	    {
	    	cout<<"\nBill not calculated:";
		}
		else
		{
		cout<<"\n\nGrand Total = "<<gtotal;
	    }
		getch();
	}
	ifs.close();
}

void customer::modify()
{
	system("cls");
	int cid2,ch1,flag=0;
	cout<<"=====================MODIFY RECORD SECTION===================\n\n";
	ofstream ofs("temp.txt");
	ifstream ifs("hotel.txt");
	if(!ifs)
	{
		cout<<"File not found :("<<endl;
		getch();
		exit(0);
	}
	cout<<"\nEnter Customer ID to be modified : ";
	cin>>cid2;
	while(ifs.read((char*)&c,sizeof(customer)))
	{
		if(cid2==cid)
		{
			flag=1;
			cout<<"\nCustomer Name : "<<cn<<endl;
			cout<<"\nChoose the option to be modified:";
		    cout<<"\n1- Customer Name:";
		    cout<<"\n2- Date of Birth:";
		    cout<<"\n3- Gender:";
		    cout<<"\n4- Identification Proof(Adhaar/Voter ID/Pan card):";
		    cout<<"\n5- Contact Number:";
		    cout<<"\n6- Email-ID:";
		    cout<<"\n7- Nationality:";
		    cout<<"\n8- Check-in Date:";
		    cout<<"\n9- Check-in Time:";
		    cout<<"\n10- Check-out Date:";
		    cout<<"\n11- Check-out Time:";
		    cout<<"\n\nEnter Your Choice(1-11) : ";
		    cin>>ch1;
		    fflush(stdin);
		    switch(ch1)
		    {
		    	case 1:
		    		cout<<"\nEnter Customer Name : ";
		    		gets(cn);
		    		break;
		    	case 2:
		    		cout<<"\nEnter Date of Birth : ";
	                gets(dob);
	                break;
		    	case 3:
		    		cout<<"\nEnter Gender : ";
		    		gets(g);
		    		break;
		    	case 4:
		    		cout<<"\nEnter Identification Proof(Adhaar/Voter ID/Pan card) : ";
		    		gets(id);
		    		break;
		    	case 5:
		    		cout<<"\nEnter Contact Number : ";
		    		gets(cno);
		    		break;
		    	case 6:
		    		cout<<"\nEnter Email-Id : ";
		    		gets(eid);
		    		break;
		    	case 7:
		    		cout<<"\nEnter Nationality : ";
		    		gets(nty);
		    		break;
		    	case 8:
		    		cout<<"\nEnter Check-in Date : ";
		    		gets(cd);
		    		break;
		    	case 9:
		    		cout<<"\nEnter Check-in Time : ";
		    		gets(cit);
		    		break;
		    	case 10:
		    		cout<<"\nEnter Check-out Date : ";
		    		gets(cod);
		    		break;
		    	case 11:
		    		cout<<"\nEnter Check-out Time : ";
		    		gets(cot);
		    		break;
		    	default:
		    		cout<<"\nIvalid Choice :("<<endl;
			}
			ofs.write((char*)&c,sizeof(customer));
			cout<<"\nData Modified Successfully :)";
		}
		else
		{
			ofs.write((char*)&c,sizeof(customer));
		}
	}
	if(flag==0)
	{
		cout<<"\nCustomer ID not found :("<<endl;
	}
	ofs.close();
	ifs.close();
	remove("hotel.txt");
	rename("temp.txt","hotel.txt");
}

void customer::room()
{
	int ramt1=0,ramt2=0,ramt3=0,ramt4=0,ramt5=0,no,rm,cid3,flag=0;
	char more;
	system("cls");
	cout<<"====================ROOM PREFERENCE SECTION====================\n\n";
	ofstream ofs("temp.txt");
	ifstream ifs("hotel.txt");
	if(!ifs)
	{
		cout<<"File not found :("<<endl;
		getch();
		exit(0);
	}
	cout<<"\nEnter Customer ID to add rooms : ";
	cin>>cid3;
	while(ifs.read((char*)&c,sizeof(customer)))
	{
	if(cid3==cid)
	{
		flag=1;
		cout<<"\nCustomer Name: "<<cn<<endl;
		cout<<"\nSL. NO.\t\tCHOOSE YOUR ROOM PREFERENCE\tCHARGES PER DAY";
		cout<<"\nType1-\t\tSuper Deluxe Premium\t\tRs.4500/day";
		cout<<"\nType2-\t\tDeluxe\t\t\t\tRs.4000/day";
		cout<<"\nType3-\t\tA/C\t\t\t\tRs.3500/day";
		cout<<"\nType4-\t\tNon-A/C\t\t\t\tRs.3000/day";
		cout<<"\nType5-\t\tStandard\t\t\tRs.2500/day";
		cout<<"\n-----------------------------------";
	    do
	    {
		    cout<<"\nEnter your Room Preference(1-5) : ";
		    cin>>rm;
		    fflush(stdin);
		    switch(rm)
		    {
			    case 1:
				    cout<<"\nType1- Super Deluxe Premium = Rs.4500/Day";
				    cout<<"\nEnter Total no. of rooms to be taken : ";
				    cin>>no;
				    cout<<"\nEnter no. of days to stay = ";
				    cin>>stay;
				    ramt1=4500*no*stay;
				    cout<<"\nTotal Amount = "<<ramt1;
				    tramt+=ramt1;
				    break;
			    case 2:
				    cout<<"\nType2- Deluxe = Rs.4000/Day";
				    cout<<"\nEnter Total no. of rooms to be taken : ";
				    cin>>no;
				    cout<<"\nEnter no. of days to stay = ";
				    cin>>stay;				
				    ramt2=4000*no*stay;
				    cout<<"\nTotal Amount = "<<ramt2;
				    tramt+=ramt2;
				    break;
			    case 3:
			    	cout<<"\nType3- A/C = Rs.3500/Day";
				    cout<<"\nEnter Total no. of rooms to be taken : ";
			    	cin>>no;
				    cout<<"\nEnter no. of days to stay = ";
				    cin>>stay;				
				    ramt3=3500*no*stay;
				    cout<<"\nTotal Amount = "<<ramt3;	
				    tramt+=ramt3;
				    break;
			    case 4:
				    cout<<"\nType4- Non-A/C = Rs.3000/Day";
				    cout<<"\nEnter Total no. of rooms to be taken : ";
				    cin>>no;
				    cout<<"\nEnter no. of days to stay = ";
				    cin>>stay;				
				    ramt4=3000*no*stay;
				    cout<<"\nTotal Amount = "<<ramt4;
				    tramt+=ramt4;
				    break;
			    case 5:
				    cout<<"\nType5- Standard = Rs.2500/Day";
				    cout<<"\nEnter Total no. of rooms to be taken : ";
				    cin>>no;
				    cout<<"\nEnter no. of days to stay = ";
				    cin>>stay;				
				    ramt5=2500*no*stay;
				    cout<<"\nTotal Amount = "<<ramt5;
				    tramt+=ramt5;
				    break;
			    default:
		        cout<<"\nInvalid Input :("<<endl;
		    }
		    cout<<"\n\nDo you want to take more rooms?(Press Y/N) : ";
		    cin>>more;
	    }while(more=='Y'||more=='y');
	    tramt+=tramt*0.15;
	    cout<<"\nTotal Expenditure on Rooms = "<<tramt;
    	ofs.write((char*)&c,sizeof(customer));
	    cout<<"\nRoom Allotted Successfully :)";
    }
	else
	{
		ofs.write((char*)&c,sizeof(customer));
	}
}
	if(flag==0)
	{
		cout<<"\nCustomer ID not found :("<<endl;
	}
	ofs.close();
	ifs.close();
	remove("hotel.txt");
	rename("temp.txt","hotel.txt");	
}

void customer::food()
{
	int flag=0,items,cid4,fd1=0,fd2=0,fd3=0,fd4=0,fd5=0,fd6=0,fd7=0,fd8=0,fd9=0,fd10=0;
	char order;
	system("cls");
	cout<<"=========================FOODING SERVICES====================\n\n";
	ofstream ofs("temp.txt");
	ifstream ifs("hotel.txt");
	if(!ifs)
	{
		cout<<"File not found :("<<endl;
		getch();
		exit(0);
	}
	cout<<"\nEnter Customer ID to add Food Items : ";
	cin>>cid4;
	while(ifs.read((char*)&c,sizeof(customer)))
	{
	if(cid4==cid)
	{
		flag=1;
		cout<<"\nCustomer Name : "<<cn<<endl;
		cout<<"\nSL.NO\t\tMENU\t\t\tCHARGES AS PER REQUIRED\n";
	    cout<<"\n1- \t\tIndian Thaali:\t\tRs.300";
        cout<<"\n2- \t\tDal Makhni:\t\tRs.500";
        cout<<"\n3- \t\tPaneer based :\t\tRs.700";
        cout<<"\n4- \t\tChhole Bhature:\t\tRs.200";
        cout<<"\n5- \t\tChicken Masala:\t\tRs.600";
        cout<<"\n6- \t\tBurritos:\t\tRs.300";
        cout<<"\n7- \t\tSausage Tacos:\t\tRs.500";
        cout<<"\n8- \t\tChilli Con-Carne :\tRs.700";
        cout<<"\n9- \t\tChicken Quesadillas:\tRs.200";
        cout<<"\n10- \t\tTomato Salsa:\t\tRs.400";
		cout<<"\n---------------------------------";		
        do
        {
	        cout<<"\nEnter type to make order : ";
            cin>>items;
            fflush(stdin);
            switch(items)
            {
	            case 1:
	    	        fd1=300;
	    	        cout<<"\n1- Indian Thaali : "<<fd1;
		            tfamt+=fd1;
		            break;
	            case 2:
	    	        fd2=500;
	    	        cout<<"\n2- Dal Makhni : "<<fd2;
		            tfamt+=fd2;
		            break;
	            case 3:
	    	        fd3=700;
	    	        cout<<"\n3- Paneer Based : "<<fd3;
		            tfamt+=fd3;
		            break;
	            case 4:
	    	        fd4=200;
	    	        cout<<"\n4- Chhole Bhature : "<<fd4;
		            tfamt+=fd4;
		            break;
	            case 5:
	    	        fd5=600;
	    	        cout<<"\n5- Chicken Masala : "<<fd5;
		            tfamt+=fd5;
		            break;
	            case 6:
	    	        fd6=300;
	    	        cout<<"\n6- Burritos : "<<fd6;
	    	        tfamt+=fd6;
	    	        break;
    	        case 7:
    		        fd7=500;
    		        cout<<"\n7- Sausage Tacos : "<<fd7;
	    	        tfamt+=fd7;
	    	        break;
    	        case 8:
    		        fd8=700;
    		        cout<<"\n8- Chilli Con-Carne : "<<fd8;
	    	        tfamt+=fd8;
	    	        break;
	            case 9:
	    	        fd9=200;
		            cout<<"\n9- Chicken Quesadillas : "<<fd9;
		            tfamt+=fd9;
		            break;
	            case 10:
	    	        fd10=400;
		            cout<<"\n10- Tomato Salsa : "<<fd10;
		            tfamt+=fd10;
			        break;
	            default:
		        cout<<"Invalid Input :(";
	        }
	        cout<<"\n\nDo You Want to Add More Food Items? (Press Y/N) : ";
            cin>>order;
        }while(order=='Y'||order=='y');
        tfamt+=tfamt*0.05;
        cout<<"\nTotal Food Amount:"<<tfamt;
        ofs.write((char*)&c,sizeof(customer));
        cout<<"\nFood Items Added Successfully :)";	
    }
	else
	{
		ofs.write((char*)&c,sizeof(customer));
	}
}
    if(flag==0)
    {
	    cout<<"\nCustomer ID not found :("<<endl;
    }
    ofs.close();
    ifs.close();
    remove("hotel.txt");
    rename("temp.txt","hotel.txt"); 
}

void customer::event()
{
	int flag=0,ev1=0,ev2=0,ev3=0,ev4=0,ev5=0,ev6=0,ev7=0,event,cid5;
	char choose;
	system("cls");
	cout<<"======================EVENT BOOKING SECTION==========================\n\n";
	ofstream ofs("temp.txt");
	ifstream ifs("hotel.txt");
	if(!ifs)
	{
		cout<<"File not found :("<<endl;
		getch();
		exit(0);
	}
	cout<<"\nEnter Customer ID to add events : ";
	cin>>cid5;
	while(ifs.read((char*)&c,sizeof(customer)))
	{
	if(cid5==cid)
	{
		flag=1;
		cout<<"\nCustomer Name:"<<cn<<endl;
		cout<<"\nSL.NO\t\tTYPE OF EVENT\t\t\t\t\tCHARGES AS PER REQUIRED";
	    cout<<"\nType1-\t\tBirthday Celebration(Banquet Hall Only)\t\tRs.6,000/day";
	    cout<<"\nType2-\t\tWedding Ceremony(Banquet Hall)\t\t\tRs.45,000/day";
	    cout<<"\nType3-\t\tMarriage Anniversary\t\t\t\tRs.18,000/day";
        cout<<"\nType4-\t\tPress Conference Meeting\t\t\tRs.3,000/day";
        cout<<"\nType5-\t\tFashion Events\t\t\t\t\tRs.10,000/day";
        cout<<"\nType6-\t\tChildren Events\t\t\t\t\tRs.2,000/day";
        cout<<"\nType7-\t\tSpecial Auction\t\t\t\t\tRs.15,000/day";
        cout<<"\n-----------------------------------------------------";		
	    do
	    {
	        cout<<"\nWhich of the following events do you want to choose :";
	        cin>>event;
	        switch(event)
	        {
		        case 1:
		        	ev1=6000;
			        cout<<"\nBirthday Celebration Charges ="<<ev1;
			        cout<<"\n\nNo. of days = ";
			        cin>>stay;
			        tevamt+=ev1*stay;
		        	break;
		        case 2:
		        	ev2=45000;
		        	cout<<"\nWedding Ceremony Charges ="<<ev2;
			        cout<<"\n\nNo. of days = ";
			        cin>>stay;		        	
			        tevamt+=ev2*stay;
		        	break;
		        case 3:
		        	ev3=18000;
			        cout<<"\nMarriage Anniversary Charges ="<<ev3;
			        cout<<"\n\nNo. of days = ";
			        cin>>stay;			        
			        tevamt+=ev3*stay;
			        break;
		        case 4:
		        	ev4=3000;
			        cout<<"\nPress Conference Charges ="<<ev4;
			        cout<<"\n\nNo. of days = ";
			        cin>>stay;			        
			        tevamt+=ev4*stay;
			        break;
		        case 5:
		        	ev5=10000;
			        cout<<"\nFashion Event Charges ="<<ev5;
			        cout<<"\n\nNo. of days = ";
			        cin>>stay;				        
			        tevamt+=ev5*stay;
			        break;
		        case 6:
		        	ev6=2000;
			        cout<<"\nChildren Event Charges ="<<ev6;
			        cout<<"\n\nNo. of days = ";
			        cin>>stay;			        
			        tevamt+=ev6*stay;
			        break;
		        case 7:
		        	ev7=15000;
			        cout<<"\nSpecial Auction Charges ="<<ev7;
			        cout<<"\n\nNo. of days = ";
			        cin>>stay;			        
			        tevamt+=ev7*stay;
			        break;
		        default:
			        cout<<"\nInvalid Input :("<<endl;
			        getch();
	        }
	        cout<<"\nDo you want to continue with more events? (Press Y/N) : ";
	        cin>>choose;
        }while(choose=='Y'||choose=='y');
        tevamt+=tevamt*0.1;
        cout<<"\nTotal Amount with GST(10%): "<<tevamt;
        ofs.write((char*)&c,sizeof(customer));   
        cout<<"\nEvents Added Successfully :)";
    }
	else
	{
		ofs.write((char*)&c,sizeof(customer));
	}
}
   	if(flag==0)
	{
		cout<<"\nCustomer ID not found :("<<endl;
	}
	ofs.close();
	ifs.close();
	remove("hotel.txt");
	rename("temp.txt","hotel.txt");    
} 

void customer::bill()
{
	int cid6,flag=0;
	system("cls");
	cout<<"=======================BILLING SECTION==================\n\n";
	ofstream ofs("temp.txt");
	ifstream ifs("hotel.txt");
	if(!ifs)
	{
		cout<<"File not found :("<<endl;
		getch();
		exit(0);
	}
	cout<<"\nEnter Customer ID for Bill Generation : ";
	cin>>cid6;
	while(ifs.read((char*)&c,sizeof(customer)))
	{
		if(cid6==cid)
		{
			flag=1;
			cout<<"\nCustomer Name:"<<cn;
			cout<<"\nExpenditure on Rooms = "<<tramt;
			cout<<"\nExpenditure on Food = "<<tfamt;
			cout<<"\nExpenditure on Events = "<<tevamt;
			gtotal+=tramt+tfamt+tevamt;
			cout<<"\nGrand Total = "<<gtotal;
			ofs.write((char*)&c,sizeof(customer));
			cout<<"\nBill Generated Successfully :)";
		}
		else
		{
			ofs.write((char*)&c,sizeof(customer));
		}
	}
	if(flag==0)
	{
		cout<<"\nCustomer ID not found :(";
	}
	ifs.close();
	ofs.close();
	remove("hotel.txt");
	rename("temp.txt","hotel.txt");
		
}

void customer::del()
{
	system("cls");
	int cid7,flag=0;
	cout<<"=====================DELETE RECORD SECTION===================\n\n";
	ofstream ofs("temp.txt");
	ifstream ifs("hotel.txt");
	if(!ifs)
	{
		cout<<"File not found :("<<endl;
		getch();
		exit(0);
	}
	cout<<"\nEnter Customer ID to be delete : ";
	cin>>cid7;
	while(ifs.read((char*)&c,sizeof(customer)))
	{
		if(cid7==cid)
		{
			flag=1;
			cout<<"\nRecord Deleted Succesfully :)";		    
		}
		else
		{
			ofs.write((char*)&c,sizeof(customer));
		}
	}
	if(flag==0)
	{
		cout<<"\nCustomer ID not found :("<<endl;
	}
	ofs.close();
	ifs.close();
	remove("hotel.txt");
	rename("temp.txt","hotel.txt");
}

int main()
{
	int ch;
	char choice;
	do
	{
	    system("cls");
	    cout<<"====================WELCOME TO BLACK DIAMOND HOTEL===================\n\n";
	    cout<<"1- Add New Customer Record:";
	    cout<<"\n2- Search Customer Record:";
	    cout<<"\n3- Display All Customer Records:";
	    cout<<"\n4- Modify Customer Record:";
	    cout<<"\n5- Room Status:";
	    cout<<"\n6- Fooding:";
	    cout<<"\n7- Event Booking:";
	    cout<<"\n8- Bill Generation:";
	    cout<<"\n9- Delete Customer Details:";
	    cout<<"\n10- Exit";
	    cout<<"\n\nEnter Your Choice(1-9) : ";
	    cin>>ch;
	    switch(ch)
	    {
		    case 1:
			    c.add();
			    break;
		    case 2:
			    c.search();
			    break;
		    case 3:
			    c.display();
			    break;
		    case 4:
			    c.modify();
		    	break;
    		case 5:
	    		c.room();
		    	break;
	    	case 6:
	    		c.food();
	    		break;
	    	case 7:
	    		c.event();
	    		break;
	    	case 8:
	    		c.bill();
	    		break;
	    	case 9:
	    		c.del();
	    		break;
	    	case 10:
	    		cout<<"\n\nThank You, Visit Again!";
		}
	    cout<<"\nDo You Want To Continue? (Press Y or N) : ";
	    cin>>choice;
    }while(choice=='Y'||choice=='y');
} 
