#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(void) {
    char texto[500];
    int i = 0;
    char palavra[200][200];
    FILE *abrindoItems;
    //============================== Abrir o arquivo e Capturar os dados =====================================
    abrindoItems = fopen("items2.txt", "r");
    while(!feof(abrindoItems)){
    fscanf(abrindoItems, "%s", &palavra[i][200]);
    printf("\n%s", &palavra[i][200]);
    i++;
    }
    fclose(abrindoItems);
    getchar();
//============================== Mostrar as QTD no console=====================================
    printf("\nSelecione o item que seja adicionar ao estoque:\n\n");
    i = 0;
    while(palavra[i][200] != NULL){
    printf("\n %i. %s \n", i + 1 ,&palavra[i][200]);
    i++;
    }

    if(palavra[8][200] == NULL){
        printf("esta palavra nao existe");
    }
    else{
        printf("meu programa deu errado");
    }
    return 0;
}
