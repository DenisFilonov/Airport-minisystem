#pragma once
#include"Airplane.h"

class Airport
{
	/*
	НА ВЫСОКИЙ БАЛЛ (10-12), СОЗДАТЬ СИСТЕМУ (КЛАСС), УПРАВЛЯЮЩУЮ МАССИВОМ ОБЪЕКТОВ (Аэропорт, Магазин одежды): 
	•	Добавление, 
	•	Удаление,  
	•	Редактирование
	•	Поиск.
	•	Перегрузить оператор индексирования
	*/
	int size;
	Airplane* arr;

public:
	Airport();
	~Airport();
	
	const int getAmount()const;
	void addPlane(Airplane obj);
	void delPlane(int id);
	void changeInfoOfPlane(int id);
	void findPlaneByDirection(string direction);
	void showAirport()const;

	Airplane& operator[](int id);
	Airplane operator[](string flightnumber);

	void saveInfoAP();
	void loadInfoAP();
};

