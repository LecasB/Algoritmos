#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *proximo;
} NO;

//função  de empilhar ou push
int novo_dado(){
    int dado_pedido;
    printf("\nInsira um valor\n");
    scanf("%d",&dado_pedido);
    return dado_pedido;
}

NO* empilhar(NO *topo){
    NO *novo = malloc(sizeof(NO)); //alocar espaço na memoria
    if (novo){
        novo->dado=novo_dado();
        novo->proximo=topo;
        return novo;
    }else{
        printf("\n Erro ao alocar memoria");
    }
}



//função desempilhar ou pop

NO* desempilhar(NO **topo){
    NO *remove;
    if (*topo!=NULL){
        remove=*topo;
        *topo=remove->proximo;
        return remove;
    }else{
      ("\nPilha Vazia\n"); 
    }
}

void imprimir(NO *topo){
    printf("\n Pilha: \n");
    while(topo){
        printf("\n %d", topo->dado);
        topo=topo->proximo;
    }
    
}

int main(int argc, char *argv[])
{
    NO *topo = NULL, *remover;
    int opcao;
    do
    {
        printf("\n 0-Sair \n 1-Empilhar \n 2-Desempilhar \n 3- Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        topo=empilhar(topo);
            break;
        case 2:
        remover=desempilhar(&topo);
        if(remover){
            printf("\n No removido\n");
        }else{
            printf("\n Sem no para remover\n");
        }
            break;
        case 3:
        imprimir(topo);
            break;

        default:
        if (opcao!=0)
        printf("\nOpcao Invalida...\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}