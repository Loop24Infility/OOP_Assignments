#include <bits/stdc++.h>
using namespace std;

class Account
{
public:
    string name;
    int acc_num;
    string acc_type;
    float balance;

    Account(string name, int acc_num, string acc_type, float balance)
    {
        this->name = name;
        this->acc_num = acc_num;
        this->acc_type = acc_type;
        this->balance = balance;
    }

    void check_bal()
    {
        cout << "Current Balance : " << balance << endl;
    }

    void deposit()
    {
        float amount;
        cout << "Enter amount to deposit: "<<endl;
        cin >> amount;

        balance += amount;
        cout << "Amount deposited successfully" << endl;
        cout << "New balance: " << balance << endl;
    }

    void deposit(float amount)
    {
        balance += amount;
        cout << "Amount deposited successfully (interest added)" << endl;
        cout << "New balance: " << balance << endl;
    }

    void withdraw()
    {
        float amount;
        cout << "Enter amount to withdraw: "<<endl;
        cin >> amount;

        if (amount > balance)
        {
            cout << "Insufficient Balance!" << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawal successful" << endl;
            cout << "New balance: " << balance << endl;
        }
    }
};

class Savings_acc : public Account
{
public:
    Savings_acc(string name, int acc_num, string acc_type, float balance)
        : Account(name, acc_num, acc_type, balance) {}

    void comp_interest(float rate, int time)
    {
        float interest = balance * pow((1 + rate / 100), time) - balance;
        cout << "Interest computed: " << interest << endl;
        deposit(interest);
    }
};

class Current_acc : public Account
{
public:
    float min_bal = 1000;
    float service_charge = 100;

    Current_acc(string name, int acc_num, string acc_type, float balance)
        : Account(name, acc_num, acc_type, balance) {}

    void check_min_bal()
    {
        if (balance < min_bal)
        {
            balance -= service_charge;
            cout << "Service charge applied!" << endl;
            cout << "Balance after deducting service charge: " << balance << endl;
        }
};

int main()
{
    float balance = 100000;

    cout<<"For Savings Account "<<endl;
    Savings_acc S("Ansh", 1, "Savings", balance);
    S.deposit();
    S.withdraw();
    S.check_bal();
    S.comp_interest(5, 3);

    cout<<"For Current Account "<<endl;
    Current_acc C("Ansh", 2, "Current", balance);
    C.deposit();
    C.withdraw();
    C.check_bal();
    C.check_min_bal();

    cout << "CODE BY KSHITIJ JADHAV";
}
