#include <stdio.h>
#include <string.h>

#define MAX_TAREFAS 100

typedef enum {
    PERFIL_GESTOR,
    PERFIL_DESENVOLVEDOR
} TipoPerfil;

typedef enum {
    PRIORIDADE_BAIXA,
    PRIORIDADE_MEDIA,
    PRIORIDADE_ALTA
} Prioridade;

typedef enum {
    STATUS_PENDENTE,
    STATUS_EM_ANDAMENTO,
    STATUS_CONCLUIDO,
    STATUS_APROVADO
} Statustarefa;

typedef struct {
    int id;
    char nome[50];
    TipoPerfil perfil;
} Usuario;

typedef struct {
    int id;
    char titulo[100];
    char descricao[250];
    Prioridade prioridade;
    Statustarefa status;
    int id_gestor;
    int id_desenvolvedor;
} Tarefa;

void criar_tarefa(Tarefa lista[], int *total);
void listar_tarefas(Tarefa lista[], int total);
void menu_gestor(Tarefa lista[], int *total);

int main() {
    Tarefa listaTarefas[MAX_TAREFAS];
    int totalTarefas = 0;
    int opcao;

    do {
        printf("\n=============================\n");
        printf("    SISTEMA DE TAREFAS\n");
        printf("=============================\n");
        printf("1. Entrar como Gestor\n");
        printf("2. Entrar como Desenvolvedor\n");
        printf("0. Sair do Sistema\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menu_gestor(listaTarefas, &totalTarefas);
                break;
            case 2:
                printf("\n--- Modo Desenvolvedor (Em construcao) ---\n");
                break;
            case 0:
                printf("\nSaindo do sistema...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

void menu_gestor(Tarefa lista[], int *total) {
    int opcao_gestor;

    do {
        printf("\n--- MODO GESTOR ---\n");
        printf("1. Criar nova tarefa\n");
        printf("2. Listar todas as tarefas\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao_gestor);

        switch (opcao_gestor) {
            case 1:
                criar_tarefa(lista, total);
                break;
            case 2:
                listar_tarefas(lista, *total);
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao_gestor != 0);
}

void criar_tarefa(Tarefa lista[], int *total) {
    if (*total >= MAX_TAREFAS) {
        printf("\nLimite de tarefas atingido!\n");
        return;
    }

    printf("\n--- Criar Nova Tarefa ---\n");

    lista[*total].id = *total + 1;
    lista[*total].status = STATUS_PENDENTE;

    getchar();

    printf("Digite o titulo da tarefa: ");
    fgets(lista[*total].titulo, 100, stdin);
    lista[*total].titulo[strcspn(lista[*total].titulo, "\n")] = 0;

    printf("Digite a descricao: ");
    fgets(lista[*total].descricao, 250, stdin);
    lista[*total].descricao[strcspn(lista[*total].descricao, "\n")] = 0;

    printf("Prioridade (0 - Baixa, 1 - Media, 2 - Alta): ");
    scanf("%d", (int*)&lista[*total].prioridade);

    printf("ID do desenvolvedor designado: ");
    scanf("%d", &lista[*total].id_desenvolvedor);

    (*total)++;
    printf("\nTarefa criada com sucesso! (ID: %d)\n", lista[*total - 1].id);
}

void listar_tarefas(Tarefa lista[], int total) {
    if (total == 0) {
        printf("\nNenhuma tarefa cadastrada ate o momento.\n");
        return;
    }

    printf("\n--- LISTA DE TAREFAS CADASTRADAS ---\n");
    for (int i = 0; i < total; i++) {
        printf("ID: %d\n", lista[i].id);
        printf("Titulo: %s\n", lista[i].titulo);
        printf("Descricao: %s\n", lista[i].descricao);
        printf("Prioridade: %d | Status: %d | Dev ID: %d\n",
               lista[i].prioridade, lista[i].status, lista[i].id_desenvolvedor);
        printf("------------------------------------\n");
    }
}
