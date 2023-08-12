/*
DUPLA:
Elpidio Viana Cabral Neto - 536369 
Marcelo Mikael Pinheiro Lessa Peres - 536011
*/
 
#ifndef DOUBLEVECTOR_H
#define DOUBLEVECTOR_H

class DoubleVector {
    private:
        int* m_list; // "array" de valores da lista
        int  m_size; // quantidade de elementos atual no vetor
        int  m_capacity; // capacidade máxima do vetor
        int  m_head; // aponta para o local do próximo elemento a ser inserido na esquerda
        int  m_tail; // aponta para o local do próximo elemento a ser inserido na direita
        
    public:
        //Construtor da classe. 
        DoubleVector(); 

        // Construtor da classe com tamanho definido pelo user. 
        DoubleVector(int n);  

        // Destrutor da classe. 
        ~DoubleVector(); 

        // Retorna o numero de elementos na lista.
        int size(); 

        // Retorna a capacidade da lista
        int capacity();
    
        // Retorna true se a lista estiver vazia e false caso contrario.
        bool empty();
    
        //  Insere o inteiro value ao final da lista.
        void push_back(int value);
        
        // Remove elemento do final da lista e retorna seu valor
        int pop_back();
        
        // Insere o inteiro value no inicio da lista
        void push_front(int value);
        
        // Remove elemento do inicio da lista e retorna seu valor.
        int pop_front();
        
        // Retorna o elemento da lista de indice k 
        int at(int k); // essa função deve ser O(1)
        
        // Realiza o deslocamento completo, seja para a direita ou esquerda.
        void shift();
        
        // Duplica a capacidade da lista, deixando os elementos antigos no meio do novo vetor. 
        void resize();
        
        // Remove o elemento de indice k da lista 
        void remove(int k);
        
        // Remove da lista todas as ocorrencias de value.
        void removeAll(int value);
        
        // Imprime os elementos da lista.
        void print();
        
        // Imprime os elementos da lista em ordem reversa.
        void printReverse();
        
        // Concatena a lista atual com a lista lst passada por parametro. 
        void concat(DoubleVector& lst);

        // Retorna true se as listas forem iguais, caso contrario, retorna false.
        bool equal(DoubleVector& lst);

        void replaceAt(int value, int index);

        void insert(int value, int index);
};

#endif