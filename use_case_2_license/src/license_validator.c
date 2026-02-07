#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validate_license(char *key) {
    if (strlen(key) != 16) {
        return 0;
    }
    
    int checksum = 0;
    for (int i = 0; i < 16; i++) {
        checksum += key[i] * (i + 1);
    }
    
    // Valid if checksum is divisible by 37
    if (checksum % 37 == 0) {
        return 1;
    }
    
    return 0;
}

void print_banner() {
    printf("================================\n");
    printf("  Software License Validator\n");
    printf("================================\n");
}

int main(int argc, char *argv[]) {
    print_banner();
    
    if (argc != 2) {
        printf("Usage: %s <license-key>\n", argv[0]);
        return 1;
    }
    
    printf("Validating license key: %s\n", argv[1]);
    
    if (validate_license(argv[1])) {
        printf("License key is VALID!\n");
        printf("Full version unlocked.\n");
        return 0;
    } else {
        printf("License key is INVALID!\n");
        printf("Please purchase a valid license.\n");
        return 1;
    }
}
