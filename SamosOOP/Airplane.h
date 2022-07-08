#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Airplane
{
	/*
	����������� ������ �� ���������. 
	����������� �������:
	�	����������� �� ��������� 
	�	����������� � �����������
	�	����������
	�	����������� �����������
	�	��������� (������� � �������)
	�	����������� �������� ����������, ��������� ���������, ����������, ����������
	�	����������� ����, �����

	1 �������
	������� ����� Airplane (�������: ����� �����, �����������, ������� ���-�� ����������, ������������ ���-�� ����������)
	� ������� ���������� ���������� �����������:
	1. �������� �� ��������� �� ������ ����� (�������� = =)
	2. ���������� � ���������� ���������� � ������ �������� (�������� ++ � - - � ���������� �����)
	3. ��������� ���� ��������� �� ����������� ���������� ���������� ���������� �� ����� (��������>)
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

