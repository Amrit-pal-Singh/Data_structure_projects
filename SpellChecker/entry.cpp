#include "entry.h"
void entry::add_word(string word_in){
    this->word = word_in;
}

void entry::add_meaning(string meaning_in){
    this->meaning = meaning_in;
}

string entry::get_meaning(){
    return meaning;
}

string entry::get_word(){
    return word;
}
