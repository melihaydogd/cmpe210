/*
 *	File : SortedType.cpp
*/
#include "SortedType.h"

SortedType::SortedType () {
	length = 0;
}

bool SortedType::IsFull() {
	if (length == MAX_ITEMS) {
		return 1;
	} else {
		return 0;
	}
}

int SortedType::LengthIs() {
	return length;
}

void SortedType::RetrieveItem(MyNumberType& number, bool& found) {
	found = false;
	for(int len = 0; len < length; len++) {
		if(info[len].GetValue() == number.GetValue()) {
			number = info[len];
			found = true;
		}
	}
}

void SortedType::InsertItem(MyNumberType number) {
	info[length] = number;
	bool swapped = true;
	int border = 0;
	while(swapped == true) {
		swapped = false;
		for(int i = 0; i < length; i++) {
			if(info[i].GetValue() > info[i+1].GetValue()) {
				MyNumberType temp = info[i];
				info[i] = info[i+1];
				info[i+1] = temp;
				swapped = true;
			}
		}
	}
	length++;
}

void SortedType::DeleteItem(MyNumberType number) {
	for(int i = 0; i < length; i++) {
		if(info[i].GetValue() == number.GetValue()) {
			for(int j = 1; j < length - i; j++) {
				info[i] = info[i+1];
			}
			length--;
		}
	}
}

void SortedType::MakeEmpty() {
	length = 0;
	cout << "The list is cleared!\n";
}

void SortedType::PrintList() {
	if(length == 0){
		cout << "The list cannot be printed because it is empty.";
	}
	for(int i = 0; i < length; i++) {
		info[i].Print();
		cout << " ";
	}
	cout << "\n";
}
