#include "TestEntityRepo.h"
#include "TestsService.h"
#ifndef MAIN_CPP_TESTALL_H
#define MAIN_CPP_TESTALL_H
class TestAll{
public:
    TestAll() = default;
    ~TestAll() = default;

    void testAll(){

        TestEntityRepo testEntityRepo;
        testEntityRepo.testAll();

        TestService testService;
        testService.testService();
    }
};

#endif //MAIN_CPP_TESTALL_H
