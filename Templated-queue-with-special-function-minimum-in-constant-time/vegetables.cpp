#include "vegetables.h"



void vegetables::add(string type,int location_x, int location_y, int price_per_kg, double volume_per_kg,
    double calories, double amount_to_add){
        this->type = type;
        this->location_x = location_x;
        this->location_y = location_y;
        this->price_per_kg = price_per_kg;
        this->volume_per_kg = volume_per_kg;
        this->calories = calories;
        this->amount_to_add = amount_to_add;
}
void vegetables::Print() const{
        cout <<endl<<"                -------  "<<type<<"-------- : " <<endl<< " location_x "<< location_x <<endl<< " location_y " <<location_y <<endl<< " price_per_kg "
        << price_per_kg <<endl<< " volume_per_kg " << volume_per_kg<<endl 
        <<" calories " <<  calories <<endl<< " amount_to_add " <<  amount_to_add <<endl<<endl;
        
}
double vegetables::Calories() const{
        return calories;
}

int vegetables::operator > (const vegetables& i) const{
    if(this->calories > i.Calories()){
        return 1;
    }
    else
        return 0;
}



int vegetables::operator == (const vegetables& i) const{
    if(this->calories == i.Calories()){
        return 1;
    }
    else
        return 0;
}
