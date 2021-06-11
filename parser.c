#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "functions.h"
//#include "tokens.c"

void sintatico()
{
    FILE *pont_arq;
    pont_arq = fopen("LexTable.txt", "r");
    char token[50];
    char lexema[50];
    char linha[50];

    while (fscanf(pont_arq, "%s ",lexema) != EOF)
    {

        printf("%s\n", lexema);
    }
}