/*
DUPLA:
Elpidio Viana Cabral Neto - 536369 
Marcelo Mikael Pinheiro Lessa Peres - 536011
*/

#ifndef NODE_CPP
#define NODE_CPP

#include "node.h"
#include <string>

template<typename T>
Node<T>::Node(T val, Node<T> *l, Node<T> *r){
    value = val;
    left = l;
    right = r;
}

template<typename T>
T Node<T>::getValue(){
    return this->value;
}

template<typename T>
void Node<T>::setValue(T newValue){
    this->value = newValue;
}

template<typename T>
Node<T>* Node<T>::getLeft(){
    return this->left;
}

template<typename T>
void Node<T>::setLeft(Node<T>* newLeft){
    this->left = newLeft;
}

template<typename T>
Node<T>* Node<T>::getRight(){
    return this->right;
}

template<typename T>
void Node<T>::setRight(Node<T>* newRight){
    this->right = newRight;
}

// novos metodos
template<typename T>
void Node<T>::addId(string newId) {
    if(id == "") {
        id += newId;
        return;    
    }

    for(int i=0, j = 0; i<id.length(); i++) {
        if(i == id.length()-1){ 
            if(id.substr(j, newId.length()) == newId) return;
        }else if(id[i] == '\t'){
            if(id.substr(j, newId.length()) == newId) return;
            j = i+1;
        }
    }
    id += "\t"+newId;
}

template<typename T>
string Node<T>::getId() {
    return this->id;
}

#endif