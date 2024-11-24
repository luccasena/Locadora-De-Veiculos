#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

int main(){
    setlocale(LC_ALL,"");

    int escolha_usuario;

    while(true){

        cabecalho();
        linhas();
        printf("Selecione algum das opções acima conforme seu índice: ");
        scanf("%d", &escolha_usuario);

        limpar_tela();
        switch(escolha_usuario){
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

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
