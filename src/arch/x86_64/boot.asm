global start


section .text
bits 32

start:
    mov esp, stack_top ; initialize stack

    hlt

error:
    ; 0xb8000 = VGA text buffer, 4000 bytes long, each cell is 2 bytes (1 ASCII 1 color attribute)
    ; print "ERROR: {code}"
    mov dword [0xb8000], 0x0f520f45
    mov dword [0xb8004], 0x0f4f0f52
    mov dword [0xb8008], 0x0f3a0f52
    mov word [0xb80012], 0x0f20
    mov byte [0xb80014], al
    hlt


section .bss

stack_bottom:
    resb 64
stack_top: