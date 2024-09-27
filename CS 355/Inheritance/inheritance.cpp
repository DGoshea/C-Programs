#include <iostream>
using namespace std;

class Pair
{
    int x, y;

public:
    Pair(): x(0), y(0){cout << "Pair Default" << endl;} // default constructor
    Pair(int v1, int v2):x(v1), y(v2){cout << "Pair Data" << endl;}// data constructor
    virtual void print()const
    {
        cout << x << ", " << y;
    }
    void setX(int v)
    {
        x = v;
    }
    void setY(int v)
    {
        y = v;
    }

    int getX()const
    {
        return x;
    }
    int getY()const
    {
        return y;
    }

};

class Triple : public Pair
{
    int z;
public:
    Triple():z(0){cout << "Triple Default" << endl;};
    Triple(int v1, int v2, int v3):Pair(v1, v2),z(v3){cout << "Triple Data" << endl;};
    void setZ(int v)
    {
        z = v;
    }
    int getZ()
    {
        return z;
    }
    void print()const
    {
        Pair::print();
        cout << ", " << z;
    }
};

class Quad : public Triple
{
    int a;
public:
    Quad():a(0){cout << "Quad default" << endl;};
    Quad(int v1, int v2, int v3, int v4):Triple(v1, v2, v3), a(v4){cout << "Quad Data" << endl;}
    int getA()
    {
        return a;
    }
    void setA(int v)
    {
        a = v;
    }
    void print()const
    {
        Triple::print();
        cout << ", " << a;
    }
};

int main()
{
    Pair p1;
    Pair p2(2,3);
    Pair* ptr = new Pair(2,3);
    Triple* tptr = new Triple(1,2,3);
    Quad* qptr = new Quad(5,6,7,8);
    ptr->print(); cout << endl;
    tptr->print(); cout << endl;
    qptr->print();
    /*p1.print(); cout << endl;
    p2.print(); cout << endl;
    Triple t1;
    Triple t2(1,2,3);
    t1.print(); cout << endl;
    t2.print(); cout << endl;
    Quad q1;
    Quad q2(5,6,7,8);
    q1.print(); cout << endl;
    q2.print(); cout << endl;
*/
    return 0;
}
