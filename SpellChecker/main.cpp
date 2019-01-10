#include <iostream>
#include <fstream> 
#include "managing_dict.h"
using namespace std;


int main(){
    // cout<<"enter the length of hash table"<<endl;
    int length;
    // cin>>length;
    length = 100000;
    managing m("words.txt", length);
    m.add_elements();
    while(1){
        int choice;
        string word;
        cout<<endl<<
        "PRESS 1 TO ADD NEW ITEM OR REPLACE CURRENT ELEMENT"<<endl<<
        "PRESS 2 TO REMOVE ITEM"<<endl<<
        "PRESS 3 TO CHECK THE SIZE"<<endl<<
        "PRESS 4 TO CHECK THE SPELL"<<endl<<
        "PRESS 5 TO PRINT ALL ELEMENTS"<<endl<<
        "PRESS 99 TO EXIT"<<endl<<endl;
        cin >> choice;
        switch(choice){
            case 1:
                m.add_or_replace();
                break;
            case 2:
                m.remove_elemnt();
                break;
            case 3:
                m.print_size();
                break;
            case 4:
                cout<<"ENTER THE WORD"<<endl;
                cin>>word;
                m.spell_check(word);
                break;
            case 5:
                m.print();
                break;
            case 99:
                return 0;
            default:
                cout<<"WRONG INPUT"<<endl;
                break;
        }
    
    }
}