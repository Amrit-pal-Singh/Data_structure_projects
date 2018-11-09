#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

class items{ 
	private:
		friend class fruit;
		friend class vegetables;
	protected:
		//int purchase_id;
		int location_x;
		int location_y;
		double purchase_time;
		string type;
		int calories;
	public:
		virtual void Print(){}
		virtual int LocationX(){}
		virtual int LocationY(){}
		virtual string Name(){}
		virtual double Units(){}
		virtual void ChangeUnits(double units){}
		virtual double WeightPerUnit(){}
		virtual int Price(){}	
		virtual int VolumePerKg(){}
		virtual double Calories(){}
		virtual void add(string type, int location_x, int location_y, double weight_per_unit, int price_per_unit,
			double  calories, double units_to_add){}
		virtual void add(string type,int location_x, int location_y, int price_per_kg, double volume_per_kg,
			double calories, double amount_to_add){}
};	

#endif
