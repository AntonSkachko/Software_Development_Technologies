#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	int size;
	cout << "Size = ";
	cin >> size;
	char* a = new char[size];
	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}
	cout << "New array: " << endl;

	sort(a, a + size);
	int left = 0;
	int right = 0;
	while (true) {
		while (a[left] == a[right] && right < size) {
			right++;
		}
		left++;
		if (right == size) {
			break;
		}
		a[left] = a[right];
	}
	size = left;
	for (int i = 0; i < size; i++) {
		cout << a[i] << ' ';
	}
	delete[] a;
	return 0;90
		9
}