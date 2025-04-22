/*Make a class named Fruit with a data member to calculate the number of fruits in a basket. Create
 two other class named Apples and Mangoes to calculate the number of apples and mangoes in the
 basket. Print the number of fruits of each type and the total number of fruits in the basket.*/

#include<bits/stdc++.h>
using namespace std;

class Fruit 
{
    public:
    int num_fruits = 0 ;

    void counter(int num_apple , int num_mango )
    {
        num_fruits = num_apple + num_mango ;
        cout<<"Total number of fruits : "<<num_fruits<<endl;
    }
};

class Apples : public Fruit
{
    public:
    int num_apple = 0;

    Apples(int count)
    {
        num_apple += count ;
        cout<<"Number of Apples : "<<num_apple<<endl;
    }

    int info()
    {
        return num_apple;
    }

};

class Mangoes : public Fruit 
{
    public:
    int num_mango = 0;

    Mangoes(int count)
    {
        num_mango += count ;
        cout<<"Number of Mangoes : "<<num_mango<<endl;
    }

    int info()
    {
        return num_mango;
    }

};

int main()
{
    Apples A(5);
    Mangoes M(7);

    Fruit F;
    F.counter(A.info(),M.info());

    return 0;
}