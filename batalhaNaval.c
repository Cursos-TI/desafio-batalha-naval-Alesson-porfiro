#include <stdio.h>
#include <stdlib.h> // Necessário para a função abs()

// Define constantes para facilitar a manutenção
#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5 // Usaremos 5x5 como sugerido

// Símbolos para o tabuleiro
#define AGUA 0
#define NAVIO 3
#define EFEITO 5

void aplicarHabilidade(
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
    int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], 
    int origemLinha, 
    int origemColuna
) {
    int raio = TAMANHO_HABILIDADE / 2; 

    printf("...Aplicando habilidade em (%d, %d)...\n", origemLinha, origemColuna);

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int L = origemLinha + (i - raio);
                int C = origemColuna + (j - raio);
                if (L >= 0 && L < TAMANHO_TABULEIRO && C >= 0 && C < TAMANHO_TABULEIRO) {
                    tabuleiro[L][C] = EFEITO;
                }
            }
        }
    }
}
// -----------------------------------------------------------------


int main() {
    // 1️⃣ Declaração do tabuleiro (10x10)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // 2️⃣ Inicializa todas as posições com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    int tamanho = 3;
    int linhaH = 2, colunaH = 4;
    int linhaV = 5, colunaV = 7;
    int linhaD1 = 0, colunaD1 = 0;
    int linhaD2 = 0, colunaD2 = 9;
    #define LIVRE(i, j) (tabuleiro[i][j] == 0)
    for (int j = 0; j < tamanho; j++) { tabuleiro[linhaH][colunaH + j] = NAVIO; }
    for (int i = 0; i < tamanho; i++) { tabuleiro[linhaV + i][colunaV] = NAVIO; }
    for (int i = 0; i < tamanho; i++) { tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO; }
    for (int i = 0; i < tamanho; i++) { tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO; }
    // --- Fim da lógica de navios ---


    
    int habilidadeCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    int raio = TAMANHO_HABILIDADE / 2; 

    printf("\nGerando templates de habilidades 5x5 (1=afeta, 0=não afeta)...\n");

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Cone
            habilidadeCone[i][j] = (i >= raio && abs(j - raio) <= (i - raio)) ? 1 : 0;
            // Cruz
            habilidadeCruz[i][j] = (i == raio || j == raio) ? 1 : 0;
            // Octaedro (Losango)
            habilidadeOctaedro[i][j] = (abs(i - raio) + abs(j - raio) <= raio) ? 1 : 0;
        }
    }

    printf("Template 'Cone':\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        printf("  ");
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) { printf("%d ", habilidadeCone[i][j]); }
        printf("\n");
    }
    printf("Template 'Cruz':\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        printf("  ");
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) { printf("%d ", habilidadeCruz[i][j]); }
        printf("\n");
    }
    printf("Template 'Octaedro' (Losango):\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        printf("  ");
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) { printf("%d ", habilidadeOctaedro[i][j]); }
        printf("\n");
    }


    // 11. Integrar TODAS as Habilidades ao Tabuleiro
    
    
    // Octaedro no local original (5, 4)
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, 5, 4);
    
    // Cone no canto inferior direito (7, 7)
    aplicarHabilidade(tabuleiro, habilidadeCone, 7, 7);
    
    // Cruz no navio diagonal superior esquerdo (2, 2)
    aplicarHabilidade(tabuleiro, habilidadeCruz, 2, 2);
    

    // 12. 🚢 Exibir o Tabuleiro com Habilidade
    
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n");
    printf("~ : Água | N : Navio | X : Área de Efeito\n\n");

    printf("  ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) { printf("%d ", j); }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); 
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            switch (tabuleiro[i][j]) {
                case AGUA:   printf("0 "); break;
                case NAVIO:  printf("3 "); break;
                case EFEITO: printf("5 "); break;
                default:     printf("? ");
            }
        }
        printf("\n");
    }

    return 0;
}