#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "items.h"
#include "fruit.h"
#include "vegetables.h"
#include "grocery_store.h"
#include "node.h"
using namespace std;






int main(){	
	grocery_store gs1("fruits.txt");
	grocery_store gs2("vegetables.txt");
	gs1.input_fruit_file();
	gs2.input_veg_file();
	int check = 0;	
	int input = 0;
	while(1){


		cout<<endl
			<< "Press 1 for adding new entries" << endl
			<< "Press 2 for selling items(Fruit/Vegetable)" << endl
			<< "Press 3 to display the amount left of a item" << endl
			<< "Press 4 to display all the items(Fruit and Vegetable)" << endl
			<< "Press 5 to display the items in a Location" << endl
			<< "Press 6 to sell items according to the Calories" << endl
			<<endl
			<<endl;

		cin >> input;
		switch(input){
			case 1:{
					cout << "1 to add FRUIT " << endl << "2 to add VEGETABLES" <<endl;
					int in;
					cin >> in;
					if(in == 1)
						gs1.add_element(1);
					else if(in == 2)
						gs2.add_element(2);
					else{
						cout<<"wrong input"<<endl;
						return 0;
					}
					
			}
			break;
			case 2:{
					cout << "1 to sell FRUIT " <<endl << "2 to sell VEGETABLES" <<endl;
					int in;
					double amount;
					cin >> in;
					if(in == 1){
						cout << "enter the NAME and AMOUNT "<<endl;
						string str;
						cin >> str >> amount;	
						gs1.sell_items(str,amount,"number");
					}

					else if(in == 2){
						cout << "enter the NAME and AMOUNT "<<endl;
						string str;
						cin >> str >> amount;
						gs2.sell_items(str,amount,"kg");
					}

					else{
						cout<<"wrong input"<<endl;
						return 0;	
					}
				}
				break;
			case 3:
				{
					int in;
					cout << "1 for FRUIT " << endl << "2 for VEGETABLES" <<endl;
					cin >> in;
					if(in!=2 && in!=1){
						cout<<"wrong input"<<endl;
						return 0;	
					}
					cout << "Enter the NAME"<<endl;
					string str;
					cin >> str;
					if(in == 1)
						gs1.counting_elements(str, 1);
					else if(in == 2)
						gs2.counting_elements(str, 2);
				}
				break;	
			case 4:
				{
					gs1.print();
					gs2.print();
				}
				break;
			case 5:
				{
					cout << "enter the location_X and location_Y"<<endl;
					int x_coordinate;
					int y_coordinate;
					cin >> x_coordinate >>y_coordinate;
					gs1.location(x_coordinate, y_coordinate);
					gs2.location(x_coordinate, y_coordinate);	
				}
				break;
			case 6:
				{
					int in;
					double amount;
					cout << "1 for FRUIT " << endl << "2 for VEGETABLES" <<endl;
					cin >> in;
					if(in!=2 && in!=1){
						cout<<"wrong input"<<endl;
						return 0;	
					}
					cout << "Enter the NAME and CALORIES AMOUNT"<<endl;
					string str;
					cin >> str >> amount;
					if(in == 1)
						gs1.sell_items_acc_calories(str, amount, "number");
					else if(in == 2)
						gs2.sell_items_acc_calories(str, amount, "kg");	
				}
				break;
			default:
				cout << "enter a valid number" << endl;
		}
	}
}
