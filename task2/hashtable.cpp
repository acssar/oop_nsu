#include "hashtable.h"


   using namespace std;


unsigned int hash_f(const Key& s, unsigned int table_size){
    std::hash<Key> g;
    return g(s) % table_size;
}


HashTable::HashTable() {
    table_size = 10;
    records = 0;
    list<pair<Key, Value>>* empty_v = nullptr;
    table.resize(table_size, empty_v);
}


HashTable::~HashTable() {
    vector<list<pair<Key, Value>>*>().swap(table);
    records = 0;
}

//constructor (HashTable a(b);) copy
HashTable::HashTable(const HashTable& b){
    table = b.table;
    table_size = b.table_size;
    records = b.records;
}

//constructor move
HashTable::HashTable(HashTable&& b) noexcept {
    table = b.table;
    table_size = b.table_size;
    records = b.records;
    for (auto& it : b.table) {
        it = nullptr;
    }
}

//copying operator q = b
HashTable& HashTable::operator=(const HashTable& b) {
    if (this == &b) {
        return *this;
    }
    table_size = b.table_size;
    records = b.records;
    table.clear();
    table = b.table;

    return *this;
}

//noexcept - гарантия безопасной работы
HashTable& HashTable::operator=(HashTable&& b) noexcept {
    if (this == &b) {
        return *this;
    }
    table_size = b.table_size;
    records = b.records;
    table.clear();
    table = b.table;
    for (auto it : b.table) {
        it = nullptr;
    }
    return *this;
}


void HashTable::resize(){
    vector<list<pair<Key, Value>>*> new_arr = table;
    table.clear();
    table_size *= 2;

    list<pair<Key, Value>>* null_vec = nullptr;
    table.resize(table_size, null_vec);
    for (int i = 0; i < table_size / 2; i++){
        if (!new_arr[i]->empty()){
            for (auto & it : *new_arr[i])
                insert(it.first, it.second);
        }
    }
}


void HashTable::swap(HashTable &b) {
    HashTable buf(b);
    b.table = table;
    b.records = records;
    table = buf.table;
    records = buf.records;
}


void HashTable::clear(){
    list<pair<Key, Value>>* null_list = nullptr;
    table.resize(table_size, null_list);
    records = 0;
    table_size = 0;
}


bool HashTable::erase(const Key& k) {

    if (contains(k)) {
        unsigned int hash = hash_f(k, table_size);
        for (auto it = table[hash]->begin(); it != table[hash]->end(); it++) {
            if (it->first == k) {
                table[hash]->erase(it);
                records--;
            }
            return true;
        }
    }
        return false;
}


bool HashTable::insert(const Key& k, const Value& v){
    if (contains(k))
        return false;

    unsigned int hash = hash_f(k, table_size);

    if (table[hash] == nullptr){
        table[hash] = new list<pair<Key, Value>>;
    }

    table[hash]->push_front(make_pair(k, v));

    if(table[hash]->size() > 10){
        resize();
    }
    records++;
    return true;
}


bool HashTable::contains(const Key& k) const{
    unsigned int hash = hash_f(k, table_size);
    if(table[hash] == nullptr){
        return false;
    }
//    any_of(table[hash]->begin(), table[hash]->end(),[](int i) {return k == table[hash][i].Key;});

    for (const auto & it : *table[hash]) {
        if (it.first == k){
            return true;
        }
    }
    return false;
}


Value& HashTable::operator[](const Key &k) {
    if (contains(k)){
        unsigned int hash = hash_f(k, table_size);
        for (auto & it : *table[hash]){
            if (it.first == k){
                return it.second;
            }
        }
    }
    insert(k, default_value);
    return default_value;
}


Value& HashTable::at(const Key &k) {
    if (contains(k)){
        unsigned int hash = hash_f(k, table_size);
        for (auto & it : *table[hash]){
            if (it.first == k){
                return it.second;
            }
        }
    }

        throw out_of_range("Element doesnt belong to table");
}


size_t HashTable::size() const{
    return records;
}


bool HashTable::empty() const{
    if (!records)
        return true;
    else
        return false;
}


bool operator==(const HashTable& a, const HashTable& b){
    bool size = a.table_size == b.table_size;
    bool table_ = a.table == b.table;
    return size && table_;
}


bool operator!=(const HashTable& a, const HashTable& b){
    bool size = a.table_size == b.table_size;
    bool table_ = a.table == b.table;
    bool r = size && table_;
    return !r;
}

