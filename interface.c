#include <stdio.h>
#include "funcoes.h"

int menu_inicio(){
    int escolha;

    printf ("JOGO DA VELHA\n");
    printf ("\n");
    printf ("\n");
    ("Pressione o numero da opcao que deseja:\n");
    printf ("[1] Jogador x Jogador\n");
    printf ("[2] Jogador x Bot\n");
    printf ("[3] Sair\n");
    scanf("%d", &escolha);
    clear_terminal();

    return escolha;
}

void jogo_pvp(){
    int jogar_de_novo = 1; int jogador1 = 1; int jogador2 = 2; int jogador1_win = 0; int jogador2_win = 0;

    while(jogar_de_novo == 1){
        clear_terminal();
        int vitoria = 0;
        char simbolo_j1; char simbolo_j2;

        char velha[3][3] = { 
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '} };

            simbolo_j1 = escolha_simbolo(jogador1);

            do {
                simbolo_j2 = escolha_simbolo(jogador2);
                    if (simbolo_j2 == simbolo_j1) {
                    printf("Símbolo já escolhido pelo Jogador 1. Escolha outro.\n");
                    }
            } while (simbolo_j2 == simbolo_j1);


            int jogador_atual = jogador1;
            char simbolo_atual = simbolo_j1;

            while (vitoria == 0) {
                clear_terminal();
                print_vitorias(jogador1, jogador1_win, 0);
                print_vitorias(jogador2, jogador2_win, 0);
                exibir_velha(velha);

                realizar_jogada(velha, jogador_atual, simbolo_atual);

                if (checar_win(velha, simbolo_atual)) {
                    clear_terminal();
                    print_vitorias(jogador1, jogador1_win, 0);
                    print_vitorias(jogador2, jogador2_win, 0);
                    exibir_velha(velha);
                    printf("Jogador %d venceu!\n", jogador_atual);
                    if (jogador_atual == jogador1) {
                        jogador1_win++;
                    } else {
                        jogador2_win++;
                    }
                    vitoria = 1;
                    break;
                }

                if (checar_empate(velha)) {
                    clear_terminal();
                    print_vitorias(jogador1, jogador1_win, 0);
                    print_vitorias(jogador2, jogador2_win, 0);
                    exibir_velha(velha);
                    printf("Deu velha, Empate! \n");
                break;
                }

                // Alterna jogador
                if (jogador_atual == jogador1) {
                    jogador_atual = jogador2;
                    simbolo_atual = simbolo_j2;
                } else {
                    jogador_atual = jogador1;
                    simbolo_atual = simbolo_j1;
                }
            }

            printf("Jogar de novo Jogador x Jogador:\n");
            printf("[1] Sim\n");
            printf("[2] Nao\n");
            scanf("%d", &jogar_de_novo);
    }
    
}


void jogo_pve() {
    int jogar_de_novo = 1; int jogador = 1; int bot = 2; int jogador_win = 0; int bot_win = 0;

    while (jogar_de_novo == 1) {
        clear_terminal();
        int vitoria = 0;
        char simbolo_bot = 'O'; char simbolo_jogador;

        char velha[3][3] = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
        };

        printf("Aviso: O Bot jogara com o simbolo '%c'\n", simbolo_bot);
        simbolo_jogador = escolha_simbolo(jogador);

        int jogador_atual = jogador;
        char simbolo_atual = simbolo_jogador;

        while (vitoria == 0) {
            clear_terminal();
            print_vitorias(jogador, jogador_win, 0);
            print_vitorias(bot, bot_win, 1);
            exibir_velha(velha);

            if (jogador_atual == jogador) {
                realizar_jogada(velha, jogador_atual, simbolo_atual);
            } else {
                jogada_bot(velha, simbolo_atual);
            }

            if (checar_win(velha, simbolo_atual)) {
                clear_terminal();
                print_vitorias(jogador, jogador_win, 0);
                print_vitorias(bot, bot_win, 1);
                exibir_velha(velha);
                if (jogador_atual == jogador) {
                    printf("Parabens! Voce venceu!\n");
                    jogador_win++;
                } else {
                    printf("Bot venceu!\n");
                    bot_win++;
                }
                vitoria = 1;
                break;
            }

            if (checar_empate(velha)) {
                clear_terminal();
                print_vitorias(jogador, jogador_win, 0);
                print_vitorias(bot, bot_win, 1);
                exibir_velha(velha);
                printf("Deu velha, Empate!\n");
                break;
            }

            // Alterna jogador
            if (jogador_atual == jogador) {
                jogador_atual = bot;
                simbolo_atual = simbolo_bot;
            } else {
                jogador_atual = jogador;
                simbolo_atual = simbolo_jogador;
            }
        }
        printf("Jogar de novo Jogador x Bot:\n");
            printf("[1] Sim\n");
            printf("[2] Nao\n");
            scanf("%d", &jogar_de_novo);
    }
}

