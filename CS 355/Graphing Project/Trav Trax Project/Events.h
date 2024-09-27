#ifndef EVENTS_H
#define EVENTS_H

#include <iostream>
#include <fstream>
#include "pQueue.h"

using namespace std;

struct Events {
    string name;
    double rating;
    double avgCostForOne;
    string sport;
    string time;
    string day;
    int id;
    int distance;

    // Default constructor
    Events();

    // Parametric constructor with id and avgCostForOne only
    Events(int x, int y);

    // Overloaded comparison operators
    bool operator<(const Events& other) const;
    bool operator>=(const Events& other) const;
    bool operator==(const Events& other) const;

    // Member functions to read events data from a file
    static void eventFile(const string& filename);
    static void sportFile(const string& filename);

    // Static member queues
    static pQueue<Events> eventQueue;
    static pQueue<Events> sportQueue;
};

#endif // EVENTS_H
