# 🕹️ Jogo da Velha em C

## 📜 Descrição
Este projeto é um **Jogo da Velha (Tic-Tac-Toe)** desenvolvido em linguagem **C**, executado no terminal.

Foi realizado como **projeto de estudo**, desenvolvido por um aluno da **Universidade Federal de São Paulo (UNIFESP)**, no contexto das aulas de **Lógica de Programação**.

O objetivo principal é a aplicação prática dos conceitos aprendidos na disciplina, incluindo algoritmos, estruturas de controle, manipulação de matrizes e modularização de código em C.

---

## 🚀 Funcionalidades
- Menu interativo com seleção de modo de jogo:
  - 🎮 **Jogador vs Jogador (PvP)**
  - 🤖 **Jogador vs Bot (PvE)**
- Sistema de placar de vitórias entre as partidas.
- Validação de jogadas (casa ocupada, jogada fora do tabuleiro).
- Checagem automática de vitória, derrota e empate.
- Bot que realiza jogadas aleatórias em posições livres.
- Opção de reiniciar a partida ou retornar ao menu inicial.
- Limpeza do terminal a cada rodada para melhor visualização.

---

## 📁 Organização dos Arquivos
```plaintext
├── main.c          → Função principal e controle do fluxo geral
├── interface.c     → Gerenciamento dos modos de jogo (PvP e PvE) e menus
├── interface.h     → Protótipos das funções da interface
├── funcoes.c       → Funções auxiliares e regras do jogo (jogada, vitória, empate, bot)
├── funcoes.h       → Protótipos das funções auxiliares
├── README.md       → Documentação do projeto
```
---

## 🛠️ Conceitos e Tecnologias Aplicadas

### 📚 Conteúdos abordados na disciplina de Lógica de Programação (UNIFESP)
- Manipulação de matrizes bidimensionais.
- Estruturas de controle de fluxo (`if`, `while`, `do while`).
- Declaração e chamada de funções.
- Passagem de parâmetros por valor e por referência.
- Validação de entrada de dados no terminal.
- Algoritmos de verificação (checagem de vitória nas linhas, colunas e diagonais).
- Uso de números aleatórios com `rand()` e `srand()`.

### 🧠 Boas práticas aplicadas
- Modularização do código (separação em múltiplos arquivos `.c` e `.h`).
- Organização e clareza no código.
- Separação de responsabilidades:
  - `interface.c` → fluxo dos modos de jogo.
  - `funcoes.c` → regras do jogo e funções auxiliares.
  - `main.c` → ponto de entrada do programa e menu principal.

---

## ✅ Como Compilar
Usando o compilador `gcc`, execute:

```bash
gcc main.c interface.c funcoes.c -o jogo_da_velha
./jogo_da_velha
```
