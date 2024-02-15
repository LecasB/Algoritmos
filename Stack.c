#include <stdio.h>

typedef struct no
{
    int dado;
    struct no *proximo;
} NO;

//função  de empilhar ou push


NO* empilhar(NO *topo){
    NO *novo = malloc(sizeof(NO)); //alocar espaço na memoria
    if (novo){
        novo->dado=novo_dado();
        novo->dado=topo;
        return novo;
    }else{
        print("\n Erro ao alocar memoria");
    }
}

int novo_dado(){
    int dado_pedido;
    print("\nInsira um valor\n");
    scanf("%d",&dado_pedido);
    return dado_pedido;
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


int main(int argc, char *argv[])
{
    NO *topo = NULL;
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

            break;
        case 3:
            break;

        default:
        if (opcao!=0)
        printf("\nOpcao Invalida...\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}