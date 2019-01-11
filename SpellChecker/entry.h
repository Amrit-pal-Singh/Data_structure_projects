#ifndef ENTRY_H
#define ENTRY_H
#include <iostream>
using namespace std;


class entry{
    private:
        string word;
        string meaning;
    public:
        void add_word(string word_in);
        void add_meaning(string meaning_in);  
        string get_word();
        string get_meaning();
};


#endif