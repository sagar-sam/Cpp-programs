#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<unistd.h>
//#include<windows.h>

using namespace std;

class banking{
    protected:
        string name;
        int acc_no;
        int bal;
    public:
        void show_bal();
        virtual void create_account()=0;
        virtual void update_info(int flag)=0;
};


class current : public banking
{
    int new_bal;
	public:
    void add_money();
   // void show_bal();
    void create_account();
    current();
    current(int iacc_no,int iamount,string iname);
    void update_info(int flag);
    void withdraw_money();
};

current::current()
{
    cout<<"\n\n\n\t\t\t\tCURRENT ACCOUNT";
    ifstream inf("details.txt");
    int first_acc_no;
    inf>>first_acc_no;
    acc_no=first_acc_no+1;
    cout<<"\n\n\n Account No. : "<<acc_no;
    inf.close();
}
void current::withdraw_money()
{
    int withdraw;
    cout<<"\n\n\n Enter the amount to be withdrawn : ";
    cin>>withdraw;
    bal=bal-withdraw;
    cout<<"\n\n\n Current Balance is Rs. "<<bal;
    sleep(3);
    system("clear");
}
current::current(int iacc_no,int iamount,string iname)
{
    acc_no=iacc_no;
    bal=iamount;
    name=iname;
    cout<<"\n\n\n\t\tWelcome to your Current Account"<<iname;
}
void current::add_money()
{
    int add_bal;
    cout<<"\n\n\n Enter the amount you want to deposit : ";
    cin>>add_bal;
    bal=bal+add_bal;
    cout<<"\n\n\n Current Balance is Rs. "<<bal;
    sleep(3);
    system("clear");
}
void current::create_account()
{
    cout<<"\n\nEnter your name : ";
    getline(cin,name);
    cout<<"\n\nEnter the amount you want to deposit : ";
    cin>>bal;
    cin.clear();
    fflush(stdin);
    cout<<"\n\n\n\t\t Account created successfully... ";
    sleep(4);
    system("clear");
}
void current ::update_info(int flag)
{
    ofstream file("info.txt",ios::out | ios::app);
    file.seekp(0,ios ::end);
    file<<endl<<acc_no<<" "<<'c'<<" "<<bal<<" "<<name;
    file.close();
    if(flag==0)
    {
        ofstream ofs("details.txt");
        ofs<<acc_no;
        ofs.close();
    }
}
void banking::show_bal()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t Your Current Balance is Rs. "<<bal;
    sleep(3);
    system("clear");
}

class savings : public banking
{
public:
    savings();
   // void show_bal();
    void create_account();
    savings(int iacc_no,int iamount,string iname);
    void update_info(int flag);
    void add_money();
};

void savings :: add_money()
{
    int add;
    cout<<"\n\n\n Enter the amount you want to deposit : ";
    cin>>add;
    bal=bal+add;
    cout<<"\n\n\n Current Balance is Rs. "<<bal;
    sleep(3);
    system("clear");
}
void savings :: update_info(int flag)
{
    ofstream file("info.txt",ios::out | ios::app);
    file.seekp(0,ios ::end);
    file<<endl<<acc_no<<" "<<'s'<<" "<<bal<<" "<<name;
    file.close();
    if(flag==0)
    {
        ofstream ofs("details.txt");
        ofs<<acc_no;
        ofs.close();
    }
}
savings ::savings()
{
     cout<<"\n\n\n\t\t\t\tSAVINGS ACCOUNT";
    ifstream inf("details.txt");
    int first_acc_no;
    inf>>first_acc_no;
    acc_no=first_acc_no+1;
    cout<<"\n\n\n\n Account Number : "<<acc_no;
    inf.close();
}
savings :: savings(int iacc_no,int iamount,string iname)
{
    acc_no=iacc_no;
    bal=iamount;
    name=iname;
    cout<<"\n\n\n\t\tWelcome to your Savings Account"<<iname;
}
/*void savings :: show_bal()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t Your Current balance is Rs. "<<bal;
    Sleep(3000);
    system("cls");
}*/
void savings ::create_account()
{
    cout<<"\n\n\nEnter your Name : ";
    getline(cin,name);
    cout<<"\n\nEnter the amount you want to deposit : ";
    cin>>bal;
    cin.clear();
    fflush(stdin);
    cout<<"\n\n\n\t\t Account Created Successfully..!!!";
    sleep(4);
    system("clear");
}

int main()
{
    int n;
    while(n!=3)
    {
        cout << "\n\n\t\t\t\t S K S  BANK\n\n\n\n"<<endl<<" 1. New User (Sign up)\n"<<endl<<" 2. Already have an Account (Login)"<<"\n\n 3. EXIT"<<"\n\n\n\n Please select your choice : ";
        cin>>n;
        cin.clear();
        fflush(stdin);
        system("clear");
        int m=4;
        switch(n)
        {
        case 1:
            {
                while(m!=1 && m!=2 && m!=3)
                {
                    cout<<"\n\n\n\t\t\t    Welcome to S K S Bank";
                    cout<<"\n\n\n\n\n 1. Current Account"<<endl<<"\n 2. Savings Account"<<endl<<"\n 3. Back to Main Menu";
                    cout<<"\n\n\n\n Please select your choice : ";
                    cin>>m;
                    cin.clear();
                    fflush(stdin);
                    system("clear");
                    switch(m)
                    {
                    case 1:{
                        current cur;
                        cur.create_account();
                        cur.update_info(0);
                        break;
                        }
                    case 2:
                        {
                        savings sav;
                        sav.create_account();
                        sav.update_info(0);
                        break;
                        }
                    case 3:
                        break;
                    default:
                        cout<<"Please select an appropriate choice."<<endl;
                    }
                }
                break;
            }
        case 2:
            {
                    char acc_type,actual_acc_type;
                    int acc_search,amount,actual_acc_search,actual_amount;
                    string iname,actual_iname;
                    int iacc_no;
                    cout<<"\n\n\n\n Enter your Account number : ";
                    cin.clear();
                    fflush(stdin);
                    cin>>iacc_no;
                    cin.clear();
                    fflush(stdin);
                    fstream file("info.txt",ios::in | ios::out | ios::app);
                    if(!file.is_open())
                        cout<<"ERROR 404 !!!! System not responding !!";
                    else
                    {
                        while(file.good())
                        {
                            file>>actual_acc_search>>actual_acc_type>>actual_amount;
                            getline(file,actual_iname);
                            if(actual_acc_search==iacc_no)
                            {
                                acc_search=actual_acc_search;
                                acc_type=actual_acc_type;
                                amount=actual_amount;
                                iname=actual_iname;
                            }
                        }
                        if(acc_type=='c')
                        {
                            int o=1;
                            current cur(acc_search,amount,iname);
                            while(o!=4)
                            {
                                cout<<"\n\n\n 1. Deposit money"<<"\n 2. Show Balance"<<"\n 3. Withdraw Money"<<"\n 4. Back to previous Menu";
                                cout<<"\n\n\n\n Please select your choice : ";
                                cin.clear();
                                fflush(stdin);
                                cin>>o;
                                system("clear");
                                switch(o)
                                {
                                case 1:
                                    {
                                    cur.add_money();
                                    break;
                                    }
                                case 2:
                                    {
                                    cur.show_bal();
                                    break;
                                    }
                                case 3:
                                    {
                                    cur.withdraw_money();
                                    break;
                                    }
                                case 4:
                                    {
                                    cur.update_info(1);
                                    break;
                                    }
                                default:
                                    cout<<"\n\n\nPlease select an appropriate choice"<<endl;
                                }
                            }
                        }
                        else if(acc_type=='s')
                        {
                            savings sav(acc_search,amount,iname);
                            int o=1;
                            while(o!=3)
                            {
                                cout<<"\n\n\n 1. Deposit money"<<"\n 2. Show Balance"<<"\n 3. Back to previous Menu";
                                cout<<"\n\n\n Please select an option : ";
                                cin.clear();
                                fflush(stdin);
                                cin>>o;
                                cin.clear();
                                fflush(stdin);
                                system("clear");
                                switch(o)
                                {
                                case 1:
                                    {
                                        sav.add_money();
                                        break;
                                    }
                                case 2:
                                    {
                                    sav.show_bal();
                                    break;
                                    }
                                case 3:
                                    {
                                    sav.update_info(1);
                                    break;
                                    }
                                default:
                                    cout<<"\n\nPlease select an appropriate option."<<endl;
                                }
                            }
                        }
                    }
                break;
            }
        case 3:
            break;
        default :
            cout<<"\n\n Please select an appropriate choice."<<endl;
        }
    }
    return 0;
}
