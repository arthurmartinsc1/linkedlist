#include <iostream> 

using namespace std;


class Node
{
    public:
    int  key;
    Node *prox;

    Node(int k){
        key = k;
        prox = NULL;
    }

    ~Node(){
        cout << "destrutor " << key << endl;}
};


class ListaEncadeada{
Node *inicio;
public:
ListaEncadeada(){
inicio = NULL;
}
~ListaEncadeada(){
while (inicio){
Node *aux = inicio->prox;
delete inicio;
inicio = aux;
}
}


void inserir(int valor){
    Node *atual = new Node(valor);
    if (atual==NULL){
        cout << "ERRO";
        return;
    }
    //novo no precisa apontar para o primeiro elemento da lista atual
    atual->prox = inicio;
    atual->key = valor;
    inicio = atual;
}



void remover(int valor){
    Node *atual = inicio, *ant = NULL;
    while (atual && atual->key !=valor){
        ant = atual;
        atual = atual->prox;
    }
    if (atual){
        if (atual==inicio)
        //verifica se o no a ser removido é o primeiro da lista
            inicio = inicio->prox;
        else
            //verifica se o no a ser removido não é o primeiro
            ant->prox = atual->prox;
        delete atual;
    }
}


void impressao(){
Node *atual = inicio;
while (atual){
cout << atual->key << " ";
atual = atual->prox;
}
cout << endl;
}
};

int main(){
ListaEncadeada l;

l.inserir(10);
l.inserir(7);
l.inserir(5);

l.impressao();

l.remover(7);
l.remover(9);

l.impressao();
}




