/*
DUPLA:
Elpidio Viana Cabral Neto - 536369 
Marcelo Mikael Pinheiro Lessa Peres - 536011
*/
 
#include "doublevector.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//Construtor da classe. 
DoubleVector::DoubleVector() {
    m_size = 0;
    m_capacity = 16;
    m_list = new int[16];
    m_tail = 8;
    m_head = 7;
};

// Construtor da classe com tamanho definido pelo user. 
DoubleVector::DoubleVector(int n) {
    if((n%2) == 1) n++;
    m_size = 0;
    m_capacity = n;
    m_list = new int[m_capacity];
    m_tail = n/2;
    m_head = m_tail-1;
};

// Destrutor da classe. 
DoubleVector::~DoubleVector() {
    delete [] m_list;
    m_size = 0, m_capacity = 0, m_head = 0, m_tail = 0;
}; 

// Retorna o numero de elementos na lista.
int DoubleVector::size() {
    return m_size;
}; 

int DoubleVector::capacity() {
    return m_capacity;
};

// Retorna true se a lista estiver vazia e false caso contrario.
bool DoubleVector::empty(){
    if(m_size == 0) return true;
    return false;
};

//  Insere o inteiro value ao lado direito da lista.
void DoubleVector::push_back(int value) { 
    if(size() == capacity()) resize();
    else if(m_tail == capacity()) shift();

    m_list[m_tail] = value;
    m_size++;
    m_tail++;
};

// Remove ultimo elemento do lado direito da lista e retorna seu valor
int DoubleVector::pop_back() {
    int aux = m_list[m_tail-1];
    m_tail--;
    m_size--;
    return aux;
};

// Insere o inteiro value no inicio da lista
void DoubleVector::push_front(int value) {
    if(size() == capacity()) {
        //printf("-AAAA-");
        resize();
    }
    else if(m_head == -1) {
        //printf("-BBBBB-");
        shift();
    }

    m_list[m_head] = value;
    m_head--;
    m_size++;
}; 

// Remove elemento do inicio da lista e retorna seu valor.
int DoubleVector::pop_front() {
    int aux = m_list[m_head+1];
    m_head++;
    m_size--;
    return aux;
};

// Retorna o elemento da lista de indice k 
int DoubleVector::at(int k) {
    if(k > size() || k < 0) return -1;
    int indice = m_head+1+k;
    return m_list[indice];
};

// Realiza o deslocamento completo, seja para a direita ou esquerda.
void DoubleVector::shift() {
    int rest = (capacity()-size());
    if(rest > 1) rest /= 2;         // tratamento: 1 de espaço sobrando
    
    if(m_tail == capacity()) {
        //printf("-CCCCCC-");
        int new_head = m_head-rest+1;  
        int index = m_head+1;
        for(int i = 0; i < size(); i++) m_list[new_head+i] = m_list[index+i];
        m_head = new_head-1;
        m_tail = m_tail-rest;
    } else {
        //printf("-DDDDD-");
        int new_tail = m_tail+rest-1;
        int index = m_tail-1;
        for(int i = 0; i < size(); i++) m_list[new_tail-i] = m_list[index-i];
        m_tail = new_tail+1;
        m_head += rest;
    }
};

// Duplica a capacidade da lista, deixando os elementos antigos no meio do novo vetor. 
void DoubleVector::resize() {
    m_capacity *= 2;
    int* aux = new int[capacity()];
    int new_head = ((capacity()/2)) - (size() / 2); // 4-2 = 2      
    
    for(int i=0; i<size(); i++) aux[new_head + i] = m_list[m_head + 1 + i];
    
    delete [] m_list;
    m_list = aux;

    m_head = new_head - 1;
    m_tail = ((capacity()/2)) + (size() / 2);
}

// Remove o elemento de indice k da lista 
void DoubleVector::remove(int k) {
    if(k >= capacity()/2) {
        for(int i = m_head+1+k; i+1 != m_tail; i++) m_list[i] = m_list[i+1];
        m_tail--; 
    } else {
        for(int i = m_head+1+k; i-1 != m_head; i--) m_list[i] = m_list[i-1];
        m_head++;
    }
    m_size--;
};

// Remove da lista todas as ocorrencias de value.
void DoubleVector::removeAll(int value) {
    for(int i=0; i<size(); i++) {
        if(at(i) == value) {
            remove(i);
            i--;
        }
    }
};

// Imprime os elementos da lista.
void DoubleVector::print() {
    for(int i=0; i<size(); i++) {
        // printf("Valor: %d; M_tail: %d; M_head: %d; Size: %d; Capacidade: %d\n", m_list[m_head+1+i], m_tail, m_head, size(), capacity());
        printf("%d ", at(i));
    }
};

// Imprime os elementos da lista em ordem reversa.
void DoubleVector::printReverse() {
    for(int i = size()-1; i > -1; i--) printf("%d ", at(i));
};

// Concatena a lista atual com a lista lst passada por parametro. 
void DoubleVector::concat(DoubleVector& lst) {
    for(int i = 0; i < lst.size(); i++) push_back(lst.at(i));
};

// Retorna true se as listas forem iguais, caso contrario, retorna false.
bool DoubleVector::equal(DoubleVector& lst) {
    if(lst.size() != size()) return false;
    for(int i = 0; i < size(); i++) {
        if(at(i) != lst.at(i)) return false;
    }
    return true;
};

// funçoes para teste //

void DoubleVector::replaceAt(int value, int index) {
    m_list[m_head+1+index] = value;
};

void DoubleVector::insert(int value, int index) {
    if(size() == capacity()) resize();
    if(index >= capacity()/2) {
        //printf("AAAAAAAA");
        if(m_tail == capacity()) shift();
        for(int i = m_tail; i > index+m_head+1; i--) m_list[i] = m_list[i-1];
        m_tail++; 
    } else {
        //printf("BBBBBBBBB");
        if(m_head == -1) shift();
        for(int i = m_head; i < index+m_head+1; i++) m_list[i] = m_list[i+1];
        m_head--;
    }
    m_list[m_head+index+1] = value;
    m_size++;
};
