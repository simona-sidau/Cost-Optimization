#include <cassert>
#include "TestsService.h"
#include "../Service/CheltuialaService.h"

void TestService::testService() {
    testCrud();
    testFunctionalities();

}


void TestService::testCrud() {
    CheltuialaService serv;
    assert(serv.read().size() == 0);

    //Tests add
    serv.addCheltuiala(1, "apa", 20);
    serv.addCheltuiala(2, "altele", 15);
    assert(serv.getCheltuiala(1).getSum() == 20);
    assert(strcmp(serv.getCheltuiala(1).getType(), "apa") == 0);
    assert(serv.getCheltuiala(2).getSum() == 15);
    assert(strcmp(serv.getCheltuiala(2).getType(), "altele") == 0);

    //Tests read
    assert(serv.read().size() == 2);

    //TestEntityRepo update
    serv.updateCheltuiala(1, 1, "gaz", 25);

    assert(serv.getCheltuiala(1).getSum() == 25);
    assert(strcmp(serv.getCheltuiala(1).getType(), "gaz") == 0);

    //Tests delete
    assert(serv.read().size() == 2);
    serv.deleteCheltuialaNrApartament(1);
    assert(serv.read().size() == 1);

}

void TestService::testFunctionalities() {
    CheltuialaService serv;

    //Test Delete by Id
    serv.addCheltuiala(10, "apa", 250);
    assert(serv.read().size() == 1);
    serv.deleteCheltuialaId(1);
    assert(serv.read().size() == 0);

    //Test delete by Apartament's number
    serv.addCheltuiala(10, "apa", 250);
    serv.addCheltuiala(15, "apa", 150);
    serv.addCheltuiala(10, "gaz", 270);
    assert(serv.read().size() == 3);
    serv.deleteCheltuialaNrApartament(10);
    assert(serv.read().size() == 1);

    //Test delete by type
    serv.addCheltuiala(10, "apa", 250);
    serv.addCheltuiala(10, "gaz", 270);
    assert(serv.read().size() == 3);
    serv.deleteCheltuialaType("apa");
    assert(serv.read().size() == 1);
    serv.deleteCheltuialaNrApartament(10);

    //Test get sum
    serv.addCheltuiala(10, "gaz", 100);
    serv.addCheltuiala(10, "apa", 185);
    serv.addCheltuiala(45, "gaz", 120);

    assert(serv.getSumByType("gaz") == 220);

    //Test get max
    assert(serv.getMax(10).getSum() == 185);

    //Test sort descending
    serv.sortDescending("gaz");
    Vector<Cheltuiala> ch = serv.read();
    assert(ch.size() == 2);
    assert(ch[0].getSum() == 120);

    serv.undo();

    //Test filter by type
    serv.filterByType("gaz");
    ch = serv.read();
    assert(ch.size() == 2);
    assert(ch[0].getSum() == 100);

    serv.undo();

    //Test filyer by sum
    serv.filterBySum(110);
    ch = serv.read();
    assert(ch.size() == 1);
    assert(ch[0].getSum() == 100);

}

void TestService::testUndo() {
    CheltuialaService serv;

    //add
    serv.addCheltuiala(1, "apa", 25);
    assert(serv.read().size() == 1);
    serv.undo();
    assert(serv.read().size() == 0);

    //delete
    serv.addCheltuiala(1, "apa", 25);
    serv.deleteCheltuialaNrApartament(1);
    assert(serv.read().size() == 0);
    serv.undo();
    assert(serv.read().size() == 1);

    //update
    serv.updateCheltuiala(2, 1, "curent", 70);
    Vector<Cheltuiala> ch = serv.read();
    assert(ch[0].getNrApartament() == 1);
    assert(ch[0].getSum() == 70);
    assert(strcmp(ch[0].getType(), "curent") == 0);
    serv.undo();
    ch = serv.read();
    assert(ch[0].getNrApartament() == 1);
    assert(ch[0].getSum() == 25);
    assert(strcmp(ch[0].getType(), "apa") == 0);

    //deleteById
    serv.deleteCheltuialaId(2);
    assert(serv.read().size() == 0);
    serv.undo();
    assert(serv.read().size() == 0);

    serv.deleteCheltuialaId(2);

    //sort descending
    serv.addCheltuiala(1, "apa", 200);
    serv.addCheltuiala(1, "gaz", 320);
    serv.addCheltuiala(18, "apa", 250);
    assert(serv.read().size() == 3);
    serv.sortDescending("apa");
    ch = serv.read();
    assert(ch.size() == 2);
    assert(ch[0].getSum() == 250);
    assert(ch[1].getSum() == 200);
    assert(strcmp(ch[0].getType(), "apa") == 0);
    assert(strcmp(ch[1].getType(), "apa") == 0);

    serv.undo();
    ch = serv.read();
    assert(ch.size() == 3);
    assert(ch[0].getSum() == 200);
    assert(ch[1].getSum() == 320);
    assert(strcmp(ch[0].getType(), "apa") == 0);
    assert(strcmp(ch[1].getType(), "gaz") == 0);

    //filter by type
    serv.filterByType("gaz");
    ch = serv.read();
    assert(ch.size() == 1);
    assert(ch[0].getSum() == 300);
    assert(strcmp(ch[0].getType(), "gaz") == 0);

    serv.undo();

    ch = serv.read();
    assert(ch.size() == 3);
    assert(ch[0].getSum() == 200);
    assert(ch[1].getSum() == 320);
    assert(strcmp(ch[0].getType(), "apa") == 0);
    assert(strcmp(ch[1].getType(), "gaz") == 0);

    //Filter by sum
    serv.filterBySum(300);
    ch = serv.read();
    assert(ch.size() == 2);
    assert(ch[0].getSum() == 250);
    assert(ch[1].getSum() == 200);

    serv.undo();

    ch = serv.read();
    assert(ch.size() == 3);
    assert(ch[0].getSum() == 200);
    assert(ch[1].getSum() == 320);
    assert(strcmp(ch[0].getType(), "apa") == 0);
    assert(strcmp(ch[1].getType(), "gaz") == 0);

}


