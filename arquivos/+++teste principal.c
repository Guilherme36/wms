#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//int acabou = 0;

int main(void) {
    char texto[500];
    int sla();
    char item3[200] = "carvao";
    int acabou = 0;
    int xa = 0;
    char palavra[200][200];
    FILE *nomeDoMeuPonteiro;
    nomeDoMeuPonteiro = fopen("items.txt", "r");


    /*fscanf(nomeDoMeuPonteiro, "%[^NULL]s", &texto);
    printf("%s", texto);
    getchar();
*/
    //printf("\n hahahha\n");

   //metodo 2
   /*
    while((fgets(palavra,200,nomeDoMeuPonteiro))!=NULL){
        printf("%s",palavra);
    }
    */

   /*
    while(!feof(nomeDoMeuPonteiro)){
    fscanf(nomeDoMeuPonteiro, "%s", &palavra);
    printf("\n%s", &palavra);
    }
    */
   int i = 0;
    while(!feof(nomeDoMeuPonteiro)){
    fscanf(nomeDoMeuPonteiro, "%s", &palavra[i][200]);
    printf("\n%s", &palavra[i][200]);
    i++;
    }

    fclose(nomeDoMeuPonteiro);

    getchar();
   // printf("\n%s\n", &palavra[5][200]);

    if(palavra[5][200] == NULL){
        printf("o items acabou por ai");
    }

    sla(10,20);
    printf("o valor da func e %d", sla);
    getchar();
    printf("\n%d\n", &acabou);
    float sos = 7.55;
    printf("%f", sos);
    return 0;
}

int sla (int a, int b){
    int soma;
    soma = a + b;
    printf("\n\nola tudo bem?\n\n");
    printf("soma e %d", soma);
    return soma;
}
