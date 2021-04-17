#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

struct tab
{
    /* data */
    char *lexema;
    char *token;
    struct tab *prox;
};
void criar(tabela *Table)
{
    Table = (tabela *)malloc(sizeof(tabela));
}

void add(tabela *Table, char *Lexema, char *Token)
{
    tabela *aux = (tabela *)malloc(sizeof(tabela));
    if (Table == NULL)
    {
        Table->lexema = Lexema;
        Table->token = Token;
        Table->prox = NULL;
    }
    else
    {
        aux = Table;

        while (aux!=NULL)
        {
            aux=aux->prox;
        }
        aux->lexema = Lexema;
        aux->token = Token;

    }
}



