// 6.Faça um programa que receba valores aleatórios e diferentes em um vetor de inteiros de 
// 6 posições e implemente o heap sort em uma função para ordenar este vetor.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 6

// Função para gerar valores aleatórios e diferentes


void gerarValoresAleatorios(int vetor[], int tamanho) {
    int i, j, valor;
    for (i = 0; i < tamanho; i++) {
        do {
            valor = rand() % 100;  // gera um número aleatório entre 0 e 99
            for (j = 0; j < i; j++) {
                if (vetor[j] == valor) { // se o valor gerado ja existir, sai do loop
                    break;
                }
            }
        } while (j != i);  // garante que o número gerado seja único
        vetor[i] = valor;  // adiciona o valor ao vetor
    }
}

// Função que "constrói" um heap maximizador a partir de um vetor


void heapify(int vetor[], int n, int i) {
    int maior = i; // Inicializa a raiz como o maior valor
    int esquerda = 2 * i + 1; // Índice do filho à esquerda: 2 * i + 1
    int direita = 2 * i + 2;  // Índice do filho à direita: 2 * i + 2

    // Se o filho da esquerda for maior que a raiz
    if (esquerda < n && vetor[esquerda] > vetor[maior])
        maior = esquerda;  // Atualiza a posição do maior valor

    // Se o filho da direita for maior que o maior valor até agora
    if (direita < n && vetor[direita] > vetor[maior])
        maior = direita;  // Atualiza a posição do maior valor

    // Se o maior valor não é a raiz
    if (maior != i) {
        // Troca o valor da raiz com o maior
        int temp = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = temp;

        // Chama recursivamente o heapify na subárvore afetada

        heapify(vetor, n, maior);
    }
}

// Função Heap Sort


void heap_sort(int vetor[], int n) {
    // Passo 1: Construir o heap maximizador (organiza o vetor como uma árvore binária)
    // Começa a partir do último nó não-folha (n / 2 - 1) e vai até a raiz (índice 0)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vetor, n, i); // Organiza a subárvore com raiz em i

    // Passo 2: Extrair elementos do heap, um por um
    // O laço remove a raiz (o maior elemento) e move para o final do vetor
    for (int i = n - 1; i >= 0; i--) {
        // Troca a raiz (maior elemento) com o último elemento
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;

        // Chama heapify no heap reduzido para restaurar a propriedade de heap
        heapify(vetor, i, 0); // A subárvore enraizada no índice 0 é reorganizada
    }
}

// Função para imprimir o vetor


void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);  // Exibe cada elemento do vetor
    }
    printf("\n");
}


// funcao principal main do programa

int main() {

    int vetor[TAMANHO];
    
    
    srand(time(NULL)); // inicializa o gerador de números aleatórios
    gerarValoresAleatorios(vetor, TAMANHO);    // era valores aleatórios e únicos
    
 
    printf("Vetor original: "); // printa a mensagem e o vetor original 
    imprimirVetor(vetor, TAMANHO);
    
    // Ordena o vetor com Heap Sort
    heap_sort(vetor, TAMANHO);
    

    printf("Vetor ordenado: ");    // printa a mensagem e o vetor ordenado 
    imprimirVetor(vetor, TAMANHO);
    
    return 0;
}