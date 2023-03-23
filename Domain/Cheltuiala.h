//
// Created by user on 4/5/2022.
//

#ifndef LAB7_CHELTUIALA_H
#define LAB7_CHELTUIALA_H

#include <ostream>
//#include <string>
//#include<sstream>
//#include<cstring>

class Cheltuiala {
private:
    unsigned int id;
    unsigned int nrApartament;
    char* type;
    int sum;
public:
    bool operator==(const Cheltuiala &rhs) const;

    bool operator!=(const Cheltuiala &rhs) const;

/**
 * Constructors without parameters
 */
    Cheltuiala();

/**
 * Constructor with parameters
 * @param id - nrApartament of entity
 * @param sum - sum
 * @param type - the type
 */
    Cheltuiala(unsigned int id, unsigned int nrApartament,const char* type, int sum );

    /**
     * Copy constructor
     * @param ch - entity
     */

    Cheltuiala(const Cheltuiala &rhs);

    /**
     * Destructor
     */
    ~Cheltuiala();

/**
 * Sets the sum
 * @param newSum
 */
    void setSum(int newSum);


/**
 * Gets the sum
 * @return
 */
    int getSum();

/**
 * sets the ID
 * @param newNrApartament
 */
    void setNrApartament(int newNrApartament);

    /**
     * gets the number of apartment
     * @return
     */
    int getNrApartament();

/**
 * Gets the type
 * @return the type
 */
    char *getType();

        /**
     * Sets the description
     * @param newType
     */

    void setType(char *newType);
    /**
      * Gets the id of entity
      * @return
      */
    int getId();

    void setId(unsigned int newId);

    friend std::ostream &operator<<(std::ostream &os, const Cheltuiala &cheltuiala);

    bool operator<(const Cheltuiala &rhs) const;

    bool operator>(const Cheltuiala &rhs) const;

    bool operator<=(const Cheltuiala &rhs) const;

    bool operator>=(const Cheltuiala &rhs) const;

    Cheltuiala &operator=(const Cheltuiala &rhs);


};



#endif //LAB7_CHELTUIALA_H


