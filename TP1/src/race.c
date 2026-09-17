/*
 * Projet -- Simulation de course de voitures (etapes C et D)
 *
 * N voitures (threads) avancent en parallele sur une piste de 100 m.
 * Un tableau partage "position[]" est mis a jour par chaque thread ;
 * le thread principal affiche periodiquement l'etat de toutes les
 * voitures a partir de ce tableau (affichage centralise, etape C),
 * et la course se termine quand toutes les voitures sont arrivees
 * (generalisation a N voitures, etape D).
 *
 * Compilation : gcc race.c -o race -pthread
 * Execution   : ./race
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define DISTANCE_TOTALE 100
#define MAX_VOITURES 10
#define VITESSE_MIN 1
#define VITESSE_MAX 10
#define PERIODE_AFFICHAGE_US 500000

int nb_voitures;
int position[MAX_VOITURES];
int arrivee[MAX_VOITURES]; /* 0 = en course, 1 = arrivee */

/*
 * Fonction executee par chaque thread-voiture.
 * arg pointe vers l'indice (int) de la voiture dans les tableaux
 * position[] / arrivee[].
 */
void *voiture(void *arg) {
    /* TODO : recuperez le numero de la voiture a partir de "arg". */
    int numero = 0; /* <-- a corriger */

    while (position[numero] < DISTANCE_TOTALE) {
        /* TODO : tirez une vitesse aleatoire entre VITESSE_MIN et
         * VITESSE_MAX (rand() % (VITESSE_MAX - VITESSE_MIN + 1) + VITESSE_MIN),
         * puis ajoutez-la a position[numero] (sans depasser
         * DISTANCE_TOTALE).
         */

        usleep(PERIODE_AFFICHAGE_US);
    }

    /* TODO : marquez la voiture comme arrivee dans le tableau arrivee[]. */

    return NULL;
}

/*
 * Affiche l'etat de la course pour toutes les voitures, sous forme
 * d'une barre de progression par voiture.
 */
void print_race(void) {
    system("clear");
    printf("=== Course de voitures (%d m) ===\n\n", DISTANCE_TOTALE);

    for (int i = 0; i < nb_voitures; i++) {
        int p = position[i];
        int nb_barres = p * 40 / DISTANCE_TOTALE;

        printf("Voiture %2d [", i);
        for (int b = 0; b < 40; b++) {
            printf(b < nb_barres ? "=" : " ");
        }
        printf("] %3d/%d m%s\n", p, DISTANCE_TOTALE,
               arrivee[i] ? "  ARRIVEE" : "");
    }
}

/* Renvoie 1 si toutes les voitures sont arrivees, 0 sinon. */
int course_terminee(void) {
    /* TODO : parcourez le tableau arrivee[] ; si une voiture n'est
     * pas encore arrivee, renvoyez 0. Si toutes sont arrivees,
     * renvoyez 1.
     */
    return 1; /* <-- a corriger */
}

int main(void) {
    printf("Nombre de voitures (2-%d) : ", MAX_VOITURES);
    if (scanf("%d", &nb_voitures) != 1
        || nb_voitures < 2 || nb_voitures > MAX_VOITURES) {
        fprintf(stderr, "Nombre de voitures invalide.\n");
        return 1;
    }

    srand(42); /* graine fixe pour des courses reproductibles en TP */

    pthread_t tids[MAX_VOITURES];
    int numeros[MAX_VOITURES];

    for (int i = 0; i < nb_voitures; i++) {
        position[i] = 0;
        arrivee[i] = 0;
        numeros[i] = i;
    }

    /* TODO : creez un thread par voiture (pthread_create), en
     * passant a chacun l'adresse de SA case dans numeros[].
     */
    for (int i = 0; i < nb_voitures; i++) {
        /* pthread_create(&tids[i], NULL, voiture, &numeros[i]); */
    }

    /* TODO : boucle d'affichage en temps reel : tant que la course
     * n'est pas terminee (course_terminee() == 0), affichez l'etat
     * de la course (print_race()) et attendez PERIODE_AFFICHAGE_US.
     */
    while (!course_terminee()) {
        print_race();
        usleep(PERIODE_AFFICHAGE_US);
    }
    print_race();

    /* TODO : attendez la fin de tous les threads avec pthread_join(). */
    for (int i = 0; i < nb_voitures; i++) {
        /* pthread_join(tids[i], NULL); */
    }

    printf("\nCourse terminee !\n");
    return 0;
}
