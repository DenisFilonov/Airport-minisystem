#include"Airport.h"
#include<Windows.h>

int main()
{
	setlocale(NULL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int menu, menu1;
	string s1 = "", s2 = "";
	int tmp1 = 0, tmp2 = 0;
	int id = 0;

	Airport* Gdansk = new Airport(); // Gdańsk - is a city in Poland, this Airport is named after Lekh Walensa "Port Lotniczy Gdańsk im. Lecha Wałęsy", you can look to img
	Airplane tmp;

	cout << "\nЗапуск процесса загрузки информации аэропорта.";
	Gdansk->loadInfoAP();
	cout << "\nНачало работы системы терминала.\n\n";
	// Bonus
	system("start Port_lotniczy.jpg");
	system("start IMG_20191221_153846.jpg");
	system("start IMG_20191221_153930_1.jpg");
	system("start IMG_20191223_125946.jpg");
	system("start IMG_20191221_153909.jpg");

	do
	{
		cout << "\n1. Добавить новый рейс полёта.";
		cout << "\n2. Удалить имеющийся рейс полёта.";
		cout << "\n3. Изменить информацию рейса полёта.";
		cout << "\n4. Показать список задействованных рейсов.";
		cout << "\n5. Поиск рейса полёта.";
		cout << "\n6. Создать копию рейса на основе имеющегося.";
		cout << "\n0. Завершить работу и сохранить информацию.\nВыбор: ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			Gdansk->addPlane(Airplane());
			cout << "\nНовый рейс добавлен! Введите следующую информацию:\n\n";
			id = Gdansk->getAmount();
			Gdansk->changeInfoOfPlane(id - 1);
			break;

		case 2:
			cout << "\n1) У меня есть идентификационный номер рейса в системе.";
			cout << "\n2) У меня нет идентификационного номера рейса в системе.\nВыбор: ";
			cin >> tmp1;

			if (tmp1 == 1)
			{
				cout << "\nНомер рейса в системе: ";
				cin >> tmp1;
				Gdansk->delPlane(tmp1 - 1);
			}
			else if (tmp1 == 2)
			{
				cout << "\nНомер рейса: ";
				cin.ignore();
				getline(cin, s1);
				(*Gdansk)[s1].showInfo();
			}
			else cout << "\nНеверно выбран пункт!\n\n";
			break;

		case 3:
			cout << "\nНомер рейса в системе: ";
			cin >> tmp1;
			Gdansk->changeInfoOfPlane(tmp1 - 1);
			break;

		case 4:
			Gdansk->showAirport();
			break;

		case 5:
			cout << "\n\tМЕНЮ ПОИСКА РЕЙСА:\n";
			cout << "\n1) Поиск по направлению.";
			cout << "\n2) Поиск по идентификационному номеру в системе.";
			cout << "\n0. Вернуться назад.\nВыбор:";
			cin >> menu1;

			switch (menu1)
			{

			case 1:
				cout << "\nНаправление: ";
				cin.ignore();
				getline(cin, s1);
				Gdansk->findPlaneByDirection(s1);
				break;

			case 2:
				cout << "\nНомер рейса в системе: ";
				cin >> tmp1;
				(*Gdansk)[tmp1].showInfo();
				break;

			default: if (menu1 > 5 && menu1 != 0 || menu1 < 0) cout << "\nНеверно выбран пункт меню.\n\n";	break;
			}
			break;

		case 6:
			cout << "\nНомер рейса в системе: ";
			cin >> tmp1;
			tmp = (*Gdansk)[tmp1 - 1];
			Gdansk->addPlane(tmp);

			cout << "\nРейс скопирован.\nЖелаете изменить информацию сейчас?\n1) Да\n2) Нет\nВыбор: ";
			cin >> tmp2;
			if (tmp2 == 1)
			{
				id = Gdansk->getAmount();
				Gdansk->changeInfoOfPlane(id - 1);
			}
			else { break; }
			break;

		default: if (menu > 6 && menu != 0 || menu < 0) cout << "\nНеверно выбран пункт меню.\n\n";	break;
		}
	} while (menu != 0);

	cout << "\nЗапуск процесса сохранения информации аэропорта.";
	Gdansk->saveInfoAP();
	cout << "\nЗавершение работы системы терминала.\n";
	if (Gdansk != NULL) delete Gdansk;
	return 0;
}