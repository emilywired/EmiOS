#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "idtr.h"
#include "vga.h"

void register_page_fault_handler(struct InterruptDescriptor64* idt,
                                 uint64_t handler_addr);

void page_fault_handler(void);

#endif