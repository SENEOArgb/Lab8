#pragma once
#include "Smartphones.h"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

// Определение узла списка
struct Node {
    Smartphone data;
    Node* prev;
    Node* next;
    Node(const Smartphone& smartphone) : data(smartphone), prev(nullptr), next(nullptr) {}
};

class PhonesList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    PhonesList() : head(nullptr), tail(nullptr), size(0) {}
    ~PhonesList();

    void addToPosition(const Smartphone& smartphone, int position);
    void removeFromPosition(int position);
    Smartphone getValueAtPosition(int position) const;
    pair<int, int> findBrand(const string& brand) const;
    vector<Smartphone> getSmartphonesWithScreenSize(double screenSize) const;
};

// Деструктор для класса 
PhonesList::~PhonesList() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

// Добавление элемента в заданную позицию
void PhonesList::addToPosition(const Smartphone& smartphone, int position) {
    if (position < 0)
        position = 0;
    else if (position > size)
        position = size;

    Node* newNode = new Node(smartphone);
    if (size == 0) {
        head = newNode;
        tail = newNode;
    }
    else if (position == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else if (position == size) {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    else {
        Node* current = head;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
    }
    ++size;
}

// Удаление элемента по номеру позиции
void PhonesList::removeFromPosition(int position) {
    if (position < 0 || position >= size)
        throw out_of_range("Invalid position");

    Node* current;
    if (size == 1) {
        current = head;
        head = nullptr;
        tail = nullptr;
    }
    else if (position == 0) {
        current = head;
        head = head->next;
        head->prev = nullptr;
    }
    else if (position == size - 1) {
        current = tail;
        tail = tail->prev;
        tail->next = nullptr;
    }
    else {
        current = head;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    delete current;
    --size;
}

// Получение значения элемента по номеру позиции
Smartphone PhonesList::getValueAtPosition(int position) const {
    if (position < 0 || position >= size)
        throw out_of_range("Invalid position");

    Node* current = head;
    for (int i = 0; i < position; ++i) {
        current = current->next;
    }
    return current->data;
}

// Поиск по марке
pair<int, int> PhonesList::findBrand(const string& brand) const {
    pair<int, int> positions(-1, -1);
    Node* current = head;
    int pos = 0;
    while (current) {
        if (current->data.brand == brand) {
            if (positions.first == -1)
                positions.first = pos;
            positions.second = pos;
        }
        current = current->next;
        ++pos;
    }
    return positions;
}

// Получение описаний всех смартфонов с указанной диагональю экрана
vector<Smartphone> PhonesList::getSmartphonesWithScreenSize(double screenSize) const {
    vector<Smartphone> smartphones;
    Node* current = head;
    while (current) {
        if (current->data.screen_size == screenSize) {
            smartphones.push_back(current->data);
        }
        current = current->next;
    }
    return smartphones;
}