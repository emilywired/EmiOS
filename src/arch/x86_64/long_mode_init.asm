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

    ; print "Welcome to EmiOS!!!"
    mov word [0xb8000], 0xdf57
    mov word [0xb8002], 0xdf65
    mov word [0xb8004], 0xdf6c
    mov word [0xb8006], 0xdf63
    mov word [0xb8008], 0xdf6f
    mov word [0xb800A], 0xdf6d
    mov word [0xb800C], 0xdf65

    mov word [0xb800E], 0xdf20

    mov word [0xb8010], 0xdf74
    mov word [0xb8012], 0xdf6f

    mov word [0xb8014], 0xdf20

    mov word [0xb8016], 0xdb45
    mov word [0xb8018], 0xdb6d
    mov word [0xb801A], 0xdb69
    mov word [0xb801C], 0xdb4f
    mov word [0xb801E], 0xdb53

    mov word [0xb8020], 0xdf21
    mov word [0xb8022], 0xdf21
    mov word [0xb8024], 0xdf21

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
