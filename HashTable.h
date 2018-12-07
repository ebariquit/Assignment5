// Evan Bariquit
// CS300 - Assignment 5

//		HashTable class. Automatically sets size to 1000!
//		Hashing Method: h(x) = x mod tableSize (=1000)
//		Assumption: we already know we need a table of size 1000

//		***NOTE*** :	I believe this file is causing a core
//						dump when trying to compile RunScanners.cpp.

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include <list>
#include <cstdlib>
using namespace std;

template <class T>
struct hashNode{
	T data;
	hashNode<T>* next;
};

template <class T>
class HashTable{
	int size = 1000;
	list<T> *table;
	public:
		HashTable(); // constructor
		HashTable(const HashTable&)=delete;	// copy constructor
		void makeTableEmpty(); 
		void makeListEmpty(list<T>);
		void insert(T&);
		bool search(T&);
		int hashFunction(T&);
		~HashTable() { makeTableEmpty(); }	// destructor	
};

template <class T>
HashTable<T>::HashTable() {
	table = new list<T>[size];
}
template <class T>
void HashTable<T>::makeTableEmpty() {
	for (int i = size - 1; i >= 0; i--){
		makeListEmpty(table[i]);
	}
	delete table;
}

template <class T>
void HashTable<T>::makeListEmpty(list<T> l) {
	while(!l.empty()) {
		l.pop_back();
	}
}

template <class T>
void HashTable<T>::insert(T& item) {
	int index = hashFunction(item);
	table[index].push_front(item);
}

template <class T>
bool HashTable<T>::search(T& item) {
	int index = hashFunction(item);
	typename list<T>::iterator i;
	for(i = table[index].begin(); i 
			!= table[index].end(); i++) {
		if(*i == item) {
			return true;
		}
		else { return false; }
	}
}

template <class T>
int HashTable<T>::hashFunction(T& item) {
	return abs(item.key % size);
}

#endif

