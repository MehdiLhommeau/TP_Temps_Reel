/*
 * Projet course -- Etape B : deux voitures sans coordination d'affichage
 *
 * Deux threads executent la meme fonction "voiture" et affichent
 * chacun directement leur progression : observez le melange des
 * lignes a l'ecran, qui motive l'etape C (affichage centralise).
 *
 * Compilation : gcc race_step_B.c -o race_step_B -pthread
 * Execution   : ./race_step_B
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define DISTANCE_TOTALE 100
#define NB_VOITURES 2

void *voiture(void *arg) {
    int numero = *(int *)arg;
    int position = 0;

    while (position < DISTANCE_TOTALE) {
        int avance = rand() % 10 + 1;
        position += avance;
        if (position > DISTANCE_TOTALE) position = DISTANCE_TOTALE;

        printf("Voiture %d -> position %d/%d\n", numero, position, DISTANCE_TOTALE);

        usleep(500000);
    }

    printf("Voiture %d arrivee !\n", numero);
    return NULL;
}

int main(void) {
    srand(42);

    pthread_t tids[NB_VOITURES];
    int numeros[NB_VOITURES];

    /* TODO : creez NB_VOITURES threads executant "voiture", chacun
     * avec son propre numero (attention au piege de la variable de
     * boucle vu dans l'etape B de la serie threads !).
     */
    for (int i = 0; i < NB_VOITURES; i++) {
        numeros[i] = i;
        /* TODO : pthread_create(&tids[i], NULL, voiture, &numeros[i]); */
    }

    /* TODO : attendez tous les threads avec pthread_join(). */

    return 0;
}
