#include <stdio.h>  //lib padrão
#include <stdlib.h> //lib para system cls
#include <locale.h> //lib para pt-br
#include <windows.h> //lib para pausa no windows
#include <string.h> //necessário para strcpy
//#include <unistd.h> //lib para pausa no Linux
//============================== Declaração das variáveis GLOBAIS =====================================

int qtdTotal = 5;
char qtd[100][30];
char items[100][200];
FILE *abrindoItems;
FILE *salvandoItems;
FILE *abrindoQtd;
FILE *salvandoQtd;
//============================== Função Principal =====================================
int main (){
    setlocale(LC_ALL, "Portuguese"); //configurar para portugues
   //============================== Funções =====================================


    void entrada(int menu);
   //============================== Inicialização =====================================
    entrada(1);


    return 0;
 }

void entrada(int menu) {
    //============================== Declaração variáveis Locais =====================================


        int i = 0;
        int escolha = 0;
        int aprovado = 0;
        char mensagem[3][200];
        strcpy(mensagem[0], " ");
        strcpy(mensagem[2], "Selecione o item que seja adicionar ao estoque:");
        strcpy(mensagem[1], "Qual material deseja consultar?");
        //============================== Abrir Items e Capturar os dados =====================================
        abrindoItems = fopen("items.txt", "r");
        while(!feof(abrindoItems)){
            fscanf(abrindoItems, "%s", &items[i][200]);
            //printf("\n%s", &items[i][200]);
            i++;
        }
        fclose(abrindoItems);
        //getchar();
        //============================== Mostrar os items no console=====================================
        do{
            printf("\n %s \n\n", &mensagem[0][200]);
            i = 0;
            while(items[i][200] != NULL){
            printf(" %i. %s \n", i + 1 ,&items[i][200]);
            i++;
            }

            printf("\nItem escolhido: ");
            scanf("%d",&escolha);
            fflush(stdin);
            if(items[escolha - 1][200] == NULL){
                aprovado = 0;
                printf("----------------------------");
                printf("\nErro : Item informado nao existe no sistema!\n");
                printf("----------------------------\n");
                Sleep(2000);
                system("cls");
            }
            else{
                aprovado = 1;
            }
        }while(aprovado != 1);
}
