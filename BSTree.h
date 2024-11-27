#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T> 
class BSTree {
    private:
        int nelem;
        BSNode<T> *root;
        BSNode<T>* search(BSNode<T>* n, T e) const {
        if (n == nullptr) {
            return nullptr; 
        }
        if (e == n->elem) {
            return n; 
        } else if (e < n->elem) {
            return search(n->left, e);
        } else {
            return search(n->right, e);
        }
        }
        template <typename T>
        void print_inorder(std::ostream &out, BSNode<T>* n) const {
            if (n != nullptr) {     
                print_inorder(out, n->left);
                out << n->elem << "-";
                print_inorder(out, n->right);
            }}

        template <typename T>

        BSNode<T>* remove(BSNode<T>* n, T e) {
            if (n == nullptr) {
                throw std::runtime_error("Elemento no encontrado");
            } else if (e < n->elem) {  
                n->left = remove(n->left, e);
            } else if (e > n->elem) {  
                n->right = remove(n->right, e);
            } else {  
                if (n->left != nullptr && n->right != nullptr) {  
                    n->elem = max(n->left);       
                    n->left = remove_max(n->left); 
                } else { 
                    BSNode<T>* temp = (n->left != nullptr) ? n->left : n->right;
                    delete n;  
                    return temp; 
                }
            }
            return n;
        }

        T max(BSNode<T>* n) {
            if (n == nullptr) {
                throw std::runtime_error("Elemento no encontrado");
            }
            while (n->right != nullptr) {  
                n = n->right;
            }
            return n->elem;
        }

   
        BSNode<T>* remove_max(BSNode<T>* n) {
            if (n->right == nullptr) {
                return n->left;  
            }
            n->right = remove_max(n->right);
            return n;
        }

        BSTree() : root(nullptr) {}

        
            void remove(T e) {
            root = remove(root, e);
        }

        void delete_cascade(BSNode<T>* n) {
            if (n != nullptr) {
                
                delete_cascade(n->left);
                delete_cascade(n->right);
                delete n;
            }
        }

    public:
        BSTree();
        int size() const{
            return nelem;
        }

        T search(T e) const {
        BSNode<T>* result = search(root, e);
        if (result != nullptr) {
            return result->elem;
        } else {
            throw std::runtime_error("Elemento no encontrado");
        }
    }
        T operator[](T e) const {
            return search(e);
        }
        friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst);
        void remove(T e){
            remove(BSNode<T>* n, T e);
        }

        ~BSTree(){
            delete_cascade(root);
        }



};
    template <typename T>
    std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
        out=print_inorder();
        return out;
    }




#endif