#include <stdio.h>

    typedef enum{
        PERFIL_GESTOR,
        PERFIL_DESENVOLVEDOR
    }TipoPerfil;
    typedef enum{
        PRIORIDADE_BAIXA,
        PRIORIDADE_MEDIA,
        PRIORIDADE_ALTA
    }Prioridade;
    typedef enum{
        STATUS_PENDENTE,
        STATUS_EM_ANDAMENTO,
        STATUS_CONCLUIDO,
        STATUS_APROVADO
    }Statustarefa;

    typedef struct{
        int id;
        char nome [50];
        TipoPerfil perfil;
    }Usuario;
    typedef struct{
        int id;
        char titulo[100];
        char descricao[250];
        Prioridade prioridade;
        Statustarefa status;
        int id_gestor;
        int id_desenvolvedor;
    }Tarefa;

#define TAREFA MAXIMA 100
int main(){

    int opcao;
    do{
        printf("1. Entar como Gestor\n");
        printf("2. Entar como Desenvolvedor\n");
        printf("0. Sair do Sistema\n");
        scanf("%d", &opcao);
            switch(opcao){
                case 1:
                printf ("\n---Modo Gestor---\n");
                break;
                case 2:
                printf ("\n---Modo Desenvolvedor---\n");
                break;
                case 0:
                printf ("\n---Sair---\n");
                break;
                default:
                break;
            }
    } while (opcao !=0);
}
void menu_gestor(Tarefa lista[], int *total) {
    int opcao_gestor;

    do {
        printf("\n--- Modo Gestor ---\n");
        printf("1. Criar nova tarefa\n");
        printf("2. Listar tarefas enviadas para revisao\n");
        printf("0. Encerar sistema\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao_gestor);

            switch (opcao_gestor) {
                case 1:
                printf("1. Criar nova tarefa\n");
                criar_tarefa(lista, total);
                break;
                case 2:
                printf("2. Listar tarefas enviadas para revisao\n");
                break;
                case 0:
                printf("Voltagem ao menu principal...\n");
                break;
                default:
                printf("Opcao invalida!\n");
                break;
        }

    } while (opcao_gestor != 0);
}
void criar_tarefa(Tarefa lista[], int *total){
    printf("\n---Criar nova tarefa---\n");

    lista[*total].id= *total + 1;
    lista[*total].status = STATUS_PENDENTE;

    getchar();

    printf("Digite o tirulo da tarefa: ");
    fgets(lista[*total].titulo, 100, stdin);
    printf("Digite a descricao: ");
    fgets(lista[*total].descricao, 250, stdin);
    printf("Prioridade (0 - Baixa, 1 - Media, 2 - ALta): ");
    scanf("%d", (int*)&lista[*total].prioridade);
    printf("ID do desenvolvedor designado: ");
    scanf("%d", &lista[*total].id_desenvolvedor);
    (*total)++;
    printf("\nTarefa criado com sucesso! (ID: %d)\n", lista[*total - 1].id);
    break;
}
void listar_tarefas(Tarefa lista[], int total) {
    if (total == 0) {
        printf("\nNenhuma tarefa cadastrada ate o momento.\n");
        return;
    }

    printf("\n--- LISTA DE TAREFAS CADASTRADAS ---\n");
    for (int i = 0; i < total; i++) {
        printf("ID: %d\n", lista[i].id);
        printf("Titulo: %s", lista[i].titulo);
        printf("Descricao: %s", lista[i].descricao);
        printf("Prioridade: %d | Status: %d | Dev ID: %d\n",
               lista[i].prioridade, lista[i].status, lista[i].id_desenvolvedor);
        printf("------------------------------------\n");
    }
}
