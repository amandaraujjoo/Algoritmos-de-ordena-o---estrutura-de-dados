//5.Faça um programa que receba valores aleatórios e diferentes em um vetor de inteiros de 
// 6 posições e implemente o quick sort em uma função para ordenar este vetor.

//quick
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 6

//funcao que gera valores aleatorios 
void gerarValoresAleatorios(int vetor[], int tamanho) {
    int i, j, valor;
    for (i = 0; i < tamanho; i++) { // loop que preenche as posicoes 
        do {
            valor = rand() % 100;
            for (j = 0; j < i; j++) { // verifica se o valor ja existe no vetor
                if (vetor[j] == valor) {  // se ja existir, sai do loop 
                    break;
                }
            }
        } while (j != i); // repete enquanto o valor gerado já existir no vetor
        vetor[i] = valor; // atribui o valor ao vetor
    }
}

// Função para particionar o vetor



int particao (int vetor[], int baixo, int alto) {

    int pivo = vetor[alto]; // Pivô é o último elemento
    int i = (baixo - 1); // Índice do menor elemento

    for (int j = baixo; j < alto; j++) {

        // Se o elemento atual é menor ou igual ao pivô
        if (vetor[j] <= pivo) {
            i++;


            // Troca os elementos
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }



    int temp = vetor[i + 1];     // Troca o pivô com o elemento que o separa
    vetor[i + 1] = vetor[alto];
    vetor[alto] = temp;

    return (i + 1); // Retorna a posição do pivô
}

// declarando a funcao quick short  que recebe 3 parametros 

void quick_sort(int vetor[], int baixo, int alto) {
    if (baixo < alto) {
        // Particiona o vetor e obtém a posição do pivô
        int pi = particao(vetor, baixo, alto);

        // Ordena recursivamente as subpartes
        quick_sort(vetor, baixo, pi - 1);
        quick_sort(vetor, pi + 1, alto);
    }
}


// funcao criada para imprimir o valor do vetor

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função principal main

int main() {
    int vetor[TAMANHO]; 
    
    srand(time(NULL));  // inicializa o gerador de números aleatórios com base no tempo atual
    
    gerarValoresAleatorios(vetor, TAMANHO);  // preenche o vetor com  os valores 

    printf("Vetor original: ");  // exibe a mensagem "Vetor original:" e o-imprime
    imprimirVetor(vetor, TAMANHO); 
    
    quick_sort(vetor, 0, TAMANHO - 1);  // chama a função Quick Sort para ordenar o vetor
    
    printf("Vetor ordenado: ");  // exibe a mensagem "Vetor ordenado:" e o-imprime
    imprimirVetor(vetor, TAMANHO);  
    
    return 0;  
}
