//Divine Goshea, Jayden Green, Krutivas Pradhan
//2/19/24
#include <iostream>
using namespace std;

class Shape {
protected:
    string name;
public:
    Shape():name("What"){}
    Shape(string str):name(str){}
    virtual double GetArea()const = 0 ;
    virtual double GetPerimeter()const = 0 ;
    virtual void PrintInfo() const{}
};

class Circle: public Shape {
protected:
    double radius;
    string color;
    const int Pi = 3.14;
public:
    Circle():Shape("Circle") {
        radius = 0;
        color = "none";
    }
    Circle(double r):Shape("Circle") {
        radius = r;
    }
    Circle(double r, string c):Shape("Circle") {
        radius = r;
        color = c;
    }
    string GetName()const {
        return name;
    }
    virtual double GetArea()const {
        double area;
        area = Pi * (radius * radius);
        return area;
    }
    virtual double GetPerimeter()const {
        double perimeter;
        perimeter = 2 * Pi * radius;
        return perimeter;
    }
    virtual void PrintInfo()const {
        cout << "Name: " << GetName() << endl;
        cout << "Color: " << color << endl;
        cout << "Perimeter: " << GetPerimeter() << endl;
        cout << "Area: " << GetArea() << endl;
    }


};

class Rectangle: public Shape {
protected:
    string color;
    double length, width;

public:
    Rectangle(double l, double w, string c):Shape("rectangle") {
        length = l;
        width = w;
        color = c;
    }
    virtual double GetArea()const {
        double area;
        area = length* width;
        return area;
    }
    virtual double GetPerimeter()const {
        double perimeter;
        perimeter = 2 * (length + width);
        return perimeter;
}

    virtual void PrintInfo()const {
        cout << "Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Perimeter: " << GetPerimeter() << endl;
        cout << "Area: " << GetArea() << endl;
    }



};
int main() {
    Rectangle obj(1.0, 2.3,"blue");
    obj.PrintInfo();
    Circle cir(1.0, "red");
    cir.PrintInfo();
    Shape *s1 = new Circle(1.0, "red");
    Shape *s2 = new Rectangle(3.4, 5, "blue");
    s1->PrintInfo();
    s2->PrintInfo();
return 0;
}
