#include <iostream>
using namespace std;

class Employee {
private:
    int age;
    int yearsOfService;
    double salary;
public:
    Employee(int a, int y, double s) {
        age = a;
        yearsOfService = y;
        salary = s;
    }

    void setAge(int a) { age = a; }
    void setYearsOfService(int y) { yearsOfService = y; }
    void setSalary(double s) { salary = s; }

    int getAge() { return age; }
    int getYearsOfService() { return yearsOfService; }
    double getSalary() { return salary; }

    int salaryInThousands() {
        return static_cast<int>((salary + 500) / 1000);
    }
};

int main() {
    Employee e1(30, 5, 55000);
    Employee e2(45, 20, 98000);

    cout << "Employee 1:\n";
    cout << "Age = " << e1.getAge() << "\n";
    cout << "Years of Service = " << e1.getYearsOfService() << "\n";
    cout << "Salary = $" << e1.getSalary() << "\n";
    cout << "Rounded Salary = $" << e1.salaryInThousands() << ",000\n\n";

    cout << "Employee 2:\n";
    cout << "Age = " << e2.getAge() << "\n";
    cout << "Years of Service = " << e2.getYearsOfService() << "\n";
    cout << "Salary = $" << e2.getSalary() << "\n";
    cout << "Rounded Salary = $" << e2.salaryInThousands() << ",000\n";
    cout << "CODE BY KSHITIJ JADHAV";
    return 0;
}
