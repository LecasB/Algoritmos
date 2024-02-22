#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct dicionario
{
    char palavra[30];
    char definicao[100];
};

bool compararPalavras (const char palavra1[], const char palavra2[]){
    int x = 0;
    while(palavra1[x] == palavra2[x] && palavra1[x] != '\0' && palavra2[x] != '\0') {
        ++x;
    }
    return palavra1[x] == '\0' && palavra2[x] == '\0';
}

int procuraPalavras (const struct dicionario lingua[], const char palavra[], const int numdepalavras) {
    //bool compararPalavras (const char palavra1[], const char palavra[]);
    int x = 0;
    while(x<numdepalavras) {
        if (compararPalavras(palavra,lingua[x].palavra)) {
            return x;
        } else {
            ++x;
        }
    }
    return -1;
}

int main (void){
    const int NUMERODEDEFINICOES = 7;
    char palavra[30] = {'\0'};
    int resultadopesquisa;
    const struct dicionario portugues[7] = {
        {"mao","alimento a base de farinha"},
        {"mortadela","tipo de carne"},
        {"feijao","e um componente essencial na mesa dos brasileiros"},
        {"tropeiro","tipo de feijao"},
        {"queijo", "Da Serra da Estrela"},
        {"macarronada","Prato culinário de macarrão cozido, manteiga, queijo e um molho em geral de tomate"},
        {"pizza","tipico da italia"}};
        //pedir palavra para procurar no dicionario
        printf("digite uma palavra: ");
        scanf("%s",palavra);
        resultadopesquisa = procuraPalavras (portugues,palavra,NUMERODEDEFINICOES);
        if (resultadopesquisa != -1){
            printf("%s\n", portugues[resultadopesquisa].definicao);
            printf("%s\n", portugues[resultadopesquisa].palavra);
        }else{
            printf("\npalavra nao encontrada\n");
        }
}