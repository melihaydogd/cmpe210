/*
 *	File : StackType.h
*/
#include "Book.cpp"
#include <string>
#include <iostream>
#include <typeinfo>
#include <vector>
#define MAX_ITEMS 20

using namespace std;

class FullStack {
	public:
		FullStack(string message) {
			msg = message;
		}
		string GetMsg() const {
			return msg;
		}
	private:
		string msg;
};

class EmptyStack {
	public:
		EmptyStack(string message) {
			msg = message;
		}
		string GetMsg() const {
			return msg;
		}
	private:
		string msg;
};

template <class ItemType>
class StackType {
	private:
		ItemType *info;
		int top;
	public:
		StackType();
		~StackType();
		int LengthIs();
		bool IsFull() const;
		bool IsEmpty() const;
		void Push(ItemType);
		void Pop(ItemType&);
		ItemType Top();
		void MakeEmpty();
		void PrintStack(vector<ItemType>);
		void PrintStack();
		string PushOnFullStack();
};
