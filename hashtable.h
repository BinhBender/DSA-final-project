#pragma once
#include <string>
#include <iostream>

//TABLE_SIZE should depend on the wanted speed and wanted memory efficiency
#define HASH_TABLE_SIZE 64 
template<typename T1, typename T2>
class HashTable{

public: 
	HashTable<T1,T2>();
	
	~HashTable<T1,T2>();
	

	//insert an element into the table
	void insert(T1);

	//insert element AND the data
	//This could also be used to find an existing key and enter the data into its map.
	void insert(T1, T2);

	//Find element in the list based on an input key
	T2& find(T1);

	//Erase an element 
	void erase(T1);
	//Essentially the same as end() in map.
	//Returns an empty value of the key
	T2 findNull();
	void clear();
	void clearTable();
private:

	struct Node{
	   public:
		T1 key;
		T2 data;
		
	    Node* next = nullptr;

	};
	//This will act as our nullptr
	T2 empty;

	Node** table;

	int TABLE_SIZE;
	//int hash_function(T1);

	//Hash Function, returns any byte sized thing into a 64 byte number
	unsigned long long fnv_hash_1a_64 (const void *key, int len );


};


template<typename T1, typename T2>
HashTable<T1,T2>::HashTable(){
	//The TABLE_SIZE is an arbitrary number,
	//Making it larger will have less chainning but more memory space
	//Smaller will involve more chaining but more space filled up
	TABLE_SIZE = HASH_TABLE_SIZE;
	table = new HashTable<T1,T2>::Node*[TABLE_SIZE]();
	empty = T2();

}
template<typename T1, typename T2>
HashTable<T1,T2>::~HashTable(){

	clear();

	delete[] table;
	
	table = nullptr;
	
}

template<typename T1, typename T2>
void HashTable<T1,T2>::insert(T1 keyinsert){
	int index = fnv_hash_1a_64(&keyinsert, sizeof(T1));
	HashTable<T1,T2>::Node* new_node = new Node;
	new_node->key = keyinsert;

	//If not elements exists in this index already, then add it.
	if(table[index] == nullptr) {
		table[index] = new_node;
		return;
	}

	//Checks if the first node is a thing or not
	if(table[index]->key == keyinsert){
		delete new_node;
		return;
	}
	//Loop to end of the chain
	HashTable<T1,T2>::Node* trav = table[index];
	while(trav->next != nullptr){

		//If it already exists then we return
		if(trav->key == keyinsert) return;
		
		//Traverse to the next node
		trav = trav->next;
		
	}
	//After the loop we've reached the end of the chaining so we append
	trav->next = new_node;

	return;
}
template<typename T1, typename T2>
T2 HashTable<T1,T2>::findNull(){
	return empty;
}
template<typename T1, typename T2>
void HashTable<T1,T2>::insert(T1 keyinsert, T2 datainsert){
    
	int index = fnv_hash_1a_64(&keyinsert, sizeof(T1));

	//Create and load node with data
	HashTable<T1,T2>::Node* new_node = new HashTable<T1,T2>::Node;
	new_node->key = keyinsert;
	new_node->data = datainsert;
	
	//If not elements exists in this index already, then add it.
	if(table[index] == nullptr) {
		table[index] = new_node;
		return;
	}

	//Checks if the first node is a thing or not
	if(table[index]->key == keyinsert){
		delete new_node;
		return;
	}
	//Loop to end of the chain
	Node* trav = table[index];
	while(trav->next != nullptr){

		//If it already exists then put new data in and 
		//we return
		if(trav->key == keyinsert) {
			trav->data = datainsert;
			delete new_node;
			return;
		}
		
		//Traverse to the next node
		trav = trav->next;
		
	}
	//After the loop we've reached the end of the chaining so we append
	trav->next = new_node;

	return;
}


//Created by Fowler, Noll, and Vol 
//void pointers basically holds a general pointer
template<typename T1, typename T2>
unsigned long long HashTable<T1,T2>::fnv_hash_1a_64 (const void *key, int len ) {

//turns the void key pointer into a char pointer
//This char pointer holds the same bit data that key pointed to
//And so p is now an array of chars 
    const unsigned char *p = reinterpret_cast<const unsigned char*>(key);

	//math number
    unsigned long long h = 0xcbf29ce484222325ULL;
    int i;
	//This loops through every byte of the 
	//char array using the funny numbers in funny ways
    for ( i = 0; i < len; i++ )
		//voodoo magic 
	  h = ( h ^ p[i] ) * 0x100000001b3ULL;
	h = h % TABLE_SIZE;
   return h;
}



template<typename T1, typename T2>
T2& HashTable<T1,T2>::find(T1 keyinsert){
	
	int index = fnv_hash_1a_64(&keyinsert,sizeof(T1));

	Node* trav = table[index];

	//Loop through the chain at the index until we
	//find the node with the same key or a nullptr
	while(trav != nullptr){
		
		if(trav->key == keyinsert){
			
			//if it finds the value before it reaches the end
			//early return the address
			return trav->data;
			
		}else{
			
			//If it hasn't found the value, go to the next node
			trav = trav->next;
			
		}
	}
	//if it had been exhausted, then trav is nullptr

	std::cout << "Returning empty\n";
	return empty;
	
}

template<typename T1, typename T2>
void HashTable<T1,T2>::erase(T1 keyinsert){
	int h = fnv_hash_1a_64(&keyinsert, sizeof(T1));
	HashTable<T1,T2>::Node* trav = table[h];
	
	//checks for if the table at h is empty
	if(trav == nullptr) return;
	
	//checks if the first block in the chain is the input or not
	if(trav->key == keyinsert) {
		
		//moves the pointer to the next node
		table[h] = trav->next;
		
		//delete old node
		delete trav;
		return;
	}
	
	
	//Holds the previous node
	HashTable<T1,T2>::Node *holder = trav;
	
	while(trav != nullptr){
		if(trav->key == keyinsert){
			//Sets the previous node to point to the one after the target node
			holder->next = trav->next;
			delete trav;
			break;
		}
		holder  = trav;
		//Advances to the next node
		trav = trav->next;
		
	}
}

template<typename T1, typename T2>
void HashTable<T1,T2>::clear(){

	//For each index...
	for(int i = 0; i < TABLE_SIZE; i++){
		
		HashTable<T1,T2>::Node* deleter;
		HashTable<T1,T2>::Node* traverser = table[i];

		//...we will delete each node in the chain
		while(traverser != nullptr){
			
			deleter = traverser;
		
			traverser = traverser->next;
			
			delete deleter;
		}
		table[i] =nullptr;
	}
}

template<typename T1, typename T2>
void HashTable<T1,T2>::clearTable(){
	delete[] table;
}
//====================================================
//For the string exception 

template<typename T2>
class HashTable<std::string, T2>{

public: 
	HashTable<std::string,T2>();
	
	~HashTable<std::string,T2>();
	

	//insert an element into the table
	void insert(std::string);

	//insert element AND the data
	//This could also be used to find an existing key and enter the data into its map.
	void insert(std::string, T2);

	//Find element in the list based on an input key
	T2& find(std::string);

	//Erase an element 
	void erase(std::string);
	//Essentially the same as end() in map.
	//Returns an empty value of the key
	T2 findNull();

	void clear();

	void clearTable();
private:

	struct Node{
	   public:
		std::string key;
		T2 data;
		
		
	    Node* next = nullptr;

	};
	//This will act as our nullptr
	T2 empty;

	Node** table;

	int TABLE_SIZE;
	//int hash_function(T1);

	//Hash Function, returns any byte sized thing into a 64 byte number
	unsigned long long fnv_hash_1a_64 (const void *key, int len );


};


template<typename T2>
HashTable<std::string,T2>::HashTable(){
	//The TABLE_SIZE is an arbitrary number,
	//Making it larger will have less chainning but more memory space
	//Smaller will involve more chaining but more space filled up
	TABLE_SIZE = HASH_TABLE_SIZE;
	table = new HashTable<std::string,T2>::Node*[TABLE_SIZE]();
	empty = T2();

}
template< typename T2>
HashTable<std::string,T2>::~HashTable(){

	clear();

	delete[] table;
	
	table = nullptr;
	
}

template<typename T2>
void HashTable<std::string,T2>::insert(std::string keyinsert){
	int index = fnv_hash_1a_64(&keyinsert, keyinsert.size());
	HashTable<std::string,T2>::Node* new_node = new Node;
	new_node->key = keyinsert;

	//If not elements exists in this index already, then add it.
	if(table[index] == nullptr) {
		table[index] = new_node;
		return;
	}

	//Checks if the first node is a thing or not
	if(table[index]->key == keyinsert){
		delete new_node;
		return;
	}
	//Loop to end of the chain
	HashTable<std::string,T2>::Node* trav = table[index];
	while(trav->next != nullptr){

		//If it already exists then we return
		if(trav->key == keyinsert) return;
		
		//Traverse to the next node
		trav = trav->next;
		
	}
	//After the loop we've reached the end of the chaining so we append
	trav->next = new_node;

	return;
}
template<typename T2>
T2 HashTable<std::string,T2>::findNull(){
	return empty;
}
template<typename T2>
void HashTable<std::string,T2>::insert(std::string keyinsert, T2 datainsert){
    
	int index = fnv_hash_1a_64(keyinsert.data(), keyinsert.size());
	
	HashTable<std::string,T2>::Node* new_node = new HashTable<std::string,T2>::Node;
	new_node->key = keyinsert;
	new_node->data = datainsert;
	
	//If not elements exists in this index already, then add it.
	if(table[index] == nullptr) {
		table[index] = new_node;
		return;
	}

	//Checks if the first node is a thing or not
	if(table[index]->key == keyinsert){
		delete new_node;
		return;
	}
	//Loop to end of the chain
	Node* trav = table[index];
	while(trav->next != nullptr){

		//If it already exists then put new data in and 
		//we return
		if(trav->key == keyinsert) {
			trav->data = datainsert;
			delete new_node;
			return;
		}
		
		//Traverse to the next node
		trav = trav->next;
		
	}
	//After the loop we've reached the end of the chaining so we append
	trav->next = new_node;

	return;
}

//Created by Fowler, Noll, and Vol 
//void pointers basically holds a general pointer
template<typename T2>
unsigned long long HashTable<std::string,T2>::fnv_hash_1a_64 (const void *key, int len ) {

//turns the void key pointer into a char pointer
//This char pointer holds the same bit data that key pointed to
//And so p is now an array of chars 
    const unsigned char *p = reinterpret_cast<const unsigned char*>(key);

	//math number
    unsigned long long h = 0xcbf29ce484222325ULL;
    int i;

    for ( i = 0; i < len; i++ )
		//voodoo magic 
	  h = ( h ^ p[i] ) * 0x100000001b3ULL;
	h = h % TABLE_SIZE;
   return h;
}



template<typename T2>
T2& HashTable<std::string,T2>::find(std::string keyinsert){
	
	int index = fnv_hash_1a_64(keyinsert.data(), keyinsert.size());

	Node* trav = table[index];
	
	//Loop through the chain at the index until we
	//find the node with the same key or a nullptr
	while(trav != nullptr){
		
		if(trav->key == keyinsert){
			
			//if it finds the value before it reaches the end
			//early return the address
			return trav->data;
			
		}else{
			
			//If it hasn't found the value, go to the next node
			trav = trav->next;
			
		}
	}
	//if it had been exhausted, then trav is nullptr

	std::cout << "Returning empty\n";
	return empty;
	
}

template<typename T2>
void HashTable<std::string,T2>::erase(std::string keyinsert){
	int h = fnv_hash_1a_64(keyinsert.data(), keyinsert.size());
	HashTable<std::string,T2>::Node* trav = table[h];
	
	//checks for if the table at h is empty
	if(trav == nullptr) return;
	
	//checks if the first block in the chain is the input or not
	if(trav->key == keyinsert) {
		
		//moves the pointer to the next node
		table[h] = trav->next;
		
		//delete old node
		delete trav;
		return;
	}
	
	
	//Holds the previous node
	HashTable<std::string,T2>::Node *holder = trav;
	
	while(trav != nullptr){
		if(trav->key == keyinsert){
			//Sets the previous node to point to the one after the target node
			holder->next = trav->next;
			delete trav;
			break;
		}
		holder  = trav;
		//Advances to the next node
		trav = trav->next;
		
	}
}
template<typename T2>
void HashTable<std::string,T2>::clear(){

	//For each index...
	for(int i = 0; i < TABLE_SIZE; i++){
		
		HashTable<std::string,T2>::Node* deleter;
		HashTable<std::string,T2>::Node* traverser = table[i];

		//...we will delete each node in the chain
		while(traverser != nullptr){
			
			deleter = traverser;
		
			traverser = traverser->next;
			
			delete deleter;
		}
		table[i] =nullptr;
	}
}

template< typename T2>
void HashTable<std::string,T2>::clearTable(){
	delete[] table;
}