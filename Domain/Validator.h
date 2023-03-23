//
// Created by user on 4/18/2022.
//

#ifndef MAIN_CPP_VALIDATOR_H
#define MAIN_CPP_VALIDATOR_H

#include <cstring>
#include "Cheltuiala.h"

class Validator{
public:
    Validator() = default;
    ~Validator() = default;
    /**
     * Validates an Entity
     * @param ch
     */
    void validate(Cheltuiala ch){
        char validTypes[5][20] ={"apa", "curent", "gaz", "caldura", "altele"};
        int ok = 0;
        for(int i = 0; i < 5; i++){
            if(strcmp(validTypes[i], ch.getType())==0){
                ok = 1;
            }
        }
        if(!ok){
            throw std::invalid_argument("Invalid type");
        }

    }
};
#endif //MAIN_CPP_VALIDATOR_H
