#include <stdio.h>
#include <string.h>

int check_password(char *input) {
    char correct[] = "Th3s1sR0cks!"; // This string will appear in the .rodata / .rdata section
    
    if (strcmp(input, correct) == 0) {
        return 1;
    }
    return 0;
}

void success() {
    printf("Access granted! Welcome to the system.\n");
}

void failure() {
    printf("Access denied. Invalid password.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }
    
    // This branch will look very different at -O0 vs -O2/-O3
    if (check_password(argv[1])) {
        success();
    } else {
        failure();
    }
    
    return 0;
}
