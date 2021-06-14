#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "functions.h"
//#include "tokens.c"
struct tabLex
{
    char token[50];
    char lexema[50];
    char linha[50];
};
typedef struct tabLex TabelaLex;

void sintatico()
{
    FILE *pont_arq;
    pont_arq = fopen("LexTable.txt", "r");

    while (fscanf(pont_arq, "%s,%s,%s ", linha, , lexema) != EOF)
    {

        printf("%s\n", lexema);
    }
}

void external_declaration()
{
    if ()
    {
        function_definition();
        /* code */
    }
    else if ()
    {
        declaration();
        /* code */
    }
}
void function_definition()
{
    if ()
    {

        declaration_specifier();
        declarator();
        declaration();
    }
}

void declaration_specifier()
{
    if ()
    {
        storage_class_specifier();
        /* code */
    }
    else if (/* condition */)
    {
        type_specifier();
        /* code */
    }
    else if ()
    {
        type_qualifier();
        /* code */
    }
}
void storage_class_specifier()
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

void type_specifier()
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
        struct_or_union_specifier();
    }
    else if ()
    {
        enum_specifier();
    }
    else if ()
    {
        typedef_name();
    }
}

void struct_or_union_specifier()
{
    struct_or_union();
    struct_or_union_specifier1();
}
void struct_or_union_specifier1()
{
    if ()
    {
        //tokenidentifier();
        //chave aberta
        struct_or_union_specifier2();
        //+
        //chave fechada
    }
}
void struct_or_union2()
{
    if (/* condition */)
    {
        //chave aberta
        struct_declaration();
        //+
        //chave fechada
    }
}

void struct_or_union()
{
    if ("struct")
    {

        /* code */
    }
    else if ("union")
    {
        /* code */
    }
    else
    {
        printf("esperava struct ou union na linha %d", linha);
    }
}

void struct_declaration()
{
    if (/* condition */)
    {
        specifier_qualifier();
        //asterisco
        struct_declarator_list();
        /* code */
    }
}

void specifier__qualifier()
{
    if (/* condition */)
    {
        type_specifier();
        /* code */
    }
    else if (/* condition */)
    {
        type_qualifier();
        /* code */
    }
}

void struct_declarator_list()
{
    if (/* condition */)
    {
        struct_declarator();
        struct_declarator_list1();
        /* code */
    }
    else
    {
        /* code */
    }
}

void struct_declarator_list1()
{
    if (/* condition */)
    {
        //virgula
        struct_declarator();
        struct_declarator_list1();

        /* code */
    }
}
void struct_declarator()
{
    if (/* condition */)
    {
        declarator();
        struct_declarator2();
        /* code */
    }
    else if (/* condition */)
    {
        // dois pontos
        constant_experession();
        /* code */
    }
    else
    {
        /* code */
    }
}

void struct_declarator2()
{
    if (/* condition */)
    {
        //dois pontos
        constant_experession();

        /* code */
    }
}
void declarator()
{
    if ()
    {
        //abre parenteses
        pointer();
        // fecha parenteses
        //ponto de interrogacao
        direct_declarator();
    }
    else
    {
    }
}
void pointer()
{
    if
    {
        //chave aberta
        type_qualifier();
        //chave fechada
        //asterisco
        //chave aberta
        pointer();
        //chave fechada
        //ponto de interrogacao
    }
    else
    {
    }
}
void type_qualifier()
{
    if ("const")
    {

        /* code */
    }
    else if ("volatile")
    {
        /* code */
    }
}
void direct_declarator()
{
    if (/* condition */)
    {
        //tokenIdentificador
        direct_declarator1();
        /* code */
    }
    else if (/* condition */)
    {
        //parentese aberto
        declarator();
        //parentese fechado
        direct_declarator1();
        /* code */
    }
    else
    {
        /* code */
    }
}

void direct_declarator1()
{
    if (/* condition */)
    {
        //pare recto ab
        // chave abe
        constant_experession();
        //chave fe
        //ponto de interroga
        //pare recto fe
        direct_declarator1();
        /* code */
    }
    else if (/* condition */)
    {
        //parentese ab
        direct_declarator2();
        /* code */
    }
    else
    {
        /* code */
    }
}

void direct_declarator2()
{
    if (/* condition */)
    {

        parameter_type_list();
        direct_declarator1();
        /* code */
    }
    else if (/* condition */)
    {
        //chave ab
        //tokenIdentificador
        //cahve fe
        // asterisco
        //parente fe
        direct_declarator1();

        /* code */
    }
    else
    {
        /* code */
    }
}

void constant_experession()
{
    if ()
    {
        conditional_expression();
    }
    else
    {
    }
}
void conditional_expression()
{
    if (/* condition */)
    {
        logical_or_experssion();
        conditional_expression1();
        /* code */
    }
}

void conditional_expression1()
{
    if (/* condition */)
    {
        //ponto de interrogacao
        expression();
        //dois pontos
        conditional_expression();
        /* code */
    }
    else
    {
        /* code */
    }
}

void logical_or_experssion()
{
    if (/* condition */)
    {
        logical_or_experssion();
        logical_or_experssion1();
        /* code */
    }
    else
    {
        /* code */
    }
}

void logical_or_experssion1()
{
    if (/* condition */)
    {
        // Token OR
        logical_or_experssion();
        logical_or_experssion1();
        /* code */
    }
    else
    {
    }
}

void logical_and_experssion()
{
    if (/* condition */)
    {
        inclusive_or_experssion();
        inclusive_and_experssion1();
        /* code */
    }
    else
    {
    }
}

void logical_and_experssion1()
{
    if
    {
        //Token &&
        inclusive_or_experssion();
        logical_and_experssion1();
    }
    else
    {
    }
}

void inclusive_or_experssion()
{
    if (/* condition */)
    {
        exclusive_or_expression();
        inclusive_or_experssion1();
        /* code */
    }
    else
    {
    }
}

void inclusive_or_experssion1()
{
    if (/* condition */)
    {
        //token |
        exclusive_or_expression();
        inclusive_or_experssion1();
        /* code */
    }
    else
    {
        /* code */
    }
}

void exclusive_or_expression()
{
    if (/* condition */)
    {
        and_expression();
        exclusive_or_expression1();
        /* code */
    }
    else
    {
        /* code */
    }
}

void exclusive_or_expression1()
{
    if (/* condition */)
    {
        //Token circunlexo
        and_expression();
        exclusive_or_expression1();
        /* code */
    }
}

void and_expression()
{
    if (/* condition */)
    {
        equality_expression();
        and_expression1();
        /* code */
    }
    else if (/* condition */)
    {
        /* code */
    }
}

void and_expression1()
{
    if (/* condition */)
    {
        //Token &
        equality_expression();
        and_expression1();
        /* code */
    }
    else
    {
        /* code */
    }
}

void equality_expression()
{
    if ()
    {
        relational_expression();
        equality_expression1();
    }
}
void equality_expression1()
{
    if (/* condition */)
    {

        relational_expression();
        equality_expression1();
    }
    else if ()
    {
        //Token !=
        relational_expression();
        equality_expression1();
    }
    else
    {
    }
}
void relational_expression()
{
    if ()
    {

        relational_expression1();
    }
    else
    {
    }
}

void relational_expression1()
{
    if (/* condition */)
    {
        // Verifica < TOKEN

        relational_expression1();

        /* code */
    }
    else if ()
    {
        // Verifica > Token

        relational_expression1();

        /* code */
    }
    else if (/* condition */)
    {
        // Verifica <= Token

        relational_expression1();
        /* code */
    }
    else if (/* condition */)
    {
        // Verifica >= Token

        relational_expression1();
        /* code */
    }
    else
    {
    }
}

void cast_expression()
{
    if ()
    {
        unary_expression()
    }
    else if (/* condition */)
    {
        //Verifica (
        type_name();

        //Verifica )
        /* code */
        cast_expression();
    }
}

void unary_expression()
{
    if (/* condition */)
    {
        postfix_expression();
        /* code */
    }
    else if (/* condition */)
    {
        //Verifica ++
        unary_expression();
        /* code */
    }
    else if ()
    {
        //Verifica --
        postfix_expression();
        /* code */
    }
    else if (/* condition */)
    {
        unary_expression();
        cast_expression();
        /* code */
    }
    else if ()
    {
        //verifica sizeof
        unary_expression1();
    }
}
void unary_expression1()
{
    if (/* condition */)
    {
        unary_expression();
        /* code */
    }
    else if (/* condition */)

    {
        type_name();
        /* code */
    }
}

void primary_expression()
{
    if
    {
        //verifica identifier
    }
    else if (/* condition */)
    {
        //Verifica constante
        // ou int ou caracter ou float
        /* code */
    }
    else if (/* condition */)
    {
        //verifica string
        /* code */
    }
    else if ()
    {
        //verifica (

        expression();
        //verifica )
    }
}

void expression() {}
void expression() {}
void assigment_expression() {}
void assigment_operator() {}
void unary_operator() {}
void type_name() {}
void parameter_type_list() {}
void parameter_type_list1() {}
void parameter_list() {}
void parameter_list1() {}
void parameter_declaration() {}
void parameter_declaration1() {}
void abstract_declarator() {}
void abstract_declarator1() {}
void direct_abstract_declarator() {}
void direct_abstract_declarator1() {}
void typedef_name() {}
void declaration() {}
void init_declarator() {}
void init_declarator1() {}
void initializer() {}
void initializer_list() {}
void initializer_list1() {}
void compound_statement() {}
void statement() {}
void labeled_statement() {}
void expression_statement() {
    
}
void selection_statement()
{
    if (/* condition */)
    {
        //verifica if
        // verifica (
        //verifica { opt
        expression();
        //verifica } opt
        //verifica )
        statement();
        selection_statement1();
        /* code */
    }
    else if (/* condition */)
    {
        // verifica switch
        // verifica (
        expression();
        //verifica )
        statement();
        /* code */
    }
    else
    {
        /* code */
    }
}
void selection_statement1()
{
    if (/* condition */)
    {
        //verifica else
        statement();
        /* code */
    }
}
void iteration_statement()
{
    if (/* condition */)
    {
        //verfica while
        //verifica (
        expression();
        //verifica)
        statement();

        /* code */
    }
    else if ()
    {
        //verifica "do"
        statement();
        //verifica while
        //verifica (
        expression()
        //verifica  )
        //verifica ;

        /* code */
    }
    else if (/* condition */)
    {
        //verifica for
        //verifica (
        // verifica { opt
        expression();
        //verifica }
        //verifica;
        // verifica { opt
        expression();
        //verifica }
        //verifica;// verifica { opt
        expression();
        //verifica }
        //verifica )
        statement();

        /* code */
    }
}
void jump_statement1()
{
    if (/* condition */)
    {
        // verifica goto
        // identificador
        /* code */
    }
    else if (/* condition */)
    {
        //verifica continue
        //verifica ;

        /* code */
    }
    else if ()
    {
        //verifica break
        //verifica ;
        /* code */
    }
    else if (/* condition */)
    {
        // verifica return
        //{ opcional
        expression();
        //} opcional
        //verifica ;
        /* code */
    }
}
