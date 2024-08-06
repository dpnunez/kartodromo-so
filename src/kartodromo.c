#include "kartodromo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // Para a função sleep

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

void *piloto_thread(void *arg) {
    Piloto *piloto = (Piloto *)arg;

    printf("Piloto %s, idade: %d está na pista!\n", piloto->nome, piloto->idade);

    // Simulando ação do piloto
    sleep(1 + rand() % 5); // Simula o tempo de corrida

    printf("Piloto %s, idade: %d saiu da pista!\n", piloto->nome, piloto->idade);
    return NULL;
}

void chegada_grupo(Kartodromo *k, int num_pilotos) {
    Piloto *pilotos[num_pilotos];

    for (int i = 0; i < num_pilotos; i++) {
        pilotos[i] = malloc(sizeof(Piloto));
        if (pilotos[i] == NULL) {
            perror("Erro ao alocar memória para piloto");
            exit(EXIT_FAILURE);
        }

        snprintf(pilotos[i]->nome, 50, "Piloto%d", i + 1);
        int idade = (rand() % 17) + 5; // Pseudo idade
        if (idade > 18) {
            pilotos[i]->idade = (rand() % 33) + 18; // Garantir maior diversidade entre adultos
        } else {
            pilotos[i]->idade = idade;
        }

        // Criação da thread
        if (pthread_create(&pilotos[i]->thread, NULL, piloto_thread, (void *)pilotos[i]) != 0) {
            perror("Erro ao criar thread");
            exit(EXIT_FAILURE);
        }
    }

    // Duvida: posso fazer isso? Aguardando que todas as threads do grupo terminem
    for (int i = 0; i < num_pilotos; i++) {
        pthread_join(pilotos[i]->thread, NULL); // Espera a thread do piloto terminar
        free(pilotos[i]); // Libera a memória alocada
    }

    imprime_kartodromo(k);
}
