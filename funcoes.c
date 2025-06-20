#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

void clear_terminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void exibir_velha(char velha[3][3]){
    printf("\n");
    printf("\n");
    printf("\n");
    printf(" %c | %c | %c\n", velha[0][0], velha[0][1], velha[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", velha[1][0], velha[1][1], velha[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", velha[2][0], velha[2][1], velha[2][2]);
    printf("\n");
    printf("\n");
    printf("\n");
}

void print_vitorias(int jogador, int jogador_win, int bot){
    if (bot != 1){
        printf("Jogador %d: %d vitoria\n", jogador, jogador_win);
    }else{printf("Bot: %d vitoria\n", jogador_win);}

}

char escolha_simbolo(int jogador){
    char simbolo;
    printf("Jogador %d, escolha seu simbolo usado para o jogo: ", jogador);
    scanf(" %c", &simbolo);
    return simbolo;
}

void realizar_jogada(char velha[3][3], int jogador, char simbolo) {
    int linha, coluna;

    while (1) {
        printf("Jogador %d, escolha a linha que deseja jogar (1 a 3): ", jogador);
        scanf("%d", &linha);
        printf("Jogador %d, escolha a coluna que deseja jogar (1 a 3): ", jogador);
        scanf("%d", &coluna);

        linha--;
        coluna--;

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
            printf("Jogada invalida! Casa fora da velha. Escolha outra jogada.\n");
        } else if (velha[linha][coluna] != ' ') {
            printf("Jogada invalida! Casa ocupada. Escolha outra jogada.\n");
        } else {
            velha[linha][coluna] = simbolo;
            break;
        }
    }
}


int checar_win(char velha[3][3], char simbolo){
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (velha[i][0] == simbolo && velha[i][1] == simbolo && velha[i][2] == simbolo) {
            return 1;
        }
    }

    // Verificar colunas
    for (int i = 0; i < 3; i++) {
        if (velha[0][i] == simbolo && velha[1][i] == simbolo && velha[2][i] == simbolo) {
            return 1;
        }
    }

    // Verificar diagonal principal
    if (velha[0][0] == simbolo && velha[1][1] == simbolo && velha[2][2] == simbolo) {
        return 1;
    }

    // Verificar diagonal secundária
    if (velha[0][2] == simbolo && velha[1][1] == simbolo && velha[2][0] == simbolo) {
        return 1;
    }

    // Se não houver vitória
    return 0;
    

}

int checar_empate(char velha[3][3]){
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (velha[i][j] == ' ')
                return 0;
    return 1;
}

void jogada_bot(char velha[3][3], char simbolo) {
    int linha, coluna;

    do {
        linha = rand() % 3;
        coluna = rand() % 3;
    } while (velha[linha][coluna] != ' ');

    velha[linha][coluna] = simbolo;
    printf("Bot jogou na linha %d, coluna %d\n", linha + 1, coluna + 1);
}
