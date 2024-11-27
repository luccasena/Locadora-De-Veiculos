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
        printf("[1] - Cadastro de Veículos\n");
        printf("[2] - Cadastro de Clientes\n");
        printf("[3] - Registrar Aluguel\n");
        printf("[4] - Calcular preço do Aluguel\n");
        printf("[5] - Listagem de veículos disponíveis e alugados\n");
        printf("[6] - Créditos\n");
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
        printf("[1] - Normal;\n[2] - Elétrico;\n[3] - Híbrido;\n");
        printf("Digite o tipo do veículo: \n");
        scanf("%d", &tipo);
        if(tipo < 1 || tipo > 3){
            limpar_tela();
            printf("Opção Inválida! Tente novamente...\n");
            linhas();
        }
        else{
            switch(tipo){
                case 1:
                    strcpy(cadastro->tipo, "Normal");
                    break;
                case 2:
                    strcpy(cadastro->tipo, "Elétrico");
                    break;
                case 3:
                    strcpy(cadastro->tipo,  "Híbrido");
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
        printf("Selecione algum das opções acima conforme seu índice: ");
        scanf("%d", &escolha_usuario);

        limpar_tela();
        linhas();
        switch(escolha_usuario){
            case 1:
                printf(" Você escolheu o cadastro de carros! [1]\n");
                opcao1_cadastrarVeiculos(&cadastro);

                linhas();
                strcat(registro_carro, cadastro.nome);
                strcat(registro_carro, cadastro.marca);
                strcat(registro_carro, cadastro.tipo);

                printf("%s", registro_carro);

                break;
            case 2:
                printf(" Você escolheu o cadastro de clientes! [2]\n");

                break;
            case 3:
                 printf(" Você escolheu registrar aluguel! [3]\n");

                break;
            case 4:
                printf(" Você escolheu o calcular preço do aluguel! [4]\n");

                break;
            case 5:
                printf(" Você escolheu o ver a listagem de veículos disponíveis e alugados! [5]\n");

                break;
            case 6:
                printf(" Você escolheu o ver os créditos! [6]\n");

                break;
            case 0:

                break;
            default:
                printf("Opção Inválida!, Tente novamente...\n");

        }

        if(escolha_usuario == 0){
            limpar_tela();
            printf("Obrigado por utilizar nosso programa!\n");
            break;
        }
    }




    return 0;
}
