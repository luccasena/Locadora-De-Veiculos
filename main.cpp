#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

/// -------------------------  1. Funções Visuais  --------------------------- //

// 1.1 - Função que imprime linhas:
void linhas(){
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

// 1.2 - Função que limpa os dados imprimindos anteriormente no terminal, está configuração funciona apenas no Windows:

void limpar_tela(){
    system("cls");
}

// 1.3 - Função que imprime o cabeçalho do nosso programa:
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


/// ------------------------- 2. Estrutura de Dados  -------------------------- //

// 2.1 - Estrututa para o cadastramento de carros:
typedef struct CadastroCarros{
        char    marca[50];
        char    nome[50];
        char    tipo[10];

}Carros;


/// -----------------  3. Funções para a Manipulação de dados  -----------------//

// 3.1 - Função que irá cadastrar carros, conforme os dados fornecidos pelo usuário:
void opcao1_cadastrarVeiculos(Carros *cadastro){

    getchar(); // Limpa o Buffer do teclado

    // Solicita os dados para o usuário sobre marca e nome do carro:
    // Aqui, são utilizados conceitos de ponteiros com objetivo de enviar os dados para a função main do programa:
    printf("Digite a marca do carro: ");
    fgets(cadastro->marca, sizeof(cadastro->marca), stdin);

    printf("Digite o nome do carro: ");
    fgets(cadastro->nome, sizeof(cadastro->nome), stdin);

    // Aqui, é utilizado um while infinito para tratar erros de índices digitados incorretamente pelo usuário:
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

            // Caso o usuário digite os índices corretamente, utilizamos a função strcpy que irá cadastrar o tipo conforme o índice escolhido:
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

void opcao5_mostrarCarros(char *base_dados){


}

int main(){
    setlocale(LC_ALL,"");

    Carros cadastro;

    int escolha_usuario;
    char registro_carro[110] = "";
    char registros_de_carros[50][110];
    int i = 0;


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
                linhas();

                opcao1_cadastrarVeiculos(&cadastro);

                linhas();

                // Essa função é responsável por concatenar os dados de uma struct em uma string
                snprintf(registros_de_carros[i], sizeof(registros_de_carros[i])," Carro [%d]: %s Marca: %s Tipo: %s \n",
                         i+1,cadastro.nome, cadastro.marca, cadastro.tipo);
                i++;
                limpar_tela();

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
                while(true){
                    printf(" Você escolheu o ver a listagem de veículos disponíveis e alugados! [5]\n");
                    linhas();
                    for(int cont = 0; cont < i; cont++){
                        puts(registros_de_carros[cont]);
                    }

                    printf("Deseja sair da listagem? [1 - Sim]: ");
                    scanf("%d", &escolha_usuario);
                    if(escolha_usuario == 1){
                        break;
                    }else{
                        limpar_tela();
                        printf("Opção Inválida! Tente Novamente...\n");
                        linhas();
                        }
                }
                limpar_tela();

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
