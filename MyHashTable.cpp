#include <sstream>
#include "MyHashTable.h"

using namespace std;

// Default constructor. Do not modiify.
MyHashTable::MyHashTable() {
  for (size_t i = 0; i < CAPACITY; i++) {
    table[i] = new vector<pair<string, int>>;
  }
}

// Simple hash function. Do not modify.
size_t MyHashTable::hash(string name) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < name.size(); i++) {
		accumulator += name.at(i);
	}
	return accumulator % CAPACITY;
}

void MyHashTable::insertItem(string name, int perm) {
	int index = hash(name);
	table[index]->push_back(std::make_pair(name,perm));
}

void MyHashTable::deleteItem(string name) {
	
	for(size_t i=0; i < this -> CAPACITY; i++){
		
		for(vector<std::pair<std::string, int>>::iterator j = table[i]->begin(); j!= table[i]->end(); j++){
			 if(j->first == name){
			  table[i]->erase(j);
			  return;
			}
		}
	}
	return;
}

string MyHashTable::toString() const {
std::ostringstream oss;
	for(size_t i=0; i < this -> CAPACITY; i++){
		oss<< i <<":";
		if (table[i]->empty())
				{ oss<< "[]"<<endl;
				}
		else{
				oss<<"[";
			for(vector<std::pair<std::string, int>>::iterator j = table[i]->begin(); j!= table[i]->end(); j++){
				oss<<"("<<  j->first<<","<<j->second<<")";
				}
				oss<< "]"<<endl;
		}
	}
	
	return oss.str();
}


MyHashTable::MyHashTable(const MyHashTable &orig) {
	for (size_t i = 0; i < CAPACITY; i++) {
		delete table[i];
    table[i] = new vector<pair<string, int>>;

  }
	for(size_t i=0; i < CAPACITY; i++){
			for(vector<std::pair<std::string, int>>::iterator j = orig.table[i]->begin(); j!= orig.table[i]->end(); j++){
				this->table[i]->push_back(std::make_pair(j->first,j->second));		
			}
	}

}

MyHashTable::~MyHashTable() {

	for (size_t i = 0; i < CAPACITY; i++){
		
		table[i]->clear();
		delete table[i];
		
	}
	
}
