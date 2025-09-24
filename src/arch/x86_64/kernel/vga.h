#ifndef VGA_H
#define VGA_H

#include <stdint.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_SIZE VGA_WIDTH* VGA_HEIGHT

extern volatile uint16_t* vga;

void vga_clear();
void vga_print_welcome_message();

#endif