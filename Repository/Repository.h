//
// Created by user on 4/5/2022.
//

#ifndef LAB7_REPOSITORY_H
#define LAB7_REPOSITORY_H

#include<ostream>
#include "../Domain/Cheltuiala.h"
#include "../Domain/Vector.h"

using namespace std;

template<class T>
class Repository {
private:
    Vector<T> entities;
public:
    /**
     * Constructor
     */
    Repository();

    Repository(const Repository<T> &repository);


    /**
 * Destructor
 */
    ~Repository() = default;
/**
 * Adds an entity to repository
 * @param entity - the entity to be added
 */
    void addEntity(T entity);
/**
 * Removes an entity to the repository
 * @param entity - the entity to be removed
 */
    void remove(T entity);
/**
 * updates an entity
 * @param index - the index of the entity to be updated
 * @param entity - the entity to be updated
 */
    void update(unsigned int index, T entity);
/**
 * Gets al the entities
 * @return a vector containing all the entities
 */
    Vector<T> getAll();
    /**
     * Gets an entity to a given index
     * @param index - the index of the entity
     * @return - the entity wanted
     */

    T getEntity(int index);
/**
 * Gets the number of the entities
 * @return
 */
    int getSize();
    /**
     * Refactor repo
     * @param newEntities
     */
    void modifyList(Vector<T> newEntities);


    template<class Y>
    friend std::ostream &operator<<(std::ostream &os, const Repository<Y> &repository);
};

template<class T>
Repository<T>::Repository() = default;

template<class T>
Repository<T>::Repository(const Repository<T> &repository) {
    this->entities = repository.entities;

}

template<class T>
void Repository<T>::addEntity(T entity) {
    this->entities.push_back(entity);
}

template<class T>
Vector<T> Repository<T>::getAll() {
    return this->entities;
}

template<class T>
T Repository<T>::getEntity(int index) {
    return entities.at(index);
}

template<class T>
int Repository<T>::getSize() {
    return this->entities.size();
}

template<class T>
void Repository<T>::remove(T entity) {
    for (int i = 0; i < this->entities.size(); i++) {
        if (this->entities[i] == entity) {
            this->entities.remove(i);
            break;
        }
    }
}

template<class T>
void Repository<T>::update(unsigned int index, T entity) {
    this->entities.remove(index);
    this->entities.insert(index, entity);
}


template<class Y>
std::ostream &operator<<(std::ostream &os, const Repository<Y> &repository) {
    os << repository.entities;
    return os;
}

template<class T>
void Repository<T>::modifyList(Vector<T> newEntities) {
    this->entities = newEntities;
}



#endif //LAB7_REPOSITORY_H
