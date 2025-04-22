#include <bits/stdc++.h>
using namespace std;

class Shape {
public:
    void print() {
        cout << "This is a shape" << endl;
    }
};

class Polygon : public Shape {
public:
    void print() {
        cout << "Polygon is a shape" << endl;
    }
};

class Rectangle : public Polygon {
public:
    void print() {
        cout << "Rectangle is a polygon" << endl;
    }
};

class Triangle : public Polygon {
public:
    void print() {
        cout << "Triangle is a polygon" << endl;
    }
};

class Square : public Rectangle {
public:
    void print() {
        cout << "Square is a rectangle" << endl;
    }
};

int main() {
    Shape s;
    Polygon p;
    Rectangle r;
    Triangle t;
    Square sq;
    
    s.print();
    p.print();
    r.print();
    t.print();
    sq.print();
    cout << "CODE BY KSHITIJ JADHAV";
    return 0;
}
