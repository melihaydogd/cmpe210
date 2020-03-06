/*
 *	File : main.cpp
*/
#include "TreeType.cpp"

int main() {

	//Creating the tree.
	TreeType<int> tree;

	int arr[20] = {20,6,19,40,5,15,34,16,8,23,66,12,1,27,30,45,78,35,3,22};

	for(int i = 0; i < 20; i++) {
		tree.InsertItem(arr[i]);
	}
	cout << "The Tree is created:" << endl;
	tree.Print(IN_ORDER);

	//Checking whether the tree is full or not.
	cout << "Controlling the fullness: ";
	if(tree.IsFull()) {
		cout << "The Tree is full.\n";
	} else {
		cout << "The Tree is not full.\n";
	}
	cout << "The length: " << tree.LengthIs() << ".\n" << endl;

	//Inserting 21, 99 and 10 into the tree.
	cout << "Inserting 21, 99 and 10:\n";
	tree.InsertItem(21);
	tree.InsertItem(99);
	tree.InsertItem(10);
	tree.Print(IN_ORDER);
	cout << "The length: " << tree.LengthIs() << ".\n" << endl;

	//Deleting 20, 40 and 27.
	cout << "Deleting 20, 40 and 27:\n";
	tree.DeleteItem(20);
	tree.DeleteItem(40);
	tree.DeleteItem(27);
	tree.Print(IN_ORDER);
	cout << "The length: " << tree.LengthIs() << ".\n" << endl;

	//Retrieving 66.
	cout << "Retrieving 66:" << endl;
	int number = 66;
	bool found;
	tree.RetrieveItem(number,found);
	if(found) {
		cout << "Item is found.";
	} else {
		cout << "Item is not found.";
	}
	cout << endl << endl;

	//Retrieving 49.
	cout << "Retrieving 49:" << endl;
	number = 49;
	tree.RetrieveItem(number,found);
	if(found) {
		cout << "Item is found.";
	} else {
		cout << "Item is not found.";
	}
	cout << endl << endl;

	//Printing Inorder, Preorder and Postorder Traversal.
	cout << "Printing Inorder, Preorder and Postorder Traversal:" << endl;
	tree.Print(PRE_ORDER);
	tree.Print(IN_ORDER);
	tree.Print(POST_ORDER);
	cout << endl;
	
	//Copying tree and printing the copy.
	cout << "Copying tree:" << endl;
	TreeType<int> copy(tree);
	copy.Print(IN_ORDER);
	cout << endl;
	
	//Copying tree using operator and printing the copy.
	cout << "Copying tree using operator and printing the copy:" << endl;
	TreeType<int> copy1;
	copy1 = tree;
	copy1.Print(IN_ORDER);
	cout << endl;

	//Making the Tree empty.
	tree.MakeEmpty();
	cout << "Controlling the Tree: ";
	if(tree.IsEmpty()) {
		cout << "The Tree is empty.\n";
	} else {
		cout << "The Tree is not empty.\n";
	}
	cout << "The length: " << tree.LengthIs() << ".\n" << endl;
	
	return 0;
}
