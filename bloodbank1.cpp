#include<bits/stdc++.h>
using namespace std;
class Blood_group
{
protected:
    string blood_group;
public:
    Blood_group(string n)
    {
        blood_group=n;
    }
	void set_Blood_group(string n)
	{
	    blood_group=n;
	}
	string get_Blood_group()
	{
	    return blood_group;
	}

};
class User
{
protected:
	string phone_no;
	string email;
	string aadhar_no;
public:
    User(string a,string b,string c)
    {
        phone_no=a;
        email=b;
        aadhar_no=c;
    }
    void set_phone_no(string p)
	{
    		phone_no=p;
	}
    void set_email(string e){
    	email=e;
	}
    void set_aadhar(string h){
	aadhar_no=h;
	}	

    string get_phone_no(){
    	return phone_no;
	}

    string get_email(){
    	return email;
	}
    string get_aadhar(){
    	return aadhar_no;
	}

};
class Department
{
protected:
    string department;
public:
    Department(string d)
    {
        department=d;
    }
    string get_department(string d)
	{
    		return department;
	}
    void set_department(string d){
    		department=d;
	}
};
class Name
{
protected:
    string name;
public:
    Name(string n)
    {
        name=n;
    }
	void set_name(string n)
	{
	    name=n;
	}
	string get_name()
	{
	    return name;
	}

};
class Roll
{
protected:
    long int roll;
public:
    Roll(long int n)
    {
        roll=n;
    }
	void set_roll(long int  r)
	{
	    roll=r;
	}
	long int get_roll()
	{
	    return roll;
	}

};

class Donor:public Roll,public Name,public Department,public Blood_group,public User
{
protected:
    int no_of_blood_donate;
    string last_date_of_blood_donation;
public:
	Donor(string name,long int rollnum,string phone_no,string email,string aadhar_no,string blood_group,string dept,int num_of_blood,string lst_dt_of_bd):Roll(rollnum),User(phone_no,email,aadhar_no),Name(name),Department(dept),Blood_group(blood_group)
    {
        no_of_blood_donate=num_of_blood;
        last_date_of_blood_donation=lst_dt_of_bd;
	}
        void set_no_of_blood_donate(int n)
	{
	    no_of_blood_donate=n;
	}
	void set_last_date_of_blood_donation(string d)
	{
	    last_date_of_blood_donation=d;
	}
	int get_no_of_blood_donate()
	{
	    return no_of_blood_donate;
	}
	string get_last_date_of_blood_donation()
	{
	    return last_date_of_blood_donation;
	}
	void print1()
	{
		cout<<endl;
		cout<<"Name: "<<name<<endl;
		cout << "Phone no.:" << phone_no <<endl;
	}
	void print()
	{
		cout<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Email: "<<email<<endl;
		cout<<"Phone No.: "<<phone_no<<endl;
		cout<<"Aadhar No.: "<<aadhar_no<<endl;
		cout<<"Roll No.: "<<roll<<endl;
		cout<<"Blood Group: "<<blood_group<<endl;
		cout<<"Department: "<<department<<endl;
		cout<<"Amount of blood donated: "<<no_of_blood_donate<<endl;
		cout<<"Last Date of Blood Donation: "<<last_date_of_blood_donation<<endl;
		cout<<endl;
	}

};
int main(){
	int data;
    	cout<<"           WELCOME TO  BLOOD BANK MANAGEMENT SYSTEM    " <<endl;
	cout<<"include all the users in a file to get filled initially into the system"<<endl;
	ifstream infile; 
   	infile.open("input.txt");
	int num;
	//cout<<"Enter number of donors:"<<endl;
	infile>>num;
	//cin>>num;
	unordered_map<string,Donor> name_donors;
	unordered_map<string,Donor> aadhar_donors;
	unordered_map<string,vector<Donor>> blood_list;
	while(num--){
		string name,phonenum,email,addhar_no,blood_group,dept,lst_dt_of_bd;
		long int rollnum;
		int num_of_blood;		
		//cout<<"enter name=";
		infile>>name;
		//cout<<"enter phonenum:";
        infile>>phonenum;
		//cout<<"enter email:";
		infile>>email;
		//cout<<"enter addhar_no:";
		infile>>addhar_no;
		//cout<<"enter blood group:";
		infile>>blood_group;
		//cout<<"Enter dept:";
		infile>>dept;
		//cout<<"enter rollnum:";
		infile>>rollnum;
		//cout<<"Enter blood in ml:";
		infile>>num_of_blood;
		//cout<<"Enter the last donation:";
		infile>>lst_dt_of_bd;
		name_donors.insert({name,Donor(name,rollnum,phonenum,email,addhar_no,blood_group,dept,num_of_blood,lst_dt_of_bd)});
		aadhar_donors.insert({addhar_no,Donor(name,rollnum,phonenum,email,addhar_no,blood_group,dept,num_of_blood,lst_dt_of_bd)});
		auto itr=blood_list.find(blood_group);
		if(itr == blood_list.end()){	
			vector<Donor> donor_dt;
			donor_dt.push_back(Donor(name,rollnum,phonenum,email,addhar_no,blood_group,dept,num_of_blood,lst_dt_of_bd));
			blood_list.insert({blood_group,donor_dt});
		}
		else{
			itr->second.push_back(Donor(name,rollnum,phonenum,email,addhar_no,blood_group,dept,num_of_blood,lst_dt_of_bd));
		}
	}			
	infile.close();
	ofstream fout;
	fout.open("input.txt", ios::app);
	unordered_map<string,Donor>::iterator p;
	unordered_map<string,Donor>::iterator t;
	for(p=name_donors.begin();p!=name_donors.end();p++){
		p->second.print();
	}
	ifstream infile;
	infile.open("input.txt");
	string temp;
	int ch;
	while(1)
	{
		cout << "1-Add new user to the database\n2->Search by name \n3->Search by Aadhar Number\n4->Total count of each blood group\n5->Name and Phone no. according to blood group\n6->Exit\nEnter your choice\n";
		cin >> ch;
		unordered_map<string,vector<Donor>>::iterator itr2=blood_list.begin();
		unordered_map<string,vector<Donor>>::iterator itr3=blood_list.end();
		string name,phonenum,email,addhar_no,blood_group,dept,lst_dt_of_bd;
						long int rollnum;
						int num_of_blood;
		switch(ch)
		{
			case 1:
						if(fout.is_open()){		
						cout<<"enter name=";
						cin>>name;
						fout<<name<<endl;
						cout<<"enter phonenum:";
        				cin>>phonenum;
						fout<<phonenum<<endl;
						cout<<"enter email:";
						cin>>email;
						fout<<email<<endl;
						cout<<"enter addhar_no:";
						cin>>addhar_no;
						fout<<addhar_no<<endl;
						cout<<"enter blood group:";
						cin>>blood_group;
						fout<<blood_group<<endl;
						cout<<"Enter dept:";
						cin>>dept;
						fout<<dept<<endl;
						cout<<"enter rollnum:";
						cin>>rollnum;
						fout<<rollnum<<endl;
						cout<<"Enter blood in ml:";
						cin>>num_of_blood;
						fout<<num_of_blood<<endl;
						cout<<"Enter the last donation:";
						cin>>lst_dt_of_bd;
						fout<<lst_dt_of_bd<<endl;
						fout.close();
						name_donors.insert({name,Donor(name,rollnum,phonenum,email,addhar_no,blood_group,dept,num_of_blood,lst_dt_of_bd)});
						aadhar_donors.insert({addhar_no,Donor(name,rollnum,phonenum,email,addhar_no,blood_group,dept,num_of_blood,lst_dt_of_bd)});
						if(1){
						auto itr=blood_list.find(blood_group);
						
						if(itr == blood_list.end()){	
							vector<Donor> donor_dt;
							donor_dt.push_back(Donor(name,rollnum,phonenum,email,addhar_no,blood_group,dept,num_of_blood,lst_dt_of_bd));
							blood_list.insert({blood_group,donor_dt});
						}
					else{
						itr->second.push_back(Donor(name,rollnum,phonenum,email,addhar_no,blood_group,dept,num_of_blood,lst_dt_of_bd));
						}
						}
						}
					break;
			case 2:
				cout<<"Enter the name to be searched:"<<endl;
				cin>>temp;
				
				if (name_donors.find(temp) == name_donors.end()) 
				cout << "Element Not Present\n"; 
			    	else
				{
					p=name_donors.find(temp);
					p->second.print();
				}
				break;
			case 3:
				cout<<"Enter the Aadhar Number to be searched:"<<endl;
				cin>>temp;
				
				if (aadhar_donors.find(temp) == aadhar_donors.end()) 
				cout << "Element Not Present\n"; 
			    	else
				{
					t=aadhar_donors.find(temp);
					t->second.print();
				}
				break;
			case 4:	
				if(1)		
				{	
					int sum=0;
					while(itr2 != itr3)
					{
						sum=0;
						cout<<itr2->first;
						auto ptr=itr2->second.begin();
						auto ptr1=itr2->second.end();
						while(ptr != ptr1)
						{
							sum=sum+ptr->get_no_of_blood_donate();
							ptr++;
						}
						cout << "\t"<<sum ; 
						itr2++;
						cout<<endl;
					}
				}
				break;
			case 5:
				if(1)
				{	
					while(itr2 != itr3)
					{
						cout<<itr2->first;
						auto ptr=itr2->second.begin();
						auto ptr1=itr2->second.end();
						while(ptr != ptr1)
						{
							ptr->print1();
							ptr++;
						} 
						cout <<"\t\t\t";
						cout << "There are "<< itr2->second.size() << "people with " << itr2->first;
						itr2++;
						cout<<endl;
					}
				}
			        break;
			case 6:
				exit(1);
			default:
				cout<<"The option choosen is invalid.\n";
		}
        }        	
}