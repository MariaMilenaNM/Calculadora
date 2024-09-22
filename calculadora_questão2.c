#include <stdio.h>
#include <string.h>
/*Autor: Maria Milena Neci Malaquias
Email: milena.nmalaquias@upe.br
*/


void Float(float num) {
    int bits;
    //armazenabits
    memcpy(&bits, &num, sizeof(float));

    // Sinal 0 ou 1 para negativo e positivo
    int sinal = (bits >> 31) & 0x1;

    // Expoente
    int expoente = (bits >> 23) & 0xFF;

    // Fração
    int fracao = bits & 0x7FFFFF;

    // Expoente com viés (bias de 127 para float)
    int expoViés = expoente - 127;

    printf("Float:\n");
    printf(" %u  %fx10^%u \n", sinal, num, expoente);
    printf("Sinal: %u\n", sinal);
    printf("Expoente: %u\n", expoente);
    printf("Expoente com viés: %d\n", expoViés);
    printf("Fração: %u\n", fracao);
    printf("\n");
}

void Double(double num) {
    //utilizado o unsigned long long pra manter a precisão do double que tem maior precisão em comparação ao float e precisa de mais bits
    unsigned long long bits;
    memcpy(&bits, &num, sizeof(double));

    // Sinal
    unsigned long long sinal = (bits >> 63) & 0x1;

    // Expoente
    unsigned long long expoente = (bits >> 52) & 0x7FF;

    // Fração
    unsigned long long fracao = bits & 0xFFFFFFFFFFFFF;

    // Expoente com viés (bias de 1023 para double)
    long long expoViés = expoente - 1023;

    printf("Double:\n");
    printf(" %llu  %fx10^%llu \n", sinal, num, expoente);
    printf("Sinal: %llu\n", sinal);
    printf("Expoente: %llu\n", expoente);
    printf("Expoente com viés: %lld\n", expoViés);
    printf("Fração: %llu\n", fracao);
}

int main() {
    float numFloat;
    double numDouble;

    printf("digite um número para representação em float: ");
    scanf("%f", &numFloat);
    Float(numFloat);

    printf("digite um número para representação em double: ");
    scanf("%lf", &numDouble);
    Double(numDouble);

    return 0;
}






