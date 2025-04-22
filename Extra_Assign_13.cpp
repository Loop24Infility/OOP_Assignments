#include<bits/stdc++.h>
using namespace std;

const int MAX_STUDENTS = 100;

class Marks {
public:
    static int nextRollNumber;
    int rollNumber;
    string name;
    int marks;

    Marks() {
        rollNumber = ++nextRollNumber;
    }

    void setName(string n) {
        name = n;
    }

    void setMarks(int m) {
        marks = m;
    }

    int getRollNumber() {
        return rollNumber;
    }

    string getName() {
        return name;
    }

    float getMarks() {
        return marks;
    }
};

int Marks::nextRollNumber = 0;

class Physics : public Marks {
public:
    Physics() : Marks() {}
};

class Chemistry : public Marks {
public:
    Chemistry() : Marks() {}
};

class Mathematics : public Marks {
public:
    Mathematics() : Marks() {}
};

int main() {
    int numStudents;
    cout << "Enter the number of students : ";
    cin >> numStudents;

    if (numStudents > MAX_STUDENTS) {
        cout << "Error: Number of students exceeds maximum limit of " << MAX_STUDENTS << endl;
        return 1;
    }

    Physics phy_st[MAX_STUDENTS];
    Chemistry chem_st[MAX_STUDENTS];
    Mathematics math_st[MAX_STUDENTS];


    for (int i = 0; i < numStudents; i++) {
        string name;
        float physicsMarks, chemistryMarks, mathMarks;

        cout << "\nEnter details for student " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Physics marks: ";
        cin >> physicsMarks;
        cout << "Chemistry marks: ";
        cin >> chemistryMarks;
        cout << "Mathematics marks: ";
        cin >> mathMarks;

        phy_st[i].setName(name);
        phy_st[i].setMarks(physicsMarks);

        chem_st[i].setName(name);
        chem_st[i].setMarks(chemistryMarks);

        math_st[i].setName(name);
        math_st[i].setMarks(mathMarks);
    }

    cout << "\nResults:" << endl;
    cout << "Roll No.\tName\tTotal\tAverage" << endl;

    int classTotal = 0;

    for (int i = 0; i < numStudents; i++) {
        int total = phy_st[i].getMarks() + 
                     chem_st[i].getMarks() + 
                     math_st[i].getMarks();
        float average = total / 3;
        classTotal += total;

        cout << phy_st[i].getRollNumber() << "\t\t"
             << phy_st[i].getName() << "\t\t"
             << total << "\t" << average << endl;
    }

    float classAverage = classTotal / (numStudents * 3);
    cout << "Class Average: " << classAverage << endl;

    return 0;
}
