/*
 *	File : main.cpp
*/
#include <iostream>
#include "SortedType.cpp"
#include <vector>
using namespace std;

int main () {
	//Creating the list and numbers. Then, filling them.
	SortedType list;

	vector<MyNumberType> number(20);

	int arr[] = {5,8,4,10,64,34,23,54,43,21,76,43,56,32,14,23,65,37,98};

	int i;

	for(i = 0; i < sizeof(arr)/sizeof(int); i++) {
		number[i].EnterValue(arr[i]);
		list.InsertItem(number[i]);
	}
	
	cout << "The list is created:\n";
	list.PrintList();
	
	//Cheching whether the list is full or not.
	cout << "Controlling the fullness: ";
	if(list.IsFull() == 1) {
		cout << "The list is full." << "\n";
	} else {
		cout << "The list is not full." << "\n";
	}
	cout << "The length: " << list.LengthIs() << ".\n\n";

	//Adding one more item to full the list.
	cout << "Adding 30 to the list:\n";
	number[i] = 30;
	list.InsertItem(number[i]);
	list.PrintList();
	
	//Checking whether the list full or not.
	cout << "Controlling the fullness: ";
	if(list.IsFull() == 1) {
		cout << "The list is full." << "\n";
	} else {
		cout << "The list is not full." << "\n";
	}
	cout << "The length: " << list.LengthIs() << ".\n\n";
	
	//Deleting an item.
	cout << "Deleting " << number[5].GetValue() << " from the list:\n";
	list.DeleteItem(number[5]);
	list.PrintList();
	cout << number[5].GetValue() << " is deleted." << "\n\n";
	
	
	//Retrieving an item.
	MyNumberType number1(65);
	cout << "Retrieving " << number1.GetValue() << " from the list:\n";
	bool isfound;
	list.RetrieveItem(number1,isfound);
	if(isfound == true) {
		cout << "The item is found and retrieved.\n\n";
	} else {
		cout << "The item is not found.\n\n";
	}
	
	//Retrieving an item.
	MyNumberType number2(35);
	cout << "Retrieving " << number2.GetValue() << " from the list:\n";
	list.RetrieveItem(number2,isfound);
	if(isfound == true) {
		cout << "The item is found and retrieved.\n\n";
	} else {
		cout << "The item is not found.\n\n";
	}

	//Making the list empty.
	cout << "Clearing the list:\n";
	list.MakeEmpty();
	list.PrintList();	

	return 0;
}
