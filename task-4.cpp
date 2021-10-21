#include <iostream>
#include <ctime>
#include <random>
#include <algorithm> // add sort()
#include <limits>  // add INT_MIN  and INT_MAX
using namespace std;


int** createMatrix(int &line, int &column) {
	srand(time(NULL));
	int** matr = new int* [line];
	for (int i = 0; i < line; i++) {
		matr[i] = new int[column];
	}

	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			matr[i][j] = 1 + rand() % 10;
		}
	}
	return matr;
}

void printMatrix(int** matr, int line, int column) {
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
}
void deleteMatrix(int** matr, int line) {
	for (int i = 0; i < line; i++) {
		delete[] matr[i];
	}
	delete[] matr;
}


double* createArray(int& number) {
	double* arr = new double[number];
	cout << endl << "Enter array elements: ";
	for (int i = 0; i < number; i++) {
		cin >> arr[i];
	}
	return arr;

}

void printArray(int* arr, int number) {

	for (int i = 0; i < number; i++) {
		cout << arr[i];
	}
}

void deleteArray(double* arr) {
	delete[] arr;
}

int main() {

	cout << "\t -task 1-" << endl;
	int line, column;

	cout << "Enter the number of elements in the matrix line: "; cin >> line;
	cout << "Enter the number of elements in the matrix column: "; cin >> column;

	int** matr = createMatrix(line, column);
	printMatrix(matr, line, column);
	deleteMatrix(matr, line);
	cout << endl;


	cout << "\n \t -task 2-" << endl;
	int number, summa = 0;
	cout << "Enter the number of elements of the array: "; cin >> number;
	double* arr = createArray(number);
	for (int i = 0; i < number; i++) {
		summa += arr[i];
	}
	cout << summa << endl;
	deleteArray(arr);



	cout << "\n \t -task 3-" << endl;
	int line1, line2, column1, column2;

	cout << "Enter the number of elements in the first matrix line: "; cin >> line1;
	cout << "Enter the number of elements in the first matrix column: "; cin >> column1;
	int** first_matr = createMatrix(line1, column1);
	printMatrix(first_matr, line1, column1);
	cout << endl;

	cout << "Enter the number of elements in the second matrix line: "; cin >> line2;
	cout << "Enter the number of elements in the second matrix column: "; cin >> column2;
	int** second_matr = createMatrix(line2, column2);
	printMatrix(second_matr, line2, column2);
	cout << endl;


	int** result_matr = new int* [line1];
	for (int i = 0; i < line2; i++) {
		result_matr[i] = new int[column2];
	}

	if (column1 == line2) {
		for (int i = 0; i < line1; i++) {
			for (int j = 0; j < column2; j++) {
				double buf_result = 0;
				for (int y = 0; y < column1; y++) {
					buf_result += first_matr[i][y] * second_matr[y][j];
				}
				result_matr[i][j] = buf_result;

			}
		}
		cout << "Result:" << endl;
		printMatrix(result_matr, line2, column1);
	}
	else {
		cout << "These matrixs aren't multiplied. Sorry(";
	}
	deleteMatrix(first_matr, line1);
	deleteMatrix(second_matr, line2);
	deleteMatrix(result_matr, line2);


	cout << "\n \t -task 4- " << endl;

	int numbers;

	cout << "Enter the number of elements of the array: "; cin >> numbers;
	double* array = createArray(numbers);

	sort(array, array + numbers);
	cout << "Sorted array: ";
	for (int i = 0; i < numbers; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	cout << "The average: ";
	if (numbers % 2 == 0) {
		int average;
		average = numbers / 2;
		cout << (array[average] + array[average - 1]) / 2;
	}
	else {
		int average;
		average = (numbers) / 2;
		cout << (array[average]);
	}
	deleteArray(array);
	cout << endl;

	cout << "\n \t -task 5-" << endl;

	int line5, column5;
	cout << "Enter the number of elements in the matrix line: "; cin >> line5;
	cout << "Enter the number of elements in the matrix column: "; cin >> column5;

	int** matrix = createMatrix(line5, column5);
	printMatrix(matrix, line5, column5);
	cout << endl;

	int xyq = line5 * column5;
	double* arraym = new double[xyq];

	for (int i = 0; i < line5; i++) {
		for (int j = 0; j < column5; j++) {
			arraym[i * column5 + j] = matrix[i][j];
		}
	}
	sort(arraym, arraym + xyq);
	
	cout << endl << "The average: ";
	if (xyq % 2 == 0) {
		int average;
		average = xyq / 2;
		cout << (arraym[average] + arraym[average - 1]) / 2 << endl;
	}
	else {
		int average;
		average = (xyq) / 2;
		cout << (arraym[average]) << endl;
	}
	cout << endl;

	cout << "Min element matrix: " << arraym[0] << endl;
	cout << "Max element matrix: " << arraym[xyq - 1] << endl;

	deleteArray(arraym);
	deleteMatrix(matrix, line5);
	return 0;
}