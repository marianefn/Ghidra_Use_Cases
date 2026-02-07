#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// XOR key
#define KEY 0x42

void decode_string(char *encoded, char *output, int length) {
    for (int i = 0; i < length; i++) {
        output[i] = encoded[i] ^ KEY;
    }
    output[length] = '\0';
}

int check_secret(char *input) {
    // Encoded string: "SecretPassphrase" XORed with 0x42
    char encoded[] = {0x11, 0x27, 0x21, 0x30, 0x27, 0x36, 0x12, 0x23, 0x31, 0x31, 0x32, 0x2a, 0x30, 0x23, 0x31, 0x27};
    char decoded[20];
    
    decode_string(encoded, decoded, 16);
    
    if (strcmp(input, decoded) == 0) {
        return 1;
    }
    return 0;
}

void anti_debug_check() {
    // Simple anti-debugging: check if being traced
    // This is a placeholder - real anti-debug is more complex
    printf("Checking environment...\n");
}

int main(int argc, char *argv[]) {
    anti_debug_check();
    
    if (argc != 2) {
        printf("Usage: %s <passphrase>\n", argv[0]);
        return 1;
    }
    
    if (check_secret(argv[1])) {
        char success_msg[] = {0x03, 0x21, 0x21, 0x27, 0x31, 0x31, 0x62, 0x25, 0x30, 0x23, 0x2c, 0x36, 0x27, 0x26, 0x63};
        char decoded[20];
        decode_string(success_msg, decoded, 15);
        printf("%s\n", decoded);
    } else {
        printf("Incorrect passphrase.\n");
    }
    
    return 0;
}