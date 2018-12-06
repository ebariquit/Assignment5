// Evan Bariquit
// CS300 - Assignment 4 & 5

//		Defines a Product object.
//		Used to assign values (product description)
//		to keys (UPC's). Also 

#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <iostream>
using namespace std;

class Product{
	public:
		// Fields
		long key;
		string info;
		// Constructors
		Product():key(0),info(""){}
		Product(long k, string i):key(k),info(i){}
		// Modifiers
		void setUPC(long k){ key = k; }
		void setInfo(string i){ info = i; }
		// Accessors
		long getUPC(){ return key; }
		string getInfo(){ return info; }
		// Comparators
		bool operator<(Product &p){ 
			return (this->key < p.key);
		}
		bool operator>(Product &p){
			return (this->key > p.key);
		}
		bool operator==(Product &p){
			return (this->key == p.key);
		}
	
};
#endif
