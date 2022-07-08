#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Airplane
{
	/*
	–еализовать классы по вариантам. 
	ќб€зательно описать:
	Х	 онструктор по умолчанию 
	Х	 онструктор с параметрами
	Х	ƒеструктор
	Х	 онструктор копировани€
	Х	јксессоры (сеттеры и геттеры)
	Х	ѕерегрузить оператор присвоени€, операторы сравнени€, инкремента, декремента
	Х	ѕерегрузить ввод, вывод

	1 вариант
	—оздать класс Airplane (самолет: номер рейса, направление, текущее кол-во пассажиров, максимальное кол-во пассажиров)
	— помощью перегрузки операторов реализовать:
	1. ѕроверка на равенство по номеру рейса (операци€ = =)
	2. ”величение и уменьшение пассажиров в салоне самолета (операции ++ и - - в префиксной форме)
	3. —равнение двух самолетов по максимально возможному количеству пассажиров на борту (операци€>)
	*/

	string flightNumber;
	string direction;
	int amountInside;
	int maxAmount;

public:
	Airplane();
	Airplane(string flightNumber, string direction, int amountInside, int maxAmount);
	~Airplane();
	Airplane(const Airplane& obj);
	Airplane& operator = (const Airplane& obj);

	bool operator == (const Airplane& obj);
	bool operator != (const Airplane& obj);
	bool operator > (const Airplane& obj);
	bool operator < (const Airplane& obj);
	bool operator >= (const Airplane& obj);
	bool operator <= (const Airplane& obj);
	Airplane& operator -- ();
	Airplane& operator ++ ();
	Airplane operator -- (int);
	Airplane operator ++ (int);
	friend ostream& operator << (ostream& os, const Airplane& obj);
	friend istream& operator >> (istream& is, Airplane& obj);

	/*	
	string flightNumber;
	string direction;
	int amountInside;
	int maxAmount;
	*/
	void setFlNumber(string flightNumber);
	void setDirection(string direction);
	void setAmountInside(int amount);
	void setMaxAmount(int amount);

	string getFlNumber()const;
	string getDirection()const;
	int getAmountInside()const;
	int getMaxAmount()const;

	
	void showInfo();

	void saveInfoA(ofstream& file);
	void loadInfoA(ifstream& file);
};

