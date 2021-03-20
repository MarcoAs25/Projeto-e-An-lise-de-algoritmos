#include <iostream>
#include <clocale>

using namespace std;

int const tamanho = 10;

struct Pilha{
    int vetNum[tamanho];
    int fundo,topo;
};

void criarPilha(Pilha &p){
    p.topo = 0;
    p.fundo = p.topo;
}

bool estaVazia(Pilha p){
    return p.topo == p.fundo;
}

bool estaCheia(Pilha p){
    return p.topo >= tamanho;
}

void empilhar(Pilha &p, int item){
    if(!estaCheia(p)){
        p.vetNum[p.topo] = item;
        p.topo++;
    }else{
        cout<<"Pilha cheia, não é possível adicionar"<<endl;
    }
}

void desempilhar(Pilha &p){
    if(!estaVazia(p)){
        p.topo--;
    }else{
        cout<<"pilha vazia!"<<endl;
    }
}

void mostrar(Pilha p){
    if(!estaVazia(p)){
        for(int i = p.topo-1; i >= p.fundo; i--){
            cout<<"mostrando item do topo: "<<p.vetNum[i]<<endl;
        }
    }else{
        cout<<"Pilha vazia, nada para mostrar"<<endl;
    }

}
int main(){
    setlocale(LC_ALL,"Portuguese");
    Pilha pilha;

    criarPilha(pilha);

    empilhar(pilha,11);
    empilhar(pilha,12);
    empilhar(pilha,13);
    empilhar(pilha,14);
    empilhar(pilha,15);
    empilhar(pilha,16);
    empilhar(pilha,17);
    empilhar(pilha,18);
    empilhar(pilha,19);
    empilhar(pilha,20);
    empilhar(pilha,21);//dará erro, pois a pilha estará cheia
    cout<<endl;
    mostrar(pilha);
    cout<<endl;
    desempilhar(pilha);
    desempilhar(pilha);
    desempilhar(pilha);
    desempilhar(pilha);
    desempilhar(pilha);
    desempilhar(pilha);
    mostrar(pilha);
    cout<<endl;
    desempilhar(pilha);
    desempilhar(pilha);
    desempilhar(pilha);
    desempilhar(pilha);
    desempilhar(pilha);//dará erro, pois a pilha estará vazia
    mostrar(pilha);


    return 0;
}
