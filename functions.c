#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "tokens.c"

int linha = 0;

struct tab
{
    Elem *lex;
    struct tab *prox;
};
struct elem
{
    char *lexema;
    char *token;
    int linha;
};
void criar(tabela *Table)
{
    Table = (tabela *)malloc(sizeof(tabela));
}

void add(tabela *Table, Elem lex)
{
}
char lerChar(FILE *farq)
{

    if (farq == NULL) // Pode-se fazer o teste dessa forma
    {
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    // printf("\n\nVou ler e mostrar o texto gravado....\n\n");

    return fgetc(farq);
}
void analex(int estado, tabela *LexTable)
{
    int verifica = 1;
    FILE *farq;
    int car, dot = 0;
    farq = fopen("arqtexto.txt", "r");
    Elem lex;
    char lexema[999] = "";
    char token[999] = "";

    while (estado != -1)
    {

        if (verifica == 1)
        {

            car = (int)lerChar(farq);

            while (car == 32 || car == 10 || car == 11)
            {

                if (car == 10)
                {
                    //   linha++;
                }
                if (estado == 1)
                {

                    strcpy(token, "TOKIDENTIFICADOR");
                    //lex.linha = linha;
                    printf("%s \t %s\n", lexema, token);
                    //add(LexTable, lex);
                    printf("%s \t %s\n", lexema, token);
                    lexema[0] = '\0';
                }
                car = (int)lerChar(farq);
                fflush(stdin);
            }
        }
        if ((char)car == EOF)
        {
            break;
        }

        switch (estado)
        {
        case 0:

            if ((car >= 65 && car <= 90) || (car >= 97 && car <= 122) || car == 95)
            {

                char carac = (char)car;

                strncat(lexema, &carac, 1);

                estado = 1;
            }
            else if (car == 45)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 33;
            }
            else if (car == 43)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 14;
            }
            else if (car >= 48 && car <= 57)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 37;
            }
            else if (car == 38)
            {

                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 49;
            }
            else if (car == 47)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 41;
            }
            else if (car == 42)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 21;
            }
            else if (car == 34)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 41;
            }
            else if (car == 60)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 7;
            }
            else if (car == 62)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 3;
            }
            else if (car == 33)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 18;
            }
            else if (car == 61)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 11;
            }
            else if (car == 39)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 57;
            }
            else if (car == 126)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 60;
                verifica = 0;
            }
            else if (car == 44)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 61;
                verifica = 0;
            }
            else if (car == 41)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 32;
                verifica = 0;
            }
            else if (car == 40)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 31;
                verifica = 0;
            }
            else if (car == 91)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 62;
                verifica = 0;
            }
            else if (car == 93)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 63;
                verifica = 0;
            }
            else if (car == 123)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 28;
                verifica = 0;
            }
            else if (car == 125)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 29;
                verifica = 0;
            }
            else if (car == 58)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 64;
                verifica = 0;
            }
            else if (car == 59)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 30;
                verifica = 0;
            }
            else if (car == 37)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 65;
            }
            else if (car == 94)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 66;
            }
            else
            {
                estado = -1;
            }

            break;
        case 1:

            while ((car >= 65 && car <= 90) || (car >= 97 && car <= 122) || car == 95 || (car >= 48 && car <= 57))
            {

                char carac = (char)car;

                strncat(lexema, &carac, 1);
                car = (int)lerChar(farq);
                fflush(stdin);
            }
            if (strcmp(lexema, TOKAUTO[0]) == 0)
            {
                strcpy(token, TOKAUTO[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKBREAK[0]) == 0)
            {
                strcpy(token, TOKBREAK[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKCASE[0]) == 0)
            {

                strcpy(token, TOKCASE[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
               
            }
            else if (strcmp(lexema, TOKCHAR[0]) == 0)
            {

                strcpy(token, TOKCHAR[1]);

                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKCONST[0]) == 0)
            {
                strcpy(token, TOKCONST[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKCONTINUE[0]) == 0)
            {

                strcpy(token, TOKCONTINUE[1]);

                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKDEFAULT[0]) == 0)
            {

                strcpy(token, TOKDEFAULT[1]);

                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKDO[0]) == 0)
            {

                strcpy(token, TOKDO[1]);

                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKDOUBLE[0]) == 0)
            {

                strcpy(token, TOKDOUBLE[1]);

                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKELSE[0]) == 0)
            {

                strcpy(token, TOKELSE[1]);

                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKENUM[0]) == 0)
            {

                strcpy(token, TOKENUM[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKEXTERN[0]) == 0)
            {
                strcpy(token, TOKEXTERN[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKFLOAT[0]) == 0)
            {

                strcpy(token, TOKFLOAT[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKFOR[0]) == 0)
            {

                strcpy(token, TOKFOR[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKGOTO[0]) == 0)
            {

                strcpy(token, TOKGOTO[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKIF[0]) == 0)
            {

                strcpy(token, TOKIF[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKINT[0]) == 0)
            {

                strcpy(token, TOKINT[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKLONG[0]) == 0)
            {

                strcpy(token, TOKLONG[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKREGISTER[0]) == 0)
            {

                strcpy(token, TOKREGISTER[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKRETURN[0]) == 0)
            {

                strcpy(token, TOKRETURN[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKSHORT[0]) == 0)
            {

                strcpy(token, TOKSHORT[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKSIGNED[0]) == 0)
            {

                strcpy(token, TOKSIGNED[0]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKSIZEOF[0]) == 0)
            {

                strcpy(token, TOKSIZEOF[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKSTATIC[0]) == 0)
            {

                strcpy(token, TOKSTATIC[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKSTRUCT[0]) == 0)
            {

                strcpy(token, TOKSTRUCT[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKSWITCH[0]) == 0)
            {

                strcpy(token, TOKSWITCH[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKTYPEDEF[0]) == 0)
            {

                strcpy(token, TOKTYPEDEF[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKUNION[0]) == 0)
            {

                strcpy(token, TOKUNION[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKUNSIGNED[0]) == 0)
            {

                strcpy(token, TOKUNSIGNED[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKVOID[0]) == 0)
            {

                strcpy(token, TOKVOID[1]);
                printf("%s \t %s\n", lexema, token);
                // add(LexTable, lex);
                lexema[0] = '\0';
            }
            else if (strcmp(lexema, TOKVOLATILE[0]) == 0)
            {

                strcpy(token, TOKVOLATILE[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKWHILE[0]) == 0)
            {

                strcpy(token, TOKWHILE[1]);
                // add(LexTable, lex);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else
            {
                strcpy(token, "TOKIDENTIFICADOR");
                //add(LexTable, lex);

                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
                //printf( "%d %s %s", lex.linha, lexema, token);
            }

            break;
        case 33:
            if (car >= 48 && car <= 57)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 37;
            }
            else if (car == 61)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 35;
            }
            else if (car == 45)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 36;
            }
            else if (strcmp(lexema, TOKMENOS[0]) == 0)
            {
                strcpy(token, TOKMENOS[1]);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }

            break;
        case 35:
        case 36:
            if (strcmp(lexema, TOKDEC[0]) == 0)
            {
                strcpy(token, TOKDEC[1]);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKDECATR[0]) == 0)
            {
                strcpy(token, TOKDECATR[1]);
                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }

            break;
        case 24:
        case 37:
        case 38:

            while (car >= 48 && car <= 57)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                car = (int)lerChar(farq);
            }
            if (car == 46)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 38;
                dot = 1;
            }
            else
            {
                if (dot == 1)
                {
                    strcpy(token, "TOK_NFLOAT");
                    dot = 0;
                }
                else if (dot == 0)
                {
                    strcpy(token, "TOK_NINT");
                }

                printf("%s \t %s\n", lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }

            break;

        default:
            break;
        }
    }
}
