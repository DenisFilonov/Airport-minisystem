#include "Airport.h"

Airport::Airport()
{
    size = 0;
    arr = nullptr;
}

Airport::~Airport()
{
    if (size > 0) delete[] arr;
}

const int Airport::getAmount() const
{
	return this->size;
}

void Airport::addPlane(Airplane obj)
{
	Airplane* tmp = new Airplane[++size];
	for (int i = 0; i < size - 1; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[size - 1] = obj;
	if (arr != NULL) delete[] arr;
	arr = tmp;
	cout << "\n������ ������� �������� � ������������.\n";
}

void Airport::delPlane(int id)
{
	Airplane* tmp = new Airplane[--size];
	for (int i = 0; i < size; i++)
	{
		if (i < id) tmp[i] = arr[i];
		else if (i >= id) tmp[i] = arr[i + 1];
	}
	if (arr != NULL) delete[] arr;
	arr = tmp;
	cout << "\n������ ������� ���� � ������������.\n";
}

void Airport::changeInfoOfPlane(int id)
{
	int menu = 0;
	string str = "";
	int value = 0;
	do
	{
		cout << "\n\t���� ��������� ����������:";
		cout << "\n1) ����� �����.";
		cout << "\n2) ����������� �����.";
		cout << "\n3) ���������� ������� ���� � �������.";
		cout << "\n4) ������������ ���������� ���� � �������.";
		cout << "\n0. ��������� �����.\n�����: ";
		cin >> menu;

		switch (menu)
		{

		case 1:
			cout << "\n�����: ";
			cin.ignore();
			getline(cin, str);
			arr[id].setFlNumber(str);
			cout << "\n����� ����� ������� �������.\n\n";
			break;

		case 2:
			cout << "\n�����������: ";
			cin.ignore();
			getline(cin, str);
			arr[id].setDirection(str);
			cout << "\n����������� ����� ������� ��������.\n\n";
			break;

		case 3:
			cout << "\n������� �����: ";
			cin >> value;
			arr[id].setAmountInside(value);
			cout << "\n���������� ������� ���� � ������� ������� ��������.\n\n";
			break;

		case 4:
			cout << "\n����������� ����: ";
			cin >> value;
			arr[id].setMaxAmount(value);
			cout << "\n������������ ���������� ���� � ������� ������� ��������.\n\n";			
			break;

		default: if (menu > 4 && menu != 0 || menu < 0) cout << "\n������� ������ ����� ����.\n\n";	break;
		}
	} while (menu != 0);

}

void Airport::findPlaneByDirection(string direction)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].getDirection() == direction)
		{
			cout << "���� �����: " << i + 1;
			arr[i].showInfo();
			cout << endl;
		}
	}
}

void Airport::showAirport() const
{
	if (size > 0)
	{
		cout << "\n===================================\n";
		for (int i = 0; i < size; i++)
		{
			cout << "\t������ �" << i + 1 << endl;
			arr[i].showInfo();
			cout << endl;
		}
		cout << "===================================\n\n";
	}
	else
	{
		cout << "\n\t��������! ����������� �������� ����������� ��� ��������!\n";
	}
}

Airplane& Airport::operator[](int id)
{
	return arr[id];
}

Airplane Airport::operator[](string flightnumber)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].getFlNumber() == flightnumber)
		{
			return arr[i];
		}
	}
	return Airplane("Noflight", "Noflight", 1, 1);
}

void Airport::saveInfoAP()
{
	ofstream fw("Airport.txt");

	if (fw.is_open())
	{
		fw << this->size << endl;
		for (int i = 0; i < this->size; i++)
		{
			arr[i].saveInfoA(fw);
		}
		fw.close();
		cout << "\n������ ��������� ������� ��������� � ���� ������!\n\n";
	}
	else
	{
		cout << "\n������ �������� ���� ������ ���������! ��������� �����.\n\n";
	}
}

void Airport::loadInfoAP()
{
	ifstream fr("Airport.txt");
	if (fr.is_open())
	{
		fr >> this->size;
		arr = new Airplane[size];

		for (int i = 0; i < this->size; i++)
		{
			arr[i].loadInfoA(fr);
		}
		fr.close();
		cout << "\n������ ��������� ������� ��������� �� ���� ������!\n\n";
	}
	else
	{
		cout << "\n������ �������� ���� ������ ���������! ��������� �����.\n\n";
		this->size = 0;
		arr = nullptr;
	}
}
