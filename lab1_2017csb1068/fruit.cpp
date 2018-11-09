#include "fruit.h"



void fruit::add(string type, int location_x, int location_y, double weight_per_unit, int price_per_unit,
			double calories, double units_to_add){
			this->type = type;
			this->location_x = location_x;
			this->location_y = location_y;
			this->weight_per_unit = weight_per_unit;
			this->price_per_unit = price_per_unit;
			this->calories = calories;
			this->units_to_add = units_to_add;
		}
		void fruit::Print(){
			cout <<type <<endl<< " location_x "<<location_x <<endl<<" location_y " << location_y <<endl<< " weight_per_unit "
			<< weight_per_unit	<<endl<<" price_per_unit " <<price_per_unit <<endl<< " calories " <<calories 
			<<endl<< " units_to_add "<< units_to_add << endl <<endl;
		}
		string fruit::Name(){
			return type;
		}
		int fruit::LocationX(){
			return location_x;
		}
		int fruit::LocationY(){
			return location_y;
		}
		double fruit::WeightPerUnit(){
			return weight_per_unit;
		}
		double fruit::Units(){
			return units_to_add;
		}
		void fruit::ChangeUnits(double units){
			units_to_add = units;
		}
		int fruit::Price(){
			return price_per_unit;
		}
		double fruit::Calories(){
			return calories;
		}