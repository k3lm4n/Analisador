#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct err
{
    char *token;
    char *lexema;
    char *linha;
} erro;
typedef struct error
{
    erro tab;
    struct error *prox;
    /* data */
} LError;
typedef struct lex
{
    char *token;
    char *lexema;
    char *linha;
} Lex;
typedef struct lista
{
    Lex tab;
    struct lista *prox;
    /* data */
} Lista;

LError* Erros = NULL;

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
        printf("%s %s %s\n", aux->tab.linha, aux->tab.lexema, aux->tab.token);
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
    imp(li);
}
void program(Lista *li)
{
    int par = 0;
    if (strcmp(li->tab.lexema, "{") == 0)
    {
        par++;
        li = li->prox;
    }
    external_declaration(li);
    if (par > 0)
    {
        if (strcmp(li->tab.lexema, "}") == 0)
        {

            li = li->prox;
        }
        else
        {
        }
    }
}
void external_declaration(Lista *li)
{
    if (strcmp() || strcmp() || strcmp() || strcmp() || strcmp() || strcmp())
    {
        function_definition(li);
    }
    else if ()
    {
        declaration(li);
    }
}
void function_definition(Lista *li)
{
    if ()
    {

        declaration_specifier(li);
        declarator(li);
        declaration(li);
    }
}

void declaration_specifier(Lista *li)
{
    if ()
    {
        storage_class_specifier(li);
    }
    else if ()
    {
        type_specifier(li);
    }
    else if ()
    {
        type_qualifier(li);
    }
}
void storage_class_specifier(Lista *li)
{
    if ("auto")
    {
    }
    else if ("resgister")
    {
    }
    else if ("static")
    {
    }
    else if ("extern")
    {
    }
    else if ("typedef")
    {
    }
}

void type_specifier(Lista *li)
{
    if ("void")
    {
    }
    else if ("char")
    {
    }
    else if ("short")
    {
    }
    else if ("int")
    {
    }
    else if ("long")
    {
    }
    else if ("float")
    {
    }
    else if ("double")
    {
    }
    else if ("signed")
    {
    }
    else if ("unsigned")
    {
    }
    else if ()
    {
        struct_or_union_specifier(li);
    }
    else if ()
    {
        enum_specifier(li);
    }
    else if ()
    {
        typedef_name(li);
    }
}

void struct_or_union_specifier(Lista *li)
{
    struct_or_union(li);
    struct_or_union_specifier1(li);
}
void struct_or_union_specifier1(Lista *li)
{
    if ()
    {
        //tokenidentifier();
        //chave aberta
        struct_or_union_specifier2(li);
        //+
        //chave fechada
    }
}
void struct_or_union2(Lista *li)
{
    if ()
    {
        //chave aberta
        struct_declaration(li);
        //+
        //chave fechada
    }
}

void struct_or_union(Lista *li)
{
    if ("struct")
    {
    }
    else if ("union")
    {
    }
    else
    {
        printf("esperava struct ou union na linha %d", linha);
    }
}

void struct_declaration(Lista *li)
{
    if ()
    {
        specifier_qualifier(li);
        //asterisco
        struct_declarator_list(li);
    }
}

void specifier_qualifier(Lista *li)
{
    if ()
    {
        type_specifier(li);
    }
    else if ()
    {
        type_qualifier(li);
    }
}

void struct_declarator_list(Lista *li)
{
    if ()
    {
        struct_declarator(li);
        struct_declarator_list1(li);
    }
    else
    {
    }
}

void struct_declarator_list1(Lista *li)
{
    if ()
    {
        //virgula
        struct_declarator(li);
        struct_declarator_list1(li);
    }
}
void struct_declarator(Lista *li)
{
    if ()
    {
        declarator(li);
        struct_declarator2(li);
    }
    else if ()
    {
        // dois pontos
        constant_experession(li);
    }
    else
    {
    }
}

void struct_declarator2(Lista *li)
{
    if ()
    {
        //dois pontos
        constant_experession(li);
    }
}
void declarator(Lista *li)
{
    if ()
    {
        //abre parenteses
        pointer(li);
        // fecha parenteses
        //ponto de interrogacao
        direct_declarator(li);
    }
    else
    {
    }
}
void pointer(Lista *li)
{
    if
    {
        //chave aberta
        type_qualifier(li);
        //chave fechada
        //asterisco
        //chave aberta
        pointer(li);
        //chave fechada
        //ponto de interrogacao
    }
    else
    {
    }
}
void type_qualifier(Lista *li)
{
    if ("const")
    {
    }
    else if ("volatile")
    {
    }
}
void direct_declarator(Lista *li)
{
    if ()
    {
        //tokenIdentificador
        direct_declarator1(li);
    }
    else if ()
    {
        //parentese aberto
        declarator(li);
        //parentese fechado
        direct_declarator1(li);
    }
    else
    {
    }
}

void direct_declarator1(Lista *li)
{
    if ()
    {
        //pare recto ab
        // chave abe
        constant_experession(li);
        //chave fe
        //ponto de interroga
        //pare recto fe
        direct_declarator1(li);
    }
    else if ()
    {
        //parentese ab
        direct_declarator2(li);
    }
    else
    {
    }
}

void direct_declarator2(Lista *li)
{
    if ()
    {

        parameter_type_list(li);
        direct_declarator1(li);
    }
    else if ()
    {
        //chave ab
        //tokenIdentificador
        //cahve fe
        // asterisco
        //parente fe
        direct_declarator1(li);
    }
    else
    {
    }
}

void constant_experession(Lista *li)
{
    if ()
    {
        conditional_expression(li);
    }
    else
    {
    }
}
void conditional_expression(Lista *li)
{
    if ()
    {
        logical_or_experssion(li);
        conditional_expression1(li);
    }
}

void conditional_expression1(Lista *li)
{
    if ()
    {
        //ponto de interrogacao
        expression(li);
        //dois pontos
        conditional_expression(li);
    }
    else
    {
    }
}

void logical_or_experssion(Lista *li)
{
    if ()
    {
        logical_or_experssion(li);
        logical_or_experssion1(li);
    }
    else
    {
    }
}

void logical_or_experssion1(Lista *li)
{
    if ()
    {
        // Token OR
        logical_or_experssion(li);
        logical_or_experssion1(li);
    }
    else
    {
    }
}

void logical_and_experssion(Lista *li)
{
    if ()
    {
        inclusive_or_experssion(li);
        inclusive_and_experssion1(li);
    }
    else
    {
    }
}

void logical_and_experssion1(Lista *li)
{
    if
    {
        //Token &&
        inclusive_or_experssion(li);
        logical_and_experssion1(li);
    }
    else
    {
    }
}

void inclusive_or_experssion(Lista *li)
{
    if ()
    {
        exclusive_or_expression(li);
        inclusive_or_experssion1(li);
    }
    else
    {
    }
}

void inclusive_or_experssion1(Lista *li)
{
    if ()
    {
        //token |
        exclusive_or_expression(li);
        inclusive_or_experssion1(li);
    }
    else
    {
    }
}

void exclusive_or_expression(Lista *li)
{
    if ()
    {
        and_expression(li);
        exclusive_or_expression1(li);
    }
    else
    {
    }
}

void exclusive_or_expression1(Lista *li)
{
    if ()
    {
        //Token circunlexo
        and_expression(li);
        exclusive_or_expression1(li);
    }
}

void and_expression(Lista *li)
{
    if ()
    {
        equality_expression(li);
        and_expression1(li);
    }
    else if ()
    {
    }
}

void and_expression1(Lista *li)
{
    if ()
    {
        //Token &
        equality_expression(li);
        and_expression1(li);
    }
    else
    {
    }
}

void equality_expression(Lista *li)
{
    if ()
    {
        relational_expression(li);
        equality_expression1(li);
    }
}
void equality_expression1(Lista *li)
{
    if ()
    {

        relational_expression(li);
        equality_expression1(li);
    }
    else if ()
    {
        //Token !=
        relational_expression(li);
        equality_expression1(li);
    }
    else
    {
    }
}
void relational_expression(Lista *li)
{
    if ()
    {

        relational_expression1(li);
    }
    else
    {
    }
}

void relational_expression1(Lista *li)
{
    if ()
    {
        // Verifica < TOKEN

        relational_expression1(li);
    }
    else if ()
    {
        // Verifica > Token

        relational_expression1(li);
    }
    else if ()
    {
        // Verifica <= Token

        relational_expression1(li);
    }
    else if ()
    {
        // Verifica >= Token

        relational_expression1(li);
    }
    else
    {
    }
}

void cast_expression(Lista *li)
{
    if ()
    {
        unary_expression(li);
    }
    else if ()
    {
        //Verifica (
        type_name(li);

        //Verifica )

        cast_expression(li);
    }
}

void unary_expression(Lista *li)
{
    if ()
    {
        postfix_expression(li);
    }
    else if ()
    {
        //Verifica ++
        unary_expression(li);
    }
    else if ()
    {
        //Verifica --
        postfix_expression(li);
    }
    else if ()
    {
        unary_expression(li);
        cast_expression(li);
    }
    else if ()
    {
        //verifica sizeof
        unary_expression1(li);
    }
}
void unary_expression1(Lista *li)
{
    if ()
    {
        unary_expression(li);
    }
    else if ()

    {
        type_name(li);
    }
}

void primary_expression(Lista *li)
{
    if
    {
        //verifica identifier
    }
    else if ()
    {
        //Verifica constante
        // ou int ou caracter ou float
    }
    else if ()
    {
        //verifica string
    }
    else if ()
    {
        //verifica (

        expression(li);
        //verifica )
    }
}

void expression(Lista *li)
{
    if ()
    {
        assigment_expression(li);
        expression1(li);
    }
}
void expression1(Lista *li)
{
    if ()
    {
        //verifica ,
        assigment_expression(li);
        expression1(li);
    }
}
void assigment_expression(Lista *li)
{
    if ()
    {
        conditional_expression(li);
    }
    else if ()
    {
        unary_expression(li);
        assigment_operator(li);
        assigment_expression(li);
    }
}
void assigment_operator(Lista *li)
{
    if ()
    {

        // verifica = *= /= %= += -= <<= >>= &=
    }
}
void unary_operator(Lista *li)
{
    if ()
    {
        // verifica & * + - ~ !
    }
}
void type_name(Lista *li)
{
    if ()
    {
        //verifica {
        specifier_qualifier(li);
        //verifica }
        //verifica {
        abstract_declarator(li);
        //verifica }
    }
}
void parameter_type_list(Lista *li)
{
    parameter_list(li);
    parameter_type_list1(li);
}
void parameter_type_list1(Lista *li)
{
    if ()
    {
        //verifica ,
        //verifica ...
    }
}
void parameter_list(Lista *li)
{
    if ()
    {
        parameter_declaration(li);
        parameter_list1(li);
    }
}
void parameter_list1(Lista *li)
{
    if ()
    {
        //verifica ,
        parameter_declaration(li);
        parameter_list1(li);
    }
}
void parameter_declaration(Lista *li)
{
    if ()
    {
        // verifica {
        declaration_specifier(li);
        //verifica }
        parameter_declaration1(li);
    }
}
void parameter_declaration1(Lista *li)
{
    if ()
    {
        declarator(li);
    }
    else if ()
    {
        abstract_declarator(li);
    }
}
void abstract_declarator(Lista *li)
{
    if ()
    {
        // verifica
        pointer(li);
        abstract_declarator1(li);
    }
}
void abstract_declarator1(Lista *li)
{
    if ()
    {
        direct_abstract_declarator(li);
    }
}
void direct_abstract_declarator(Lista *li)
{
    if ()
    {
        // verifica (
        abstract_declarator(li);
        // verifica )
    }
    else if ()
    {
        //verifica { opt
        direct_abstract_declarator(li);
        //verifica }
        direct_abstract_declarator1(li);
    }
}
void direct_abstract_declarator1(Lista *li)
{
    if ()
    {

        //verifica [
        //verifica {
        conditional_expression(li);
        //verifica }
        //verifica ]
    }
    else if ()
    {
        // verifica (
        //verifica { opt
        parameter_type_list(li);
        //verifica }
    }
}
void typedef_name(Lista *li)
{
    if ()
    {
        //verifica identificador
    }
}
void declaration(Lista *li)
{
    if ()
    {
        //verifica {
        declaration_specifier(li);
        //verifica}
        //verifica { opt
        init_declarator(li);
        //verifica }
        //verifica ;
    }
}
void init_declarator(Lista *li)
{
    if ()
    {
        declarator(li);
        init_declarator1(li);
    }
}
void init_declarator1(Lista *li)
{
    if ()
    {
        //verifica =
        initializer(li);
    }
}
void initializer(Lista *li)
{
    if ()
    {
        assigment_expression(li);
    }
    else if ()
    {
        initializer_list(li);
        initializer1(li);
    }
}
void initializer1(Lista *li)
{
    if ()
    {
        //verifica ,
        //verifica }
    }
    else if ()
    {
        //verifica }
    }
}
void initializer_list(Lista *li)
{
    initializer(li);
    initializer_list1(li);
}
void initializer_list1(Lista *li)
{
    if ()
    {
        //verifica ,
        initializer(li);
        initializer_list1(li);
    }
}
void compound_statement(Lista *li)
{
    if ()
    {
    }
    declaration(li);
}
void statement(Lista *li)
{
    if ()
    {
        //verifica identifier
        labeled_statement(li)
    }
    else if ()
    {
        expression_statement(li);
    }
    else if ()
    {
        //verifica {
        compound_statement(li);
    }
    else if ()
    {
        // verifica if ou switch
        selection_statement(li)
    }
    else if ()
    {
        //verifica while do for
        iteration_statement(li);
    }
    else if ()
    {

        //verifica goto break continue
        jump_statement(li);
    }
}
void labeled_statement(Lista *li)
{
    if ()
    {

        // verifica :
        statement(li);
    }
    else if ()
    {
        //verifica case
        constant_experession(li);
        //verifica :
        statement(li);
    }
    else if ()
    {
        //verifica default
        //verfica :
        statement(li);
    }
}
void expression_statement(Lista *li)
{
    //verifica { opt
    expression(li);
    //verifica } opt
    //verifica ;
}
void selection_statement(Lista *li)
{
    if ()
    {
        //verifica if
        // verifica (
        //verifica { opt
        expression(li);
        //verifica } opt
        //verifica )
        statement(li);
        selection_statement1(li);
    }
    else if ()
    {
        // verifica switch
        // verifica (
        expression(li);
        //verifica )
        statement(li);
    }
    else
    {
    }
}
void selection_statement1(Lista *li)
{
    if ()
    {
        //verifica else
        statement(li);
    }
}
void iteration_statement(Lista *li)
{
    if ()
    {
        //verfica while
        //verifica (
        expression(li);
        //verifica)
        statement(li);
    }
    else if ()
    {
        //verifica "do"
        statement(li);
        //verifica while
        //verifica (
        expression(li)
        //verifica  )
        //verifica ;
    }
    else if ()
    {
        //verifica for
        //verifica (
        // verifica { opt
        expression(li);
        //verifica }
        //verifica;
        // verifica { opt
        expression(li);
        //verifica }
        //verifica;// verifica { opt
        expression(li);
        //verifica }
        //verifica )
        statement(li);
    }
}
void jump_statement(Lista *li)
{
    if ()
    {
        // verifica goto
        // identificador
    }
    else if ()
    {
        //verifica continue
        //verifica ;
    }
    else if ()
    {
        //verifica break
        //verifica ;
    }
    else if ()
    {
        // verifica return
        //{ opcional
        expression(li);
        //} opcional
        //verifica ;
    }
}
