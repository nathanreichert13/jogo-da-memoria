#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <ctime>
using namespace std;

#define linha 4
#define coluna 4

void menu()
{
    int opcao, voltar;
    string opcoes[] = {"Iniciar o Jogo", "Como Jogar", "Sobre Nós", "Sair do Jogo"};

    for (;;)
    {
        cout << "\n=== MENU DO JOGO ===" << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << (i + 1) << " - " << opcoes[i] << endl;
        }

        cout << "Escolha uma opção: " << endl;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            iniciarJogo(); // Preencher futuramente com a função devida
            break;

        case 2:
            cout << "Você escolheu Como Jogar" << endl;
            comoJogar();
            break;

        case 3:
            cout << "Você escolheu Sobre Nós" << endl;
            sobreNos();
            break;

        case 4:
            cout << "Voce escolheu sair.. Obrigado por Jogar!!" << endl;
            break;

        default:
            cout << "Opção Inválida, retornando ao menu.." << endl;
        }

        cout << "\nDeseja voltar ao menu ou sair do jogo?" << endl;
        cout << "\n1 - Voltar ao menu" << endl;
        cout << "\n2 - Sair do jogo" << endl;
        cout << "\nEscolha a opção" << endl;
        cin >> voltar;

        if (voltar == 1)
        {
            continue;
        }
        else if (voltar == 2)
        {
            cout << "\nSaindo... Obrigado por entrar no jogo!!" << endl;
            break;
        }
        else
        {
            cout << "\nOpção Inválida! Voltando pro menu..." << endl;
        }
    }
}

void comoJogar()
{
    cout << "*********************************************************" << endl;
    cout << "*                                                       *" << endl;
    cout << "*               GUIA DE COMO JOGAR                      *" << endl;
    cout << "*                                                       *" << endl;
    cout << "*********************************************************" << endl;
    cout << endl;

    cout << "- Objetivo: Encontrar todos os pares de peças escondidas." << endl;
    cout << "- A matriz do jogo tem 16 peças (8 pares) em uma matriz 4x4." << endl;
    cout << "- Você joga sozinho e deve formar os pares antes de acabar as jogadas." << endl;
    cout << endl;

    cout << "\n================== COMO FUNCIONA ==================" << endl;
    cout << "- O programa cria uma matriz principal com os pares." << endl;
    cout << "- Essa matriz é embaralhada de forma aleatória." << endl;
    cout << "- Você verá uma matriz vazia no começo do jogo." << endl;
    cout << "- Em cada jogada, escolha a linha e a coluna de duas peças." << endl;
    cout << "- O programa revela as peças e informa se formou um par:" << endl;
    cout << "    -> Se forem iguais: JOGADA OK" << endl;
    cout << "    -> Se forem diferentes: JOGADA NOK" << endl;
    cout << endl;

    cout << "- Número máximo de jogadas: 24 (3x o número de pares)." << endl;
    cout << "- O jogo termina ao descobrir todos os pares (Vitória)" << endl;
    cout << "  ou ao usar todas as jogadas sem formar todos os pares (Derrota)." << endl;
    cout << endl;

    cout << "\n================== EXEMPLO DE JOGADA ==================" << endl;
    cout << "Digite linha da primeira peça: 1" << endl;
    cout << "Digite coluna da primeira peça: 2" << endl;
    cout << "Digite linha da segunda peça: 3" << endl;
    cout << "Digite coluna da segunda peça: 4" << endl;
    cout << " --> O programa revela as peças e mostra se formou um par." << endl;
    cout << endl;

    cout << "\n================== DICA ==================" << endl;
    cout << "- Lembre as posições já reveladas para encontrar os pares mais fácil." << endl;
    cout << "- Use bem suas jogadas!" << endl;

    cout << endl;
    cout << "\n*********************************************************" << endl;
    cout << "*               BOA SORTE E BOM JOGO!                   *" << endl;
    cout << "*********************************************************" << endl;
}

void sobreNos()
{
    cout << "*******************************************************" << endl;
    cout << "*                                                     *" << endl;
    cout << "*        TRABALHO SOBRE JOGO DE MATRIZES - T3         *" << endl;
    cout << "*                                                     *" << endl;
    cout << "*******************************************************" << endl;
    cout << endl;

    cout << "\nUNIVALI - Univerdade do Vale do Itajaí - Campus Itajai" << endl;
    cout << "\nMatéria: Algoritmos e Programação" << endl;
    cout << "\nProfessor: Michael Douglas" << endl;

    cout << "*******************************************************" << endl;
    cout << "*                                                     *" << endl;
    cout << "*            ======== MEMBROS =========               *" << endl;
    cout << "*               Luiz Felipe de Souza                  *" << endl;
    cout << "*                  Matheus Pompeo                     *" << endl;
    cout << "*                 Nathan Reichert                     *" << endl;
    cout << "*           =============================             *" << endl;
    cout << "*******************************************************" << endl;
    cout << endl;
}

void matrizGlobalFinal(int matriz[linha][coluna], int matrizResultado[linha][coluna])
{

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            matriz[i][j] = matrizResultado[i][j];
        }
    }
}

void iniciarJogar(int matriz[linha][coluna], int matrizResultado[linha][coluna])
{
    int intervalo = 5;            // intervalo de 2 segundos
    time_t ultimoTempo = time(0); // pega o tempo atual

    cout << "Você terá que memorizar essa matriz: " << endl;

    matrizGlobalFinal(matriz, matrizResultado);

    while (true)
    {
        time_t agora = time(0); // pega o tempo atual novamente

        if (agora - ultimoTempo >= intervalo)
        {
            matriz[linha][coluna];
            ultimoTempo = agora; // atualiza o tempo da última execução
        }
    }
}

void aleatorizarMatriz(int matriz[linha][coluna])
{
    int tipoMatriz = rand() % 4;
    int matrizResultado[linha][coluna];

    switch (tipoMatriz)
    {
    case 0: // MATRIZ ORIGINAL
        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
            {
                matrizResultado[i][j] = matriz[i][j];
                cout << matrizResultado[i][j] << " ";
            }
            cout << endl;
        }
        break;

    case 1: // MATRIZ TRANSPOSTA
        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
            {
                matrizResultado[i][j] = matriz[j][i]; // Transposição
                cout << matrizResultado[i][j] << " ";
            }
            cout << endl;
        }
        break;

    case 2: // MATRIZ INVERTIDA POR LINHA
        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
            {
                matrizResultado[i][j] = matriz[i][coluna - j - 1];
                cout << matrizResultado[i][j] << " ";
            }
            cout << endl;
        }
        break;

    case 3: // MATRIZ INVERTIDA POR COLUNA
        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
            {
                matrizResultado[i][j] = matriz[linha - i - 1][j];
                cout << matrizResultado[i][j] << " ";
            }
            cout << endl;
        }
        break;
    }
}

int numeroAleatorio()
{
    int numeroAleatorio = rand() % 10;
}

int gerarMatriz(int matriz[linha][coluna])
{
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            matriz[i][j] = numeroAleatorio(); // Função que gera os numeros aleatorios de 0 a 10
        }
    }
}

void jogar(int matriz[linha][coluna])
{
    gerarMatriz(matriz);
    aleatorizarMatriz(matriz);
    menu();
}

int main()
{
    int matriz[linha][coluna];
    srand(time(NULL));

    jogar(matriz);
    return 0;
}