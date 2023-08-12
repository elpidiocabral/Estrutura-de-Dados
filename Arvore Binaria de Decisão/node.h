/*
DUPLA:
Elpidio Viana Cabral Neto - 536369 
Marcelo Mikael Pinheiro Lessa Peres - 536011
*/

#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;

template<typename T>
class Node {
private:
    T value;  // num do sintoma
    string id; // array de doenças do sintoma
    Node<T> *left;  // ponteiro para filho esquerdo
    Node<T> *right;  // ponteiro para filho direito
    
public:
    /**
     * Construtor que recebe o valor que o nó irá armazenar e os ponteiros para os 
     * filhos esquerdo e direito, respectivamente.
     * */
    Node(T val, Node<T> *l, Node<T> *r);
    
    /**
    Métodos gets e sets dos atributos
    **/
    T getValue();
    Node<T>* getLeft();
    Node<T>* getRight();
    string getId();
    
    
    void setValue(T newValue);
    void setLeft(Node<T>* newLeft);
    void setRight(Node<T>* newRight);
    void addId(string newId);
};
#include "node.cpp"
#endif
