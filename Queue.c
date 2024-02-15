#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int num;
    struct Node *prox;
};
typedef struct Node node;

int tam;

int main(int argc, char *argv[])
{
    // cria a fila
    node *FILA = (node *)malloc(sizeof(node));
    printf("Fila criada \n\n");

    // inicializa a fila
    FILA->prox = NULL;
    tam = 0;
    printf("Fila Iniciada \n\n");

    // verifica se a fila está vazia
    if (FILA->prox == NULL)
        printf("Fila Vazia \n\n");
    else
        printf("Fila com dados \n\n");

    // insere um numero á lista
    node *novo = (node *)malloc(sizeof(node));
    printf("Novo elemento: ");
    scanf("%d", &novo->num);
    novo->prox = NULL;
    if (FILA->prox == NULL) // fila vazia
        FILA->prox = novo;
    else
    { // fila com dados
        node *tmp = FILA->prox;

        while (tmp->prox != NULL)
            tmp = tmp->prox;
        tmp->prox = novo;
    }
    tam++;

    // mostrar a fila
    node *tmp2;
    tmp2 = FILA->prox;
    printf("Fila :");
    while (tmp2 != NULL)
    {
        printf("%5d", tmp2->num);
        tmp2 = tmp2->prox;
    }
    printf("\n        ");
    int count;
    for (count = 0; count < tam; count++)
        printf("  ^  ");
    printf("\nOrdem:");
    for (count = 0; count < tam; count++)
        printf("%5d", count + 1);
    printf("\n\n");

    // verifica se a fila está vazia
    if (FILA->prox == NULL)
        printf("Fila Vazia \n\n");
    else
        printf("Fila com dados \n\n");

    // retira elemento
    if (FILA->prox == NULL)
    {
        printf("Fila ja esta vazia\n");
        return NULL;
    }
    else
    { 
        node *tmp = FILA->prox;
        FILA->prox = tmp->prox;
        tam--;
        printf("Retirado \n\n");
    }

    // verifica se a fila está vazia
    if (FILA->prox == NULL)
        printf("Fila Vazia \n\n");
    else
        printf("Fila com dados \n\n");
    return 0;
}
