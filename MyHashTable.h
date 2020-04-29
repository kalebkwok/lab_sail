#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>

class MyHashTable {

  public:

    MyHashTable();
    void insertItem(std::string name, int perm);
    void deleteItem(std::string name);
    std::string toString() const;

    MyHashTable(const MyHashTable &orig);
    ~MyHashTable();


  private:

    const static size_t CAPACITY = 5;
    // capacity for the hash table array
    
    size_t hash(std::string word) const;
    // Hash function that will return an index for the hash table.
    // This is implemented for you in MyHashTable.cpp.

    std::vector<std::pair<std::string, int>>* table[CAPACITY];
    // hash table array of vectors. Each index in the array will contain
    // a pointer to a vector on the heap. Each element in the vector
    // contains a <string, int> pair where the string value represents a
    // unique name of a student and the int value represents the perm
    // number of that student.


};


#endif
