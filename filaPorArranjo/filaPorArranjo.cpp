#include <iostream>
#include <clocale>
using namespace std;

const int tamanho = 10;

struct Fila{
    int vetNum[tamanho];
    int frente, tras;
};

void criarFila(Fila &f){
    f.frente = 0;
    f.tras = f.frente;
}

bool estaVazia(Fila f){
    return f.frente == f.tras;
}

bool estaCheia(Fila f){
    return f.tras >= tamanho;
}

void enfileirar(Fila &f, int item){
    if(!estaCheia(f)){
        f.vetNum[f.tras] = item;
        f.tras++;
    }else{
        cout<<"Fila cheia, não foi possível remover"<<endl;
    }
}

void desenfileirar(Fila &f){
    if(!estaVazia(f)){
        f.frente++;
    }else{
        cout<<"Fila vazia, nada para remover"<<endl;
    }
}

void mostrar(Fila f){
    if(!estaVazia(f)){
        for(int i = f.frente; i < f.tras; i++){
            cout<<"Mostrando item da fila: "<<f.vetNum[i]<<endl;
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

    //abaixo mostra o problema desta implementação, onde mesmo a fila não contendo
    //nenhum item, não conseguimos adicionar, isso é facilmente resolvido com aritmética modular
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
