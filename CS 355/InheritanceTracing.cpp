#include <iostream>

using namespace std;
#define STARS cout << "*******************" << endl;

class Base{

    int x;

public:
    Base():x(5){cout << "Base default"<< endl;}

    Base(int v):x(v){cout << "Base data"<< endl;}

    virtual void Method1(){cout <<"Base::Method1 "<< endl;}

    void Method2(){cout << "Base::Method2 " << endl;}

    virtual void Method3(){cout <<"Base::Method3 " <<  endl;}

    virtual void Print(){cout <<"Base::Print " <<endl<< "x: " << x << endl;}

};

class D1: public Base{

    int y;

public:

    D1():y(10){cout << "D1's default" << endl;}

    D1(int v1, int v2):Base(v1), y(v2){cout << "D1's Data 1" << endl;}

    D1(int v1, int v2, int v3):y(v1+v2+v3){cout << "D1's Data 2" << endl;}

    void Method1(){cout <<"D1::Method1 "<< endl;}

    void Method2(){cout <<"D1::Method2 "<< endl;}

    virtual void Print()
    {

        cout << "D1::Print" << endl;

        Base::Print();

        cout << "y: " << y << endl;

    }

};

class D2: public D1{

      int z;

public:

       D2():D1(10,20,30),z(99){cout << "D2's default" << endl;}

       void Method3(){cout << "D2::Method3" << endl;}

       virtual void Print()
       {

            cout << "D2::Print" << endl;

            D1::Print();

            cout << "z: " << z << endl;

       }

};

int main(){

    STARS;

    Base *ptr[5];

    ptr[0] = new Base();STARS;

    ptr[1] = new D1();STARS;

    ptr[2] = new D1(1,2); STARS;

    ptr[3] = new D1(101,202,303);STARS;

    ptr[4] = new D2(); STARS;

    for (int x = 0; x < 5; x++)
        {
            STARS;

            ptr[x]->Print();

            ptr[x]->Method1();

            ptr[x]->Method2();

            ptr[x]->Method3();

        }

    return 0;

}
