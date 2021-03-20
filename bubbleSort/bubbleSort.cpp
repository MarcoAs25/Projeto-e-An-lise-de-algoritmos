#include <iostream>

using namespace std;


void swapp(int v[],int indexesq,int indexdir){
    int temp= v[indexesq];//troca os valores v[indexesq] <--> v[indexdir]
    v[indexesq] = v[indexdir];
    v[indexdir] = temp;
}

void bubbleSort(int v[], int tamanho){
    for(int j = 0; j < (tamanho - 1); j++){// executa tamanho-1 vezes a ordenação por bolha
        bool trocou = false;
        for(int i = 0; i < (tamanho-1-j); i++){//executa de 0 até o último valor não ordenado
            if(v[i] > v[i + 1]){//verifica se o valor do vizinho a direita é maior
                swapp(v, i, i + 1);//efetua o swapp
                trocou = true;//caso tenha trocado, trocou = true;
            }
        }
        if(!trocou){//caso não tenha trocado
        //isso quer dizer que percorremos todo o vetor e os valores estão ordenados
            break;//então paramos a execução
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
    bubbleSort(vetor,40);
    mostrar(vetor, 40);
    return 0;
}
