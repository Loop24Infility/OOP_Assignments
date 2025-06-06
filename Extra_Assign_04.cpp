#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    void updatePerson(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Account : virtual public Person {
protected:
    string accountNumber;
    double balance;
public:
    void updateAccount(string accNum, double bal) {
        accountNumber = accNum;
        balance = bal;
    }

    void displayAccount() {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
};

class Admin : virtual public Person {
protected:
    string adminID;
    string role;
public:
    void updateAdmin(string id, string r) {
        adminID = id;
        role = r;
    }

    void displayAdmin() {
        cout << "Admin ID: " << adminID << ", Role: " << role << endl;
    }
};

class Master : public Account, public Admin {
public:
    void updateMaster(string n, int a, string accNum, double bal, string id, string r) {
        updatePerson(n, a);
        updateAccount(accNum, bal);
        updateAdmin(id, r);
    }

    void displayMaster() {
        cout << "Master Information:" << endl;
        displayPerson();
        displayAccount();
        displayAdmin();
    }
};

int main() {
    Master m;
    m.updateMaster("Kshitij", 30, "ACC123", 1500.75, "ADM001", "Manager");
    m.displayMaster();
    cout << "CODE BY KSHITIJ JADHAV";
    return 0;
}
