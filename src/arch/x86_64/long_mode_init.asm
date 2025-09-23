global long_mode_start

section .text
bits 64

global set_cr3
set_cr3:
    mov cr3, rdi
    ret

global set_idtr
set_idtr:
    lidt [rdi]
    ret

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
    ; TODO: understand stosq optimization
    mov dword [0xb8000 + rcx * 4], 0x00000000

    inc rcx
    cmp rcx, 1000
    jne .clear_vga_buffer

    ret

section .bss
align 16
stack:
    resb 4096
stack_top:
