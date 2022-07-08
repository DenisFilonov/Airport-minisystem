#pragma once
#include"Airplane.h"

class Airport
{
	/*
	�� ������� ���� (10-12), ������� ������� (�����), ����������� �������� �������� (��������, ������� ������): 
	�	����������, 
	�	��������,  
	�	��������������
	�	�����.
	�	����������� �������� ��������������
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

