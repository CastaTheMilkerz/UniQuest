#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int start, end, remaining;
    printf("Inserisci l'estremo inferiore dell'intervallo: ");
    scanf("%d", &start);
    printf("Inserisci l'estremo superiore dell'intervallo: ");
    scanf("%d", &end);
    getchar(); // legge e rimuove il carattere di invio dal buffer di input
    remaining = end - start + 1;

    int *array = (int *)malloc(remaining * sizeof(int)); // crea un array dinamico di dimensione "remaining"
    for (int i = 0; i < remaining; i++) {
        array[i] = start + i; // riempie l'array con i numeri dell'intervallo
    }

    srand(time(0)); // inizializza il generatore di numeri casuali con il tempo corrente

    printf("Premi Invio per generare un numero casuale.\n");

    while (remaining > 0) {
        getchar(); // attende l'input dell'utente
        int random_index = rand() % remaining; // genera un indice casuale nell'intervallo degli indici validi dell'array
        printf("%d ", array[random_index]);
        // elimina il numero dall'array spostando gli elementi successivi indietro di una posizione
        for (int i = random_index; i < remaining - 1; i++) {
            array[i] = array[i + 1];
        }
        remaining--;
        array = (int *)realloc(array, remaining * sizeof(int)); // ridimensiona l'array dinamico
    }

    printf("\nHai terminato l'intervallo.\n");
    free(array); // libera la memoria allocata per l'array dinamico
    return 0;
}
