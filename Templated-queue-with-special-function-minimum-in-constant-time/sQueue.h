#ifndef SQUEUE_H
#define SQUEUE_H
#include <iostream>
#include <deque>
#include <queue>
#include "items.h"
#include "n_store.h"
#include "fruit.h"
#include "vegetables.h"
using namespace std;



template <typename T>
class sQueue{
    private:
        struct node{
            T data;
            struct node* next;
        };
        deque<T> d;
        struct node* front_node;
        struct node* rear;
        int n;
        int n1;
    
    public:
        sQueue();
        void enqueue(const T& input);
        void dequeue();
        T& front();
        T& min();    
        T& back();   //show back item
        void show(); //show all items
        int size() const; //size
        bool empty() const;	 
        int size_deque();  //size of deque
};



template <typename T>
sQueue<T>::sQueue()
:front_node(NULL), rear(NULL), n(0), n1(0){}

template <typename T>
int sQueue<T>::size() const{
    return n;
}

template <typename T>
int sQueue<T>::size_deque(){
    return n1;
}


template <typename T>
void sQueue<T>::enqueue(const T& input){
    node* temp = new node;
    temp->data = input;
    temp -> next = NULL;
    if(front_node == NULL && rear == NULL){
		front_node = temp;
		rear = temp;
	}
	else{
		rear->next = temp;
		rear = temp;
	}
    n++;
    while(!d.empty() && (d.back()) > input && size_deque()>0){
        n1 = n1-1;
        //cout<<"deleted back"<<d.back().Calories()<<endl;
        d.pop_back();
    }
    d.push_back(input);
    //cout<<"added back"<<d.back().Calories()<<endl;
    n1++;
    
}


template <typename T>
void sQueue<T>::dequeue(){
    node* temp = new node;
    if(size_deque()>0){
        if(d.front() == front_node->data){
            n1--;
            //cout<<"deleted front"<<d.front().Calories()<<endl;
            d.pop_front();
        }
    }
    if(size()<=0){
		cout<< "Queue is empty"<<endl;
        return;
    }
    else if(size() == 1){ //or front == rear
		temp = front_node;
		front_node = NULL;
		rear = NULL;
	}		
	else{
		temp = front_node;
		front_node = front_node->next;
	}
    cout<<endl<<"#### Deleting this item ####"<<endl<<endl;
    temp->data.Print();
    cout<<endl<<"############################"<<endl<<endl;
	free(temp);
	n--;
    
}


template <typename T>
T& sQueue<T>::front(){
    if(size() > 0)
        return front_node->data;
} 


template <typename T>
T& sQueue<T>::min(){
    if(size_deque()>0){
        return d.front();
    }
}

template <typename T>
bool sQueue<T>::empty() const{
    return size()<=0;
}



template <typename T>
T& sQueue<T>::back(){
    if(size() > 0)
        return rear->data;
}

template <typename T>
void sQueue<T>::show(){
    if(size()>0){
        cout<<endl<<"##################      Printing all element         ##################"<<endl;
        node* temp = front_node;
        while(temp!=rear){
            temp->data.Print();
            temp = temp -> next;
        }
        temp->data.Print();    
        cout<<endl<<"####################################################################"<<endl<<endl;
    }
}


#endif
