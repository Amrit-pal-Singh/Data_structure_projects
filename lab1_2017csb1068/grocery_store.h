#ifndef GROCERY_STORE_H
#define GROCERY_STORE_H
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "items.h"
#include "node.h"
#include "fruit.h"
#include "vegetables.h"

using namespace std;



class grocery_store{	
	private:
		int purchase_id;
		int location_x;
		int location_y;
		double purchase_time;
		string type;
		double calories; 
		double weight_per_unit;
		int price_per_unit;
		int price_per_kg;
		double volume_per_kg;
		double amount_to_add;
		double units_to_add;
		int extra;
		ifstream finput;
		fruit *obj_fr;
		vegetables *obj_veg;
		node obj_node;
		int i_to_add_fruit;
        int i_to_add_veg;
        int i;

	public:
		grocery_store(const char* file);
		~grocery_store();
        void input_fruit_file();
		void input_veg_file();
		void add_element(int check);
		void print();
        void sell_items(string name, double amount, string units);
		void location(int x_coordinate,int y_coordinate);
		void sell_items_acc_calories(string name, double amount, string units);
		void counting_elements(string str, int check);
};

#endif