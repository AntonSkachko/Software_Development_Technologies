#include <iostream>

using namespace std;

string getBackString(int number);
string getBackString(double number);
void toNormalString(string& back_string);
int* createArray(int amount_of_number);
int countingNumbers(int* array, int amount_of_number, int cheking_number);
int countingNumbers(long long* array, int amount_of_number, long long cheking_number);
int countingNumbers(char* array, int amount_of_number, char cheking_number);
int countingNumbers(double* array, int amount_of_number, double cheking_number);


int main() {
	int number;
	cout << "Enter number: "; cin >> number;
	string our_string = getBackString(number);
	cout << "It's string: " << our_string << endl;


	int amount_of_number;
	cout << "Enter amount of number: ";
	cin >> amount_of_number;

	int cheking_number;
	cout << "Enter the number that we will check for occurrence";
	cin >> cheking_number;
	

	auto  array = createArray(amount_of_number);
	cout << "The number of occurrences of your number is "
		<< countingNumbers(array, amount_of_number, cheking_number);
	return 0;
}

string getBackString(int number) {
	string back_string;
	while (number != 0) {
		back_string += number % 10 + '0';
		number /= 10;
	}
	toNormalString(back_string);
	return back_string;
}

string getBackString(double number) {
	string back_string;
	int temp = static_cast<int>(number);
	while (number != 0) {
		back_string += temp % 10 + '0';
		number /= 10;
	}
	toNormalString(back_string);
	return back_string;
}

void toNormalString(string &back_string) {
	int size = back_string.size();
	for (int i = 0; i * 2 < size; ++i) {
		swap(back_string[i], back_string[size - i - 1]);
	}
}


int* createArray(int amount_of_number) {
	int* array = new int[amount_of_number];
	for (int i = 0; i < amount_of_number; i++) {
		cin >> array[i];
	}
	return array;
}
int countingNumbers(int* array, int amount_of_number, int cheking_number) {
	int number_of_occurrences = 0;

	for (int i = 0; i < amount_of_number; i++) {
		if (cheking_number == array[i]) {
			number_of_occurrences++;
		}
	}

	return number_of_occurrences;

}

int countingNumbers(long long* array, int amount_of_number, long long cheking_number) {
	int number_of_occurrences = 0;

	for (int i = 0; i < amount_of_number; i++) {
		if (cheking_number == array[i]) {
			number_of_occurrences++;
		}
	}

	return number_of_occurrences;

}

int countingNumbers(char* array, int amount_of_number, char cheking_number) {
	int number_of_occurrences = 0;

	for (int i = 0; i < amount_of_number; i++) {
		if (cheking_number == array[i]) {
			number_of_occurrences++;
		}
	}

	return number_of_occurrences;
}

int countingNumbers(double* array, int amount_of_number, char cheking_number) {
	int number_of_occurrences = 0;

	for (int i = 0; i < amount_of_number; i++) {
		if (cheking_number == array[i]) {
			number_of_occurrences++;
		}
	}

	return number_of_occurrences;
}