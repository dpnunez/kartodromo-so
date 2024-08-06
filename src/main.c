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
    
    // 3. Logia de chegada de pilotos/grupos

    // 2. Defini e inicia pilotos


    // 4. Destroi pilotos e katodromo
    destroi_kartodromo(&kartodromo);

    return 0; 
}