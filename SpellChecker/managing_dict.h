#ifndef MANAGING_DICT_H
#define MANAGING_DICT_H
#include <fstream>
#include <iostream>
#include <string> 
#include "operations.h"
#include "entry.h"
using namespace std;

class managing{
    private:
        int table_size;
        operation obj_o;
        ifstream file;
        entry* obj_entry;
        int index;

    public:
        managing(const char* name, int table_size);
        void add_or_replace();
        void add_elements();
        void remove_elemnt();
        void print_size();
        void print();
        void spell_check(string& word);
        
};


#endif