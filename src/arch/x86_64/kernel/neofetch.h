#ifndef NEOFETCH_H
#define NEOFETCH_H

#include "vga.h"

void print_neofetch() {
    vga_print("                   -`                  ", VGA_FG(LIGHT_CYAN));
    vga_print("   emilia@emios\n", VGA_FG(BRIGHT_WHITE));
    vga_print("                  .o+`                 ", VGA_FG(LIGHT_CYAN));
    vga_print("  ----------------------------\n", VGA_FG(LIGHT_MAGENTA));
    vga_print("                 `ooo/                 ", VGA_FG(LIGHT_CYAN));
    vga_print("   Kernel: ", VGA_FG(LIGHT_CYAN));
    vga_print("0.0.3-emios-x86_64\n", VGA_FG(BRIGHT_WHITE));
    vga_print("                `+oooo:                ", VGA_FG(LIGHT_CYAN));
    vga_print("   Uptime", VGA_FG(LIGHT_CYAN));
    vga_print(": 0s\n", VGA_FG(BRIGHT_WHITE));
    vga_print("               `+oooooo:               ", VGA_FG(LIGHT_CYAN));
    vga_print("   Terminal", VGA_FG(LIGHT_CYAN));
    vga_print(": VGA\n", VGA_FG(BRIGHT_WHITE));
    vga_print("               -+oooooo+:              ", VGA_FG(LIGHT_MAGENTA));
    vga_print("   Resolution", VGA_FG(LIGHT_CYAN));
    vga_print(": 1920x1080\n", VGA_FG(BRIGHT_WHITE));
    vga_print("             `/:-:++oooo+:             ", VGA_FG(LIGHT_MAGENTA));
    vga_print("   RAM", VGA_FG(LIGHT_CYAN));
    vga_print(": ? / 1024MiB\n", VGA_FG(BRIGHT_WHITE));
    vga_print("            `/++++/+++++++:            ", VGA_FG(LIGHT_MAGENTA));
    vga_print("   Disk", VGA_FG(LIGHT_CYAN));
    vga_print(": 0G / 0G\n", VGA_FG(BRIGHT_WHITE));
    vga_print("           `/++++++++++++++:           ", VGA_FG(BRIGHT_WHITE));
    vga_print("  ----------------------------\n", VGA_FG(LIGHT_MAGENTA));
    vga_println("          `/+++ooooooooooooo/`         ", VGA_FG(BRIGHT_WHITE));
    vga_println("         ./ooosssso++osssssso+`        ", VGA_FG(BRIGHT_WHITE));
    vga_println("        .oossssso-````/ossssss+`       ", VGA_FG(LIGHT_MAGENTA));
    vga_println("       -osssssso.      :ssssssso.      ", VGA_FG(LIGHT_MAGENTA));
    vga_println("      :osssssss/        osssso+++.     ", VGA_FG(LIGHT_MAGENTA));
    vga_println("     /ossssssss/        +ssssooo/-     ", VGA_FG(LIGHT_CYAN));
    vga_println("   `/ossssso+/:-        -:/+osssso+-   ", VGA_FG(LIGHT_CYAN));
    vga_println("  `+sso+:-`                 `.-/+oso:  ", VGA_FG(LIGHT_CYAN));
    vga_println(" `++:.                           `-/+/ ", VGA_FG(LIGHT_CYAN));
}

#endif
