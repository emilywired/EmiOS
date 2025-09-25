#include <stddef.h>
#include <stdint.h>

#include "exceptions.h"
#include "idtr.h"
#include "neofetch.h"
#include "paging.h"
#include "vga.h"

void kmain(void) {
    init_paging();
    init_idtr();
    register_all_exceptions();

    print_neofetch();
}
