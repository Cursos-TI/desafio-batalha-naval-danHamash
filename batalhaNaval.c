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
    // Navio horizontal começa na linha 2, coluna 3 (ocupando as posições 2,D 2,E e 2,F)
    posicionarNavio(tabuleiro, 2, 3,  'H'); 

    // Navio vertical começa na linha 7, coluna 8 (ocupando as posições 7,I, 8,I e 9,I)
    posicionarNavio(tabuleiro, 7, 8,  'V'); 

    // Exibe o tabuleiro formatado após o posicionamento dos navios
    exibirTabuleiro(tabuleiro);
    
    return 0;
}

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

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

  
