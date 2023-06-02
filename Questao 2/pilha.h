//Questão 2 - a
#include "node.h"

int vazia(node *PILHA) {
    if (PILHA->prox == NULL)
        return 1;
    else
        return 0;
}

void empilha(node *PILHA) {
    node *novo = (node *)malloc(sizeof(node));
    novo->prox = NULL;

    printf("Digite o novo item: ");
    scanf("%d", &novo->conteudo);

    if (vazia(PILHA))
        PILHA->prox = novo;
    else {
        node *tmp = PILHA->prox;
        while (tmp->prox != NULL) {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
}

void imprimePilha(node *PILHA) {
    if (vazia(PILHA)) {
        printf("PILHA vazia!\n\n");
        return;
    }
    node *tmp;
    tmp = PILHA->prox;
    printf("PILHA:");
    while (tmp != NULL) {
        printf("%3d ", tmp->conteudo);
        tmp = tmp->prox;
    }
    printf("\n");
}

void imprimeTopo(node *PILHA) {
    if (vazia(PILHA)) {
        printf("PILHA vazia!\n\n");
        return;
    }
    node *tmp;
    tmp = PILHA->prox;
    while (tmp != NULL) {
        if (tmp->prox == NULL) {
            printf("topo: %3d\n", tmp->conteudo);
        }
        tmp = tmp->prox;
        
    }

}

void desempilha(node *PILHA) {
    if (PILHA->prox == NULL) {
        printf("PILHA ja vazia\n\n");
        return;
    }
    else {
        node *ultimo = PILHA->prox;
        node *penultimo = PILHA;

        while (ultimo->prox != NULL) {
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        free(ultimo);
        penultimo->prox = NULL;
    }
}

void limparPilha(node *PILHA) {
    while (!vazia(PILHA)) {
        desempilha(PILHA);
    }
}
