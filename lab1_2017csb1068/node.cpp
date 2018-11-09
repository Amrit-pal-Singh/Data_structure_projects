#include "node.h"

		node::node(){
			i=0;
			j =0;
			count = 0;
			count1 = 0;
			count_claories = 0;
			amount = 0;
			temp = head;
		}


        //to add new items
		void node::insert(items* ob){
			temp = new node_struct;
			if(head == NULL){
				temp->object = ob;
				temp->next = NULL;
				head = temp;
			}
			else{
				temp = head;
				while(temp->next != NULL){
					temp = temp->next;
				}
				temp1 = new node_struct;
				temp1->object = ob;
				temp1->next = NULL;
				temp->next = temp1;
			}
		}


		//to get the previous item (used in deleting a node for printing)
		node:: node_struct* node:: getting_previous(struct node_struct* check){
			prev = NULL;
			temp = head;
			while(temp != check){
				if(check == head){
					prev = NULL;
					temp = temp->next;
				}
				else{
					prev = temp;
					temp = temp->next;
				}
			}
			return prev;
		}


        //to sell items
		void node::delete_node(string type, double amount, string units){  
			i=0;
			temp = head;
			while(temp != NULL){
				if((temp->object)->Name()==type){
					duplicate[i] = temp;         //to save one having same name as type(inputed)
					i++;
				}
				temp = temp->next;
			}
			j=0;

            //sort according to price
			for(j=0; j<i-1; j++){      
				for(int z=0; z<i-j-1; z++){
					if((duplicate[z])->object->Price() > duplicate[z+1]->object->Price()){
						temp = duplicate[z];
						duplicate[z] = duplicate[z+1];
						duplicate[z+1] = temp;
					}
				}
			}
			j=0;
			count = 0;


			while(j<i){
				node_struct* prev = getting_previous(duplicate[j]);
				count = count + duplicate[j]->object->Units();
				if(count < amount){
					if(prev==NULL){  //if we have to use the head node
						head = head->next;
						cout << duplicate[j]->object->Units() <<" "<<units<<" of "<<type<<" at price of per unit " << duplicate[j]->object->Price() <<endl;
						free(duplicate[j]);
					}

					else{
						prev -> next = (prev->next)->next;
						cout << duplicate[j]->object->Units() <<" "<<units<<" of "<<type<<" at price of per unit " << duplicate[j]->object->Price() <<endl;
						free(duplicate[j]);
					}
				}
				else{   //to change the amount left of item purchased
					cout <<amount-(count-(duplicate[j]->object->Units()))<<" "<<units<<" of " <<" " << type<< " at price per unit " << duplicate[j]->object->Price() <<endl;
					duplicate[j]->object->ChangeUnits(count-amount);
					break;
				}
				j++;
			}
			if(count < amount){
				cout <<"we do not have "<< amount-count <<" " <<type<<" in our shop  " <<endl;
			}
			temp = head;
		}


		//sell items using calories
		void node::delete_using_calories(string type, double amount, string units){
			//as we need the maximum amount/count we have to sort the sequence according to calories
			//and then calculate the number of items
			i=0;
			count1 = 0;
			temp = head;
			while(temp != NULL){
				if((temp->object)->Name()==type){
					duplicate[i] = temp;
					i++;
				}
				temp = temp->next;
			}
			j=0;
			//sort the duplicate
			for(j=0; j<i-1; j++){
				for(int z=0; z<i-j-1; z++){
					if((duplicate[z])->object->Calories() > duplicate[z+1]->object->Calories()){
						temp = duplicate[z];
						duplicate[z] = duplicate[z+1];
						duplicate[z+1] = temp;
					}
				}
			}
			j=0;
			while(j<i){
				number_of_calories[j] = (duplicate[j]->object->Calories())*(duplicate[j]->object->Units());
				j++;
			}
			j=0;
			temp = head;
			j=0;
			count = 0;
			while(j<i){
				node_struct* prev = getting_previous(duplicate[j]);
				count = count + number_of_calories[j];
				if(count < amount){
					if(prev==NULL){ //if we have to use the head node
						head = head->next;
						double_number_to_sell = number_of_calories[j]/(duplicate[j]->object->Calories());
						cout << double_number_to_sell <<" "<<units<<" of "<<type<<" at price of "
							<< duplicate[j]->object->Price()<<" Total Calories -" << number_of_calories[j]<<endl<<"calorie per unit = "<<duplicate[j]->object->Calories()<<endl;
						free(duplicate[j]);
					}
					else{
						prev -> next = (prev->next)->next;
						double_number_to_sell = number_of_calories[j]/(duplicate[j]->object->Calories());
						cout << double_number_to_sell <<" "<<units<<" of "<<type<<" at price of " 
							<< duplicate[j]->object->Price()<<" Total Calories -" << number_of_calories[j] <<endl<<"calorie per unit = "<<duplicate[j]->object->Calories()<<endl;
						free(duplicate[j]);
					}
				}
				else{
					count1 = amount - (count - number_of_calories[j]);
					double_number_to_sell = (double)(count1/(duplicate[j]->object->Calories()));
					cout <<double_number_to_sell<<" "<<units<<" of " <<" " << type<< " at price of "<< (duplicate[j]->object->Price())<<" Total Calories = " << count1 <<endl
						<<"calorie per unit = "<<duplicate[j]->object->Calories()<<endl;
					duplicate[j]->object->ChangeUnits((count-amount)/duplicate[j]->object->Calories());
					break;
				}
				j++;
			}
			if(count < amount){
				cout <<(amount-count)<<" calories left, you can buy some other item" <<endl;
			}
			temp = head;
		}

		
		//count the amount of a particular item
		void node::counting(string name, int check){
			temp = head;
			while(temp != NULL){
				if(((temp->object)->Name())==name){ 
					if(check == 1)
						cout <<" number of units " << (temp->object)->Units() << ", at price of " << (temp->object)->Price() << " per unit" << endl;
					if(check == 2)
						cout <<" amount left " <<((temp->object)->Units()) << " kg,"<< " at price of " << (temp->object)->Price() << " per kg" << endl;
				}
				temp = temp->next;
			}
		}


		//print item from a particular location 
		void node::item_from_location(int location_x, int location_y){
			temp = head;
			while(temp!=NULL){
				if(((temp->object)->LocationX() == location_x) && ((temp->object)->LocationY() == location_y)){
					(temp->object)->Print();
				}
				temp = temp->next;	
			}
			
		}


		//print all items
		void node::print(){
			temp = head;
			while(temp != NULL){
				(temp->object)->Print();
				temp = temp->next;
			}
		}
