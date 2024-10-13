// kernel.c
extern void program_main(); // Declare the program's entry point

void kernel_main() {
    const char *message = "This is just a test message. The system software should be booting shortly.";
    char *video_memory = (char *) 0xb8000; // Video memory address for text mode
    int i;

    // Clear the screen
    for (i = 0; i < 80 * 25; i++) {
        video_memory[i * 2] = ' '; // Character
        video_memory[i * 2 + 1] = 0x07; // Attribute byte (light grey on black)
    }

    // Write the initial message
    for (i = 0; message[i] != '\0'; i++) {
        video_memory[i * 2] = message[i];
        video_memory[i * 2 + 1] = 0x07;
    }

    // Jump to the program's main function
    program_main();
}
