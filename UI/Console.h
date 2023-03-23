//
// Created by user on 4/5/2022.
//
#include "../Repository/Repository.h"
#include "../Service/CheltuialaService.h"

#ifndef LAB7_CONSOLE_H
#define LAB7_CONSOLE_H


class Console {
private:
    CheltuialaService serv;
public:
    void showMenu();

    void runMenu();


};

#endif //LAB7_CONSOLE_H
