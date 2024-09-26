//EXERCICIO 1.Faça um programa que receba valores aleatórios e diferentes em um vetor de inteiros de
 //6 posições e implemente o bubble sort em uma função para ordenar este vetor.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 6 // definindo o tamanho do vetor 6

// função para gerar valores aleatórios e diferentes


void gerarValoresAleatorios(int vetor[], int tamanho) { // declara a funcao que recebe 2 parametros
    int i, j, valor;
    for (i = 0; i < tamanho; i++) {
        do {
            valor = rand() % 100; // gera um número aleatório entre 0 e 99 e verifica se o valor ja foi gerado
           //  anteriormente
            for (j = 0; j < i; j++) {
                if (vetor[j] == valor) { // condiçaõ if caso o valor ja tenha sido gerado
                    break;
                }
            }
        } while (j != i); // repete o processo enquanto o valor existir
        vetor[i] = valor; // atribui o valor único ao vetor
    }
}



// função Bubble Sort para ordenar o vetor


void bubble_sort(int vetor[], int tamanho) {// declara a funcao que recebe 2 parametros
    int i, j, aux;

    for (i = 0; i < tamanho - 1; i++) {
        // o laço interno realiza a comparação de elementos 
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) { // condiçaõ caso  o valor da posição atual for maior que o próximo, 
                // se verdade, troca os dois valores
                aux = vetor[j]; 
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}



// função para imprimir os elementos do vetor


void imprimirVetor(int vetor[], int tamanho) { // declara a funcao que recebe 2 parametros
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]); // exibe o valor 
    }
    printf("\n"); // pula para a próxima linha
}


// funcao principal main



int main(){

    int vetor[TAMANHO]; // declara um array de inteiroscom um tamanho definido.
    
    srand(time(NULL)); // inicializa o gerador de números aleatórios com base no tempo atual 
    //para garantir valores diferentes em cada execução.
    
    gerarValoresAleatorios (vetor, TAMANHO); // chama a função que preenche o array 'vetor' 


    printf("Vetor original: "); // exibe a mensagem "Vetor original:" 
    imprimirVetor(vetor, TAMANHO); 

    bubble_sort(vetor, TAMANHO); 
    // utiliza-se o bubble sort para charmar a funçaõ 

    printf("Vetor ordenado: ");  // exibe a mensagem "Vetor ordenado"
    imprimirVetor(vetor, TAMANHO); 
    
    return 0; 
}
