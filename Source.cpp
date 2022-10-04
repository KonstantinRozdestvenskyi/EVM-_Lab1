#include<iostream>
#include<bitset>
#include<math.h>
#include <limits>
using namespace std;

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
double getDouble()//ввод double с проверкой
{
	while (true) // Цикл, пока пользователь не введет допустимые данные
	{
		cout << "введите вещественное число: " << '\n';
		double x;
		cin >> x;

		// Проверяем на неудачное извлечение
		if (cin.fail()) // предыдущее извлечение не удалось?
		{
			// да, давайте разберемся с ошибкой
			cin.clear(); // возвращаем нас в "нормальный" режим работы
			ignoreLine();     // и удаляем неверные входные данные
			cout << "Неверный ввод.Повторите попытку." << '\n';
		}
		else
		{
			ignoreLine(); // удаляем любые посторонние входные данные

			// пользователь не может ввести бессмысленное значение double,
			// поэтому нам не нужно беспокоиться о его проверке
			return x;
		}
	}
}
unsigned getUInt()//ввод unsigned int с проверкой
{
	while (true) // Цикл, пока пользователь не введет допустимые данные
	{
		cout << "введите целое неотрицательное число (в случае введения вещественного числа оно округлиться в меньшую сторону!): " << '\n';
		long long int x;//объявляем lon long int, чтобы предотвратить ввод отрицательных и слишком больших
		cin >> x;
		if (x < 0 || x > 4294967295 || cin.fail()) {
			cin.clear(); // возвращаем нас в "нормальный" режим работы
			ignoreLine();     // и удаляем неверные входные данные
			cout << "Неверный ввод. Повторите попытку.\n";
		}
		else {
			ignoreLine(); // удаляем любые посторонние входные данные

			// пользователь не может ввести бессмысленное значение double,
			// поэтому нам не нужно беспокоиться о его проверке
			(unsigned)x;//приводим проверенное число к нужному типу
			return x;
		}
	}
}
int main() {
	setlocale(LC_ALL, "RUS");
	cout << "Выберите тип данных: " << '\n' << "1 - unsigned int" << '\n' << "2 - double" << '\n' << "3 - завершить работу программы" << '\n';
	int choose_type;
	while (1) {
		cin >> choose_type;
		if (choose_type == 1 || choose_type == 2 || choose_type == 3) {
			break;
		}
		else
			cout << "некоректная команда. Повторите запрос." << '\n';
	}
	switch (choose_type){
	case 1: {
		unsigned x;
		x = getUInt();
		auto bin1 = bitset<32>(x);
		cout << "двоичное представление введённоcго числа: " << '\n';
		cout << bin1 << '\n';
		int number, quantity, value;
		while (1) {
			while (1) {
				cout << "введите номер младшего изменяемого бита: " << '\n';
				cin >> number;
				if (number < 0 || number > 31) {
					cout << "некоректный номер. Повторите ввод." << '\n';
				}
				else
					break;
			}
			while (1) {
				cout << "введите количество изменяемых битов: " << '\n';
				cin >> quantity;
				if (quantity < 0 || quantity > 32) {
					cout << "некоректное количество. Повторите ввод." << '\n';
				}
				else
					break;
			}
			if (number + quantity > 32) {
				cout << "сумма номера младшего изменяемого бита и их количества превышают количество бита в числе." << '\n'
					<< "повторите ввод номера и/или количества." << '\n';
			}
			else
				break;
		}
		cout << "введите новое состояние каждого бита: " << '\n';
		for (int i = 0; i < quantity; i++) {
			while (1) {
				cin >> value;
				if (value == 0 || value == 1) {
					break;
				}
				else
					cout << "неверное состояние бита. Повторите ввод." << '\n';
			}
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
		x = getDouble();//функция ввода double с проверкой на некорректность ввода
		auto bin1 = bitset<64>(*(unsigned long long*)(&x));
		cout << "двоичное представление введённоcго числа: " << '\n';
		cout << bin1 << '\n';
		int number, quantity, value;
		while (1) {
			while (1) {
				cout << "введите номер младшего изменяемого бита: " << '\n';
				cin >> number;
				if (number < 0 || number > 63) {
					cout << "некоректный номер. Повторите ввод." << '\n';
				}
				else
					break;
			}
			while (1) {
				cout << "введите количество изменяемых битов: " << '\n';
				cin >> quantity;
				if (quantity < 0 || quantity > 64) {
					cout << "некоректное количество. Повторите ввод." << '\n';
				}
				else
					break;
			}
			if (number + quantity > 64) {
				cout << "сумма номера младшего изменяемого бита и их количества превышают количество бита в числе." << '\n'
					<< "повторите ввод номера и/или количества." << '\n';
			}
			else
				break;
		}
		cout << "введите новое состояние каждого бита: " << '\n';
		for (unsigned i = 0; i < quantity; i++) {
			while (1) {
				cin >> value;
				if (value == 0 || value == 1) {
					break;
				}
				else
					cout << "неверное состояние бита. Повторите ввод." << '\n';
			}
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