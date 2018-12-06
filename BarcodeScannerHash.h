// Evan Bariquit
// CS 300 - Assignment5

//		HashTable Scanner class.
//		Creates a HashTable and defines searching method.

#ifndef BARCODESCANNERHASH_H_
#define BARCODESCANNERHASH_T_

#include "HashTable.h"
#include "Product.h"
#include <iostream>
using namespace std;

class BarcodeScannerHash{
	public:
		// fields
		HashTable<Product> ht;
		// constructor
		BarcodeScannerHash() {}
		// Scanning method
		bool scan(long upc){
			Product *p = new Product();
			p->setUPC(upc);
			return ht.search(*p);
			delete p;				
		}
};
#endif
