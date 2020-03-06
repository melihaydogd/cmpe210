/*
 *	File : SortedType.h
*/
#include "MyNumberType.cpp"
#define MAX_ITEMS 20

using namespace std;

class SortedType {
	private:
		int length;
		MyNumberType info[MAX_ITEMS];
		int currentPos;
	public:
		SortedType();
		bool IsFull();
		int LengthIs();
		void RetrieveItem(MyNumberType&, bool&);
		void InsertItem(MyNumberType);
		void DeleteItem(MyNumberType);
		void MakeEmpty();
		void PrintList();
};
