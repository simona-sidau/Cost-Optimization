//
// Created by user on 4/5/2022.
//

#ifndef LAB7_VECTOR_H
#define LAB7_VECTOR_H

#include <ostream>
#include <iostream>
#include "Cheltuiala.h"

template<class T>
class Vector {
private:
    int DEFAULT_CAPACITY = 10;
    T *_entities;
    int _capacity;
    int _size;

    void resize(){
        _capacity = _capacity + DEFAULT_CAPACITY;
        T* newEntities = new T[_capacity];
        for (int i = 0; i < _size; i++) {
            newEntities[i] = _entities[i];
        }
        delete[] _entities;
        _entities = newEntities;
    }

public:
/**
 * Constructor
 */
    Vector();

    /**
     * Copy constructor
     * @param vector
     */

    Vector(const Vector<T> &vector);

/**
 * Deconstructor
 */
    ~Vector();

    /**
     * Adds an entity
     * @param entity
     */

    void push_back(T entity);

/**
 * Gets the size of the vector
 * @return the size of the vector
 */
    int size() const;

    /**
     * inserts an entity
     * @param index
     * @param value
     */

    void insert(unsigned int index, T const &value);

/**
 * remove one entity from the vector
 * @param index
 */
    void remove(unsigned int index);

    T pop_back() {
        T value = _entities[_size - 1];
        this->remove(_size - 1);
        return value;
    }

    /**
     * gets an entity from a given index
     * @param index
     * @return - the entity
     */

    T &at(int index) const;

    T &operator=(const Vector<T> &rhs);

    T &operator[](int index);

    friend std::ostream &operator<<(std::ostream &os, const Vector<T> &vector) {
        for (int i = 0; i < vector._size; i++) {
            os << vector[i] << '\n';
        }
        return os;
    }
};

template<class T>
Vector<T>::Vector() {
    _capacity = DEFAULT_CAPACITY;
    _entities = new T[_capacity];
    _size = 0;
}

template<class T>
Vector<T>::Vector(const Vector<T> &vector) {
    /* this->_capacity = vector._capacity;
     this->_size = vector._size;
     auto *newEntities = new T[_capacity];
     for (int i = 0; i < _size; i++) {
         newEntities[i] = vector._entities[i];
     }
     this->_entities = newEntities;*/
    /*this->_capacity = vector._capacity;
    this->_size = vector._size;
    delete[] this->_entities;
    this->_entities = new T[_capacity];
    for(int i = 0; i < _size; i++) {
        this->_entities[i] = vector._entities[i];
    }
*/
    this->_capacity = vector._capacity;
    this->_size = vector._size;
    T* newEntities = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        newEntities[i] = vector._entities[i];
    }
    this->_entities = newEntities;

}


template<class T>
Vector<T>::~Vector() {
    delete[] this->_entities;
}


template<class T>
void Vector<T>::push_back(T entity) {
    if (_size == _capacity) {
        resize();
    }
    _entities[_size] = entity;
    _size++;
}


template<class T>
void Vector<T>::insert(unsigned int index, const T &value) {
    if (index > this->_size) {
        return;
    }
    if (this->_size == this->_capacity) {
        this->resize();
    }
    for (int i = this->_size; i > index; i--) {
        this->_entities[i] = this->_entities[i - 1];
    }
    this->_entities[index] = value;
    this->_size++;

}

template<class T>
void Vector<T>::remove(unsigned int index) {
    for(int i = index; i < this->_size - 1; i++) {
        _entities[i] = _entities[i + 1];
    }
    this->_size--;

}
template<class T>
int Vector<T>::size() const {
    return this->_size;
}

template<class T>
T &Vector<T>::operator[](int index) {
    return this->_entities[index];
}

template<class T>
T &Vector<T>::at(int index) const {
    return this->_entities[index];
}

template<class T>
T &Vector<T>::operator=(const Vector<T> &rhs) {
    this->_size = rhs._size;
    this->_capacity = rhs._capacity;
    delete[] this->_entities;
    this->_entities = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        this->_entities[i] = rhs._entities[i];
    }
    //return *this;

    /*this->_capacity = rhs._capacity;
    this->_size = rhs._size;
    delete[] this->_entities;
    this->_entities = new T[_capacity];
    for(int i = 0; i < _size; i++){
        this->_entities[i] = rhs._entities[i];
    }
    return *this;*/
}


#endif //LAB7_VECTOR_H
