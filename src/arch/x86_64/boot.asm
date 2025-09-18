global start


section .text
bits 32

start:
    mov esp, stack_top ; initialize stack

    call check_multiboot
    call check_cpuid
    call check_long_mode

    ; print "OK"
    mov dword [0xb8000], 0x0f4b0f4f

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

check_multiboot:
    cmp eax, 0x36d76289
    jne .no_multiboot
    ret

.no_multiboot:
    mov al, "0"
    jmp error

check_cpuid:
    ; Check if CPUID is supported by attempting to flip the ID bit (bit 21)
    ; in the FLAGS register. If we can flip it, CPUID is available.

    ; Copy FLAGS in to EAX via stack
    pushfd
    pop eax

    ; Copy to ECX as well for comparing later on
    mov ecx, eax

    ; Flip the ID bit
    xor eax, 1 << 21

    ; Copy EAX to FLAGS via the stack
    push eax
    popfd

    ; Copy FLAGS back to EAX (with the flipped bit if CPUID is supported)
    pushfd
    pop eax

    ; Restore FLAGS from the old version stored in ECX (i.e. flipping the
    ; ID bit back if it was ever flipped).
    push ecx
    popfd

    ; Compare EAX and ECX. If they are equal then that means the bit
    ; wasn't flipped, and CPUID isn't supported.
    cmp eax, ecx
    je .no_cpuid
    ret

.no_cpuid:
    mov al, "1"
    jmp error

check_long_mode:
    ; test if extended processor info in available
    mov eax, 0x80000000    ; implicit argument for cpuid
    cpuid                  ; get highest supported argument
    cmp eax, 0x80000001    ; it needs to be at least 0x80000001
    jb .no_long_mode       ; if it's less, the CPU is too old for long mode

    ; use extended info to test if long mode is available
    mov eax, 0x80000001    ; argument for extended processor info
    cpuid                  ; returns various feature bits in ecx and edx
    test edx, 1 << 29      ; test if the LM-bit is set in the D-register
    jz .no_long_mode       ; If it's not set, there is no long mode
    ret

.no_long_mode:
    mov al, "2"
    jmp error

section .bss

stack_bottom:
    resb 64
stack_top: