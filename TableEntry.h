#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>
using namespace std;

template <typename V> 
class TableEntry {
    public:

        string key;
        V value;

        TableEntry(std::string key, V value):key(key), value(value){}
        TableEntry(std::string key):key(key), value(){}
        TableEntry():key(""), value(){}

        friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2){
            if(te1.key==te2.key){return 1;}
            else{
                return 0;}
        }
        friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2){
            if(te1.key!=te2.key){return 1;}
            else{
                return 0;}
        }
        friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te){
            out<<te.key<<"->"<<te.value<<endl;
                return out;
        }

    
};

#endif