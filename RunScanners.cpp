// Evan Bariquit
// CS300 - Assignment 4 & 5

//		Main file for assignments 4 & 5.
//		Compiles the BarcodeScanner classes, stores
//		UPC's (keys) and their product information (values), 
//		then tests the time it takes for each scanner to
//		retrieve this information.

#include "Product.h"
#include "BarcodeScannerArray.h"
#include "BarcodeScannerBST.h"
#include "BarcodeScannerHash.h" 
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
using namespace std;

BarcodeScannerArray arr;
BarcodeScannerBST bst;
BarcodeScannerHash hTable;

int main() {
	// Setup fields, open file
	long upc;
	string description;
	ifstream inFile;
	inFile.open("upc_corpus.txt");
	if(!inFile) {
		cerr<<"Unable to open file"<<endl;
		exit(1);					
	}
	// Fill data structures 
	int i = 0; // for Array insertion
	while (inFile) {
		// Pull data from file
		string upcString;
		getline(inFile, upcString, ',');
		getline(inFile, description, '\n');
		stringstream convert(upcString);
		convert>>upc;
		Product product(upc, description);
		// Insert into data structures
		bst.bst.insert(product);
		arr.array[i]=product;
		hTable.ht.insert(product);		
		i++;
	}
	// Enter(Scan) a UPC
	long searchUPC;
	while (searchUPC != 0) {
		cout<<"Enter a UPC\n[0 to quit]:\t";
		cin>>searchUPC;
		// Record BST runtime
		clock_t bTime;
		bTime = clock();
		bst.scan(searchUPC);
		bTime = clock() - bTime;
		// Record Array runtime
		clock_t aTime;
		aTime = clock();
		arr.scan(searchUPC);
		aTime = clock() - aTime;
		// Record HashTable runtime
		clock_t hTime;
		hTime = clock();
		hTable.scan(searchUPC);
		hTime = clock() - hTime;
		// Print results
		cout<<"BST time: "<<bTime<<" milliseconds"<<endl;
		cout<<"Array time: "<<aTime<<" milliseconds"<<endl;
		cout<<"HashTable time: "<<hTime<<" milliseconds\n\n"<<endl;
	}
	return 0;
}	
	
