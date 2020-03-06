/*
 *	File : StackType.cpp
*/
#include "StackType.h"

template <class ItemType>
StackType<ItemType>::StackType() {
	info = new ItemType [MAX_ITEMS];
	top = -1;
}

template <class ItemType>
StackType<ItemType>::~StackType() {
	cout << "Destructor is called.";
	delete[] info;
}

template <class ItemType>
int StackType<ItemType>::LengthIs() {
	return top+1;
}

template <class ItemType>
bool StackType<ItemType>::IsFull() const {
	if(top == 19) {
		return true;
	} else {
		return false;
	}
}

template <class ItemType>
bool StackType<ItemType>::IsEmpty() const {
	if(top == -1) {
		return true;
	} else {
		return false;
	}
}

/*template <class ItemType>
void StackType<ItemType>::Push(ItemType newItem) {
	if(IsFull()) {
		try {
			throw FullStack("The stack is full.");
		} catch (FullStack& e) {
			cout << "An exception is thrown: " << e.GetMsg();
		}
	} else {
		top++;
		info[top] = newItem;
	}
}*/

template <class ItemType>
string StackType<ItemType>::PushOnFullStack() {
	return "The stack is full.";
}

template <class ItemType>
void StackType<ItemType>::Push(ItemType newItem) {
	if(IsFull()) {
		try {
			throw PushOnFullStack();
		} catch (string e) {
			cout << "An exception is thrown: " << e;
		}
	} else {
		top++;
		info[top] = newItem;
	}
}


template <class ItemType>
void StackType<ItemType>::Pop(ItemType& item) {
	if(IsEmpty()) {
		try {
			throw EmptyStack("The stack is empty.");
		} catch (EmptyStack& e) {
			cout << "An exception is thrown: " << e.GetMsg();
		}
	} else {
		item = info[top];
		top--;
	}
}

template <class ItemType>
ItemType StackType<ItemType>::Top() {
	if(IsEmpty()) {
		try {
			throw EmptyStack("The stack is empty.");
		} catch (EmptyStack& e) {
			cout << "An exception is thrown: " << e.GetMsg();
		}
	} else {
		return info[top];
	}
}

template <class ItemType>
void StackType<ItemType>::MakeEmpty() {
	top = -1;
}

template <class ItemType>
void StackType<ItemType>::PrintStack(vector<ItemType> item) {
	//To print an array whose values are from an abstract data type.
	if(IsEmpty()) {
		try {
			throw EmptyStack("The stack is empty.");
		} catch (EmptyStack& e) {
			cout << "An exception is thrown: " << e.GetMsg();
		}
	} else {
		if(typeid(ItemType).name() == typeid(Book).name()) {
			for(int i = 0; i < top+1; i++) {
				info[i].Print();
				cout << "\n";
			}
		}
	}
}

template <class ItemType>
void StackType<ItemType>::PrintStack() {
	//To print an array whose values are built-in data type.
	if(IsEmpty()) {
		try {
			throw EmptyStack("The stack is empty.");
		} catch (EmptyStack& e) {
			cout << "An exception is thrown: " << e.GetMsg();
		}
	} else {
		for(int i = 0; i < top+1; i++) {
			cout << info[i] << " ";
		}
	}
}
