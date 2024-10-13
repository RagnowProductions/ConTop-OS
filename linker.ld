OUTPUT_FORMAT("binary")
ENTRY(_start)

SECTIONS
{
    . = 0x1000;
    .text : { *(.text) }
    . = 0x2000; // Next section (where our program will go)
    .text_program : { *(.text_program) }
}
