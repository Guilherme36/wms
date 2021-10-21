#include <stdio.h>  //lib padrão
#include <stdlib.h> //lib para system cls
#include <locale.h> //lib para pt-br
#include <windows.h> //lib para pausa no windows
//#include <unistd.h> //lib para pausa no Linux
#include <ctype.h>    //lib para Uppercase
//============================== Declaração das variáveis GLOBAIS =====================================

int qtdTotal = 5;
int escolha;
int sair;
char qtd[100][30];
char items[100][200];
char local[100][4];
FILE *abrindoItems;
FILE *salvandoItems;
FILE *abrindoQtd;
FILE *salvandoQtd;
FILE *abrindoLocal;
void abrirItem(void);
void mostrarItem(int menu);
void abrirQtd(void);
void salvarQtd(void);
void abrirLocal (void);
void voltarMenu (int voltar);
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
    Sleep(1000);
    system("cls");
    login();
    Sleep(2000);
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
        fflush(stdin);     //Limpar o buffer
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
        fflush(stdin);     //Limpar o buffer
        printf("Senha: ");
        scanf("%s",&senhaDigitada);
        fflush(stdin);     //Limpar o buffer

        //printf("\nO login digitado armazenado foi: %s", loginDigitado);
        //printf("\nO nome armazenado foi: %s\n", senhaDigitada);

        if (strcmp(loginCorreto, loginDigitado) == 0 && strcmp(senhaCorreta, senhaDigitada) == 0){
            aprovado = 1;
        }
        else{
            aprovado = 0;
            printf("----------------------------------------------");
            printf("\nErro : Usuario ou senha digitado incorretos\n");
            printf("----------------------------------------------\n");
            Sleep(2000);
            system("cls");
        }
    }while (aprovado != 1);
    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>> ACESSO PERMITIDO <<<<<<<<<<<<<<<<<<<<<<<<\n");
}

void entrada(void) {
    do{
        int qtdEscolhida = 0;
        //============================== Abrir Items e Capturar os dados =====================================
        abrirItem();
        //============================== Mostrar os items no console=====================================
        mostrarItem(0);
        //============================== Quantidade Desejada =====================================
        system("cls");
        printf("\n\nQual a quantidade a ser inserida? ");
        scanf("%d",&qtdEscolhida);
        fflush(stdin);     //Limpar o buffer
        //============================== Abrir QTD e Capturar os dados =====================================
        abrirQtd();
        //============================== Alterar o valor QTD =====================================
        system("cls");
        qtd[escolha - 1][30] = qtdEscolhida + qtd[escolha - 1][30];
        printf("\n %d items de %s foram adicionados com sucesso", qtdEscolhida, &items[escolha - 1][200]);
        //============================== Salvar no arquivo =====================================
        salvarQtd();
        Sleep(5000);
        system("cls");
        //============================== Adicionar mais items? =====================================
        voltarMenu(0);
        system("cls");
    }while (sair != 2);

}
void separacao(void) {
    printf("\nvoce entrou na SEPARACAO");
}
void consultas(void) {
    do{
        //============================== Abrir Items e Capturar os dados =====================================
        abrirItem();
        //============================== Mostrar os items no console=====================================
        mostrarItem(1);
        //============================== Informações sobre o item escolhido =====================================
        system("cls");
        printf("%s \n", &items[escolha - 1][200]);
        abrirQtd();
        printf("Quantidade: %d pecas\n", qtd[escolha - 1][30]);
        abrirLocal();
        printf("Local: %s \n", &local[escolha - 1][4]);
        //Sleep(5000);
        printf("\n\n----------------------------------------------");
        printf("\nPressione qualquer tecla para continuar");
        printf("\n----------------------------------------------");
        getchar();
        system("cls");
        //============================== Adicionar mais items? =====================================
        voltarMenu(1);
        system("cls");
    }while(sair != 2);
}

//============================== Mexer no arquivo =====================================

void abrirItem(void) {
    int i = 0;
    abrindoItems = fopen("items.txt", "r");
        while(!feof(abrindoItems)){
            fscanf(abrindoItems, "%s", &items[i][200]);
            //printf("\n%s", &items[i][200]);
            i++;
        }
        fclose(abrindoItems);
}

void abrirQtd(void) {
    int i = 0;
        abrindoQtd = fopen("qtd.txt", "r");
        while(!feof(abrindoQtd)){
            fscanf(abrindoQtd, "%i", &qtd[i][30]);
            //printf("%d\n", qtd[i][30]);
            i++;
        }
        fclose(abrindoQtd);
}

void salvarQtd(void) {
    int i = 0;
    salvandoQtd = fopen("qtd.txt", "w");
        while(qtd[i][30] != qtd[qtdTotal][30]){
            fprintf(salvandoQtd, "%i\n", qtd[i][30]);
            i++;
        }
    fclose(salvandoQtd);
}

void abrirLocal(void) {
    int i = 0;
    abrindoLocal = fopen("local.txt", "r");
        while(!feof(abrindoLocal)){
            fscanf(abrindoLocal, "%s", &local[i][4]);
            //printf("\n%s", &local[i][4]);
            i++;
        }
        fclose(abrindoLocal);
}

//============================== Funções Reutilizaveis =====================================

void mostrarItem(int menu) {
    int i;
    char mensagem[2][100] = {"Selecione o item que seja adicionar ao estoque:", "Qual material deseja consultar?"};
    escolha = 0;
    int aprovado = 0;
    do{
            printf("\n %s \n\n", &mensagem[menu-1][100]);
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

void voltarMenu(int voltar) {
    char decisao = ' ';
    char mensagem[3][100] = {"Deseja adicionar mais algum item?", "Deseja verificar os itens de mais alguma nota?", "Deseja verificar mais algum item?"};
    do{
            printf("\n %s Digite [S] para Sim e [N] para nao: ", &mensagem[voltar][100]);
            scanf("%c",&decisao);
            fflush(stdin);
            if(toupper(decisao) == 'S'){
                sair = 1;
            }
            else if (toupper(decisao) == 'N'){
                sair = 2;
            }
            else{
                sair = 0;
                printf("\n-------------------------------------------------------------------");
                printf("\nErro : O caractere digitado nao corresponde as opcoes informadas\n");
                printf("-------------------------------------------------------------------\n");
                Sleep(5000);
                system("cls");
            }

        }while(sair <= 0);
}

