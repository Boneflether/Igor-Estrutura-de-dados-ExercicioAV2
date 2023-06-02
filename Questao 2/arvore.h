typedef struct no {
    int chave;
    struct no *esquerda, *direita;
} No;

No *inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        No *novo = (No *)malloc(sizeof(No));
        novo->chave = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    else {
        if (valor < raiz->chave)
            raiz->esquerda = inserir(raiz->esquerda, valor);
        if (valor > raiz->chave)
            raiz->direita = inserir(raiz->direita, valor);
        return raiz;
    }
}

void imprime(No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        imprime(raiz->esquerda);
        imprime(raiz->direita);
    }
}

No *remover(No *raiz, int item) {
    if (raiz == NULL) {
        printf("Valor nao encontrado!\n");
        return raiz;
    }
    else {
        if (raiz->chave == item) {
            if (raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                return NULL;
            }
            else {
                if (raiz->esquerda == NULL || raiz->direita == NULL) {
                    No *aux;
                    if (raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    return aux;
                }
                else {
                    No *aux = raiz->esquerda;
                    while (aux->direita != NULL)
                        aux = aux->direita;
                    raiz->chave = aux->chave;
                    aux->chave = item;
                    raiz->esquerda = remover(raiz->esquerda, item);
                    return raiz;
                }
            }
        }
    }
    return raiz;
}

No *buscarElemento(No *raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave) {
        return raiz;
    }
    if (raiz->chave < chave) {
        return buscarElemento(raiz->direita, chave);
    }
    return buscarElemento(raiz->esquerda, chave);
}

void imprimirOrdenado(No *raiz) {
    if (raiz != NULL) {
        imprimirOrdenado(raiz->direita);
        printf("%d ", raiz->chave);
        imprimirOrdenado(raiz->esquerda);
    }
}

int maiorElemento(No *raiz) {
    if (raiz->direita == NULL) {
        return raiz->chave;
    }
    return maiorElemento(raiz->direita);
}
