#include <iostream>
#include "events.h"
using namespace std;
//Constructor
Events::Events()
{
    name = " ";
    rating = 0;
    avgCostForOne = 0;
    distance = 0;
    id = 0;
}

/*Parametric Constructor
    Incoming Data: two integers to set the distance and the cost
    Outgoing Data: None
*/
Events::Events(int x, int y) : id(x), avgCostForOne(y){}

    // Overloading the '<' operator for comparison based on the lowest average cost
 bool Events::operator<(const Events& other) const {
        return avgCostForOne < other.avgCostForOne;
    }

    // Overloading the '>=' operator for comparison based on the lowest average cost
bool Events::operator>=(const Events& other) const {
        return avgCostForOne >= other.avgCostForOne;
    }

    // Overloading the '==' operator for comparison based on name
bool Events::operator==(const Events& other) const {
        return (name == other.name);
    }
