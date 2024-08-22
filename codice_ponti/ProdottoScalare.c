#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void popolaArray(int *array, int size) {
    for(int i = 0; i < size; i++) {
        array[i] = rand() % 100 + 1;
    }
}
void visualizzaArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ",array[i]);
    }
}

int main(void) {

    int N,result=0;

    printf("\nDefinisci la grandezza dei vettori a e b: ");
    scanf("%d",&N);

    int *a = calloc(N,sizeof(int));
    int *b = calloc(N,sizeof(int));

    srand(time(NULL));
    popolaArray(a,N);
    popolaArray(b,N);

    printf("\nA: ");
    visualizzaArray(a,N);
    printf("\nB: ");
    visualizzaArray(b,N);

#pragma omp parallel for shared (a,b) reduction(+:result) //Si parallelizza il ciclo for.
        for(int i = 0; i < N; i++) {
            result += a[i]*b[i];
        }

    printf("\n\nIl risultato derivato dal prodotto scalare di a e b: %d\n",result);

    free(a);
    free(b);
    return 0;

}
