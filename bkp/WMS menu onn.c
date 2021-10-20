#include <stdio.h>  //lib padrão
#include <stdlib.h> //lib para system cls
#include <locale.h> //lib para pt-br
#include <windows.h> //lib para pausa no windows
//#include <unistd.h> //lib para pausa no Linux

int main (){
    setlocale(LC_ALL, "Portuguese"); //configurar para portugues
   //============================== Funções =====================================
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
    int fim = 0;
   //============================== Menu principal =====================================
    do{
        int escolha = 0;
        system("cls");  
        printf("\n==============================================================");
        printf("\nMenu: Escolha uma das seguintes opcoes:\n\n");
        printf("1. Entrada\n");
        printf("2. Separacao\n");
        printf("3. Consultas\n");
        printf("4. Encerrar o programa\n");
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
    //============================== Declaração variáveis login =====================================
    char loginCorreto[4] = "gui";
    char loginDigitado[20];
    char senhaCorreta[6] = "admin";
    char senhaDigitada[20];
    int aprovado = 0;
    //============================== LOGIN =====================================
    do{
        printf("Insira seu login:\n\n");
        printf("Usuario:\t");
        scanf("%s",&loginDigitado);
        printf("Senha:\t");
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
    } while (aprovado != 1);
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>> ACESSO PERMITIDO <<<<<<<<<<<<<<<<<<<<<<<<\n");
}

void entrada(void);
    void separacao(void);
    void consultas(void);
    void encerrar(void);

void entrada(void) {
    printf("\nvoce entrou na ENTRADA");
}
void separacao(void) {
    printf("\nvoce entrou na SEPARACAO");
}
void consultas(void) {
    printf("\nvoce entrou na CONSULTAS");
}



