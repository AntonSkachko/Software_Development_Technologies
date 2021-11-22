#include <iostream>
#include <ctime>
using namespace std;

void rectangle() {
	int width, height, area, perimeter;
	std::cout << "Enter width: "; cin >> width;
	cout << "Enter height: "; cin >> height;

	area = width * height;
	perimeter = 2 * (width + height);

	cout << endl << "Area = " << area << endl;
	cout << "Perimeter = " << perimeter << endl;

	for (int i = 0; width > i; i++) {
		for (int j = 0; height > j; j++) {
			cout << "* ";
		}
		cout << endl;
	}
}

void fibonacciFactorial() {
	int firstNumber = 0, secondNumber = 1, indexOfFibonacci;
	cout << "Enter number of Fibonacci: ";  cin >> indexOfFibonacci;
	while (indexOfFibonacci <= 0) {
		cout << "ERROR! Enter the number greater than zero: ";
		cin >> indexOfFibonacci;
	}
	while (indexOfFibonacci != 0) {
		firstNumber += secondNumber;
		secondNumber = firstNumber - secondNumber;
		indexOfFibonacci -= 1;
		cout << firstNumber << " ";
	}
	cout << endl << endl;


	int indexOfFactorial, numberOfFactorial = 1;
	cout << "Enter number of Factorial: "; cin >> indexOfFactorial;

	for (int i = 1; indexOfFactorial > i; i++) {
		numberOfFactorial *= i;
	}
	cout << numberOfFactorial << endl << endl;
}

void greatestCommonFactor() {
	int firstNumber, secondNumber;
	cout << "First number: "; cin >> firstNumber;
	cout << "Second number: "; cin >> secondNumber;
	
	if ((firstNumber * firstNumber) % 24 != 1) {
		cout << "Frist number isn't simple" << endl;
		
	}
	else if ((secondNumber * secondNumber) % 24 != 1) {
		cout << "Second number isn't simple" << endl;
	}
	else {
		cout << "Number are simple" << endl << endl;
	}

	

	while (firstNumber != secondNumber) {
		if (firstNumber > secondNumber) {
			firstNumber -= secondNumber;
		}
		else {
			secondNumber -= firstNumber;
		}

	}
	cout << "Greatest common factor: " << firstNumber<< endl << endl;
}

void decimalNumber() {
	int number, remainder;
	string decimal;
	cout << "Enter number: "; cin >> number;
	while (number) {
		remainder = number % 2;
		number /= 2;
		if (remainder != 1) {
			decimal += '0';
		}
		else {
			decimal += '1';
		}
	}
	cout << decimal << endl << endl;
	cout << "I'm sorry. I don't know how to fix this bug"<< endl;
	cout << "Sorry" << endl << endl;
}

void random() {
	srand(time(NULL));
	cout << "random value: " << 1 + rand() % 10 << endl;
	system("pause");

}

int main() {
	rectangle();
	fibonacciFactorial();
	greatestCommonFactor();
	decimalNumber();
	random();
	return 0;
}
