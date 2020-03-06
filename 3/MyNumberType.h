/*
 *	File : MyNumberType.h
*/
#include <iostream>

using namespace std;

class MyNumberType {
	private:
		int value;
	public:
		MyNumberType();
		MyNumberType(int);
		void EnterValue(int);
		void Print();
		int GetValue();
};
