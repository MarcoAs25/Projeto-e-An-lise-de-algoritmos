#include <iostream>
using namespace std;
//Aluno: Marco Antônio


//Efetua a troca entre as posições do vetor
void efetuaTroca(int* valor1, int* valor2){
    int temp = *valor1;//usamos uma variavel temp para efetuar a troca de posições do valor 1 com o valor 2
    *valor1 = *valor2;
    *valor2 = temp;
}

// ordena o vetor de forma que todo lado esquerdo do pivô
// escolhido é menor que o mesmo, e todo lado direito do pivô
// se torna maior que o mesmo.

int particao(int vetorparaOrdenar[], int inicio, int fim ){
    int pivo = vetorparaOrdenar[fim];   // escolha do pivô
    int indice = (inicio-1);            // início do índice
    for(int j = inicio; j <= fim - 1; j++){ //laço de repetição para efetuar a troca de posições
        if(vetorparaOrdenar[j]<pivo){     //condição de troca
            indice++;
            efetuaTroca(&vetorparaOrdenar[indice], &vetorparaOrdenar[j]);
        }
    }
    efetuaTroca(&vetorparaOrdenar[indice + 1], &vetorparaOrdenar[fim]); //efetuando a última troca
    return (indice + 1);//retornando o índice do pivô
}
void quickSort(int vetorparaOrdenar[], int inicio, int fim){
    int pivo;
    if(inicio < fim){
       pivo = particao(vetorparaOrdenar, inicio, fim);// executa o algoritmo de "pivotamento" e retorna a posição do pivô
       quickSort(vetorparaOrdenar, inicio, pivo-1);// executa novamente a função do início ao pivô-1
       quickSort(vetorparaOrdenar, pivo + 1, fim);// executa novamente a função do pivô+1 ao fim
    }
}
void mostrar(int vetor[],int tamanho,string n){ // mostra o vetor
    cout<<n<<endl;
    cout<<"A = [";
    for(int i=0; i < tamanho; i++){
        if(i != (tamanho - 1)){
          cout<<vetor[i]<<", ";
        }else{
            cout<<vetor[i];
        }
    }
    cout<<"]"<<endl;
}
int main()
{
    int A[] = {9 , 10 , -1, 3, 6, 2, 1, -3, 1, 0, -2, 15, 8, -7, 0};
    int tamanhodoVetor = sizeof(A) / sizeof(A[0]);
    mostrar(A, tamanhodoVetor, "vetor Desordenado:");
    quickSort(A, 0, tamanhodoVetor - 1);
    mostrar(A, tamanhodoVetor, "vetor Ordenado:");
    return 0;
}
