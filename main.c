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
        float   diaria;

}Carros;

// 2.2 - Estrutura para o cadastramento de clientes:
 typedef struct CadastroClientes {
        char    nomeDoUsuario[50];
        char    cpf[13];
        char    telefone[11];
}Clientes;


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

        }

        getchar();
        printf("Digite a diária do veiculo: ");
        scanf("%f", &cadastro->diaria);

        limpar_tela();
        break;
    }

}

// 3.2 - Função que irá cadastrar dados do cliente, conforme os dados fornecidos pelo usuário:
void opcao2_cadastrarClientes(Clientes *cadastro2){
    getchar();

    printf("Digite seu nome: ");
    fgets(cadastro2->nomeDoUsuario, sizeof(cadastro2->nomeDoUsuario), stdin);

    printf("Digite seu cpf: ");
    fgets(cadastro2->cpf, sizeof(cadastro2->cpf), stdin);

    printf("Digite seu número de telefone: ");
    fgets(cadastro2->telefone, sizeof(cadastro2->telefone), stdin);
}


int main(){
    setlocale(LC_ALL,"");

    int escolha_usuario;

    // Registro de Carros
    Carros cadastro;

    int i_carro = 0;

    char registro_carro[110] = "";
    char registros_de_carros[30][110];
    float valor_de_diaria[30];

    // Registro de Clientes:
    Clientes cadastro2;

    int i_cliente = 0;

    char registro_cliente[110] = "";
    char registros_de_clientes[30][110];


    while(true){

        cabecalho();
        linhas();
        printf("Selecione algum das opções acima conforme seu índice: ");
        scanf("%d", &escolha_usuario);

        limpar_tela();
        linhas();

        int veiculo = 0;
        switch(escolha_usuario){
            case 1:
                printf(" Você escolheu o cadastro de carros! [1]\n");
                linhas();

                opcao1_cadastrarVeiculos(&cadastro);

                linhas();

                // Essa função é responsável por concatenar os dados de uma struct em uma string:
                snprintf(registros_de_carros[i_carro], sizeof(registros_de_carros[i_carro])," Carro [%d]:\n Nome: %s Marca: %s Tipo: %s \n",
                         i_carro,cadastro.nome, cadastro.marca, cadastro.tipo);

                valor_de_diaria[i_carro] = cadastro.diaria;

                i_carro++;
                limpar_tela();

                break;
            case 2:
                printf(" Você escolheu o cadastro de clientes! [2]\n");
                linhas();
                opcao2_cadastrarClientes(&cadastro2);

                linhas();
                // Essa função é responsável por concatenar os dados de uma struct em uma string
                snprintf(registros_de_clientes[i_cliente], sizeof(registros_de_clientes[i_cliente])," Cliente [%d]: %s cpf: %s telefone: %s \n",
                         i_cliente+1,cadastro2.nomeDoUsuario, cadastro2.cpf, cadastro2.telefone);

                i_cliente++;
                limpar_tela();


                break;
            case 3:
                 printf(" Você escolheu registrar aluguel! [3]\n");
                 linhas();
                 printf("Carros disponiveis: \n");
                 for(int cont = 0; cont < i_carro; cont++){
                        puts(registros_de_carros[cont]);
                    }

                break;
            case 4:
                while(true){
                    int indice_carro;
                    int dias;
                    printf(" Você escolheu calcular preço do aluguel! [4]\n");
                    for(int cont = 0; cont < i_carro; cont++){
                        puts(registros_de_carros[cont]);
                        printf("Diária: R$%.2f\n", valor_de_diaria[cont]);
                        linhas();
                    }
                    printf("Digite o índice do carro desejado para se calcular o aluguel: ");
                    scanf("%d", &indice_carro);
                    printf("Digite a quantidade de dias que o carro será utilizado: ");
                    scanf("%d", &dias);
                    limpar_tela();
                    printf("Consulta de Orçamento:\n");
                    linhas();
                    puts(registros_de_carros[indice_carro]);
                    printf("Valor total do aluguel com uso de %d dias: %.2f \n", dias,dias*valor_de_diaria[indice_carro]);
                    linhas();
                    printf("Deseja sair? [1 - Sim | 0 - Não]: ");
                    scanf("%d", &escolha_usuario);

                    limpar_tela();
                    if(escolha_usuario == 1){
                        break;
                    }else if(escolha_usuario == 0){
                        continue;
                    }else{
                        limpar_tela();
                        printf("Opção Inválida! Tente Novamente...\n");
                        linhas();
                    }
                    limpar_tela();
                }


                break;
            case 5:
                getchar();
                while(true){
                    printf(" Você escolheu ver a listagem de veículos disponíveis e alugados! [5]\n");
                    linhas();
                    for(int cont = 0; cont < i_carro; cont++){
                        puts(registros_de_carros[cont]);
                        printf("Diária: R$%.2f\n", valor_de_diaria[cont]);
                        linhas();
                    }

                    printf("Deseja sair da listagem? [1 - Sim]: ");
                    scanf("%d", &escolha_usuario);
                    if(escolha_usuario == 1){
                        limpar_tela();
                        break;
                    }else{
                        limpar_tela();
                        printf("Opção Inválida! Tente Novamente...\n");
                        linhas();
                        }
                }


                break;
            case 6:
                while(true){
                printf(" Você escolheu ver os créditos! [6]\n");
                linhas();
                printf("Desenvolvido por:\nLucca de Sena\nMaximus Feitoza\nLeonardo Lucas1\nCauã Augusto\nRyan Emanuel\n");
                linhas();
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
