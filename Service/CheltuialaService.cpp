#include "CheltuialaService.h"
#include "../Domain/Validator.h"
#include <iostream>

CheltuialaService::CheltuialaService() = default;

CheltuialaService::~CheltuialaService() = default;

void CheltuialaService::addCheltuiala(unsigned int nrApartament, const std::string &type, int sum) {
    Validator validator;
    undoVector.push_back(repo.getAll());
    Cheltuiala ch(this->idEntity, nrApartament, type.c_str(), sum);
    validator.validate(ch);
    repo.addEntity(ch);
    this->idEntity++;

}

void CheltuialaService::deleteCheltuialaNrApartament(int nrApartament) {
    undoVector.push_back(repo.getAll());
    Vector<Cheltuiala> ch = repo.getAll();
    for (int i = 0; i < ch.size(); i++) {
        if (ch[i].getNrApartament() == nrApartament) {
            repo.remove(ch[i]);
            }
        }

}

void CheltuialaService::updateCheltuiala(unsigned int id, unsigned int nrApartament, const string &type, int sum) {
    Validator validator;
    undoVector.push_back(repo.getAll());
    Vector<Cheltuiala> cheltuieli = repo.getAll();
    const char* type_chr = type.c_str();
    Cheltuiala ch(id,nrApartament, type_chr, sum);
    validator.validate(ch);
    for (int i = 0; i < repo.getSize(); i++) {
        if (cheltuieli[i].getId() == id) {
            repo.update(i, ch);
            return;
        }
    }


}

Cheltuiala CheltuialaService::getCheltuiala(int id) {
    Vector<Cheltuiala> cheltuieli = repo.getAll();
    for (int i = 0; i < cheltuieli.size(); i++) {
        if (cheltuieli[i].getNrApartament() == id) {
            return cheltuieli[i];
        }
    }
}

Vector<Cheltuiala> CheltuialaService::read() {
    return repo.getAll();
}

void CheltuialaService::deleteCheltuialaId(int id) {
    undoVector.push_back(repo.getAll());
    Vector<Cheltuiala> ch = repo.getAll();
    for (int i = 0; i < ch.size(); i++) {
        if (ch[i].getId() == id) {
            repo.remove(ch[i]);
            return;
        }
    }
}

void CheltuialaService::deleteCheltuialaType(const std::string &type) {
    undoVector.push_back(repo.getAll());
    Vector<Cheltuiala> ch = repo.getAll();
    for (int i = 0; i < ch.size(); i++)
        if (ch[i].getType() == type) {
            repo.remove(ch[i]);
        }

}

int CheltuialaService::getSumByType(const string &type) {
    int sum =0;
    Vector<Cheltuiala> ch = repo.getAll();
    for (int i = 0; i < ch.size(); i++) {
        if (ch[i].getType() == type){
            sum += ch[i].getSum();
        }
    }
    return sum;
}

Cheltuiala CheltuialaService::getMax(int nrAp) {
    Cheltuiala max;
    Vector<Cheltuiala> ch = repo.getAll();
    for (int i = 0; i < ch.size(); i++) {
        if(ch[i].getNrApartament() == nrAp && ch[i].getSum() > max.getSum()){
            max = ch[i];
        }
    }
    return max;

}

void CheltuialaService::sortDescending(const string &type) {
    undoVector.push_back(repo.getAll());
    Vector<Cheltuiala> ch = repo.getAll();
    Vector<Cheltuiala> result;
    for(int i =0; i < ch.size(); i++){
        if(ch[i].getType() == type){
            result.push_back(ch[i]);
        }
    }
    Cheltuiala copy;
    for(int i = 0; i < result.size() - 1; i++){
        for(int j = i + 1; j < result.size(); j++){
            if(result[i] < result[j]){
                copy = result[i];
                result[i] = result[j];
                result[j] = copy;
            }
        }
    }
    repo.modifyList(result);
}

void CheltuialaService::filterByType(const string &type) {
    undoVector.push_back(repo.getAll());
    Vector<Cheltuiala> ch = repo.getAll();
    Vector<Cheltuiala> result;
    for(int i =0; i < ch.size(); i++){
        if(ch[i].getType() == type){
            result.push_back(ch[i]);
        }
    }
    repo.modifyList(result);

}

void CheltuialaService::filterBySum(int sum) {
    undoVector.push_back(repo.getAll());
    Vector<Cheltuiala> ch = repo.getAll();
    Vector<Cheltuiala> result;
    for(int i =0; i < ch.size(); i++){
        if(ch[i].getSum() < sum){
            result.push_back(ch[i]);
        }
    }
    repo.modifyList(result);

}

void CheltuialaService::undo() {
    if(undoVector.size() != 0){
        repo.modifyList(undoVector.pop_back());
    }
    else{
        std::cout<<"Nu exista o actiune anterioara"<< '\n';
    }


}
