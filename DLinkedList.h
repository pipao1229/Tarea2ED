#pragma once
#include <stdexcept>
#include <iostream>
#include "List.h"
#include "DNode.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class DLinkedList : public List<E>
{
private:
	DNode<E>* head;
	DNode<E>* tail;
	DNode<E>* current;
	int size;

public:
	DLinkedList() {
		current = head = new DNode<E>(nullptr, nullptr);
		head->next = tail = new DNode<E>(nullptr, head);
		size = 0;
	}
	~DLinkedList() {
		clear();
		delete head;
		delete tail;
	}
	void insert(E element) {
		current->next = current->next->previous
			= new DNode<E>(element, current->next, current);
		size++;
	}
	void append(E element) {
		tail->previous = tail->previous->next
			= new DNode<E>(element, tail, tail->previous);
		size++;
	}
	void set(E element) {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (current->next == tail)
			throw runtime_error("No current element.");
		current->next->element = element;
	}
	E remove() {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (current->next == tail)
			throw runtime_error("No current element.");
		E result = current->next->element;
		current->next = current->next->next;
		delete current->next->previous;
		current->next->previous = current;
		size--;
		return result;
	}
	void clear() {
		while (head->next != tail) {
			head->next = head->next->next;
			delete head->next->previous;
		}
		tail->previous = head;
		size = 0;
	}
	E getElement() {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (current->next == tail)
			throw runtime_error("No current element.");
		return current->next->element;
	}
	void goToStart() {
		current = head;
	}
	void goToEnd() {
		current = tail->previous;
	}
	void goToPos(int pos) {
		if (pos < 0 || pos > size)
			throw runtime_error("Index out bounds.");
		current = head;
		for (int i = 0; i < pos; i++) {
			current = current->next;
		}
	}
	void next() {
		if (current != tail->previous)
			current = current->next;
	}
	void previous() {
		if (current != head)
			current = current->previous;
	}
	bool atStart() {
		return current == head;
	}
	bool atEnd() {
		return current == tail->previous;
	}
	int getSize() {
		return size;
	}
	int getPos() {
		// Elaborado por Alejandro Madrigal
		DNode<E>* temp = head;
		int i;
		for (i = 0; current != temp; i++)
			temp = temp->next;
		return i;
	}
	int indexOf(E element) {
		DNode<E>* temp = head->next;
		int index = 0;
		while (temp != tail) {
			if (temp->element == element) {
				return index;  // Retorna la posición del elemento si se encuentra
			}
			temp = temp->next;
			index++;
		}
		return -1;  // Retorna -1 si el elemento no se encuentra en la lista
	}
	bool contains(E element) {
		DNode<E>* temp = head->next;
		while (temp != tail) {
			if (temp->element == element) {
				return true;  // Retorna true si el elemento se encuentra en la lista
			}
			temp = temp->next;
		}
		return false;  // Retorna false si el elemento no se encuentra en la lista
	}
	void print() {
		cout << "[ ";
		DNode<E>* temp = head->next;
		while (temp != tail) {
			cout << temp->element << " ";
			temp = temp->next;
		}
		cout << "]" << endl;
	}
};

