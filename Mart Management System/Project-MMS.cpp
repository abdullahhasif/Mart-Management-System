#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<stdio.h>
#include<fstream>
#include<string>
#include<iomanip>
#include<unistd.h>

using namespace std;

void validation(){
	
	start:	
	int first,last;

    int sum=0;

	int long arr[16];
	int long  arr2[16];

	int long arr_weigh[16]={2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1};
	
	cout<<"PLease Enter your Master-card / Visa-card Number: ";
	for(int i=0;i<16;i++)
	{
    cin>>arr[i];	
	}

	cout<<"This is the Key : ";
	for(int i=0;i<16;i++)
	{
    cout<<arr_weigh[i]<<" ";
	}
	
	for(int i=0;i<16;i++){
    arr2[i]=arr[i]*arr_weigh[i];
    if(arr2[i]>9){
        first = arr2[i]/10;
        last = arr2[i]%10;
        sum= sum + first + last;

    }
    else{
        sum += arr2[i];
       
}
}	

if(sum % 10 == 0){
    cout<<"\nYour Master-card / Visa-card Number is Authentic\n";
    cout<<"Thank you for shopping with us";
}
else{
    cout<<"\nYour Master-card / Visa-card Number is Not Authentic. Please try again.\n";
    cout<<endl<<endl;
    goto start;
}
}
struct FeedbackData 
{
    string name;
    string feedback;
};

int collect_feedback(FeedbackData & data) 
{
	
    cout <<"Enter your name: ";
    cin>>data.name;

    cout << "Please provide your feedback(no spaces.): ";
    cin>>data.feedback;

    ofstream file("feedback.txt", ios::app);  // Open file in append mode
    if (file.is_open()) {
        file <<"Feedback from "<< data.name<<": " << data.feedback << "\n";
        file.close();
        cout << "Thank you for your feedback!\n";
    }
	 else 
	{
        cout << "Error opening feedback file.\n";
    }
    return 0;
}

int admin_signup(){
	
	ofstream admin_write;
	admin_write.open("Admin Username.txt", ios::app);
	admin_write.close();
	
	admin_write.open("Admin Password.txt", ios::app);
	admin_write.close();
	
	string username;
	string *pointer_username= &username;
	
	user:
		
	cout<<"Please enter your Username"<<endl;
	cin>>username;
	cout<<endl;
	
	//this code encrypts username
	
	for (int counter=0; counter<username.length(); counter++){
		
		username[counter]=username[counter]+3;
	}
	
	ifstream admin_read;
	admin_read.open("Admin Username.txt", ios::app);
	
	string line_username;
	string *pointer_line=&line_username;
	bool check_username=true;
	
	
    //this code checks if the username entered is a duplicate or not
	
		if(admin_read.is_open()){
		
		while(!admin_read.eof()){
			
		   getline(admin_read, line_username);
		   
		   if(*pointer_line==*pointer_username){
		   	
		   	check_username=false;
		   	break;
		   }
		   	
		}
					
		
		
	admin_read.close();
	
	if(check_username==true){
		
	admin_write.open("Admin Username.txt", ios::app);
		
	admin_write<<*pointer_username<<endl;
		
	}
	
	else {
		
		cout<<"You have entered a duplicate Username. Please try again."<<endl<<endl;
		goto user;
	}
	
	}
	
	admin_read.close();
	admin_write.close();
	
	//This code enters unique passwords
	
	pass:
		
	string password;
	string *pointer_password=&password;
	
	cout<<"Please enter your password"<<endl;
	cin>>password;
	cout<<endl;
	
	//this code encrypts the password
	
	for (int counter=0; counter<password.length(); counter++){
		
		password[counter]= password[counter]+3;
	}
		
	admin_read.open("Admin Password.txt", ios::app);
	
	string line_password;
    pointer_line=&line_password;
	bool check_password=true;
	
	
    //this code checks if the password entered is a duplicate or not
	
		if(admin_read.is_open()){
		
		while(!admin_read.eof()){
			
		   getline(admin_read, line_password);
		     
		   if(*pointer_line==*pointer_password){
		   	
		   	check_password=false;
		   	break;
		   }
		   	
		}
					
	admin_read.close();
	
	if(check_password==true){
		
	admin_write.open("Admin Password.txt", ios::app);
		
	admin_write<<*pointer_password<<endl;
	
	cout<<"Signup succesful."<<endl;
			
		
	}
	
	else {
		
		cout<<"Signup succesful"<<endl;
		
		return 0; 
	}
	}
	
}




int user_signup(){
	
	ofstream admin_write;
	admin_write.open("User Username.txt", ios::app);
	admin_write.close();
	
	admin_write.open("User Password.txt", ios::app);
	admin_write.close();
	
	string username;
	string *pointer_username= &username;
	
	user:
		
	cout<<"Please enter your Username"<<endl;
	cin>>username;
	cout<<endl;
	
	//this code encrypts username
	
	for (int counter=0; counter<username.length(); counter++){
		
		username[counter]=username[counter]+3;
	}
	
	ifstream admin_read;
	admin_read.open("User Username.txt", ios::app);
	
	string line_username;
	string *pointer_line=&line_username;
	bool check_username=true;
	
    //this code checks if the username entered is a duplicate or not
	
		if(admin_read.is_open()){
		
		while(!admin_read.eof()){
			
		   getline(admin_read, line_username);
		   
		   if(*pointer_line==*pointer_username){
		   	
		   	check_username=false;
		   	break;
		   }
		   	
		}
					
		
		
	admin_read.close();
	
	if(check_username==true){
		
	admin_write.open("User Username.txt", ios::app);
		
	admin_write<<*pointer_username<<endl;
	
	
			
		
	}
	
	else {
		
		cout<<"You have entered a duplicate Username. Please try again."<<endl<<endl;
		goto user;
	}
	
	}
	
	admin_read.close();
	admin_write.close();
	
	//This code enters unique passwords
	
	pass:
		
	string password;
	string *pointer_password=&password;
	
	cout<<"Please enter your password"<<endl;
	cin>>password;
	cout<<endl;
	
	//this code encrypts the password
	
	for (int counter=0; counter<password.length(); counter++){
		
		password[counter]= password[counter]+3;
	}
		
	admin_read.open("User Password.txt", ios::app);
	
	string line_password;
    pointer_line=&line_password;
	bool check_password=true;
	
	
    //this code checks if the password entered is a duplicate or not
	
		if(admin_read.is_open()){
		
		while(!admin_read.eof()){
			
		   getline(admin_read, line_password);
		     
		   if(*pointer_line==*pointer_password){
		   	
		   	check_password=false;
		   	break;
		   }
		   	
		}
					
	admin_read.close();
	
	if(check_password==true){
		
	admin_write.open("User Password.txt", ios::app);
		
	admin_write<<*pointer_password<<endl;
	
	cout<<"Signup successful."<<endl;
			
		
	}
	
	else {
		cout<<"Signup successful."<<endl;
    return 0;  
	}
	}
	
}

int admin_login(){
	
	ifstream read;
	string line;
	int menu_type_admin,menu_type_admin1,menu_type_admin2;
	char go_back;

int price_dairy[5]= {200, 200, 150, 100, 180};

int price_bakery[7]={120, 80, 40, 50, 50, 40, 40};

int array_pantry[11]={0,0,0,0,0,0,0,0,0,0,0};
int price_pantry[11]= {120, 110, 150, 150, 150, 210, 170, 140, 150, 120, 130};

int array_condiments[8]={0,0,0,0,0,0,0,0};
int price_condiments[8]= {90, 90, 90, 80, 130, 120, 150, 150};

int array_canned[5]={0,0,0,0,0,};
int price_canned[5]= {120, 120, 130, 140, 170};

int array_frozen[8]={0,0,0,0,0,0,0,0};
int price_frozen[8]= {200, 450, 140, 850, 250, 350, 400, 150};

int array_meat[4]={0,0,0,0};
int price_meat[4]={450, 950, 850, 1050};

int array_drinks[9]={0,0,0,0,0,0,0,0,0};
int price_drinks[9]={80, 150, 150, 60, 60, 40, 120, 150, 150};

int array_snacks[7]={0,0,0,0,0,0,0};
int price_snacks[7]= {80, 80, 120, 150, 180, 180, 60};

int array_sweets[5]={0,0,0,0,0};
int price_sweets[5]= {120, 10, 40, 850, 60};

int array_cleaning[5]={0,0,0,0,0};
int price_cleaning[5]={200, 250, 300, 300, 250};

int array_punjabi[5]={0,0,0,0,0};
int price_punjabi[5]= {200, 250, 150, 80, 280};

int array_italian[5]={0,0,0,0,0};
int price_italian[5]={300, 1050, 150, 180, 280};

int array_indian[6]={0,0,0,0,0,0};
int price_indian[6]= {220, 210, 200, 50, 250, 210};

int array_chinese[4]={0,0,0,0};
int price_chinese[4]= {290, 350, 190, 180};

int array_vegeterian[6]={0,0,0,0,0,0};
int price_vegeterian[6]= {120, 120, 130, 140, 170, 80};

int array_fast[8]={0,0,0,0,0,0,0,0};
int price_fast[8]= {250, 150, 70, 150, 120, 180, 150, 120};

int array_seafood[4]={0,0,0,0};
int price_seafood[4]={450, 950, 850, 1050};

int array_cold_drinks[6]={0,0,0,0,0,0};
int price_cold_drinks[6]={80, 120, 120, 80, 80, 80};

int array_hot_drinks[6]={0,0,0,0,0,0};
int price_hot_drinks[6]= {80, 80, 120, 150, 180, 180};

string dairy[5];
	
int line_number=1;
	
	
read.open("Dairy.txt");
	
if (read.is_open()){
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				dairy[0]=line;
			}
			
			else if (line_number==2){
				
				dairy[1]=line;
			}
			
			else if (line_number==3){
				
				dairy[2]=line;
			}
			
			else if(line_number==4){
				
				dairy[3]=line;
			}
			
			else if (line_number==5){
				
				dairy[4]=line;
			}
			
			line_number++;
		}
	}
	
	read.close();


string bakery[7];

read.open("Bakery.txt");

if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				bakery[0]=line;
			}
			
			else if (line_number==2){
				
				bakery[1]=line;
			}
			
			else if (line_number==3){
				
				bakery[2]=line;
			}
			
			else if(line_number==4){
				
				bakery[3]=line;
			}
			
			else if (line_number==5){
				
				bakery[4]=line;
			}
			
			else if (line_number==6){
				
				bakery[5]=line;
			}
			
			else if (line_number==7){
				
				bakery[6]=line;
			}
			
			line_number++;
		}
}

read.close();

string pantry[11];

read.open("Pantry.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				pantry[0]=line;
			}
			
			else if (line_number==2){
				
				pantry[1]=line;
			}
			
			else if (line_number==3){
				
				pantry[2]=line;
			}
			
			else if(line_number==4){
				
				pantry[3]=line;
			}
			
			else if (line_number==5){
				
				pantry[4]=line;
			}
			
			else if (line_number==6){
				
				pantry[5]=line;
			}
			
			else if (line_number==7){
				
				pantry[6]=line;
			}
			
			else if (line_number==8){
				
				pantry[7]=line;
			}
			
			else if (line_number==9){
				
				pantry[8]=line;
			}
			
			else if (line_number==10){
				
				pantry[9]=line;
			}
			
			else if (line_number==11){
				
				pantry[10]=line;
			}
			
			line_number++;
		}
}

read.close();

string condiments[8];

read.open("Condiments.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				condiments[0]=line;
			}
			
			else if (line_number==2){
				
				condiments[1]=line;
			}
			
			else if (line_number==3){
				
				condiments[2]=line;
			}
			
			else if(line_number==4){
				
				condiments[3]=line;
			}
			
			else if (line_number==5){
				
				condiments[4]=line;
			}
			
			else if (line_number==6){
				
				condiments[5]=line;
			}
			
			else if (line_number==7){
				
				condiments[6]=line;
			}
			
			else if (line_number==8){
				
				condiments[7]=line;
			}

			
			line_number++;
		}
}

read.close();


string canned[6];

read.open("canned.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				canned[0]=line;
			}
			
			else if (line_number==2){
				
				canned[1]=line;
			}
			
			else if (line_number==3){
				
				canned[2]=line;
			}
			
			else if(line_number==4){
				
				canned[3]=line;
			}
			
			else if (line_number==5){
				
				canned[4]=line;
			}
			
			else if (line_number==6){
				
				canned[5]=line;
			}
		
			line_number++;
		}
}

read.close();

string frozen[8];

read.open("Frozen.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				frozen[0]=line;
			}
			
			else if (line_number==2){
				
				frozen[1]=line;
			}
			
			else if (line_number==3){
				
				frozen[2]=line;
			}
			
			else if(line_number==4){
				
				frozen[3]=line;
			}
			
			else if (line_number==5){
				
				frozen[4]=line;
			}
			
			else if (line_number==6){
				
				frozen[5]=line;
			}
			
			else if (line_number==7){
				
				frozen[6]=line;
			}
			
			else if (line_number==8){
				
				frozen[7]=line;
			}

			line_number++;
		}
}

read.close();

string meat[4];

read.open("Meat.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				meat[0]=line;
			}
			
			else if (line_number==2){
				
				meat[1]=line;
			}
			
			else if (line_number==3){
				
				meat[2]=line;
			}
			
			else if(line_number==4){
				
				meat[3]=line;
			}
			
			line_number++;
		}
}

read.close();

string drinks[9];

read.open("Drinks.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				drinks[0]=line;
			}
			
			else if (line_number==2){
				
				drinks[1]=line;
			}
			
			else if (line_number==3){
				
				drinks[2]=line;
			}
			
			else if(line_number==4){
				
				drinks[3]=line;
			}
			
			else if (line_number==5){
				
				drinks[4]=line;
			}
			
			else if (line_number==6){
				
				drinks[5]=line;
			}
			
			else if (line_number==7){
				
				drinks[6]=line;
			}
			
			else if (line_number==8){
				
				drinks[7]=line;
			}
			
			else if (line_number==9){
				
				drinks[8]=line;
			}

			line_number++;
		}
}

read.close();

string snacks[7];

read.open("Snacks.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				snacks[0]=line;
			}
			
			else if (line_number==2){
				
				snacks[1]=line;
			}
			
			else if (line_number==3){
				
				snacks[2]=line;
			}
			
			else if(line_number==4){
				
				snacks[3]=line;
			}
			
			else if (line_number==5){
				
				snacks[4]=line;
			}
			
			else if (line_number==6){
				
				snacks[5]=line;
			}
			
			else if (line_number==7){
				
				snacks[6]=line;
			}
			
			line_number++;
		}
}

read.close();

string sweets[5];

read.open("Sweets.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				sweets[0]=line;
			}
			
			else if (line_number==2){
				
				sweets[1]=line;
			}
			
			else if (line_number==3){
				
				sweets[2]=line;
			}
			
			else if(line_number==4){
				
				sweets[3]=line;
			}
			
			else if (line_number==5){
				
				sweets[4]=line;
			}
			
			line_number++;
		}
}

read.close();

string cleaning[5];

read.open("Cleaning.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				cleaning[0]=line;
			}
			
			else if (line_number==2){
				
				cleaning[1]=line;
			}
			
			else if (line_number==3){
				
				cleaning[2]=line;
			}
			
			else if(line_number==4){
				
				cleaning[3]=line;
			}
			
			else if (line_number==5){
				
				cleaning[4]=line;
			}
			
			line_number++;
		}
}
read.close();

string punjabi[5];

read.open("Punjabi Food.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				punjabi[0]=line;
			}
			
			else if (line_number==2){
				
				punjabi[1]=line;
			}
			
			else if (line_number==3){
				
				punjabi[2]=line;
			}
			
			else if(line_number==4){
				
				punjabi[3]=line;
			}
			
			else if (line_number==5){
				
				punjabi[4]=line;
			}
			
			line_number++;
		}
}

read.close();


string italian[5];

read.open("Italian Food.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				italian[0]=line;
			}
			
			else if (line_number==2){
				
				italian[1]=line;
			}
			
			else if (line_number==3){
				
			italian[2]=line;
			}
			
			else if(line_number==4){
				
				italian[3]=line;
			}
			
			else if (line_number==5){
				
				italian[4]=line;
			}
			
			line_number++;
		}
}

read.close();


string indian[6];

read.open("Indian Food.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				indian[0]=line;
			}
			
			else if (line_number==2){
				
				indian[1]=line;
			}
			
			else if (line_number==3){
				
			indian[2]=line;
			}
			
			else if(line_number==4){
				
				indian[3]=line;
			}
			
			else if (line_number==5){
				
				indian[4]=line;
			}
			
			else if (line_number==6){
				
			indian[5]=line;
			}
		
			line_number++;
		}
}

read.close();

string chinese[4];

read.open("Chinese Food.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				chinese[0]=line;
			}
			
			else if (line_number==2){
				
			chinese[1]=line;
			}
			
			else if (line_number==3){
				
			chinese[2]=line;
			}
			
			else if(line_number==4){
				
			chinese[3]=line;
			}
			
			line_number++;
		}
}

read.close();


string vegeterian[6];

read.open("Vegeterian Food.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				vegeterian[0]=line;
			}
			
			else if (line_number==2){
				
			vegeterian[1]=line;
			}
			
			else if (line_number==3){
				
			vegeterian[2]=line;
			}
			
			else if(line_number==4){
				
			vegeterian[3]=line;
			}
			
			else if (line_number==5){
				
			vegeterian[4]=line;
			}
			
			else if (line_number==6){
				
			vegeterian[5]=line;
			}
		
			line_number++;
		}
}

read.close();


string fast[8];

read.open("Fast Food.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				fast[0]=line;
			}
			
			else if (line_number==2){
				
				fast[1]=line;
			}
			
			else if (line_number==3){
				
				fast[2]=line;
			}
			
			else if(line_number==4){
				
			fast[3]=line;
			}
			
			else if (line_number==5){
				
				fast[4]=line;
			}
			
			else if (line_number==6){
				
				fast[5]=line;
			}
			
			else if (line_number==7){
				
			fast[6]=line;
			}
			
			else if (line_number==8){
				
			fast[7]=line;
			}

			line_number++;
		}
}

read.close();

string seafood[4];

read.open("Sea Food.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				seafood[0]=line;
			}
			
			else if (line_number==2){
				
			seafood[1]=line;
			}
			
			else if (line_number==3){
				
			seafood[2]=line;
			}
			
			else if(line_number==4){
				
			seafood[3]=line;
			}
			
			line_number++;
		}
}

read.close();

string cold_drinks[6];

read.open("Cold Drinks.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				cold_drinks[0]=line;
			}
			
			else if (line_number==2){
				
			cold_drinks[1]=line;
			}
			
			else if (line_number==3){
				
			cold_drinks[2]=line;
			}
			
			else if(line_number==4){
				
			cold_drinks[3]=line;
			}
			
			else if (line_number==5){
				
			cold_drinks[4]=line;
			}
			
			else if (line_number==6){
				
			cold_drinks[5]=line;
			}
		
			line_number++;
		}
}

read.close();

string hot_drinks[6];

read.open("Hot Drinks.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				hot_drinks[0]=line;
			}
			
			else if (line_number==2){
				
			hot_drinks[1]=line;
			}
			
			else if (line_number==3){
				
			hot_drinks[2]=line;
			}
			
			else if(line_number==4){
				
			hot_drinks[3]=line;
			}
			
			else if (line_number==5){
				
			hot_drinks[4]=line;
			}
			
			else if (line_number==6){
				
			hot_drinks[5]=line;
			}
		
			line_number++;
		}
}

read.close();


	
	string username;
	string *pointer_username=&username;
	
	string password;
	string *pointer_password=&password;
	
	string line_username;
	string *pointer_line_username= &line_username;
	
	string line_password;
	string *pointer_line_password= &line_password;
	
	for (int counter=3; counter>0; counter--){
		
		bool check_username=true;
	    bool check_password=true;
		
		cout<<"Please enter your username"<<endl;
		cin>>username;
		cout<<endl;
		
		ifstream read;
		read.open("Admin Username.txt");
		
		if(read.is_open()){
			
			while(!read.eof()){
				
				getline(read, line_username);
				
				//this code decrypts username
				
				for (int counter=0; counter<line_username.length(); counter++){
					
					line_username[counter]=line_username[counter]-3;
				}
				
				if (*pointer_username == *pointer_line_username){
					check_username=false;
					break;
					
				}
			}
		}
		
		if (check_username==false){
			
			read.close();
			
			cout<<"Please enter your password"<<endl;
			cin>>password;
			cout<<endl;
			
			read.open("Admin Password.txt");
			
			if (read.is_open()){
				
				while(!read.eof()){
					
					getline(read, line_password);
					
					//this code decrypts passwords
					
					for (int counter=0; counter<line_password.length(); counter++){
						
						line_password[counter]= line_password[counter]-3;
					}
					
					if (*pointer_password==*pointer_line_password){
						
						check_password=false;
						break;
					}
				}
		}
			
			if (check_password==false){
				
				ofstream write;
				
				write.open("Dairy.txt", ios::app);
				write.close();
				write.open("Dairy Quantity.txt", ios::app);
				write.close();
				
				write.open("Bakery.txt", ios::app);
				write.close();
				write.open("Bakery Quantity.txt", ios::app);
				write.close();
				
				write.open("pantry.txt", ios::app);
				write.close();
				write.open("Pantry Quantity.txt", ios::app);
				write.close();
				
				write.open("condiments.txt", ios::app);
				write.close();
				write.open("Condiments Quantity.txt", ios::app);
				write.close();
				
				write.open("canned.txt", ios::app);
				write.close();
				write.open("Canned Quantity.txt", ios::app);
				write.close();
				
				write.open("frozen.txt", ios::app);
				write.close();
				write.open("Frozen Quantity.txt", ios::app);
				write.close();
				
				write.open("meat.txt", ios::app);
				write.close();
				write.open("Meat Quantity.txt", ios::app);
				write.close();
				
				write.open("drinks.txt", ios::app);
				write.close();
				write.open("Drinks Quantity.txt", ios::app);
				write.close();
				
				write.open("snacks.txt", ios::app);
				write.close();
				write.open("Snacks Quantity.txt", ios::app);
				write.close();
				
				write.open("sweets.txt", ios::app);
				write.close();
				write.open("Sweets Quantity.txt", ios::app);
				write.close();
				
				write.open("cleaning.txt", ios::app);
				write.close();
				write.open("Cleaning Quantity.txt", ios::app);
				write.close();
				
				write.open("Punjabi Food.txt", ios::app);
				write.close();
				write.open("Punjabi Food Quantity.txt", ios::app);
				write.close();
				
				write.open("Italian Food.txt", ios::app);
				write.close();
				write.open("Italian Food Quantity.txt", ios::app);
				write.close();
				
				write.open("Indian Food.txt", ios::app);
				write.close();
				write.open("Indian Food Quantity.txt", ios::app);
				write.close();
				
		        write.open("Chinese Food.txt", ios::app);
		        write.close();
		        write.open("Chinese Food Quantity.txt", ios::app);
		        write.close();
		        
		        write.open("Vegetarian Food.txt", ios::app);
		        write.close();
		        write.open("Vegeterian Food Quantity.txt", ios::app);
		        write.close();
		        
		        write.open("Fast Food.txt", ios::app);
		        write.close();
		        write.open("Fast Food Quantity.txt", ios::app);
		        write.close();
		        
		        write.open("Sea Food.txt", ios::app);
		        write.close();
		        write.open("Sea Food Quantity.txt", ios::app);
		        write.close();
		        
		        write.open("Cold Drinks.txt", ios::app);
		        write.close();
		        write.open("Cold Drinks Quantity.txt", ios::app);
		        write.close();
		        
		        write.open("Hot Drinks.txt", ios::app);
		        write.close();
		        write.open("Hot Drinks Quantity.txt", ios::app);
		        write.close();
				
				int direction=0;
				system("cls");
				
				cout<<"What would you like to access?"<<endl;
				cout<<"Press '1' to enter new menu"<<endl;
				cout<<"Press '2' for see current menu"<<endl;
				cin>>direction;
				
				if (direction==1){
					
					switch (direction)
{
case 1:
	system("cls");
	int menu_type=0;
	int menu_type_1=0 , menu_type_2=0;
	string line_change;
	
    cout<<"\nSELECT THE MENU YOU WANT TO CHANGE ";
      cout<<"\n\n\t1. GROCERY ITEMS";
      cout<<"\n\n\t2. FOOD"<<endl;
      cout<<"\n- Select Option 1 or Option 2: ";
      cin>>menu_type;
      
      system("cls");
      if(menu_type==1)
	  {
      	
      	grocery:
      	cout<<"\n\tWelcome to the GROCERY ITEMS";
      	
      	cout<<"\n\nWHAT MENU WOULD YOU LIKE TO CHANGE";
      	
      	cout<<"\n\n1.DAIRY AND EGGS"<<endl;
      	cout<<"2.BAKERY ITEMS"<<endl;
      	cout<<"3.PANTRY STAPLES"<<endl;
      	cout<<"4.CONDIMENTS"<<endl;
      	cout<<"5.CANNED GOODS"<<endl;
      	cout<<"6.FROZEN FOODS"<<endl;
      	cout<<"7.MEAT AND PROTEINS"<<endl;
      	cout<<"8.BEVERAGES"<<endl;
      	cout<<"9.SNACKS"<<endl;
      	cout<<"10.SWEETS"<<endl;
      	cout<<"11. CLEANING AND HOUSEHOLD"<<endl;
      	cin>>menu_type_1;
      	
      	switch (menu_type_1){
      		
      		
      		case 1:
      			system("cls");
      			
      			cout<<"Please enter the new items. They have to be 5 in number"<<endl<<endl;
      			
      			write.open("Dairy.txt");
      			
      			for (int counter=0; counter<5; counter++){
      				
      				cout<<"Please enter the item"<<endl;
      				cin>>line_change;
      				
      				write<<line_change<<endl;
      				
      				
				  }
				  write.close();
      			
			break;
			
			case 2:
			system("cls");
			cout<<"Please enter the new items. They have to be 8 in number"<<endl<<endl;
			
			write.open("Bakery.txt");
			
			for (int counter=0; counter<8; counter++){
				
				cout<<"Please enter the item"<<endl;
				cin>>line_change;
				
				write<<line_change<<endl;
			}
			write.close();
			break;
			
			case 3:
				system("cls");
			cout<<"Please enter the new items. They have to be 11 in number"<<endl<<endl;
			
			write.open("Pantry.txt");
			
			for (int counter=0; counter<11; counter++){
				
				cout<<"Please enter the item"<<endl;
				cin>>line_change;
				
				write<<line_change<<endl;
			}
			write.close();
			break;
			
			case 4:
				system("cls");
			cout<<"Please enter the new items. They have to be 8 in number"<<endl<<endl;
			
			write.open("Condiments.txt");
			
			for (int counter=0; counter<8; counter++){
				
				cout<<"Please enter the item"<<endl;
				cin>>line_change;
				
				write<<line_change<<endl;
			}
			write.close();
			break;
			
			case 5:
				system("cls");
			cout<<"Please enter the new items. They have to be 6 in number"<<endl<<endl;
			
			write.open("Canned.txt");
			
			for (int counter=0; counter<6; counter++){
				
				cout<<"Please enter the item"<<endl;
				cin>>line_change;
				
				write<<line_change<<endl;
			}
			write.close();
			break;
			
			case 6:
				system("cls");
			cout<<"Please enter the new items. They have to be 8 in number"<<endl<<endl;
			
			write.open("frozen.txt");
			
			for (int counter=0; counter<8; counter++){
				
				cout<<"Please enter the item"<<endl;
				cin>>line_change;
				
				write<<line_change<<endl;
			}
			write.close();
			break;
			
			case 7:
				system("cls");
			cout<<"Please enter the new items. They have to be 4 in number"<<endl<<endl;
			
			write.open("Meat.txt");
			
			for (int counter=0; counter<4; counter++){
				
				cout<<"Please enter the item"<<endl;
				cin>>line_change;
				
				write<<line_change<<endl;
			}
			write.close();
			break;
			
			case 8:
				system("cls");
			cout<<"Please enter the new items. They have to be 9 in number"<<endl<<endl;
			
			write.open("drinks.txt");
			
			for (int counter=0; counter<9; counter++){
				
				cout<<"Please enter the item"<<endl;
				cin>>line_change;
				
				write<<line_change<<endl;
			}
			write.close();
			break;
			
			case 9:
				system("cls");
			cout<<"Please enter the new items. They have to be 7 in number"<<endl<<endl;
			
			write.open("Snacks.txt");
			
			for (int counter=0; counter<7; counter++){
				
				cout<<"Please enter the item"<<endl;
				cin>>line_change;
				
				write<<line_change<<endl;
			}
			write.close();
			break;
			
			case 10:
				system("cls");
			cout<<"Please enter the new items. They have to be 5 in number"<<endl<<endl;
			
			write.open("Sweets.txt");
			
			for (int counter=0; counter<5; counter++){
				
				cout<<"Please enter the item"<<endl;
				cin>>line_change;
				
				write<<line_change<<endl;
			}
			write.close();
			break;
			
			case 11:
				system("cls");
			cout<<"Please enter the new items. They have to be 5 in number"<<endl<<endl;
			
			write.open("Cleaning.txt");
			
			for (int counter=0; counter<5; counter++){
				
				cout<<"Please enter the item"<<endl;
				cin>>line_change;
				
				write<<line_change<<endl;
			}
			write.close();
			break;	  	
      	
		}
		}
		
		else if(menu_type==2)
 {
      	
        food:
        	system("cls");
      	cout<<"\n\tWelcome to the FOOD Items ";
      	
      	cout<<"\n\nThis is the list of food items";
      	
      	cout<<"\n\n1.PUNJABI FOOD"<<endl;
      	cout<<"2.ITALIAN FOOD"<<endl;
      	cout<<"3.INDIAN FOOD"<<endl;
      	cout<<"4.CHINESE FOOD"<<endl;
      	cout<<"5.VEGETERIAN FOOD"<<endl;
      	cout<<"6.FAST FOOD"<<endl;
      	cout<<"7.SEAFOOD"<<endl;
      	cout<<"8.COLD DRINKS"<<endl;
      	cout<<"9.HOT DRINKS"<<endl;
      	
      	cout<<"\nWhat menu would you like to re-write: ";
      	cin>>menu_type_2;
      	
      		switch(menu_type_2)
      		{
      		
      		
      		case 1:
      			system("cls");
      			cout<<"Please enter the new items. They have to be 5 in number"<<endl<<endl;
      			
      			write.open("Punjabi Food.txt");
      			
      			for (int counter=0; counter<5; counter++){
      				
      				cout<<"Please enter the item"<<endl;
      				cin>>line_change;
      				
      				write<<line_change<<endl;
      				
				  }
				  write.close();
      			
			break;
			
			case 2:
			system("cls");
			cout<<"Please enter the new items. They have to be 5 in number"<<endl<<endl;
			
			write.open("Italian Food.txt");
			
			for (int counter=0; counter<5; counter++){
				
				cout<<"Please enter the item"<<endl;
				cin>>line_change;
				
				write<<line_change<<endl;
			}
			write.close();
			break;
			
			case 3:
				system("cls");
			cout<<"Please enter the new items. They have to be 6 in number"<<endl<<endl;
			
			write.open("Indian Food.txt");
			
			for (int counter=0; counter<6; counter++){
				
				cout<<"Please enter the item"<<endl;
				cin>>line_change;
				
				write<<line_change<<endl;
			}
			write.close();
			break;
			
			case 4:
				system("cls");
			cout<<"Please enter the new items. They have to be 4 in number"<<endl<<endl;
			
			write.open("Chinese Food.txt");
			
			for (int counter=0; counter<4; counter++){
				
				cout<<"Please enter the item"<<endl;
				cin>>line_change;
				
				write<<line_change<<endl;
			}
			write.close();
			break;
			
			case 5:
				system("cls");
			cout<<"Please enter the new items. They have to be 6 in number"<<endl<<endl;
			
			write.open("Vegeterian Food.txt");
			
			for (int counter=0; counter<6; counter++){
				
				cout<<"Please enter the item"<<endl;
				cin>>line_change;
				
				write<<line_change<<endl;
			}
			write.close();
			break;
			
			case 6:
				system("cls");
			cout<<"Please enter the new items. They have to be 8 in number"<<endl<<endl;
			
			write.open("Fast Food.txt");
			
			for (int counter=0; counter<8; counter++){
				
				cout<<"Please enter the item"<<endl;
				cin>>line_change;
				
				write<<line_change<<endl;
			}
			write.close();
			break;
			
			case 7:
				system("cls");
			cout<<"Please enter the new items. They have to be 4 in number"<<endl<<endl;
			
			write.open("Sea Food.txt");
			
			for (int counter=0; counter<4; counter++){
				
				cout<<"Please enter the item"<<endl;
				cin>>line_change;
				
				write<<line_change<<endl;
			}
			write.close();
			break;
			
			case 8:
				system("cls");
			cout<<"Please enter the new items. They have to be 6 in number"<<endl<<endl;
			
			write.open("Cold Drinks.txt");
			
			for (int counter=0; counter<6; counter++){
				
				cout<<"Please enter the item"<<endl;
				cin>>line_change;
				
				write<<line_change<<endl;
			}
			write.close();
			break;
			
			case 9:
				system("cls");
			cout<<"Please enter the new items. They have to be 6 in number"<<endl<<endl;
			
			write.open("Hot Drinks.txt");
			
			for (int counter=0; counter<6; counter++){
				
				cout<<"Please enter the item"<<endl;
				cin>>line_change;
				
				write<<line_change<<endl;
			}
			write.close();
			break;
			
		}
		
		}
					
			

}
return 0;
}
else if(direction==2)
{
	system("cls");
	cout<<"\nSELECT THE ITEMS YOU WANT TO SEE";
      cout<<"\n\n\t1. GROCERY ITEMS";
      cout<<"\n\n\t2. FOOD";
      cout<<"\n\n\t3. See Feedback"<<endl;
      cout<<"\n- Select Option 1 or Option 2 or Option 3: ";
      cin>>menu_type_admin;
      
      if(menu_type_admin==1)
      {
      	menu:
      		system("cls");
      cout<<"\n\tWelcome back to the GROCERY ITEMS";
      	
      	cout<<"\n\nWHAT MENU WOULD YOU LIKE TO CHANGE?";
      	
      	cout<<"\n\n1.DAIRY AND EGGS"<<endl;
      	cout<<"2.BAKERY ITEMS"<<endl;
      	cout<<"3.PANTRY STAPLES"<<endl;
      	cout<<"4.CONDIMENTS"<<endl;
      	cout<<"5.CANNED GOODS"<<endl;
      	cout<<"6.FROZEN FOODS"<<endl;
      	cout<<"7.MEAT AND PROTEINS"<<endl;
      	cout<<"8.BEVERAGES"<<endl;
      	cout<<"9.SNACKS"<<endl;
      	cout<<"10.SWEETS"<<endl;
      	cout<<"11. CLEANING AND HOUSEHOLD"<<endl<<endl;
      	cout<<"Which portion you want to see?"<<endl;
      	cin>>menu_type_admin1;
      	
      	switch(menu_type_admin1)
      	{
      		case 1:
      			{
      				system("cls");
      				cout<<"\n\n\t\tDAIRY AND EGGS";
      				
      				cout<<"\n\nITEMS\t\t\t\t\t\tRATE(RS)\t\t\t\tQUANTITY";
      				cout<<"\n\n1."<<dairy[0] <<"\t\t\t\t\t\t"<<price_dairy[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<dairy[1] <<"\t\t\t\t\t\t"<<price_dairy[1]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n3."<<dairy[2] <<"\t\t\t\t\t"<<price_dairy[2]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n4."<<dairy[3] <<"\t\t\t\t\t"<<price_dairy[3]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n5."<<dairy[4] <<"\t\t\t\t\t"<<price_dairy[4]<<"Rs"<<"\t\t\t\t\t280";
					cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
					break;	
				}
			case 2:
				{
					system("cls");
					cout<<"BAKERY ITEMS";
      				
					cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)";
      				cout<<"\n\n1."<<bakery[0] <<"\t\t\t\t\t\t"<<price_bakery[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<bakery[1] <<"\t\t\t\t\t\t"<<price_bakery[1]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n3."<<bakery[2] <<"\t\t\t\t\t\t"<<price_bakery[2]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n4."<<bakery[3] <<"\t\t\t\t\t\t"<<price_bakery[3]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n5."<<bakery[4] <<"\t\t\t\t\t\t"<<price_bakery[4]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n6."<<bakery[5] <<"\t\t\t\t\t\t"<<price_bakery[5]<<"Rs"<<"\t\t\t\t\t280";
      		    	cout<<"\n7."<<bakery[6] <<"\t\t\t\t\t\t"<<price_bakery[6]<<"Rs"<<"\t\t\t\t\t280";
			    	cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
					break;
				}
					case 3:
				{
					system("cls");
      				cout<<"PANTRY STAPLES";
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)\t\t\t\tQUANTITY";
					cout<<"\n\n1."<<pantry[0] <<"\t\t\t\t\t\t"<<price_pantry[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<pantry[1] <<"\t\t\t\t\t\t"<<price_pantry[1]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n3."<<pantry[2] <<"\t\t\t\t\t\t"<<price_pantry[2]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n4."<<pantry[3] <<"\t\t\t\t\t\t"<<price_pantry[3]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n5."<<pantry[4] <<"\t\t\t\t\t\t"<<price_pantry[4]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n6."<<pantry[5] <<"\t\t\t\t\t\t"<<price_pantry[5]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n7."<<pantry[6] <<"\t\t\t\t\t\t"<<price_pantry[6]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n8."<<pantry[7] <<"\t\t\t\t\t\t"<<price_pantry[7]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n9."<<pantry[8] <<"\t\t\t\t\t\t"<<price_pantry[8]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n10."<<pantry[9] <<"\t\t\t\t\t\t"<<price_pantry[9]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n11."<<pantry[10] <<"\t\t\t\t\t\t"<<price_pantry[10]<<"Rs"<<"\t\t\t\t\t280";
      			    cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
				  	break;
      			}
      			case 4:
      			{
			system("cls");
      			cout<<"CONDIMENTS";
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)\t\t\t\tQUANTITY";
      				cout<<"\n\n1."<<condiments[0] <<"\t\t\t\t\t\t"<<price_condiments[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<condiments[1] <<"\t\t\t\t\t\t"<<price_condiments[1]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n3."<<condiments[2] <<"\t\t\t\t\t\t"<<price_condiments[2]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n4."<<condiments[3] <<"\t\t\t\t\t\t"<<price_condiments[3]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n5."<<condiments[4] <<"\t\t\t\t\t\t"<<price_condiments[4]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n6."<<condiments[5] <<"\t\t\t\t\t\t"<<price_condiments[5]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n7."<<condiments[6] <<"\t\t\t\t\t\t"<<price_condiments[6]<<"Rs"<<"\t\t\t\t\t280";
      		    	cout<<"\n8."<<condiments[7] <<"\t\t\t\t\t\t"<<price_condiments[7]<<"Rs"<<"\t\t\t\t\t280";
      		        cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
					  break;
			  	}
			  	case 5:
			  		{
			  			system("cls");
				
			  		cout<<"CANNED GOODS";
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)\t\t\t\tQUANTITY";
      				cout<<"\n\n1."<<canned[0] <<"\t\t\t\t\t\t"<<price_canned[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<canned[1] <<"\t\t\t\t\t\t"<<price_canned[1]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n3."<<canned[2] <<"\t\t\t\t\t\t"<<price_canned[2]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n4."<<canned[3] <<"\t\t\t\t\t\t"<<price_canned[3]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n5."<<canned[4] <<"\t\t\t\t\t\t"<<price_canned[4]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n6."<<canned[5] <<"\t\t\t\t\t\t"<<price_canned[5]<<"Rs"<<"\t\t\t\t\t280";
					cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
					 break;
					  }
			    case 6:
			    	{
			    		system("cls");
			    		cout<<"FROZEN FOODS";
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)\t\t\t\tQUANTITY";
      				cout<<"\n\n1."<<frozen[0] <<"\t\t\t\t\t\t"<<price_frozen[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<frozen[1] <<"\t\t\t\t\t\t"<<price_frozen[1]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n3."<<frozen[2] <<"\t\t\t\t\t\t"<<price_frozen[2]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n4."<<frozen[3] <<"\t\t\t\t\t\t"<<price_frozen[3]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n5."<<frozen[4] <<"\t\t\t\t\t\t"<<price_frozen[4]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n6."<<frozen[5] <<"\t\t\t\t\t\t"<<price_frozen[5]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n7."<<frozen[6] <<"\t\t\t\t\t\t"<<price_frozen[6]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n8."<<frozen[7] <<"\t\t\t\t\t\t"<<price_frozen[7]<<"Rs"<<"\t\t\t\t\t280";
					cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
					break;
					}
					case 7:
						{
							system("cls");
							cout<<"Meat and Proteins";
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)\t\t\t\tQUANTITY";
      				cout<<"\n\n1."<<meat[0] <<"\t\t\t\t\t\t"<<price_meat[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<meat[1] <<"\t\t\t\t\t\t"<<price_meat[1]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n3."<<meat[2] <<"\t\t\t\t\t\t"<<price_meat[2]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n4."<<meat[3] <<"\t\t\t\t\t\t"<<price_meat[3]<<"Rs"<<"\t\t\t\t\t280";
				cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
					break;
						}
				case 8:
					{
						system("cls");
						cout<<"BEVERAGES";
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)\t\t\t\tQUANTITY";
      				cout<<"\n\n1."<<drinks[0] <<"\t\t\t\t\t\t"<<price_drinks[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<drinks[1] <<"\t\t\t\t\t\t"<<price_drinks[1]<<"Rs"<<"\t\t\t\t\t280";
      			    cout<<"\n3."<<drinks[2] <<"\t\t\t\t\t\t"<<price_drinks[2]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n4."<<drinks[3] <<"\t\t\t\t\t\t"<<price_drinks[3]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n5."<<drinks[4] <<"\t\t\t\t\t\t"<<price_drinks[4]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n6."<<drinks[5] <<"\t\t\t\t\t\t"<<price_drinks[5]<<"Rs"<<"\t\t\t\t\t280";
      		    	cout<<"\n7."<<drinks[6] <<"\t\t\t\t\t\t"<<price_drinks[6]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n8."<<drinks[7] <<"\t\t\t\t\t\t"<<price_drinks[7]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n9."<<drinks[8] <<"\t\t\t\t\t\t"<<price_drinks[8]<<"Rs"<<"\t\t\t\t\t280";
			       cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
				break;
					}
					case 9:
						{
							system("cls");
							cout<<"SNACKS";
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)\t\t\t\tQUANTITY";
      				cout<<"\n\n1."<<snacks[0] <<"\t\t\t\t\t\t"<<price_snacks[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<snacks[1] <<"\t\t\t\t\t\t"<<price_snacks[1]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n3."<<snacks[2] <<"\t\t\t\t\t\t"<<price_snacks[2]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n4."<<snacks[3] <<"\t\t\t\t\t\t"<<price_snacks[3]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n5."<<snacks[4] <<"\t\t\t\t\t\t"<<price_snacks[4]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n6."<<snacks[5] <<"\t\t\t\t\t\t"<<price_snacks[5]<<"Rs"<<"\t\t\t\t\t280";
      			    cout<<"\n7."<<snacks[6] <<"\t\t\t\t\t\t"<<price_snacks[6]<<"Rs"<<"\t\t\t\t\t280";
				    cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
					break;
						}
			    	case 10:
					{
						system("cls");
						cout<<"SWEETS";
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)\t\t\t\tQUANTITY";
      				cout<<"\n\n1."<<sweets[0] <<"\t\t\t\t\t\t"<<price_sweets[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<sweets[1] <<"\t\t\t\t\t\t"<<price_sweets[1]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n3."<<sweets[2] <<"\t\t\t\t\t\t"<<price_sweets[2]<<"Rs"<<"\t\t\t\t\t280";
      			    cout<<"\n4."<<sweets[3] <<"\t\t\t\t\t\t"<<price_sweets[3]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n5."<<sweets[4] <<"\t\t\t\t\t\t"<<price_sweets[4]<<"Rs"<<"\t\t\t\t\t280";		
			cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
				break;
					}
					case 11:
					{
						system("cls");
						cout<<"CLEANING AND HOUSEHOLD";
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)\t\t\t\tQUANTITY";
      				cout<<"\n\n1."<<cleaning[0] <<"\t\t\t\t\t\t"<<price_cleaning[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<cleaning[1] <<"\t\t\t\t\t\t"<<price_cleaning[1]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n3."<<cleaning[2] <<"\t\t\t\t\t\t"<<price_cleaning[2]<<"Rs"<<"\t\t\t\t\t280";
      			    cout<<"\n4."<<cleaning[3] <<"\t\t\t\t\t\t"<<price_cleaning[3]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n5."<<cleaning[4] <<"\t\t\t\t\t\t"<<price_cleaning[4]<<"Rs"<<"\t\t\t\t\t280";	
			        cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
			break;
				}
		  }
      
      }
      else if(menu_type_admin==2)
      {
      	system("cls");
      	
      	cout<<"\n\tWelcome to the FOOD Items ";
      	
      	cout<<"\n\nFollowing are different types of food";
      	
      	cout<<"\n\n1.PUNJABI FOOD"<<endl;
      	cout<<"2.ITALIAN FOOD"<<endl;
      	cout<<"3.INDIAN FOOD"<<endl;
      	cout<<"4.CHINESE FOOD"<<endl;
      	cout<<"5.VEGETERIAN FOOD"<<endl;
      	cout<<"6.FAST FOOD"<<endl;
      	cout<<"7.SEAFOOD"<<endl;
      	cout<<"8.COLD DRINKS"<<endl;
      	cout<<"9.HOT DRINKS"<<endl;
      	
      	cout<<"\nWhich type of FOOD  you want to See: ";
      	cin>>menu_type_admin2;
      	
      	
      	switch(menu_type_admin2)
      	{
      		case 1:
      			{
      				system("cls");
      				cout<<"\n\n\t\tPunjabi Food";
      				
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)\t\t\t\tQUANTITY";
      				cout<<"\n\n1."<<punjabi[0] <<"\t\t\t\t\t\t"<<price_punjabi[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<punjabi[1] <<"\t\t\t\t\t\t"<<price_punjabi[1]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n3."<<punjabi[2] <<"\t\t\t\t\t\t"<<price_punjabi[2]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n4."<<punjabi[3] <<"\t\t\t\t\t\t"<<price_punjabi[3]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n5."<<punjabi[4] <<"\t\t\t\t\t\t"<<price_punjabi[4]<<"Rs"<<"\t\t\t\t\t280";
				    cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
				 break;
				  }
			case 2:
				{
					system("cls");
					cout<<"\n\n\t\tItalian Food";
      				
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)\t\t\t\tQUANTITY";
      				cout<<"\n\n1."<<italian[0] <<"\t\t\t\t\t\t"<<price_italian[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<italian[1] <<"\t\t\t\t\t\t"<<price_italian[1]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n3."<<italian[2] <<"\t\t\t\t\t\t"<<price_italian[2]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n4."<<italian[3] <<"\t\t\t\t\t\t"<<price_italian[3]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n5."<<italian[4] <<"\t\t\t\t\t\t"<<price_italian[4]<<"Rs"<<"\t\t\t\t\t280";
				  cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
				break;
				}
			case 3:
				{
					system("cls");
					cout<<"\n\n\t\tIndian Food";
      				
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)\t\t\t\tQUANTITY";
      				cout<<"\n1."<<indian[0] <<"\t\t\t\t\t\t"<<price_indian[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<indian[1] <<"\t\t\t\t\t\t"<<price_indian[1]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n3."<<indian[2] <<"\t\t\t\t\t\t"<<price_indian[2]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n4."<<indian[3] <<"\t\t\t\t\t\t"<<price_indian[3]<<"Rs"<<"\t\t\t\t\t280";
      		    	cout<<"\n5."<<indian[4] <<"\t\t\t\t\t\t"<<price_indian[4]<<"Rs"<<"\t\t\t\t\t280";
				    cout<<"\n6."<<indian[5] <<"\t\t\t\t\t\t"<<price_indian[5]<<"Rs"<<"\t\t\t\t\t280";
				cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
				break;
				}
			case 4:
				{
					system("cls");
					cout<<"\n\n\t\tChinese Food";
      				
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)\t\t\t\tQUANTITY";
      				cout<<"\n\n1."<<chinese[0] <<"\t\t\t\t\t\t"<<price_chinese[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<chinese[1] <<"\t\t\t\t\t\t"<<price_chinese[1]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n3."<<chinese[2] <<"\t\t\t\t\t\t"<<price_chinese[2]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n4."<<chinese[3] <<"\t\t\t\t\t\t"<<price_chinese[3]<<"Rs"<<"\t\t\t\t\t280";
			    cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
			 break;
				}
			case 5:
				{
					system("cls");
					cout<<"\n\n\t\tVegeterian Food";
      				
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)\t\t\t\tQUANTITY";
      				cout<<"\n\n1."<<vegeterian[0] <<"\t\t\t\t\t\t"<<price_vegeterian[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<vegeterian[1] <<"\t\t\t\t\t\t"<<price_vegeterian[1]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n3."<<vegeterian[2] <<"\t\t\t\t\t\t"<<price_vegeterian[2]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n4."<<vegeterian[3] <<"\t\t\t\t\t\t"<<price_vegeterian[3]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n5."<<vegeterian[4] <<"\t\t\t\t\t\t"<<price_vegeterian[4]<<"Rs"<<"\t\t\t\t\t280";
					cout<<"\n6."<<vegeterian[5] <<"\t\t\t\t\t\t"<<price_vegeterian[5]<<"Rs"<<"\t\t\t\t\t280";
			    cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
				break;
				}
		   case 6:
		   	{
		   		system("cls");
		   		cout<<"\n\n\t\tFast Food";
      				
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)\t\t\t\tQUANTITY";
      				cout<<"\n\n1."<<fast[0] <<"\t\t\t\t\t\t"<<price_fast[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<fast[1] <<"\t\t\t\t\t\t"<<price_fast[1]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n3."<<fast[2] <<"\t\t\t\t\t\t"<<price_fast[2]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n4."<<fast[3] <<"\t\t\t\t\t\t"<<price_fast[3]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n5."<<fast[4] <<"\t\t\t\t\t\t"<<price_fast[4]<<"Rs"<<"\t\t\t\t\t280";
					cout<<"\n6."<<fast[5] <<"\t\t\t\t\t\t"<<price_fast[5]<<"Rs"<<"\t\t\t\t\t280";
					cout<<"\n7."<<fast[6] <<"\t\t\t\t\t\t"<<price_fast[6]<<"Rs"<<"\t\t\t\t\t280";
					cout<<"\n8."<<fast[7] <<"\t\t\t\t\t\t"<<price_fast[7]<<"Rs"<<"\t\t\t\t\t280";
			     cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
			   break;
			   }
			case 7:
				{
					system("cls");
					cout<<"\n\n\t\tSea Food";
      				
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)\t\t\t\tQUANTITY";
      				cout<<"\n\n1."<<seafood[0] <<"\t\t\t\t\t\t"<<price_seafood[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<seafood[1] <<"\t\t\t\t\t\t"<<price_seafood[1]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n3."<<seafood[2] <<"\t\t\t\t\t\t"<<price_seafood[2]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n4."<<seafood[3] <<"\t\t\t\t\t\t"<<price_seafood[3]<<"Rs"<<"\t\t\t\t\t280";
		cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
			break;
				}
			case 8:
				{
					system("cls");
					cout<<"\n\n\t\tCold Drinks";
      				
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)\t\t\t\tQUANTITY";
      				cout<<"\n\n1."<<cold_drinks[0] <<"\t\t\t\t\t\t"<<price_cold_drinks[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<cold_drinks[1] <<"\t\t\t\t\t\t"<<price_cold_drinks[1]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n3."<<cold_drinks[2] <<"\t\t\t\t\t\t"<<price_cold_drinks[2]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n4."<<cold_drinks[3] <<"\t\t\t\t\t\t"<<price_cold_drinks[3]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n5."<<cold_drinks[4] <<"\t\t\t\t\t\t"<<price_cold_drinks[4]<<"Rs"<<"\t\t\t\t\t280";
					cout<<"\n6."<<cold_drinks[5] <<"\t\t\t\t\t\t"<<price_cold_drinks[5]<<"Rs"<<"\t\t\t\t\t280";
				cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
				break;
				}
			case 9:
				{
					system("cls");
					cout<<"\n\n\t\tHot Drinks";
      				
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)\t\t\t\tQUANTITY";
      				cout<<"\n\n1."<<hot_drinks[0] <<"\t\t\t\t\t\t"<<price_hot_drinks[0]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n2."<<hot_drinks[1] <<"\t\t\t\t\t\t"<<price_hot_drinks[1]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n3."<<hot_drinks[2] <<"\t\t\t\t\t\t"<<price_hot_drinks[2]<<"Rs"<<"\t\t\t\t\t280";
      			    cout<<"\n4."<<hot_drinks[3] <<"\t\t\t\t\t\t"<<price_hot_drinks[3]<<"Rs"<<"\t\t\t\t\t280";
      				cout<<"\n5."<<hot_drinks[4] <<"\t\t\t\t\t\t"<<price_hot_drinks[4]<<"Rs"<<"\t\t\t\t\t280";
					cout<<"\n6."<<hot_drinks[5] <<"\t\t\t\t\t\t"<<price_hot_drinks[5]<<"Rs"<<"\t\t\t\t\t280";
				cout<<"\n\nIf you want to go back menu press Y"<<endl;
					cin>>go_back;
					if((go_back=='y')||(go_back=='Y'))
					{
						goto menu;
					}
					else
					{
						return 0;
					}
				break;
				}
					
		  }
  	
  }
  else if(menu_type_admin==3)
  {
  	 ifstream file;
	  file.open("feedback.txt");
    if (file.is_open())
  {
     
      while(file.good())
      {
      	getline(file, line);
      	cout<<line<<endl;
	  }
        
  }	
return 0;	
}

    else{
    	
    	cout<<"Your password is incorrect. Please try again."<<endl;
		cout<<"You have "<<counter-1<<" tries remaining"<<endl<<endl;
		read.close();
	}
}
   else {
   	   cout<<"Your username is incorrect. Please try again."<<endl;
	   cout<<"You have "<<counter-1<<" tries remaining"<<endl<<endl;
	   read.close();
   }



}		
}
}
}
				

int user_login(){
	
	string username;
	string *pointer_username=&username;
	
	string password;
	string *pointer_password=&password;
	
	string line_username;
	string *pointer_line_username= &line_username;
	
	string line_password;
	string *pointer_line_password= &line_password;
	
	for (int counter=3; counter>0; counter--){
		
		bool check_username=true;
	    bool check_password=true;
		
		cout<<"Please enter your username"<<endl;
		cin>>username;
		cout<<endl;
		
		ifstream read;
		read.open("User Username.txt");
		
		if(read.is_open()){
			
			while(!read.eof()){
				
				getline(read, line_username);
				
				//this code decrypts username
				
				for (int counter=0; counter<line_username.length(); counter++){
					
					line_username[counter]=line_username[counter]-3;
				}
				
				if (*pointer_username == *pointer_line_username){
					check_username=false;
					break;
					
				}
			}
		}
		
		if (check_username==false){
			
			read.close();
			
			cout<<"Please enter your password"<<endl;
			cin>>password;
			cout<<endl;
			
			read.open("User Password.txt");
			
			if (read.is_open()){
				
				while(!read.eof()){
					
					getline(read, line_password);
					
					//this code decrypts passwords
					
					for (int counter=0; counter<line_password.length(); counter++){
						
						line_password[counter]= line_password[counter]-3;
					}
				
					if (*pointer_password==*pointer_line_password){
						
						check_password=false;
						break;
					}
				}
			}
			
			if (check_password==false){
				
				
	
	/********************************* Displaying the Main Heading ************************/
				
   string fname,lname;
   char yn, cont,yn1,cont1;
   int bill, menu, menu_type, menu_type_1, menu_type_2;
   int sum=0,total=0;
   int check=0;
   char back;	
   home_page:
   system("cls");		
	cout<<"=========================================================================="<<endl;
	cout<<"\t\t || Welcome to the Destin Grocery  ||"<<endl;
	cout<<"=========================================================================="<<endl<<endl;
	
	system("pause"); // used to display "Press any key to continue"

/**************************************** MENU **********************************************/
cout<<"\n\n=====================================================";
cout<<"\n\n\tChoose Your Desired Option: ";
cout<<"\n\n=====================================================";

cout<<"\n\n\n\1.MENU & PURCHASE";
cout<<"\n\n\n\2.DETAILS";
cout<<"\n\n\n\3.FEEDBACK";
cout<<"\n\n\nENTER YOUR CHOICE:";
cin>>menu;

system("cls"); // Shows a new display by removing the previous display.

string line;
ifstream read;

int array_dairy[5]={0,0,0,0,0};
int price_dairy[5]= {200, 200, 150, 100, 180};

int array_bakery[7]={0,0,0,0,0,0,0};
int price_bakery[7]={120, 80, 40, 50, 50, 40, 40};

int array_pantry[11]={0,0,0,0,0,0,0,0,0,0,0};
int price_pantry[11]= {120, 110, 150, 150, 150, 210, 170, 140, 150, 120, 130};

int array_condiments[8]={0,0,0,0,0,0,0,0};
int price_condiments[8]= {90, 90, 90, 80, 130, 120, 150, 150};

int array_canned[5]={0,0,0,0,0,};
int price_canned[5]= {120, 120, 130, 140, 170};

int array_frozen[8]={0,0,0,0,0,0,0,0};
int price_frozen[8]= {200, 450, 140, 850, 250, 350, 400, 150};

int array_meat[4]={0,0,0,0};
int price_meat[4]={450, 950, 850, 1050};

int array_drinks[9]={0,0,0,0,0,0,0,0,0};
int price_drinks[9]={80, 150, 150, 60, 60, 40, 120, 150, 150};

int array_snacks[7]={0,0,0,0,0,0,0};
int price_snacks[7]= {80, 80, 120, 150, 180, 180, 60};

int array_sweets[5]={0,0,0,0,0};
int price_sweets[5]= {120, 10, 40, 850, 60};

int array_cleaning[5]={0,0,0,0,0};
int price_cleaning[5]={200, 250, 300, 300, 250};

int array_punjabi[5]={0,0,0,0,0};
int price_punjabi[5]= {200, 250, 150, 80, 280};

int array_italian[5]={0,0,0,0,0};
int price_italian[5]={300, 1050, 150, 180, 280};

int array_indian[6]={0,0,0,0,0,0};
int price_indian[6]= {220, 210, 200, 50, 250, 210};

int array_chinese[4]={0,0,0,0};
int price_chinese[4]= {290, 350, 190, 180};

int array_vegeterian[6]={0,0,0,0,0,0};
int price_vegeterian[6]= {120, 120, 130, 140, 170, 80};

int array_fast[8]={0,0,0,0,0,0,0,0};
int price_fast[8]= {250, 150, 70, 150, 120, 180, 150, 120};

int array_seafood[4]={0,0,0,0};
int price_seafood[4]={450, 950, 850, 1050};

int array_cold_drinks[6]={0,0,0,0,0,0};
int price_cold_drinks[6]={80, 120, 120, 80, 80, 80};

int array_hot_drinks[6]={0,0,0,0,0,0};
int price_hot_drinks[6]= {80, 80, 120, 150, 180, 180};

string dairy[5];
	
int line_number=1;
	
	
read.open("Dairy.txt");
	
if (read.is_open()){
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				dairy[0]=line;
			}
			
			else if (line_number==2){
				
				dairy[1]=line;
			}
			
			else if (line_number==3){
				
				dairy[2]=line;
			}
			
			else if(line_number==4){
				
				dairy[3]=line;
			}
			
			else if (line_number==5){
				
				dairy[4]=line;
			}
			
			line_number++;
		}
	}
	
	read.close();


string bakery[7];

read.open("Bakery.txt");

if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				bakery[0]=line;
			}
			
			else if (line_number==2){
				
				bakery[1]=line;
			}
			
			else if (line_number==3){
				
				bakery[2]=line;
			}
			
			else if(line_number==4){
				
				bakery[3]=line;
			}
			
			else if (line_number==5){
				
				bakery[4]=line;
			}
			
			else if (line_number==6){
				
				bakery[5]=line;
			}
			
			else if (line_number==7){
				
				bakery[6]=line;
			}
			
			line_number++;
		}
}

read.close();

string pantry[11];

read.open("Pantry.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				pantry[0]=line;
			}
			
			else if (line_number==2){
				
				pantry[1]=line;
			}
			
			else if (line_number==3){
				
				pantry[2]=line;
			}
			
			else if(line_number==4){
				
				pantry[3]=line;
			}
			
			else if (line_number==5){
				
				pantry[4]=line;
			}
			
			else if (line_number==6){
				
				pantry[5]=line;
			}
			
			else if (line_number==7){
				
				pantry[6]=line;
			}
			
			else if (line_number==8){
				
				pantry[7]=line;
			}
			
			else if (line_number==9){
				
				pantry[8]=line;
			}
			
			else if (line_number==10){
				
				pantry[9]=line;
			}
			
			else if (line_number==11){
				
				pantry[10]=line;
			}
			
			line_number++;
		}
}

read.close();

string condiments[8];

read.open("Condiments.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				condiments[0]=line;
			}
			
			else if (line_number==2){
				
				condiments[1]=line;
			}
			
			else if (line_number==3){
				
				condiments[2]=line;
			}
			
			else if(line_number==4){
				
				condiments[3]=line;
			}
			
			else if (line_number==5){
				
				condiments[4]=line;
			}
			
			else if (line_number==6){
				
				condiments[5]=line;
			}
			
			else if (line_number==7){
				
				condiments[6]=line;
			}
			
			else if (line_number==8){
				
				condiments[7]=line;
			}

			
			line_number++;
		}
}

read.close();


string canned[6];

read.open("canned.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				canned[0]=line;
			}
			
			else if (line_number==2){
				
				canned[1]=line;
			}
			
			else if (line_number==3){
				
				canned[2]=line;
			}
			
			else if(line_number==4){
				
				canned[3]=line;
			}
			
			else if (line_number==5){
				
				canned[4]=line;
			}
			
			else if (line_number==6){
				
				canned[5]=line;
			}
		
			line_number++;
		}
}

read.close();

string frozen[8];

read.open("Frozen.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				frozen[0]=line;
			}
			
			else if (line_number==2){
				
				frozen[1]=line;
			}
			
			else if (line_number==3){
				
				frozen[2]=line;
			}
			
			else if(line_number==4){
				
				frozen[3]=line;
			}
			
			else if (line_number==5){
				
				frozen[4]=line;
			}
			
			else if (line_number==6){
				
				frozen[5]=line;
			}
			
			else if (line_number==7){
				
				frozen[6]=line;
			}
			
			else if (line_number==8){
				
				frozen[7]=line;
			}

			line_number++;
		}
}

read.close();

string meat[4];

read.open("Meat.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				meat[0]=line;
			}
			
			else if (line_number==2){
				
				meat[1]=line;
			}
			
			else if (line_number==3){
				
				meat[2]=line;
			}
			
			else if(line_number==4){
				
				meat[3]=line;
			}
			
			line_number++;
		}
}

read.close();

string drinks[9];

read.open("Drinks.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				drinks[0]=line;
			}
			
			else if (line_number==2){
				
				drinks[1]=line;
			}
			
			else if (line_number==3){
				
				drinks[2]=line;
			}
			
			else if(line_number==4){
				
				drinks[3]=line;
			}
			
			else if (line_number==5){
				
				drinks[4]=line;
			}
			
			else if (line_number==6){
				
				drinks[5]=line;
			}
			
			else if (line_number==7){
				
				drinks[6]=line;
			}
			
			else if (line_number==8){
				
				drinks[7]=line;
			}
			
			else if (line_number==9){
				
				drinks[8]=line;
			}

			line_number++;
		}
}

read.close();

string snacks[7];

read.open("Snacks.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				snacks[0]=line;
			}
			
			else if (line_number==2){
				
				snacks[1]=line;
			}
			
			else if (line_number==3){
				
				snacks[2]=line;
			}
			
			else if(line_number==4){
				
				snacks[3]=line;
			}
			
			else if (line_number==5){
				
				snacks[4]=line;
			}
			
			else if (line_number==6){
				
				snacks[5]=line;
			}
			
			else if (line_number==7){
				
				snacks[6]=line;
			}
			
			line_number++;
		}
}

read.close();

string sweets[5];

read.open("Sweets.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				sweets[0]=line;
			}
			
			else if (line_number==2){
				
				sweets[1]=line;
			}
			
			else if (line_number==3){
				
				sweets[2]=line;
			}
			
			else if(line_number==4){
				
				sweets[3]=line;
			}
			
			else if (line_number==5){
				
				sweets[4]=line;
			}
			
			line_number++;
		}
}

read.close();

string cleaning[5];

read.open("Cleaning.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				cleaning[0]=line;
			}
			
			else if (line_number==2){
				
				cleaning[1]=line;
			}
			
			else if (line_number==3){
				
				cleaning[2]=line;
			}
			
			else if(line_number==4){
				
				cleaning[3]=line;
			}
			
			else if (line_number==5){
				
				cleaning[4]=line;
			}
			
			line_number++;
		}
}
read.close();

string punjabi[5];

read.open("Punjabi Food.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				punjabi[0]=line;
			}
			
			else if (line_number==2){
				
				punjabi[1]=line;
			}
			
			else if (line_number==3){
				
				punjabi[2]=line;
			}
			
			else if(line_number==4){
				
				punjabi[3]=line;
			}
			
			else if (line_number==5){
				
				punjabi[4]=line;
			}
			
			line_number++;
		}
}

read.close();


string italian[5];

read.open("Italian Food.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				italian[0]=line;
			}
			
			else if (line_number==2){
				
				italian[1]=line;
			}
			
			else if (line_number==3){
				
			italian[2]=line;
			}
			
			else if(line_number==4){
				
				italian[3]=line;
			}
			
			else if (line_number==5){
				
				italian[4]=line;
			}
			
			line_number++;
		}
}

read.close();


string indian[6];

read.open("Indian Food.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				indian[0]=line;
			}
			
			else if (line_number==2){
				
				indian[1]=line;
			}
			
			else if (line_number==3){
				
			indian[2]=line;
			}
			
			else if(line_number==4){
				
				indian[3]=line;
			}
			
			else if (line_number==5){
				
				indian[4]=line;
			}
			
			else if (line_number==6){
				
			indian[5]=line;
			}
		
			line_number++;
		}
}

read.close();

string chinese[4];

read.open("Chinese Food.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				chinese[0]=line;
			}
			
			else if (line_number==2){
				
			chinese[1]=line;
			}
			
			else if (line_number==3){
				
			chinese[2]=line;
			}
			
			else if(line_number==4){
				
			chinese[3]=line;
			}
			
			line_number++;
		}
}

read.close();


string vegeterian[6];

read.open("Vegeterian Food.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				vegeterian[0]=line;
			}
			
			else if (line_number==2){
				
			vegeterian[1]=line;
			}
			
			else if (line_number==3){
				
			vegeterian[2]=line;
			}
			
			else if(line_number==4){
				
			vegeterian[3]=line;
			}
			
			else if (line_number==5){
				
			vegeterian[4]=line;
			}
			
			else if (line_number==6){
				
			vegeterian[5]=line;
			}
		
			line_number++;
		}
}

read.close();


string fast[8];

read.open("Fast Food.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				fast[0]=line;
			}
			
			else if (line_number==2){
				
				fast[1]=line;
			}
			
			else if (line_number==3){
				
				fast[2]=line;
			}
			
			else if(line_number==4){
				
			fast[3]=line;
			}
			
			else if (line_number==5){
				
				fast[4]=line;
			}
			
			else if (line_number==6){
				
				fast[5]=line;
			}
			
			else if (line_number==7){
				
			fast[6]=line;
			}
			
			else if (line_number==8){
				
			fast[7]=line;
			}

			line_number++;
		}
}

read.close();

string seafood[4];

read.open("Sea Food.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				seafood[0]=line;
			}
			
			else if (line_number==2){
				
			seafood[1]=line;
			}
			
			else if (line_number==3){
				
			seafood[2]=line;
			}
			
			else if(line_number==4){
				
			seafood[3]=line;
			}
			
			line_number++;
		}
}

read.close();

string cold_drinks[6];

read.open("Cold Drinks.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				cold_drinks[0]=line;
			}
			
			else if (line_number==2){
				
			cold_drinks[1]=line;
			}
			
			else if (line_number==3){
				
			cold_drinks[2]=line;
			}
			
			else if(line_number==4){
				
			cold_drinks[3]=line;
			}
			
			else if (line_number==5){
				
			cold_drinks[4]=line;
			}
			
			else if (line_number==6){
				
			cold_drinks[5]=line;
			}
		
			line_number++;
		}
}

read.close();

string hot_drinks[6];

read.open("Hot Drinks.txt");

 if (read.is_open()){
	
	line_number=1;
	
	while(!read.eof()){
		
		getline(read, line );
			
			if (line_number==1){
				
				hot_drinks[0]=line;
			}
			
			else if (line_number==2){
				
			hot_drinks[1]=line;
			}
			
			else if (line_number==3){
				
			hot_drinks[2]=line;
			}
			
			else if(line_number==4){
				
			hot_drinks[3]=line;
			}
			
			else if (line_number==5){
				
			hot_drinks[4]=line;
			}
			
			else if (line_number==6){
				
			hot_drinks[5]=line;
			}
		
			line_number++;
		}
}

read.close();


switch (menu)
{
case 1:{
	

    cout<<"\nSELECT THE ITEMS YOU WANT TO PURCHASE";
      cout<<"\n\n\t1. GROCERY ITEMS";
      cout<<"\n\n\t2. FOOD"<<endl;
      cout<<"\n- Select Option 1 or Option 2: ";
      cin>>menu_type;
      
      system("cls");
      if(menu_type==1){
      	
      	grocery:
      	cout<<"\n\tWelcome to the GROCERY ITEMS";
      	
      	cout<<"\n\nWe have the following items for you";
      	
      	cout<<"\n\n1.DAIRY AND EGGS"<<endl;
      	cout<<"2.BAKERY ITEMS"<<endl;
      	cout<<"3.PANTRY STAPLES"<<endl;
      	cout<<"4.CONDIMENTS"<<endl;
      	cout<<"5.CANNED GOODS"<<endl;
      	cout<<"6.FROZEN FOODS"<<endl;
      	cout<<"7.MEAT AND PROTEINS"<<endl;
      	cout<<"8.BEVERAGES"<<endl;
      	cout<<"9.SNACKS"<<endl;
      	cout<<"10.SWEETS"<<endl;
      	cout<<"11. CLEANING AND HOUSEHOLD"<<endl;
      	
      	cout<<"\nSelect The Items you want to buy: ";
      	cin>>menu_type_1;
      	
      		switch(menu_type_1){
      			
      			case 1:
      				cout<<"\n\n\t\tDAIRY AND EGGS";
      				
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)"<<endl;
      				cout<<"\n\n1."<<dairy[0]<<"\t\t\t\t\t"<<price_dairy[0];
      				cout<<"\n2."<<dairy[1]<<"\t\t\t\t\t"<<price_dairy[1];
      				cout<<"\n3."<<dairy[2]<<"\t\t\t\t\t"<<price_dairy[2];
      				cout<<"\n4."<<dairy[3]<<"\t\t\t\t\t"<<price_dairy[3];
      				cout<<"\n5."<<dairy[4]<<"\t\t\t\t\t"<<price_dairy[4];
      				cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn;
      				
      				if (yn == 'y' || yn=='Y'){
      					cout<<"Purchase List"<<endl;
      						cout<<"\n\n1."<<dairy[0]<<": ";
      						cin>>array_dairy[0];
      						
      						cout<<"\n2."<<dairy[1]<<": ";
      						cin>>array_dairy[1];
      						
      						cout<<"\n3."<<dairy[2]<<": ";
      						cin>>array_dairy[2];
      						
      						cout<<"\n4."<<dairy[3]<<": ";
      						cin>>array_dairy[3];
      						
      						cout<<"\n5."<<dairy[4]<<": ";
      						cin>>array_dairy[4];
      						
					  }
					  
					  cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont;
					  if(cont == 'y' || cont == 'Y'){
					  	goto grocery;
					  }
					  
					  else if (cont == 'n' || cont == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
      				break;
      				
      			case 2:
      				cout<<"BAKERY ITEMS";
      				
					cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)";
					
      			cout<<"\n\n1."<<bakery[0]<<"\t\t\t\t\t120 Rs";
      				cout<<"\n2."<<bakery[1]<<"\t\t\t\t\t80 Rs";
      				cout<<"\n3."<<bakery[2]<<"\t\t\t\t\t40 Rs";
      				cout<<"\n4."<<bakery[3]<<"\t\t\t\t\t50 Rs";
      				cout<<"\n5."<<bakery[4]<<"\t\t\t\t\t50 Rs";
      				cout<<"\n6."<<bakery[5]<<"\t\t\t\t\t40 Rs";
      				cout<<"\n7."<<bakery[6]<<"\t\t\t\t\t40 Rs";
      				cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn;
      				
      				if (yn == 'y' || yn=='Y'){
      					cout<<"Purchase List"<<endl;
      						cout<<"\n\n1."<<bakery[0]<<": ";
      						cin>>array_bakery[0];
      						
      						
      						cout<<"\n2."<<bakery[1]<<": ";
      						cin>>array_bakery[1];
      						
      						cout<<"\n3."<<bakery[2]<<": ";
      						cin>>array_bakery[2];
      						
      						cout<<"\n4."<<bakery[3]<<": ";
      						cin>>array_bakery[3];
      						
      						cout<<"\n5."<<bakery[4]<<": "; 
      						cin>>array_bakery[4];
      						
      						cout<<"\n6."<<bakery[5]<<": ";
      						cin>>array_bakery[5];
      						
      						cout<<"\n7."<<bakery[6]<<": ";
      						cin>>array_bakery[6];
      						
					  }
					  
					  cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont;
					  if(cont == 'y' || cont == 'Y'){
					  	goto grocery;
					  }
					  
					  else if (cont == 'n' || cont == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
      				
      				break;
      				
      			case 3:
      				cout<<"PANTRY STAPLES";
      				
					cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)";
      				cout<<"\n\n1."<<pantry[0]<<"120 Rs";
      			cout<<"\n2."<<pantry[1]<<"\t\t\t\t\t110 Rs";
      			cout<<"\n3."<<pantry[2]<<"\t\t\t\t\t150 Rs";
      			cout<<"\n4."<<pantry[3]<<"\t\t\t\t\t150 Rs";
      			cout<<"\n5."<<pantry[4]<<"\t\t\t\t\t150 Rs";
      			cout<<"\n6."<<pantry[5]<<"\t\t\t\t\t210 Rs";
      			cout<<"\n7."<<pantry[6]<<"\t\t\t\t\t170 Rs";
      			cout<<"\n8."<<pantry[7]<<"\t\t\t\t\t140 Rs";
      			cout<<"\n9."<<pantry[8]<<"\t\t\t\t\t150 Rs";
      			cout<<"\n10."<<pantry[9]<<"\t\t\t\t\t120 Rs";
      			cout<<"\n11."<<pantry[10]<<"\t\t\t\t\t130 Rs";
      				cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn;
      				
      				if (yn == 'y' || yn=='Y'){
      					cout<<"Purchase List"<<endl;
      						cout<<"\n\n1."<<pantry[0]<<": ";
      						cin>>array_pantry[0];
      						
      						cout<<"\n2."<<pantry[1]<<": ";
      						cin>>array_pantry[1];
      						
      						cout<<"\n3."<<pantry[2]<<": ";
      						cin>>array_pantry[2];
      						
      						cout<<"\n4."<<pantry[3]<<": ";
      						cin>>array_pantry[3];
      						
      						cout<<"\n5."<<pantry[4]<<": ";
      						cin>>array_pantry[4];
      						
      						cout<<"\n6."<<pantry[5]<<": ";
      						cin>>array_pantry[5];
      						
      						cout<<"\n7."<<pantry[6]<<": ";
      						cin>>array_pantry[6];
      						
      						cout<<"\n8."<<pantry[7]<<": ";
      						cin>>array_pantry[7];
      						
      						cout<<"\n9."<<pantry[8]<<": ";
      						cin>>array_pantry[8];
      						
      						cout<<"\n10."<<pantry[9]<<": ";
      						cin>>array_pantry[9];
      						
      						cout<<"\n11."<<pantry[10]<<": ";
      						cin>>array_pantry[10];		
					  }
					  
					  cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont;
					  if(cont == 'y' || cont == 'Y'){
					  	goto grocery;
					  }
					  
					  else if (cont == 'n' || cont == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
      			
      				break;
      				
      			case 4:
      				cout<<"CONDIMENTS";
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)";
      				cout<<"\n\n1."<<condiments[0]<<"\t\t\t\t\t90 Rs";
      				cout<<"\n2."<<condiments[1]<<"\t\t\t\t\t90 Rs";
      				cout<<"\n3."<<condiments[2]<<"\t\t\t\t\t90 Rs";
      				cout<<"\n4."<<condiments[3]<<"\t\t\t\t\t80 Rs";
      				cout<<"\n5."<<condiments[4]<<"\t\t\t\t\t130 Rs";
      				cout<<"\n6."<<condiments[5]<<"\t\t\t\t\t120 Rs";
      				cout<<"\n7."<<condiments[6]<<"\t\t\t\t\t150 Rs";
      				cout<<"\n8."<<condiments[7]<<"\t\t\t\t\t150 Rs";
      				cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn;
      				
      				if (yn == 'y' || yn=='Y'){
      					cout<<"Purchase List"<<endl;
      						cout<<"\n\n1."<<condiments[0]<<": ";
      						cin>>array_condiments[0];
      						
      						cout<<"\n2."<<condiments[1]<<": ";
      						cin>>array_condiments[1];
      						
      						cout<<"\n3."<<condiments[2]<<": ";
      						cin>>array_condiments[2];
      						
      						cout<<"\n4."<<condiments[3]<<": ";
      						cin>>array_condiments[3];
      						
      						cout<<"\n5."<<condiments[4]<<": ";
      						cin>>array_condiments[4];
      						
      						cout<<"\n6."<< condiments[5]<<": ";
      						cin>>array_condiments[5];
      						
      						cout<<"\n7."<< condiments[6]<<": ";
      						cin>>array_condiments[6];
      						
      						cout<<"\n8."<< condiments[7]<<": ";
      						cin>>array_condiments[7];
      						
					  }
					  
					  cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont;
					  if(cont == 'y' || cont == 'Y'){
					  	goto grocery;
					  }
					  
					  else if (cont == 'n' || cont == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
      				
      				break;
      				
      			case 5:
      				cout<<"CANNED GOODS";
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)";
      				cout<<"\n\n1."<<canned[0]<<"\t\t\t\t\t120 RS";
      				cout<<"\n2."<<canned[1]<<"\t\t\t\t\t120 Rs";
      				cout<<"\n3."<<canned[2]<<"\t\t\t\t\t130 Rs";
      				cout<<"\n4."<<canned[3]<<"\t\t\t\t\t140 Rs";
      				cout<<"\n5."<<canned[4]<<"\t\t\t\t\t140 Rs";
      				cout<<"\n6."<<canned[5]<<"\t\t\t\t\t170 Rs";
					cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn;
      				
      				if (yn == 'y' || yn=='Y'){
      					cout<<"Purchase List"<<endl;
      						cout<<"\n\n1."<<canned[0]<<": ";
      						cin>>array_canned[0];
      						
      						cout<<"\n2."<<canned[1]<<": ";
      						cin>>array_canned[1];
      						
      						cout<<"\n3."<<canned[2]<<": ";
      						cin>>array_canned[2];
      						
      						cout<<"\n4."<<canned[3]<<": ";
      						cin>>array_canned[3];
      						
      						cout<<"\n5."<<canned[4]<< ": ";
      						cin>>array_canned[4];
      						
      						cout<<"\n6."<<canned[5]<<": ";
      						cin>>array_canned[5];
      						
					  }
					  
					  cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont;
					  if(cont == 'y' || cont == 'Y'){
					  	goto grocery;
					  }
					  
					  else if (cont == 'n' || cont == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
      				
      				break;
      				
      			case 6:
      				cout<<"FROZEN FOODS";
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)";
      				cout<<"\n\n1."<<frozen[0]<<"\t\t\t\t\t200 Rs";
      				cout<<"\n2."<<frozen[1]<<"\t\t\t\t\t450 Rs";
      				cout<<"\n4."<<frozen[2]<<"\t\t\t\t\t140 Rs";
      				cout<<"\n3."<<frozen[3]<<"\t\t\t\t\t850 Rs";
      				cout<<"\n5."<<frozen[4]<<"\t\t\t\t\t250 Rs";
      				cout<<"\n6."<<frozen[5]<<"\t\t\t\t\t350 Rs";
      				cout<<"\n7."<<frozen[6]<<"\t\t\t\t\t400 Rs";
      				cout<<"\n8."<<frozen[7]<<"\t\t\t\t\t150 Rs";
      				cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn;
      				
      				if (yn == 'y' || yn=='Y'){
      					cout<<"Purchase List"<<endl;
      						cout<<"\n\n1."<<frozen[0]<<": ";
      						cin>>array_frozen[0];
      						
      						cout<<"\n2."<<frozen[1]<<": ";
      						cin>>array_frozen[1];
      						
      						cout<<"\n3."<<frozen[2]<<": ";
      						cin>>array_frozen[2];
      						
      						cout<<"\n4."<<frozen[3]<<": ";
      						cin>>array_frozen[3];
      						
      						cout<<"\n5."<<frozen[4]<< ": ";
      						cin>>array_frozen[4];
      						
      						cout<<"\n5."<<frozen[5]<<": ";
      						cin>>array_frozen[5];
      						
      						cout<<"\n5."<<frozen[6]<<": ";
							cin>>array_frozen[6];
      						
      						cout<<"\n5."<<frozen[7]<<": ";
      						cin>>array_frozen[7];
      						
					  }
					  
					  cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont;
					  if(cont == 'y' || cont == 'Y'){
					  	goto grocery;
					  }
					  
					  else if (cont == 'n' || cont == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
      				
      				break;
      				
      			case 7:
      				cout<<"Meat and Proteins";
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)";
      				cout<<"\n\n1."<<meat[0]<<"\t\t\t\t\t450 Rs";
      				cout<<"\n2."<<meat[1]<<"\t\t\t\t\t950 Rs";
      				cout<<"\n3."<<meat[2]<<"\t\t\t\t\t850 Rs";
      				cout<<"\n4."<<meat[3]<<"\t\t\t\t\t1050 Rs";
      				cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn;
      				
      				if (yn == 'y' || yn=='Y'){
      					cout<<"Purchase List"<<endl;
      						cout<<"\n\n1."<< meat[0]<<": ";
      						cin>>array_meat[0];
      						
      						cout<<"\n2."<<meat[1]<<": ";
      						cin>>array_meat[1];
      						
      						cout<<"\n3."<<meat[2]<<": ";
      						cin>>array_meat[2];
      						
      						cout<<"\n4."<<meat[3]<<": ";
      						cin>>array_meat[3];
      						
					  }
					  
					  cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont;
					  if(cont == 'y' || cont == 'Y'){
					  	goto grocery;
					  }
					  
					  else if (cont == 'n' || cont == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
      				
      				break;
      				
      			case 8:
      				
      				cout<<"BEVERAGES";
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)";
      				cout<<"\n\n1."<<drinks[0]<<"\t\t\t\t\t80 Rs";
      				cout<<"\n2."<<drinks[1]<<"\t\t\t\t\t150 Rs";
      				cout<<"\n3."<<drinks[2]<<"\t\t\t\t\t150 Rs";
      				cout<<"\n4."<<drinks[3]<<"\t\t\t\t\t60 Rs";
      				cout<<"\n5."<<drinks[4]<<"\t\t\t\t\t60 Rs";
      				cout<<"\n6."<<drinks[5]<<"\t\t\t\t\t40 Rs";
      				cout<<"\n7."<<drinks[6]<<"\t\t\t\t\t120 Rs";
      				cout<<"\n8."<<drinks[7]<<"\t\t\t\t\t150 Rs";
      				cout<<"\n9."<<drinks[8]<<"\t\t\t\t\t150 Rs";
      				cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn;
      				
      				if (yn == 'y' || yn=='Y'){
      					cout<<"Purchase List"<<endl;
      					
      						cout<<"\n\n1."<< drinks[0]<<": ";
      						cin>>array_drinks[0];

							cout<<"\n\n2."<< drinks[1]<<": ";
      						cin>>array_drinks[1];
      						
      						cout<<"\n3."<< drinks[2]<<": ";
      						cin>>array_drinks[2];
      						
      						cout<<"\n4."<< drinks[3]<<": ";
      						cin>>array_drinks[3];
      						
      						cout<<"\n5."<<drinks[4]<<": ";
      						cin>>array_drinks[4];
      						
      						cout<<"\n6."<< drinks[5]<<": ";
      						cin>>array_drinks[5];
      						
      						cout<<"\n7."<<drinks[6]<<": ";
      						cin>>array_drinks[6];
      						
      						cout<<"\n8."<<drinks[7]<<": ";
      						cin>>array_drinks[7];
      						
      						cout<<"\n9."<<drinks[8]<<": ";
      						cin>>array_drinks[8];
      						
					  }
					  
					  cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont;
					  if(cont == 'y' || cont == 'Y'){
					  	goto grocery;
					  }
					  
					  else if (cont == 'n' || cont == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
      				
      				break;
      				
      			case 9:
      				cout<<"SNACKS";
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)";
      				cout<<"\n\n1."<<snacks[0]<<"\t\t\t\t\t80 Rs";
      				cout<<"\n2."<<snacks[1]<<"\t\t\t\t\t80 Rs";
      				cout<<"\n3."<<snacks[2]<<"\t\t\t\t\t120 Rs";
      				cout<<"\n4."<<snacks[3]<<"\t\t\t\t\t150 Rs";
      				cout<<"\n5."<<snacks[4]<<"\t\t\t\t\t180 Rs";
      				cout<<"\n6."<<snacks[5]<<"\t\t\t\t\t180 Rs";
      				cout<<"\n7."<<snacks[6]<<"\t\t\t\t\t60 Rs";
      				cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn;
      				
      				if (yn == 'y' || yn=='Y'){
      					cout<<"Purchase List"<<endl;
      					
      						cout<<"\n\n1."<<snacks[0]<<": ";
      						cin>>array_snacks[0];
      						
      						cout<<"\n2."<<snacks[1]<<": ";
      						cin>>array_snacks[1];
      						
      						cout<<"\n3."<<snacks[2]<<": ";
      						cin>>array_snacks[2];
      						
      						cout<<"\n4."<<snacks[3]<<": ";
      						cin>>array_snacks[3];
      						
      						cout<<"\n5."<<snacks[4]<<": ";
      						cin>>array_snacks[4];
      						
      						cout<<"\n6."<<snacks[5]<<": ";
      						cin>>array_snacks[5];
      						
      						cout<<"\n7."<<snacks[6]<<": ";
      						cin>>array_snacks[6];
      						
					  }
					  
					  cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont;
					  if(cont == 'y' || cont == 'Y'){
					  	goto grocery;
					  }
					  
					  else if (cont == 'n' || cont == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
      				
      				break;
      				
      			case 10:
      				cout<<"SWEETS";
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)";
      				cout<<"\n\n1."<<sweets[0]<<"\t\t\t\t\t120 Rs";
      				cout<<"\n2."<<sweets[1]<<"\t\t\t\t\t10 Rs";
      				cout<<"\n3."<<sweets[2]<<"\t\t\t\t\t40 Rs";
      				cout<<"\n4."<<sweets[3]<<"\t\t\t\t\t850 Rs";
      				cout<<"\n5."<<sweets[4]<<"\t\t\t\t\t60 Rs";
      				cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn;
      				
      				if (yn == 'y' || yn=='Y'){
      					cout<<"Purchase List"<<endl;
      					
      						cout<<"\n\n1."<<sweets[0]<<": ";
      						cin>>array_sweets[0];
      						
      						cout<<"\n2."<< sweets[1]<<": ";
      						cin>>array_sweets[1];
      						
      						cout<<"\n3."<<sweets[2]<<": ";
      						cin>>array_sweets[2];
      						
      						cout<<"\n4."<<sweets[3]<<": ";
      						cin>>array_sweets[3];
      						
      						cout<<"\n5."<<sweets[4]<<": ";
      						cin>>array_sweets[4];
      						
					  }
					  
					  cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont;
					  if(cont == 'y' || cont == 'Y'){
					  	goto grocery;
					  }
					  
					  else if (cont == 'n' || cont == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
      				
			   	break;
      				
      			case 11:
      				cout<<"CLEANING AND HOUSEHOLD";
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)";
      				cout<<"\n\n1."<<cleaning[0]<<"\t\t\t\t\t200 Rs";
      				cout<<"\n2."<<cleaning[1]<<"\t\t\t\t\t250 Rs";
      				cout<<"\n3."<<cleaning[2]<<"\t\t\t\t\t300 Rs";
      				cout<<"\n4."<<cleaning[3]<<"\t\t\t\t\t300 Rs";
      				cout<<"\n5."<<cleaning[4]<<"\t\t\t\t\t250 Rs";
      				cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn;
      				
      				if (yn == 'y' || yn=='Y'){
      					cout<<"Purchase List"<<endl;
      						
      						cout<<"\n\n1."<<cleaning[0]<<": ";
      						cin>>array_cleaning[0];
      						
      						cout<<"\n2."<<cleaning[1]<<": ";
      						cin>>array_cleaning[1];
      						
      						cout<<"\n3."<< cleaning[2]<<": ";
      						cin>>array_cleaning[2];
      						
      						cout<<"\n4."<<cleaning[3]<<": ";
      						cin>>array_cleaning[3];
      						
      						cout<<"\n5."<<cleaning[4]<<": ";
      						cin>>array_cleaning[4];
      						
					  }
					  
					  cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont;
					  if(cont == 'y' || cont == 'Y'){
					  	goto grocery;
					  }
					  
					  else if (cont == 'n' || cont == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
      				
      				break;
      				
      			default:
      				cout<<"Please choose the correct option!!";
			  
	  }	  
}

	 else if(menu_type==2)
 {
      	
        food:
      	cout<<"\n\tWelcome to the FOOD Items ";
      	
      	cout<<"\n\nWe have the Spectial types of food items for you";
      	
      	cout<<"\n\n1.PUNJABI FOOD"<<endl;
      	cout<<"2.ITALIAN FOOD"<<endl;
      	cout<<"3.INDIAN FOOD"<<endl;
      	cout<<"4.CHINESE FOOD"<<endl;
      	cout<<"5.VEGETERIAN FOOD"<<endl;
      	cout<<"6.FAST FOOD"<<endl;
      	cout<<"7.SEAFOOD"<<endl;
      	cout<<"8.COLD DRINKS"<<endl;
      	cout<<"9.HOT DRINKS"<<endl;
      	
      	cout<<"\nSelect any type of FOOD  you want to eat: ";
      	cin>>menu_type_2;
      	
      		switch(menu_type_2){
			  
			
      			
      			case 1:
      				cout<<"\n\n\t\tPunjabi Food";
      				
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)";
      				cout<<"\n\n1."<<punjabi[0]<<"\t\t\t\t\tRs: "<<price_punjabi[0];
      				cout<<"\n2."<<punjabi[1]<<"\t\t\t\t\tRs: "<<price_punjabi[1];
      				cout<<"\n3."<<punjabi[2]<<"\t\t\t\t\tRs: "<<price_punjabi[2];
      				cout<<"\n4."<<punjabi[3]<<"\t\t\t\t\tRs: "<<price_punjabi[3];
      				cout<<"\n5."<<punjabi[4]<<"\t\t\t\t\tRs: "<<price_punjabi[4];
      				cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn1;
      				
      				if (yn1 == 'y' || yn1=='Y'){
      					cout<<"Purchase List"<<endl;
      						cout<<"\n\n1."<<punjabi[0]<<": ";
      						cin>>array_punjabi[0];
      						
      						cout<<"\n2."<<punjabi[1]<<": ";
      						cin>>array_punjabi[1];
      						
      						cout<<"\n3."<<punjabi[2]<<": ";
      						cin>>array_punjabi[2];
      						
      						cout<<"\n4."<<punjabi[3]<<": ";
      						cin>>array_punjabi[3];
      						
      						cout<<"\n5."<<punjabi[4]<<": ";
      						cin>>array_punjabi[4];
      						
					  }
					   cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont1;
					  if(cont1 == 'y' || cont1 == 'Y'){
					  	goto food;
					  }
					  
					  else if (cont1 == 'n' || cont1 == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
      				break;
			
			case 2:
      				cout<<"\n\n\t\tItalian Food";
      				
      				cout<<"\n\nITEMS\t\t\t\tRATE(RS)";
      				cout<<"\n\n1."<<italian[0]<<"\t\t\t\t\tRs: "<<price_italian[0];
      				cout<<"\n2."<<italian[1]<<"\t\t\t\t\tRs: "<<price_italian[1];
      				cout<<"\n3."<<italian[2]<<"\t\t\t\t\tRs: "<<price_italian[2];
      				cout<<"\n4."<<italian[3]<<"\t\t\t\t\tRs: "<<price_italian[3];
      				cout<<"\n5."<<italian[4]<<"\t\t\t\t\tRs: "<<price_italian[4];
      				cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn1;
      				
      				if (yn1 == 'y' || yn1=='Y'){
      					cout<<"Purchase List"<<endl;
      						cout<<"\n\n1."<<italian[0]<<": ";
      						cin>>array_italian[0];
      						
      					cout<<"\n2."<<italian[1]<<": ";
      						cin>>array_italian[1];
      						
      						cout<<"\n3."<<italian[2]<<": ";
      						cin>>array_italian[2];
      						
      						cout<<"\n4."<<italian[3]<<": ";
      						cin>>array_italian[3];
      						
      						cout<<"\n5."<<italian[4]<<": ";
      						cin>>array_italian[4];		
					  }

					   cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont1;
					  
					  if(cont1 == 'y' || cont1 == 'Y'){
					  	goto food;
					  }
					  
					  else if (cont1 == 'n' || cont1 == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
      				break;
      				
					case 3:
      				cout<<"\n\n\t\tIndian Food";
      				
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)";
      			cout<<"\n\n1."<<indian[0]<<"\t\t\t\t\tRs: "<<price_indian[0];
      				cout<<"\n2."<<indian[1]<<"\t\t\t\t\tRs: "<<price_indian[1];
      				cout<<"\n3."<<indian[2]<<"\t\t\t\t\tRs: "<<price_indian[2];
      				cout<<"\n4."<<indian[3]<<"\t\t\t\t\tRs: "<<price_indian[3];
      				cout<<"\n5."<<indian[4]<<"\t\t\t\t\tRs: "<<price_indian[4];
      				cout<<"\n6."<<indian[5]<<"\t\t\t\t\tRs: "<<price_indian[5];
      				cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn1;
      				
      				if (yn1 == 'y' || yn1=='Y'){
      					cout<<"Purchase List"<<endl;
      						cout<<"\n\n1."<<indian[0]<<": ";
      						cin>>array_indian[0];
      						
      						cout<<"\n2."<<indian[1]<<": ";
      						cin>>array_indian[1];
      						
      						cout<<"\n3."<<indian[2]<<": ";
      						cin>>array_indian[2];
      						
      						cout<<"\n4."<<indian[3]<<": ";
      						cin>>array_indian[3];
      						
							cout<<"\n5."<<indian[4]<<": ";
      						cin>>array_indian[4];
      						
      						cout<<"\n6."<<indian[5]<<": ";
      						cin>>array_indian[5];
      						
					  }
					   cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont1;
					  if(cont1 == 'y' || cont1 == 'Y'){
					  	goto food;
					  }
					  
					  else if (cont1 == 'n' || cont1 == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
      				break;
      				
					case 4:
						
      				cout<<"\n\n\t\tChinese Food";
      				
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)";
      				cout<<"\n\n1."<<chinese[0]<<"\t\t\t\t\tRs: "<<price_chinese[0];
      				cout<<"\n2."<<chinese[1]<<"\t\t\t\t\tRs: "<<price_chinese[1];
      				cout<<"\n3."<<chinese[2]<<"\t\t\t\t\tRs: "<<price_chinese[2];
      				cout<<"\n4."<<chinese[3]<<"\t\t\t\t\tRs: "<<price_chinese[3];
      				cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn1;
      				
      				if (yn1 == 'y' || yn1=='Y'){
      					cout<<"Purchase List"<<endl;
      						cout<<"\n\n1."<<chinese[0]<<": ";
      						cin>>array_chinese[0];
      						
      						cout<<"\n2."<<chinese[1]<<": ";
      						cin>>array_chinese[1];
      						
      						cout<<"\n3."<<chinese[2]<<": ";
      						cin>>array_chinese[2];
      						
      						cout<<"\n4."<<chinese[3]<<": ";
      						cin>>array_chinese[3];
      							
					  }

					   cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont1;
					  
					  if(cont1 == 'y' || cont1 == 'Y'){
					  	goto food;
					  }
					  
					  else if (cont1 == 'n' || cont1 == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
					  
      				break;
      				
					case 5:
      				cout<<"\n\n\t\tVegeterian Food";
      				
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)";
      				cout<<"\n\n1."<<vegeterian[0]<<"\t\t\t\t\tRs: "<<price_vegeterian[0];
      				cout<<"\n2."<<vegeterian[1]<<"\t\t\t\t\tRs: "<<price_vegeterian[1];
      				cout<<"\n3."<<vegeterian[2]<<"\t\t\t\t\tRs: "<<price_vegeterian[2];
      				cout<<"\n4."<<vegeterian[3]<<"\t\t\t\t\tRs: "<<price_vegeterian[3];
      				cout<<"\n5."<<vegeterian[4]<<"\t\t\t\t\tRs: "<<price_vegeterian[4];
      				cout<<"\n6."<<vegeterian[5]<<"\t\t\t\t\tRs: "<<price_vegeterian[5];
      				cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn1;
      				
      				if (yn1 == 'y' || yn1=='Y'){
      					cout<<"Purchase List"<<endl;
      						cout<<"\n\n1."<<vegeterian[0]<<": ";
      						cin>>array_vegeterian[0];
      						
      						cout<<"\n2."<<vegeterian[1]<<": ";
      						cin>>array_vegeterian[1];
      						
      						cout<<"\n3."<<vegeterian[2]<<": ";
      						cin>>array_vegeterian[2];
      						
      						cout<<"\n4."<<vegeterian[3]<<": ";
      						cin>>array_vegeterian[3];
      						
							cout<<"\n5."<<vegeterian[4]<<": ";
      						cin>>array_vegeterian[4];
      						
      						cout<<"\n6."<<vegeterian[5]<<": ";
      						cin>>array_vegeterian[5];
      						
					  }
					   cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont1;
					  if(cont1 == 'y' || cont1 == 'Y'){
					  	goto food;
					  }
					  
					  else if (cont1 == 'n' || cont1 == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
      				break;
					case 6:
      				cout<<"\n\n\t\tFast Food";
      				
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)";
      				cout<<"\n\n1."<<fast[0]<<"\t\t\t\t\tRs: "<<price_fast[0];
      				cout<<"\n2."<<fast[1]<<"\t\t\t\t\tRs: "<<price_fast[1];
      				cout<<"\n3."<<fast[2]<<"\t\t\t\t\tRs: "<<price_fast[2];
      				cout<<"\n4."<<fast[3]<<"\t\t\t\t\tRs: "<<price_fast[3];
      				cout<<"\n5."<<fast[4]<<"\t\t\t\t\tRs: "<<price_fast[4];
      				cout<<"\n6."<<fast[5]<<"\t\t\t\t\tRs: "<<price_fast[5];
      				cout<<"\n7."<<fast[6]<<"\t\t\t\t\tRs: "<<price_fast[6];
      				cout<<"\n8."<<fast[7]<<"\t\t\t\t\tRs: "<<price_fast[7];
      				cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn1;
      				
      				if (yn1 == 'y' || yn1=='Y'){
      					cout<<"Purchase List"<<endl;
      						cout<<"\n\n1."<<fast[0]<<": ";
      						cin>>array_fast[0];
      						
      						cout<<"\n2."<<fast[1]<<": ";
      						cin>>array_fast[1];
      						
      						cout<<"\n3."<<fast[2]<<": ";
      						cin>>array_fast[2];
      						
      						cout<<"\n4."<<fast[3]<<": ";
      						cin>>array_fast[3];
      						
							cout<<"\n5."<<fast[4]<<": ";
      						cin>>array_fast[4];
      						
      						cout<<"\n6."<<fast[5]<<": ";
      						cin>>array_fast[5];

							cout<<"\n7."<<fast[6]<<": ";
      						cin>>array_fast[6];

							cout<<"\n8."<<fast[7]<<": ";
      						cin>>array_fast[7];
      						
					  }
					   cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont1;
					  if(cont1 == 'y' || cont1 == 'Y'){
					  	goto food;
					  }
					  
					  else if (cont1 == 'n' || cont1 == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
      				break;
					case 7:
      				cout<<"\n\n\t\tSea Food";
      				
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)";
      				cout<<"\n\n1."<<seafood[0]<<"\t\t\t\t\tRs: "<<price_seafood[0];
      				cout<<"\n2."<<seafood[1]<<"\t\t\t\t\tRs: "<<price_seafood[1];
      				cout<<"\n3."<<seafood[2]<<"\t\t\t\t\tRs: "<<price_seafood[2];
      				cout<<"\n4."<<seafood[3]<<"\t\t\t\t\tRs: "<<price_seafood[3];
      				cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn1;
      				
      				if (yn1 == 'y' || yn1=='Y'){
      					cout<<"Purchase List"<<endl;
      						cout<<"\n\n1."<<seafood[0]<<": ";
      						cin>>array_seafood[0];
      						
      						cout<<"\n2."<<seafood[1]<<": ";
      						cin>>array_seafood[1];
      						
      						cout<<"\n3."<<seafood[2]<<": ";
      						cin>>array_seafood[2];
      						
      						cout<<"\n4."<<seafood[3]<<": ";
      						cin>>array_seafood[3];
      							
					  }

					   cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont1;
					  
					  if(cont1 == 'y' || cont1 == 'Y'){
					  	goto food;
					  }
					  
					  else if (cont1 == 'n' || cont1 == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
      				break;
					case 8:
      				cout<<"\n\n\t\tCold Drinks";
      				
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)";
      			    cout<<"\n\n1."<<cold_drinks[0]<<"\t\t\t\t\tRs: "<<price_cold_drinks[0];
      				cout<<"\n2."<<cold_drinks[1]<<"\t\t\t\t\tRs: "<<price_cold_drinks[1];
      				cout<<"\n3."<<cold_drinks[2]<<"\t\t\t\t\tRs: "<<price_cold_drinks[2];
      				cout<<"\n4."<<cold_drinks[3]<<"\t\t\t\t\tRs: "<<price_cold_drinks[3];
      				cout<<"\n5."<<cold_drinks[4]<<"\t\t\t\t\tRs: "<<price_cold_drinks[4];
      				cout<<"\n6."<<cold_drinks[5]<<"\t\t\t\t\tRs: "<<price_cold_drinks[5];
      				cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn1;
      				
      				if (yn1 == 'y' || yn1=='Y'){
      					cout<<"Purchase List"<<endl;
      					cout<<"\n\n1."<<cold_drinks[0]<<": ";
      						cin>>array_cold_drinks[0];
      						
      						cout<<"\n2."<<cold_drinks[1]<<": ";
      						cin>>array_cold_drinks[1];
      						
      						cout<<"\n3."<<cold_drinks[2]<<": ";
      						cin>>array_cold_drinks[2];
      						
      						cout<<"\n4."<<cold_drinks[3]<<": ";
      						cin>>array_cold_drinks[3];
      						
							cout<<"\n5."<<cold_drinks[4]<<": ";
      						cin>>array_cold_drinks[4];
      						
      						cout<<"\n6."<<cold_drinks[5]<<": ";
      						cin>>array_cold_drinks[5];
      						
					  }
					   cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont1;
					  if(cont1 == 'y' || cont1 == 'Y'){
					  	goto food;
					  }
					  
					  else if (cont1 == 'n' || cont1 == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
      				break;
					case 9:
      				cout<<"\n\n\t\tHold Drinks";
      				
      				cout<<"\n\nITEMS\t\t\t\t\tRATE(RS)";
      				cout<<"\n\n1."<<hot_drinks[0]<<"\t\t\t\t\tRs: "<<price_hot_drinks[0];
      				cout<<"\n2."<<hot_drinks[1]<<"\t\t\t\t\tRs: "<<price_hot_drinks[1];
      				cout<<"\n3."<<hot_drinks[2]<<"\t\t\t\t\tRs: "<<price_hot_drinks[2];
      				cout<<"\n4."<<hot_drinks[3]<<"\t\t\t\t\tRs: "<<price_hot_drinks[3];
      				cout<<"\n5."<<hot_drinks[4]<<"\t\t\t\t\tRs: "<<price_hot_drinks[4];
      				cout<<"\n6."<<hot_drinks[5]<<"\t\t\t\t\tRs: "<<price_hot_drinks[5];
      				cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N): ";
      				cin>>yn1;
      				
      				if (yn1 == 'y' || yn1=='Y'){
      					cout<<"Purchase List"<<endl;
      						cout<<"\n\n1."<<hot_drinks[0]<<": ";
      						cin>>array_hot_drinks[0];
      						
      						cout<<"\n2."<<hot_drinks[1]<<": ";
      						cin>>array_hot_drinks[1];
      						
      						cout<<"\n3."<<hot_drinks[2]<<": ";
      						cin>>array_hot_drinks[2];
      						
      						cout<<"\n4."<<hot_drinks[3]<<": ";
      						cin>>array_hot_drinks[3];
      						
							cout<<"\n5."<<hot_drinks[4]<<": ";
      						cin>>array_hot_drinks[4];
      						
      						cout<<"\n6."<<hot_drinks[5]<<": ";
      						cin>>array_hot_drinks[5];
      						
					  }
					   cout<<"\n\nDo you want to continue shopping(Y/N): ";
					  cin>>cont1;
					  if(cont1 == 'y' || cont1 == 'Y'){
					  	goto food;
					  }
					  
					  else if (cont1 == 'n' || cont1 == 'N'){
					  	goto bill;
					  }
					  
					  else{
					  	cout<<"\nEnter Y for yes and N for NO.";
					  }
      				break;
      				
      				default:
      					cout<<"Please enter valid input"<<endl;
      					break;
					
			}
		}   


bill:

	cout<<"\n===============================================================================";

	cout<<"\n\t\t\t\tTotal bill:";

	cout<<"\n===============================================================================";

	for (int counter=0; counter<5; counter++){

	if (array_dairy[counter]>0){

		cout<<"\n\n"<<dairy[counter]<<"\t\t\t\t\t\t"<<array_dairy[counter]<<"\t\t\t\t\t\tRs:"<<price_dairy[counter]*array_dairy[counter];
	}
	}
	
	for (int counter=0; counter<7; counter++){
		
		if (array_bakery[counter]>0){
			
			cout<<"\n\n"<<bakery[counter]<<"\t\t\t\t\t\t"<<array_bakery[counter]<<"\t\t\t\t\t\tRs:"<<price_bakery[counter]*array_bakery[counter];
		}
	}

	for (int counter=0; counter<11; counter++){

	if (array_pantry[counter]>0){

		cout<<"\n\n"<<pantry[counter]<<"\t\t\t\t"<<array_pantry[counter]<<"\t\t\t\tRs:"<<price_pantry[counter]*array_pantry[counter];
	}
	}
	

	for (int counter=0; counter<8; counter++){

	if (array_condiments[counter]>0){

		cout<<"\n\n"<<condiments[counter]<<"\t\t\t\t"<<array_condiments[counter]<<"\t\t\t\tRs:"<<price_condiments[counter]*array_condiments[counter];
	}
	}


	for (int counter=0; counter<5; counter++){

	if (array_canned[counter]>0){

		cout<<"\n\n"<<canned[counter]<<"\t\t\t\t"<<array_canned[counter]<<"\t\t\t\tRs:"<<price_canned[counter]*array_canned[counter];
	}
	}
	
	for (int counter=0; counter<8; counter++){

	if (array_frozen[counter]>0){

		cout<<"\n\n"<<frozen[counter]<<"\t\t\t"<<array_frozen[counter]<<"\t\t\tRs:"<<price_frozen[counter]*array_frozen[counter];
	}	
	}
	
	
	for (int counter=0; counter<4; counter++){

	if (array_meat[counter]>0){

		cout<<"\n\n"<<meat[counter]<<"\t\t\t\t"<<array_meat[counter]<<"\t\t\t\tRs:"<<price_meat[counter]*array_meat[counter];
	}
	}


	for (int counter=0; counter<9; counter++){

	if (array_drinks[counter]>0){

		cout<<"\n\n"<<drinks[counter]<<"\t\t\t\t"<<array_drinks[counter]<<"\t\t\t\tRs:"<<price_drinks[counter]*array_drinks[counter];
	}
	}
	
	
	for (int counter=0; counter<7; counter++){

	if (array_snacks[counter]>0){

		cout<<"\n\n"<<snacks[counter]<<"\t\t\t\t"<<array_snacks[counter]<<"\t\t\t\tRs:"<<price_snacks[counter]*array_snacks[counter];
	}
	}

	for (int counter=0; counter<5; counter++){

	if (array_sweets[counter]>0){

		cout<<"\n\n"<<sweets[counter]<<"\t\t\t\t"<<array_sweets[counter]<<"\t\t\t\tRs:"<<price_sweets[counter]*array_sweets[counter];
	}
	}

	for (int counter=0; counter<5; counter++){

	if (array_cleaning[counter]>0){

		cout<<"\n\n"<<cleaning[counter]<<"\t\t\t\t"<<array_cleaning[counter]<<"\t\t\t\tRs:"<<price_cleaning[counter]*array_cleaning[counter];
	}
	}
	
	for (int counter=0; counter<5; counter++){

	if (array_punjabi[counter]>0){

		cout<<"\n\n"<<punjabi[counter]<<"\t\t\t\t\t\t"<<array_punjabi[counter]<<"\t\t\t\t\t\tRs:"<<price_punjabi[counter]*array_punjabi[counter];
	}
	}

	for (int counter=0; counter<5; counter++){

	if (array_italian[counter]>0){

		cout<<"\n\n"<<italian[counter]<<"\t\t\t\t"<<array_italian[counter]<<"\t\t\t\tRs:"<<price_italian[counter]*array_italian[counter];
	}
	}
	

	for (int counter=0; counter<6; counter++){

	if (array_indian[counter]>0){

		cout<<"\n\n"<<indian[counter]<<"\t\t\t\t"<<array_indian[counter]<<"\t\t\t\tRs:"<<price_indian[counter]*array_indian[counter];
	}
	}


	for (int counter=0; counter<4; counter++){

	if (array_chinese[counter]>0){

		cout<<"\n\n"<<chinese[counter]<<"\t\t\t\t"<<array_chinese[counter]<<"\t\t\t\tRs:"<<price_chinese[counter]*array_chinese[counter];
	}
	}
	
	for (int counter=0; counter<6; counter++){

	if (array_vegeterian[counter]>0){

		cout<<"\n\n"<<vegeterian[counter]<<"\t\t\t"<<array_vegeterian[counter]<<"\t\t\tRs:"<<price_vegeterian[counter]*array_vegeterian[counter];
	}	
	}
	
	
	for (int counter=0; counter<8; counter++){

	if (array_fast[counter]>0){

		cout<<"\n\n"<<fast[counter]<<"\t\t\t\t"<<array_fast[counter]<<"\t\t\t\tRs:"<<price_fast[counter]*array_fast[counter];
	}
	}


	for (int counter=0; counter<4; counter++){

	if (array_seafood[counter]>0){

		cout<<"\n\n"<<seafood[counter]<<"\t\t\t\t"<<array_seafood[counter]<<"\t\t\t\tRs:"<<price_seafood[counter]*array_seafood[counter];
	}
	}
	
	
	for (int counter=0; counter<6; counter++){

	if (array_cold_drinks[counter]>0){

		cout<<"\n\n"<<cold_drinks[counter]<<"\t\t\t\t"<<array_cold_drinks[counter]<<"\t\t\t\tRs:"<<price_cold_drinks[counter]*array_cold_drinks[counter];
	}
	}

	for (int counter=0; counter<6; counter++){

	if (array_hot_drinks[counter]>0){

		cout<<"\n\n"<<hot_drinks[counter]<<"\t\t\t\t"<<array_hot_drinks[counter]<<"\t\t\t\tRs:"<<price_hot_drinks[counter]*array_hot_drinks[counter];
	}
	}

	sum=0;
	total=0;

	for (int counter=0; counter<5; counter++){
		
		sum+=array_dairy[counter];
		total+=(array_dairy[counter]*price_dairy[counter]);
	}
	
	for (int counter=0; counter<7; counter++){
		
		sum+=array_bakery[counter];
		total+=(array_bakery[counter]*price_bakery[counter]);
	}
	
	for (int counter=0; counter<11; counter++){
		
		sum+=array_pantry[counter];
		total+=(array_pantry[counter]*price_pantry[counter]);
	}
	
	for (int counter=0; counter<8; counter++){
		
		sum+=array_condiments[counter];
		total+=(array_condiments[counter]*price_condiments[counter]);
	}
	
	for (int counter=0; counter<5; counter++){
		
		sum+=array_canned[counter];
		total+=(array_canned[counter]*price_canned[counter]);
	}
	
	for (int counter=0; counter<8; counter++){
		
		sum+=array_frozen[counter];
		total+=(array_frozen[counter]*price_frozen[counter]);
	}
	
	for (int counter=0; counter<4; counter++){
		
		sum+=array_meat[counter];
		total+=(array_meat[counter]*price_meat[counter]);
	}
	
	for (int counter=0; counter<9; counter++){
		
		sum+=array_drinks[counter];
		total+=(array_drinks[counter]*price_drinks[counter]);
	}
	
	for (int counter=0; counter<7; counter++){
		
		sum+=array_snacks[counter];
		total+=(array_snacks[counter]*price_snacks[counter]);
	}
	
	for (int counter=0; counter<5; counter++){
		
		sum+=array_sweets[counter];
		total+=(array_sweets[counter]*price_sweets[counter]);
	}
	
	for (int counter=0; counter<5; counter++){
		
		sum+=array_cleaning[counter];
		total+=(array_cleaning[counter]*price_cleaning[counter]);
	}
	
	for (int counter=0; counter<5; counter++){
		
		sum+=array_punjabi[counter];
		total+=(array_punjabi[counter]*price_punjabi[counter]);
	}
	
	for (int counter=0; counter<5; counter++){
		
		sum+=array_italian[counter];
		total+=(array_italian[counter]*price_italian[counter]);
	}
	
	for (int counter=0; counter<6; counter++){
		
		sum+=array_indian[counter];
		total+=(array_indian[counter]*price_indian[counter]);
	}
	
	for (int counter=0; counter<4; counter++){
		
		sum+=array_chinese[counter];
		total+=(array_chinese[counter]*price_chinese[counter]);
	}
	
	for (int counter=0; counter<6; counter++){
		
		sum+=array_vegeterian[counter];
		total+=(array_vegeterian[counter]*array_vegeterian[counter]);
	}
	
	for (int counter=0; counter<8; counter++){
		
		sum+=array_fast[counter];
		total+=(array_fast[counter]*price_fast[counter]);
	}
	
	for (int counter=0; counter<4; counter++){
		
		sum+=array_seafood[counter];
		total+=(array_seafood[counter]*price_seafood[counter]);
	}
	
	for (int counter=0; counter<6; counter++){
		
		sum+=array_cold_drinks[counter];
		total+=(array_cold_drinks[counter]*price_cold_drinks[counter]);
	}
	
	for (int counter=0; counter<6; counter++){
		
		sum+=array_hot_drinks[counter];
		total+=(array_hot_drinks[counter]*price_hot_drinks[counter]);
	}
	
	cout<<"\n===============================================================================";
    cout<<"\nTOTAL:"<<"\t\t\t\t"<<sum<<"\t\t\t\tRs."<<total;
	cout<<"\n==============================================================================="<<endl<<endl;
	
	string date;
	cout<<"Please enter today's date"<<endl;
	cin>>date;
	cout<<endl<<endl<<endl;
	
	system("pause");
	system("cls");
	validation();
	ofstream write;
	write.open("Bill.txt", ios::app);
	write<<date<<endl;
	write<<"User has bought "<<sum<<" items totaling:"<<total<<"Rs"<<endl<<endl;
	return 0;
	break;
}
case 2:
	{
	system("cls");
	cout<<endl<<endl;
	cout<<"\t\t\t    =============================================================" ; 
	cout<<"\n\t\t\t\t\t\t  CANTEEN DETAILS";
	cout<<"\n\t\t\t    =============================================================" ;
	cout<<"\n\n\t\t\t\t#  CANTEEN WILL BE OPENED FROM 7 AM TO 2 AM";
    cout<<"\n\n\t\t\t\t#  GOODS ONCE SOLD WILL NOT BE EXCHANGED/REPLACED";
    cout<<"\n\n\t\t\t\t#  TAKE YOUR SMART CARD WITH YOU";
    cout<<"\n\n\t\t\t\t#  COLLECT YOUR SMART CARD & BILL AFTER PAYMENT";
    cout<<"\n\n\t\t\t\t#  DO NOT BREAK ANY MART ITEMS";
    cout<<"\n\n\n\n If you want to go back Home page press Y"<<endl;
    cin>>back;
			if((back=='y')||(back=='Y'))
			{
				goto home_page;
			}
			else
			{
				return 0;
			}
    return 0;
	break;

}

	case 3:{
		
	
	system("cls");  
    
	FeedbackData data;
	collect_feedback(data);
	    return 0;
    	break;
}
    

	default:
		cout<<"Kindly Select The Right Item.";

    }


    }
				
	
			
			else{
				
			cout<<"Your password is incorrect. Please try again."<<endl;
			cout<<"You have "<<counter-1<<" tries remaining"<<endl<<endl;
			read.close();
			
			}
		}
		
		else{
			
			cout<<"Your username is incorrect. Please try again."<<endl;
			cout<<"You have "<<counter-1<<" tries remaining"<<endl<<endl;
			read.close();
			
		}
		
	}	
}



int main(){
	
	struct user_admin{
		int check=0;
		int direction=0;
	};
    user_admin enter ;
    cout<<"Would you like to access admin side or client side. Press '1' for admin. Press '2' for client"<<endl;
    cin>>enter.direction;
    cout<<endl;

if (enter.direction==1){


cout<<"Would you like to login or signup? Press '1' for signup, Press '2' for login"<<endl;
cin>>enter.check;
cout<<endl;

if (enter.check==1){
	
	admin_signup();
}

else if (enter.check==2){
	
	admin_login();
}

else {
	
	cout<<"Please enter valid input";
}

}

else if (enter.direction==2){
	
cout<<"Would you like to login or signup? Press '1' for signup, Press '2' for login"<<endl;
cin>>enter.check;
cout<<endl;

if (enter.check==1){
	
	user_signup();
	
}

else if (enter.check==2){
	
	user_login();
	cout<<endl<<endl;
}

else {
	
	cout<<"Please enter valid input";
}	
}  

}

