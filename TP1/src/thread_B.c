/*
 * Serie progressive threads -- Etape B : N threads et le piege de la
 * variable de boucle
 *
 * But : creer N threads affichant chacun son numero d'ordre (0 a N-1).
 * Une premiere version (bugguee, en commentaire) illustre le piege
 * classique ; a vous d'ecrire la version corrigee.
 *
 * Compilation : gcc thread_B.c -o thread_B -pthread
 * Execution   : ./thread_B
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *afficher_numero(void *arg) {
    int numero = *(int *)arg;
    printf("Thread numero %d\n", numero);
    return NULL;
}

int main(int argc, char *argv[]) {
    int n = 5;
    if (argc > 1) {
        n = atoi(argv[1]);
    }

    pthread_t *tids = malloc(n * sizeof(pthread_t));

    /* ------------------------------------------------------------
     * Version buguee (a NE PAS reproduire) donnee ici pour reference :
     *
     * for (int i = 0; i < n; i++) {
     *     pthread_create(&tids[i], NULL, afficher_numero, &i);
     * }
     *
     * Probleme : &i pointe vers UNE SEULE variable partagee par tous
     * les threads, qui continue de changer pendant qu'ils demarrent.
     * ------------------------------------------------------------ */

    /* TODO : allouez un tableau d'entiers valeurs[n], remplissez-le
     * avec valeurs[i] = i, puis creez les n threads en passant a
     * chacun l'adresse de SA propre case valeurs[i] (et non &i).
     */
    int *valeurs = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        valeurs[i] = i;
        /* TODO : pthread_create(&tids[i], NULL, afficher_numero, &valeurs[i]); */
    }

    /* TODO : attendez chaque thread avec pthread_join() avant de
     * liberer la memoire.
     */

    free(valeurs);
    free(tids);
    return 0;
}
