/*
DUPLA:
Elpidio Viana Cabral Neto - 536369 
Marcelo Mikael Pinheiro Lessa Peres - 536011
- - -
Enviamos o TXT de sintomas também!
*/

// salve salve humilde
#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include"binarytree.cpp"

using namespace std;


int main() {
    ifstream arquivo("SintomasMenor.txt"); // base de dados fornecida pelo profº.
                                      // tambem conseguimos rodar com a base de dados maior (b^_^)
    string texto;

    string* doencas;
    string* sintomas;

    /*
        Setando o numero de doenças e sintomas
        num_doenca = numero de doenças
        num_sintoma = numero de sintomas
        doencas = lista de doencas
        sintomas = lista de sintomas
    */
    getline(arquivo, texto); // linha 0
    int space = texto.find(" ");
    int num_doenca = stoi(texto.substr(0, space));
    int num_sintoma = stoi(texto.substr(space));

    doencas = new string[num_doenca];
    sintomas = new string[num_sintoma];
    
    for(int i = 0; i < num_doenca; i++) {
        getline(arquivo, texto);
        doencas[i] = texto;
    }

    for(int i = 0; i < num_sintoma; i++) {
        getline(arquivo, texto);
        sintomas[i] = texto;
    }

    /*
        criação da arvore binaria de decisao
    */
    BinaryTree<int> arvore = BinaryTree<int>(); 
    Node<int>* raiz = new Node<int>(-1, nullptr, nullptr); // -1: padrão para nó interno!
    arvore.setRoot(raiz);

    while (getline (arquivo, texto)) { 
        int tab = texto.find("\t");
        string id = texto.substr(0, tab);

        Node<int>* aux = arvore.getRoot();

        /*
            Usando o padrão de espaço entre o codigo do diagnostico, pegamos o tamanho da linha e trabalhamos 
            a iteração baseado em já termos o cod da doença em "id"
        */
        for(int i = tab+1; i < texto.length(); i += 2) {
            int decisao = texto[i]-'0';
            Node<int>* no;
            if(decisao == 1) {
                no = aux->getLeft();
                if(no == nullptr){
                    no = new Node<int>(-1, nullptr, nullptr);
                    aux->setLeft(no);
                }
            } 
            else {
                no = aux->getRight(); 
                if(no == nullptr) {
                    no = new Node<int>(-1, nullptr, nullptr);
                    aux->setRight(no);
                }
            }           
            aux = no;
        }
        aux->addId(id);
    }

    arquivo.close();

    /*
        Inicio do questionário de diagnostico!
    */
    while(true) {
        Node<int>* no = raiz;
        queue<int> resposta;

        cout << "\nDeseja 'REALIZAR DIAGNOSTICO' ou 'SAIR'?" << endl;
        cout << "1: 'REALIZAR DIAGNOSTICO' \n0: 'SAIR'" << endl;
        int s;
        cin >> s;
        if(!s) break;

        cout << "\n!Auxiliar no Diagnostico de doencas!" << endl;
        cout << "Sera questionado se voce possui certos sintomas!" << endl;
        cout << "Digite 1 para 'Sim' \nDigite 0 para 'Nao'\n" << endl;
        
        for(int j = 0; j < num_sintoma; j++) {
            cout << "Voce esta sentindo/com '" << sintomas[j] << "' ?" << endl;
            int r;
            cin >> r;
            resposta.push(r);
            // ta top
        }
        
        // percorrendo a arvore com a fila
        bool null_diag = false;
        while(!resposta.empty()) {
            int r = resposta.front();
            resposta.pop();

            if(r == 1) no = no->getLeft();
            else no = no->getRight();
            if(no == nullptr) {
                cout << "\nNao ha diagnostico para esses sintomas! \n" << endl;
                null_diag = true;
                break;
            }
        }

        if(null_diag) continue;            // se não ha diagnostico, pule para proxima iteração
        string diagnostico = no->getId();
        
        //cout << "diagnostico antes pae: " << diagnostico << endl;
        cout << "\nVoce possui a(s) seguinte(s) doenca(s): " << endl;
        for(int j = 0, i = 0; j < diagnostico.length(); j++) {
            if(j == diagnostico.length()-1) {
                cout << doencas[stoi(diagnostico.substr(i, j-i+1))-1] << endl;
            }else if(diagnostico[j] == '\t'){
                cout << doencas[stoi(diagnostico.substr(i, j-i+1))-1] << '\t';
                i = j+1;
            } 
        }
    }
}