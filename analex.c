#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "tokens.c"

int linha = 1;

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
void volta_char(FILE *farq)
{
    fseek(farq, -1, SEEK_CUR);
}
void analex(int estado, tabela *LexTable)
{
    int verifica = 1;
    FILE *farq;
    int car = 0, dot = 0;
    farq = fopen("arqtexto.txt", "r");
    FILE *pont_arq;
    pont_arq = fopen("LexTable.txt", "w");
    Elem lex;
    char lexema[999] = "";
    char token[999] = "";

    while (estado != -1)
    {

        if (verifica == 1)
        {
            //printf("Verificou %d\n",linha);
            car = (int)lerChar(farq);

            while (car == 32 || car == 10)
            {

                if (car == 10)
                {
                    linha++;
                }
                if (estado == 1)
                {

                    strcpy(token, "TOKIDENTIFICADOR");
                    //lex.linha = linha;
                    printf("%d \t%s   \t %s\n", linha, lexema, token);
                    fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                    //add(LexTable, lex);
                    //printf("%d \t %s \t %s\n",linha, lexema, token);
                    lexema[0] = '\0';
                }
                car = (int)lerChar(farq);
            }
        }
        else if (verifica == 0)
        {
            car = (int)lerChar(farq);
            verifica = 1;
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
            else if (car == 34)
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
                verifica = 0;
            }
            else if (car == 42)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 21;
            }
            else if (car == 47)
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
                estado = 21;
            }
            else if (car == 39)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 57;
                verifica = 0;
            }
            else if (car == 124)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 54;
                verifica = 0;
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
            else if (car == 38)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 51;
                verifica = 0;
            }
            else if (car == 94)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 66;
            }
            else if (car == 35)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 67;
            }
            else if (car == 46)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 68;
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
            }
            volta_char(farq);
            if (strcmp(lexema, TOKAUTO[0]) == 0)
            {
                strcpy(token, TOKAUTO[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKBREAK[0]) == 0)
            {
                strcpy(token, TOKBREAK[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKCASE[0]) == 0)
            {

                strcpy(token, TOKCASE[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKCHAR[0]) == 0)
            {

                strcpy(token, TOKCHAR[1]);

                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKCONST[0]) == 0)
            {
                strcpy(token, TOKCONST[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKCONTINUE[0]) == 0)
            {

                strcpy(token, TOKCONTINUE[1]);

                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKDEFAULT[0]) == 0)
            {

                strcpy(token, TOKDEFAULT[1]);

                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKDO[0]) == 0)
            {

                strcpy(token, TOKDO[1]);

                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKDOUBLE[0]) == 0)
            {

                strcpy(token, TOKDOUBLE[1]);

                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKELSE[0]) == 0)
            {

                strcpy(token, TOKELSE[1]);

                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKENUM[0]) == 0)
            {

                strcpy(token, TOKENUM[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKEXTERN[0]) == 0)
            {
                strcpy(token, TOKEXTERN[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKFOR[0]) == 0)
            {

                strcpy(token, TOKFOR[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKGOTO[0]) == 0)
            {

                strcpy(token, TOKGOTO[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKIF[0]) == 0)
            {

                strcpy(token, TOKIF[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKINT[0]) == 0)
            {

                strcpy(token, TOKINT[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKLONG[0]) == 0)
            {

                strcpy(token, TOKLONG[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKREGISTER[0]) == 0)
            {

                strcpy(token, TOKREGISTER[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKRETURN[0]) == 0)
            {

                strcpy(token, TOKRETURN[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKSHORT[0]) == 0)
            {

                strcpy(token, TOKSHORT[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKSIGNED[0]) == 0)
            {

                strcpy(token, TOKSIGNED[0]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKSIZEOF[0]) == 0)
            {

                strcpy(token, TOKSIZEOF[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKSTATIC[0]) == 0)
            {

                strcpy(token, TOKSTATIC[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKSTRUCT[0]) == 0)
            {

                strcpy(token, TOKSTRUCT[1]);
                // add(LexTable, lex);
                printf("%d \t%s\t %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKSWITCH[0]) == 0)
            {

                strcpy(token, TOKSWITCH[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKTYPEDEF[0]) == 0)
            {

                strcpy(token, TOKTYPEDEF[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKUNION[0]) == 0)
            {

                strcpy(token, TOKUNION[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKUNSIGNED[0]) == 0)
            {

                strcpy(token, TOKUNSIGNED[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKVOID[0]) == 0)
            {

                strcpy(token, TOKVOID[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                // add(LexTable, lex);
                lexema[0] = '\0';
            }
            else if (strcmp(lexema, TOKVOLATILE[0]) == 0)
            {

                strcpy(token, TOKVOLATILE[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKWHILE[0]) == 0)
            {

                strcpy(token, TOKWHILE[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKINCLUDE[0]) == 0)
            {
                strcpy(token, TOKINCLUDE[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else
            {
                strcpy(token, "TOKIDENTIFICADOR");
                //add(LexTable, lex);

                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
                //printf( "%d %s %s", lex.linha, lexema, token);
            }

            break;
        case 3:
            if (car == 62)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 5;
            }
            else if (car == 61)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 4;
            }
            else
            {
                volta_char(farq);
                estado = 6;
            }
            break;
        case 4:
        case 5:
        case 6:
            volta_char(farq);
            if (strcmp(token, TOKDESDIR[0]) == 0)
            {
                strcpy(token, TOKDESDIR[1]);

                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(token, TOKMAOIG[0]) == 0)
            {
                strcpy(token, TOKMAOIG[1]);

                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else
            {
                strcpy(token, TOKMAIOR[1]);

                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }

            break;

        case 7:
            if (car == 60)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 9;
            }
            else if (car == 61)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 8;
            }
            else
            {
                volta_char(farq);
                estado = 10;
            }

            break;
        case 8:
        case 9:
        case 10:
            volta_char(farq);
            if (strcmp(token, TOKDESESQ[0]) == 0)
            {
                strcpy(token, TOKDESESQ[1]);

                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(token, TOKMENIG[0]) == 0)
            {
                strcpy(token, TOKMENIG[1]);

                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else
            {
                strcpy(token, TOKMENORQUE[1]);

                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }

            break;
        case 11:
            if (car == 61)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 12;
            }
            else
            {
                volta_char(farq);
                estado = 13;
            }
            break;

        case 12:
            volta_char(farq);
            strcpy(token, TOKIGUAL[1]);
            printf("%d \t%s   \t %s\n", linha, lexema, token);
            fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            lexema[0] = '\0';
            estado = 0;
            break;
        case 13:
            volta_char(farq);
            strcpy(token, TOKATR[1]);
            printf("%d \t%s   \t %s\n", linha, lexema, token);
            fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            lexema[0] = '\0';
            estado = 0;
            break;
        case 18:
            if (car == 61)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 19;
            }
            else
            {
                volta_char(farq);
                estado = 20;
            }

            break;
        case 19:
        case 20:
            volta_char(farq);
            if (strcmp(lexema, TOKDIFE[0]) == 0)
            {
                strcpy(token, TOKDIFE[1]);

                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else
            {
                strcpy(token, TOKNOT[1]);

                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
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
            else
            {
                volta_char(farq);
                estado = 34;
            }

            break;
        case 34:
        case 35:
        case 36:
            volta_char(farq);
            if (strcmp(lexema, TOKMENOS[0]) == 0)
            {
                strcpy(token, TOKMENOS[1]);

                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKDECATR[0]) == 0)
            {
                strcpy(token, TOKDECATR[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKDEC[0]) == 0)
            {

                strcpy(token, TOKDEC[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }

            break;
        case 21:
            if (car == 61)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 22;
            }
            else
            {
                volta_char(farq);
                estado = 23;
            }
            break;
        case 22:
            volta_char(farq);
            strcpy(token, TOKMULTCATR[1]);
            printf("%d \t%s   \t %s\n", linha, lexema, token);
            fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            lexema[0] = '\0';
            estado = 0;
            break;
        case 23:
            volta_char(farq);
            strcpy(token, TOKMUL[1]);
            printf("%d \t%s   \t %s\n", linha, lexema, token);
            fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            lexema[0] = '\0';
            estado = 0;
            break;
            break;
        case 24:
        case 37:
        case 38:
        a:
            if (dot == 1)
            {
                char carac = (char)car;
                car = (int)lerChar(farq);
                strncat(lexema, &carac, 1);
            }
            while (car >= 48 && car <= 57)
            {

                char carac = (char)car;
                strncat(lexema, &carac, 1);
                car = (int)lerChar(farq);
            }
            if (car == 46)
            {
                dot = 1;
                goto a;
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

                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            volta_char(farq);

            break;
        case 14:
            if (car == 43)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 15;
            }
            else if (car == 61)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 16;
            }
            else
            {

                volta_char(farq);

                estado = 17;
            }
            break;
        case 15:
        case 16:
        case 17:
            volta_char(farq);
            if (strcmp(lexema, TOKINC[0]) == 0)
            {
                strcpy(token, TOKINC[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKSOATR[0]) == 0)
            {
                strcpy(token, TOKSOATR[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKPLUS[0]) == 0)
            {
                strcpy(token, TOKPLUS[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }

            break;
        case 49:
        case 50:
        {
            while (car != 34)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                car = (int)lerChar(farq);
            }
            char carac = (char)car;
            strncat(lexema, &carac, 1);

            strcpy(token, "TOKSTRING");
            printf("%d \t%s\t %s\n", linha, lexema, token);
            lexema[0] = '\0';
            estado = 0;
        }
        break;
        case 51:
            if (car == 38)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 53;
            }
            else
            {
                volta_char(farq);
                estado = 52;
            }
            break;
        case 52:
            volta_char(farq);
            strcpy(token, TOKANDBIT[1]);
            printf("%d \t%s   \t %s\n", linha, lexema, token);
            fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            lexema[0] = '\0';
            estado = 0;
            verifica = 1;
            break;

        case 53:
            volta_char(farq);
            strcpy(token, TOKAND[1]);
            printf("%d \t%s   \t %s\n", linha, lexema, token);
            fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            lexema[0] = '\0';
            estado = 0;
            verifica = 1;
            break;
        case 54:
            if (car == 124)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 55;
            }
            else
            {
                volta_char(farq);
                estado = 56;
            }
            break;
        case 55:
            volta_char(farq);
            strcpy(token, TOKOR[1]);
            printf("%d \t%s   \t %s\n", linha, lexema, token);
            fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            lexema[0] = '\0';
            estado = 0;
            verifica = 1;
            break;

        case 56:
            volta_char(farq);
            strcpy(token, TOKORBIT[1]);
            printf("%d \t%s   \t %s\n", linha, lexema, token);
            fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            lexema[0] = '\0';
            estado = 0;
            verifica = 1;
            break;

        case 41:
            if (car == 47)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 45;
            }
            else if (car == 61)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 47;
                verifica = 1;
            }
            else if (car == 42)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 42;
                verifica = 1;
            }
            else
            {
                volta_char(farq);
                estado = 48;
                verifica = 1;
            }
            break;
        case 42:
        {
            while (car != 42)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                car = (int)lerChar(farq);
            }
            char carac = (char)car;
            strncat(lexema, &carac, 1);
            //volta_char(farq);
            estado = 43;
        }
        break;
        case 43:
            //volta_char(farq);
            if (car != 47)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                estado = 42;
            }
            else
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                strcpy(token, "TOKCOMENTARIO");
                printf("%d \t%s\t %s\n", linha, lexema, token);
                lexema[0] = '\0';
                estado = 0;
            }
            break;
        case 45:

            while (car != 10)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                car = (int)lerChar(farq);
            }
            strcpy(token, "TOKCOMENTARIO");
            printf("%d \t%s\t %s\n", linha, lexema, token);
            lexema[0] = '\0';
            verifica = 1;
            estado = 0;
            break;
        case 47:
        {
            volta_char(farq);
            strcpy(token, TOKDIVCATR[1]);
            printf("%d \t%s   \t %s\n", linha, lexema, token);
            fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            lexema[0] = '\0';
            estado = 0;
            break;
        }
        case 48:
            volta_char(farq);
            strcpy(token, TOKDIV[1]);
            printf("%d \t%s   \t %s\n", linha, lexema, token);
            fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            lexema[0] = '\0';
            estado = 0;
            break;
        case 57:
            if (car == 92)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);

                estado = 69;
            }
            else if (car != 39)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);

                estado = 58;
            }

            break;

        case 58:
        case 69:
            if (car == 48)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);

                estado = 70;
            }
            else if (car == 39)
            {
                char carac = (char)car;
                strncat(lexema, &carac, 1);
                strcpy(token, "TOKCARATER");
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                estado = 0;
                lexema[0] = '\0';
                verifica = 1;
            }
            else
            {

                char carac = (char)car;
                strncat(lexema, &carac, 1);
                strcpy(token, "Esperava \' ");
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                estado = 0;
                verifica = 1;
                lexema[0] = '\0';
            }
            break;
        case 70:
        {

            char carac = (char)car;
            strncat(lexema, &carac, 1);
            strcpy(token, "TOKCARATER");
            printf("%d \t%s   \t %s\n", linha, lexema, token);
            fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            estado = 0;
            lexema[0] = '\0';
            verifica = 1;
            break;
        }
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 60:
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
        case 66:
        {
            volta_char(farq);
            if (strcmp(lexema, TOKPS_ABERTO[0]) == 0)
            {
                strcpy(token, TOKPS_ABERTO[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            }
            else if (strcmp(lexema, TOKPS_FECHADO[0]) == 0)
            {
                strcpy(token, TOKPR_FECHADO[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            }
            else if (strcmp(lexema, TOKCH_ABERTO[0]) == 0)
            {
                strcpy(token, TOKCH_ABERTO[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            }
            else if (strcmp(lexema, TOKCH_FECHADO[0]) == 0)
            {
                strcpy(token, TOKCH_FECHADO[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            }
            else if (strcmp(lexema, TOKPR_ABERTO[0]) == 0)
            {
                strcpy(token, TOKPR_ABERTO[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            }
            else if (strcmp(lexema, TOKPR_FECHADO[0]) == 0)
            {
                strcpy(token, TOKPR_FECHADO[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            }
            else if (strcmp(lexema, TOKVIRGULA[0]) == 0)
            {
                strcpy(token, TOKVIRGULA[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            }
            else if (strcmp(lexema, TOKPVIRGULA[0]) == 0)
            {
                strcpy(token, TOKPVIRGULA[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            }
            else if (strcmp(lexema, TOKBITCATR[0]) == 0)
            {
                strcpy(token, TOKBITCATR[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            }
            else if (strcmp(lexema, TOKCOM[0]) == 0)
            {
                strcpy(token, TOKCOM[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            }
            else if (strcmp(lexema, TOKOREX[0]) == 0)
            {
                strcpy(token, TOKOREX[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            }
            else if (strcmp(lexema, TOKPERCENT[0]) == 0)
            {
                strcpy(token, TOKPERCENT[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            }
            lexema[0] = '\0';
            verifica = 1;
            estado = 0;
            break;
        }
        case 67:
            volta_char(farq);
            strcpy(token, "TOKCARDINAL");
            printf("%d \t%s   \t %s\n", linha, lexema, token);
            fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            lexema[0] = '\0';
            estado = 0;
            break;
        case 68:
            volta_char(farq);
            strcpy(token, "TOKPONTO");
            printf("%d \t%s   \t %s\n", linha, lexema, token);
            fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            lexema[0] = '\0';
            estado = 0;
            break;
        default:
            break;
        }
    }
}