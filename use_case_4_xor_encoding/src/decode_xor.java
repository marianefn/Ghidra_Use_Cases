//Ghidra script to decode XOR-encoded strings
//@category Analysis
import ghidra.app.script.GhidraScript;

public class decode_xor extends GhidraScript {
    // XOR key extracted from binary analysis
    private static final int XOR_KEY = 0x42;
    
    /**
     * Decode XOR-encoded bytes
     */
    private String decodeBytes(int[] encodedBytes) {
        StringBuilder decoded = new StringBuilder();
        for (int b : encodedBytes) {
            char decodedChar = (char) (b ^ XOR_KEY);
            decoded.append(decodedChar);
        }
        return decoded.toString();
    }
    
    @Override
    public void run() throws Exception {
        // Encoded bytes extracted from binary analysis
        int[] encodedPassphrase = {
            0x11, 0x27, 0x21, 0x30, 0x27, 0x36, 0x12, 0x23,
            0x31, 0x31, 0x32, 0x2a, 0x30, 0x23, 0x31, 0x27
        };
        
        int[] encodedSuccess = {
            0x03, 0x21, 0x21, 0x27, 0x31, 0x31, 0x62, 0x25,
            0x30, 0x23, 0x2c, 0x36, 0x27, 0x26, 0x63
        };
        
        println("=== XOR Decode Script ===");
        println("XOR Key: 0x" + Integer.toHexString(XOR_KEY));
        println("Decoded passphrase: " + decodeBytes(encodedPassphrase));
        println("Decoded success message: " + decodeBytes(encodedSuccess));
    }
}