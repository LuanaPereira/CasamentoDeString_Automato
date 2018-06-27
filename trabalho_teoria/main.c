#include <stdio.h>
#include <stdlib.h>
char alfabeto[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int testar_prefixo(char palavra[], char prefixo[]){
    int tamanho_palavra=0, contador=0, contador_prefixo=0;
    int a, b, resultado=0;
    while (palavra[tamanho_palavra] != '\0' ){
        tamanho_palavra++;
    }
    while (prefixo[contador_prefixo] != '\0'){
        contador_prefixo++;
    }
    for (a=0; a<tamanho_palavra; a++){
        for (b=0; b<26; b++){
            if(palavra[a] == alfabeto[b]){
                contador++;
            }
        }
    }
    if (contador==tamanho_palavra){
        printf("Palavra aceita\n");
    }else {
        printf("Palavra rejeitada\n\n");
        return;
    }
    for (a=0; a<contador_prefixo; a++){
        if (palavra[a]!=prefixo[a]){
           resultado=1;
        }
     }
    if (resultado==0){
        printf("Reconheceu prefixo! \n\n");
    }else{
        printf("Nao reconheceu prefixo! \n\n");
    }
    return 1;
}
int testar_sufixo(char palavra[], char sufixo[]){
    int tamanho_palavra=0, contador=0, contador_sufixo=0;
    int a, b, resultado=0;
    int teste = 0;

    while (palavra[tamanho_palavra]!='\0'){
        tamanho_palavra++;
    }
    while (sufixo[contador_sufixo]!='\0'){
        contador_sufixo++;
    }
    for (a=0; a<tamanho_palavra; a++){
        for (b=0; b<26; b++){
            if (palavra[a] == alfabeto[b]){
                contador++;
            }
        }
    }
    if (contador==tamanho_palavra){
        printf("Palavra aceita\n");
    }else {
        printf("Palavra rejeitada\n\n");
        return;
    }
    for (a=(tamanho_palavra-contador_sufixo); a<tamanho_palavra; a++){
        if (palavra[a] != sufixo[teste]){
            resultado=1;
        }
        teste++;
    }
    if (resultado==0){
        printf("Reconheceu sufixo!\n\n");
    }else{
        printf("Nao reconheceu sufixo!\n\n");
    }
    return 1;
}
int testar_subpalavra(char palavra[], char subpalavra[]){
    int tamanho_palavra=0, contador=0, contador_subpalavra=0;
    int a, b=0, resultado=0;

    while (palavra[tamanho_palavra]!='\0'){
        tamanho_palavra++;
    }
    while (subpalavra[contador_subpalavra]!='\0'){
        contador_subpalavra++;
    }
    for (a=0; a<tamanho_palavra; a++){
        for (b=0; b<26; b++){
            if (palavra[a]== alfabeto[b]){
                contador++;
            }
        }
    }
    if (contador==tamanho_palavra){
        printf("Palavra aceita\n");
    }else {
        printf("Palavra rejeitada\n\n");
        return;
    }
    while(palavra[a]!='\0'){
        if (palavra[a]==subpalavra[b]){
            for (b=0; b<contador_subpalavra; b++){
                if (palavra[a]==subpalavra[b]){
                    resultado=1;
                }else{
                    resultado=0;
                    break;
                }
                a++;
            }
        }
        a++;
    }
    if (resultado==1){
        printf("Reconheceu subpalavra\n\n");
    }
    else {
        printf("Nao reconheceu subpalavra\n\n");
    }
}
int main(){
    char palavra[50], verificacao[50];
    int x;
    while (1){
        printf("1 para funcao prefixo \n2 para funcao sufixo \n3 para funcao subpalavra\n\n");
        printf("Escolha a funcao: \n");
        scanf("%d", &x);
        printf("\nDigite a palavra: \n");
        scanf("%s", &palavra);
        printf("Digite a palavra para a verificacao: \n");
        scanf("%s", &verificacao);


        switch (x){
        case 1:
            testar_prefixo(&palavra, &verificacao);
            break;
        case 2:
           testar_sufixo(&palavra, &verificacao);
            break;
        case 3:
            testar_subpalavra(&palavra, &verificacao);
            break;
        default:
            printf("\nEscolha a funcao novamente, opcao nao aceita! \n");
        }
    }
    return 0;
}

