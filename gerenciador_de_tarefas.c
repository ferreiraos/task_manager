#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Enumerando as tarefas
struct tarefa {
    char titulo[50];
    char descricao[100];
    time_t data_criacao;
    struct tm prazo_conclusao;
    int status;
};

typedef struct tarefa Tarefa;

// Para organizar e guardar as tarefas, um vetor
Tarefa tarefas[100];
int total_tarefas = 0; // Mantém o controle do número total de tarefas

// Função para imprimir todas as tarefas do usuário
void imprimir_tarefas() {
    printf("----- Tarefas do Usuário -----\n");
    for (int i = 0; i < total_tarefas; i++) {
        printf("Tarefa %d:\n", i + 1);
        printf("  Título: %s", tarefas[i].titulo);
        printf("  Descrição: %s", tarefas[i].descricao);
        printf("  Data de Criação: %s", asctime(&tarefas[i].data_criacao));
        printf("  Prazo de Conclusão: %d/%d/%d\n", tarefas[i].prazo_conclusao.tm_mday, tarefas[i].prazo_conclusao.tm_mon + 1, tarefas[i].prazo_conclusao.tm_year + 1900);
        printf("  Status: %s\n", tarefas[i].status ? "Concluída" : "Pendente");
        printf("-----------------------------\n");
    }
}

// Função para cadastrar uma nova tarefa
void cadastrar_tarefa(Tarefa *tarefa) {
    printf("----- Cadastro de Tarefa -----\n");
    // ... (código anterior)

    // Adiciona a tarefa ao vetor e incrementa o total de tarefas
    tarefas[total_tarefas++] = *tarefa;

    // Imprime as tarefas após o cadastro
    imprimir_tarefas();
}

// Função para editar uma tarefa existente
void editar_tarefa(Tarefa *tarefa) {
    printf("----- Edição de Tarefa -----\n");
    // ... (código anterior)

    // Imprime as tarefas após a edição
    imprimir_tarefas();
}

int main() {
    // Exemplo de uso
    Tarefa minha_tarefa;

    // Chamando funções para exemplificar
    cadastrar_tarefa(&minha_tarefa);
    editar_tarefa(&minha_tarefa);

    return 0;
}
