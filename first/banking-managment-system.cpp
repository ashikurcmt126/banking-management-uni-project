#include<iostream>
#include<stdio.h>
#include<istream>
#include <conio.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

void register1();
void login();
void user_panel();
void admin_panel();
void valid_user();

int main()
{
    int choice;
    cout<<"\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
	cout<<"\n\t\t\tWELCOME TO OUR BANKING MANAGMENT SYSTEM\t";
	cout<<"\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
	cout<<endl;
    cout<<"1. USER PANEL "<<endl;
    cout<<"2. ADMIN PANEL"<<endl;
    cout<<"ENTER YOUR CHOICE: "<<endl;
    cin>>choice;

    switch(choice)
    {
        case 1:
            user_panel();
            break;
        case 2:
            admin_panel();
            break;
        /*
        case 1:
            register1();
            break;
        case 2:
            login();
            break;
        case 4:
            cout<<"THANKS FOR USING LOGIN PAGE"<<endl;
            break;

        default:
            cout<<"SORRY, YOU HAVE SELECTED WRONG OPTION"<<endl;
            main();
        */
    }

}

void user_panel()
{
    int choice;

    cout<<"\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
    cout<<"\n\t\t\tUSER PANEL\t";
    cout<<"\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";

    cout<<"\n\n"<<endl;
    cout<<"1. REGISTER"<<endl;
    cout<<"2. LOGIN"<<endl;

    cout<<"ENTER YOUR CHOICE"<<endl;
    cin>>choice;

    switch(choice)
    {
        case 1:
            register1();
            break;
        case 2:
            login();
            break;
        default:
            cout<<"SORRY, YOU HAVE SELECTED WRONG OPTION. TRY AGAIN"<<endl;
            break;

    }
    /*
    cout<<"DEPOSIT MONEY"<<endl;
    cout<<"WITHDRAW MONEY"<<endl;
    cout<<"TRANSFER MONEY"<<endl;
    cout<<"TAKE LOAN"<<endl;
    cout<<"PAY LOAN"<<endl;
    cout<<"BALANCE ENQUIRY"<<endl;
    cout<<"UPDATE OR EDIT ACCOUNT"<<endl;
    cout<<"LOGOUT"<<endl;
    */

}
void admin_panel()
{
    cout<<"This is admin pannel"<<endl;
}

void register1()
{
        string regUser,regPass,regPass2,account_number;
        char type;
        char actype[10];
        float accountBalance;

        system("cls");
        cout<<"\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
        cout<<"\n\t\t\tREGISTRATION FORM\t";
        cout<<"\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
        cout<<"\nENTER YOUR USERNAME :";
        cin>>regUser;
        cout<<"\nENTER YOUR ACCOUNT NUMBER :";
        cin>>account_number;
        password:
        cout<<"\nENTER 6-DIGIT PIN:";
        cin>>regPass;
        cout<<"\nRE-ENTER 6-DIGIT PIN:";
        cin>>regPass2;

        if(regPass != regPass2){
            cout<<"\nPASSWORD NOT MATCHING";
            cout<<"\nENTER AGAIN";
            goto password;
        }

        cout<<"\nENTER TYPE OF ACCOUNT.\n(C FOR CURRENT & S FOR SAVING"<<endl;
        cin>>type;
        type=toupper(type);

        cout<<"\nENTER THE INITIAL AMMOUNT: ";
        again:
        cout<<"\n>=500 FOR SAVING & >=1000 FOR CURRENT"<<endl;
        cin>>accountBalance;

        if(accountBalance<500 && type=='S' || accountBalance<1000 && type=='C'){
            cout<<"INSUFFICIENT BALANCE"<<endl;
            cout<<"RE-ENTER INITIAL AMMOUNT"<<endl;
            goto again;
        }
        ofstream reg("database.txt",ios::app);
        reg<<regUser<<' '<<regPass<<' '<<account_number<<endl;
        cout<<"\nREGISTRATION SUCCESSFULL\n\n";

        cout<<"DO YOU WANNA LOGIN AS A USER"<<endl;
        cout<<"Y/N?"<<endl;

        char ch;
        cin>>ch;
        ch=toupper(ch);

        if(ch == 'Y')login();
        else if(ch == 'N')main();
        else cout<<"YOU HAVE ENTERED WRONG CHARACTER"<<endl;

}

void login()
{
        int count,i=0;
        string username,pin_code,u,p;
        char ch, password[20];
        system("cls");
        cout<<"\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
        cout<<"\n\t\t\tLOGIN FORM\t";
        cout<<"\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
        cout<<"\nUSERNAME :";
        cin>>username;
        cout<<"PIN CODE :";
        for(i=0; i<10; i++)
        {
             ch = getch();
             if (ch != 13)
             {
                 password[i] = ch;
                 ch = '*' ;
                 printf("%c",ch);
             }
             if(ch == 13)
                   break;
        }
        password[i]=' ';
        ifstream input("database.txt");
        while(input>>u>>p)
        {

            p = p+" ";

                if(u==username && p==password)

                {
                        count=1;
                        //system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHELLO "<<username<<"\nLOGIN SUCESS.\nTHANKS FOR LOG IN\n";
                cin.get();
                valid_user();
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPLEASE CHECK YOUR USERNAME AND PASSWORD\n";
                //login();
        }
}

void valid_user()
{
    int choice;

    cout<<"1. DEPOSIT MONEY"<<endl;
    cout<<"2. WITHDRAW MONEY"<<endl;
    cout<<"3. TRANSFER MONEY"<<endl;
    cout<<"4. TAKE LOAN"<<endl;
    cout<<"5. PAY LOAN"<<endl;
    cout<<"6. BALANCE ENQUIRY"<<endl;
    cout<<"7. UPDATE OR EDIT ACCOUNT"<<endl;
    cout<<"8. LOGOUT"<<endl;
    cout<<"9. HOME"<<endl;


    cout<<"ENTER YOUR CHOICE"<<endl;
    cin>>choice;

    switch(choice)
    {
        case 9:
            main();
            break;
        default:
            cout<<"SORRY, YOU HAVE SELECTED WRONG OPTION. TRY AGAIN"<<endl;
            break;

    }

}















