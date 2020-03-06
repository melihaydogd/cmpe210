/*
 *	File : Book.cpp
*/
#include "Book.h"

Book::Book() {
}

Book::Book(string n) {
	name = n;
}

void Book::EnterName(string n) {
	name = n;
}

void Book::Print() {
	cout << name;
}

string Book::GetName() {
	return name;
}
