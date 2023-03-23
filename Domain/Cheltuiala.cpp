#include "Cheltuiala.h"
#include <iostream>
#include <cstring>


Cheltuiala::Cheltuiala() {
    this->id = 0;
    this->nrApartament = 0;
    this->type = nullptr;
    this->sum = 0;

}

Cheltuiala::Cheltuiala(unsigned int id, unsigned int nrApartament, const char *t, int sum) {
    this->id = id;
    this->nrApartament = nrApartament;
    this->type = new char[strlen(t) + 1];
    strcpy(this->type, t);
    this->sum = sum;

}

Cheltuiala::Cheltuiala(const Cheltuiala &rhs) {
    this->id = rhs.id;
    this->nrApartament = rhs.nrApartament;
    this->type = new char[strlen(rhs.type) + 1];
    strcpy(this->type, rhs.type);
    this->sum = rhs.sum;


}

Cheltuiala::~Cheltuiala() {
    delete[] this->type;
    this->type = nullptr;
}


void Cheltuiala::setSum(int newSum) {
    this->sum = newSum;

}

int Cheltuiala::getSum() {
    return this->sum;

}

int Cheltuiala::getNrApartament() {
    return this->nrApartament;
}

void Cheltuiala::setNrApartament(int newNrApartament) {
    this->nrApartament = newNrApartament;

}

char *Cheltuiala::getType() {
    return const_cast<char *>(this->type);
}


void Cheltuiala::setType(char *newType) {

    delete[] this->type;
    this->type = new char[strlen(newType) + 1];
    strcpy(this->type, newType);

}

int Cheltuiala::getId() {
    return this->id;
}

void Cheltuiala::setId(unsigned int newId) {
    this->id = newId;
}

bool Cheltuiala::operator<(const Cheltuiala &rhs) const {
    if (strcmp(type, rhs.type) == 0) {
        if (nrApartament < rhs.nrApartament)
            return true;
        if (sum < rhs.sum)
            return true;
    }
    return false;

}

bool Cheltuiala::operator>(const Cheltuiala &rhs) const {
    return rhs < *this;
}

bool Cheltuiala::operator<=(const Cheltuiala &rhs) const {
    return !(rhs < *this);
}

bool Cheltuiala::operator>=(const Cheltuiala &rhs) const {
    return !(*this < rhs);
}

bool Cheltuiala::operator==(const Cheltuiala &rhs) const {
    return this->id == rhs.id &&
           this->nrApartament == rhs.nrApartament &&
           strcmp(type, rhs.type) == 0 &&
           this->sum == rhs.sum;
}

bool Cheltuiala::operator!=(const Cheltuiala &rhs) const {
    return !(rhs == *this);
}


Cheltuiala &Cheltuiala::operator=(const Cheltuiala &rhs) {
    delete[] this->type;
    this->id = rhs.id;
    this->nrApartament = rhs.nrApartament;
    this->sum = rhs.sum;

    this->type = new char[strlen(rhs.type) + 1];
    strcpy(this->type, rhs.type);

    return *this;
}

std::ostream &operator<<(std::ostream &os, const Cheltuiala &cheltuiala) {
    os << "Cheltuiala {" << '\n';
    os << "ID: " << cheltuiala.id << '\n';
    os << "Numar apartament: " << cheltuiala.nrApartament << '\n' << " Suma: " << cheltuiala.sum << '\n' << " Tipul: "
       << cheltuiala.type;
    os << '\n' << "}";
    return os;
}

