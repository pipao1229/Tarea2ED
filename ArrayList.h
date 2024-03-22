#pragma once

#define DEFAULT_MAX_SIZE 1024

#include <stdexcept>
#include <iostream>
#include "List.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class ArrayList : public List<E> {
protected:
    E* elements;
    int max;
    int size;
    int pos;

public:
    ArrayList(int max = DEFAULT_MAX_SIZE) {
        elements = new E[max];
        this->max = max;
        size = pos = 0;
    }

    ~ArrayList() {
        delete[] elements;
    }

    void expand() {
        int newMax = max * 2;
        E* newElements = new E[newMax];

        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }

        delete[] elements;
        elements = newElements;
        max = newMax;
    }

    void insert(E element) {
        if (size == max)
            expand(); // Ahora se usa el método expand en lugar de tirar error
        for (int i = size; i > pos; i--)
            elements[i] = elements[i - 1];
        elements[pos] = element;
        size++;
    }

    void append(E element) {
        if (size == max)
            expand(); // Ahora se usa el método expand en lugar de tirar error
        elements[size] = element;
        size++;
    }

    void set(E element) {
        if (pos == size)
            throw runtime_error("No current element.");
        elements[pos] = element;
    }

    E remove() {
        if (size == 0)
            throw runtime_error("List is empty.");
        if (pos == size)
            throw runtime_error("No current element.");
        E result = elements[pos];
        for (int i = pos; i < size - 1; i++)
            elements[i] = elements[i + 1];
        size--;
        return result;
    }

    void clear() {
        pos = size = 0;
    }

    E getElement() {
        if (size == 0)
            throw runtime_error("List is empty.");
        if (pos == size)
            throw runtime_error("No current element.");
        return elements[pos];
    }

    void goToStart() {
        pos = 0;
    }

    void goToEnd() {
        pos = size;
    }

    void goToPos(int pos) {
        if (pos < 0 || pos > size)
            throw runtime_error("Index out of bounds.");
        this->pos = pos;
    }

    void next() {
        if (pos < size)
            pos++;
    }

    void previous() {
        if (pos > 0)
            pos--;
    }

    bool atStart() {
        return pos == 0;
    }

    bool atEnd() {
        return pos == size;
    }

    int getSize() {
        return size;
    }

    int getPos() {
        return pos;
    }

    int indexOf(E element) {
        for (int i = 0; i < size; i++) {
            if (elements[i] == element) {
                return i;  // Retorna la posición del elemento si se encuentra
            }
        }
        return -1;  // Retorna -1 si el elemento no se encuentra en la lista
    }

    bool contains(E element) {
        for (int i = 0; i < size; i++) {
            if (elements[i] == element) {
                return true;  // Retorna true si el elemento se encuentra en la lista
            }
        }
        return false;  // Retorna false si el elemento no se encuentra en la lista
    }

    void print() {
        cout << "[ ";
        for (int i = 0; i < size; i++)
            cout << elements[i] << " ";
        cout << "]" << endl;
    }
};

