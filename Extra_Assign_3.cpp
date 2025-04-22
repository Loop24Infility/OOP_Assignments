#include<bits/stdc++.h>
using namespace std;

class Staff
{
    protected:
    int code;
    string name;

    public:
    void getS()
    {
        cout<<"Enter Staff Code: ";
        cin>>code;
        cout<<"Enter Staff Name: ";
        cin.ignore(); 
        getline(cin,name);
    }

    void displayS()
    {
        cout<<"Staff Code: "<<code<<endl;
        cout<<"Staff Name: "<<name<<endl;
    }
};

class Teacher : public Staff
{
    protected:
    string subject,publication;

    public:
    void getT()
    {
        cout<<"Enter Subject: ";
        getline(cin,subject);
        cout<<"Enter Publication: ";
        getline(cin,publication);
    }

    void displayT()
    {
        cout<<"Subject: "<<subject<<endl;
        cout<<"Publication: "<<publication<<endl;
    }
};

class Officer : public Staff
{
    protected:
    string grade;

    public:
    void getO()
    {
        cout<<"Enter Grade: ";
        getline(cin,grade);
    }

    void displayO()
    {
        cout<<"Grade: "<<grade<<endl;
    }
};  

class Typist : public Staff
{
    protected:
    float speed;

    public:
    void getTy()
    {
        cout<<"Enter Speed: ";
        cin>>speed;
    }

    void displayTy()
    {
        cout<<"Speed: "<<speed<<endl;
    }
};

class Regular : public Typist
{
    protected:
    float salary;

    public:
    void getR()
    {
        cout<<"Enter Salary: ";
        cin>>salary;
    }

    void displayR()
    {
        cout<<"Salary: "<<salary<<endl;
    }
};

class Casual : public Typist
{
    protected:
    float dailyWage;

    public:
    void getC()
    {
        cout<<"Enter Daily Wage: ";
        cin>>dailyWage;
    }

    void displayC()
    {
        cout<<"Daily Wage: "<<dailyWage<<endl;
    }
};

int main()
{
    Teacher t;
    Officer o;
    Regular r;
    Casual c;

    cout<<"Enter Teacher Details"<<endl;
    t.getS();
    t.getT();
    cout<<"Enter Officer Details"<<endl;
    o.getS();
    o.getO();
    cout<<"Enter Regular Typist Details"<<endl;
    r.getS();
    r.getTy();
    r.getR();
    cout<<"Enter Casual Typist Detail"<<endl;
    c.getS();
    c.getTy();
    c.getC();

    cout<<endl<<"-Teacher Details"<<endl;
    t.displayS();
    t.displayT();
    
    cout<<endl<<"Officer Details"<<endl;
    o.displayS();
    o.displayO();

    cout<<endl<<"Regular Typist Details"<<endl;
    r.displayS();
    r.displayTy();
    r.displayR();

    cout<<endl<<"Casual Typist Details-"<<endl;
    c.displayS();
    c.displayTy();
    c.displayC();

    return 0;
}