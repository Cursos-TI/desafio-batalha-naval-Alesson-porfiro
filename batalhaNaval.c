#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// NÍVEL AVENTUREIRO — Tabuleiro Completo e Navios Diagonais
// Desenvolvido por Alesson

int main() {
    // 1️⃣ Declaração do tabuleiro (10x10)
    int tabuleiro[10][10];

    // 2️⃣ Inicializa todas as posições com 0 (representando água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 3️⃣ Tamanho dos navios
    int tamanho = 3;

    // 4️⃣ Coordenadas iniciais fixas (sem entrada do usuário)
    int linhaH = 2, colunaH = 4;   // navio horizontal
    int linhaV = 5, colunaV = 7;   // navio vertical
    int linhaD1 = 0, colunaD1 = 0; // navio diagonal 
    int linhaD2 = 0, colunaD2 = 9; // navio diagonal 

    // ⚙️ Função auxiliar de verificação de sobreposição (inline)
    #define LIVRE(i, j) (tabuleiro[i][j] == 0)

    // 5️⃣ Posicionamento do navio horizontal 
    for (int j = 0; j < tamanho; j++) {
        if (colunaH + j >= 10 || !LIVRE(linhaH, colunaH + j)) {
            printf("❌ Erro: posição inválida ou sobreposição no navio horizontal.\n");
            return 1;
        }
    }
    for (int j = 0; j < tamanho; j++) {
        tabuleiro[linhaH][colunaH + j] = 3;
        printf("✅ Navio horizontal posicionado em (%d, %d)\n", linhaH, colunaH + j);
    }

    // 6️⃣ Posicionamento do navio vertical 
    for (int i = 0; i < tamanho; i++) {
        if (linhaV + i >= 10 || !LIVRE(linhaV + i, colunaV)) {
            printf("❌ Erro: posição inválida ou sobreposição no navio vertical.\n");
            return 1;
        }
    }
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
        printf("✅ Navio vertical posicionado em (%d, %d)\n", linhaV + i, colunaV);
    }

    // 7️⃣ Posicionamento do navio diagonal (da esquerda superior para a direita inferior)
    for (int i = 0; i < tamanho; i++) {
        if (linhaD1 + i >= 10 || colunaD1 + i >= 10 || !LIVRE(linhaD1 + i, colunaD1 + i)) {
            printf("❌ Erro: posição inválida ou sobreposição no navio diagonal.\n");
            return 1;
        }
    }
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
        printf("✅ Navio diagonal posicionado em (%d, %d)\n", linhaD1 + i, colunaD1 + i);
    }

    // 8️⃣ Posicionamento do navio diagonal (da direita superior para a esquerda inferior)
    for (int i = 0; i < tamanho; i++) {
        if (linhaD2 + i >= 10 || colunaD2 - i < 0 || !LIVRE(linhaD2 + i, colunaD2 - i)) {
            printf("❌ Erro: posição inválida ou sobreposição no navio diagonal.\n");
            return 1;
        }
    }
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
        printf("✅ Navio diagonal posicionado em (%d, %d)\n", linhaD2 + i, colunaD2 - i);
    }

    // 9️⃣ Exibe o tabuleiro completo
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
