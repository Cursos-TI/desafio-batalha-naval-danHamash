#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Essa função percorre toda a matriz tabuleiro e preenche cada posição com agua = 0,
    // matriz de 10x10 sendo preechido com valor 0.
void inicializarTabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}
/// função que posiciona um navio no tabuleiro.
// o navio ocupa 3 casas e pode ser posicionado de forma horizontal "H" ou vertical "V".
// se a posição for valida a função preenche as posições correspondentes com o valor 3(navio).

void posicionarNavio(int tabuleiro[10][10], int linha, int coluna, char direcao) {
    // Verifica se o navio pode ser posicionado horizontalmente e dentro dos limites do tabuleiro
    if (direcao == 'H' && coluna + 3 <= 10) {
        // Preenche as posições do navio horizontalmente
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha][coluna + i] = 3;
        }
    }
    
    // Verifica se o navio pode ser posicionado verticalmente e dentro dos limites do tabuleiro 
    else if (direcao == 'V' && linha + 3 <= 10) {
        // Preenche as posições do navio verticalmente
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha + i][coluna] = 3;
        }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    }else if (direcao == 'D' && linha - 2 >= 0 && coluna + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha - i][coluna + i] = 3;
        }
    }
}
//Habilidades adicionadas
void posicionarHabilidade(int tabuleiro[10][10], int linha, int coluna, char tipo) {
    if (tipo == 'C') { // Cone
        for (int i = 0; i < 3; i++) {
            for (int j = -i; j <= i; j++) {
                int x = linha + i;
                int y = coluna + j;
                if (x >= 0 && x < 10 && y >= 0 && y < 10) {
                    tabuleiro[x][y] = 5;  // Valor 5 representa a habilidade
                }
            }
        }
    }
    else if (tipo == 'X') { // Cruz
        for (int i = -2; i <= 2; i++) {
            int x1 = linha + i;
            int y1 = coluna;
            int x2 = linha;
            int y2 = coluna + i;
            if (x1 >= 0 && x1 < 10) tabuleiro[x1][y1] = 5;
            if (y2 >= 0 && y2 < 10) tabuleiro[x2][y2] = 5;
        }
    }
    else if (tipo == 'O') { // Octaedro
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int x = linha + i;
                int y = coluna + j;
                if (x >= 0 && x < 10 && y >= 0 && y < 10) {
                    if (i == 0 || j == 0) tabuleiro[x][y] = 5;
                }
            }
        }
    }
}

// imprime o tabuleiro, formatando as colunas com letras de 'A' a 'J'.
void exibirTabuleiro(int tabuleiro[10][10]) {

    //exibe as letras de coluna na parte de cima do tabuleiro
    char letras[]= {'A','B','C','D','E','F','G','H','I','J'};
    printf("  ");
    for (int j = 0; j < 10; j++) {
        printf("%c ", letras[j]);
    }
    printf("\n");
    
    //imprime as linhas do tabuleiro com cada indice
    for (int i = 0; i < 10; i++) {
        printf("%d ", i); // imprime o indice da linha 

        // exibe os valores do tabuleiro para cada coluna
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    //cria um tabulerio 10x10
    int tabuleiro[10][10];

    // Inicializa o tabuleiro (todas as posições são preenchidas com 0, representando agua)
    inicializarTabuleiro(tabuleiro);

    // Posiciona os navios no tabuleiro de forma manual
    posicionarNavio(tabuleiro, 2, 3, 'H');  // Horizontal
    posicionarNavio(tabuleiro, 7, 8, 'V');  // Vertical
    posicionarNavio(tabuleiro, 8, 2, 'D');  // Diagonal 
    posicionarNavio(tabuleiro, 6, 2, 'D');  // Diagonal

    

    // Posicionamento das habilidades
    // posicionarHabilidade(tabuleiro, 6, 6, 'C');  // Cone
    // posicionarHabilidade(tabuleiro, 6, 6, 'X');  // Cruz
    posicionarHabilidade(tabuleiro, 6,6, 'O');  // Octaedro

    // Exibe o tabuleiro formatado após o posicionamento dos navios
    exibirTabuleiro(tabuleiro);
    
    return 0;
}

    

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

  
