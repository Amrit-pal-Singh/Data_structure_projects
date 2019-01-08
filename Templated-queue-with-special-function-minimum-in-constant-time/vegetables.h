#ifndef VEGETABLES_H
#define VEGETABLES_H
#include <iostream>
#include <stdlib.h>
#include "items.h"
#include <fstream>
using namespace std;



class vegetables: public items{
	private:
		int price_per_kg;
		double volume_per_kg;
		double amount_to_add;
	public:
		void add(string type,int location_x, int location_y, int price_per_kg, double volume_per_kg,
			double calories, double amount_to_add);
		void Print() const;
		int operator > (const vegetables& i) const;
		int operator == (const vegetables& i) const;
		double Calories() const;
};

#endif
