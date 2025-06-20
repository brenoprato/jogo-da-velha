#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "interface.h"
#include "funcoes.h"

int main() {
    int modo_de_jogo;
    srand(time(NULL));
    
    do {
        clear_terminal();
        modo_de_jogo = menu_inicio();

        if (modo_de_jogo == 1) {
            jogo_pvp();
        } else if (modo_de_jogo == 2) {
            jogo_pve();
        } else if (modo_de_jogo == 3) {
            printf("Jogo encerrado!\n");
        }

    } while (modo_de_jogo != 3);

    return 0;
}
