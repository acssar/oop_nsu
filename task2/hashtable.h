//
// Created by roman on 27/09/21.
//

//guards/only includes once (pragma once)
#ifndef TASK2_HASHTABLE_H
#define TASK2_HASHTABLE_H

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>


using namespace std;


struct Student {
    unsigned age;
    unsigned weight;
};

typedef string Key;     //ключом будет выступать строка(имя студента)
typedef Student Value;  //значением - произвольная структура(численные характеристики студента)

unsigned int hash_f(const Key& s, unsigned int table_size);

class HashTable {
private:
    vector<list<pair<Key, Value>>*> table;
    int table_size;
    int records;
    Value default_value{19, 65};
public:
    HashTable(); //constr

    ~HashTable(); //destruct

    HashTable(const HashTable& b); //copy constr

    HashTable(HashTable&& b) noexcept ; //move constr

    HashTable& operator=(const HashTable& b); //copy operator
    HashTable& operator=(HashTable&& b) noexcept ; //move operator

    void resize();

    // Обменивает значения двух хэш-таблиц.
    void swap(HashTable& b);

    // Очищает контейнер.
    void clear();
    // Удаляет элемент по заданному ключу.
    bool erase(const Key& k);
    // Вставка в контейнер. Возвращаемое значение - успешность вставки.
    bool insert(const Key& k, const Value& v);

    // Проверка наличия значения по заданному ключу.
    bool contains(const Key& k) const;

    // Возвращает значение по ключу. Небезопасный метод.
    // В случае отсутствия ключа в контейнере, следует вставить в контейнер
    // значение, созданное конструктором по умолчанию и вернуть ссылку на него.
    Value& operator[](const Key& k);

    // Возвращает значение по ключу. Бросает исключение при неудаче.
    Value& at(const Key& k);

    size_t size() const;
    bool empty() const;

    friend bool operator==(const HashTable& a, const HashTable& b);
    friend bool operator!=(const HashTable& a, const HashTable& b);
};
#endif //TASK2_HASHTABLE_H
