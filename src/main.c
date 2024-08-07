#include "kartodromo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    // 1. Defini e inicia kartodromo
    Kartodromo kartodromo;
    inicializa_kartodromo(&kartodromo);
    imprime_kartodromo(&kartodromo);
    
    // 2. Logia de chegada de grupos
    for (int i = 0; i < NUM_GRUPOS; i++) {
        int num_pilotos = 25 + rand() % 11; // Gera um número entre 5 e 15
        printf("\nGrupo %d chegando com %d pilotos\n", i + 1, num_pilotos);

        // 3. Chegada de pilotos
        chegada_grupo(&kartodromo, num_pilotos);
    }


    // 3. Destroi pilotos e katodromo
    destroi_kartodromo(&kartodromo);

    return 0; 
}