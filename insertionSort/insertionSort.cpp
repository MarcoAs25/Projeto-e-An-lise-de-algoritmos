#include <iostream>

using namespace std;

void swapp(int v[],int indexesq,int indexdir){
    int temp= v[indexesq];//troca os valores v[indexesq] <--> v[indexdir]
    v[indexesq] = v[indexdir];
    v[indexdir] = temp;
}

void insertionSort(int v[],int tamanho){
    for(int i = 1; i < tamanho; i++){//percorre todo o vetor da posição até tamanho -1
        int j = i;
        while(j > 0 && v[j] < v[j-1]){//percorre de j = i até j > 0 ou até que v[j] < v[j-1]
            swapp(v, j-1, j);//efetua a troca caso  j > 0 e v[j] < v[j-1]
            j--;//j vai uma posição para a esquerda
        }
    }
}

void mostrar(int vetor[], int tamanho){
    for(int i=0; i < tamanho; i++){//mostra os valores no vetor
        cout<<vetor[i]<<endl;
    }
}

int main(){
    int vetor[] = {714, 373, 830, 124, 190, 434, 556, 157, 618, 724, 952, 863, 214, 944, 361, 720, 795, 409, 830, 105, 105, 133, 698, 268, 664, 289, 293, 665, 430, 626, 714, 286, 559, 724, 374, 266, 624, 118, 258, 236};
    insertionSort(vetor, 40);
    mostrar(vetor, 40);

    return 0;
}
