#include <iostream>
#include <clocale>

using namespace std;

const int tamanho = 10;

struct Fila{
    int vetNum[tamanho];
    int frente, tras,QuantidadeDeItensNaFila;
};

void criarFila(Fila &f){
    f.frente = 0;
    f.tras = f.frente;
    f.QuantidadeDeItensNaFila = f.frente;
}

bool estaVazia(Fila f){
    return f.QuantidadeDeItensNaFila == 0;
}

bool estaCheia(Fila f){
    return f.QuantidadeDeItensNaFila >= tamanho;
}

void enfileirar(Fila &f, int item){
    if(!estaCheia(f)){
        f.vetNum[f.tras] = item;
        f.tras = (f.tras + 1) % tamanho;
        f.QuantidadeDeItensNaFila++;
    }else{
        cout<<"Fila cheia, não foi possível remover"<<endl;
    }
}

void desenfileirar(Fila &f){
    if(!estaVazia(f)){
        f.frente = (f.frente + 1) % tamanho;
        f.QuantidadeDeItensNaFila--;
    }else{
        cout<<"Fila vazia, nada para remover"<<endl;
    }
}

void mostrar(Fila f){
    if(!estaVazia(f)){
        int aux = f.frente;
        for(int i = 1; i <= f.QuantidadeDeItensNaFila; i++){
            cout<<"Mostrando item da fila: "<<f.vetNum[aux]<<endl;
            aux = (aux + 1) % tamanho;
        }
    }else{
        cout<<"Fila vazia, nada para mostrar"<<endl;
    }
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    Fila fila;
    criarFila(fila);

    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 30);
    enfileirar(fila, 40);
    enfileirar(fila, 50);
    enfileirar(fila, 60);
    enfileirar(fila, 70);
    enfileirar(fila, 80);
    enfileirar(fila, 90);
    enfileirar(fila, 100);
    mostrar(fila);
    cout<<endl;

    desenfileirar(fila);
    desenfileirar(fila);
    desenfileirar(fila);
    desenfileirar(fila);
    desenfileirar(fila);
    mostrar(fila);
    cout<<endl;

    desenfileirar(fila);
    desenfileirar(fila);
    desenfileirar(fila);
    desenfileirar(fila);
    desenfileirar(fila);
    mostrar(fila);
    cout<<endl;

    //abaixo mostra o problema da implementação passada resolvida, onde mesmo a fila não contendo
    //nenhum item, não conseguíamos adicionar.
    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 30);
    enfileirar(fila, 40);
    enfileirar(fila, 50);
    enfileirar(fila, 60);
    enfileirar(fila, 70);
    enfileirar(fila, 80);
    enfileirar(fila, 90);
    enfileirar(fila, 100);
    mostrar(fila);

    return 0;
}
