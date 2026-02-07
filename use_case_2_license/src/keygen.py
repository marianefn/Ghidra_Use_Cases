#!/usr/bin/env python3
"""
License Key Generator
Based on reverse-engineered algorithm from binary analysis
"""

def calculate_checksum(key):
    """Calculate checksum for a 16-character key"""
    if len(key) != 16:
        return None
    
    checksum = 0
    for i in range(16):
        checksum += ord(key[i]) * (i + 1)
    return checksum

def validate_key(key):
    """Validate a license key"""
    checksum = calculate_checksum(key)
    if checksum is None:
        return False
    return checksum % 37 == 0

def generate_valid_key(prefix="LICENSE"):
    """
    Generate a valid license key
    Strategy: Choose first 15 characters, calculate required 16th character
    """
    if len(prefix) > 15:
        prefix = prefix[:15]
    
    # Pad prefix to 15 characters with random printable chars
    import random
    import string
    while len(prefix) < 15:
        prefix += random.choice(string.ascii_uppercase + string.digits)
    
    # Calculate checksum contribution from first 15 characters
    partial_checksum = 0
    for i in range(15):
        partial_checksum += ord(prefix[i]) * (i + 1)
    
    # Find the 16th character (position 15, weight 16)
    # We need: (partial_checksum + char16 * 16) % 37 == 0
    # Therefore: char16 * 16 ≡ -partial_checksum (mod 37)
    
    target = (-partial_checksum) % 37
    
    # Solve: char16 * 16 ≡ target (mod 37)
    # Need modular multiplicative inverse of 16 mod 37
    # Using extended Euclidean algorithm or brute force
    
    for char_value in range(32, 127):  # Printable ASCII range
        if (char_value * 16) % 37 == target:
            char16 = chr(char_value)
            key = prefix + char16
            return key
    
    # If no printable solution, try different prefix
    return None

def generate_simple_key():
    """Generate simple valid key (all same character)"""
    # For all same char: checksum = char * (1+2+...+16) = char * 136
    # Need: char * 136 % 37 == 0
    # 136 % 37 = 25, so need char where (char * 25) % 37 == 0
    
    for char_value in range(32, 127):
        if (char_value * 136) % 37 == 0:
            key = chr(char_value) * 16
            return key
    return None

# Main execution
if __name__ == "__main__":
    print("=== License Key Generator ===\n")
    
    # Generate simple key
    simple = generate_simple_key()
    print(f"Simple key (all same char): {simple}")
    print(f"Validation: {validate_key(simple)}\n")
    
    # Generate custom keys
    for prefix in ["LICENSE", "VALID", "UNLOCK", "CRACKED"]:
        key = generate_valid_key(prefix)
        if key:
            print(f"Key with prefix '{prefix}': {key}")
            print(f"Validation: {validate_key(key)}")
            print(f"Checksum: {calculate_checksum(key)}\n")