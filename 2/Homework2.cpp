#include <iostream>
#include <cstring>

using namespace std;

void read(char dest[], char source[]) {
	for(int i = 0; i < strlen(source); i++) {
		dest[i] = source[i];
	}
}

class Library {
	private:
		const char *author_of_books[20];
		const char *date_of_registration[20];
		int number_of_books[20];
		int password;
		int number_of_registered_books;
	protected:
		const char *name_of_books[20];
	public:
		Library();
		void book_insertion(char[],char[],char[],int);
		void book_list();
		void book_information(int);
		void borrow(int);
		int password_verification(int);
};

Library::Library() {
	number_of_registered_books = 7;
	const char *names[] = {
		"Lord of the Rings: The Fellowship of the Ring", "Lord of the Rings: The Two Towers", 
		"Lord of the Rings: The Return of the King",
		"1984", "Milli Savas Hikayeleri", "Aylak Adam", "Sevda Dolu Bir Yaz"
	};
	for(int i = 0; i < number_of_registered_books; i++) {
		name_of_books[i] = names[i];
	}
	const char *authors[] =
	{"J. R. R. Tolkien", "J. R. R. Tolkien", "J. R. R. Tolkien", "George Orwell", 
	"Yakup Kadri Karaosmanoglu", "Yusuf Atilgan", "Furuzan"};
	for(int i = 0; i < number_of_registered_books; i++) {
		author_of_books[i] = authors[i];
	}
	const char *dates[] = {"2007", "2007", "2007", "1990", "2017", "2018", "2019"};
	for(int i = 0; i < number_of_registered_books; i++) {
		date_of_registration[i] = dates[i];
	}
	int numbers[] = {5,6,4,14,16,12,20};
	for(int i = 0; i < number_of_registered_books; i++) {
		number_of_books[i] = numbers[i];
	}
	password = 1234;
}

void Library::book_insertion(char name[],char author[],char date[], int number) {
	name_of_books[number_of_registered_books] = name;
	author_of_books[number_of_registered_books] = author;
	date_of_registration[number_of_registered_books] = date;
	number_of_books[number_of_registered_books] = number;
	number_of_registered_books = number_of_registered_books + 1;
}

void Library::book_list() {
	cout << "The list of the books:\n";
	for(int i = 0; i < number_of_registered_books; i++) {
		cout << i+1 << ". " << name_of_books[i] << "\n";
	}
}

void Library::book_information(int n) {
	cout << "The Name of the Book: " << name_of_books[n-1] << "\n";
	cout << "The Author of the Book: " << author_of_books[n-1] << "\n";
	cout << "The Date of Registration: " << date_of_registration[n-1] << "\n";
	cout << "The Number of the Book: " << number_of_books[n-1] << "\n";
}

void Library::borrow(int n) {
	number_of_books[n-1] = number_of_books[n-1] - 1;
}

int Library::password_verification(int n) {
	if(n == password) {
		return 1;
	} else {
		return 0;
	}
}

class People:Library {
	private:
		const char *name_and_surname[20];
		const char *date_of_borrow[20];
		const char *residence[20];
		const char *borrowed_book[20];
		int age[20];
		int number_of_persons;
	public:
		People();
		void person_registration(char[],char[],char[],int,int);
		void person_information(int);
		void inf(int);
};

People::People() {
	number_of_persons = 0;
}

void People::person_registration(char name_[],char date[],char address[], int number, int agep) {
	name_and_surname[number_of_persons] = name_;
	date_of_borrow[number_of_persons] = date;
	residence[number_of_persons] = address;
	borrowed_book[number_of_persons] = name_of_books[number-1];
	age[number_of_persons] = agep;
	number_of_persons = number_of_persons + 1;
}

void People::person_information(int book_number) {
	int number = -1;
	for(int i = 0; i < number_of_persons; i++) {
		if(borrowed_book[i] == name_of_books[book_number-1]) {
			number = i;
			cout << "Name and Surname: " << name_and_surname[number] << "\n";
			cout << "Age: " << age[number] << "\n";
			cout << "Province: " << residence[number] << "\n";
			cout << "The Date of Borrow: " << date_of_borrow[number] << "\n";
			cout << "The Borrowed Book: " << borrowed_book[number] << "\n";
		}
	}
	if(number == -1) {
		cout << "Nobody borrowed this book.\n";
	}
}


int main () {
	Library lib;
	People person;
	lib.book_list();
	const char *operations[6] = 
	{"1. Add Books", "2. Borrow Books", "3. See Book Info", 
	"4. See Person Info", "5. See the List of the Books", "6. Exit"};
	int choice;
	while(choice != 6) {
		cout << "What do you want to do?\n";
		for(int i = 0; i < 6; i++) {
			cout << operations[i] << "\n";
		}
		cout << "Please enter the number of the process:";
		cin >> choice;
		if(choice == 1) {
			char namee[30];
			char author[30];
			char datee[4];
			int number;
			cout << "The name of the book:";
			cin.ignore();
			cin.getline(namee,30);
			cout << "The author of the book:";
			cin.getline(author,30);
			cout << "The date of registration:";
			cin >> datee;
			cout << "The number of book:";
			cin >> number;
			lib.book_insertion(namee,author,datee,number);
		} else if(choice == 2) {
			char name[30];
			int age;
			char address[20];
			char date[4];
			int booknumber;
			cout << "Name and Surname:";
			cin.ignore();
			cin.getline(name,30);
			cout << "Age:";
			cin >> age;
			cout << "Province:";
			cin >> address;
			cout << "The Date of Borrow:";
			cin >> date;
			cout << "The Number of Book:";
			cin >> booknumber;
			person.person_registration(name,date,address,booknumber,age);
			lib.borrow(booknumber);
		} else if(choice == 3) {
			int book_number;
			cout << "Please enter the number of the book:";
			cin >> book_number;
			lib.book_information(book_number);
		} else if(choice == 4) {
			int pass;
			cout << "Please enter the password:";
			cin >> pass;
			int value = lib.password_verification(pass);
			if(value == 1) {
				int number_of_book;
				cout << "Enter the book number:";
				cin >> number_of_book;
				person.person_information(number_of_book);
			} else {
				cout << "Invalid password!" << "\n";
			}
		} else if(choice == 5) {
			lib.book_list();
		} else if(choice == 6) {
			cout << "Exiting...";
		}
		cout << "\n";
	}

	return 0;
}
