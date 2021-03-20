#include <iostream>

using namespace std;

void mergge(int v[],int indexMaisAEsquerda,int indexMeio,int indexMaisADireita){
    //definimos 2 vetores auxiliares, cada um com metade do tamanho
    int tamanhoDdoVetAuxA = indexMeio - indexMaisAEsquerda + 1;
    int tamanhoDdoVetAuxB = indexMaisADireita - indexMeio;
    int vetAuxA[tamanhoDdoVetAuxA],vetAuxB[tamanhoDdoVetAuxB];
    //copiamos metade dos valores para cada vetor auxiliar
    for(int i = 0; i < tamanhoDdoVetAuxA; i++){
        vetAuxA[i] = v[indexMaisAEsquerda+i];
    }
    for(int i = 0; i < tamanhoDdoVetAuxB; i++){
        vetAuxB[i] = v[indexMeio + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = indexMaisAEsquerda;
    //distribuimos os 2 vetores auxiliares em v verificando qual valor é maior
    while(i < tamanhoDdoVetAuxA && j < tamanhoDdoVetAuxB){
        if(vetAuxA[i] <= vetAuxB[j]){
            v[k] = vetAuxA[i];
            i++;
        }else{
            v[k] = vetAuxB[j];
            j++;
        }
        k++;
    }
    //caso tenha sobrado valores no vetor auxiliarA então v recebe os valores
    while(i < tamanhoDdoVetAuxA){
        v[k] = vetAuxA[i];
        k++;
        i++;
    }
    //senão v recebe os valores do vetor auxiliarB
    while(j < tamanhoDdoVetAuxB){
        v[k] = vetAuxB[j];
        k++;
        j++;
    }
}

void mergeSort(int v[], int indexMaisAEsquerda, int indexMaisADireita){
    if(indexMaisAEsquerda < indexMaisADireita){//enquanto não chegarmos a um vetor tamanho 1
        //encontramos o meio, particionamos metade para cada lado e chamamos a função recursivamente
        int indexMeio = indexMaisAEsquerda + (indexMaisADireita - indexMaisAEsquerda)/2;
        mergeSort(v, indexMaisAEsquerda, indexMeio);
        mergeSort(v, indexMeio+1, indexMaisADireita);
        mergge(v, indexMaisAEsquerda, indexMeio, indexMaisADireita);
    }
}


void mostrar(int vetor[], int tamanho){
    for(int i=0; i < tamanho; i++){//mostra os valores no vetor
        cout<<vetor[i]<<endl;
    }
}

int main(){
    int vetor[] = {714, 373, 830, 124, 190, 434, 556, 157, 618, 724, 952, 863, 214, 944};
    mergeSort(vetor, 0, 13);
    mostrar(vetor, 14);
    return 0;
}
