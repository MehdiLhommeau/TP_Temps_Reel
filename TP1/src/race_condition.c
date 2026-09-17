/*
 * Exercice dirige -- observer et mesurer une condition de course
 *
 * 5 threads incrementent un compteur global NB_ITER fois chacun,
 * sans aucune synchronisation. Le resultat final devrait etre
 * 5 * NB_ITER mais ne l'est generalement pas : c'est la condition
 * de course a observer et expliquer.
 *
 * Compilation : gcc race_condition.c -o race_condition -pthread
 * Execution   : ./race_condition            (NB_ITER par defaut)
 *               ./race_condition 100000     (NB_ITER = 100000)
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NB_THREADS 5

long compteur = 0;
long NB_ITER = 10; /* valeur par defaut, modifiable en argument */

void *incrementer(void *arg) {
    (void)arg;

    /* TODO (question 1) : remplacez la ligne ci-dessous par une boucle
     * de NB_ITER iterations qui incremente "compteur"
     * (compteur = compteur + 1;), SANS aucune synchronisation.
     */
    compteur = compteur + 1;

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        NB_ITER = atol(argv[1]);
    }

    pthread_t tids[NB_THREADS];

    for (int i = 0; i < NB_THREADS; i++) {
        pthread_create(&tids[i], NULL, incrementer, NULL);
    }

    for (int i = 0; i < NB_THREADS; i++) {
        pthread_join(tids[i], NULL);
    }

    printf("NB_ITER = %ld\n", NB_ITER);
    printf("Valeur attendue : %ld\n", NB_THREADS * NB_ITER);
    printf("Valeur obtenue  : %ld\n", compteur);

    /* TODO (question 4) : lancez ce programme plusieurs fois avec
     * NB_ITER = 1, puis 100, puis 100000, et notez a chaque fois
     * l'ecart entre "attendue" et "obtenue".
     */

    return 0;
}
