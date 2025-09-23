#ifndef IDTR_H
#define IDTR_H
#include <stdint.h>

#define IDT_ENTRY_LIMIT 64

struct IDTR {
    uint16_t limit;  // 16 bytes * IDT_ENTRIES_COUNT - 1
    uint64_t base;   // base address of IDT
} __attribute__((packed));

struct InterruptDescriptor64 {
    uint16_t offset_1;  // offset bits 0..15
    uint16_t selector;  // code segment selector in GDT or LDT
    uint8_t ist;  // bits 0..2 holds Interrupt Stack Table offset, rest zero
    uint8_t type_attributes;  // gate type, DPL, present flag
    uint16_t offset_2;        // offset bits 16..31
    uint32_t offset_3;        // offset bits 32..63
    uint32_t zero;            // reserved
} __attribute__((packed));

struct IDTR init_idtr();
void register_page_fault_handler(uint64_t handler_addr);

#endif