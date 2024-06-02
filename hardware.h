#ifndef HARDWARE_H
#define HARDWARE_H

void liga(unsigned short* reg);
void desliga(unsigned short* reg);
void exibicao(int i, unsigned short* reg, unsigned short* reg2);
void configure_message(const char* message, unsigned short** registers);

#endif
