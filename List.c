#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num;
    struct Node *prox;
};
typedef struct Node node;

node* empilhar(node *topo) {
    node *novo = malloc(sizeof(node)); //alocar espaço na memoria
    if (novo) {
        printf("Novo elemento: ");
        scanf("%d", &novo->num);
        novo->prox = topo;
        return novo;
    } else {
        printf("\n Erro ao alocar memoria");
        return NULL;
    }
}

void showList(node *head) {
    node *current = head;
    printf("Lista: ");
    while (current != NULL) {
        printf("%d ", current->num);
        current = current->prox;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    char ola;
    node *FILA = NULL; // Inicializa a fila como vazia
    printf("Fila criada \n\n");

    while(1){ // Loop infinito
        printf("Deseja inserir no inicio ou no fim? (i/f): ");
        scanf(" %c", &ola); // Deixe um espaço antes do %c para ignorar espaços em branco

        if (ola == 'f') {
            node *novo = (node *)malloc(sizeof(node));
            printf("Novo elemento: ");
            scanf("%d", &novo->num);
            novo->prox = NULL;

            if (FILA == NULL) { // Se a fila estiver vazia, novo será o primeiro elemento
                FILA = novo;
            } else {
                node *current = FILA;
                while (current->prox != NULL) {
                    current = current->prox;
                }
                current->prox = novo;
            }
        } else if (ola == 'i') {
            FILA = empilhar(FILA);
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }

        showList(FILA);
    }

    return 0;
}
