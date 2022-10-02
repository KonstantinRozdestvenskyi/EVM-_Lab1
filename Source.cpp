#include<iostream>
#include<bitset>
#include<math.h>
#include <limits>
using namespace std;

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
double getDouble()//���� double � ���������
{
	while (true) // ����, ���� ������������ �� ������ ���������� ������
	{
		cout << "������� ������������ �����: " << '\n';
		double x;
		cin >> x;

		// ��������� �� ��������� ����������
		if (cin.fail()) // ���������� ���������� �� �������?
		{
			// ��, ������� ���������� � �������
			cin.clear(); // ���������� ��� � "����������" ����� ������
			ignoreLine();     // � ������� �������� ������� ������
			cout << "�������� ����.��������� �������." << '\n';
		}
		else
		{
			ignoreLine(); // ������� ����� ����������� ������� ������

			// ������������ �� ����� ������ ������������� �������� double,
			// ������� ��� �� ����� ������������ � ��� ��������
			return x;
		}
	}
}
unsigned getUInt()//���� unsigned int � ���������
{
	while (true) // ����, ���� ������������ �� ������ ���������� ������
	{
		cout << "������� ����� ��������������� ����� (� ������ �������� ������������� ����� ��� ����������� � ������� �������!): " << '\n';
		long long int x;//��������� lon long int, ����� ������������� ���� ������������� � ������� �������
		cin >> x;
		if (x < 0 || x > 4294967295) {
			cin.clear(); // ���������� ��� � "����������" ����� ������
			ignoreLine();     // � ������� �������� ������� ������
			cout << "�������� ����. ��������� �������.\n";
		}
		else {
			ignoreLine(); // ������� ����� ����������� ������� ������

			// ������������ �� ����� ������ ������������� �������� double,
			// ������� ��� �� ����� ������������ � ��� ��������
			(unsigned)x;//�������� ����������� ����� � ������� ����
			return x;
		}
	}
}
int main() {
	setlocale(LC_ALL, "RUS");
	cout << "�������� ��� ������: " << '\n' << "1 - unsigned int" << '\n' << "2 - double" << '\n' << "3 - ��������� ������ ���������" << '\n';
	int choose_type;
	cin >> choose_type;
	switch (choose_type){
	case 1: {
		unsigned x;
		x = getUInt();
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
		x = getDouble();//������� ����� double � ��������� �� �������������� �����
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