#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "parser.h"

struct err
{
    char token[50];
    char lexema[50];
    char *linha;
};
struct error
{
    erro tab;
    struct error *prox;
    /* data */
};
struct lex
{
    char *token;
    char *lexema;
    char *linha;
};
struct lista
{
    Lex tab;
    struct lista *prox;
    /* data */
};

LError *Erros = NULL;

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

        /* code */
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
        printf("%s\n", aux->tab.token);
        aux = aux->prox;
    }
}

LError *initError()
{
    LError *li = malloc(sizeof(LError));
    li->prox = NULL;
    return li;
}

LError *insereError(LError *li, erro tab)
{
    LError *novo = initError();
    LError *aux = li;
    novo->tab = tab;

    if (aux == NULL)
    {
        li = novo;

        /* code */
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

void impError(LError *li)
{
    LError *aux = li;

    while (aux != NULL)
    {
        printf("%s %s %s\n", aux->tab.linha, aux->tab.lexema, aux->tab.token);
        aux = aux->prox;
    }
}

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
}

void sintatico()
{
    Lista *li = NULL;
    li = digital(li);
    //imp(li);
    program(li);
}

void program(Lista *li)
{
    li = functions(li);

    if (li == NULL)
        printf("Verificacao completa\n");
    else
        printf("Verificacao incompleta\n");
}

Lista *functions(Lista *li)
{
    printf(" functions %s\n", li->tab.lexema);
    if (strcmp(li->tab.token, "TOKIDENTIFICADOR") == 0 || strcmp(li->tab.lexema, "int") == 0 || strcmp(li->tab.lexema, "char") == 0 || strcmp(li->tab.lexema, "float") == 0 || strcmp(li->tab.lexema, "void") == 0 || strcmp(li->tab.lexema, "double") == 0)
    {

        li = external(li);
        li = functions(li);
    }
    return li;
}

Lista *external(Lista *li)
{
    printf("external %s\n", li->tab.lexema);
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
Lista *type(Lista *li)
{
    printf("type %s\n", li->tab.lexema);
    if (strcmp(li->tab.lexema, "int") == 0 || strcmp(li->tab.lexema, "char") == 0 || strcmp(li->tab.lexema, "float") == 0 || strcmp(li->tab.lexema, "Lista *") == 0 || strcmp(li->tab.lexema, "double") == 0)
    {
        li = li->prox;
        return li;
    }
    
}
Lista *func(Lista *li)
{

    printf("func %s\n", li->tab.lexema);
    li = f_args(li);
    if (strcmp(li->tab.lexema, "{") != 0)
    {
        printf("Esperava \"{\" na linha %s\n", li->tab.linha);
        li = li->prox;
    }
    else
        li = li->prox;

    li = dcls(li);
    li = stmts(li);
    if (strcmp(li->tab.lexema, "}") != 0)
    {
        printf("Esperava \"}\" na linha %s\n", li->tab.linha);
        li = li->prox;
    }
    else
        li = li->prox;
    return li;
}

Lista *restoextern(Lista *li)
{
    printf("restoextern %s\n", li->tab.lexema);
    if (strcmp(li->tab.token, "TOKIDENTIFICADOR") == 0)
    {
        li = li->prox;
        li = restoextern2(li);
    }
    else
    {
        if (strcmp(li->tab.lexema, "*") != 0)
        {
            printf("Esperava \"*\" na linha %s\n", li->tab.linha);

            li = li->prox;
        }
        else
            li = li->prox;
        if (strcmp(li->tab.token, "TOKIDENTIFICADOR") != 0)
        {
            printf("Esperava \"IDENTIFICADOR\" na linha %s\n", li->tab.linha);
            li = li->prox;
        }
        else
            li = li->prox;
        li = restovars(li);
    }
    return li;
}

Lista *restoextern2(Lista *li)
{
    printf("restoextern2 %s\n", li->tab.lexema);
    if (strcmp(li->tab.lexema, "{") == 0)
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
    printf("restovars %s\n", li->tab.lexema);
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
            printf("Aqui\n");
            printf("Esperava \";\" na linha %s\n", li->tab.linha);
            li = li->prox;
        }
        else
            li = li->prox;
    }
    return li;
}

Lista *funct(Lista *li)
{

    li = f_args(li);
    if (strcmp(li->tab.lexema, "}") != 0)
    {
        li = li->prox;
    }
    else
    {
        printf("Esperava \"{\" na linha %s\n", li->tab.linha);
        li = li->prox;
    }

    li = dcls(li);
    li = stmts(li);
    if (strcmp(li->tab.lexema, "}") != 0)
    {
        printf("Esperava \"}\" na linha %s\n", li->tab.linha);
        li = li->prox;
    }
    else
        li = li->prox;
    return li;
}

Lista *dcls(Lista *li)
{
    if (strcmp(li->tab.lexema, "char") == 0 || strcmp(li->tab.lexema, "int") == 0 || strcmp(li->tab.lexema, "Lista *") == 0 || strcmp(li->tab.lexema, "double") == 0)
    {
        li = var(li);
        li = dcls(li);
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

Lista *stmt(Lista *li)
{
    if (strcmp(li->tab.lexema, "if") == 0)
    {
        li = li->prox;
        if (strcmp(li->tab.lexema, "(") != 0)
        {
            printf("Esperava \"(\" na linha %s\n", li->tab.linha);
            li = li->prox;
        }
        else
            li = li->prox;
        li = expro(li);
        if (strcmp(li->tab.lexema, ")") != 0)
        {
            printf("Esperava \")\" na linha %s\n", li->tab.linha);
            li = li->prox;
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
            printf("Esperava \"(\" na linha %s\n", li->tab.linha);
            li = li->prox;
        }
        else
            li = li->prox;
        li = expro(li);
        if (strcmp(li->tab.lexema, ")") == 0)
        {
            printf("Esperava \")\" na linha %s\n", li->tab.linha);
            li = li->prox;
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
            printf("Esperava \"(\" na linha %s\n", li->tab.linha);
            li = li->prox;
        }
        else
            li = li->prox;
        li = expro(li);
        if (strcmp(li->tab.lexema, ";") != 0)
        {
            printf("Esperava \";\" na linha %s\n", li->tab.linha);
            li = li->prox;
        }
        else
            li = li->prox;
        li = expro(li);
        if (strcmp(li->tab.lexema, ";") != 0)
        {
            printf("Esperava \";\" na linha %s\n", li->tab.linha);
            li = li->prox;
        }
        else
            li = li->prox;
        li = expro(li);

        if (strcmp(li->tab.lexema, ")") != 0)
        {
            printf("Esperava \")\" na linha %s\n", li->tab.linha);
            li = li->prox;
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
            printf("Esperava \";\" na linha %s\n", li->tab.linha);
            li = li->prox;
        }
        else
            li = li->prox;
    }
    else if (strcmp(li->tab.lexema, "continue") == 0)
    {
        li = li->prox;
        if (strcmp(li->tab.lexema, ";") != 0)
        {
            printf("Esperava \";\" na linha %s\n", li->tab.linha);
            li = li->prox;
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
            printf("Esperava \";\" na linha %s\n", li->tab.linha);
            li = li->prox;
        }
        else
            li = li->prox;
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
            printf("Esperava \";\" na linha %s\n", li->tab.linha);
            li = li->prox;
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
        printf("Esperava \")\" na linha %s\n", li->tab.linha);
        li = li->prox;
    }
    else
        li = li->prox;
    li = stmts(li);
    if (strcmp(li->tab.lexema, "}") != 0)
    {
        printf("Esperava \")\" na linha %s\n", li->tab.linha);
        li = li->prox;
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

Lista *f_args(Lista *li)
{
    if (strcmp(li->tab.lexema, "(") != 0)
    {
        printf("Esperava \"(\" na linha %s\n", li->tab.linha);
        li = li->prox;
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
        li = li->prox;

        li = args(li);
        if (strcmp(li->tab.lexema, ")") != 0)
        {
            printf("Esperava \")\" na linha %s\n", li->tab.linha);
            li = li->prox;
        }
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
Lista *dclr(Lista *li)
{
    if (strcmp(li->tab.lexema, "TOKIDENTIFICADOR") == 0)
    {
        li = li->prox;
        li = restodclr(li);
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
        if (strcmp(li->tab.token, "TOK_NINT") == 0)
        {
            li = li->prox;
        }
        else
        {
            printf("Esperava \"]\" na linha %s\n", li->tab.linha);
            li = li->prox;
        }
    }
    return li;
}

Lista *expr(Lista *li)
{

    li = restoexpr(li, or (li));
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
            printf("Esperava \")\" na linha %s\n", li->tab.linha);
            li = li->prox;
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
            printf("Esperava \"]\" na linha %s\n", li->tab.linha);
            li = li->prox;
        }
        else
            li = li->prox;
    }
    return li;
}
bool or (Lista * li)
{
    bool e1 = and(li);
    bool e2 = restoor(li);
    return e1 && e2;
}

bool restoor(Lista *li)
{
    if (strcmp(li->tab.lexema, "||") == 0)
    {
        li = li->prox;
        or (li);
        return false;
    }
    else
    {
        return true;
    }
}

bool and (Lista * li)
{
    bool e1 = not(li);
    bool e2 = restoand(li);
    return e1 && e2;
}

bool restoand(Lista *li)
{
    if (strcmp(li->tab.lexema, "&") == 0)
    {
        li = li->prox;
        and(li);
        return false;
    }
    else
    {
        return true;
    }
}

bool not(Lista * li)
{
    if (strcmp(li->tab.lexema, "!") == 0)
    {
        li = li->prox;
        not(li);
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
            printf("Esperava \"*\" na linha %s\n", li->tab.linha);
            li = li->prox;
        }
        else
            li = li->prox;
        if (strcmp(li->tab.token, "TOKIDENTIFICADOR") != 0)
        {
            printf("Esperava \"IDENTIFICADOR\" na linha %s\n", li->tab.linha);
            li = li->prox;
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
            printf("Esperava \"]\" na linha %s\n", li->tab.linha);
            li = li->prox;
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
            printf("Esperava \"IDENTIFICADOR\" na linha %s\n", li->tab.linha);
            li = li->prox;
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
            printf("Esperava \"]\" na linha %s\n", li->tab.linha);
            li = li->prox;
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