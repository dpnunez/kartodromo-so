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

    // k->total_clientes_atendidos = 0;
    // k->total_espera = 0;
    // k->total_recursos_utilizados_karts = 0;
    // k->total_recursos_utilizados_capacetes = 0;
}

void destroi_kartodromo(Kartodromo *k) {
    // pthread_mutex_destroy(&k->mutex_karts);
    // pthread_mutex_destroy(&k->mutex_capacetes);
    // pthread_cond_destroy(&k->cond_karts);
    // pthread_cond_destroy(&k->cond_capacetes);
}

void imprime_kartodromo(Kartodromo *k) {
    printf("\n\n\nKartódromo:\n");
    printf("Disponíveis: Karts: %d, Capacetes: %d\n", k->karts_disponiveis, k->capacetes_disponiveis);
    // printf("Total de clientes atendidos: %d\n", k->total_clientes_atendidos);
    // printf("Total de recursos utilizados (Karts): %d\n", k->total_recursos_utilizados_karts);
    // printf("Total de recursos utilizados (Capacetes): %d\n", k->total_recursos_utilizados_capacetes);
}

typedef struct {
    Piloto *piloto;
    Kartodromo *kartodromo;
} PilotoArg;


void *piloto_thread(void *arg) {
    PilotoArg *piloto_arg = (PilotoArg *)arg;
    Piloto *piloto = piloto_arg->piloto;
    Kartodromo *kartodromo = piloto_arg->kartodromo;

    printf("Piloto %s, idade: %d está tentando pegar um kart e capacete.\n", piloto->nome, piloto->idade);


    // toDo: checkpoint
    if (piloto->idade > 18) {
        // pegar kart
    } else if (piloto->idade <= 14) {
        // pegar capacete com prioridade
    } else {
        // pegar capacete sem prioridade
    }

    sleep(rand() % 5 + 1); // Simula o tempo de corrida
    printf("Piloto %s, idade: %d saiu da pista!\n", piloto->nome, piloto->idade);
    return NULL;
}

void chegada_grupo(Kartodromo *k, int num_pilotos) {
    Piloto *pilotos[num_pilotos];
    PilotoArg *piloto_args[num_pilotos];

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

        pilotos[i]->prioridade = (pilotos[i]->idade <= 14) ? 1 : 0;

        piloto_args[i] = malloc(sizeof(PilotoArg));
        if (piloto_args[i] == NULL) {
            perror("Erro ao alocar memória para piloto_args");
            exit(EXIT_FAILURE);
        }

        // Montando estrutura para passar para a thread
        piloto_args[i]->piloto = pilotos[i];
        piloto_args[i]->kartodromo = k;


        // Criação da thread
        if (pthread_create(&pilotos[i]->thread, NULL, piloto_thread, (void *)piloto_args[i]) != 0) {
            perror("Erro ao criar thread");
            exit(EXIT_FAILURE);
        }
    }

    // Aguardando que todas as threads do grupo terminem
    for (int i = 0; i < num_pilotos; i++) {
        pthread_join(pilotos[i]->thread, NULL); // Espera a thread do piloto terminar
        free(pilotos[i]); // Libera a memória alocada
        free(piloto_args[i]); // Libera a memória do argumento
    }

    imprime_kartodromo(k);
}
