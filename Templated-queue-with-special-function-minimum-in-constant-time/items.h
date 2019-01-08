#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <deque>
using namespace std;

class items{ 
	private:
		friend class fruit;
		friend class vegetables;
	protected:
		int location_x;
		int location_y;
		double purchase_time;
		string type;
		double calories;
};	
#endif