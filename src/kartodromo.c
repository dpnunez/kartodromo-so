#include "kartodromo.h"
#include <stdio.h>
#include <stdlib.h>

void inicializa_kartodromo(Kartodromo *k) {
    k->karts_disponiveis = NUM_KARTS;
    k->capacetes_disponiveis = NUM_CAPACETES;
    pthread_mutex_init(&k->mutex_karts, NULL);
    pthread_mutex_init(&k->mutex_capacetes, NULL);
    pthread_cond_init(&k->cond_karts, NULL);
    pthread_cond_init(&k->cond_capacetes, NULL);
}

void destroi_kartodromo(Kartodromo *k) {
    pthread_mutex_destroy(&k->mutex_karts);
    pthread_mutex_destroy(&k->mutex_capacetes);
    pthread_cond_destroy(&k->cond_karts);
    pthread_cond_destroy(&k->cond_capacetes);
}

void imprime_kartodromo(Kartodromo *k) {
    printf("Kartódromo:\n");
    printf("Karts disponíveis: %d\n", k->karts_disponiveis);
    printf("Capacetes disponíveis: %d\n", k->capacetes_disponiveis);
}