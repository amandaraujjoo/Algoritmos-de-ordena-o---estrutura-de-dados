//7.Faça um programa que receba valores aleatórios e diferentes em um vetor de inteiros de
// 6 posições e implemente o shell sort em uma função para ordenar este vetor.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 6

// Função para gerar valores aleatórios e diferentes

void gerarValoresAleatorios(int vetor[], int tamanho) {
    int i, j, valor;
    for (i = 0; i < tamanho; i++) {
        do {
            valor = rand() % 100; // gera numeros aleatorios e diferentes ( de 0 a 99)
            for (j = 0; j < i; j++) {
                if (vetor[j] == valor) { // se o numero for repetido, sai do loop
                    break;
                }
            }
        } while (j != i); // garante que o numero seja unico
        vetor[i] = valor; //adiciona o valor ao vetor
    }
}

// Função Shell Sort

void shell_sort(int vetor[], int tamanho) {
    int gap, i, j, temp;

    // Inicializa o gap (intervalo de separação) com a metade do tamanho do vetor
    for (gap = tamanho / 2; gap > 0; gap /= 2) {
        // O laço percorre o vetor de gap em gap
        for (i = gap; i < tamanho; i++) {
            // Armazena o valor atual em uma variável temporária
            temp = vetor[i];
            
            // Desloca os elementos maiores para a direita, criando espaço para o valor armazenado
            for (j = i; j >= gap && vetor[j - gap] > temp; j -= gap) {
                vetor[j] = vetor[j - gap]; // Move o elemento para frente
            }
            
            // Coloca o valor temporário na posição correta
            vetor[j] = temp;
        }
    }
}

// Função para imprimir o vetor


void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

//funcao principal main
int main() {
    int vetor[TAMANHO];
    
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));
    
    // Gera valores aleatórios e únicos
    gerarValoresAleatorios(vetor, TAMANHO);
    
    printf("Vetor original: ");   // exibe o a mensagem e o vetor original (não ordenado)
    imprimirVetor(vetor, TAMANHO);
    
    shell_sort(vetor, TAMANHO); // ordena o vetor com o Shell Sort
    
    printf("Vetor ordenado: "); // exibe o a mensagem e o vetor ordenado (ordenado)
    imprimirVetor(vetor, TAMANHO);
    
    return 0;
}