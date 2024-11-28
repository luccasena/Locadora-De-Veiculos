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
        printf("[5] - Listagem de Veículos\n");
        printf("[6] - Listagem de Clientes\n");
        printf("[7] - Créditos\n");
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

// 2.2 - Estrutura para o contrato do aluguel:

typedef struct registra_aluguel{
    char carro[110];
    char cpf_cliente[13];
    int  diaria;
};


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

        if (scanf("%d", &tipo) != 1) {
                limpar_tela();
                printf("Opção Inválida! Tente novamente.\n");
                linhas();

                while (getchar() != '\n');
        }else{
            if (tipo >= 1 && tipo <= 3) {
                break;

           }else{
                limpar_tela();
                printf("Opção fora do intervalo permitido! Tente novamente.\n");
                linhas();
            }
            }
        }
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

        getchar();
        while(true){
            printf("Digite a diária do veiculo: ");

        if(scanf("%f", &cadastro->diaria) != 1) {
            limpar_tela();
            printf("Opção Inválida! Tente novamente.\n");
            linhas();
            while (getchar() != '\n');
        }else{
            break;

            }
        }
        limpar_tela();
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

// 3.3 - Função que irá mostrar os carros disponíveis da Locadora de Veículos:

void opcao_mostrar_carros(int i_carro, char registros_de_carros[][110], float valor_de_diaria[]){

    for(int cont = 0; cont < i_carro; cont++){
        puts(registros_de_carros[cont]);
        printf("Diária: R$%.2f\n", valor_de_diaria[cont]);
        linhas();
    }
}

// 3.4 - Função que irá mostrar os clientes registrados na Locadora:

void opcao_mostrar_clientes(int i_cliente, char registros_de_clientes[][110]){

    for(int cont = 0; cont < i_cliente; cont++){
        puts(registros_de_clientes[cont]);
        linhas();
    }


}

// 3.5 - Função que irá calcular o preço do aluguel, conforme a diária especificada anteriormente:

void opcao_calcular_aluguel(char registros_de_carros[][110], float valor_de_diaria[], int qnt_carros){
    int i_carro2, dias;

    if(qnt_carros == 0){
        printf("Opção Indisponível no momento...\nNenhum veículo cadastrado!\n");
        linhas();

    }else{
    while(true){
        printf("Digite o índice do carro desejado para se calcular o aluguel: ");

        if (scanf("%d", &i_carro2) != 1) {                  // Verifica se é um tipo diferente de inteiro.
            limpar_tela();
            linhas();
            printf("Opção Inválida! Tente novamente.\n");
            linhas();
            opcao_mostrar_carros(qnt_carros, registros_de_carros, valor_de_diaria);
            while (getchar() != '\n');                      // Limpa o buffer do Teclado.

        }else{
            if (i_carro2 >= 0 && i_carro2 < qnt_carros) {  // Verifica se o índice está no intervalo indicado.
                break;

           }else{
                limpar_tela();
                linhas();
                printf("Opção fora do intervalo permitido! Tente novamente...\n");
                linhas();
                opcao_mostrar_carros(qnt_carros, registros_de_carros, valor_de_diaria);

            }
        }
    }

    while(true){
        printf("Digite a quantidade de dias que o carro será utilizado: ");

        if (scanf("%d", &dias) != 1) {                  // Verifica se é um tipo diferente de inteiro.
            limpar_tela();
            linhas();
            printf("Opção Inválida! Tente novamente.\n");
            linhas();
            while (getchar() != '\n');                      // Limpa o buffer do Teclado.

        }else{
            break;
        }

    }


    limpar_tela();
    printf("Consulta de Orçamento:\n");
    linhas();
    puts(registros_de_carros[i_carro2]);
    printf("Valor total do aluguel com uso de %d dias: %.2f \n", dias,dias*valor_de_diaria[i_carro2]);
    linhas();
    }
}


/// ------------------------  4. Código Principal  -----------------------------//

int main(){
    // Função responsável por permitir acentuações no terminal:
    setlocale(LC_ALL,"");


    int escolha_usuario;
    int sair_ou_nao;

    // Configurações para o Registro de Carros:
    Carros cadastro_carro;


    char registro_carro[110] = "";                                  // Vai armazenar as informações fornecidas pelo usuário de um único carro.
    char registros_de_carros[30][110];                              // Vai armazenar os veículos registrados pelo usuário.
    float valor_de_diaria[30];                                      // Vai armazenar o valor da diária de cada veículo. Foi decidido criar um outro array para posteriormente manipula-los mais facilmente.

    int i_carro = 0;                                                // Índice que irá fazer o controle de quantos carros foram registrados no array "registros_de_carros".

    // Configurações para o Registro de Clientes:
    Clientes cadastro_cliente;


    char registro_cliente[110] = "";                                // Vai armazenar as informações fornecidas pelo usuário de um único cliente.
    char registros_de_clientes[30][110];                            // Vai armazenar os clientes registrados pelo usuário.

    int i_cliente = 0;                                              // Índice que irá fazer o controle de quantos carros foram registrados no array "registros_de_clientes".


    while(true){                                                    /// Esse while(true) será essencial para o funcionamento do nosso programa, pois será ele o responsável por permitir que o usuário fique presente no programa até ele digitar o valor 0.

        while(true){
            cabecalho();                                            // Tratamento de Erro: Aqui estamos nó certificando se o usuário irá digitar os índices corretamente
            linhas();
            printf("Selecione algum das opções acima conforme seu índice: ");

            if (scanf("%d", &escolha_usuario) != 1) {               // Verifica se é um tipo diferente de inteiro.
                limpar_tela();
                printf("Opção Inválida! Tente novamente.\n");
                while (getchar() != '\n');                          // Limpa o buffer do Teclado.

            }else{
                if (escolha_usuario >= 0 && escolha_usuario <= 7) { // Verifica se o índice está no intervalo indicado.
                    break;

            }   else {
                    limpar_tela();
                    printf("Opção fora do intervalo permitido! Tente novamente.\n");

                }
            }
        }

        limpar_tela();
        linhas();

        int veiculo = 0;
        switch(escolha_usuario){
            case 1:
                printf(" Você escolheu o cadastro de carros! [1]\n");
                linhas();

                opcao1_cadastrarVeiculos(&cadastro_carro);          // Leva para a Função que irá cadastrar os dados do usuário dentro da struct "cadastro_carro"

                linhas();
                                                                    // A função abaixo é responsável por concatenar os dados de uma struct em uma string:
                snprintf(registros_de_carros[i_carro], sizeof(registros_de_carros[i_carro])," Carro [%d]:\n Nome: %s Marca: %s Tipo: %s \n", i_carro,cadastro_carro.nome, cadastro_carro.marca, cadastro_carro.tipo);

                valor_de_diaria[i_carro] = cadastro_carro.diaria;   // Nesta linha, o valor da diária será armazenado em um array a parte.

                i_carro++;
                limpar_tela();

                int * ponteiro_i_carro;
                int i_carro_valor = i_carro;
                ponteiro_i_carro = &i_carro_valor;

                break;
            case 2:
                printf(" Você escolheu o cadastro de clientes! [2]\n");
                linhas();

                opcao2_cadastrarClientes(&cadastro_cliente);        // Leva para a Função que irá cadastrar os dados do usuário dentro da struct "cadastro_carro"

                linhas();
                                                                    // A função abaixo é responsável por concatenar os dados de uma struct em uma string:
                snprintf(registros_de_clientes[i_cliente], sizeof(registros_de_clientes[i_cliente])," Cliente [%d]: %s cpf: %s telefone: %s \n", i_cliente+1,cadastro_cliente.nomeDoUsuario, cadastro_cliente.cpf, cadastro_cliente.telefone);

                i_cliente++;
                limpar_tela();
                getchar();

                break;

            case 3:
                if(i_carro == 0){
                    printf("Opção Indisponível no momento...\nNenhum veículo cadastrado!\n");
                }else{
                    printf(" Voce escolheu registrar aluguel! [3]\n");
                    linhas();
                    int i , aux=0,veiculo = 0,id_carro , cont=0 , reposta_usuario;
                    char cpf_do_cliente[11];
                    int sair = 0;
                    struct registra_aluguel aluguel;
                    while(sair != 1){
                    if(*ponteiro_i_carro != 0){
                        printf("Carros disponiveis: \n");

                        opcao_mostrar_carros(i_carro, registros_de_carros, valor_de_diaria);

                        printf("Digite o ID do carro que ira ser alugado: ");
                        scanf("%d",&id_carro);
                        limpar_tela();
                        linhas();
                        printf("O carro %d foi selecionado \n",id_carro);
                        printf("Carro [%d]:\n Nome: %s Marca: %s Tipo: %s \n",id_carro,cadastro_carro.nome, cadastro_carro.marca, cadastro_carro.tipo);
                        printf("Vamos para os dados do aluguel! \n");
                        fflush(stdin);
                        linhas();
                        printf("Digite o cpf do cliente:");
                        fgets(aluguel.cpf_cliente, sizeof(aluguel.cpf_cliente), stdin);
                        fflush(stdin);
                        linhas();
                        printf("Digite o numero de diarias:");
                        fgets(aluguel.cpf_cliente, sizeof(aluguel.cpf_cliente), stdin);
                        linhas();
                        printf("Otimo!\nAgora para verificarmos\ntem certeza que deseja registrar o aluguel desse carro?\n");
                        linhas();
                        printf("Carro[%d]:\nNome:%sMarca:%sTipo:%s\n",id_carro,cadastro_carro.nome, cadastro_carro.marca, cadastro_carro.tipo);
                        linhas();
                        printf("Digite 1 para Sim\nDigite 2 para Nao\n");
                        scanf("%d",&reposta_usuario);
                        if(reposta_usuario == 1){
                            printf("ALuguel registrado com sucesso \n");
                            printf("Deseja sair da listagem? [1 - Sim]:");
                            scanf("%d",&sair);
                            if(sair == 1){
                                limpar_tela();
                                break;
                            }
                            else{
                                limpar_tela();
                                printf("Opcao Invalida! Tente Novamente...\n");
                                linhas();
                            }
                        }
                        else{
                            limpar_tela();
                        }
                    }
                }
            }
            break;
            case 4:
                while(true){

                    printf(" Você escolheu calcular preço do aluguel! [4]\n");
                    linhas();

                    opcao_mostrar_carros(i_carro, registros_de_carros, valor_de_diaria);

                    opcao_calcular_aluguel(registros_de_carros, valor_de_diaria, i_carro);

                    while(true){
                        printf("Deseja sair? [1 - Sim | 0 - Não]: ");
                        if (scanf("%d", &sair_ou_nao) != 1) {               // Verifica se é um tipo diferente de inteiro.
                            limpar_tela();
                            printf("Opção Inválida! Tente novamente.\n");
                            linhas();
                            while (getchar() != '\n');                      // Limpa o buffer do Teclado.

                        }else{
                            if (sair_ou_nao == 0 || sair_ou_nao == 1) {     // Verifica se o índice está no intervalo indicado.
                                limpar_tela();
                                break;

                           }else{
                                limpar_tela();
                                printf("Opção fora do intervalo permitido! Tente novamente...\n");
                                linhas();

                            }
                        }
                    }
                    if(sair_ou_nao == 1){
                        break;
                    }
                }


                break;
            case 5:
                getchar();

                while(true){
                    if(i_carro == 0){
                        printf("Opção Indisponível no momento...\nNenhum veículo cadastrado!\n");
                        break;
                    }else{
                        printf(" Você escolheu ver a listagem de veículos disponíveis e alugados! [5]\n");
                        linhas();

                        opcao_mostrar_carros(i_carro, registros_de_carros, valor_de_diaria);

                        printf("Deseja sair? [1 - Sim]: ");
                        if (scanf("%d", &sair_ou_nao) != 1){                    // Verifica se é um tipo diferente de inteiro.
                            limpar_tela();
                            printf("Opção Inválida! Tente novamente.\n");
                            linhas();
                            while (getchar() != '\n');                          // Limpa o buffer do Teclado.

                        }else{
                            if (sair_ou_nao == 1) {                             // Verifica se o índice está no intervalo indicado.
                                limpar_tela();
                                break;

                            }else{
                                limpar_tela();
                                printf("Opção fora do intervalo permitido! Tente novamente...\n");
                                linhas();
                            }
                        }
                    }
                }

                break;
            case 6:
                getchar();
                if(i_carro == 0){
                    printf("Opção Indisponível no momento...\nNenhum cliente cadastrado!\n");
                }else{
                    while(true){

                        printf(" Você escolheu ver a listagem de Clientes cadastrados! [6]\n");
                        linhas();

                        opcao_mostrar_clientes(i_cliente, registros_de_clientes);

                        printf("Deseja sair? [1 - Sim]: ");
                        if (scanf("%d", &sair_ou_nao) != 1){                    // Verifica se é um tipo diferente de inteiro.
                            limpar_tela();
                            printf("Opção Inválida! Tente novamente.\n");
                            linhas();
                            while (getchar() != '\n');                          // Limpa o buffer do Teclado.

                        }else{
                            if (sair_ou_nao == 1) {                             // Verifica se o índice está no intervalo indicado.
                                limpar_tela();
                                break;

                        }else{
                            limpar_tela();
                            printf("Opção fora do intervalo permitido! Tente novamente...\n");
                            linhas();
                            }
                        }
                    }
                }

                break;
            case 7:
                while(true){
                    printf(" Você escolheu ver os créditos! [7]\n");
                    linhas();
                    printf("Desenvolvido por:\nLucca de Sena\nMaximus Feitoza\nLeonardo Lucas1\nCauã Augusto\nRyan Emanuel\n");
                    linhas();
                    printf("Deseja sair da listagem? [1 - Sim]: ");  // Tratamento!
                    if (scanf("%d", &sair_ou_nao) != 1){                    // Verifica se é um tipo diferente de inteiro.
                        limpar_tela();
                        printf("Opção Inválida! Tente novamente.\n");
                        linhas();
                        while (getchar() != '\n');                          // Limpa o buffer do Teclado.

                    }else{
                        if (sair_ou_nao == 1) {                             // Verifica se o índice está no intervalo indicado.
                            limpar_tela();
                            break;

                       }else{
                            limpar_tela();
                            printf("Opção fora do intervalo permitido! Tente novamente...\n");
                            linhas();
                            }
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
