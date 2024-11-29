#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>      // Para usar isdigit()

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
        printf("[5] - Contratos de Aluguéis\n");
        printf("[6] - Listagem de Veículos\n");
        printf("[7] - Listagem de Clientes\n");
        printf("[8] - Créditos\n");
        printf("[0] - Sair\n");
        linhas();
        printf("Utilize os índices [x] para poder acessar as funcionalidade!\n");
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
        char    cpf[20];
        char    telefone[20];
}Clientes;

// 2.2 - Estrutura para o contrato do aluguel:

typedef struct RegistraAluguel{
    char carro[110];
    char cpf_cliente[13];
    char numero_telefone[11];
    int  diaria;
}Aluguel;


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

void opcao2_cadastrarClientes(Clientes *cadastro2) {
    getchar();

    printf("Digite seu nome: ");
    fgets(cadastro2->nomeDoUsuario, sizeof(cadastro2->nomeDoUsuario), stdin);

    printf("Digite seu CPF: ");
    fgets(cadastro2->cpf, sizeof(cadastro2->cpf), stdin);

    printf("Digite seu telefone: ");
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

// 3.6 - Função que irá calcular o preço do aluguel, conforme a diária especificada anteriormente:

void opcao_mostrar_contratos(int i_aluguel, char registros_de_alugueis[][110]){

    for(int cont = 0; cont < i_aluguel; cont++){
        puts(registros_de_alugueis[cont]);
        linhas();
    }

}

/// ------------------------  4. Código Principal  -----------------------------//

int main(){
    // Função responsável por permitir acentuações no terminal:
    setlocale(LC_ALL,"");


    int escolha_usuario;
    int sair_ou_nao;

    // 1. Configurações para o Registro de Carros:
    Carros cadastro_carro;


    char registro_carro[110] = "";                                  // Vai armazenar as informações fornecidas pelo usuário de um único carro.
    char registros_de_carros[30][110];                              // Vai armazenar os veículos registrados pelo usuário.
    float valor_de_diaria[30];                                      // Vai armazenar o valor da diária de cada veículo. Foi decidido criar um outro array para posteriormente manipula-los mais facilmente.

    int i_carro = 0;                                                // Índice que irá fazer o controle de quantos carros foram registrados no array "registros_de_carros".

    // 2. Configurações para o Registro de Clientes:
    Clientes cadastro_cliente;


    char registro_cliente[110] = "";                                // Vai armazenar as informações fornecidas pelo usuário de um único cliente.
    char registros_de_clientes[30][110];                            // Vai armazenar os clientes registrados pelo usuário.

    int i_cliente = 0;                                              // Índice que irá fazer o controle de quantos carros foram registrados no array "registros_de_clientes".

    // 3. Configurações para o Registro de Aluguel:
    Aluguel cadastro_aluguel;


    char registro_aluguel[110] = "";                                // Vai armazenar as informações fornecidas pelo usuário de um único aluguel.
    char registros_de_alugueis[30][256];                            // Vai armazenar os alugueis registrados pelo usuário.

    int i_aluguel = 0;                                              // Índice que irá fazer o controle de quantos alugueis foram registrados no array "registros_de_alugueis".


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
                if (escolha_usuario >= 0 && escolha_usuario <= 8) { // Verifica se o índice está no intervalo indicado.
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
                    printf("Opção Indisponível no momento...\nNenhum Carro Cadastrado!\nImpossível de realizar um contrato!\n");
                    break;
                }else{
                    printf("Você escolheu registrar aluguel! [3]\n");
                    linhas();

                    int sair = 0, id_carro, diarias;
                    char numero_do_cliente[11];

                    while(true) {
                        printf("Carros disponíveis:\n");
                        opcao_mostrar_carros(i_carro, registros_de_carros, valor_de_diaria);

                        printf("Digite o ID do carro que será alugado: ");
                        if(scanf("%d", &id_carro) != 1) {
                            limpar_tela();
                            printf("Opção Inválida! Tente novamente.\n");
                            linhas();
                            while (getchar() != '\n'); // Limpa o buffer
                        }else{
                            if (id_carro >= 0 && id_carro < i_carro) {  // Verifica se o índice está no intervalo indicado.
                                break;

                            }else{
                                limpar_tela();

                                printf("Opção fora do intervalo permitido! Tente novamente...\n");
                                linhas();
                                }

                            }
                        }

                            limpar_tela();
                            printf("Carro selecionado:\n");
                            linhas;
                            puts(registros_de_carros[id_carro]);
                            linhas();

                            while (true){
                                printf("Digite o número do cliente: ");
                                scanf("%s", numero_do_cliente);
                                getchar();

                                bool numero_valido = true;
                                for (int i = 0; i < strlen(numero_do_cliente); i++) {
                                    if (!isdigit(numero_do_cliente[i])  || strlen(numero_do_cliente) < 11 || strlen(numero_do_cliente) > 11) {
                                        numero_valido = false;
                                        break;
                                    }
                                }

                                if (!numero_valido) {
                                    limpar_tela();
                                    printf("Opção Inválida ou Número incorreto! Tente novamente...\n");
                                    linhas();
                                } else {
                                    break;
                                }
                            }

                            // Validação do número de diárias
                            while (true) {
                                printf("Digite o número de diárias: ");
                                if (scanf("%d", &diarias) != 1 || diarias <= 0) {
                                    limpar_tela();
                                    printf("Opção Inválida! Tente novamente.\n");
                                    linhas();
                                    while (getchar() != '\n'); // Limpa o buffer
                                } else {
                                    break;
                                }
                            }

                            limpar_tela();
                            linhas();
                            printf("Resumo do Aluguel:\n");
                            linhas();
                            printf("%s", registros_de_carros[id_carro]);
                            printf("\n Número de Telefone do cliente: %s \n", numero_do_cliente);
                            printf(" Número de diárias: %d\n", diarias);
                            printf(" Total: R$%.2f\n", valor_de_diaria[id_carro] * diarias);
                            linhas();

                            printf("Deseja confirmar o aluguel? [1 - Sim | 0 - Não]: ");
                            int confirmar;
                            scanf("%d", &confirmar);
                            if (confirmar == 1) {

                                strcpy(cadastro_aluguel.carro, registros_de_carros[id_carro]);
                                strcpy(cadastro_aluguel.numero_telefone, numero_do_cliente);
                                cadastro_aluguel.diaria = diarias;

                                snprintf(registros_de_alugueis[i_aluguel], sizeof(registros_de_alugueis[i_aluguel])," Cliente [%d]: %s Telefone: %s \n", i_aluguel+1,cadastro_aluguel.carro, cadastro_aluguel.numero_telefone);

                                i_aluguel++;
                                limpar_tela();
                                printf("Aluguel registrado com sucesso!\n");
                            } else {
                                limpar_tela();
                                printf("Operação cancelada.\n");
                            }

                    break;
                }

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
                if(i_aluguel == 0){
                    printf("Opção Indisponível no momento...\nNenhum contrato registrado!\n");
                    break;
                }else{
                    printf(" Você escolheu ver os Contratos de Aluguéis! [5] - \n");
                    linhas();

                    opcao_mostrar_contratos(i_aluguel, registros_de_alugueis);

                    while(true){
                        printf("Deseja sair? [1 - Sim | 0 - Não]: ");
                        if (scanf("%d", &sair_ou_nao) != 1) {               // Verifica se é um tipo diferente de inteiro.
                            limpar_tela();
                            printf("Opção Inválida! Tente novamente...\n");
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
            }

            break;

            case 6:
                getchar();

                while(true){
                    if(i_carro == 0){
                        printf("Opção Indisponível no momento...\nNenhum veículo cadastrado!\n");
                        break;
                    }else{
                        printf(" Você escolheu ver a listagem de veículos disponíveis! [6]\n");
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

            case 7:
                getchar();
                if(i_cliente == 0){
                    printf("Opção Indisponível no momento...\nNenhum cliente cadastrado!\n");

                }else{
                    while(true){

                        printf(" Você escolheu ver a listagem de Clientes cadastrados! [7]\n");
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

            case 8:
                while(true){
                    printf(" Você escolheu ver os créditos! [8]\n");
                    linhas();
                    printf("Desenvolvido por:\nLucca de Sena\nMaximus Feitoza\nLeonardo Lucas\nCauã Augusto\nRyan Emanuel\n");
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
