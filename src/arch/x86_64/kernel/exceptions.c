#include "exceptions.h"

// TODO: generic register function
void register_page_fault_handler(struct InterruptDescriptor64* idt,
                                 uint64_t handler_addr) {
    struct InterruptDescriptor64* page_fault_entry = &idt[14];

    page_fault_entry->offset_1 = (uint16_t)handler_addr;
    page_fault_entry->selector = 0x08;
    page_fault_entry->ist = 0;
    page_fault_entry->type_attributes = 0b10001110;  // Interrupt Gate
    page_fault_entry->offset_2 = (uint16_t)(handler_addr >> 16);
    page_fault_entry->offset_3 = (uint32_t)(handler_addr >> 32);
    page_fault_entry->zero = 0;
}

void page_fault_handler(void) {
    vga_clear(0x1000);
    vga_println("Page Fault", VGA_COLOR(BLUE, BRIGHT_WHITE));

    __asm__ volatile("hlt");
}