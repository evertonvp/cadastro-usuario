#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ClienteS 1000

struct Cliente {
    int identificador;
    char nome[50];
    char genero[15];
    char email[45];
    double altura;
    int vacina;
    char endereco[90];
};

int gerarIdentificador() {
    return rand() % 10000 + 1;
}

void imprimirCliente(struct Cliente Cliente) {
    printf("ID: %d\n", Cliente.identificador);
    printf("Nome Completo: %s\n", Cliente.nome);
    printf("Endereço de Email: %s\n", Cliente.email);
    printf("Gênero: %s\n", Cliente.genero);
    printf("Localização: %s\n", Cliente.endereco);
    printf("Altura: %.2f metros\n", Cliente.altura);
    printf("Status de Vacinação: %d\n", Cliente.vacina);
    printf("\n");
}

void adicionarCliente(struct Cliente Clientes[], int *totalClientes) {
    if (*totalClientes < MAX_ClienteS) {
        struct Cliente novoCliente;
        novoCliente.identificador = gerarIdentificador();

        printf("Informe o Nome Completo: ");
        scanf(" %[^\n]s", novoCliente.nome);

        printf("Informe o Endereço de Email: ");
        scanf(" %s", novoCliente.email);

        if (strchr(novoCliente.email, '@') == NULL) {
            printf("Email inválido. Certifique-se de incluir o caractere '@'.\n");
            return;
        }

        printf("Informe o Gênero (Feminino/Masculino/Outro): ");
        scanf(" %s", novoCliente.genero);

        if (strcmp(novoCliente.genero, "Feminino") != 0 && strcmp(novoCliente.genero, "Masculino") != 0 &&
            strcmp(novoCliente.genero, "Outro") != 0) {
            printf("Gênero inválido. Escolha Feminino, Masculino ou Outro.\n");
            return;
        }

        printf("Informe a Localização: ");
        scanf(" %[^\n]s", novoCliente.endereco);

        printf("Informe a Altura (entre 1 e 2 metros): ");
        scanf("%lf", &novoCliente.altura);

        if (novoCliente.altura < 1 || novoCliente.altura > 2) {
            printf("Altura inválida. A altura deve estar entre 1 e 2 metros.\n");
            return;
        }

        printf("A pessoa recebeu a Vacina? (1 para sim, 0 para não): ");
        scanf("%d", &novoCliente.vacina);

        if (novoCliente.vacina != 0 && novoCliente.vacina != 1) {
            printf("Opção de vacinação inválida. Digite 1 para sim ou 0 para não.\n");
            return;
        }

        Clientes[*totalClientes] = novoCliente;
        (*totalClientes)++;
        printf("Usuário adicionado com sucesso!\n");
    } else {
        printf("Limite máximo de usuários alcançado.\n");
    }
}

void editarCliente(struct Cliente Clientes[], int totalClientes) {
    int idEditar;
    printf("Informe o ID do usuário que deseja editar: ");
    scanf("%d", &idEditar);

    for (int i = 0; i < totalClientes; i++) {
        if (Clientes[i].identificador == idEditar) {
            printf("Informe o novo Nome Completo: ");
            scanf(" %[^\n]s", Clientes[i].nome);

            printf("Informe o novo Endereço de Email: ");
            scanf(" %s", Clientes[i].email);

            if (strchr(Clientes[i].email, '@') == NULL) {
                printf("Email inválido. Certifique-se de incluir o caractere '@'.\n");
                return;
            }

            printf("Informe o novo Gênero (Feminino/Masculino/Outro): ");
            scanf(" %s", Clientes[i].genero);

            if (strcmp(Clientes[i].genero, "Feminino") != 0 && strcmp(Clientes[i].genero, "Masculino") != 0 &&
                strcmp(Clientes[i].genero, "Outro") != 0) {
                printf("Gênero inválido. Escolha Feminino, Masculino ou Outro.\n");
                return;
            }

            printf("Informe o novo Endereço: ");
            scanf(" %[^\n]s", Clientes[i].endereco);

            printf("Informe a nova Altura (entre 1 e 2 metros): ");
            scanf("%lf", &Clientes[i].altura);

            if (Clientes[i].altura < 1 || Clientes[i].altura > 2) {
                printf("Altura inválida. A altura deve estar entre 1 e 2 metros.\n");
                return;
            }

            printf("A pessoa recebeu a Vacina? (1 para sim, 0 para não): ");
            scanf("%d", &Clientes[i].vacina);

            if (Clientes[i].vacina != 0 && Clientes[i].vacina != 1) {
                printf("Opção de vacinação inválida. Digite 1 para sim ou 0 para não.\n");
                return;
            }

            printf("Usuário editado com sucesso!\n");
            return;
        }
    }

    printf("Usuário não encontrado.\n");
}

void excluirCliente(struct Cliente Clientes[], int *totalClientes) {
    int idExcluir;
    printf("Informe o ID do usuário que deseja excluir: ");
    scanf("%d", &idExcluir);

    for (int i = 0; i < *totalClientes; i++) {
        if (Clientes[i].identificador == idExcluir) {
            for (int j = i; j < *totalClientes - 1; j++) {
                Clientes[j] = Clientes[j + 1];
            }
            (*totalClientes)--;
            printf("Usuário excluído com sucesso!\n");
            return;
        }
    }

    printf("Usuário não encontrado.\n");
}

void buscarClientePorEmail(struct Cliente Clientes[], int totalClientes) {
    char emailBuscar[50];
    printf("Informe o email do usuário que deseja buscar: ");
    scanf(" %s", emailBuscar);

    for (int i = 0; i < totalClientes; i++) {
        if (strcmp(Clientes[i].email, emailBuscar) == 0) {
            imprimirCliente(Clientes[i]);
            return;
        }
    }

    printf("Usuário não encontrado.\n");
}

void imprimirTodosClientes(struct Cliente Clientes[], int totalClientes) {
    for (int i = 0; i < totalClientes; i++) {
        imprimirCliente(Clientes[i]);
    }
}

int main() {
    struct Cliente Clientes[MAX_ClienteS];
    int totalClientes = 0;
    char opcao;

    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Adicionar usuário\n");
        printf("2. Editar usuário\n");
        printf("3. Excluir usuário\n");
        printf("4. Buscar usuário por email\n");
        printf("5. Imprimir todos os usuários\n");
        printf("0. Sair\n");

        printf("Opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                adicionarCliente(Clientes, &totalClientes);
                break;
            case '2':
                editarCliente(Clientes, totalClientes);
                break;
            case '3':
                excluirCliente(Clientes, &totalClientes);
                break;
            case '4':
                buscarClientePorEmail(Clientes, totalClientes);
                break;
            case '5':
                imprimirTodosClientes(Clientes, totalClientes);
                break;
            case '0':
                printf("Encerrando o programa. Até logo!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != '0');

    return 0;
}
