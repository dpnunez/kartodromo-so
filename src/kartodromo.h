#define KARTODROMO_H

#include <pthread.h>

#define NUM_KARTS 10
#define NUM_CAPACETES 10
#define NUM_GRUPOS 5 // Número de grupos de pessoas que chegam durante o dia

typedef struct {
    char nome[50];
    int idade;
} Piloto;

typedef struct {
    int karts_disponiveis;
    int capacetes_disponiveis;
    // pthread_mutex_t mutex_karts;
    // pthread_mutex_t mutex_capacetes;
    // pthread_cond_t cond_karts;
    // pthread_cond_t cond_capacetes;
} Kartodromo;

void inicializa_kartodromo(Kartodromo *k);
void destroi_kartodromo(Kartodromo *k);
void chegada_grupo(Kartodromo *k, int num_pilotos);
void imprime_kartodromo(Kartodromo *k);
