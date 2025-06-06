#include<bits/stdc++.h>
using namespace std ;

class Account
{
    public:
    string name ;
    int acc_num ;
    string acc_type;

    void setInfo(string name , int acc_num , string acc_type )
    {
        this->name = name ;
        this->acc_num = acc_num;
        this->acc_type = acc_type;
    }

    void check_bal(float balance)
    {
        cout<<"Current Balance : "<<balance<<endl;
    }

    void deposit(float balance  )
    {
        float amount;
        cout<<"Enter amount to deposit : "<<endl;
        cin>>amount;

        balance += amount ;
        cout<<"Amount deposited successfully"<<endl;
        cout<<"New balance : "<<balance<<endl;
    }

    void withdraw(float balance )
    {
        float amount;
        cout<<"Enter amount to withdraw : "<<endl;
        cin>>amount;

        if(amount>balance)
        {
            cout<<"Insufficient Balance! "<<endl;
        }
        else 
        {
            balance -= amount ;
            cout<<"Withdrawal successful "<<endl;
            cout<<"New balance : "<<balance<<endl;
        }
    }
};

class Savings_acc : public Account
{
    public:
    void comp_interest(float balance ,float rate , int time )
    {
    float interest = balance*pow((1+rate/100),time)-balance ;
    cout<<"Interest computed : "<<interest <<endl;
    deposit(interest);
    }
};

class Current_acc : public Account 
{
    public:
    float min_bal = 1000 ;
    float service_charge = 100 ;

    void check_min_bal(float balance)
    {
        if(balance < min_bal)
        {
            balance -= service_charge ;
            cout<<"Balance after deducting service charge : "<<balance <<endl;
        }
    }
};

int main()
{
    float balance = 100000 ;
    float amount ;

    Savings_acc S;
    S.setInfo("Ansh",1,"Savings");
    S.deposit(balance);
    S.withdraw(balance);
    S.check_bal(balance);
    S.comp_interest(balance,5,3);

    Current_acc C;
    C.setInfo("Ansh",1,"Savings");
    C.deposit(balance);
    C.withdraw(balance);
    C.check_bal(balance);
    C.check_min_bal(balance);

    cout << "CODE BY KSHITIJ JADHAV";

}
