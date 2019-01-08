#ifndef FRUIT_H
#define FRUIT_H
#include <iostream>
#include <stdlib.h>
#include "items.h"
#include <fstream>
using namespace std;


class fruit: public items{
	public:
		void add(string type, int location_x, int location_y, double weight_per_unit, int price_per_unit,
			double calories, double units_to_add);
		void Print() const;
		double Calories() const;
		int operator > (const fruit& i) const;
		int operator == (const fruit& i) const;


	private: 
	
		double weight_per_unit;
		int price_per_unit;
		double units_to_add;
};


#endif
