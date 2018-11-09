#include "grocery_store.h"


		grocery_store::grocery_store(const char* file) //it donot take string as parameter
		:finput(file) {
				obj_fr = new fruit[10000];
				obj_veg = new vegetables[10000];
				i = 0;
				i_to_add_fruit = 0;
				i_to_add_veg = 0;
		} //if string file is used .....then do :finput(file.c_str())


		grocery_store::~grocery_store(){}


		void grocery_store::input_fruit_file(){          //input the files from fruit.txt and save in liked list 
				i_to_add_fruit = 0;
				if(finput.is_open()){
					while(finput >> type>> location_x >> location_y>> weight_per_unit>> price_per_unit>> calories>> units_to_add){
						(&obj_fr[i_to_add_fruit])->add(type, location_x, location_y, weight_per_unit, price_per_unit, calories, units_to_add);
						obj_node.insert(&obj_fr[i_to_add_fruit]);    //this object will be added in node of linked list
						i_to_add_fruit++; 
					}	
				}
				else
					cout << "file cannot be opened" << endl;
		}



		void grocery_store::input_veg_file(){			//input the files from vegetables.txt and save in linked list
				i_to_add_veg = 0;
				if(finput.is_open()){
					while(finput >>type>> location_x>> location_y>> price_per_kg>> volume_per_kg>> calories>> amount_to_add){
						obj_veg[i_to_add_veg].add(type, location_x, location_y, price_per_kg, volume_per_kg, calories, amount_to_add);
						obj_node.insert(&obj_veg[i_to_add_veg]);
						i_to_add_veg++;
					}	
				}
				else
					cout << "file cannot be opened" << endl;
		}



		void grocery_store::add_element(int check){		// add an item from user
	
				if(check == 1){
					cout << "enter -> type, location_x, location_y, weight_per_unit, price_per_unit, calories, units_to_add"<<endl;
				    cin >>type>> location_x >> location_y>> weight_per_unit>> price_per_unit>> calories>> units_to_add;
						(&obj_fr[i_to_add_fruit])->add(type, location_x, location_y, weight_per_unit, price_per_unit, calories, units_to_add);
					obj_node.insert(&obj_fr[i_to_add_fruit]);
					i_to_add_fruit++;
		  		}

				if(check == 2){
					cout << "enter -> type, location_x, location_y, price_per_kg, volume_per_kg, calories, amount_to_add" <<endl;
					ofstream file("vegetables.txt", fstream::app);
				    cin>>type>> location_x>> location_y>> price_per_kg>> volume_per_kg>> calories>> amount_to_add;
				    obj_veg[i_to_add_veg].add(type, location_x, location_y, price_per_kg, volume_per_kg, calories, amount_to_add);
				    obj_node.insert(&obj_veg[i_to_add_veg]);
					i_to_add_veg++;
				    
				}
		}


		void grocery_store::print(){					//print all the items
				obj_node.print();	
		}


		void grocery_store::sell_items(string name, double amount, string units){   //selling items
				obj_node.delete_node(name, amount, units);
		}


		void grocery_store::location(int x_coordinate,int y_coordinate){			// showing item from location
				obj_node.item_from_location(x_coordinate, y_coordinate);
		}


		void grocery_store::sell_items_acc_calories(string name, double amount, string units){  //sell item using linked list
				obj_node.delete_using_calories(name, amount, units);
		}


		void grocery_store::counting_elements(string str, int check){				//count a particular item
				obj_node.counting(str, check);
		}
