// EXERCICIO 3.Faça um programa que receba valores aleatórios e diferentes em um vetor de inteiros de 
 // 6 posições e implemente o insert sort em uma função para ordenar este vetor

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 6

// função para gerar valores aleatórios e diferentes


void gerarValoresAleatorios(int vetor[], int tamanho) {
    int i, j, valor;
    for (i = 0; i < tamanho; i++) {
        do {
            valor = rand() % 100;// gera um número aleatório entre 0 e 99
            // verifica se o valor ja foi gerado anterioromente e esta presente no vetor
            for (j = 0; j < i; j++) {
                if (vetor[j] == valor) { // se o valor for encontrado no vetor, sai do loop
                    break;
                }
            }
        } while (j != i); // repete o processo enquanto o valor gerado já existir no vetor
        vetor[i] = valor; // atribui o valor ao vetor
    }
}


void insertion_sort(int vetor[], int tamanho) {
    int i, atual, j;

    // laço externo percorre o vetor
    for (i = 1; i < tamanho; i++) {
        atual = vetor[i]; // valor atual a ser inserido 
        j = i - 1;//elemento anterior ao analisado

        
        while (j >= 0 && vetor[j] > atual) {// analisa os  anteriores e desloca os elementos maiores para a direita

        //posiciona os elementos uma posição para frente
        vetor[j + 1] = vetor[j];

            //faz o j andar para trás
            j--;
        }
        vetor[j + 1] = atual; // Insere o valor atual (menor número) na posição correta
    }
}
 // funcao para imprimir vetor 


void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}




int main() {

    int vetor[TAMANHO]; // declara o vetor com o tamanho ja definido 
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com base no tempo atual

    gerarValoresAleatorios (vetor, TAMANHO); // chama a função que gera valores aleatórios 
    
     // exibe o vetor original (não ordenado)
    printf("Vetor original: ");
    imprimirVetor(vetor, TAMANHO);

    insertion_sort(vetor, TAMANHO); // Ordena com Insertion Sort
    
     // exibe o vetor já ordenado
    printf("Vetor ordenado: "); 
    imprimirVetor(vetor, TAMANHO);
    
    return 0;
}