//HEADER FILES
#include<iostream> 
#include<cstring> 
#include<iomanip> 
#include<fstream> 
using namespace std;
//CLASS 
class Fee_Structure
{
	//DECLARING CLASS PROPERTIES
	private:
	int Examination_Fee;
	int Tuition_Fee;
	char Student_name[45];
	char Student_Registration_Number[15];
	char Father_name[32];
	char Department[15];
	char Class[35];
	int Security_Fee;
	int Hostel_Dues;
	int Fines;
	float Total;
	//DECLARING THE ATTRIBUTES FOR THE UPDATE FUNCTION
	int Examination_Fee_M;
	int Tuition_Fee_M;
	char Student_name_M[45];
	char Student_Registration_NumberM[15];
	char Father_name_M[32];
	char Department_M[15];
	char Class_M[35];
	int Security_Fee_M;
	int Hostel_Dues_M;
	int Fines_M;
	
	//DECLARING PUBLIC FUNCTIONS
	public:
		void create_the_record();
		void update_record();
		void Deletee();
		void search();
		void showing();
		void password();
		void name(char []);
		char* getrollno()
		{
			return 
			Student_Registration_Number;
		}
		///simple functions 
		void input_record();
	 	void show_account();
	 	void update();
	 	void save_record();
	 	void menu();
		void show_database_title()const
		{
			cout<<"\n\n\t\t\t\t**************************************************\n";
			cout<<"\t\t\t\t              STUDENT FEE SYSTEM";
			cout<<"\n\t\t\t\t**************************************************\n";
    		cout<<"***********************************************************************************************************\n";
    		//cout<<"----------------------------------------------------------------------------------------------------\n";
			}
	
};
void Fee_Structure::name(char a[]) 
{
	repeat:
	cin.getline(a,25);
	int j=0,m=0;
	while(a[j]!='\0')
	{
		j++;
		m++;
	}
	int ctr=0;
	for(int i=0;i<m;i++)
	{
		if(a[i]>=48&&a[i]<=57)
		{
		ctr++;
		}
	}
	while(ctr>0)
	{
		cout<<"\n\t\t\tWRONG INPUT(it must be only characters and not include any numbers).....ENTER AGAIN\n\t\t\t";
		goto repeat;
	}
}

//DEFINIG CREATE FUNCTION TO INPUT DATA OF STUDENTS 
void Fee_Structure::create_the_record()
{
	Fee_Structure ab;
	system("CLS"); //USED TO CLEAR THE CONSOLE 
	cin.ignore();
	cout<<"\n\n\t\t\t\t**************************************************\n";
	cout<<"\t\t\t\t             STUDENT FEE SYSTEM";
	cout<<"\n\t\t\t\t**************************************************";
	cout<<"\n\n\t\t\t\t******************************************************\n";
	cout<<"\t\t\t\t             ENTER STUDENT DATA ";
	cout<<"\n\t\t\t\t*****************************************************\n";
	cout<<"\n\t\t\tEnter Name of student: ";
	ab.name(Student_name);
	cout<<"\n\t\t\tEnter the  Registration number of the student  \n\t\t\t(it must include only numbers) 22-NTU-: ";
	cin.getline(Student_Registration_Number,15);
//	while(Student_Registration_Number==Student_Registration_Number)
//	{
//		cout<<"Already Registered!!!";
//		cout<<"\n\t\t\tEnter the  Registration number of the student  \n\t\t\t(it must include only numbers) 22-NTU-: ";
//		cin.getline(Student_Registration_Number,15);
//	}
	cout<<"\n\t\t\tEnter Father name of Student: ";
	ab.name(Father_name);
	cout<<"\n\t\t\tEnter  class  of  student (BSSE-2)  \n\t\t\t(it must include characters): ";
	cin.getline(Class,11); 
	cout<<"\n\t\t\tEnter department of the student: ";
	ab.name(Department);
	cout<<"\n\t\t\tEnter tution fee of student \n\t\t\t(it must include numbers only): ";
	cin>>Tuition_Fee;
	cout<<"\n\t\t\tEnter the  security fee of student \n\t\t\t(it must include numbers only): ";
	cin>>Security_Fee;
	cout<<"\n\t\t\tEnter hostel duess of student(if student is in hostel otherwise enter 0) \n\t\t\t(it must include numbers only): ";
	cin>>Hostel_Dues;
	cout<<"\n\t\t\tEnter the  fines of student(if there is any finee otherwise enter 0) \n\t\t\t(it must be include numbers only): ";
	cin>>Fines;
	cout<<"\n\t\t\tEnter the  examination fee of student \n\t\t\t(it must include number only): ";
	cin.ignore();
	cin>>Examination_Fee;
	Total = Tuition_Fee+Security_Fee+Hostel_Dues+Fines+Examination_Fee;
}
//SETTING PASSWORD FOR MANAGEMENT SYSTEM
void Fee_Structure::password()
{
	cout<<"\n\n\t\t\t\t**************************************************\n";
	cout<<"\t\t\t\t             WELCOME TO STUDENT FEE SYSTEM";
	cout<<"\n\t\t\t\t**************************************************\n";
	string passs = "Password";
	string input;
	cout<<"Enter the password to access the management system: ";
	cin>>input;
	if(input!=passs)
	{
		{
			cout<<"Wrong Password!";
			while(input != passs)
			{
				cout<<" Enter it again.....";		
				cin>>input;
			}
		}
	}
	else
	{
		cout<<"\n\n\t\t\t\t----------------------------------------------------\n";
		cout<<"\t\t\t\t             CORRECT PASSWORD ";
		cout<<"\n\t\t\t\t---------------------------------------------------\n";
	}
}

//WRITING THE STUDENT DATA IN FILE
void Fee_Structure::input_record()
{
	Fee_Structure input;
	fstream my_File;
	my_File.open("Record.txt",ios::binary|ios::app|ios::out);
	if(!my_File)
	{
		cout<<"The file can't be open :";
	}
	input.create_the_record();
	my_File.write(reinterpret_cast <char *>(&input),sizeof(Fee_Structure));
	my_File.close();
	
}

//THIS FUNCTION IS SHOWING THE STUDENT RECORD 
void Fee_Structure::showing()
{
	cout<<"Stdnt_Name: "<<Student_name<<"\n"<<"Reg_No: 22-NTU-"<<Student_Registration_Number<<"\n"<<"Father_Name: "<<Father_name<<"\n";
	cout<<"Class: "<<Class<<"\n"<<"Department: "<<Department<<"\n"<<"Tuition_Fee: "<<Tuition_Fee<<"\n"<<"Security_Fee: "<<Security_Fee<<"\n";
	cout<<"Hostel_Dues: "<<Hostel_Dues<<"\n"<<"Fines: "<<Fines<<"\n"<<"Exam_Fee: "<<Examination_Fee<<"\n"<<"Total: "<<Total<<"\n"<<endl;;
			//cout<<"-----------  ------     ----------    ----- -----   ----------   ------------    -----------  ----- -------- --------\n";
			cout<<"Press Enter to go Back!!!!!\n";
	cout<<"************************************************************************************************************\n";
			
//	cout<<Student_name<<"\n"<<<<"\n"<<<<"\n"<< <<"\n"<<<<"\n"
//    <<Tuition_Fee<<"\n"<<<<"\n"<<<<"\n"<<Fines<<"\n"<<<<"\n"<<
}
//THIS FUNCTION WILL DISPLAY THE WHOLE STUDENT RECORD SAVED IN THE FILE
void Fee_Structure::show_account()
{
	system("CLS");
	Fee_Structure ac;
	ifstream inFile;
	inFile.open("Record.txt",ios::binary|ios::in);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	ac.show_database_title();
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Fee_Structure)))
	{
		ac.showing();
	}
	inFile.close();
}
//THIS FUNCTION WILL SHOW THE STUDENT RECORD ACCORDING TO THE ENTERED REGISTRATION NUMBER 
void Fee_Structure::search()
	{       
		Fee_Structure a;
	    char number[25];
		system("CLS");
		fstream my_File;
		my_File.open("Record.txt", ios::ate | ios::in | ios::out | ios::binary);
	    int found=0;
	    cout<<"\n\n\t\t\t\t**************************************************";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t             STUDENT FEE SYSTEM";
		cout<<"\n\t\t\t\t**************************************************\n";
		cout<<"\n\nENTER REGISTRATION NUMBER TO SEARCH ";
		cout<<"\n---------------------------------------22-NTU-";
        cin>>number;
        //seekg() function here is used to place the file pointer to the begining position in input mode of file
        my_File.seekg(0,ios::beg);
        found=0;
        while(my_File.read((char *) &a, sizeof(Fee_Structure)))
        {
            if(strcmp(number,a.getrollno())==0)
                {
                    found=1;
                    	cout<<"\n\t\t------------------------------------------------------------:";
						cout<<"\n\t\t\t\t\tRECORD FOUND: ";
						cout<<"\n\t\t------------------------------------------------------------:\n ";
                    a.show_database_title();
                    a.showing();
                }
        }
        my_File.clear();
        if(found==0)
            	{
            		cout<<"\n\t\t--------------------------------------------------------------:";
					cout<<"\n\t\t\t\t\tRECORD NOT FOUND: ";
					cout<<"\n\t\t---------------------------------------------------------------:\n ";
				}
}

void Fee_Structure::update_record()
{
	Fee_Structure s;
	cout<<"\n\n\t\t\t\t**************************************************\n";
	cout<<"\t\t\t\t              STUDENT FEE SYSTEM";
	cout<<"\n\t\t\t\t**************************************************";
	cout<<"\n\n\t\t\t\t******************************************************\n";
	cout<<"\t\t\t\t             ENTER THE NEW STUDENT DATA ";
	cout<<"\n\t\t\t\t*****************************************************\n";
	cout<<"\n\t\t\tEnter here the Student Name\n\t\t\t (ENTER \"M\" IF YOU WANT PREVIOUS DATA): ";
	cin.ignore();
	s.name(Student_name_M);
	//CONDITION FOR THE VARIABLES IN WHICH USERR DONOT WANTT TO CHANGE DATAA
	if(strcmp(Student_name_M,"M")!=0)
	{
		strcpy(Student_name,Student_name_M);
	}
	cout<<"\n\t\t\tEnter the  Registration number of the student: \n\t\t\t(ENTER \"M\" IF YOU WANT PREVIOUS DATA): ";
	cin.getline(Student_Registration_NumberM,25);
	if(strcmp(Student_Registration_NumberM,"M")!=0)
	{
		strcpy(Student_Registration_Number,Student_Registration_NumberM);
	}
	cout<<"\n\t\t\tEnter Father name of Student  \n\t\t\t(ENTER \"M\" IF YOU WANT PREVIOUS DATA): ";
	s.name(Father_name_M);
	if(strcmp(Father_name_M,"M")!=0)
	{
		strcpy(Father_name,Father_name_M);
	}
	cout<<"\n\t\t\tEnter  class  of  student (BSSE-2) \n\t\t\t(ENTER \"M\" IF YOU WANT PREVIOUS DATA): ";
	cin>>Class_M;
	if(strcmp(Class_M,"M")!=0)
	{
		strcpy(Class,Class_M);
	}
	cout<<"\n\t\t\tEnter department of the student \n\t\t\t(ENTER \"M\" IF YOU WANT PREVIOUS DATA): ";
	cin.ignore();
	s.name(Department_M);
	if(strcmp(Department_M,"M")!=0)
	{
		strcpy(Department,Department_M);
	}
	cout<<"\n\t\t\tEnter tution fee of student \n\t\t\t(ENTER \"1\" IF YOU WANT PREVIOUS DATA): ";
	cin>>Tuition_Fee_M;
	if(Tuition_Fee_M != 1)
	{
		Tuition_Fee = Tuition_Fee_M;
	}
	cout<<"\n\t\t\tEnter the  security fee  student \n\t\t\t(ENTER \"1\" IF YOU WANT PREVIOUS DATA): ";
	cin>>Security_Fee_M;
	if(Security_Fee_M != 1)
	{
		Security_Fee = Security_Fee_M;
	}
	cout<<"\n\t\t\tEnter hostel duess of student(if student is in hostel otherwise enter 0) \n\t\t\t(ENTER \"1\" IF YOU WANT PREVIOUS DATA): ";
	cin>>Hostel_Dues_M;
	if(Hostel_Dues_M != 1)
	{
		Hostel_Dues = Hostel_Dues_M;
	}
	cout<<"\n\t\t\tEnter the  fines of student(if there is any finee otherwise enter 0) \n\t\t\t(ENTER \"1\" IF YOU WANT PREVIOUS DATA): ";
	cin>>Fines_M;
	if(Fines_M != 1)
	{
		Fines = Fines_M;
	}
	cout<<"\n\t\tEnter the  examination fee of student \n\t\t\t(ENTER \"1\" IF YOU WANT PREVIOUS DATA): ";
	cin.ignore();
	cin>>Examination_Fee_M;
	if(Examination_Fee_M != 1)
	{
		Examination_Fee = Examination_Fee_M;
	}
	if(Tuition_Fee_M!=1)
	{
		Total = Tuition_Fee_M+Security_Fee+Hostel_Dues+Fines+Examination_Fee;
    }
    else if(Security_Fee_M!=1)
    {
    	Total = Tuition_Fee+Security_Fee_M+Hostel_Dues+Fines+Examination_Fee;
	}
	else if(Hostel_Dues_M!=1)      
	{
		Total = Tuition_Fee+Security_Fee+Hostel_Dues_M+Fines+Examination_Fee;
	}
	else if(Fines_M!=1)
	{
		Total = Tuition_Fee+Security_Fee+Hostel_Dues+Fines_M+Examination_Fee;
	}
	else if(Examination_Fee_M!=1)
	{
		Total = Tuition_Fee+Security_Fee+Hostel_Dues+Fines+Examination_Fee_M;
	}
	else if(Tuition_Fee_M!=1&&Security_Fee_M!=1&&Hostel_Dues_M!=1&&Fines_M!=1&&Examination_Fee_M!=1)
	{
		Total = Tuition_Fee_M+Security_Fee_M+Hostel_Dues_M+Fines_M+Examination_Fee_M;
	}

}
//THIS FUNCTION WILL UPDATE A SPECIFIC RECORD OF STUDENT 
void Fee_Structure::update()
{
	bool c = false;
	Fee_Structure a;
	fstream file;
	char number[25];
	file.open("Record.txt",ios::in | ios::out | ios::binary|ios::ate);
	file.seekg(0,ios::beg);
	file.read(reinterpret_cast<char *> (&a), sizeof(Fee_Structure));
	if(!file)
	{
		cout<<"The file can't be open :";
	}
	else
	{
		cout<<"\nENTER THE STUDENT REGISTRATION NUMBER FOR THE UPDATION: ";
		cin>>number;
	while(!file.eof())
	{
		if(!strcmp(number,a.getrollno()))
		{
			system("CLS");
			cout<<"\n\t\t----------------------------------------------------------------:";
			cout<<"\n\t\t\t\t\tRECORD YOU WANT TO UPDATE: ";
			cout<<"\n\t\t----------------------------------------------------------------:\n ";
			a.show_database_title();
			a.showing();
			//IT WAITS FOR THE USER TO PRESS ANY KEY TO PROCEED FURTHER
			system("pause");
			system("CLS");
			a.update_record();
			//here tellp() function is used to return the current working position of the file pointer in the output mode 
			long position = file.tellp();
			//here seekp() function is used to place the file pointer to the specified position in output mode of file 
			file.seekp(position-sizeof(Fee_Structure));
			file.write(reinterpret_cast<char *> (&a), sizeof(Fee_Structure));
			cout<<"\nRECORD HAS BEEN UPDATED :";
			c = true;
		}
		file.read(reinterpret_cast<char *> (&a), sizeof(Fee_Structure));
	}
	}
	file.close();
	if(c == false)
	{
		cout<<"\n\t-------------------------------------------------------------------------:";
		cout<<"\n\t\t\t\t\tRECORD NOT FOUND ";
		cout<<"\n\t----------------------------------------------------------------------:\n ";
	}
}
//DELETING THE RECORD OF A SPECIFIC STUDENT 

void Fee_Structure::Deletee()
{
	Fee_Structure a;
	ifstream inFile;
	ofstream outFile;
	char number[15];
	int found=0;
	inFile.open("Record.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Record1.txt",ios::binary);
	inFile.seekg(0,ios::beg);
	cout<<"\n\n\t\t\t\t**************************************************\n";
	cout<<"\t\t\t\t             STUDENT FEE SYSTEM";
	cout<<"\n\t\t\t\t**************************************************\n";
	cout<<"\n\t\t******************************************************************:";	
	cout<<"\n\t\t\t\t\tDELETING A RECORD:";	
	cout<<"\n\t\t*****************************************************************:\n";	
	cout<<"ENTER THE REGISTRATION NUMBER YOU WANT TO DELETE: ";
	cin>>number;
	while(inFile.read(reinterpret_cast<char *> (&a), sizeof(Fee_Structure)))
	{
		if(strcmp(number,a.getrollno())!=0)
		{
			outFile.write(reinterpret_cast<char *> (&a), sizeof(Fee_Structure));
			
		}
		if(strcmp(number,a.getrollno())==0)
		{
			found=1;
		}
	}
    inFile.close();
	outFile.close();
	remove("Record.txt");
	rename("Record1.txt","Record.txt");
		if(found==1)
	{
		cout<<"\n\t-------------------------------------------------------------------------:";
		cout<<"\n\t\t\t\t\tRECORD DELETED ";
		cout<<"\n\t----------------------------------------------------------------------:\n ";
	}
	if(found==0)
	{
		cout<<"\n\t\t----------------------------------------------------------------:";
		cout<<"\n\t\t\t\t\tRECORD NOT FOUND: ";
		cout<<"\n\t\t----------------------------------------------------------------:\n ";
	}
}
void Fee_Structure::menu()
{
	//Menu of student fee system(choose any option from (A,B)) 
	//If the user presses A option Management fee system would be accessed
	//If the user presses B option Student fee system would be accessed
		cout<<"\n\n\t\t\t\t**************************************************\n";
		cout<<"\t\t\t\t             STUDENT FEE SYSTEM";
		cout<<"\n\t\t\t\t**************************************************\n";
		cout<<"\t\t\t\t\t\t    ::MAIN MENU::\n";
		cout<<"\n\t\t\t\t\t\tA. MANAGEMENT FEE SYSTEM";
		cout<<"\n\t\t\t\t\t\tB. STUDENT ACCESS ";
		cout<<"\n\t\t\t\t\t\tC. EXIT ";
		
		cout<<"\n\n\t\t\t\tSelect Your Option (A,B,C): ";
}

	
//***************************************MAIN FUNCTION*******************************************
int main()
{
	Fee_Structure a,b; //objects of our class Fee_Structure
	char choice;
	char choice1;
	int num,number,s;
	do
	{
		system("CLS");//clearing the console
		//CALLING HERE THE MENU FUNCTION
		a.menu();
		cin>>choice1;
		switch(choice1)
		{
			case 'A':
					b.password();
					system("pause");
					system("CLS");
	do
	{
	system("CLS");
	//Menu of management fee system(choose any option from (1,2,3,4,5,6)) 
		cout<<"\n\n\t\t\t\t**************************************************\n";
		cout<<"\t\t\t\t             MANAGEMENT FEE SYSTEM";
		cout<<"\n\t\t\t\t**************************************************\n";
		cout<<"\t\t\t\t\t\t    ::MAIN MENU::\n";
		cout<<"\n\t\t\t\t\t\t1. Add Student Record";
		cout<<"\n\t\t\t\t\t\t2. Search Student record by Registration_Number";
		cout<<"\n\t\t\t\t\t\t3. Display all the Student  Record";
		cout<<"\n\t\t\t\t\t\t4. Delete any of Student Record";
		cout<<"\n\t\t\t\t\t\t5. Update any of Student Record";
		cout<<"\n\t\t\t\t\t\t6. Press any key to go back to main menu";
		cout<<"\n\n\t\t\t\tSelect Your Option (1-6): ";
		
		cin>>choice; //The user will enter choice according to his requirement 

		switch(choice)
		{
		case '1':
			system("CLS");
			//The user can input data of as many students as he want
			cout<<"\n\t\t\t|---------------------------------------------------|";
			cout<<"\n\t\t\t|Enter number of students you want to input data    |";
			cout<<"\n\t\t\t|---------------------------------------------------|: \n ";
			cin>>num;
			for(int i=0;i<num;i++)
			{
				a.input_record();
				system("pause");
			}
			break;
		case '2':
			a.search();
			break;
		case '3':
			system("CLS");
		    a.show_account();
			break;
		case '4':
			system("CLS");
			a.Deletee();
			break;
		case '5':
			a.update();
			break;
		case '6':
			system("CLS");
			a.menu();
			break;
			//If the user will enter a wrong choice(other than (1-6)) 
			//"INVALID INPUT" WILL BE DISPLAYED and esacpe sequence \a will produces a sound  
		 	default :cout<<"\aINVALID CHOICE.....";
		}
		cin.ignore();
		cin.get();
    }while(choice!='6');
		break;
    case 'B':
    	
    	//If user will choose option B the record of entered registration number will be displayed
		system("CLS") ;
		cout<<"\n\n\t\t\t\t**************************************************\n";
		cout<<"\t\t\t\t             WELCOME TO STUDENT FEE RECORD";
		cout<<"\n\t\t\t\t**************************************************\n";
		cout<<"\n\n\t\t\tHere the student can search his record through his registration number \n";
		cout<<"\n\n\t\t\t--------------------------------------------------------------------------\n";
		system("pause");
		system("CLS");
		cout<<"\n\n\t\t\t\t**************************************************\n";
		cout<<"\t\t\t\t              STUDENT FEE RECORD";
		cout<<"\n\t\t\t\t**************************************************\n";
		cout<<"\n|-------------------------------------------------|";
		cout<<"\n|ENTER THE NUMBER OF STUDENTS YOU WANT TO SEARCH  | ";
		cout<<"\n|-------------------------------------------------|:";
		cin>>s;
		for(int i=0;i<s;i++)
		{
			a.search();
			system("pause");
		}
		a.menu();
			break;
	case 'C':
			system("CLS");
			cout<<"\n\t***********************************************************************";
			cout<<"\n\t\t\tTHANK YOU FOR USING THIS APPLICATION";
			cout<<"\n\t*************************************************************************";
			cout<<"\n\t\t\tDEVELOPED BY\n\n\t\t\t MUHAMMAD SAJEEL , ZAINAB FAROOQ AND NOOR-UL-HUDAA";
			cout<<"\n\nPress any key to exit";
			//THIS MEANS SUCCESSFUL TERMINATION OF THE PROGRAM
			//(PROGRAM HAS EXECUTED WITHOUT ANY ERROR)
			exit(0);
		break;
		default :cout<<"\n\aINVALID CHOICE.....AGAIN ENTER A VALID CHOICE\n";
		system("pause");
		}  
    }
		while(1);
}




