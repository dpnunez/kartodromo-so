#include "kartodromo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    // 1. Defini e inicia kartodromo
    Kartodromo kartodromo;
    inicializa_kartodromo(&kartodromo);

    printf("Kartódromo inicializado:\n");
    printf("Karts disponíveis: %d\n", kartodromo.karts_disponiveis);
    printf("Capacetes disponíveis: %d\n", kartodromo.capacetes_disponiveis);
    

   

    // 2. Defini e inicia pilotos

    // 3. Logia de chegada de pilotos/grupos

    // 4. Destroi pilotos e katodromo
    destroi_kartodromo(&kartodromo);

    return 0; 
}