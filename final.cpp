#include<bits/stdc++.h>
#include<string>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
int cot=0;
int cot1=0;
using namespace std;
void loginjump();
int day;
int month;
int year;
char name[50];
class info
{
public:
    int ch;
    char searchname[50];
    char searchmeal[50];
    void menu();
    void n_meal();
    void deposit();
    void d_sum();
    void infoswitchpage();
    int age;
    char name[50];
    long int meal;
    long int tmeal=0;
    long int depositl;
    void infopage()
    {
        system("CLS");
        cout<<"MESS MANAGEMENT"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1.MENU CHART"<<endl;
        cout<<"2.EACH STUDENT MEAL COUNT"<<endl;
        cout<<"3.BILL"<<endl;
        cout<<"4.DEPOSIT"<<endl;
        cout<<"5.EXIT"<<endl;
        cout<<"ENTER CHOICE"<<endl;
        cout<<"     ";
        cin>>ch;
        infoswitchpage();
    }

};
void info::infoswitchpage()
{
    while(ch!=1||ch!=2||ch!=3||ch!=4||ch!=5)
    {
        switch(ch)
        {
        case 1:
            menu();
            break;
        case 2:
            n_meal();
            break;

        case 3:
            d_sum();
            break;
        case 4:
            deposit();
            break;

        case 5:
            loginjump();
            break;
        default:
            cout<<endl<<"INVALID CHOICE"<<endl;
            cout<<"ENTER CHOICE"<<endl;
            cout<<"     ";
            cin>>ch;
        }
    }
}
void info::menu()
{
    system("CLS");
    cout<<" DAY   :LAUNCH  -  DINNER"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"SATURDAY:CHICKEN -  EGG   "<<endl;
    cout<<"SUNDAY  :MUTTON  - CHICKEN"<<endl;
    cout<<"MONDAY  :EGG     - CHICKEN"<<endl;
    cout<<"TUESDAT :CHICKEN - FISH   "<<endl;
    cout<<"THURSDAY:CHICKEN - FISH   "<<endl;
    cout<<"FRIDAY  :BIRIYANI -KHICURI"<<endl;
    cout<<endl<<"PRESS ANY KEY TO CONTINUE"<<endl;
    cout<<"     ";
    getch();
    infopage();
}
void info::n_meal()
{
        system("CLS");
    cout<<"MESS MANAGENEBT";
    cout<<"-----------------"<<endl<<endl;
    ifstream mealadd("student.txt");
    ofstream mealadd1("mealdetails.txt",ios::app);
    cout<<"ENTER THE STUDENT NAME: "<<endl;
    cout<<"   ";
    cin>>searchname;
    cin.sync();
    while(mealadd>>name>>age>>tmeal>>depositl)
    {
        if(strcmp(name,searchname)==0)
        {
            cout<<"ENTER YOUR MEAL DATE"<<endl;
            cout<<"    ";
            cin>>day>>month>>year;
            if(day>31)
            {
                cout<<"Invalid date"<<endl;
                getch();
                n_meal();
            }
            else if(month>12)
            {
                cout<<"Invalid month"<<endl;
                getch();
                n_meal();
            }


            cout<<"ENTER YOUR MEAL NO."<<endl;
            cout<<"    ";
            cin>>meal;



            mealadd1<<name<<endl;
            mealadd1<<day<<':'<<month<<':'<<year<<' '<<meal<<endl<<endl;
        }
        else
            cout<<"THE NAME DOESN'T EXIT.GO TO ADMIN OFFICE TO REGISTER";
            getch();
            infopage();

cot1++;
    }
    mealadd.close();
    mealadd1.close();
    cout<<"MEAL DETAILS ADDED"<<endl;
    cout<<"DO YOU WANT TO ADD MORE?"<<endl;
    cout<<"1.yea"<<endl;
    cout<<"2.No"<<endl;
    cin>>ch;
    while(ch!=1 || ch!=2)
    {
        switch(ch)
        {
        case 1:
            n_meal();
            break;
        case 2:
            infopage();
            break;

        }
    }
    getch();
    infopage();
}
void info::d_sum()
{
    int offset2;
    string line3;
    system("CLS");
    cout<<"MESS MANAGENEBT"<<endl;
    cout<<"-----------------"<<endl;
    cout<<"ENTER STUDENT NAME"<<endl;
    cin>>searchmeal;
    ifstream summA("mealdetails.txt");
    ofstream summB("bill.txt",ios::app);
    if(summA.is_open()){
            while(getline(summA,line3)){
            if((offset2=line3.find(searchmeal,0))!=string::npos){

            tmeal=tmeal+meal;
            }

            }
}
if(summA.is_open())
    summB<<searchmeal<<'  '<<tmeal<<endl;


    cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
    cout<<"     ";
    getch();
    infopage();
}
void info::deposit()
{
    system("CLS");
    cout<<"MESS MANAGENEBT"<<endl;
    cout<<"-----------------"<<endl;
    ifstream depA("student.txt");
    ofstream depB("temp.txt");
    cout<<"STUDENT - AGE - MEAL NO. - BILL - DEPOSIT MONEY"<<endl;
    cout<<"-------------------------------"<<endl;

    while (depA>>name>>age>>meal>>tmeal>>depositl)
    {
        depositl=depositl-tmeal;
        depB<<name<<' '<<age<<' '<<meal<<' '<<tmeal<<' '<<depositl<<endl;
    }

    depA.close();
    depB.close();
    remove("student.txt");
    rename("temp.txt","student.txt");
    ifstream ldep("student.txt");

    while(cot--)
    {
        while (ldep>>name>>age>>meal>>tmeal>>depositl)
        {
            cout<<name<<" - "<<age<<" - "<<meal<<" - "<<tmeal<<" -"<<depositl<<endl ;
        }
    }
    cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
    cout<<"     ";
    getch();
    infopage();
}
class student
{
public:
    int ch,age;
    char name[50];
    char searchname[50];
    long int meal;
    void deposit();
    void addstd();
    void displaystd();
    void removestd();
    long int tbill=0;
    long int amount=0;
    void stdpageswitch();
    void displaymeal();
    void stdpage()
    {
        system("CLS");
        cout<<"MESS MANAGEMENT"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1.DISPLAY ALL STUDENT DETAILS"<<endl;
        cout<<"2.ADD NEW STUDENT DETAILS"<<endl;
        cout<<"3.REMOVE STUDENT DETAILS"<<endl;
        cout<<"4.DISPLAY MEAL DETAILS"<<endl;
        cout<<"5.EXIT"<<endl<<endl;
        cout<<"ENTER CHOICE"<<endl;
        cout<<"     ";
        cin>>ch;
        stdpageswitch();
    };
};
void student::stdpageswitch()
{
    while(ch!=1||ch!=2||ch!=3||ch!=4||ch!=5)
    {
        switch(ch)
        {
        case 1:
            displaystd();
            break;
        case 2:
            addstd();
            break;
        case 3:
            removestd();
            break;
        case 4:
            displaymeal();
            break;
        case 5:
            loginjump();
            break;
        default:
            cout<<endl<<"INVALID CHOICE"<<endl;
            cout<<"ENTER CHOICE"<<endl;
            cout<<"     ";
            cin>>ch;
        }
    }
}
void student::addstd()
{
 system("CLS");
    cout<<"MESS MANAGEMENT";
    cout<<"-----------------"<<endl<<endl;
    ofstream newstudent("student.txt",ios::app);
    cout<<"ENTER NAME OF STUDENT"<<endl;
    cout<<"     ";
    cin>>name;
    cin.sync();
    cout<<"ENTER AGE OF STUDENT:"<<endl;
    cout<<"     ";
    cin>>age;
    cout<<"ENTER BILLS OF STUDENT"<<endl;
    cout<<"     ";
    cin>>tbill;
    cout<<"ENTER AMOUNT DEPOSIT OF STUDENT"<<endl;
    cout<<"     ";
    cin>>amount;
    newstudent<<name<<' '<<age<<' '<<tbill<<' '<<amount<<endl;
    newstudent.close();
    cout<<endl<<"STUDENT ADDED"<<endl;
    cout<<endl<<"PRESS ANY KEY TO CONTINUE";
    cout<<"     ";
    cot++;
    getch();
    stdpage();
}
void student::displaystd()
{
    system("CLS");
    cout<<"MESS MANAGENEBT";
    cout<<"-----------------"<<endl<<endl;
    ifstream studentA("student.txt");
    cout<<"STUDENT - AGE - MEAL_NO - BILL"<<endl;
    cout<<"-----------------------"<<endl;
    while (studentA>>name>>age>>tbill>>amount)
    {
        cout<<name<<" - "<<age<<" - "<<tbill<<" - "<<amount<<endl;
    }
    studentA.close();
    cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
    cout<<"     ";
    getch();
    stdpage();
}
void student::removestd()
{
    system("CLS");
    cout<<"MESS MANAGEMENT"<<endl;
    cout<<"-----------------"<<endl;
    char tname[50];
    ifstream student1("student.txt");
    ofstream student2("temp.txt");
    cout<<"ENTER THE NAME OF STUDENT WISH TO REMOVE"<<endl;
    cout<<"     ";
    cin>>tname;
    while(student1>>name>>age>>tbill>>amount)
    {
        if(strcmp(name,tname)!=0)
        {
            student2<<name<<' '<<age<<' '<<tbill<<' '<<amount<<endl;
        }
    }
    student1.close();
    student2.close();
    remove("student.txt");
    rename("temp.txt","student.txt");
    cout<<endl<<"STUDENT REMOVED"<<endl;
    cout<<endl<<"PRESS ANY KEY TO CONTINUE"<<endl;
    cout<<"     ";
    getch();
    stdpage();
}
void student::displaymeal(){
    int offset;
      system("CLS");

    cout<<"MESS MANAGEMENT"<<endl;
    cout<<"-----------------"<<endl;
    cout<<"ENTER THE STUDENT NAME"<<endl;
    cout<<"   ";
    cin>>searchname;
    ifstream file;
    file.open("mealdetails.txt");
    if(!file.is_open()){
        cout<<"something wrong"<<endl;
        getch();
        stdpage();
    }
    else
    {
        string line;
        string line2;
        while(getline(file,line)){
            if((offset=line.find(searchname,0))!=string::npos)
            {
            while(getline(file,line2))
                cout<<line2<<endl;
            cout<<"  ";
                  }
            else
                cout<<"FILE DIDN'T FOUND"<<endl;
        }
    }
    cout<<endl<<"PRESS ANY KEY TO CONTINUE"<<endl;
    cout<<"     ";
    getch();
    stdpage();
}
class login
{
public:
    string pass=" ";
    int ch;
    char c;
    void homepageswitch();
    void loginswitch();
    void studentlogin();
    void adminlogin();
    void stud();
    void admin();

    void homepage()
    {
        system("CLS");
        cout<<"1. LOGIN"<<endl;
        cout<<"2. EXIT"<<endl<<endl;
        cout<<"ENTER CHOICE"<<endl;
        cout<<"     ";
        cin>>ch;
        homepageswitch();
    };
    void loginpage()
    {
        system("CLS");
        cout<<"MESS MANAGEMENT"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1.ADMIN LOGIN"<<endl;
        cout<<"2.STUDENT LOGIN"<<endl;
        cout<<"3. EXIT"<<endl<<endl;
        cout<<"ENTER CHOICE"<<endl;
        cout<<"     ";
        cin>>ch;
        loginswitch();
    };
};
void login::homepageswitch()
{
    while(ch!=1||ch!=2)
    {
        switch(ch)
        {
        case 1:
            loginpage();
            break;
        case 2:
            exit(0);
            break;
        default:
            cout<<endl<<"INVALID CHOICE"<<endl;
            cout<<"ENTER CHOICE"<<endl;

            cout<<"     ";
            cin>>ch;
        }
    }
}
void login::loginswitch()
{
    while(ch!=1||ch!=2||ch!=3)
    {
        switch(ch)
        {
        case 1:
            adminlogin();
            break;
        case 2:
            studentlogin();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout<<endl<<"INVALID CHOICE"<<endl;
            cout<<"ENTER CHOICE"<<endl;
            cout<<"     ";
            cin>>ch;
        }
    }
}
void login::adminlogin()
{
    while(pass!="12345")
    {
        pass="";
        cout<<endl<<"ENTER ADMIN PASSWORD"<<endl;
        cout<<"     ";
        c=_getch();
        while(c!=13)
        {
            pass.push_back(c);
            cout<<"*";
            c=getch();
        }
        if(pass=="12345")
        {
            cout<<endl<<"ADMIN ACCESS GRANTED"<<endl;
            cout<<endl<<"PRESS ANY KEY TO CONTINUE"<<endl;
            cout<<"     ";
            getch();
            admin();
        }
        else
        {
            cout<<endl<<"INVALID PASSWORD"<<endl;
        }
    }
}
void login::studentlogin()
{
    while(pass!="54321")
    {
        pass="";
        cout<<"ENTER STUDENT PASSWORD"<<endl;
        cout<<"     ";
        c=_getch();
        while(c!=13)
        {
            pass.push_back(c);
            cout<<"*";
            c=getch();
        }
        if(pass=="54321")
        {
            cout<<endl<<"STUDENT ACCESS GRANTED"<<endl;
            cout<<endl<<"PRESS ANY KEY TO CONTINUE"<<endl;
            cout<<"     ";
            getch();
            stud();

        }
        else
        {
            cout<<endl<<"INVALID PASSSWORD"<<endl;
        }
    }
}
void login::stud()
{
    info i;
    i.infopage();
}
void login::admin()
{
    student s;
    s.stdpage();
}
void loginjump(){
login l2;
l2.loginpage();
}


int main()
{
    login l;
    l.homepage();
    return 0;
}
