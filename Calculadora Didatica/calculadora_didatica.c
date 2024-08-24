/*******************************************************************
* Autor         : Lucas Ferreira Torres de Albuquerque
* Turma         : 3° Período - Turma A
* Nome do Arquivo         : calculadora_didatica.c
*                    
* Historico de Atualização  :
* Data		Hora		Autor 			Comentário
* ------------------------------------------------------------------
* 22/08     18:00    Lucas Ferreira      Primeira Questão
* 22/08     18:45    Lucas Ferreira      Segunda Questão
/******************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void *decimalToBinary(int decimal) {
    char binary[8];

    printf("Valor %d em binario: \n", decimal);
    for(int i = 0; i <= 8; i++) {
        printf("\nResto da divisao de %d por 2: %d\n", decimal, decimal % 2);
        binary[8-i] = decimal % 2;
        decimal /= 2;

    }

    printf("\nValor covertido para binario: ");
    for(int i = 0; i <= 8; i++) {
        printf(" %d", binary[i]);
    }
}

void decimalToOctal(int decimal) {
    char octal[3];

    printf("Valor %d em octal: ", decimal);

    for(int i = 0; i < 3; i++) {
        printf("\nResto da divisao de %d por 2: %d\n", decimal, decimal % 8);
        octal[3-i] = decimal % 8;
        decimal /= 8;

        printf("%d", octal[3-i]);
    }
}

void decimalToHexadecimal(int decimal) {
    char hexadecimal[2];

    printf("Valor %d em hexadecimal: ", decimal);

    for(int i = 0; i < 2; i++) {
        printf("\nResto da divisao de %d por 16: %d\n", decimal, decimal % 2);
        hexadecimal[2-i] = decimal % 16;
        decimal /= 16;

        printf("%d", hexadecimal[2-i]);
    }
}

void decimalToBCD(char decimals[], int array_size) {
    
    int bcd[array_size][4];
    int value;

    for(int i = 0; i < array_size; i++) {
        value = (int)decimals[i] - 48;


        for(int j = 0; j <= 4; j++) {
            bcd[i][j] = value % 2;
            value /= 2;
        }
    }

    for(int i = 0; i < array_size; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d", bcd[i][3-j]);
        }
        printf(" ");
    }
    

}

void decimalToBinaryComplement2(int decimal) {
    char binary[16];
    char result[16];
    int i;

    printf("\nValor %d em binario (complemento a 2): ", decimal);

    for (i = 15; i >= 0; i--) {
        if (decimal % 2 == 0) {
            binary[i] = '0';
        } else {
            binary[i] = '1';
        }
        decimal /= 2;
    }

    printf("\nBinario invertido: ");

    for (i = 0; i < 16; i++) {
        if (binary[i] == '0') {
            binary[i] = '1';
        } else {
            binary[i] = '0';
        }
        printf("%c", binary[i]);
    }

    int carry = 1;
    for (i = 15; i >= 0; i--) {
        if (binary[i] == '1' && carry == 1) {
            result[i] = '0';
        } else if (binary[i] == '0' && carry == 1) {
            result[i] = '1';
            carry = 0;
        } else {
            result[i] = binary[i];
        }
    }

    printf("\nBinario em complemento a 2: ");

    for (i = 0; i < 16; i++) {
        printf("%c", result[i]);
    }
    printf("\n");
}

int main() {
    int op, valor;
    printf("Calculadora Didatica\n======================\n Escolha as Opcoes de Conversao:\n1-Base2\n2-Base8\n3-Base16\n4-BCD\n5-Base 2 Complemento a 2\n6-Coverter para Float e Double\n");
    scanf("%d", &op);

    //binario
    if(op == 1) { 
        printf("Digite o valor em decimal: ");
        scanf("%d", &valor);

        decimalToBinary(valor);

    //octal
    } else if(op == 2) { 
        printf("Digite o valor em decimal: ");
        scanf("%d", &valor);

        decimalToOctal(valor);

    //hexadecimal
    } else if(op == 3) { 
        printf("Digite o valor em decimal: ");
        scanf("%d", &valor);

        decimalToHexadecimal(valor);

    //bcd
    } else if(op == 4) { 
        printf("Digite o valor em decimal: ");
        scanf("%d", &valor);

        char buffer[20];

        snprintf(buffer, sizeof(buffer), "%d", valor);

        int size = strlen(buffer);

        decimalToBCD(buffer, size);
        
    //complemento a 2
    } else if(op == 5) { 
        printf("Digite o valor em decimal: ");
        scanf("%d", &valor);

        decimalToBinaryComplement2(valor);

    } else {
        printf("Opcao invalida");
    }
}