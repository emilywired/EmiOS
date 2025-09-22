; global page_fault_handler

; section .text
; bits 64

; page_fault_handler:
;     mov rcx, 0
;     call .blue_screen_vga_buffer

;     hlt

; .blue_screen_vga_buffer:
;     mov word [0xb8000 + rcx * 2], 0x0000

;     inc rcx
;     cmp rcx, 2000
;     jne .clear_vga_buffer

;     ret