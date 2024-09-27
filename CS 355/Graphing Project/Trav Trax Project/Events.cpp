#include "Events.h"

// Default constructor implementation
Events::Events() : name(" "), rating(0), avgCostForOne(0), sport(""), time(""), day(""), id(0), distance(0) {}

// Parametric constructor implementation
Events::Events(int x, int y) : id(x), avgCostForOne(y) {}

// Definition of member functions
bool Events::operator<(const Events& other) const {
    return avgCostForOne < other.avgCostForOne;
}

bool Events::operator>=(const Events& other) const {
    return avgCostForOne >= other.avgCostForOne;
}

bool Events::operator==(const Events& other) const {
    return (name == other.name);
}

void Events::eventFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Failed to open the file: " << filename << endl;
        exit(1); // Exit with an error code
    }

    string name;
    double rating;
    double avgCostForOne;
    int i = 0;
    while (inputFile >> name >> rating >> avgCostForOne) {
        Events event;
        event.id = i;
        event.name = name;
        event.rating = rating;
        event.avgCostForOne = avgCostForOne;
        eventQueue.enQueue(event);
        i++;
    }

    inputFile.close();
}

void Events::sportFile(const string& filename) {
    ifstream sportFile(filename);
    if (!sportFile.is_open()) {
        cout << "Failed to open the file: " << filename << endl;
        exit(1); // Exit with an error code
    }

    string SportName;
    string teamName;
    string time;
    double sportCost;
    string sportDay;
    int i = 9;

    while (sportFile >> SportName >> sportDay >> time >> teamName >> sportCost) {
        Events event;
        event.id = i;
        event.name = SportName;
        event.rating = 0.0;
        event.avgCostForOne = sportCost;
        event.sport = teamName;
        event.time = time;
        event.day = sportDay;
        sportQueue.enQueue(event);
        i++;
    }

    sportFile.close();
}

pQueue<Events> Events::eventQueue;
pQueue<Events> Events::sportQueue;


