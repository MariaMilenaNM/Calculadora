#include <stdio.h>
/*
 * Autor: Maria Milena Neci Malaquias
 * Email: milena.nmalaquias@upe.br
 */

// conversão de base, criando uma função void para cada base, para fazer o calculo e printar o resultado do numero decimal nas base2,8,16,bcd
//binario
void dec_binario(int n) {
    int binario[32];
    int indice = 0;

    if (n == 0) {
        printf("Base 2: 0\n");
        return;
    }

    while (n > 0) {
        binario[indice] = n % 2;
        n = n / 2;
        indice++;
    }

    printf("Base 2: ");
    for (int i = indice - 1; i >= 0; i--) {
        printf("%d", binario[i]);
    }
    printf("\n");
    return;
}
//base8
void dec_baseoito(int n) {
    int oito[32];
    int indice = 0;

    if (n == 0) {
        printf("Base 8: 0\n");
        return;
    }

    while (n > 0) {
        oito[indice] = n % 8;
        n = n / 8;
        indice++;
    }

    printf("Base 8: ");
    for (int i = indice - 1; i >= 0; i--) {
        printf("%d", oito[i]);
    }
    printf("\n");
    return;
}
//hexadecimal
void dec_hexadecimal(int n) {
    char hex[32];
    int indice = 0;

    if (n == 0) {
        printf("Base 16: 0\n");
    
    }

    while (n > 0) {
        int resto = n % 16;
        if (resto < 10) {
            hex[indice] = resto + '0';
        } else {
            hex[indice] = resto - 10 + 'A';
        }
        n = n / 16;
        indice++;
    }

    printf("Base 16: ");
    for (int i = indice - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }
    printf("\n");
    return;
}
//base BCD
//nao consegui entender o erro =(
void dec_BCD(int n) {
    printf("Código BCD: ");
    if (n == 0) {
        printf("0000\n");
        return;
    }

    int bcd[8] = {0}; // dígitos BCD
    int indice = 0;

    while (n > 0) {
        bcd[indice++] = n % 2; // decimal
        n /= 2;
    }

    for (int i = indice - 1; i >= 0; i--) {
        printf("%.4d ", bcd[i]);
    }
    printf("\n");
}

int main() {
    int num;

    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    dec_binario(num);
    dec_baseoito(num);
    dec_hexadecimal(num);
    dec_BCD(num);
    return 0;
}






