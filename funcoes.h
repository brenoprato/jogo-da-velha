#ifndef FUNCOES_H
#define FUNCOES_H

void clear_terminal();
void exibir_velha(char velha[3][3]);
void print_vitorias(int jogador, int jogador_win, int bot);
char escolha_simbolo(int jogador);
void realizar_jogada(char velha[3][3], int jogador, char simbolo);
int checar_win(char velha[3][3], char simbolo);
int checar_empate(char velha[3][3]);
void jogada_bot(char velha[3][3], char simbolo);

#endif