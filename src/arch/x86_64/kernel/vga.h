#ifndef VGA_H
#define VGA_H

#include <stdint.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_SIZE VGA_WIDTH* VGA_HEIGHT

#define BLACK 0x0
#define BLUE 0x1
#define GREEN 0x2
#define CYAN 0x3
#define RED 0x4
#define MAGENTA 0x5
#define BROWN 0x6
#define WHITE 0x7
#define GRAY 0x8
#define LIGHT_BLUE 0x9
#define LIGHT_GREEN 0xA
#define LIGHT_CYAN 0xB
#define LIGHT_RED 0xC
#define LIGHT_MAGENTA 0xD
#define YELLOW 0xE
#define BRIGHT_WHITE 0xF

typedef uint8_t vga_color_t;
#define VGA_COLOR(bg, fg) ((bg << 4) | (fg & 0x0F))
#define VGA_FG(fg) ((BLACK << 4) | (fg & 0x0F))

extern volatile uint16_t* vga;

void vga_clear(uint16_t cell);
void vga_write_char(char c, uint8_t column, uint8_t row, vga_color_t color);
void vga_print(const char* str, vga_color_t color);
void vga_println(const char* str, vga_color_t color);

#endif