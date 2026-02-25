#include <stdio.h>

/**
 * Funções Recursivas para substituir loops simples
 */

// Simula o movimento da Torre (5 casas para a Direita)
void moverTorre(int casas) {
    if (casas > 0) {
        printf("Direita\n");
        moverTorre(casas - 1); // Chamada recursiva diminuindo o contador
    }
}

// Simula o movimento da Rainha (8 casas para a Esquerda)
void moverRainha(int casas) {
    if (casas > 0) {
        printf("Esquerda\n");
        moverRainha(casas - 1);
    }
}

// Simula o movimento do Bispo recursivamente (para a composição de direção)
void moverBispoRecursivo(int casas) {
    if (casas > 0) {
        printf("Cima, Direita\n");
        moverBispoRecursivo(casas - 1);
    }
}

int main() {
    // Constantes de movimentação
    const int MOV_TORRE = 5;
    const int MOV_BISPO = 5;
    const int MOV_RAINHA = 8;

    // --- Movimentação da Torre (Recursiva) ---
    printf("Movimento da Torre:\n");
    moverTorre(MOV_TORRE);
    printf("\n");

    // --- Movimentação da Rainha (Recursiva) ---
    printf("Movimento da Rainha:\n");
    moverRainha(MOV_RAINHA);
    printf("\n");

    // --- Movimentação do Bispo (Loops Aninhados e Recursividade) ---
    // Requisito: Loop externo vertical, interno horizontal.
    printf("Movimento do Bispo (Loops Aninhados):\n");
    for (int i = 0; i < MOV_BISPO; i++) { // Vertical
        for (int j = 0; j < 1; j++) {     // Horizontal (uma execução por casa)
            printf("Cima, ");
        }
        printf("Direita\n");
    }
    printf("\n");

    // --- Movimentação do Cavalo (Loops Complexos) ---
    // Requisito: 2 casas para Cima e 1 para a Direita em "L".
    // Utilizando múltiplas variáveis e break/continue.
    printf("Movimento do Cavalo:\n");
    
    // Loop externo com múltiplas variáveis para controle
    for (int i = 0, casasCima = 2; i < 1; i++) {
        // Loop interno simulando o salto vertical
        for (int j = 0; j < 10; j++) { 
            if (j < casasCima) {
                printf("Cima\n");
                continue; // Pula para a próxima iteração até completar as casas de cima
            }
            
            printf("Direita\n");
            break; // Sai do loop após completar o movimento lateral do "L"
        }
    }

    /* 
     * Documentação Técnica:
     * 1. Recursividade: Reduz a dependência de loops locais e utiliza a pilha de chamadas.
     * 2. Bispo: O loop aninhado decompõe a diagonal em eixos X e Y.
     * 3. Cavalo: O uso de 'continue' gerencia o deslocamento vertical e 'break' finaliza a jogada.
     */

    return 0;
}
