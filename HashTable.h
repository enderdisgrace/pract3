#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

template <typename V>
class HashTable: public Dict<V> {

    private:
        int n,max;
        std::list<TableEntry<V>>* table;
        int h(std::string key) {
            int sum = 0;
            for (char c : key) {
                sum += int(c); 
            }
            return sum % max; 
        }


    public:
        HashTable(int size) : n(0), max(size) {
            table = new ListLinked<TableEntry<V>>[max];
        }

        ~HashTable(){
            delete[] table;
        }

        int capacity(){
            return max;
        }

    V operator[](std::string key) {
        int index = h(key); 
        
        for (int i = 0; i < table[index].size(); ++i) { 
            
            if (table[index][i] == key) { 
                return table[index][i].value; 
            }
        }
        throw std::runtime_error("Key not found");
    }


        
    friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &ht) {
        for (int i = 0; i < ht.max; ++i) { 
            out << "Bucket " << i << ": "; 
        
            for (int j = 0; j < ht.table[i].size(); ++j) {
                out << ht.table[i][j] << " ";
            }
            
            out << "\n"; 
        }
        return out;
    }


        
};

#endif



