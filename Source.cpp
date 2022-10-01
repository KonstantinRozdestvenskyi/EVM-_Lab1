#include<iostream>
#include<bitset>
#include<math.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "RUS");
	cout << "�������� ��� ������: " << '\n' << "1 - unsigned int" << '\n' << "2 - double" << '\n' << "3 - ��������� ������ ���������";
	int choose_type;
	cin >> choose_type;
	switch (choose_type){
	case 1: {
		unsigned x;
		cout << "������� ����� �����" << '\n';
		cin >> x;
		auto bin1 = bitset<32>(x);
		cout << "�������� ������������� �������c�� �����: " << '\n';
		cout << bin1 << '\n';
		unsigned number, quantity, value;
		while (1) {
			cout << "������� ����� �������� ����������� ����: " << '\n';
			cin >> number;
			cout << "������� ���������� ���������� �����: " << '\n';
			cin >> quantity;
			if (number + quantity > 32) {
				cout << "����� ������ �������� ����������� ���� � �� ���������� ��������� ���������� ���� � �����." << '\n'
					<< "��������� ���� ������ �/��� ����������." << '\n';
			}
			else
				break;
		}
		cout << "������� ����� ��������� ������� ����: " << '\n';
		for (unsigned i = 0; i < quantity; i++) {
			cin >> value;
			if (value == 1)
				bin1.set(number);
			else
				bin1.reset(number);
			number++;
		}
		cout << "��������� �����: " << '\n' << (unsigned int)bin1.to_ulong() << '\n';
		cout << bin1 << '\n';
		break;
	}
	case 2: {
		double x;
		cout << "������� ������������ �����: " << '\n';
		cin >> x;
		auto bin1 = bitset<64>(*(unsigned long long*)(&x));
		cout << "�������� ������������� �������c�� �����: " << '\n';
		cout << bin1 << '\n';
		unsigned number, quantity, value;
		while (1) {
			cout << "������� ����� �������� ����������� ����: " << '\n';
			cin >> number;
			cout << "������� ���������� ���������� �����: " << '\n';
			cin >> quantity;
			if (number + quantity > 64) {
				cout << "����� ������ �������� ����������� ���� � �� ���������� ��������� ���������� ���� � �����." << '\n'
					<< "��������� ���� ������ �/��� ����������." << '\n';
			}
			else
				break;
		}
		cout << "������� ����� ��������� ������� ����: " << '\n';
		for (unsigned i = 0; i < quantity; i++) {
			cin >> value;
			if (value == 1)
				bin1.set(number);
			else
				bin1.reset(number);
			number++;
		}
		unsigned long long z = bin1.to_ullong();
		cout << "��������� �����: " << '\n' << (*(double*)(&z)) << '\n';
		cout << bin1 << '\n';
		break;
	}
	default:
		break;
	}
	return 0;
}