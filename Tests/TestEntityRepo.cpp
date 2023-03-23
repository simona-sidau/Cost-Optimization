#include "TestEntityRepo.h"
#include "TestsService.h"
#include "../Domain/Cheltuiala.h"
#include "../Repository/Repository.h"
#include "../Service/CheltuialaService.h"
#include<cassert>
#include <cstring>

void TestEntityRepo::testAll() {

    getters();
    setters();
    testRepo();
}

void TestEntityRepo::constructors() {
    Cheltuiala ch;
    assert(ch.getSum() == 0);

    char c[5] = "apa";
    Cheltuiala ch1(1, 1, c, 5);
    assert(ch1.getNrApartament() == 1);
    assert(ch1.getSum() == 5);
    assert(strcmp(ch1.getType(), c) == 0);

    Repository<Cheltuiala> repo;
    repo.addEntity(ch);
    assert(repo.getSize() == 1);
    repo.addEntity(ch1);
    assert(repo.getSize() == 2);


}

void TestEntityRepo::getters() {
    char c[5] = "apa";
    Cheltuiala ch(1, 1, c, 120);
    assert(ch.getSum() == 120);
    assert(ch.getNrApartament() == 1);
    assert(strcmp(ch.getType(), "apa") == 0);

    Repository<Cheltuiala> repo;
    Cheltuiala c1(1, 1, c, 10);
    Cheltuiala c2(2, 2, c, 20);
    Cheltuiala c3(3, 3, c, 25);

    repo.addEntity(c1);
    repo.addEntity(c2);
    repo.addEntity(c3);

    assert(repo.getSize() == 3);
    assert(repo.getEntity(0).getSum() == 10);
    assert(repo.getEntity(1).getSum() == 20);
    assert(repo.getEntity(2).getSum() == 25);


}

void TestEntityRepo::setters() {
    Cheltuiala ch;
    assert(ch.getSum() == 0);
    ch.setSum(2);
    assert(ch.getSum() == 2);
}


void TestEntityRepo::testRepo() {
    Repository<Cheltuiala> repo;

    //Constructor
    assert(repo.getSize() == 0);

    //Add entity
    Cheltuiala ch(0, 1, "apa", 120);
    repo.addEntity(ch);

    //Update
    Cheltuiala h(1, 1, "gaz", 130);
    repo.update(0, h);
    assert(repo.getEntity(0).getSum() == 130);
    assert(strcmp(repo.getEntity(0).getType(), "gaz") == 0);

    //Delete
    repo.addEntity(ch);
    assert(repo.getSize() == 2);
    repo.remove(ch);
    assert(repo.getSize() == 1);

}
