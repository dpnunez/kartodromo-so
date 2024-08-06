#include "kartodromo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa_kartodromo(Kartodromo *k) {
    k->karts_disponiveis = NUM_KARTS;
    k->capacetes_disponiveis = NUM_CAPACETES;
    // pthread_mutex_init(&k->mutex_karts, NULL);
    // pthread_mutex_init(&k->mutex_capacetes, NULL);
    // pthread_cond_init(&k->cond_karts, NULL);
    // pthread_cond_init(&k->cond_capacetes, NULL);
}

void destroi_kartodromo(Kartodromo *k) {
    // pthread_mutex_destroy(&k->mutex_karts);
    // pthread_mutex_destroy(&k->mutex_capacetes);
    // pthread_cond_destroy(&k->cond_karts);
    // pthread_cond_destroy(&k->cond_capacetes);
}

void imprime_kartodromo(Kartodromo *k) {
    printf("\n\n\nKartódromo:\n");
    printf("Disponiveis : Karts: %d, Capacetes: %d\n", k->karts_disponiveis, k->capacetes_disponiveis);
}

void chegada_grupo(Kartodromo *k, int num_pilotos) {
    Piloto pilotos[num_pilotos];

    for (int i = 0; i < num_pilotos; i++) {
        snprintf(pilotos[i].nome, 50, "Piloto%d", i + 1);
        int idade = (rand() % 17) + 5; // pseudo idade, para garantir que a maior parte dos gerados sejam crianças
        if (idade > 18) {
            pilotos[i].idade = (rand() % 33) + 18; // garantir maior diversidade entre adultos
        } else {
            pilotos[i].idade = idade;
        }
        printf("Chegou %s, idade: %d\n", pilotos[i].nome, pilotos[i].idade);
    }

    // Apenas para demonstração, imprimindo o estado do kartódromo após a chegada do grupo
    imprime_kartodromo(k);
}
