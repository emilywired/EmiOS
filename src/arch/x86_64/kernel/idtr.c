#include "idtr.h"

static struct IDTR idtr;
static struct InterruptDescriptor64 idt[IDT_ENTRY_LIMIT];

extern void set_idtr(void* idtr);

struct IDTR init_idtr() {
    uint16_t limit = IDT_ENTRY_LIMIT * 16 - 1;
    idtr.limit = limit;
    idtr.base = (uint64_t)idt;

    set_idtr(&idtr);
    return idtr;
}

void register_page_fault_handler(uint64_t handler_addr) {
    struct InterruptDescriptor64* page_fault_entry = &idt[14];

    page_fault_entry->offset_1 = (uint16_t)handler_addr;
    page_fault_entry->selector = 0x08;
    // page_fault_entry->ist =
    // page_fault_entry->type_attributes =
    page_fault_entry->offset_2 = (uint16_t)(handler_addr >> 16);
    page_fault_entry->offset_3 = (uint32_t)(handler_addr >> 32);
    // page_fault_entry->zero;  // reserved
}
