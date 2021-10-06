#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int x; 
	cout << "Введите x "; cin >> x;
	if (x % 2 == 0) {
		cout << "x является чётным" << endl;
	}
	else {
		cout << "x является нечётным" << endl;
	}

	cout << endl;
	int buf = abs(x), sum = 0, k = 0; 
	while (buf) {
		sum += buf % 10;
		buf /= 10; 
		k++;
	}

	cout << "Средне ариметическое равно = " << (1. * sum) / k << endl;
	cout << endl;

	int mounth_num;
	cout << "Введите номер месяца "; cin >> mounth_num;
	switch (mounth_num) {
		case 1:
			cout << "январь" << endl;
			cout << "зима" << endl;
			break;
		case 2:
			cout << "февраль" << endl;
			cout << "зима" << endl;
			break;
		case 3:
			cout << "март" << endl;
			cout << "весна" << endl;
			break;
		case 4:
			cout << "апрель" << endl;
			cout << "весна" << endl;
			break;
		case 5:
			cout << "май" << endl;
			cout << "весна" << endl;
			break;
		case 6:
			cout << "июнь" << endl;
			cout << "лето" << endl;
			break;
		case 7:
			cout << "июль" << endl;
			cout << "лето" << endl;
			break;
		case 8:
			cout << "август" << endl;
			cout << "лето" << endl;
			break;
		case 9:
			cout << "сентябрь" << endl;
			cout << "осень" << endl;
			break;
		case 10:
			cout << "октябрь" << endl;
			cout << "осень" << endl;
			break;
		case 11:
			cout << "ноябрь" << endl;
			cout << "осень" << endl;
			break;
		case 12:
			cout << "декабрь" << endl;
			cout << "зима" << endl;
			break;
		default:
			cout << "Попробуйте ещё раз" << endl;

	}
	cout << endl;



	int year, m;
	cout << "год:"; cin >> year;
	m = year % 12;
	switch (m - 1) {
	case 1:
		cout << "год Сабаки" << endl;
		break;
	case 2:
		cout << "год Свиньи" << endl;
		break;
	case 3:
		cout << "год Крысы" << endl;
		break;
	case 4:
		cout << "год Быка" << endl;
		break;
	case 5:
		cout << "год Тигра" << endl;
		break;
	case 6:
		cout << "год Кота" << endl;
		break;
	case 7:
		cout << "год Дракона" << endl;
		break;
	case 8:
		cout << "год Змея" << endl;
		break;
	case 9:
		cout << "год Лошади" << endl;
		break;
	case 10:
		cout << "год Козы" << endl;
		break;
	case 11:
		cout << "год Обезъяны" << endl;
		break;
	case 12:
		cout << "год Петуха" << endl;
		break;
	default:
		cout << "А как так получилось" << endl;

	}
	return 0;
}
