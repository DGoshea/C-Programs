#include <iostream>
#include <string>
using namespace std;
class Events{
private:
    string name;
    double rating;
    double avgCostForOne;
    int id;
    int distance;

public:
    Events();
    Events(int x, int y);
    bool operator<(const Events& other) const;
    bool operator>=(const Events& other) const;
    bool operator==(const Events& other) const;
    friend class Graph;
};
