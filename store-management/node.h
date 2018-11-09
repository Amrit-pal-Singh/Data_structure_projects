#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <fstream>
#include "items.h"
#include "fruit.h"
#include "vegetables.h"
#include <stdlib.h>
using namespace std;



class node{
	private:
		struct node_struct{
			items* object;
			node_struct* next;
		};
		struct node_struct* temp;
        struct node_struct* temp1;
		struct node_struct* duplicate[200]; //to store the value of nodes which have name same as that which we have to sell
		struct node_struct* prev;           //to store the previous node of one we have to delete    
		int i;
		int j;
		double count;
		double count1;
		double number_of_calories[200];     //number of calories of items having same name as one to sell
		double count_claories;
		int amount;	
		int elements;
		int* counting_elements;
		int* price;
		ofstream file;
		int* price_kg;
		double double_number_to_sell;
		struct node_struct* head = NULL;
	public:
		node();
		void insert(items* ob);
		node_struct* getting_previous(node_struct* check);
		void delete_node(string type, double amount, string units);
		void delete_using_calories(string type, double amount, string units);
		void counting(string name, int check);
		void item_from_location(int location_x, int location_y);
		void print();
};

#endif
