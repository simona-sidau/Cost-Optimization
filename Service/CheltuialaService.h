#include <set>
#include <string>
#include <queue>
#include <cstring>
#include "../Repository/Repository.h"
#include "../Domain/Cheltuiala.h"

#ifndef LAB7_CHELTUIALASERVICE_H
#define LAB7_CHELTUIALASERVICE_H

class CheltuialaService {
private:
    Repository<Cheltuiala> repo;
    Vector<Vector<Cheltuiala>> undoVector;
    int idEntity = 1;

public:
    /**
     * Constructor
     */
    CheltuialaService();

    /**
     * Destructor
     */
    ~CheltuialaService();

    /**
     * Add a new entity
     * @param nrApartament - nrApartament of entity
     * @param sum - sum of money
     * @param type - the type
     */
    void addCheltuiala(unsigned int nrApartament, const std::string &type, int sum);

    /**
     * Deletes the entities with the given nrAp
     * @param nrApartament -
     */
    void deleteCheltuialaNrApartament(int nrApartament);
    /**
     * delete the entities with the given ID
     * @param id
     */
    void deleteCheltuialaId(int id);
    /**
     * Deletes all the entities with a given type
     * @param type
     */
    void deleteCheltuialaType(const std::string &type);

    /**
     * Update an entity in the Repository
     * @param id - the ID of the entity to update
     * @param sum - the new sum
     * @param type - the new type
     */
    void updateCheltuiala(unsigned int id, unsigned int nrApartament, const std::string &type, int sum);

    /**
     * Gets an entity from a given nrApartament
     * @param id
     * @return an entity
     */

    Cheltuiala getCheltuiala(int id);

    /**
     * Gets all the entities
     * @return a vector containing the entities
     */
    Vector<Cheltuiala> read();
    /**
     * Calculate the bill's sum for a given type
     * @param type
     * @return
     */
    int getSumByType(const std::string &type);
    /**
     * Gets the most expensive bill for a given apartment
     * @param nrAp
     * @return
     */
    Cheltuiala getMax(int nrAp);
    /**
     * Sorts descending the entities with a given type
     * @param type
     */
    void sortDescending(const std::string &type);
    /**
     * Filter by a given type
     * @param type
     */
    void filterByType(const std::string &type);
    /**
     * Remove all the entities which has the sum above a given one
     * @param sum
     */
    void filterBySum(int sum);

    void undo();

};

#endif //LAB7_CHELTUIALASERVICE_H
