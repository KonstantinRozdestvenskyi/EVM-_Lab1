#include<iostream>
#include<bitset>
#include<math.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "RUS");
	cout << "Выберите тип данных: " << '\n' << "1 - unsigned int" << '\n' << "2 - double" << '\n' << "3 - завершить работу программы";
	int choose_type;
	cin >> choose_type;
	switch (choose_type){
	case 1: {
		unsigned x;
		cout << "введите целое число" << '\n';
		cin >> x;
		auto bin1 = bitset<32>(x);
		cout << "двоичное представление введённоcго числа: " << '\n';
		cout << bin1 << '\n';
		unsigned number, quantity, value;
		while (1) {
			cout << "введите номер младшего изменяемого бита: " << '\n';
			cin >> number;
			cout << "введите количество изменяемых битов: " << '\n';
			cin >> quantity;
			if (number + quantity > 32) {
				cout << "сумма номера младшего изменяемого бита и их количества превышают количество бита в числе." << '\n'
					<< "повторите ввод номера и/или количества." << '\n';
			}
			else
				break;
		}
		cout << "введите новое состояние каждого бита: " << '\n';
		for (unsigned i = 0; i < quantity; i++) {
			cin >> value;
			if (value == 1)
				bin1.set(number);
			else
				bin1.reset(number);
			number++;
		}
		cout << "изменённое число: " << '\n' << (unsigned int)bin1.to_ulong() << '\n';
		cout << bin1 << '\n';
		break;
	}
	case 2: {
		double x;
		cout << "введите вещественное число: " << '\n';
		cin >> x;
		auto bin1 = bitset<64>(*(unsigned long long*)(&x));
		cout << "двоичное представление введённоcго числа: " << '\n';
		cout << bin1 << '\n';
		unsigned number, quantity, value;
		while (1) {
			cout << "введите номер младшего изменяемого бита: " << '\n';
			cin >> number;
			cout << "введите количество изменяемых битов: " << '\n';
			cin >> quantity;
			if (number + quantity > 64) {
				cout << "сумма номера младшего изменяемого бита и их количества превышают количество бита в числе." << '\n'
					<< "повторите ввод номера и/или количества." << '\n';
			}
			else
				break;
		}
		cout << "введите новое состояние каждого бита: " << '\n';
		for (unsigned i = 0; i < quantity; i++) {
			cin >> value;
			if (value == 1)
				bin1.set(number);
			else
				bin1.reset(number);
			number++;
		}
		unsigned long long z = bin1.to_ullong();
		cout << "изменённое число: " << '\n' << (*(double*)(&z)) << '\n';
		cout << bin1 << '\n';
		break;
	}
	default:
		break;
	}
	return 0;
}