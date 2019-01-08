#ifndef N_STORE_H
#define N_STORE_H
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <deque>
#include "sQueue.h"
#include "items.h"
#include "fruit.h"
#include "vegetables.h"
using namespace std;


class n_store{
    private:
        int location_x, location_y, price_per_unit, price_per_kg, i_fr, i_veg;
        string type;
        double volume_per_kg, amount_to_add, units_to_add, calories, weight_per_unit;
        fruit *obj_fr;
        vegetables *obj_veg;
        ifstream file_input;
        sQueue<fruit> object_fr;
        sQueue<vegetables> object_veg;

    public:
        n_store(string file);

        int fruit_from_files();

        int veg_from_files();
        
        void Give_Output(int input, int check);

        void add_element(int check);
};

#endif
