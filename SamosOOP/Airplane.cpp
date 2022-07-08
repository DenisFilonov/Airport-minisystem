#include "Airplane.h"

Airplane::Airplane()
{
    flightNumber = "LL000";
    direction = "SomeCity";
    amountInside = 0;
    maxAmount = 0;
}

Airplane::Airplane(string flightNumber, string direction, int amountInside, int maxAmount)
{
    this->flightNumber = flightNumber;
    this->direction = direction;
    this->amountInside = amountInside;
    this->maxAmount = maxAmount;
}

Airplane::~Airplane()
{
    //Ничего, т.к. не исп. иниц. д/с || We have nothing here, because we don't using dynamic memory
}

Airplane::Airplane(const Airplane& obj)
{
    this->flightNumber = obj.flightNumber;
    this->direction = obj.direction;
    this->amountInside = obj.amountInside;
    this->maxAmount = obj.maxAmount;
}

Airplane& Airplane::operator=(const Airplane& obj)
{
    this->flightNumber = obj.flightNumber;
    this->direction = obj.direction;
    this->amountInside = obj.amountInside;
    this->maxAmount = obj.maxAmount;
    return *this;
}

bool Airplane::operator==(const Airplane& obj)
{
    if (this->flightNumber == obj.flightNumber)
    {
        return true;
    }
    else return false;
}

bool Airplane::operator!=(const Airplane& obj)
{
    return !(*this == obj);
}

bool Airplane::operator>(const Airplane& obj)
{
    if (this->amountInside > obj.amountInside)
    {
        return true;
    }
    else return false;
}

bool Airplane::operator<(const Airplane& obj)
{
    if (this->maxAmount < obj.maxAmount)
    {
        return true;
    }
    else return false;
}

bool Airplane::operator>=(const Airplane& obj)
{
    if (this->maxAmount > obj.maxAmount || this->maxAmount == obj.maxAmount) return true;
    else return false;
}

bool Airplane::operator<=(const Airplane& obj)
{
    if (this->amountInside < obj.amountInside || this->amountInside == obj.amountInside) return true;
    else return false;
}

Airplane& Airplane::operator--()
{
    Airplane tmp = *this;
    if (this->amountInside > 0) this->amountInside--;
    return *this;
}

Airplane& Airplane::operator++()
{
    Airplane tmp = *this;
    this->amountInside++;
    return *this;
}

Airplane Airplane::operator--(int)
{
    if (this->amountInside > 0)
    {        
        this->amountInside--;        
    }
    else cout << "\nОперация невозможна!\n\n";

    return *this;
}

Airplane Airplane::operator++(int)
{
    Airplane tmp = *this;
    if (this->amountInside < this->maxAmount)
    {
        this->amountInside++;
    }
    else cout << "\nОперация невозможна!\n\n";

    return *this;
}

ostream& operator<<(ostream& os, const Airplane& obj)
{
    os << "Номер рейса: " << obj.flightNumber;
    os << "\nНаправление рейса: " << obj.direction;
    os << "\nКоличество занятых мест в самолёте: " << obj.amountInside;
    os << "\nМаксимальное количество мест в самолёте: " << obj.maxAmount;
    return os;
}

istream& operator>>(istream& is, Airplane& obj)
{
    cout << "Номер рейса:";
    is >> obj.flightNumber;
    cout << "Направление рейса:";
    is >> obj.direction;
    cout << "Количество занятых мест в самолёте:";
    is >> obj.amountInside;
    cout << "Максимальное количество мест в самолёте:";
    is >> obj.maxAmount;
    return is;
}

void Airplane::setFlNumber(string flightNumber)
{
    if (flightNumber.size() > 0) this->flightNumber = flightNumber;
}

void Airplane::setDirection(string direction)
{
    if (direction.size() > 0) this->direction = direction;
}

void Airplane::setAmountInside(int amount)
{
    if (amount > 0) this->amountInside = amount;
}

void Airplane::setMaxAmount(int amount)
{
    if (amount > 0) this->maxAmount = amount;
}

string Airplane::getFlNumber() const
{
    return flightNumber;
}

string Airplane::getDirection() const
{
    return direction;
}

int Airplane::getAmountInside() const
{
    return amountInside;
}

int Airplane::getMaxAmount() const
{
    return maxAmount;
}

void Airplane::showInfo() const
{
    cout << "\nНомер рейса: " << this->flightNumber;
    cout << "\nНаправление рейса: " << this->direction;
    cout << "\nКоличество занятых мест в самолёте: " << this->amountInside;
    cout << "\nМаксимальное количество мест в самолёте: " << this->maxAmount << endl;
}

void Airplane::saveInfoA(ofstream& file)
{
    file << this->flightNumber << endl;
    file << this->direction << endl;

    file << this->amountInside << endl;
    file << this->maxAmount << endl;
}

void Airplane::loadInfoA(ifstream& file)
{
    char a = file.get();
    getline(file, this->flightNumber);
    getline(file, this->direction);

    file >> this->amountInside;
    file >> this->maxAmount;
}

void Airplane::toBin(ofstream& file)
{
    int tmp = 0;
    tmp = flightNumber.size();
    file.write((char*)&tmp, sizeof(int));

    file.write(flightNumber.c_str(), tmp);

    tmp = direction.size();
    file.write((char*)&tmp, sizeof(int));
    file.write(direction.c_str(), tmp);

    file.write((char*)&amountInside, sizeof(int));
    file.write((char*)&maxAmount, sizeof(int));
}

void Airplane::frBin(ifstream& file)
{
    int tmp = 0;
    file.read((char*)&tmp, sizeof(int));
    file.read((char*)&flightNumber, tmp);

    file.read((char*)&tmp, sizeof(int));
    file.read((char*)&direction, tmp);

    file.read((char*)&amountInside, sizeof(int));
    file.read((char*)&maxAmount, sizeof(int));
}
