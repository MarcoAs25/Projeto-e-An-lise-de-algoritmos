#include <iostream>
#include <clocale>

using namespace std;

const int tamanho = 10;

struct ListaArranjo{
    int vetNum[tamanho];
    int primeiro;
    int ultimo;
};

void criarLista(ListaArranjo &l){
    l.primeiro = 0;
    l.ultimo = l.primeiro;
}

bool estaVazia(ListaArranjo l){
    return l.primeiro == l.ultimo;
}

bool estaCheia(ListaArranjo l){
    return l.ultimo >= tamanho;
}

void inserir(ListaArranjo &l, int item){
    if(!estaCheia(l)){
        l.vetNum[l.ultimo] = item;
        l.ultimo++;
    }else{
        cout<<"Lista cheia :("<<endl;
    }
}

void remover(ListaArranjo &l, int index){
    if(index < l.ultimo || !estaVazia(l)){
        for(int i = index; i < l.ultimo-1; i++){
            l.vetNum[i] = l.vetNum[i+1];
        }
        l.ultimo--;
    }else{
        cout<<"Lista vazia ou posição não existente"<<endl;
    }
}

void mostrar(ListaArranjo &l){
    if(!estaVazia(l)){
        for(int i = l.primeiro; i < l.ultimo; i++){
            cout<<"item "<<i<<"= "<<l.vetNum[i]<<endl;
        }
    }else{
        cout<<"nada para mostrar, lista vazia"<<endl;
    }

}

int main(){
    setlocale(LC_ALL,"Portuguese");

    ListaArranjo lista;
    criarLista(lista);
    inserir(lista,10);
    inserir(lista,11);
    inserir(lista,12);
    inserir(lista,13);
    inserir(lista,14);
    inserir(lista,15);
    inserir(lista,16);
    inserir(lista,17);
    inserir(lista,18);
    inserir(lista,19);
    inserir(lista,20);//irá informar que a lista está cheia
    mostrar(lista);

    remover(lista,90);//irá informar que o index não existe
    remover(lista,0);
    remover(lista,1);
    remover(lista,2);
    remover(lista,3);
    remover(lista,4);
    remover(lista,5);
    remover(lista,6);
    remover(lista,7);
    remover(lista,8);
    remover(lista,9);
    remover(lista,9);//irá informar que a lista está vazia

    mostrar(lista);
    return 0;
}
