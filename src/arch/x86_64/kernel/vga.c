#include "vga.h"

#include <stddef.h>

volatile uint16_t* vga = (uint16_t*)0xb8000;

static uint8_t cursor_row = 0;
static uint8_t cursor_column = 0;

void vga_clear() {
    for (size_t i = 0; i < VGA_SIZE; i++) {
        vga[i] = 0x0000;
    }
}

inline void vga_write_char(char c, uint8_t column, uint8_t row,
                           vga_color_t color) {
    uint16_t cell = column + row * VGA_WIDTH;
    if (cell >= VGA_SIZE) return;

    vga[cell] = (color << 8) + c;
}

inline static void cursor_next_line() {
    cursor_row++;
    cursor_column = 0;
}

void vga_print(const char* str, vga_color_t color) {
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\0') break;

        if (str[i] == '\n') {
            cursor_next_line();
            continue;
        }

        vga_write_char(str[i], cursor_column, cursor_row, color);
        if (cursor_column == 80) {
            cursor_next_line();
        } else {
            cursor_column++;
        }
    }
}

inline void vga_println(const char* str, vga_color_t color) {
    vga_print(str, color);
    cursor_next_line();
}
