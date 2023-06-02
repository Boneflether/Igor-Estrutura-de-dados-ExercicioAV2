//Questão 2 - b
struct Node{
    int conteudo;
    struct Node *prox;
};
typedef struct Node node;

int EMPTY(node *FILA){
    if(FILA->prox == NULL)
        return 1;
   else
        return 0;
}

void enqueue(node *FILA){
    node *novo=(node *) malloc(sizeof(node));
    novo->prox = NULL;
    
    printf("Digite o novo item da fila: ");
    scanf("%d", &novo->conteudo);
    
    if(EMPTY(FILA))
        FILA->prox = novo;
    else{
        node *tmp = FILA->prox;
        while(tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
    tam++;
}

void dequeue(node *FILA){
    if(FILA->prox == NULL){
        printf("Fila esta vazia\n");
        return;
    }else{
        node *tmp = FILA->prox;
        FILA->prox = tmp->prox;
        tam--;
        free(tmp);
    }
}

void imprimeFila(node *FILA){
    if(vazia(FILA)){
        printf("FILA vazia!\n\n");
        return;
    }
    node *tmp;
    tmp = FILA->prox;
    printf("\nFILA:");
    while(tmp != NULL){
        printf("%3d", tmp->conteudo);
        tmp = tmp->prox;
    }
    printf("\nQtde itens FILA: %d", tam);
    printf("\n");
}

void limparFila(node *FILA){
    while (!vazia(FILA)){
        dequeue(FILA);
    }
}

void maiorElementoFila(node *FILA){
    if(vazia(FILA)){
        printf("FILA vazia!\n\n");
        return;
    }
    node *tmp;
    node *maior = FILA;
    tmp = FILA->prox;
    while(tmp != NULL){
        if(tmp->conteudo > maior->conteudo){
            maior = tmp;
        }
        tmp = tmp->prox;
    }
    printf("\nMaior item: %d", maior->conteudo);
    printf("\n");
}

void menorElementoFila(node *FILA){
    if(vazia(FILA)){
        printf("FILA vazia!\n\n");
        return;
    }
    node *tmp;
    node *menor = FILA;
    tmp = FILA->prox;
    while(tmp != NULL){
        if(tmp->conteudo < menor->conteudo){
            menor = tmp;
        }
        tmp = tmp->prox;
    }
    printf("\nMenor item: %d", maior->conteudo);
    printf("\n");
}
