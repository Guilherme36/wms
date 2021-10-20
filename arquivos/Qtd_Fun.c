#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(void) {
    int i = 0;
    int itemsTotal = 5;
    char qtd[200][30];
    FILE *abrindoQtd;
    FILE *salvandoQtd;
//============================== Abrir o arquivo e Capturar os dados =====================================
    abrindoQtd = fopen("qtd.txt", "r");
    while(!feof(abrindoQtd)){
    fscanf(abrindoQtd, "%i", &qtd[i][30]);
    printf("%d\n", qtd[i][30]);
    i++;
    }
    fclose(abrindoQtd);
    getchar();
//============================== Mostrar as QTD no console=====================================
    printf("\nSelecione o item que seja adicionar ao estoque:\n");
    i = 0;
    while(qtd[i][30] != qtd[itemsTotal][30]){
    printf("\n %d. qtd: %d \n", i + 1 , qtd[i][30]);
    i++;
    }
//============================== Alterando o valor da 1 qtd =====================================
    printf("diminui o tamanho da 1");
    qtd[0][30] = 14;
    printf("\n %d ", qtd[0][30]);
//============================== Salvar no arquivo =====================================
    i = 0;
    salvandoQtd = fopen("qtd.txt", "w");

    while(qtd[i][30] != qtd[itemsTotal][30]){
    fprintf(salvandoQtd, "%i\n", qtd[i][30]);
    i++;
    }
    fclose(salvandoQtd);
    printf("\n salvou com sucesso");
    
    return 0;
}
