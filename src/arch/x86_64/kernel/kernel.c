#include <stddef.h>
#include <stdint.h>

#include "exceptions.h"
#include "idtr.h"
#include "paging.h"
#include "vga.h"

void kmain(void) {
    init_paging();
    struct IDTR idtr = init_idtr();
    register_all_exceptions();

    vga_print_welcome_message();
}
