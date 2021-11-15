#include <catch2/catch_test_macros.hpp>
#include "hashtable.h"


TEST_CASE( "testing =, ==, !=, []") {
    HashTable h1, h2 = HashTable();
    h1.insert("Student1", {18, 70});
    h2.insert("Student2", {22, 74});
    REQUIRE( h1 != h2 );
    h2 = h1;
    REQUIRE(h1["Student1"].age == 18);
    REQUIRE(h1["Student1"].weight == 70);
    HashTable h3 = HashTable(h2);
    HashTable h4 (move(h3));
    REQUIRE( h1 == h4);
}

TEST_CASE("testing contains"){
    HashTable h1 = HashTable();
    h1.insert("Student1", {18, 70});
    REQUIRE(h1.contains("Student1"));
    REQUIRE_FALSE(h1.contains("Student2"));
}

TEST_CASE("testing swap"){
    HashTable h1, h2 = HashTable();
    h1.insert("Student1", {18, 70});
    h2.insert("Student2", {22, 74});
    REQUIRE(h1.contains("Student1"));
    REQUIRE_FALSE(h1.contains("Student2"));
    REQUIRE_FALSE(h2.contains("Student1"));
    REQUIRE(h2.contains("Student2"));
    h1.swap(h2);
    REQUIRE_FALSE(h1.contains("Student1"));
    REQUIRE(h1.contains("Student2"));
    REQUIRE(h2.contains("Student1"));
    REQUIRE_FALSE(h2.contains("Student2"));

}

TEST_CASE("testing erase"){
    HashTable h1 = HashTable();
    h1.insert("Student1", {18, 70});
    h1.insert("Student2", {22, 74});
    REQUIRE_FALSE(h1.erase("Student3"));
    REQUIRE(h1.size() == 2);
    h1.erase("Student2");
    REQUIRE(h1.size() == 1);
}

TEST_CASE("testing insert"){
    HashTable h1 = HashTable();
    h1.insert("Student1", {18, 70});
    REQUIRE(h1.size() == 1);
    h1.insert("Student2", {22, 74});
    REQUIRE(h1.size() == 2);
    REQUIRE(h1.contains("Student2"));
}

TEST_CASE("testing at"){
    HashTable h1,h2 = HashTable();
    h1.insert("Student1", {18, 70});
    h2.insert("Student1", {18, 70});
    Value value = {18, 70};
    Value value2 = h1.at("Student1");
    REQUIRE(value.age == value2.age);
    REQUIRE(value.weight == value2.weight);
}

TEST_CASE("testing clear & empty"){
    HashTable h1 = HashTable();
    h1.insert("Student1", {20, 80});
    REQUIRE(h1.contains("Student1"));
    h1.clear();
    REQUIRE(h1.empty());

}




