// logic_gates.c
#include "logic_gates.h"

// Helper macro to force 1-bit output (0 or 1)
#define BIT(x) ((x) & 0x01)


// Basic 1-bit logic gates
uint8_t gate_and(uint8_t a, uint8_t b) {
    return BIT(a) & BIT(b);
}

uint8_t gate_nand(uint8_t a, uint8_t b) {
    return BIT(~(BIT(a) & BIT(b)));
}

uint8_t gate_or(uint8_t a, uint8_t b) {
    return BIT(a) | BIT(b);
}

uint8_t gate_nor(uint8_t a, uint8_t b) {
    return BIT(~(BIT(a) | BIT(b)));
}

uint8_t gate_xor(uint8_t a, uint8_t b) {
    return BIT(a) ^ BIT(b);
}

uint8_t gate_xnor(uint8_t a, uint8_t b) {
    return BIT(~(BIT(a) ^ BIT(b)));
}

uint8_t gate_not(uint8_t a) {
    return BIT(~BIT(a));
}

// Plonck-1 specialized gates
uint8_t gate_orcd(uint8_t acc, uint8_t data) {
    // OR Complement Data: NOT(Data) OR ACC
    return BIT(gate_or(gate_not(data), acc));
}

uint8_t gate_orcr(uint8_t acc, uint8_t data) {
    // OR Complement Result: Data OR NOT(ACC)
    return BIT(gate_or(data, gate_not(acc)));
}
