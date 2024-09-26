// EXERCICIO 2.Faça um programa que receba valores aleatórios e diferentes em um vetor de inteiros de
 // 6 posições e implemente o select sort em uma função para ordenar este vetor.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 6 // definindo o tamanho como 6

// função para gerar valores aleatórios e diferentes
void gerarValoresAleatorios(int vetor[], int tamanho) {
    int i, j, valor;
    for (i = 0; i < tamanho; i++) {
        do {
            valor = rand() % 100;
            for (j = 0; j < i; j++) {
                if (vetor[j] == valor) {
                    break;
                }
            }
        } while (j != i);
        vetor[i] = valor;
    }
}



// função Select Sort


void selection_sort(int vetor[], int tamanho) {
    int i, j, posicaoMenorValor, aux;
    // laço que percorre o vetor
    for (i = 0; i < tamanho - 1; i++) {
        posicaoMenorValor = i; // assume que o menor valor está na posição i

       
        for (j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[posicaoMenorValor]) { // verifica se  ja existeum menor valor.
                posicaoMenorValor = j; // atualiza a posicaoMenorValor
            }
        }
       
        aux = vetor[i];  // troca o menor valor encontrado com o valor da posição i 
        vetor[i] = vetor[posicaoMenorValor];
        vetor[posicaoMenorValor] = aux;
    }
}

// função para imprimir o vetor

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[TAMANHO];
    
    srand(time(NULL)); // inicializa o gerador de números aleatórios
    gerarValoresAleatorios(vetor, TAMANHO); // gera os valores
    
    printf("Vetor original: ");
    imprimirVetor(vetor, TAMANHO);
    
    selection_sort(vetor, TAMANHO); // ordena com Select Sort
    
    printf("Vetor ordenado: "); // printa o vetor ordenado após a mensagem "Vetor ordenado: "
    imprimirVetor(vetor, TAMANHO);
    
    return 0;
}
