/*
 *	File : TreeType.h
*/
#include <iostream>
#include "QueueType.cpp"

using namespace std;

template <class ItemType>
struct TreeNode;

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

template <class ItemType>
class TreeType {
	private:
		TreeNode<ItemType>* root;
		QueueType<ItemType> preQue;
		QueueType<ItemType> inQue;
		QueueType<ItemType> postQue;
	public:
		TreeType();
		~TreeType();
		TreeType(const TreeType<ItemType>&);
		void operator=(const TreeType<ItemType>&);
		void MakeEmpty();
		bool IsEmpty() const;
		bool IsFull() const;
		int LengthIs() const;
		void RetrieveItem(ItemType&,bool&) const;
		void InsertItem(ItemType);
		void DeleteItem(ItemType);
		void ResetTree(OrderType);
		void GetNextItem(ItemType&,OrderType,bool&);
		void Print(OrderType) const;
};
