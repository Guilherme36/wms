#include <stdio.h>  //lib padrão
#include <stdlib.h> //lib para system cls
#include <locale.h> //lib para pt-br
#include <windows.h> //lib para pausa no windows
//#include <unistd.h> //lib para pausa no Linux
#include <ctype.h>    //lib para Uppercase
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
    int fim = 0;
    void bemVindo(void);
    void login(void);

    void entrada(void);
    void separacao(void);
    void consultas(void);
   //============================== Inicialização =====================================
    bemVindo();
    Sleep(5000);
    system("cls");
    login();

   //============================== Menu principal =====================================
    do{
        int escolha = 0;
        system("cls");
        
        printf("\nMenu: Escolha uma das seguintes opcoes:\n\n");
        printf("1. Entrada\n");
        printf("2. Separacao\n");
        printf("3. Consultas\n");
        printf("4. Encerrar o programa\n");
        printf("\n Opcao escolhida: ");
        scanf("%d",&escolha);
        switch (escolha)
        {
            case 1:
                system("cls");
                entrada();
                break;
            case 2:
                system("cls");
                separacao();
                break;
            case 3:
                system("cls");
                consultas();
                break;
            case 4:
                system("cls");
                printf("----------------------------");
                printf("\nSaindo do programa!\n");
                printf("----------------------------\n");
                Sleep(2000);
                fim = 1;
                break;

            default:
                printf("----------------------------");
                printf("\nErro : Voce escolheu uma opcao invalida.\n");
                printf("----------------------------\n");
                Sleep(2000);
                break;
        }




    }while (fim != 1);

    return 0;
 }

void bemVindo(void) {
    printf("|||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("||                                         ||\n");
    printf("||              Bem vindo ao               ||\n");
    printf("||    Warehouse Management System (WMS)    ||\n");
    printf("||                                         ||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||\n");
}

void login(void) {
    //============================== Declaração variáveis Locais =====================================
    char loginCorreto[4] = "gui";
    char loginDigitado[20];
    char senhaCorreta[6] = "admin";
    char senhaDigitada[20];
    int aprovado = 0;
    //============================== LOGIN =====================================
    do{
        printf("Insira seu login:\n\n");
        printf("Usuario: ");
        scanf("%s",&loginDigitado);
        printf("Senha: ");
        scanf("%s",&senhaDigitada);

        //printf("\nO login digitado armazenado foi: %s", loginDigitado);
        //printf("\nO nome armazenado foi: %s\n", senhaDigitada);

        if (strcmp(loginCorreto, loginDigitado) == 0 && strcmp(senhaCorreta, senhaDigitada) == 0){
            aprovado = 1;
        }
        else{
            aprovado = 0;
            printf("----------------------------");
            printf("\nErro : Usuario ou senha digitado incorretos.\n");
            printf("----------------------------\n");
            Sleep(2000);
            system("cls");
        }
    }while (aprovado != 1);
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>> ACESSO PERMITIDO <<<<<<<<<<<<<<<<<<<<<<<<\n");
    Sleep(2000);
}

void entrada(void) {
    //============================== Declaração variáveis Locais =====================================
    int sair;
    do{

        int i = 0;
        int escolha = 0;
        int aprovado = 0;
        int qtdEscolhida = 0;
        char decisao = ' ';
        sair = 0;
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
            printf("\nSelecione o item que seja adicionar ao estoque:\n\n");
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
        //============================== Quantidade Desejada =====================================
        system("cls");
        printf("\n\nQual a quantidade a ser inserida? ");
        scanf("%d",&qtdEscolhida);
        fflush(stdin);
        //============================== Abrir QTD e Capturar os dados =====================================
        i = 0;
        abrindoQtd = fopen("qtd.txt", "r");
        while(!feof(abrindoQtd)){
            fscanf(abrindoQtd, "%i", &qtd[i][30]);
            //printf("%d\n", qtd[i][30]);
            i++;
        }
        fclose(abrindoQtd);
        //============================== Alterar o valor QTD =====================================
        system("cls");
        qtd[escolha - 1][30] = qtdEscolhida + qtd[escolha - 1][30];
        printf("\n %d items de %s foram adicionados com sucesso", qtdEscolhida, &items[escolha - 1][200]);
        //============================== Salvar no arquivo =====================================
        salvandoQtd = fopen("qtd.txt", "w");
        i = 0;
        while(qtd[i][30] != qtd[qtdTotal][30]){
            fprintf(salvandoQtd, "%i\n", qtd[i][30]);
            i++;
        }
        fclose(salvandoQtd);
        Sleep(5000);
        system("cls");
        //============================== Adicionar mais items? =====================================
        do{
            printf("\nDeseja adicionar mais algum item? Digite [S] para Sim e [N] para nao: ");
            scanf("%c",&decisao);
            fflush(stdin);
            if(toupper(decisao) == 'S'){
                sair = 1;
            }
            else if (toupper(decisao) == 'N'){
                sair = 2;
            }
            else{
                printf("\n-------------------------------------------------------------------");
                printf("\nErro : O caractere digitado nao corresponde as opcoes informadas\n");
                printf("-------------------------------------------------------------------\n");
                Sleep(5000);
                system("cls");
            }
            
        }while(sair <= 0);
        system("cls");
    }while (sair != 2);

}
void separacao(void) {
    printf("\nvoce entrou na SEPARACAO");
}
void consultas(void) {
    printf("\nvoce entrou na CONSULTAS");
}



