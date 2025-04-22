#include <iostream>
using namespace std;

class DB;

class DM {
    int meters;
    int centimeters;
public:
    DM() : meters(0), centimeters(0) {}
    DM(int m, int cm) : meters(m), centimeters(cm) {}
    void read() {
        cin >> meters >> centimeters;
    }
    void display() {
        cout << "Distance: " << meters << " meters, " << centimeters << " centimeters" << endl;
    }
    friend DM add(DM, DB);
};

class DB {
    int feet;
    int inches;
public:
    DB() : feet(0), inches(0) {}
    DB(int f, int in) : feet(f), inches(in) {}
    void read() {
        cin >> feet >> inches;
    }
    void display() {
        cout << "Distance: " << feet << " feet, " << inches << " inches" << endl;
    }
    friend DM add(DM, DB);
};

DM add(DM d1, DB d2) {
    float totalMeters = d1.meters + d1.centimeters / 100.0;
    float totalFeet = d2.feet + d2.inches / 12.0;
    float totalInMeters = totalMeters + totalFeet * 0.3048;
    int resultMeters = int(totalInMeters);
    int resultCentimeters = int((totalInMeters - resultMeters) * 100);
    return DM(resultMeters, resultCentimeters);
}

int main() {
    DM dm;
    DB db;
    cout << "Enter distance in meters and centimeters: ";
    dm.read();
    cout << "Enter distance in feet and inches: ";
    db.read();
    DM result = add(dm, db);
    result.display();
    return 0;
}
