#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "pilha.h"
#include "fila.h"
#include "arvore.h"


int main() {
    node *PILHA = (node *)malloc(sizeof(node));
    PILHA->prox = NULL;

    node *FILA = (node *)malloc(sizeof(node));
    FILA->prox = NULL;
    
    No *ARVORE = NULL;

    int opcao;

    do {
        printf("Escolha uma opção:\n");
        printf("(1) Pilha\n");
        printf("(2) Fila\n");
        printf("(3) Arvore\n");
        printf("(0) Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int opcaoPilha;

                do {
                    printf("\n--- Operacoes na Pilha ---\n");
                    printf("(1) Empilhar\n");
                    printf("(2) Desempilhar\n");
                    printf("(3) Imprimir Pilha\n");
                    printf("(4) Imprimir Topo\n");
                    printf("(5) Limpar Pilha\n");
                    printf("(0) Voltar ao Menu Principal\n");
                    printf("Opcao: ");
                    scanf("%d", &opcaoPilha);

                    switch (opcaoPilha) {
                        case 1:
                            empilha(PILHA);
                            break;
                        case 2:
                            desempilha(PILHA);
                            break;
                        case 3:
                            imprimePilha(PILHA);
                            break;
                        case 4:
                            imprimeTopo(PILHA);
                            break;
                        case 5:
                            limparPilha(PILHA);
                            break;
                        case 0:
                            printf("Voltando ao Menu Principal...\n");
                            break;
                        default:
                            printf("Opção invalida!\n");
                    }

                    printf("\n");
                } while (opcaoPilha != 0);

                break;
            }
            case 2: {
                int opcaoFila;

                do {
                    printf("\n--- Operacoes na Fila ---\n");
                    printf("(1) Enqueue\n");
                    printf("(2) Dequeue\n");
                    printf("(3) Imprimir Fila\n");
                    printf("(4) Maior Elemento\n");
                    printf("(5) Menor Elemento\n");
                    printf("(6) Limpar Fila\n");
                    printf("(0) Voltar ao Menu Principal\n");
                    printf("Opcao: ");
                    scanf("%d", &opcaoFila);

                    switch (opcaoFila) {
                        case 1:
                            enqueue(FILA);
                            break;
                        case 2:
                            dequeue(FILA);
                            break;
                        case 3:
                            imprimeFila(FILA);
                            break;
                        case 4:
                            maiorElementoFila(FILA);
                            break;
                        case 5:
                            menorElementoFila(FILA);
                            break;
                        case 6:
                            limparFila(FILA);
                            break;
                        case 0:
                            printf("Voltando ao Menu Principal...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }

                    printf("\n");
                } while (opcaoFila != 0);

                break;
            }
            case 3: {
                int opcaoArvore;

                do {
                    printf("\n--- Operações na Arvore ---\n");
                    printf("(1) Inserir Elemento\n");
                    printf("(2) Remover Elemento\n");
                    printf("(3) Imprimir Árvore\n");
                    printf("(4) Buscar Elemento\n");
                    printf("(5) Imprimir Ordenado Direita -> Raiz -> Esquerda\n");
                    printf("(6) Maior Elemento\n");
                    printf("(0) Voltar ao Menu Principal\n");
                    printf("Opcao: ");
                    scanf("%d", &opcaoArvore);

                    switch (opcaoArvore) {
                        case 1: {
                            int valor;
                            printf("Digite o valor a ser inserido: ");
                            scanf("%d", &valor);
                            ARVORE = inserir(ARVORE, valor);
                            break;
                        }
                        case 2: {
                            int item;
                            printf("Digite o valor a ser removido: ");
                            scanf("%d", &item);
                            ARVORE = remover(ARVORE, item);
                            break;
                        }
                        case 3:
                            imprime(ARVORE);
                            break;
                        case 4: {
                            int chave;
                            printf("Digite a chave a ser buscada: ");
                            scanf("%d", &chave);
                            No *encontrado = buscarElemento(ARVORE, chave);
                            if (encontrado != NULL)
                                printf("Elemento encontrado!\n");
                            else
                                printf("Elemento nao encontrado!\n");
                            break;
                        }
                        case 5:
                            imprimirOrdenado(ARVORE);
                            break;
                        case 6: {
                            int maior = maiorElemento(ARVORE);
                            printf("Maior elemento: %d\n", maior);
                            break;
                        }
                        case 0:
                            printf("Voltando ao Menu Principal...\n");
                            break;
                        default:
                            printf("Opção invalida!\n");
                    }

                    printf("\n");
                } while (opcaoArvore != 0);

                break;
            }    
            case 0:
                limparPilha(PILHA);
                limparFila(FILA);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

        printf("\n");
    } while (opcao != 0);

    free(PILHA);
    free(FILA);

    return 0;
}
