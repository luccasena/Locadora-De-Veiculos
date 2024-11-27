#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

void linhas(){
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

}

void limpar_tela(){
    system("cls");
}

void cabecalho(){
        linhas();
        printf("          Webmotors           \n");
        linhas();
        printf("[1] - Cadastro de Ve�culos\n");
        printf("[2] - Cadastro de Clientes\n");
        printf("[3] - Registrar Aluguel\n");
        printf("[4] - Calcular pre�o do Aluguel\n");
        printf("[5] - Listagem de ve�culos dispon�veis e alugados\n");
        printf("[6] - Cr�ditos\n");
        printf("[0] - Sair\n");
}

// ------------------------------------------------------------------------- //

typedef struct CadastroCarros{
        char    marca[50];
        char    nome[50];
        char    tipo[10];

}Veiculos;

void opcao1_cadastrarVeiculos(CadastroCarros *cadastro){

    linhas();
    getchar();


    printf("Digite a marca do carro: ");
    fgets(cadastro->marca, sizeof(cadastro->marca), stdin);

    printf("Digite o nome do carro: ");
    fgets(cadastro->nome, sizeof(cadastro->nome), stdin);


    int tipo;
    while(true){
        printf("[1] - Normal;\n[2] - El�trico;\n[3] - H�brido;\n");
        printf("Digite o tipo do ve�culo: \n");
        scanf("%d", &tipo);
        if(tipo < 1 || tipo > 3){
            limpar_tela();
            printf("Op��o Inv�lida! Tente novamente...\n");
            linhas();
        }
        else{
            switch(tipo){
                case 1:
                    strcpy(cadastro->tipo, "Normal");
                    break;
                case 2:
                    strcpy(cadastro->tipo, "El�trico");
                    break;
                case 3:
                    strcpy(cadastro->tipo,  "H�brido");
                    break;

            }
            break;
        }
        limpar_tela();
    }

}

int main(){
    setlocale(LC_ALL,"");

    int escolha_usuario;
    Veiculos cadastro;
    char registro_carro[110] = "";

    while(true){

        cabecalho();
        linhas();
        printf("Selecione algum das op��es acima conforme seu �ndice: ");
        scanf("%d", &escolha_usuario);

        limpar_tela();
        linhas();
        switch(escolha_usuario){
            case 1:
                printf(" Voc� escolheu o cadastro de carros! [1]\n");
                opcao1_cadastrarVeiculos(&cadastro);

                linhas();
                strcat(registro_carro, cadastro.nome);
                strcat(registro_carro, cadastro.marca);
                strcat(registro_carro, cadastro.tipo);

                printf("%s", registro_carro);

                break;
            case 2:
                printf(" Voc� escolheu o cadastro de clientes! [2]\n");

                break;
            case 3:
                 printf(" Voc� escolheu registrar aluguel! [3]\n");

                break;
            case 4:
                printf(" Voc� escolheu o calcular pre�o do aluguel! [4]\n");

                break;
            case 5:
                printf(" Voc� escolheu o ver a listagem de ve�culos dispon�veis e alugados! [5]\n");

                break;
            case 6:
                printf(" Voc� escolheu o ver os cr�ditos! [6]\n");

                break;
            case 0:

                break;
            default:
                printf("Op��o Inv�lida!, Tente novamente...\n");

        }

        if(escolha_usuario == 0){
            limpar_tela();
            printf("Obrigado por utilizar nosso programa!\n");
            break;
        }
    }




    return 0;
}
