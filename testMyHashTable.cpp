#include "MyHashTable.h"
#include "tddFuncs.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {

  // A sample test.
  MyHashTable ht;
  ht.insertItem("Hermione Granger", 27437);
  ht.insertItem("Ron Weasley", 49872);
  ht.insertItem("Harry Potter", 39857);
  ht.insertItem("Tom Riddle", 12984);
  string expected = "0:[(Hermione Granger,27437)(Ron Weasley,49872)]\n1:[]\n2:[(Tom Riddle,12984)]\n3:[(Harry Potter,39857)]\n4:[]\n";
  cout<< ht.toString()<<endl;
  ASSERT_EQUALS(expected, ht.toString());
  // Write your own tests below.
  MyHashTable a(ht);
  cout<< a.toString()<<endl;
  

  return 0;
}
