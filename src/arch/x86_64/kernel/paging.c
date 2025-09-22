#include <paging.h>
#include <stddef.h>

#define PAGE_SIZE 4096

__attribute__((aligned(PAGE_SIZE))) uint64_t p4_table[PAGE_SIZE / 8];
__attribute__((aligned(PAGE_SIZE))) uint64_t p3_table[PAGE_SIZE / 8];
__attribute__((aligned(PAGE_SIZE))) uint64_t p2_table[PAGE_SIZE / 8];

extern void set_cr3(uint64_t addr);

static void set_up_page_tables() {
    // fill p2 with entries
    for (size_t i = 0; i < 512; i++) {
        uint64_t addr = (uint64_t)i * 0x200000;  // 2MiB offset
        p2_table[i] = addr | 0b10000011;         // present + writable + huge
    }

    // add p2 to p3
    p3_table[0] = (uint64_t)p2_table | 0b11;

    // add p3 to p4
    p4_table[0] = (uint64_t)p3_table | 0b11;
}

void init_paging(void) {
    set_up_page_tables();
    set_cr3((uint64_t)p4_table);
}
