/*
 *	File : Book.h
*/
#include <iostream>
#include <string>

using namespace std;

class Book {
	private:
		string name;
	public:
		Book();
		Book(string);
		void EnterName(string);
		void Print();
		string GetName();
};
