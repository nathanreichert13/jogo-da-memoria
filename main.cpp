#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

#define LINHA 4
#define COLUNA 4

// Variáveis globais do jogo
int matrizPrincipal[LINHA][COLUNA];
int matrizGabarito[LINHA][COLUNA];
int matrizJogo[LINHA][COLUNA];
int jogadas = 0;
const int maxJogadas = 24;
int paresEncontrados = 0;
const int totalPares = (LINHA * COLUNA) / 2;

// Protótipos das funções principais
void boasVindas();
void menu();
void menuFuncionar();
void iniciarJogo();
void sobre();
void comoJogar();
void fim();
void gerarMatrizPrincipal();
void gerarMatrizGabarito();
void exibirMatrizJogo();
int lerInteiro(const string &mensagem, int min, int max);

// Interpreta a escolha do menu
void menuFuncionar()
{
    int opcaoMenu = lerInteiro("Digite a opção que deseja acessar: ", 1, 4);

    switch (opcaoMenu)
    {
    case 1:
        iniciarJogo();
        break;
    case 2:
        comoJogar();
        break;
    case 3:
        sobre();
        break;
    case 4:
        fim();
        break;
    default:
        cout << "Opção inválida. Digite novamente!" << endl;
        Sleep(1000);
        menu();
        break;
    }
}

// Exibe tela inicial com créditos
void boasVindas()
{
    system("cls");
    cout << "+----------------------------------------------+" << endl;
    cout << "|        BOAS-VINDAS AO JOGO DA MEMÓRIA!       |" << endl;
    cout << "+----------------------------------------------+" << endl;
    cout << "| Desenvolvido por:                            |" << endl;
    cout << "| Luiz Felipe de Souza                         |" << endl;
    cout << "| Matheus Pompeo Dias                          |" << endl;
    cout << "| Nathan Gustavo Padilha Reichert              |" << endl;
    cout << "+----------------------------------------------+" << endl;

    Sleep(3000); // Pausa para o usuário ler as instruções
    menu();
}

// Exibe o menu principal
void menu()
{
    system("cls");
    cout << "+----------------------------+" << endl;
    cout << "|        MENU DO JOGO        |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "| (1) Iniciar o Jogo         |" << endl;
    cout << "| (2) Como Jogar             |" << endl;
    cout << "| (3) Sobre                  |" << endl;
    cout << "| (4) Sair                   |" << endl;
    cout << "+----------------------------+" << endl
         << endl;
    menuFuncionar();
}

// Mostra informações do projeto
void sobre()
{
    system("cls");
    cout << "+------------------------------------------------------------------+" << endl;
    cout << "|                              SOBRE                               |" << endl;
    cout << "+------------------------------------------------------------------+" << endl;
    cout << "| UNIVALI - Campus Itajaí - Ciência da Computação - Turma 2025/1   |" << endl;
    cout << "| Disciplina: Algoritmos e Programação                             |" << endl;
    cout << "| Professor: Michael Douglas Alves                                 |" << endl;
    cout << "| Desenvolvedores:                                                 |" << endl;
    cout << "| Luiz Felipe de Souza (github.com/PhilipsBr567)                   |" << endl;
    cout << "| Matheus Pompeo Dias (github.com/mapompeo)                        |" << endl;
    cout << "| Nathan Gustavo Padilha Reichert (github.com/nathanreichert13)    |" << endl;
    cout << "+------------------------------------------------------------------+" << endl
         << endl;

    system("pause"); // Pausa para o usuário ler as instruções
    menu();
}

// Mostra instruções para jogar
void comoJogar()
{
    system("cls");
    cout << "+------------------------------------------------------------+" << endl;
    cout << "|                        COMO JOGAR                          |" << endl;
    cout << "+------------------------------------------------------------+" << endl;
    cout << "| Objetivo: Encontrar todos os pares de números escondidos.  |" << endl;
    cout << "| Matriz: 4x4 com 8 pares, total de 16 peças.                |" << endl;
    cout << "| O jogador vira duas peças por jogada.                      |" << endl;
    cout << "| Se forem iguais: JOGADA OK, ficam visíveis.                |" << endl;
    cout << "| Se diferentes: JOGADA NOK, peças são ocultadas novamente.  |" << endl;
    cout << "| Máximo de jogadas: 24 (3x o número de pares).              |" << endl;
    cout << "| O jogo termina ao encontrar todos os pares ou acabarem as  |" << endl;
    cout << "| jogadas.                                                   |" << endl;
    cout << "+------------------------------------------------------------+" << endl
         << endl;

    system("pause");
    menu();
}

// Encerra o jogo
void fim()
{
    system("cls");
    cout << "+----------------------------------------------------------+" << endl;
    cout << "|                       FIM DE JOGO                        |" << endl;
    cout << "+----------------------------------------------------------+" << endl;
    cout << "| Obrigado por jogar o Jogo da Memória!                    |" << endl;
    cout << "| Esperamos que tenha se divertido!                        |" << endl;
    cout << "+----------------------------------------------------------+" << endl;
    exit(0);
}

// Gera os pares embaralhados na matriz principal
void gerarMatrizPrincipal()
{
    int pares[LINHA * COLUNA];
    int k = 0;

    for (int i = 0; i < totalPares; i++)
    {
        pares[k++] = i + 1;
        pares[k++] = i + 1;
    }

    for (int i = LINHA * COLUNA - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(pares[i], pares[j]); // Swap troca os valores das variáveis sem precisar usar uma variável temporária
    }

    k = 0;
    for (int i = 0; i < LINHA; i++)
        for (int j = 0; j < COLUNA; j++)
            matrizPrincipal[i][j] = pares[k++];
}

// Exibe a matriz atual do jogador
void exibirMatrizJogo()
{
    cout << "   0 1 2 3" << endl;
    cout << "  --------" << endl;
    for (int i = 0; i < LINHA; i++)
    {
        cout << i << "| ";
        for (int j = 0; j < COLUNA; j++)
        {
            if (matrizJogo[i][j] == -1)
                cout << "* ";
            else
                cout << matrizJogo[i][j] << " ";
        }
        cout << endl;
    }
}

// Exibe qualquer matriz com coordenadas
void exibirMatrizComCoordenadas(int matriz[LINHA][COLUNA])
{
    cout << "   ";
    for (int j = 0; j < COLUNA; j++)
        cout << j << " ";
    cout << endl;
    cout << "  --------" << endl;
    for (int i = 0; i < LINHA; i++)
    {
        cout << i << "| ";
        for (int j = 0; j < COLUNA; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Aplica uma transformação aleatória na matriz
void gerarMatrizGabarito()
{
    gerarMatrizPrincipal();
    int tipo = rand() % 4;

    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            switch (tipo)
            {
            case 0: // Sem transformação
                matrizGabarito[i][j] = matrizPrincipal[i][j];
                break;
            case 1: // Transposta
                matrizGabarito[i][j] = matrizPrincipal[j][i];
                break;
            case 2: // Invertida por linha
                matrizGabarito[i][j] = matrizPrincipal[LINHA - i - 1][j];
                break;
            case 3: // Invertida por coluna
                matrizGabarito[i][j] = matrizPrincipal[i][COLUNA - j - 1];
                break;
            }
        }
    }
}

// Lê um inteiro válido dentro de um intervalo
int lerInteiro(const string &mensagem, int min, int max)
{
    int valor;
    while (true)
    {
        cout << mensagem;
        cin >> valor;
        if (cin.fail() || valor < min || valor > max) // Fail é como se fosse um system("pause"), ele verifica se a entrada é válida
        {
            cout << "Entrada inválida. Digite um número entre " << min << " e " << max << "." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else
        {
            cin.ignore(10000, '\n');
            return valor;
        }
    }
}

// Controla a execução principal do jogo
void iniciarJogo()
{
    jogadas = 0;
    paresEncontrados = 0;
    system("cls");

    gerarMatrizGabarito();

    cout << "Memorize o tabuleiro! Você tem 5 segundos..." << endl
         << endl;
    exibirMatrizComCoordenadas(matrizGabarito);
    Sleep(5000);
    system("cls");

    for (int i = 0; i < LINHA; i++)
        for (int j = 0; j < COLUNA; j++)
            matrizJogo[i][j] = -1;

    int l1, c1, l2, c2;

    while (jogadas < maxJogadas && paresEncontrados < totalPares)
    {
        system("cls");
        cout << "JOGO DA MEMÓRIA" << endl;
        cout << "-----------------" << endl;
        cout << "Jogadas restantes: " << maxJogadas - jogadas << endl;
        cout << "Pares encontrados: " << paresEncontrados << " de " << totalPares << endl;
        cout << "-----------------" << endl;

        exibirMatrizJogo();

        do
        {
            l1 = lerInteiro("\nEscolha a linha da PRIMEIRA peça (0 a 3): ", 0, LINHA - 1);
            c1 = lerInteiro("Escolha a coluna da PRIMEIRA peça (0 a 3): ", 0, COLUNA - 1);
        } while (matrizJogo[l1][c1] != -1);

        matrizJogo[l1][c1] = matrizGabarito[l1][c1];
        system("cls");
        exibirMatrizJogo();

        do
        {
            l2 = lerInteiro("\nEscolha a linha da SEGUNDA peça (0 a 3): ", 0, LINHA - 1);
            c2 = lerInteiro("Escolha a coluna da SEGUNDA peça (0 a 3): ", 0, COLUNA - 1);
        } while (matrizJogo[l2][c2] != -1 || (l1 == l2 && c1 == c2));

        matrizJogo[l2][c2] = matrizGabarito[l2][c2];
        system("cls");
        exibirMatrizJogo();
        jogadas++;

        if (matrizGabarito[l1][c1] == matrizGabarito[l2][c2])
        {
            cout << "\nJOGADA OK! Você encontrou um par!" << endl;
            paresEncontrados++;
        }
        else
        {
            cout << "\nJOGADA NÃO OK! As peças são diferentes." << endl;
            matrizJogo[l1][c1] = -1;
            matrizJogo[l2][c2] = -1;
        }
        Sleep(2000);
    }

    system("cls");
    if (paresEncontrados == totalPares)
    {
        cout << "+------------------------------------------+" << endl;
        cout << "|      PARABÉNS! VOCÊ VENCEU O JOGO!       |" << endl;
        cout << "|   Você encontrou todos os pares em " << jogadas << " jogadas! |" << endl;
        cout << "+------------------------------------------+" << endl;
    }
    else
    {
        cout << "+--------------------------------------------+" << endl;
        cout << "|               FIM DE JOGO!                 |" << endl;
        cout << "| Você não encontrou todos os pares a tempo. |" << endl;
        cout << "+--------------------------------------------+" << endl;

        cout << "\nEsta era a matriz correta:" << endl;
        for (int i = 0; i < LINHA; i++)
        {
            for (int j = 0; j < COLUNA; j++)
            {
                cout << matrizGabarito[i][j] << " ";
            }
            cout << endl;
        }
    }

    cout << endl;
    system("pause");
    menu();
}

// Ponto de entrada do programa
int main()
{
    system("chcp 65001 > nul");
    srand(time(0));
    boasVindas();
    return 0;
}
