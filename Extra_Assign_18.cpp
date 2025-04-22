#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string name;

    Student(string stName = "Unknown") {
        name = stName;
    }

    void printName() {
        cout << "Student name: " << name << endl;
    }
};

int main() {
    Student st1;
    Student st2("Kshitij");

    st1.printName();
    st2.printName();
    cout << "CODE BY KSHITIJ JADHAV";
    return 0;
}
