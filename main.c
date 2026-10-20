#include <stdio.h>
#include <locale.h>

    setlocale(LC_ALL, "Portuguese");
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
void menu_gestor(Tarefa list[], int *total){
    int opcao_gestor;
    do{
        printf("\n---Modo Gestor---\n");
        printf("1. Criar nova tarefa\n");
        printf("2. Listar tarefas enviadas para revisao\n");
        printf("Encerrar sistema\n");
        printf("Esolha uma opcao: ");
        scanf("%d", &opcao_gestor);

        switch(opcao_gestor){
            case 1:
            printf("1. Criar nova tarefa\n");
            break;
            case 2:
            printf("2. Listar tarefas enviadas para revisao\n");
            break;
            case 0:
            printf("0. Encerar sistema\n");
            break;
            default:
            break;
        }
    } while (opcao_gestor !=0);

}
