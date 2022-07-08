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
	cout << "\nСамолёт успешно добавлен в эксплуатацию.\n";
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
	cout << "\nСамолёт успешно снят с эксплуатации.\n";
}

void Airport::changeInfoOfPlane(int id)
{
	int menu = 0;
	string str = "";
	int value = 0;
	do
	{
		cout << "\n\tМЕНЮ ИЗМЕНЕНИЯ ИНФОРМАЦИИ:";
		cout << "\n1) Номер рейса.";
		cout << "\n2) Направление рейса.";
		cout << "\n3) Количество занятых мест в самолёте.";
		cout << "\n4) Максимальное количество мест в самолёте.";
		cout << "\n0. Вернуться назад.\nВыбор: ";
		cin >> menu;

		switch (menu)
		{

		case 1:
			cout << "\nНомер: ";
			cin.ignore();
			getline(cin, str);
			arr[id].setFlNumber(str);
			cout << "\nНомер рейса успешно записан.\n\n";
			break;

		case 2:
			cout << "\nНаправление: ";
			cin.ignore();
			getline(cin, str);
			arr[id].setDirection(str);
			cout << "\nНаправление рейса успешно записано.\n\n";
			break;

		case 3:
			cout << "\nЗанятые места: ";
			cin >> value;
			arr[id].setAmountInside(value);
			cout << "\nКоличество занятых мест в самолёте успешно записано.\n\n";
			break;

		case 4:
			cout << "\nМаксимально мест: ";
			cin >> value;
			arr[id].setMaxAmount(value);
			cout << "\nМаксимальное количество мест в самолёте успешно записано.\n\n";			
			break;

		default: if (menu > 4 && menu != 0 || menu < 0) cout << "\nНеверно выбран пункт меню.\n\n";	break;
		}
	} while (menu != 0);

}

void Airport::findPlaneByDirection(string direction)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].getDirection() == direction)
		{
			cout << "Борт номер: " << i + 1;
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
			cout << "\tСамолёт №" << i + 1 << endl;
			arr[i].showInfo();
			cout << endl;
		}
		cout << "===================================\n\n";
	}
	else
	{
		cout << "\n\tВнимание! Отсутствуют заданные направления для самолётов!\n";
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
		cout << "\nДанные аэропорта успешно загружены в базу данных!\n\n";
	}
	else
	{
		cout << "\nОшибка загрузки базы данных аэропорта! Проверьте файлы.\n\n";
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
		cout << "\nДанные аэропорта успешно выгружены из базы данных!\n\n";
	}
	else
	{
		cout << "\nОшибка выгрузки базы данных аэропорта! Проверьте файлы.\n\n";
		this->size = 0;
		arr = nullptr;
	}
}
