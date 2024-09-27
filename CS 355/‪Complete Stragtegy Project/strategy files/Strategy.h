#ifndef _STRATEGY_H
#define _STRATEGY_H

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 20; //to represent the 4x5 grid

// Base class
class Strategy {
protected:
	int movesleft;
public:
	Strategy():movesleft(0){}
    virtual ~Strategy(){};
	virtual int MakeDecision(void) = 0;
	virtual void ReceiveStatus(int e)= 0;
	virtual void Reset(){movesleft=0;}
	virtual int Tie()=0;
	virtual string Name(){return "Strategy01's Strategy";}
};


#endif
