#include <iostream>

using namespace std;

void swapp(int v[],int indexesq,int indexdir){
    int temp= v[indexesq];//troca os valores v[indexesq] <--> v[indexdir]
    v[indexesq] = v[indexdir];
    v[indexdir] = temp;
}

void selectionSort(int v[], int tamanho){
    for(int j = 0; j < tamanho; j++){//executa tamanho-1 vezes a ordenação por seleção
        int posPri = j;
        for(int i = posPri + 1; i < tamanho; i++){//percorre o vetor de j+1 até tamanho-1
            if(v[posPri] > v[i]){                 //seleciona o menor número no intervalo
                posPri = i;
            }
        }
        swapp(v,j,posPri);//efetua a troca ao encontrar o menor número no intervalo
    }
}

void mostrar(int vetor[], int tamanho){
    for(int i=0; i < tamanho; i++){//mostra os valores no vetor
        cout<<vetor[i]<<endl;
    }
}

int main(){
    int vetor[] = {714, 373, 830, 124, 190, 434, 556, 157, 618, 724, 952, 863, 214, 944, 361, 720, 795, 409, 830, 105, 105, 133, 698, 268, 664, 289, 293, 665, 430, 626, 714, 286, 559, 724, 374, 266, 624, 118, 258, 236};
    selectionSort(vetor,40);
    mostrar(vetor, 40);

    return 0;
}
