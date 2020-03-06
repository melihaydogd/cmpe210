/*
 *	File : main.cpp
*/
#include "StackType.cpp"
int main () {
	//Creating the stack and numbers. Then, filling them.
	StackType<Book> stack;
	vector<Book> books(20);
	string arr[19] = {"Olasiliksiz", "Derin", "1984", "Simyaci", "Satranc", 
	"Korku", "Donusum", "Korluk", "Son Ada", "Son", "Semerkant", "Yabanci", 
	"Kalp", "Itiraf", "Mecburiyet", "Mulksuzler", "Kan ve Gul", "Zorba", "Donus"};
	int i;
	for(i = 0; i < 19; i++) {
		books[i].EnterName(arr[i]);
		stack.Push(books[i]);
	}
	cout << "The stack is created:\n";
	stack.PrintStack(books);
	
	//Checking whether the stack is full or not.
	cout << "Controlling the fullness: ";
	if(stack.IsFull()) {
		cout << "The stack is full.\n";
	} else {
		cout << "The stack is not full.\n";
	}
	cout << "The length: " << stack.LengthIs() << ".\n\n";
	
	//Pushing one more item to full the stack and checking the stack.
	cout << "Pushing an item:\n";
	books[i].EnterName("Yaraticilik");
	stack.Push(books[i]);
	stack.PrintStack(books);
	if(stack.IsFull()) {
		cout << "The stack is full.\n";
	} else {
		cout << "The stack is not full.\n";
	}
	cout << "The length: " << stack.LengthIs() << ".\n";
	
	//Pushing on full stack.
	cout << "Pushing on full stack.\n";
	Book book("Korkusuz");
	stack.Push(book);
	cout << "\n\n";
	//Popping the top item.
	cout << "Popping the top item:\n";
	Book PoppedBook;
	stack.Pop(PoppedBook);
	stack.PrintStack(books);
	//Information of Top item.
	cout << "The item at the top is " << stack.Top().GetName() << ".\n\n";
	
	//Making the stack empty.
	cout << "Clearing the stack and trying to print empty stack.\n";
	stack.MakeEmpty();
	stack.PrintStack(books);
	cout << "\n\n";
	return 0;
}
