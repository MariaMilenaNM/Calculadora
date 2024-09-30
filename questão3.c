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

    // Fra��o
    int fracao = bits & 0x7FFFFF;

    // Expoente com vi�s (bias de 127 para float)
    int expoVies;
    expoVies = expoente - 127;

    printf("Float:\n");
    //para adicionar 16bits
    printf(" %u  %.16fx10^%u \n", sinal, num, expoente);
    printf("Sinal: %u\n", sinal);
    printf("Expoente: %u\n", expoente);
    printf("Expoente com vi�s: %d\n", expoVies);
    printf("Fra��o: %u\n", fracao);
    printf("\n");
}

void Double(double num) {
    //utilizado o unsigned long long pra manter a precis�o do double que tem maior precis�o em compara��o ao float e precisa de mais bits
    unsigned long long bits;
    memcpy(&bits, &num, sizeof(double));

    // Sinal
    unsigned long long sinal = (bits >> 63) & 0x1;

    // Expoente
    unsigned long long expoente = (bits >> 52) & 0x7FF;

    // Fra��o
    unsigned long long fracao = bits & 0xFFFFFFFFFFFFF;

    // Expoente com vi�s (bias de 1023 para double)
    long long expoVies = expoente - 1023;

    printf("Double:\n");
    //para adicionar 16 bits
    printf(" %llu  %.16fx10^%llu \n", sinal, num, expoente);
    printf("Sinal: %llu\n", sinal);
    printf("Expoente: %llu\n", expoente);
    printf("Expoente com vi�s: %lld\n", expoVies);
    printf("Fra��o: %llu\n", fracao);
}

int main() {
    float numFloat;
    double numDouble;

    printf("digite um n�mero para representa��o em float: ");
    scanf("%f", &numFloat);
    Float(numFloat);

    printf("digite um n�mero para representa��o em double: ");
    scanf("%lf", &numDouble);
    Double(numDouble);

    return 0;
}






