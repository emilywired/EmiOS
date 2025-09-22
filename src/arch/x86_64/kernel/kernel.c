#include <paging.h>
#include <stddef.h>
#include <stdint.h>

void print_welcome_message() {
    volatile uint16_t* vga = (uint16_t*)0xb8000;

    vga[0] = 0xdf57;
    vga[1] = 0xdf65;
    vga[2] = 0xdf6c;
    vga[3] = 0xdf63;
    vga[4] = 0xdf6f;
    vga[5] = 0xdf6d;
    vga[6] = 0xdf65;

    vga[7] = 0xdf20;

    vga[8] = 0xdf74;
    vga[9] = 0xdf6f;

    vga[10] = 0xdf20;

    vga[11] = 0xdb45;
    vga[12] = 0xdb6d;
    vga[13] = 0xdb69;
    vga[14] = 0xdb4f;
    vga[15] = 0xdb53;

    vga[16] = 0xdf21;
    vga[17] = 0xdf21;
    vga[18] = 0xdf21;
}

void kmain(void) {
    init_paging();

    print_welcome_message();
}
