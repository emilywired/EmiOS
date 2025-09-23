; global page_fault_handler

; section .text
; bits 64

; page_fault_handler:
;     mov rcx, 0
;     call .blue_screen_vga_buffer
    
;     hlt

; .blue_screen_vga_buffer:
;     ; TODO: understand stosq optimization
;     mov dword [0xb8000 + rcx * 4], 0x10001000

;     inc rcx
;     cmp rcx, 1000
;     jne .clear_vga_buffer

;     ret