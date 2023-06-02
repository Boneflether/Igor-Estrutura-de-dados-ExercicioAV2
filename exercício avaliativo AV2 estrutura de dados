//Questão 1 ORDENAÇÃO
#include <stdio.h>

void bubbleSort(int *v, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int *v, int tam) {
    int j;
   for (int i = 1; i < tam; i++) {
       int temp = v[i];
       j = i - 1;
       while (j >= 0 && v[j] > temp) {
           v[j + 1] = v[j];
           j = j - 1;
       }
       v[j + 1] = temp;
   }
}
    
int main(){
    int vetor[] = {5,3,1,9,4,6,12,3};
    int opcao;
    
    printf("Digite 1 para usar bubbleSort ou 2 para insertionSort\n");
    scanf("%d",&opcao);
    
    switch (opcao){
        case 1: {
            bubbleSort(vetor, 8);
            printf("Vetor ordenado com bubbleSort eh: ");
            break;
        }
        case 2: {
            insertionSort(vetor, 8);
            printf("Vetor ordenado com insertionSort eh: ");
            break;
        }
        default: {
            printf("opcao invalida");
        }    
    }
    
    for(int i = 0; i < 8; i++){
        printf("%d, ", vetor[i]);
    }

    return 0;
}
