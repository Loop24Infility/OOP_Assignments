#include <bits/stdc++.h>
#include <string>
using namespace std;

class RBI {
protected:
    float min_interest_rate;
    float max_withdrawal_limit;
    float min_balance;
public:
    RBI() {
        min_interest_rate = 4.0;
        max_withdrawal_limit = 1000000;
        min_balance = 10000;
    }
    
    float getMinInterestRate()
    {
         return min_interest_rate; 
    }
    float getMaxWithdrawalLimit()
    {
         return max_withdrawal_limit; 
    }
    float getMinBalance() 
    { 
        return min_balance;
    }
};

class Customer {
private:
    string name;
    string address;
    string phone;
public:
    Customer() : name(""), address(""), phone("") {} 
    
    Customer(string n, string addr, string ph) 
    {
        this->name=n;
        this->address=addr;
        this->phone=ph;
    }
    string getName() { return name; }
    string getAddress() { return address; }
    string getPhone() { return phone; }
};

class Account {
protected:
    string account_number;
    Customer customer;
    float balance;
public:
    Account() : account_number(""), customer(), balance(0) {} 
    
    Account(string accNo, Customer cust, float bal) 
    {
        this->account_number=accNo;
        this->customer=cust;
        this->balance=bal;
    }
    
    void deposit(float amount) {
        balance += amount;
        cout << "Deposited " << amount << ". New balance: " << balance << endl;
    }
    
    bool withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn " << amount << ". New balance: " << balance << endl;
            return true;
        }
        cout << "Insufficient balance!" << endl;
        return false;
    }
    
    float getBalance() 
    { 
        return balance; 
    }
    string getAccountNumber() 
    { 
        return account_number; 
    }
    Customer getCustomer() 
    { 
        return customer; 
    }
};

class SBI : public RBI {
private:
    Account account;
public:
    SBI() {
        min_interest_rate = 4.5;
    }
    
    void createAccount(Customer customer, float initialBalance) {
        string accNo = "SBI123";
        account = Account(accNo, customer, initialBalance);
    }
    
    void displayAccount() {
        cout << "\nSBI Account Details:" << endl;
        cout << "Account Number: " << account.getAccountNumber() 
             << " Balance: " << account.getBalance() << endl;
    }
    
    Account getAccount() { return account; }
};

class ICICI : public RBI {
private:
    Account account;
public:
    ICICI() {
        min_interest_rate = 5.0;
    }
    
    void createAccount(Customer customer, float initialBalance) {
        string accNo = "ICICI123";
        account = Account(accNo, customer, initialBalance);
    }
    
    void displayAccount() {
        cout << "\nICICI Account Details:" << endl;
        cout << "Account Number: " << account.getAccountNumber() 
             << " Balance: " << account.getBalance() << endl;
    }
    
    Account getAccount() { return account; }
};

int main() {
    Customer cust1("Ansh", "123 Main St", "9111");
    
    SBI sbi;
    ICICI icici;
    
    sbi.createAccount(cust1, 5000);
    icici.createAccount(cust1, 10000);
    
    Account sbiAcc = sbi.getAccount();
    Account iciciAcc = icici.getAccount();
    
    sbiAcc.deposit(2000);
    sbiAcc.withdraw(1000);
    
    iciciAcc.deposit(5000);
    iciciAcc.withdraw(2000);
    
    sbi.displayAccount();
    icici.displayAccount();
    cout << "CODE BY KSHITIJ JADHAV";
    return 0;
}
