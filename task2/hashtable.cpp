//
// Created by drizzt on 27.09.2021.
//
#include "hashtable.h"
#include <string>

struct Student {
    unsigned age;
    unsigned weight;
};

typedef std::string Key;
typedef Student Value;


class HashTable
{
public:
    HashTable();
    ~HashTable();

    HashTable(const HashTable& b);
    HashTable(HashTable&& b);

    HashTable& operator=(const HashTable& b);
    HashTable& operator=(HashTable && b);

    void swap(HashTable& b);

    void clear();

    bool erase(const Key& k);

    bool insert(const Key& k, const Value& v);

    bool contains(const Key& k) const;

    Value& oparator[](const Key& k);

    Value& at(const Key& k);
    const Value& at(const Key& k) const;

    size_t size() const;
    bool empty() const;

    friend bool operator==(const HashTable& a, const HashTable& b);

    friend bool operator!=(const HashTable& a, const HashTable& b);
};

bool operator==(const HashTable& a, const HashTable& b);
bool operator==(const HashTable& a, const HashTable)