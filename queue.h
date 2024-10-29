#include "stack.h"

#pragma once

//front is equivalent is the head
//pops from the front
//pushes from the back
template<typename T>
class Queue : public LinkedList<T>{
public:
/*
	Gets rid of an item in the head of the queue	
 */
	void pop();
/*
	Adds an item to the end of the queue
*/
	void push(T);
/*
	Access the first element in the queue
*/
	T front();
};


template<typename T>
void Queue<T>::pop(){
	LinkedList<T>::pop_front();
}

template<typename T>
T Queue<T>::front(){
	return LinkedList<T>::head->value;
}

template<typename T>
void Queue<T>::push(T val){
	LinkedList<T>::push_back(val);
}
