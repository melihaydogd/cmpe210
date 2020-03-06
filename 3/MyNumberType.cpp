/*
 *	File : MyNumberType.cpp
*/
#include "MyNumberType.h"

MyNumberType::MyNumberType() {
	value = 0;
}

MyNumberType::MyNumberType(int number) {
	value = number;
}

void MyNumberType::EnterValue(int number) {
	value = number;
}

void MyNumberType::Print() {
	cout << value;
}

int MyNumberType::GetValue() {
	return value;
}
