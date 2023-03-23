#include "UI/Console.h"
#include "Tests/TestAll.h"


int main() {

    TestAll test;
    test.testAll();

    Console console;
    console.runMenu();


}
