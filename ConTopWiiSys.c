// ConTopWiiSys.c
void program_main() {
    const char *message = "This is just a demo and is soon going to be the system itself.";
    char *video_memory = (char *) 0xb8000; // Video memory address for text mode
    int i;

    // Display a message to the screen
    for (i = 0; message[i] != '\0'; i++) {
        video_memory[i * 2] = message[i]; // Character
        video_memory[i * 2 + 1] = 0x0C; // Red text
    }

    // Loop forever to prevent the kernel from returning
    while (1) {}
}
