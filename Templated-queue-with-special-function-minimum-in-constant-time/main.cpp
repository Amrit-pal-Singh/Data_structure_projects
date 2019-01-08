#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <deque>
#include "n_store.h"
#include "fruit.h"
#include "vegetables.h"
#include "sQueue.h"
#include "items.h"
using namespace std;



int main(){
    n_store object1("fruits.txt");
    n_store object2("vegetables.txt");
    object1.fruit_from_files();
    object2.veg_from_files();
    if(object1.fruit_from_files() == 0 || object2.veg_from_files() == 0){
    }
    int j = 0;
    int input;
    int check;
    while(1){
        cout<<endl<<"1. Remove element"<<endl;
        cout<<"2. Show minimum"<<endl;
        cout<<"3. Show all element"<<endl;
        cout<<"4. Add element"<<endl;
        cout<<"5. Enter 99 to exit"<<endl<<endl;
        cin>>input;

        switch(input){
            case 1:
                cout<<"1 -> Fruits "<<endl<<"2 -> Vegetables"<<endl;
                cin>>check;
                if(check == 1){
                    object1.Give_Output(1, check);
                }
                else if(check == 2){
                    object2.Give_Output(1, check);
                }
                else{
                    cout<<endl<<"Wrong input"<<endl<<endl;
                }
                break;
            case 2:
                cout<<"1 -> Fruits "<<endl<<"2 -> Vegetables"<<endl;
                cin>>check;
                if(check == 1){
                    object1.Give_Output(2, check);
                }
                else if(check == 2){
                    object2.Give_Output(2, check);
                }
                else{
                    cout<<endl<<"Wrong input"<<endl;
                }
                break;
            case 3:
                cout<<"1 -> Fruits "<<endl<<"2 -> Vegetables"<<endl;
                cin>>check;
                if(check == 1){
                    object1.Give_Output(3, check);
                }
                else if(check == 2){
                    object2.Give_Output(3, check);
                }
                else{
                    cout<<endl<<"Wrong input"<<endl;
                }
                break;
            case 4:
                cout<<"1 -> Fruits "<<endl<<"2 -> Vegetables"<<endl;
                cin>>check;
                if(check == 1){
                    object1.add_element(1);
                }
                else if(check == 2){
                    object2.add_element(2);
                }
                else{
                    cout<<endl<<"Wrong input"<<endl;
                }
                break;
            case 99:
                return 0;
            default:
                continue;
        }   
    }   
}
