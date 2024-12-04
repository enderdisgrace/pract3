#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"


template <typename V>
class BSTreeDict : public Dict<V> {
private:
    
    BSTree<TableEntry<V>>* tree;

public:
    
    BSTreeDict() : tree(new BSTree<TableEntry<V>>()) {}

    ~BSTreeDict() {
        delete tree;
    }

    friend std::ostream& operator<<(std::ostream& out, const BSTreeDict<V>& dict) {
        dict.tree->print_inorder(out);
        return out;
    }

    V operator[](const std::string& key) {
        return this->search(key); 
    }

    
    std::vector<TableEntry<V>> entries() override {
        return tree->inorder();  
    }

    void insert(const std::string& key, const V& value) override {
        TableEntry<V> entry(key, value);
        tree->insert(entry);
    }

    V search(const std::string& key) const override {
        TableEntry<V> entry(key); 
        TableEntry<V>* found = tree->search(entry);
        if (found != nullptr) {
            return found->value;
        } else {
            throw std::runtime_error("Clave no encontrada");
        }
    }

    void remove(const std::string& key) override {
        TableEntry<V> entry(key);
        tree->remove(entry);
    }
};

#endif
