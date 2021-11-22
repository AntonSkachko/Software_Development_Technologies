#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;

struct day_of_birth {
	int day;
	int month;
	int year;
};

struct full_name {
	string name;
	string surname;
	string patronymic;
};

struct student {
    full_name nickname; // мой мозг не смог придумать более лучшее название
	day_of_birth birth;
};

student* createArray(int count_student) {
	student* array = new student[count_student];
	for (int i = 0; i < count_student; i++) {
		cout << "\nEnter student name: ";
		cin >> array[i].nickname.name;
		cout << "\nEnter student surname: ";
		cin >> array[i].nickname.surname;
		cout << "\nEnter student patronymic: ";
		cin >> array[i].nickname.patronymic;

		cout << "\n\n Enter the day when the student was born: ";
		cin >> array[i].birth.day;
		cout << "\n Enter the month when the student was born: ";
		cin >> array[i].birth.month;
		cout << "\n Enter the year when the student was born: ";
		cin >> array[i].birth.year;

	}
	return array;
}

void printStudent(student* array_of_student, int count_student) {
		for (int i = 0; i < count_student; i++) {
		cout << i + 1 << "student\n";
		cout << "Name: " << array_of_student[i].nickname.name << endl;
		cout << "Surname: " << array_of_student[i].nickname.surname << endl;
		cout << "Patronymic: " << array_of_student[i].nickname.patronymic << endl;

		cout << "time at which he was born: " << array_of_student[i].birth.day << '.'
			<< array_of_student[i].birth.month << '.' << array_of_student[i].birth.year << endl;

	}
}

string nameLookup(student* array_of_student, int count_student) {
	int max = 0, temp = 0;
	string largest_words;
	for (int i = 0; i < count_student; i++) {
		string words = array_of_student[i].nickname.name;
		for (int j = i + 1; j < count_student; j++) {
			if (words == array_of_student[j].nickname.name) {
				temp++;
			}
		}
		if (max < temp) {
			max = temp;
			largest_words = words;
		}
		temp = 0;
	}
	return largest_words;
}

bool compByName(student& first, student& second) {
	if (first.nickname.name != second.nickname.name) {
		first.nickname.name < second.nickname.name;
	}
	else {
		if (first.nickname.surname != second.nickname.surname) {
			return first.nickname.surname < second.nickname.surname;
		}
		else {
			return first.nickname.patronymic < second.nickname.patronymic;
		}
	}
}

void sortByName(student* array_of_student, int count_student) {
	sort(array_of_student, array_of_student + count_student, compByName);
}

day_of_birth getCurrentDate() {
	std::time_t current_time = std::time(nullptr);
	tm now;
	localtime_s(&now, &current_time);
	day_of_birth current_date;

	current_date.year = 1900 + now.tm_year;
	current_date.month = 1 + now.tm_mon;
	current_date.day = now.tm_mday;
	return current_date;
}

int* ageSearch(student* array_of_student, int count_student) {
	int birth_year = 0, birth_month = 0, birth_day = 0;
	day_of_birth now = getCurrentDate();
	int* age_students = new int[count_student];
	for (int i = 0; i < count_student; i++) {
		age_students[i] = now.year - array_of_student[i].birth.year;
	}
	return age_students;
}

void printAllStudent(student* array_of_student, int* age_students, int count_student) {
	cout << "№\t Name\t Surname\t patronymic\t age\t" << endl;
	cout << "==================================================================" << endl;
	for (int i = 0; i < count_student; i++) {
		cout << i + 1 << "\t" << array_of_student[i].nickname.name << "\t"
			<< array_of_student[i].nickname.surname << "\t" << array_of_student[i].nickname.patronymic << "\t"
			<< age_students[i] << "\t" << endl;

	}
}


void deleteArray(student* array_of_student) {
	delete[] array_of_student;
}

double averageAgeSearch(int* age_students, int count_student) {
	double average_age = 0;
	for (int index = 0; index < count_student; index++)
	{
		average_age += age_students[index];
	}
	average_age /= count_student;
	return average_age;
}

int main(){
	int count_student;
	cout << "how many students? ";
	cin >> count_student;

	student* array_of_student = createArray(count_student);

	printStudent(array_of_student, count_student);
	cout << endl << endl;

	cout << "Most popular name: " << nameLookup(array_of_student, count_student) << endl;

	int* age_students = ageSearch(array_of_student, count_student);
	double average_age = averageAgeSearch(age_students, count_student);
	cout << "Average age of students = " << average_age << endl;
	sortByName(array_of_student, count_student);
	printAllStudent(array_of_student, age_students, count_student);
	deleteArray(array_of_student);
	return 0;
	
}