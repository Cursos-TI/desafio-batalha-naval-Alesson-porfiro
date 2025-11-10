#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// NÍVEL NOVATO — Posicionando Navios no Tabuleiro
// Desenvolvido por Alesson

int main() {
    // 1️⃣ Declaração do tabuleiro (matriz 10x10)
    int tabuleiro[10][10];

    // 2️⃣ Inicializa todas as posições com 0 (representando água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 3️⃣ Declaração dos navios (cada um ocupa 3 posições)
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    // 4️⃣ Coordenadas iniciais definidas diretamente no código
    int linhaHorizontal = 2, colunaHorizontal = 4; // navio horizontal inicia em (2,4)
    int linhaVertical = 5, colunaVertical = 7;     // navio vertical inicia em (5,7)

    // 5️⃣ Posicionamento do navio horizontal (da esquerda para a direita)
    for (int j = 0; j < 3; j++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + j] = navioHorizontal[j];
        printf("Navio horizontal posicionado em (%d, %d)\n", linhaHorizontal, colunaHorizontal + j);
    }

    // 6️⃣ Posicionamento do navio vertical (de cima para baixo)
    for (int i = 0; i < 3; i++) {
        // Verifica se a posição já está ocupada
        if (tabuleiro[linhaVertical + i][colunaVertical] == 3) {
            printf("⚠️  Erro: sobreposição detectada na posição (%d, %d)\n", linhaVertical + i, colunaVertical);
            return 1; // Encerra o programa
        }
        tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
        printf("Navio vertical posicionado em (%d, %d)\n", linhaVertical + i, colunaVertical);
    }

    // 7️⃣ Exibe o tabuleiro completo
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
