#ifndef KARTODROMO_H
#define KARTODROMO_H

#include <pthread.h>

#define NUM_KARTS 10
#define NUM_CAPACETES 10

typedef struct {
    char nome[50];
    int idade;
} Piloto;

typedef struct {
    int karts_disponiveis;
    int capacetes_disponiveis;
    pthread_mutex_t mutex_karts;
    pthread_mutex_t mutex_capacetes;
    pthread_cond_t cond_karts;
    pthread_cond_t cond_capacetes;
} Kartodromo;

void inicializa_kartodromo(Kartodromo *k);
void destroi_kartodromo(Kartodromo *k);
void imprime_kartodromo(Kartodromo *k);

#endif // KARTODROMO_H
