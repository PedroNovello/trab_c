#include <stdio.h>
#include "hardware.h"

void set_register_bit(unsigned short* reg, int bit_position, int value) {
    if (value) {
        // Set the bit
        *reg |= (1 << bit_position);
    } else {
        // Clear the bit
        *reg &= ~(1 << bit_position);
    }
}

void liga(unsigned short* reg){
    set_register_bit(reg, 0, 1); // Pass reg directly
}

void desliga(unsigned short* reg){
    set_register_bit(reg, 0, 0); // Pass reg directly
}

void exibicao(int i,unsigned short* reg, unsigned short* reg2 ){
    switch(i){
        case 1:
            set_register_bit(reg, 1, 0);
            set_register_bit(reg2, 2, 0);
            break;
        case 2:
            set_register_bit(reg, 1, 1);
            set_register_bit(reg2, 2, 0);
            break;
        case 3:
            set_register_bit(reg, 1, 0);
            set_register_bit(reg2, 2, 1);
            break;
        case 4:
            set_register_bit(reg, 1, 1);
            set_register_bit(reg2, 2, 1);
            break;
        default:
            printf("Invalid command\n");
            break;
    }
}

void configure_message(const char* message, unsigned short** registers) {
    for (int i = 0; i < 12; ++i) {
        if (message[i] != '\0') {
            registers[i + 4][0] = message[i];
        } else {
            registers[i + 4][0] = ' ';
        }
    }
}
