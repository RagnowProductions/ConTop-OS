; boot.asm
[org 0x7C00]     ; Boot sector starts at 0x7C00

mov ax, 0x0000   ; Set up the data segment
mov ds, ax

; Load the kernel into memory at 0x1000
mov si, kernel   ; Point to the kernel label
mov bx, 0x1000   ; Destination address

mov cx, 512      ; Number of bytes to read (1 sector)
mov ah, 0x02     ; BIOS function to read sectors
mov al, 1        ; Read 1 sector
mov ch, 0        ; Cylinder
mov cl, 2        ; Sector
mov dh, 0        ; Head
mov bx, 0x1000   ; Load address
int 0x13        ; Call BIOS

jmp 0x1000       ; Jump to the loaded kernel

kernel:
    db 'kernel.bin',0

times 510-($-$$) db 0  ; Fill the rest of the sector with zeros
dw 0xAA55               ; Boot signature
