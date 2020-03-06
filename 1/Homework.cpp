#include <iostream>
using namespace std;
int sum_of_square(int);
int square_of_sum(int);

int main() {

	int sumofsquare;
	int squareofsum;

	int n;
	cout << "Enter the number:";
	cin >> n;

	if(n < 1) {
		cout << "Please enter a number which is greater than 0.\n";
	} else {
		sumofsquare = sum_of_square(n);
		squareofsum = square_of_sum(n);
		cout << "The sum of squares is " << sumofsquare << ".\n";
		cout << "The square of the sums is " << squareofsum << ".";
	}
	return 0;
}

int sum_of_square(int n) {
	//Finds the sum of the squares of the first n numbers.
	int temp = 0;
	int i = 1;
	while (i < n+1) {
		temp = temp + i*i;
		i = i + 1;
	}
	return temp;
}

int square_of_sum(int n) {
	//Finds the square of the sums of the first n numbers.
	int temp = 0;
	int i = 1;
	while(i < n+1) {
		temp = temp + i;
		i = i + 1;
	}
	return temp * temp;
}
