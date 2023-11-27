#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Enumerando as tarefas
struct tarefa {
    char titulo[50];
    char descricao[100];
    time_t data_criacao;
    struct tm prazo_conclusao; // Ajuste no tipo da estrutura para armazenar data
    int status;
};

typedef struct tarefa Tarefa;

// Para organizar e guardar as tarefas, um vetor
Tarefa tarefas[100];

// Função para cadastrar uma nova tarefa
void cadastrar_tarefa(Tarefa *tarefa) {
    // Solicita informações da tarefa ao usuário
    printf("Título: ");
    fgets(tarefa->titulo, 50, stdin);
    printf("Descrição: ");
    fgets(tarefa->descricao, 100, stdin);

    // Obtém a data atual
    tarefa->data_criacao = time(NULL);

    // Solicita prazo de conclusão ao usuário
    printf("Prazo de conclusão (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &tarefa->prazo_conclusao.tm_mday, &tarefa->prazo_conclusao.tm_mon, &tarefa->prazo_conclusao.tm_year);

    // Solicita status ao usuário
    printf("Status (0 - pendente, 1 - concluída): ");
    scanf("%d", &tarefa->status);
}

// Função para editar uma tarefa existente
void editar_tarefa(Tarefa *tarefa) {
    int opcao;

    // Solicita ao usuário a escolha do que editar
    printf("O que deseja editar?\n");
    printf("1 - Título\n");
    printf("2 - Descrição\n");
    printf("3 - Prazo de conclusão\n");
    printf("4 - Status\n");
    scanf("%d", &opcao);

    // Utiliza o switch para lidar com diferentes opções
    switch (opcao) {
        case 1:
            // Solicita novo título ao usuário
            printf("Novo título: ");
            getchar(); // Consumindo caractere de nova linha pendente
            fgets(tarefa->titulo, 50, stdin);
            break;
        case 2:
            // Solicita nova descrição ao usuário
            printf("Nova descrição: ");
            getchar(); // Consumindo caractere de nova linha pendente
            fgets(tarefa->descricao, 100, stdin);
            break;
        case 3:
            // Solicita novo prazo de conclusão ao usuário
            printf("Novo prazo de conclusão (dd/mm/aaaa): ");
            scanf("%d/%d/%d", &tarefa->prazo_conclusao.tm_mday, &tarefa->prazo_conclusao.tm_mon, &tarefa->prazo_conclusao.tm_year);
            break;
        case 4:
            // Solicita novo status ao usuário
            printf("Novo status (0 - pendente, 1 - concluída): ");
            scanf("%d", &tarefa->status);
            break;
    }
    printf("Tarefa editada com sucesso!\n");
}

int main() {

    // exemplo //
    Tarefa minha_tarefa;

    // Chamando as funções 
    cadastrar_tarefa(&minha_tarefa);
    editar_tarefa(&minha_tarefa);

    return 0;
}
