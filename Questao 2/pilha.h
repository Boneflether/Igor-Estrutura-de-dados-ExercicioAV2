//Questão 2 - a
struct Node{
    int item;
    struct Node *prox;
};
typedef struct Node node;

int vazia(node *PILHA){
    if(PILHA->prox == NULL)
        return 1;
   else
        return 0;
}

void empilha(node *PILHA) {
    node *novo=(node *) malloc(sizeof(node));
    novo->prox = NULL;
    
    printf("Digite o novo item: ");
    scanf("%d", &novo->item);
    
    if(vazia(PILHA))
        PILHA->prox = novo;
    else{
        node *tmp = PILHA->prox;
        while(tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
    tam++;
}

void imprime(node *PILHA){
    if(vazia(PILHA)){
        printf("PILHA vazia!\n\n");
    return;
    }
    node *tmp;
    tmp = PILHA->prox;
    printf("\nPILHA:");
    while(tmp != NULL){
        printf("%3d", tmp->item);
        tmp = tmp->prox;
    }
    printf("\nQtde itens PILHA: %d", tam);
    printf("\n");
}

void imprimeTopo(node *PILHA){
    if(vazia(PILHA)){
        printf("PILHA vazia!\n\n");
    return;
    }
    node *tmp;
    tmp = PILHA->prox;
    while(tmp != NULL){
        if(temp->prox == NULL){
            printf("topo: %3d", tmp->item);
        }else{
            tmp = tmp->prox;
        }
    }
    printf("\nQtde itens PILHA: %d", tam);
    printf("\n");
}

void desempilha(node *PILHA){
    if(PILHA->prox == NULL){
        printf("PILHA ja vazia\n\n");
        return;
    }else{
        node *ultimo = PILHA->prox;
        node *penultimo = PILHA;
        
    while(ultimo->prox != NULL){
        penultimo = ultimo;
        ultimo = ultimo->prox;
        }
        free(ultimo);
        penultimo->prox = NULL;
        tam--;
    }
}

void limparFila(node *PILHA){
    while (!vazia(PILHA)){
        desempilha(PILHA);
    }
}
