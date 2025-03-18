#include <stdio.h>

int main() {
    int x = 25; // Define uma variável x do tipo inteiro e atribui o valor 25 a ela
    int *y;     // Define uma variável y do tipo ponteiro para inteiro

    y = &x;     // Faz o ponteiro y apontar para o endereço de x

    *y = 12;    // Altera o valor armazenado no endereço apontado por y para 12

    y = y + 1;  // Incrementa o ponteiro y para apontar para o próximo endereço de memória
    *y = *y + 5; // Soma 5 ao valor armazenado no endereço apontado por y

    printf("Qual é o valor de x? %d\n", x); // Imprime o valor atual de x

    return 0;
}
