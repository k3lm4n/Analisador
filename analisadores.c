#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokens.c"
#include "parser.h"

struct lex
{
    char *token;
    char *lexema;
    int linha;
};

struct lista
{
    Lex tab;
    struct lista *prox;
    /* data */
};

int linha = 1;

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
Lista *analex(int estado)
{
    int verifica = 1;
    FILE *farq;
    int car = 0, dot = 0;
    farq = fopen("arqtexto.txt", "r");
    FILE *pont_arq;
    pont_arq = fopen("LexTable.txt", "w");
    Lista *li = NULL;
    Lex tab;

    char lexema[200] = "";
    char token[200] = "";

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
                    tab.linha = linha;
                    tab.lexema = strdup(lexema);
                    tab.token = strdup(token);
                    li = insere(li, tab);

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
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKBREAK[0]) == 0)
            {
                strcpy(token, TOKBREAK[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKCASE[0]) == 0)
            {

                strcpy(token, TOKCASE[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKCHAR[0]) == 0)
            {

                strcpy(token, TOKCHAR[1]);

                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKCONST[0]) == 0)
            {
                strcpy(token, TOKCONST[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKCONTINUE[0]) == 0)
            {

                strcpy(token, TOKCONTINUE[1]);

                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKDEFAULT[0]) == 0)
            {

                strcpy(token, TOKDEFAULT[1]);

                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKDO[0]) == 0)
            {

                strcpy(token, TOKDO[1]);

                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKDOUBLE[0]) == 0)
            {

                strcpy(token, TOKDOUBLE[1]);

                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKELSE[0]) == 0)
            {

                strcpy(token, TOKELSE[1]);

                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKENUM[0]) == 0)
            {

                strcpy(token, TOKENUM[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKEXTERN[0]) == 0)
            {
                strcpy(token, TOKEXTERN[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKFOR[0]) == 0)
            {

                strcpy(token, TOKFOR[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKGOTO[0]) == 0)
            {

                strcpy(token, TOKGOTO[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKIF[0]) == 0)
            {

                strcpy(token, TOKIF[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKINT[0]) == 0)
            {

                strcpy(token, TOKINT[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKLONG[0]) == 0)
            {

                strcpy(token, TOKLONG[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKREGISTER[0]) == 0)
            {

                strcpy(token, TOKREGISTER[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKRETURN[0]) == 0)
            {

                strcpy(token, TOKRETURN[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKSHORT[0]) == 0)
            {

                strcpy(token, TOKSHORT[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKSIGNED[0]) == 0)
            {

                strcpy(token, TOKSIGNED[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKSIZEOF[0]) == 0)
            {

                strcpy(token, TOKSIZEOF[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKSTATIC[0]) == 0)
            {

                strcpy(token, TOKSTATIC[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
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
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKTYPEDEF[0]) == 0)
            {

                strcpy(token, TOKTYPEDEF[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKUNION[0]) == 0)
            {

                strcpy(token, TOKUNION[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKUNSIGNED[0]) == 0)
            {

                strcpy(token, TOKUNSIGNED[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKVOID[0]) == 0)
            {

                strcpy(token, TOKVOID[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                // add(LexTable, lex);
                lexema[0] = '\0';
            }
            else if (strcmp(lexema, TOKVOLATILE[0]) == 0)
            {

                strcpy(token, TOKVOLATILE[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKWHILE[0]) == 0)
            {

                strcpy(token, TOKWHILE[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKINCLUDE[0]) == 0)
            {
                strcpy(token, TOKINCLUDE[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKMAIN[0]) == 0)
            {
                strcpy(token, TOKMAIN[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKFLOAT[0]) == 0)
            {
                strcpy(token, TOKFLOAT[1]);
                // add(LexTable, lex);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else
            {
                strcpy(token, "TOKIDENTIFICADOR");
                //add(LexTable, lex);

                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
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
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(token, TOKMAOIG[0]) == 0)
            {
                strcpy(token, TOKMAOIG[1]);

                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else
            {
                strcpy(token, TOKMAIOR[1]);

                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
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
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(token, TOKMENIG[0]) == 0)
            {
                strcpy(token, TOKMENIG[1]);

                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else
            {
                strcpy(token, TOKMENORQUE[1]);

                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
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
            tab.linha = linha;
            tab.lexema = strdup(lexema);
            tab.token = strdup(token);
            li = insere(li, tab);
            lexema[0] = '\0';
            estado = 0;
            break;
        case 13:
            volta_char(farq);
            strcpy(token, TOKATR[1]);
            printf("%d \t%s   \t %s\n", linha, lexema, token);
            fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            tab.linha = linha;
            tab.lexema = strdup(lexema);
            tab.token = strdup(token);
            li = insere(li, tab);
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
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else
            {
                strcpy(token, TOKNOT[1]);

                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
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
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKDECATR[0]) == 0)
            {
                strcpy(token, TOKDECATR[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKDEC[0]) == 0)
            {

                strcpy(token, TOKDEC[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
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
            tab.linha = linha;
            tab.lexema = strdup(lexema);
            tab.token = strdup(token);
            li = insere(li, tab);
            lexema[0] = '\0';
            estado = 0;
            break;
        case 23:
            volta_char(farq);
            strcpy(token, TOKMUL[1]);
            printf("%d \t%s   \t %s\n", linha, lexema, token);
            fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            tab.linha = linha;
            tab.lexema = strdup(lexema);
            tab.token = strdup(token);
            li = insere(li, tab);
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
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
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
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKSOATR[0]) == 0)
            {
                strcpy(token, TOKSOATR[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
                lexema[0] = '\0';
                estado = 0;
            }
            else if (strcmp(lexema, TOKPLUS[0]) == 0)
            {
                strcpy(token, TOKPLUS[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
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
            tab.linha = linha;
            tab.lexema = strdup(lexema);
            tab.token = strdup(token);
            li = insere(li, tab);
            lexema[0] = '\0';
            estado = 0;
            verifica = 1;
            break;

        case 53:
            volta_char(farq);
            strcpy(token, TOKAND[1]);
            printf("%d \t%s   \t %s\n", linha, lexema, token);
            fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            tab.linha = linha;
            tab.lexema = strdup(lexema);
            tab.token = strdup(token);
            li = insere(li, tab);
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
            tab.linha = linha;
            tab.lexema = strdup(lexema);
            tab.token = strdup(token);
            li = insere(li, tab);
            lexema[0] = '\0';
            estado = 0;
            verifica = 1;
            break;

        case 56:
            volta_char(farq);
            strcpy(token, TOKORBIT[1]);
            printf("%d \t%s   \t %s\n", linha, lexema, token);
            fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            tab.linha = linha;
            tab.lexema = strdup(lexema);
            tab.token = strdup(token);
            li = insere(li, tab);
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
            tab.linha = linha;
            tab.lexema = strdup(lexema);
            tab.token = strdup(token);
            li = insere(li, tab);
            lexema[0] = '\0';
            estado = 0;
            break;
        }
        case 48:
            volta_char(farq);
            strcpy(token, TOKDIV[1]);
            printf("%d \t%s   \t %s\n", linha, lexema, token);
            fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            tab.linha = linha;
            tab.lexema = strdup(lexema);
            tab.token = strdup(token);
            li = insere(li, tab);
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
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
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
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
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
            tab.linha = linha;
            tab.lexema = strdup(lexema);
            tab.token = strdup(token);
            li = insere(li, tab);
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
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
            }
            else if (strcmp(lexema, TOKPS_FECHADO[0]) == 0)
            {
                strcpy(token, TOKPR_FECHADO[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
            }
            else if (strcmp(lexema, TOKCH_ABERTO[0]) == 0)
            {
                strcpy(token, TOKCH_ABERTO[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
            }
            else if (strcmp(lexema, TOKCH_FECHADO[0]) == 0)
            {
                strcpy(token, TOKCH_FECHADO[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
            }
            else if (strcmp(lexema, TOKPR_ABERTO[0]) == 0)
            {
                strcpy(token, TOKPR_ABERTO[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
            }
            else if (strcmp(lexema, TOKPR_FECHADO[0]) == 0)
            {
                strcpy(token, TOKPR_FECHADO[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
            }
            else if (strcmp(lexema, TOKVIRGULA[0]) == 0)
            {
                strcpy(token, TOKVIRGULA[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
            }
            else if (strcmp(lexema, TOKPVIRGULA[0]) == 0)
            {
                strcpy(token, TOKPVIRGULA[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
            }
            else if (strcmp(lexema, TOKBITCATR[0]) == 0)
            {
                strcpy(token, TOKBITCATR[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
            }
            else if (strcmp(lexema, TOKCOM[0]) == 0)
            {
                strcpy(token, TOKCOM[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
            }
            else if (strcmp(lexema, TOKOREX[0]) == 0)
            {
                strcpy(token, TOKOREX[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
            }
            else if (strcmp(lexema, TOKPERCENT[0]) == 0)
            {
                strcpy(token, TOKPERCENT[1]);
                printf("%d \t%s   \t %s\n", linha, lexema, token);
                fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
                tab.linha = linha;
                tab.lexema = strdup(lexema);
                tab.token = strdup(token);
                li = insere(li, tab);
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
            tab.linha = linha;
            tab.lexema = strdup(lexema);
            tab.token = strdup(token);
            li = insere(li, tab);
            lexema[0] = '\0';
            estado = 0;
            break;
        case 68:
            volta_char(farq);
            strcpy(token, "TOKPONTO");
            printf("%d \t%s   \t %s\n", linha, lexema, token);
            fprintf(pont_arq, "%d %s %s\n", linha, lexema, token);
            tab.linha = linha;
            tab.lexema = strdup(lexema);
            tab.token = strdup(token);
            li = insere(li, tab);
            lexema[0] = '\0';
            estado = 0;
            break;
        default:
            break;
        }
    }
    fclose(farq);
    fclose(pont_arq);
    return li;
}

//------------------------------------------------------Sintatico-------------------------------------------------------------//

Lista *init()
{
    Lista *li = malloc(sizeof(Lista));
    li->prox = NULL;
    return li;
}

Lista *insere(Lista *li, Lex tab)
{
    Lista *novo = init();
    Lista *aux = li;
    novo->tab = tab;

    if (aux == NULL)
    {
        li = novo;
    }
    else
    {
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    return li;
}

void imp(Lista *li)
{
    Lista *aux = li;

    while (aux != NULL)
    {
        printf("%s %s\n", aux->tab.lexema, aux->tab.token);
        aux = aux->prox;
    }
}

/*

Lista *digital(Lista *li)
{
    FILE *pont_arq;
    pont_arq = fopen("LexTable.txt", "r");
    Lex tab;

    const char s[2] = " ";
    char *token;
    char s1[200];
    char s2[200];
    char s3[200];

    while (fscanf(pont_arq, "%s %s %s", s1, s2, s3) != EOF)
    {

        tab.linha = strdup(s1);

        tab.lexema = strdup(s2);

        tab.token = strdup(s3);

        li = insere(li, tab);
    }
    return li;
}*/

void sintatico(Lista *li)
{

    imp(li);
    program(li);
}

void program(Lista *li)
{

    while (li != NULL)
    {
        li = functions(li);
        li = li->prox;
    }

    printf("Verificacao completa\n");
}

Lista *functions(Lista *li)
{

    if (
        strcmp(li->tab.token, "TOKIDENTIFICADOR") == 0 || strcmp(li->tab.lexema, "int") == 0 ||
        strcmp(li->tab.lexema, "char") == 0 || strcmp(li->tab.lexema, "float") == 0 ||
        strcmp(li->tab.lexema, "void") == 0 || strcmp(li->tab.lexema, "double") == 0)
    {

        li = external(li);
        li = functions(li);
    }

    return li;
}

Lista *external(Lista *li)
{

    if (strcmp(li->tab.token, "TOKIDENTIFICADOR") == 0)
    {
        li = li->prox;
        li = func(li);
    }
    else
    {
        li = type(li);
        li = restoextern(li);
    }
    return li;
}

Lista *restoextern(Lista *li)
{
    if (strcmp(li->tab.token, "TOKIDENTIFICADOR") == 0)
    {
        li = li->prox;
        li = restoextern2(li);
    }
    else
    {
        printf("restoextern\n");
        if (strcmp(li->tab.lexema, "*") != 0)
        {
            printf("Esperava \"*\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
        if (strcmp(li->tab.token, "TOKIDENTIFICADOR") != 0)
        {
            printf("Esperava \"IDENTIFICADOR\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
        li = restovars(li);
    }
    return li;
}
Lista *type(Lista *li)
{

    if (
        strcmp(li->tab.lexema, "int") == 0 || strcmp(li->tab.lexema, "char") == 0 ||
        strcmp(li->tab.lexema, "float") == 0 || strcmp(li->tab.lexema, "void") == 0 ||
        strcmp(li->tab.lexema, "double") == 0)
    {
        li = li->prox;
        return li;
    }
}
Lista *dcls(Lista *li)
{
    if (strcmp(li->tab.lexema, "char") == 0 || strcmp(li->tab.lexema, "int") == 0 || strcmp(li->tab.lexema, "void") == 0 || strcmp(li->tab.lexema, "double") == 0)
    {
        li = var(li);
        li = dcls(li);
    }
    return li;
}
Lista *func(Lista *li)
{

    li = f_args(li);

    if (strcmp(li->tab.lexema, "{") != 0)
    {
        printf("Esperava \"{\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
    }
    else
        li = li->prox;

    li = dcls(li);
    li = stmts(li);
    if (strcmp(li->tab.lexema, "}") != 0)
    {
        printf("Esperava \"}\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
    }
    else
        li = li->prox;
    return li;
}
Lista *f_args(Lista *li)
{
    if (strcmp(li->tab.lexema, "(") != 0)
    {
        printf("ArgsAqui");
        printf("Esperava \"(\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
    }
    else
        li = li->prox;
    li = restof_args(li);
    return li;
}
Lista *restof_args(Lista *li)
{
    if (strcmp(li->tab.lexema, ")") == 0)
    {
        li = li->prox;
    }
    else
    {
        li = args(li);
        if (strcmp(li->tab.lexema, ")") != 0)
        {
            printf("Esperava \")\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
    }
    return li;
}
Lista *args(Lista *li)
{
    li = type(li);
    li = dclr(li);
    li = restot_args(li);
    return li;
}
Lista *restoextern2(Lista *li)
{

    if (strcmp(li->tab.lexema, "(") == 0)
        li = func(li);
    else
    {
        li = restodclr(li);
        li = restovars(li);
    }
    return li;
}

Lista *restovars(Lista *li)
{

    if (strcmp(li->tab.lexema, ",") == 0)
    {
        li = li->prox;
        li = dclr(li);
        li = restovars(li);
    }
    else
    {
        if (strcmp(li->tab.lexema, ";") != 0)
        {
            printf("Restovars\n");
            printf("Esperava \";\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
    }
    return li;
}

Lista *var(Lista *li)
{
    li = type(li);
    li = dclr(li);
    li = restovars(li);
    return li;
}

Lista *stmts(Lista *li)
{
    if (strcmp(li->tab.lexema, "if") == 0 || strcmp(li->tab.lexema, "while") == 0 || strcmp(li->tab.lexema, "for") == 0 || strcmp(li->tab.lexema, "return") == 0 ||
        strcmp(li->tab.lexema, "break") == 0 || strcmp(li->tab.lexema, "continue") == 0 || strcmp(li->tab.lexema, ";") == 0 || strcmp(li->tab.lexema, "!=") == 0 ||
        strcmp(li->tab.lexema, "&") == 0 || strcmp(li->tab.lexema, "*") == 0 || strcmp(li->tab.lexema, "-") == 0 || strcmp(li->tab.lexema, "+") == 0 ||
        strcmp(li->tab.lexema, "~") == 0 || strcmp(li->tab.lexema, "++") == 0 || strcmp(li->tab.lexema, "--") == 0 || strcmp(li->tab.token, "TOKIDENTIFICADOR") == 0 ||
        strcmp(li->tab.lexema, "(") == 0 || strcmp(li->tab.token, "TOK_NFLOAT") == 0 || strcmp(li->tab.token, "TOK_NINT") == 0 || strcmp(li->tab.token, "TOKSTRING") == 0 ||
        strcmp(li->tab.lexema, "{"))
    {
        li = stmt(li);
        li = stmts(li);
    }
    return li;
}

Lista *stmt(Lista *li)
{
    if (strcmp(li->tab.lexema, "if") == 0)
    {
        li = li->prox;
        if (strcmp(li->tab.lexema, "(") != 0)
        {
            printf("stmtAqui");
            printf("Esperava \"(\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
        li = expro(li);
        if (strcmp(li->tab.lexema, ")") != 0)
        {
            printf("Esperava \")\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
        li = stmt(li);
        li = restoif(li);
    }
    else if (strcmp(li->tab.lexema, "while") == 0)
    {
        li = li->prox;
        if (strcmp(li->tab.lexema, "(") != 0)
        {
            printf("whileAqui");
            printf("Esperava \"(\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
        li = expro(li);
        if (strcmp(li->tab.lexema, ")") == 0)
        {
            printf("Esperava \")\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
        li = stmt(li);
    }
    else if (strcmp(li->tab.lexema, "for") == 0)
    {

        li = li->prox;
        if (strcmp(li->tab.lexema, "(") != 0)
        {
            printf("forAqui");
            printf("Esperava \"(\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
        li = expro(li);
        if (strcmp(li->tab.lexema, ";") != 0)
        {
            printf("Esperava \";\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
        li = expro(li);
        if (strcmp(li->tab.lexema, ";") != 0)
        {
            printf("Esperava \";\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
        li = expro(li);

        if (strcmp(li->tab.lexema, ")") != 0)
        {
            printf("Esperava \")\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;

        li = stmt(li);
    }
    else if (strcmp(li->tab.lexema, "return") == 0)
    {
        li = li->prox;
        li = restoreturn(li);
    }
    else if (strcmp(li->tab.lexema, "break") == 0)
    {
        li = li->prox;
        if (strcmp(li->tab.lexema, ";") != 0)
        {
            printf("Esperava \";\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
    }
    else if (strcmp(li->tab.lexema, "continue") == 0)
    {
        li = li->prox;
        if (strcmp(li->tab.lexema, ";") != 0)
        {
            printf("Esperava \";\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
    }
    else if (strcmp(li->tab.lexema, "{") == 0)
    {
        li = block(li);
    }
    else if (strcmp(li->tab.lexema, ";") == 0)
    {
        li = li->prox;
    }
    else
    {
        li = expr(li);
        if (strcmp(li->tab.lexema, ";") != 0)
        {
            printf("Esperava \";\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
    }
    return li;
}

Lista *expro(Lista *li)
{
    if (strcmp(li->tab.lexema, "!") == 0 || strcmp(li->tab.lexema, "&") == 0 || strcmp(li->tab.lexema, "*") == 0 || strcmp(li->tab.lexema, "-") == 0 ||
        strcmp(li->tab.lexema, "+") == 0 || strcmp(li->tab.lexema, "~") == 0 || strcmp(li->tab.lexema, "++") == 0 || strcmp(li->tab.lexema, "--") == 0 ||
        strcmp(li->tab.token, "TOKIDENTIFICADOR") == 0 || strcmp(li->tab.lexema, "(") == 0 || strcmp(li->tab.token, "TOK_NINT") == 0 || strcmp(li->tab.token, "TOK_NFLOAT") == 0 ||
        strcmp(li->tab.token, "TOKSTRING") == 0 || strcmp(li->tab.lexema, "&&") == 0 || strcmp(li->tab.lexema, "||") == 0)
    {
        li = expr(li);
    }
    return li;
}
Lista *restoreturn(Lista *li)
{
    if (strcmp(li->tab.lexema, ";") == 0)
    {
        li = li->prox;
    }
    else
    {
        li = expr(li);
        if (strcmp(li->tab.lexema, ";") != 0)
        {

            printf("Esperava \";\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
    }
    return li;
}

Lista *block(Lista *li)
{
    if (strcmp(li->tab.lexema, "{") != 0)
    {
        printf("Esperava \"{\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
    }
    else
        li = li->prox;
    li = stmts(li);
    if (strcmp(li->tab.lexema, "}") != 0)
    {
        printf("Esperava \"}\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
    }
    else
        li = li->prox;
    return li;
}
Lista *restoif(Lista *li)
{
    if (strcmp(li->tab.lexema, "else") == 0)
    {
        li = li->prox;
        li = stmt(li);
    }
    return li;
}

Lista *dclr(Lista *li)
{
    if (strcmp(li->tab.token, "TOKIDENTIFICADOR") == 0)
    {
        li = li->prox;
        li = restodclr(li);
    }
    else
    {
        if (strcmp(li->tab.lexema, "*") != 0)
        {
            printf("Esperava \"*\" na Linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
        if (strcmp(li->tab.token, "TOKIDENTIFICADOR") != 0)
        {
            printf("Esperava \"IDENTIFICADOR\" na Linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
    }
    return li;
}

Lista *restot_args(Lista *li)
{
    if (strcmp(li->tab.lexema, ",") == 0)
    {
        li = li->prox;
        li = args(li);
    }
    return li;
}

Lista *restodclr(Lista *li)
{
    if (strcmp(li->tab.lexema, "[") == 0)
    {
        li = li->prox;
        li = restodclr2(li);
    }
    return li;
}

Lista *restodclr2(Lista *li)
{
    if (strcmp(li->tab.lexema, "]") == 0)
    {
        li = li->prox;
    }
    else
    {
        if (strcmp(li->tab.token, "TOK_NINT") != 0)
        {
            printf("Esperava \"INT\" na Linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
        if (strcmp(li->tab.lexema, "]") != 0)
        {
            printf("Esperava \"]\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
    }
    return li;
}

Lista *expr(Lista *li)
{

    li = restoexpr(li, _or(li));
    return li;
}

Lista *exprs(Lista *li)
{
    li = expr(li);
    li = restoexprs(li);
    return li;
}

Lista *restoexprs(Lista *li)
{
    if (strcmp(li->tab.lexema, ",") == 0)
    {
        li = li->prox;
        li = exprs(li);
    }
    return li;
}

Lista *restoexpr(Lista *li, bool lval)
{
    if (strcmp(li->tab.lexema, "==") == 0)
    {
        if (lval)
        {
            li = li->prox;
            li = expr(li);
        }
    }
    return li;
}

Lista *restofator2(Lista *li)
{
    if (strcmp(li->tab.lexema, ")") == 0)
    {
        li = li->prox;
    }
    else
    {
        li = exprs(li);
        if (strcmp(li->tab.lexema, ")") != 0)
        {
            printf("Esperava \")\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
    }
    return li;
}
Lista *restolval(Lista *li)
{
    if (strcmp(li->tab.lexema, "[") == 0)
    {
        li = li->prox;
        expr(li);
        if (strcmp(li->tab.lexema, "]") != 0)
        {
            printf("Esperava \"]\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
    }
    return li;
}
bool _or(Lista *li)
{
    bool e1 = _and(li);
    bool e2 = restoor(li);
    return e1 && e2;
}

bool restoor(Lista *li)
{
    if (strcmp(li->tab.lexema, "||") == 0)
    {
        li = li->prox;
        _or(li);
        return false;
    }
    else
    {
        return true;
    }
}

bool _and(Lista *li)
{
    bool e1 = _not(li);
    bool e2 = restoand(li);
    return e1 && e2;
}

bool restoand(Lista *li)
{
    if (strcmp(li->tab.lexema, "&") == 0)
    {
        li = li->prox;
        _and(li);
        return false;
    }
    else
    {
        return true;
    }
}

bool _not(Lista *li)
{
    if (strcmp(li->tab.lexema, "!") == 0)
    {
        li = li->prox;
        _not(li);
        return false;
    }
    else
    {
        return cfator(li);
    }
}

bool cfator(Lista *li)
{
    bool e1 = orbin(li);
    bool e2 = restocfator(li);
    return e1 && e2;
}

bool restocfator(Lista *li)
{
    if (strcmp(li->tab.lexema, "="))
    {
        li = li->prox;
        orbin(li);
        return false;
    }
    else if (strcmp(li->tab.lexema, "!") == 0)
    {
        li = li->prox;
        orbin(li);
        return false;
    }
    else if (strcmp(li->tab.lexema, "-=") == 0)
    {
        li = li->prox;
        orbin(li);
        return false;
    }
    else if (strcmp(li->tab.lexema, ">=") == 0)
    {
        li = li->prox;
        orbin(li);
        return false;
    }
    else if (strcmp(li->tab.lexema, "<") == 0)
    {
        li = li->prox;
        orbin(li);
        return false;
    }
    else if (strcmp(li->tab.lexema, ">") == 0)
    {
        li = li->prox;
        orbin(li);
        return false;
    }
    else
    {

        return true;
    }
}

bool orbin(Lista *li)
{
    bool e1 = xorbin(li);
    bool e2 = restoorbin(li);
    return e1 && e2;
}
bool restoorbin(Lista *li)
{
    if (strcmp(li->tab.lexema, "||") == 0)
    {
        li = li->prox;
        xorbin(li);
        restoorbin(li);
        return false;
    }
    else
    {

        return true;
    }
}

bool xorbin(Lista *li)
{
    bool r1 = andbin(li);
    bool r2 = restoxorbin(li);
    return r1 && r2;
}

bool restoxorbin(Lista *li)
{
    if (strcmp(li->tab.lexema, "^") == 0)
    {
        li = li->prox;
        andbin(li);
        restoxorbin(li);
        return false;
    }
    else
    {
        return true;
    }
}

bool andbin(Lista *li)
{
    bool r1 = rola(li);
    bool r2 = restoandbin(li);
    return r1 && r2;
}

bool restoandbin(Lista *li)
{
    if (strcmp(li->tab.lexema, "&&") == 0)
    {
        li = li->prox;
        rola(li);
        restoandbin(li);
        return false;
    }
    else
    {
        return true;
    }
}

bool rola(Lista *li)
{
    bool r1 = soma(li);
    bool r2 = restorola(li);
    return r1 && r2;
}

bool restorola(Lista *li)
{
    if (strcmp(li->tab.lexema, "<<") == 0)
    {

        li = li->prox;
        soma(li);
        restorola(li);
        return false;
    }
    else if (strcmp(li->tab.lexema, "&&") == 0)
    {
        li = li->prox;
        soma(li);
        restorola(li);
        return false;
    }
    else
    {
        return true;
    }
}

bool soma(Lista *li)
{
    bool r1 = mult(li);
    bool r2 = restosoma(li);
    return r1 && r2;
}

bool restosoma(Lista *li)
{
    if (strcmp(li->tab.lexema, "+") == 0)
    {
        li = li->prox;
        mult(li);
        restosoma(li);
        return false;
    }
    else if (strcmp(li->tab.lexema, "-") == 0)
    {
        li = li->prox;
        mult(li);
        restosoma(li);
        return false;
    }
    else
    {
        return true;
    }
}

bool mult(Lista *li)
{
    bool r1 = ender(li);
    bool r2 = restomult(li);
    return r1 && r2;
}

bool restomult(Lista *li)
{
    if (strcmp(li->tab.lexema, "*") == 0)
    {
        li = li->prox;
        bool r1 = ender(li);
        bool r2 = restomult(li);
        return r1 && r2;
    }
    else if (strcmp(li->tab.lexema, "/") == 0)
    {
        li = li->prox;
        ender(li);
        restomult(li);
        return false;
    }
    else if (strcmp(li->tab.lexema, "%") == 0)
    {
        li = li->prox;
        ender(li);
        restomult(li);
        return false;
    }
    else
    {

        return true;
    }
}

bool ender(Lista *li)
{
    if (strcmp(li->tab.lexema, "&&") == 0)
    {
        li = li->prox;
        lval(li);
        return false;
    }
    else if (strcmp(li->tab.lexema, "*") == 0)
    {
        bool error;
        li = li->prox;
        error = ender(li);

        return error;
    }
    else
    {
        return uno(li);
    }
}

bool uno(Lista *li)
{
    if (strcmp(li->tab.lexema, "-") == 0)
    {
        li = li->prox;
        uno(li);
        return false;
    }
    else if (strcmp(li->tab.lexema, "+") == 0)
    {
        li = li->prox;
        uno(li);
        return false;
    }
    else
    {
        return notbin(li);
    }
}

bool notbin(Lista *li)
{
    if (strcmp(li->tab.lexema, "~") == 0)
    {
        li = li->prox;
        notbin(li);
        return false;
    }
    else
    {
        return incpre(li);
    }
}

Lista *lval(Lista *li)
{
    if (strcmp(li->tab.token, "TOKIDENTIFICADOR") == 0)
    {
        li = li->prox;
        li = restolval(li);
    }
    else
    {
        if (strcmp(li->tab.lexema, "*") != 0)
        {
            printf("Esperava \"*\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
        if (strcmp(li->tab.token, "TOKIDENTIFICADOR") != 0)
        {
            printf("Esperava \"IDENTIFICADOR\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
    }
    return li;
}

bool incpre(Lista *li)
{
    if (strcmp(li->tab.lexema, "++") == 0)
    {
        li = li->prox;
        lval(li);
        return true;
    }
    else if (strcmp(li->tab.lexema, "--") == 0)
    {
        li = li->prox;
        lval(li);
        return true;
    }
    else
    {
        return incpos(li);
    }
}

bool incpos(Lista *li)
{
    bool retorno = fator(li);
    restoincpos(li);
    return retorno;
}

Lista *restoincpos(Lista *li)
{
    if (strcmp(li->tab.lexema, "--") == 0)
    {
        li = li->prox;
    }
    else if (strcmp(li->tab.lexema, "++") == 0)
    {
        li = li->prox;
    }
    return li;
}

bool fator(Lista *li)
{
    if (strcmp(li->tab.token, "TOKSTRING") == 0)
    {
        li = li->prox;
        return false;
    }
    else if (strcmp(li->tab.lexema, "(") == 0)
    {
        li = li->prox;
        li = expr(li);
        if (strcmp(li->tab.lexema, ")") != 0)
        {
            printf("Esperava \")\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
        return false;
    }
    else if (strcmp(li->tab.token, "TOK_NINT") == 0)
    {
        li = li->prox;
        return false;
    }
    else if (strcmp(li->tab.token, "TOK_NFLOAT") == 0)
    {
        li = li->prox;
        return false;
    }
    else
    {
        if (strcmp(li->tab.token, "TOKIDENTIFICADOR") != 0)
        {
            printf("Esperava \"IDENTIFICADOR\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
        return restofator1(li);
    }
}

bool restofator1(Lista *li)
{
    if (strcmp(li->tab.lexema, "[") == 0)
    {
        li = li->prox;
        li = expr(li);
        if (strcmp(li->tab.lexema, "]") != 0)
        {
            printf("Esperava \"]\" na linha %d , Mas encontrou-se %s\n", li->tab.linha,li->tab.lexema);
        }
        else
            li = li->prox;
        return true;
    }
    else if (strcmp(li->tab.lexema, "(") == 0)
    {
        li = li->prox;
        li = restofator2(li);
        return false;
    }
    else
    {
        return true;
    }
}
