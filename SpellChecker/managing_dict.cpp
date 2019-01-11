#include "managing_dict.h"

managing::managing(const char* word, int size)
:table_size(size), file(word)
{
    index = 0;
    obj_entry = new entry[10000];
    obj_o.set_size(size);
}

void managing::add_elements(){
    obj_o.set_size(table_size); 
    string str;
    while(file){
        getline(file, str);
        stringstream ss(str);
        string key;
        string meaning;
        string temp;
        int i = 0, i_m = 0;
        ss>>key;
        //cout<<key<<" -> ";
        while(ss>>temp){
            meaning =meaning + temp +" ";
        }
        //cout<<meaning<<endl;
        obj_entry[index].add_word(key);
        obj_entry[index].add_meaning(meaning);
        obj_o.add_element(&obj_entry[index++]);
    }
    obj_o.print();
}

void managing::add_or_replace(){
    cout<<"ENTER THE WORD"<<endl;
    string word;
    cin>>word;
    cout<<"ENTER THE MEANING"<<endl;
    string meaning;
    cin.ignore();
    getline(cin, meaning);
    obj_entry[index].add_word(word);
    obj_entry[index].add_meaning(meaning);
    obj_o.add_element(&obj_entry[index++]);
}


void managing::remove_elemnt(){
    cout<<"ENTER THE WORD"<<endl;
    string word;
    cin>>word;
    obj_o.remove(word);
}

void managing::print_size(){
    cout<<"SIZE OF THE DICTIONARY IS "<<obj_o.size_of_dict()<<endl;
}


void managing::print(){
    obj_o.print();
}


void managing::spell_check(string& word){
    obj_o.spellCheck(word);
}