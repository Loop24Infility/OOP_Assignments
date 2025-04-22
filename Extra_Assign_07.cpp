#include <bits/stdc++.h>
using namespace std;

class SimpleCircle {
public:
    int itsRadius;

    SimpleCircle() : itsRadius(5) {}
    
    SimpleCircle(int radius) : itsRadius(radius) {}
    
    ~SimpleCircle() {}
    
    int getRadius() const {
        return itsRadius;
    }
    
    void setRadius(int radius) {
        itsRadius = radius;
    }
    
    SimpleCircle operator++() {
        SimpleCircle result;
        result.itsRadius = itsRadius + 1;
        itsRadius = itsRadius + 1;
        return result;
    }
    
    SimpleCircle operator++(int) {
        SimpleCircle result;
        result.itsRadius = itsRadius;
        itsRadius = itsRadius + 1;
        return result;
    }
    
    SimpleCircle(const SimpleCircle& obj) {
        itsRadius = obj.itsRadius;
    }
    
    SimpleCircle operator=(const SimpleCircle obj) {
        itsRadius = obj.itsRadius;
        SimpleCircle result;
        result.itsRadius = itsRadius;
        return result;
    }
};

int main() {
    SimpleCircle circle1;  
    SimpleCircle circle2(9);  

    ++circle1;
    circle2++;

    cout << "Circle 1 radius: " << circle1.getRadius() <<endl;
    cout << "Circle 2 radius: " << circle2.getRadius() <<endl;
    
    circle1 = circle2;

    cout << "Circle 1 radius after assignment: " << circle1.getRadius() <<endl;
    cout << "CODE BY KSHITIJ JADHAV";
    return 0;
}
