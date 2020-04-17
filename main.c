//Giovani Trentin
//Helio Lidoni
//Victor Brongel

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int numero;
    char bin[50]; //use char para facilitar
    int selecao = 10;

    //While para o menu principal
    while (selecao != 0)
    {
        printf("Escolha a opção:\n1 - Binario para Decimal \n2 - Decimal para Binario\n0 - Para Finalizar\n");
        scanf("%d", &selecao);

        //Escolha para Binario - Decimal
        if (selecao == 1)
        {
            printf("Entre com o numero Binario (0's e 1's): ");
            scanf("%s", &bin);
            numero = atoi(bin); //atoi converte um número char[] em inteiro

            //Verifica se o que foi digitado é Binario
            if (isBinario(bin))
            {
                printf("\nO numero Binario digitado foi: %s, e o valor Decimal convertido foi %d \n", bin, BinarioParaDecimal(numero));
                system("PAUSE");
                system("cls");
            }
            else
            {
                printf("\nEsse numero nao e binario!\n");
                system("PAUSE");
                system("cls");
            }
        }

        //Escolha para Decimal - Binario
        if (selecao == 2)
        {
            printf("Entre com o numero Decimal (Numeros de 0 a 9, maximo de 3 caracteres): ");
            scanf("%s", &bin);
            numero = atoi(bin);

            //Verifica se o que foi digitado é numeral se é realiza a conversão.
            if (isNumero(bin) && strlen(bin) <= 3)
            {
                printf("\nO numero Decimal foi: %s, e o valor Binario convertido foi %d \n", bin, DecimalParaBinarioRecursivo(numero));
                system("PAUSE");
                system("cls");
            }
            else
            {
                printf("\nEsse numero nao e Decimal ou possui mais que 3 caracteres!\n");
                system("PAUSE");
                system("cls");
            }
        }
    }

    return 0;
}

//Funcção para verificar se o numero é binario que contem só 0 e 1
bool isBinario(char valor[50])
{
    int i, tamanho_num;
    //Função para pegar o tamanho do char
    tamanho_num = strlen(valor);
    //For para percorrer a cadeia de caracters
    for (i = 0; i < tamanho_num; ++i)
    {
        //Analise para somente aceitar os numeros 0 e 1, caso não, retorna falso.
        if (valor[i] != '0' && valor[i] != '1')
        {
            return false;
        }
    }
    //Caso tenha percorrido todo o char e os numeros estão ok, retorna Verdadeiro.
    return true;
}

//Funcção para verificar se é um numeral que contem somente de 0 a 9
bool isNumero(char valor[50])
{
    int i, tamanho_num;
    //Função para pegar o tamanho do char
    tamanho_num = strlen(valor);
    //For para percorrer a cadeia de caracters
    for (i = 0; i < tamanho_num; ++i)
    {
        //Analise para somente aceitar os numeros de 0 a 9, caso não, retorna falso.
        if (valor[i] != '0' && valor[i] != '1' && valor[i] != '2' && valor[i] != '3' && valor[i] != '4' && valor[i] != '5' && valor[i] != '6' && valor[i] != '7' && valor[i] != '8' && valor[i] != '9')
        {
            return false;
        }
    }
    //Caso tenha percorrido todo o char e os numeros estão ok, retorna Verdadeiro.
    return true;
}

int BinarioParaDecimal(int numero)
{
    int total  = 0;
    int elevada  = 1;

    while(numero > 0) {
        total += numero % 10 * elevada ; //pega o ultimo número e miltiplica pela elevada
        numero = numero / 10; //tira o último numero
        elevada  = elevada * 2;
    }

    //1101
    // 1 * 1 = 1
    // 0 * 2 = 0
    // 1 * 4 = 4
    // 1 * 8 = 8

    return total;
}

int DecimalParaBinarioRecursivo(int numero)
{
    //Quando o resto de divisão chegar a 0 desfaz a recursividade
    if (numero == 0)
    {
        return 0;
    }
    else
    {
        //Pega o resto de divisão e faz a recursividade, usei recursividade pois já entrega os valores de traz para frente e a ultima divisão sempre será 0
        return numero % 2 + 10 * DecimalParaBinarioRecursivo(numero / 2);
    }

    //13 % 2 = 1    13 % 2 + 10 * fun(110) = 1101
    // 6 % 2 = 0    6  % 2 + 10 * fun(11)  = 110
    // 3 % 2 = 1    3  % 2 + 10 * fun(1)   = 11
    // 1 % 2 = 1    1  % 2 + 10 * fun(0)   = 1
    // 0

}

