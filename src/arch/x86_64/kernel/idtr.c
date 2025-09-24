#include "idtr.h"

static struct IDTR idtr;
static struct InterruptDescriptor64 idt[IDT_ENTRY_LIMIT] = {0};

extern void set_idtr(void* idtr);

struct IDTR init_idtr() {
    uint16_t limit = IDT_ENTRY_LIMIT * 16 - 1;
    idtr.limit = limit;
    idtr.base = (uint64_t)idt;

    set_idtr(&idtr);
    return idtr;
}

struct InterruptDescriptor64* idtr_get_idt() { return idt; }

// Forward declaration of handlers
extern void register_page_fault_handler(struct InterruptDescriptor64* idt,
                                        uint64_t handler_addr);
extern void page_fault_handler(void);

void register_all_exceptions() {
    struct InterruptDescriptor64* idt = idtr_get_idt();
    register_page_fault_handler(idt, (uint64_t)page_fault_handler);
}