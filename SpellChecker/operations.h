#ifndef OPERATION_H
#define OPERATION_H
#include <iostream>
#include "entry.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <stdarg.h>
#include <bits/stdc++.h> 
#include <vector>
using namespace std;


class operation{
    private:
        int size;
        int element_number = 0;
        vector<entry*> hash_table;
        unsigned int hash_function1(string& str){
            unsigned int hash = 0;
            for(int i = 0; i < str.length(); i++){
                hash = (hash << 5) | (hash >> 27);
                hash += (unsigned int)str[i]; 
            }
            return hash;
        }
        int hash_function2(string& str){
            int key_value = hash_function1(str);
            int q = 13;
            return (q - (key_value % q));
        }
    public:
        operation();
        void set_size(int size_input);
        void add_element(entry* object);
        void add_or_replace(entry* object);
        void remove(string input);
        int size_of_dict();
        void print();
        int Minimum (int a, int b, int c);
        int* GetCellPointer (int *pOrigin, int col, int row, int nCols);
        void PutAt (int *pOrigin, int col, int row, int nCols, int x);
        int GetAt (int *pOrigin, int col, int row, int nCols);
        int distance(const string& c1,const string& c2);
        void spellCheck(string& s);
        //unsigned int edit_distance(const std::string& s1, const std::string& s2);
};


#endif