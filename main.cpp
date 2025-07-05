#include <iostream>  // Biblioteca padrão para entrada e saída
#include <cstdlib>   // Biblioteca para funções rand() e srand()
#include <ctime>     // Biblioteca para usar time() como semente randômica
#include <windows.h> // Biblioteca do Windows para usar Sleep() e system()
using namespace std;

#define LINHA 4  // Define o número de linhas da matriz
#define COLUNA 4 // Define o número de colunas da matriz

// Variáveis globais
int matrizPrincipal[LINHA][COLUNA];          // Guarda os pares embaralhados
int matrizGabarito[LINHA][COLUNA];           // Pode ser uma versão transformada da matrizPrincipal
int matrizJogo[LINHA][COLUNA];               // É a matriz que o jogador enxerga (com * ou número)
int jogadas = 0;                             // Contador de jogadas realizadas
const int maxJogadas = 24;                   // Limite máximo de jogadas permitido
int paresEncontrados = 0;                    // Quantidade de pares encontrados
const int totalPares = (LINHA * COLUNA) / 2; // Total de pares a serem encontrados (8)

// Protótipos das funções
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

// Função que lida com a escolha do menu pelo usuário
void menuFuncionar()
{
    int opcaoMenu;
    cout << "Digite a opcao que deseja ir: ";
    cin >> opcaoMenu;

    switch (opcaoMenu) // Verifica qual opção foi escolhida
    {
    case 1:
        iniciarJogo(); // Começa o jogo
        break;
    case 2:
        comoJogar(); // Explica como jogar
        break;
    case 3:
        sobre(); // Informações do projeto
        break;
    case 4:
        fim(); // Encerra o programa
        break;
    default:
        cout << "Opcao inválida, digite novamente!" << endl;
        Sleep(1000); // Espera 1 segundo
        menu();      // Volta ao menu
        break;
    }
}

// Função que exibe a mensagem de boas-vindas e créditos
void boasVindas()
{
    system("cls"); // Limpa a tela
    cout << "+----------------------------------------------+" << endl;
    cout << "|        BOAS VINDAS AO JOGO DA MEMÓRIA!       |" << endl;
    cout << "+----------------------------------------------+" << endl;
    cout << "| Desenvolvido por:                            |" << endl;
    cout << "| Luiz Felipe de Souza                         |" << endl;
    cout << "| Matheus Pompeo Dias                          |" << endl;
    cout << "| Nathan Gustavo Padilha Reichert              |" << endl;
    cout << "+----------------------------------------------+" << endl;

    Sleep(3000); // Espera 3 segundos
    menu();      // Vai para o menu
}

// Função que exibe o menu principal
void menu()
{
    system("cls"); // Limpa a tela
    cout << "+----------------------------+" << endl;
    cout << "|        MENU DO JOGO        |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "| (1) Iniciar o Jogo         |" << endl;
    cout << "| (2) Como Jogar             |" << endl;
    cout << "| (3) Sobre                  |" << endl;
    cout << "| (4) Sair                   |" << endl;
    cout << "+----------------------------+" << endl
         << endl;
    menuFuncionar(); // Chama a função que interpreta a opção escolhida
}

// Função que exibe informações sobre o projeto
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

    system("pause"); // Aguarda o usuário apertar uma tecla
    menu();          // Retorna ao menu principal
}

// Função que mostra as instruções do jogo
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
    cout << "| O jogo termina ao encontrar todos os pares ou acabar as    |" << endl;
    cout << "| jogadas.                                                   |" << endl;
    cout << "+------------------------------------------------------------+" << endl
         << endl;

    system("pause"); // Espera interação
    menu();          // Volta ao menu
}

// Função que finaliza o programa
void fim()
{
    system("cls");
    cout << "+----------------------------------------------------------+" << endl;
    cout << "|                       FIM DE JOGO                        |" << endl;
    cout << "+----------------------------------------------------------+" << endl;
    cout << "| Obrigado por jogar o Jogo da Memória!                    |" << endl;
    cout << "| Esperamos que tenha se divertido!                        |" << endl;
    cout << "+----------------------------------------------------------+" << endl;
    exit(0); // Encerra a execução
}

// Gera os pares embaralhados na matrizPrincipal
void gerarMatrizPrincipal()
{
    int pares[LINHA * COLUNA]; // Vetor auxiliar com os pares
    int k = 0;

    // Cria pares duplicados (1,1), (2,2), ..., (8,8)
    for (int i = 0; i < totalPares; i++)
    {
        pares[k++] = i + 1;
        pares[k++] = i + 1;
    }

    // Embaralha os pares com algoritmo Fisher-Yates
    for (int i = LINHA * COLUNA - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(pares[i], pares[j]);
    }

    // Preenche a matrizPrincipal com os valores embaralhados
    k = 0;
    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            matrizPrincipal[i][j] = pares[k++];
        }
    }
}

// Cria a matrizGabarito baseada na principal, podendo aplicar uma transformação
void gerarMatrizGabarito()
{
    gerarMatrizPrincipal(); // Cria a base
    int tipo = rand() % 4;  // Tipo de transformação aleatória

    // Aplica a transformação escolhida
    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            switch (tipo)
            {
            case 0:
                matrizGabarito[i][j] = matrizPrincipal[i][j]; // original
                break;
            case 1:
                matrizGabarito[i][j] = matrizPrincipal[j][i]; // transposta
                break;
            case 2:
                matrizGabarito[i][j] = matrizPrincipal[LINHA - i - 1][j]; // invertida por linha
                break;
            case 3:
                matrizGabarito[i][j] = matrizPrincipal[i][COLUNA - j - 1]; // invertida por coluna
                break;
            }
        }
    }
}

// Exibe a matriz que o jogador vê
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
                cout << "* "; // Peça ainda não revelada
            else
                cout << matrizJogo[i][j] << " "; // Mostra o número
        }
        cout << endl;
    }
}

// Função principal de execução do jogo
void iniciarJogo()
{
    jogadas = 0;
    paresEncontrados = 0;
    system("cls");

    gerarMatrizGabarito(); // Cria a matriz que o jogador tentará descobrir

    // Mostra a matriz por 5 segundos para memorizar
    cout << "Memorize o tabuleiro! Voce tem 5 segundos..." << endl
         << endl;
    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            cout << matrizGabarito[i][j] << " ";
        }
        cout << endl;
    }
    Sleep(5000); // Espera 5 segundos
    system("cls");

    // Inicializa a matriz do jogo com -1 (que representa peças escondidas)
    for (int i = 0; i < LINHA; i++)
        for (int j = 0; j < COLUNA; j++)
            matrizJogo[i][j] = -1;

    int l1, c1, l2, c2;

    // Loop principal do jogo
    while (jogadas < maxJogadas && paresEncontrados < totalPares)
    {
        system("cls");
        cout << "JOGO DA MEMORIA" << endl;
        cout << "-----------------" << endl;
        cout << "Jogadas restantes: " << maxJogadas - jogadas << endl;
        cout << "Pares encontrados: " << paresEncontrados << " de " << totalPares << endl;
        cout << "-----------------" << endl;

        exibirMatrizJogo(); // Mostra o estado atual

        // Escolha da primeira peça
        do
        {
            cout << "\nEscolha a primeira peca (linha e coluna): ";
            cin >> l1 >> c1;
        } while (l1 < 0 || l1 >= LINHA || c1 < 0 || c1 >= COLUNA || matrizJogo[l1][c1] != -1);

        matrizJogo[l1][c1] = matrizGabarito[l1][c1]; // Revela a peça
        system("cls");
        exibirMatrizJogo();

        // Escolha da segunda peça
        do
        {
            cout << "\nEscolha a segunda peca (linha e coluna): ";
            cin >> l2 >> c2;
        } while (l2 < 0 || l2 >= LINHA || c2 < 0 || c2 >= COLUNA || matrizJogo[l2][c2] != -1 || (l1 == l2 && c1 == c2));

        matrizJogo[l2][c2] = matrizGabarito[l2][c2]; // Revela a peça
        system("cls");
        exibirMatrizJogo();
        jogadas++;

        // Verifica se encontrou um par
        if (matrizGabarito[l1][c1] == matrizGabarito[l2][c2])
        {
            cout << "\nJOGADA OK! Voce encontrou um par!" << endl;
            paresEncontrados++;
        }
        else
        {
            cout << "\nJOGADA NOK! As pecas sao diferentes." << endl;
            matrizJogo[l1][c1] = -1; // Oculta novamente
            matrizJogo[l2][c2] = -1;
        }
        Sleep(2000); // Dá tempo para o jogador ver o resultado
    }

    // Mensagem final
    system("cls");
    if (paresEncontrados == totalPares)
    {
        cout << "+------------------------------------------+" << endl;
        cout << "|      PARABENS! VOCE VENCEU O JOGO!       |" << endl;
        cout << "|   Voce encontrou todos os pares em " << jogadas << " jogadas! |" << endl;
        cout << "+------------------------------------------+" << endl;
    }
    else
    {
        cout << "+--------------------------------------------+" << endl;
        cout << "|             FIM DE JOGO!                   |" << endl;
        cout << "| Voce nao encontrou todos os pares a tempo. |" << endl;
        cout << "+--------------------------------------------+" << endl;

        // Mostra a matriz correta
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
    system("pause"); // Espera o jogador apertar algo
    menu();          // Retorna ao menu
}

// Função principal do programa
int main()
{
    system("chcp 65001 > nul"); // Define codificação UTF-8 para acentuação
    srand(time(0));             // Semente aleatória baseada na hora atual
    boasVindas();               // Inicia o jogo com tela de boas-vindas
    return 0;
}
