/*
 * Projet course -- Etape A : une seule voiture
 *
 * Une voiture (un thread) avance d'une distance aleatoire (1 a 10 m)
 * toutes les 500 ms jusqu'a atteindre 100 m, en affichant sa position
 * a chaque etape.
 *
 * Compilation : gcc race_step_A.c -o race_step_A -pthread
 * Execution   : ./race_step_A
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define DISTANCE_TOTALE 100

void *voiture(void *arg) {
    (void)arg;
    int position = 0;

    while (position < DISTANCE_TOTALE) {
        /* TODO : avancez "position" d'une distance aleatoire entre
         * 1 et 10 metres (utilisez rand() % 10 + 1), puis affichez
         * la position courante.
         */

        /* TODO : attendez 500 ms entre deux avancees (usleep(500000);). */
    }

    printf("Voiture arrivee !\n");
    return NULL;
}

int main(void) {
    srand(42); /* graine fixe pour des resultats reproductibles en TP */

    pthread_t tid;

    /* TODO : creez le thread "voiture" et attendez sa fin. */

    return 0;
}
