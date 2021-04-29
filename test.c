#include <stdio.h>

int main()
{
    FILE *farq = fopen("arqtexto.txt", "r"); // b indica modo binário
    if (farq == NULL)
    {
        fprintf(stderr, "Erro ao tentar abrir arquivo.txt.");
        return 1;
    }
    char a = fgetc(farq);
    int i = 0;
    while (i != 10)
    {
        printf("%c",a);
        a = fgetc(farq);
        i++;
    }
    
    printf("\n");
    a = fgetc(farq);
    while (a!=EOF)
    {
        printf("%c",a);
        a = fgetc(farq);
    }
    fclose(farq);

    

    return 0;
}