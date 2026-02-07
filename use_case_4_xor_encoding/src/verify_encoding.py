#!/usr/bin/env python3

KEY = 0x42

# Test: "SecretPassphrase"
plaintext = "SecretPassphrase"
encoded = [ord(c) ^ KEY for c in plaintext]
print("Encoded 'SecretPassphrase':", [hex(b) for b in encoded])

# Verify decoding
decoded = ''.join(chr(b ^ KEY) for b in encoded)
print("Decoded back:", decoded)

# Test: "Access granted!"
plaintext2 = "Access granted!"
encoded2 = [ord(c) ^ KEY for c in plaintext2]
print("\nEncoded 'Access granted!':", [hex(b) for b in encoded2])