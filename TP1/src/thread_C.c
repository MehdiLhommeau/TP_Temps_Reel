/*
 * Serie progressive threads -- Etape C : recuperer les valeurs de
 * retour de N threads
 *
 * But : chaque thread calcule numero*numero et le retourne via
 * pthread_exit(). Le programme principal recupere tous les resultats
 * avec pthread_join() et les affiche.
 *
 * Compilation : gcc thread_C.c -o thread_C -pthread
 * Execution   : ./thread_C
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *calculer_carre(void *arg) {
    int numero = *(int *)arg;

    /* TODO : allouez un entier avec malloc, mettez-y numero*numero,
     * et retournez son adresse avec pthread_exit(...).
     */

    return NULL; /* <-- a remplacer par pthread_exit(resultat) */
}

int main(int argc, char *argv[]) {
    int n = 5;
    if (argc > 1) {
        n = atoi(argv[1]);
    }

    pthread_t *tids = malloc(n * sizeof(pthread_t));
    int *valeurs = malloc(n * sizeof(int));
    int *resultats = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        valeurs[i] = i;
        pthread_create(&tids[i], NULL, calculer_carre, &valeurs[i]);
    }

    for (int i = 0; i < n; i++) {
        void *retour;

        /* TODO : recuperez la valeur de retour du thread i avec
         * pthread_join(tids[i], &retour), convertissez retour en
         * (int *), stockez la valeur dans resultats[i], puis liberez
         * la memoire allouee par le thread.
         */
        (void)retour;
    }

    printf("Resultats : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", resultats[i]);
    }
    printf("\n");

    free(resultats);
    free(valeurs);
    free(tids);
    return 0;
}
