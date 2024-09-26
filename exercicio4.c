// 4.Faça um programa que receba valores aleatórios e diferentes em um vetor de inteiros de 
// 6 posições e implemente o merge sort em uma função para ordenar este vetor.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 6

// funcao para gerar valores aleatorios 


void gerarValoresAleatorios(int vetor[], int tamanho) {
    int i, j, valor;
    for (i = 0; i < tamanho; i++) { // loop que preenche as posicoes 
        do {
            valor = rand() % 100;
            for (j = 0; j < i; j++) { // verifica se o valor gerado ja existe no vetor
                if (vetor[j] == valor) { // se o valor ja existir, sai do loop
                    break;
                }
            }
        } while (j != i); // repete enquanto o valor gerado já existir no vetor
        vetor[i] = valor; // atribui o valor ao vetor
    }
}

// função para mesclar dois subarrays
void merge(int vetor[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1; //Tamaho do primeiro vetor auxiliar
    int n2 = direita - meio;      //Tamaho do segundo vetor auxiliar


    int vetorE[n1], vetorD[n2]; // arrays temporários
 
    for (i = 0; i < n1; i++)
        vetorE[i] = vetor[esquerda + i];    //passa os elementos do vetor principal para o primeiro vetor(Esquerda)


    for (j = 0; j < n2; j++)
        vetorD[j] = vetor[meio + 1 + j];  //passa os elementos do vetor principal para o segundo vetor(Direita)

    
    i = 0; j = 0; k = esquerda;  // Mescla os arrays temporários de volta no vetor original

    while (i < n1 && j < n2) {
        if (vetorE[i] <= vetorD[j]) { //Caso o valor na esquerda seja menor
            vetor[k] = vetorE[i];  //Passa para o meu vetor principal o valor menor
            i++; //Incrementa o auxiliar para passar a análise para os próximos valores do vetor auxiliar
        } else {
            vetor[k] = vetorD[j];  //Passa para o meu vetor principal o valor menor
            j++; //Incrementa o auxiliar para passar a análise para os próximos valores do vetor auxiliar
        }
        k++;  //Aumenta o índice de posicionamento do vetor
    }

    while (i < n1) {
        vetor[k] = vetorE[i];
        i++;
        k++;
    }//Se faltarem alguns elemntos do array ESQUERDO passa eles para o array principal

    
    while (j < n2) {
        vetor[k] = vetorD[j];
        j++;
        k++; //Se faltarem alguns elemntos do array DIREITO passa eles para o array principal
    }
}

// Função Merge Sort
void merge_sort(int vetor[], int esquerda, int direita) {
    if (esquerda < direita) {

         //Encontra o meio
        int meio = esquerda + (direita - esquerda) / 2;

        // Ordena a primeira e segunda metades
        merge_sort(vetor, esquerda, meio); //Da metade para trás
        merge_sort(vetor, meio + 1, direita);  //Da metade para frente

        // Mescla as duas metades
        merge(vetor, esquerda, meio, direita);
    }
}

void imprimirVetor(int vetor[], int tamanho) {  // funcao para imprimir o vetor 
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[TAMANHO];
    
    srand(time(NULL));
    gerarValoresAleatorios(vetor, TAMANHO); // chama a funçao de gerar valores
    
    printf("Vetor original: ");  // printa oo vetor original
    imprimirVetor(vetor, TAMANHO);
    
    merge_sort(vetor, 0, TAMANHO - 1); // Ordena com Merge Sort
    
    printf("Vetor ordenado: "); // printa o vetor ordenado 
    imprimirVetor(vetor, TAMANHO); 
    
    return 0;
}