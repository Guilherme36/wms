#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(void) {
    char texto[500];
    char item3[200] = "carvao";
    FILE *nomeDoMeuPonteiro;
    nomeDoMeuPonteiro = fopen("items.txt", "r");

    fscanf(nomeDoMeuPonteiro, "%[^NULL]s", &texto);
    printf("%s", texto);

    fclose(nomeDoMeuPonteiro);

    getchar();

    if(strcmp(item3, texto) == 0){
     printf("ENCONTROU");
     getchar();
    }
    else{
    //printf("ERRO");
    printf("%s", texto);
    }

    return 0;
}
