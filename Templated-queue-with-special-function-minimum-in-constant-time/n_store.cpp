#include "n_store.h"

    n_store::n_store(string file)
    :file_input(file.c_str()) {
	i_fr = 0;
	i_veg = 0;
        obj_fr = new fruit[1000];
        obj_veg = new vegetables[1000];
    }


    int n_store::fruit_from_files(){
        if(!file_input.is_open()){
            cout<<"cannot open fruit file"<<endl;
            return 0;
        }
	while(file_input >> type>> location_x >> location_y>> weight_per_unit>> price_per_unit>> calories>> units_to_add){
            (&obj_fr[i_fr])->add(type, location_x, location_y, weight_per_unit, price_per_unit, calories, units_to_add);
                object_fr.enqueue(obj_fr[i_fr]);
                i_fr++;
        }
       
    }
    int n_store::veg_from_files(){
        if(!file_input.is_open()){
            cout<<"cannot open vegetable file"<<endl;
            return 0;
        }
        while(file_input >>type>> location_x>> location_y>> price_per_kg>> volume_per_kg>> calories>> amount_to_add){
            obj_veg[i_veg].add(type, location_x, location_y, price_per_kg, volume_per_kg, calories, amount_to_add);
                object_veg.enqueue(obj_veg[i_veg]);
                i_veg++;
        }
    }

    void n_store::Give_Output(int input, int check){
        if(input == 1){
            if(check == 1)
                object_fr.dequeue();
            else
                object_veg.dequeue();
        }
        else if(input == 2){
            if(check == 1){
                if(object_fr.size_deque()>0){
                    cout<<"#########   Printing Minimum Element  ########"<<endl;
                    object_fr.min().Print();
                    cout<<"##############################################"<<endl<<endl;
                }
            }
            else{
                if(object_veg.size_deque()>0){              
                    cout<<"#########   Printing Minimum Element  ########"<<endl;  
                    object_veg.min().Print();
                    cout<<"##############################################"<<endl<<endl;

                }
            }
        }
        else if(input == 3){
            if(check == 1)
                object_fr.show();
            else
                object_veg.show();
        }
    }


    void n_store::add_element(int check){		// add an item from user
	
        if(check == 1){
            cout << "enter -> type, location_x, location_y, weight_per_unit, price_per_unit, calories, units_to_add"<<endl;
            cin >>type>> location_x >> location_y>> weight_per_unit>> price_per_unit>> calories>> units_to_add;
            (&obj_fr[i_fr])->add(type, location_x, location_y, weight_per_unit, price_per_unit, calories, units_to_add);
            object_fr.enqueue(obj_fr[i_fr]);
            i_fr++;
        }

        if(check == 2){
            cout << "enter -> type, location_x, location_y, price_per_kg, volume_per_kg, calories, amount_to_add" <<endl;
            ofstream file("vegetables.txt", fstream::app);
            cin>>type>> location_x>> location_y>> price_per_kg>> volume_per_kg>> calories>> amount_to_add;
            obj_veg[i_veg].add(type, location_x, location_y, price_per_kg, volume_per_kg, calories, amount_to_add);
            object_veg.enqueue(obj_veg[i_veg]);
            i_veg++;
        }
	}
