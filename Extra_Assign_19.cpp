#include<bits/stdc++.h>
using namespace std ;

class Rectangle 
{
    public:
    float length;
    float breadth;

    Rectangle()
    {
        length = 0;
        breadth = 0;
    }

    Rectangle(float l, float b)
    {
        length = l;
        breadth = b;
    }

    Rectangle(float n)
    {
        length = n;
        breadth = n;
    }
    void area()
    {
        cout<<"Area of Rectangle is "<<length*breadth<<endl;
    }
};

int main()
{
    Rectangle R1 ; 

    Rectangle R2(11,8);
    R2.area();

    Rectangle R3(10);
    R3.area();

    return 0 ;

}
