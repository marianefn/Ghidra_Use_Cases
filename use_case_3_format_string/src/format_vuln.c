#include <stdio.h>
#include <string.h>

int authenticated = 0;

void print_log(char *message) {
    // VULNERABLE: User input passed directly to printf
    printf(message);
    printf("\n");
}

void check_auth() {
    if (authenticated) {
        printf("Authentication bypassed! You shouldn't see this.\n");
        printf("Secret flag: FLAG{f0rm4t_str1ng_pwn3d}\n");
    } else {
        printf("Access denied. Authentication required.\n");
    }
}

int main(int argc, char *argv[]) {
    char buffer[256];
    
    printf("System Logger v1.0\n");
    printf("Enter log message: ");
    
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 1;
    }
    
    // Remove newline
    buffer[strcspn(buffer, "\n")] = 0;
    
    printf("Logging: ");
    print_log(buffer);
    
    check_auth();
    
    return 0;
}