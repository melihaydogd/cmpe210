/*
 *	File : TreeType.cpp
*/
#include "TreeType.h"

template <class ItemType>
struct TreeNode {
	ItemType info;
	TreeNode<ItemType>* left;
	TreeNode<ItemType>* right;
};

template <class ItemType>
TreeType<ItemType>::TreeType() {
	root = NULL;
}

template <class ItemType>
void DestructorHelper(TreeNode<ItemType>*& tree) {
	if(tree != NULL) {
		DestructorHelper(tree->left);
		DestructorHelper(tree->right);
		delete tree;
	}
}

template <class ItemType>
TreeType<ItemType>::~TreeType() {
	DestructorHelper(root);
}

template <class ItemType>
void CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* originalTree) {
	if (originalTree == NULL) {
		copy = NULL;
	} else {
		copy = new TreeNode<ItemType>;
		copy->info = originalTree->info;
		CopyTree(copy->left,originalTree->left);
		CopyTree(copy->right,originalTree->right);
	}
}

template <class ItemType>
TreeType<ItemType>::TreeType(const TreeType<ItemType>& originalTree) {
	CopyTree(root, originalTree.root);
}

template <class ItemType>
void TreeType<ItemType>::operator=(const TreeType<ItemType>& originalTree) {
	if(&originalTree != this) {
		DestructorHelper(root);
		CopyTree(root, originalTree.root);
	}
}

template <class ItemType>
void TreeType<ItemType>::MakeEmpty() {
	root = NULL;
}

template <class ItemType>
bool TreeType<ItemType>::IsEmpty() const {
	return (root == NULL);
}

template <class ItemType>
bool TreeType<ItemType>::IsFull() const {
	TreeNode<ItemType>* location;
	try {
		location = new TreeNode<ItemType>;
		delete location;
		return false;
	} catch(bad_alloc e) {
		return true;
	}
}

template<class ItemType>
int CountHelper(TreeNode<ItemType>* tree) {
	if(tree == NULL) {
		return 0;
	} else {
		return CountHelper(tree->left) + CountHelper(tree->right) + 1;
	}
}

template <class ItemType>
int TreeType<ItemType>::LengthIs() const {
	return CountHelper(root);
}

template <class ItemType>
void RetrieveHelper(TreeNode<ItemType>* tree, ItemType& item, bool& found) {
	if(tree == NULL) {
		found = false;
	} else if (item < tree->info) {
		RetrieveHelper(tree->left,item,found);
	} else if (item > tree->info) {
		RetrieveHelper(tree->right,item,found);
	} else {
		item = tree->info;
		found = true;
	}
}

template <class ItemType>
void TreeType<ItemType>::RetrieveItem(ItemType& item, bool& found) const {
	RetrieveHelper(root,item,found);
}

template <class ItemType>
void InsertHelper(TreeNode<ItemType>*& tree, ItemType item) {
	if(tree == NULL) {
		tree = new TreeNode<ItemType>;
		tree->info = item;
		tree->right = NULL;
		tree->left = NULL;
	} else if(item < tree->info) {
		InsertHelper(tree->left,item);
	} else if(item > tree->info) {
		InsertHelper(tree->right,item);
	}
}

string FullTree() {
	return "Full Tree!!";
}

template <class ItemType>
void TreeType<ItemType>::InsertItem(ItemType item) {
	if(IsFull()) {
		try {
			throw FullTree();
		} catch (string& e) {
			cout << "An exception is thrown: " << e << endl;
		}
	} else {
		InsertHelper(root,item);
	}
}

template <class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data) {
	while (tree->right != NULL) {
		tree = tree->right;
	}
	data = tree->info;
}

template <class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree) {
	ItemType data;
	TreeNode<ItemType>* temp;
	temp = tree;
	if (tree->left == NULL) {
		tree = tree->right;
		delete temp;
	} else if (tree->right == NULL) {
		tree = tree->left;
		delete temp;
	} else {
		GetPredecessor(tree->left,data);
		tree->info = data;
		Delete(tree->left,data);
	}
}

template <class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item) {
	if(item > tree->info) {
		Delete(tree->right,item);
	} else if(item < tree->info) {
		Delete(tree->left,item);
	} else {
		DeleteNode(tree);
	}
}

template <class ItemType>
void TreeType<ItemType>::DeleteItem(ItemType item) {
	Delete(root,item);
}

template <class ItemType>
void PreOrder(TreeNode<ItemType>* tree, QueueType<ItemType>& preQue) {
	if(tree != NULL) {
		preQue.Enqueue(tree->info);
		PreOrder(tree->left,preQue);
		PreOrder(tree->right,preQue);
	}
}
template <class ItemType>
void InOrder(TreeNode<ItemType>* tree, QueueType<ItemType>& inQue) {
	if(tree != NULL) {
		InOrder(tree->left,inQue);
		inQue.Enqueue(tree->info);
		InOrder(tree->right,inQue);
	}
}
template <class ItemType>
void PostOrder(TreeNode<ItemType>* tree, QueueType<ItemType>& postQue) {
	if(tree != NULL) {
		PostOrder(tree->left,postQue);
		PostOrder(tree->right,postQue);
		postQue.Enqueue(tree->info);
	}
}
template <class ItemType>
void TreeType<ItemType>::ResetTree(OrderType order) {
	if(order==0) {
		PreOrder(root,preQue);
	} else if (order==1) {
		InOrder(root,inQue);
	} else if (order==2) {
		PostOrder(root,postQue);
	}
}

template <class ItemType>
void TreeType<ItemType>::GetNextItem(ItemType& item, OrderType order, bool& finished) {
	finished = false;
	if(order==0) {
		preQue.Dequeue(item);
		if(preQue.IsEmpty()) {
			finished = true;
		}
	} else if (order==1) {
		inQue.Dequeue(item);
		if(inQue.IsEmpty()) {
			finished = true;
		}
	} else if (order==2) {
		postQue.Dequeue(item);
		if(postQue.IsEmpty()) {
			finished = true;
		}
	}
}

template <class ItemType>
void PrintHelperPreOrder(TreeNode<ItemType>* tree) {
	if(tree != NULL) {
		cout << tree->info << " ";
		PrintHelperPreOrder(tree->left);
		PrintHelperPreOrder(tree->right);
	}
}
template <class ItemType>
void PrintHelperInOrder(TreeNode<ItemType>* tree) {
	if(tree != NULL) {
		PrintHelperInOrder(tree->left);
		cout << tree->info << " ";
		PrintHelperInOrder(tree->right);
	}
}
template <class ItemType>
void PrintHelperPostOrder(TreeNode<ItemType>* tree) {
	if(tree != NULL) {
		PrintHelperPostOrder(tree->left);
		PrintHelperPostOrder(tree->right);
		cout << tree->info << " ";
	}
}
string EmptyTree() {
	return "Empty Tree!!";
}
template <class ItemType>
void TreeType<ItemType>::Print(OrderType order) const {
	if(IsEmpty()) {
		try {
			throw EmptyTree();
		} catch (string& e) {
			cout << "An exception is thrown: " << e << endl;
		}
	} else {
		if(order == 0) {
			cout << "Preorder Traversal: ";
			PrintHelperPreOrder(root);
			cout << "\n";
		} else if(order == 1) {
			cout << "Inorder Traversal: ";
			PrintHelperInOrder(root);
			cout << "\n";
		} else if(order == 2) {
			cout << "Postorder Traversal: ";
			PrintHelperPostOrder(root);
			cout << "\n";
		}
	}
}
