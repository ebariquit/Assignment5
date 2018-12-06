// Evan Bariquit
// CS300 - Assignment 4 & 5

//		Array Scanner class.
//		Creates an array and defines scanning method.

#ifndef BARCODESCANNERARRAY_H_
#define BARCODESCANNERARRAY_H_

#include "Product.h"
#include <iostream>
#include <array>
using namespace std;

class BarcodeScannerArray{
	public:
		// Fields
		int aTime;
		Product array[1045950]; // Actual = 1045913
		// Constructor
		BarcodeScannerArray(){}
		// Scanning method
		bool scan(long upc){
			int i = 0;
			while (upc != array[i].getUPC()){
				i++;
			}
			if(upc == array[i].getUPC()) {
				// Responsible for producing product description.
				// Initially used for debugging. 
				cout<<array[i].getInfo()<<endl;
				return true; 
			}	
		}
};
#endif
