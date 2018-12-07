// Evan Bariquit
// CS300 - Assignment 4 & 5

//		BST Scanner class.
//		Creates a BST and defines the scanning method.

#ifndef BARCODESCANNERBST_H_
#define BARCODESCANNERBST_H_

#include "BinarySearchTree.h"
#include "Product.h"
#include <iostream>
using namespace std;

class BarcodeScannerBST{
	public:
		// Fields
		BinarySearchTree<Product> bst;
		// Constructor
		BarcodeScannerBST(){}
		// Scanning method
		bool scan(long upc){ 
			Product *p = new Product();
			p->setUPC(upc);			
			return bst.search(*p); 
			delete p;
		}
};
#endif
