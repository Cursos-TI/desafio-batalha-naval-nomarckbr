#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para imprimir o tabuleiro na tela
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("A B C D E F G H I J\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Posicionar um navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int colunaInicial) {
    // Verifica se o navio cabe no tabuleiro
    if (colunaInicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0; // Erro: fora dos limites
    }

    // Verifica se há sobreposição
    for (int j = 0; j < TAMANHO_NAVIO; j++) {
        if (tabuleiro[linha][colunaInicial + j] != AGUA) {
            return 0; // Erro: sobreposição
        }
    }

    // Posiciona o navio
    for (int j = 0; j < TAMANHO_NAVIO; j++) {
        tabuleiro[linha][colunaInicial + j] = NAVIO;
    }

    return 1; // Sucesso
}

// Posicionar um navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int coluna) {
    // Verifica se o navio cabe no tabuleiro
    if (linhaInicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0; // Erro: fora dos limites
    }

    // Verifica se há sobreposição
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaInicial + i][coluna] != AGUA) {
            return 0; // Erro: sobreposição
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaInicial + i][coluna] = NAVIO;
    }

    return 1; // Sucesso
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios (pré-definidas)
    int linhaNavioH = 2, colunaNavioH = 4; // Horizontal
    int linhaNavioV = 5, colunaNavioV = 7; // Vertical

    // Posiciona os navios
    if (!posicionarNavioHorizontal(tabuleiro, linhaNavioH, colunaNavioH)) {
        printf("Erro ao posicionar navio horizontal.\n");
    }

    if (!posicionarNavioVertical(tabuleiro, linhaNavioV, colunaNavioV)) {
        printf("Erro ao posicionar navio vertical.\n");
    }

    // Exibe o tabuleiro com os navios
    exibirTabuleiro(tabuleiro);

    return 0;
}