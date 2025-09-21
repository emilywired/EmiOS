global long_mode_start

section .text
bits 64

long_mode_start:
    ; initialize stack
    mov rsp, stack_top

    ; load 0 into all data segment registers
    mov ax, 0
    mov ss, ax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov rcx, 0
    call .clear_vga_buffer

    extern kmain
    call kmain

    hlt

.clear_vga_buffer:
    mov word [0xb8000 + rcx * 2], 0x0000

    inc rcx
    cmp rcx, 2000
    jne .clear_vga_buffer

    ret

section .bss
align 16
stack:
    resb 4096
stack_top:
