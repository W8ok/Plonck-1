// logic_gates.h
#ifndef LOGIC_GATES_H
#define LOGIC_GATES_H

#include <stdint.h>

// Basic 1-bit logic gates
uint8_t gate_and(uint8_t a, uint8_t b);
uint8_t gate_nand(uint8_t a, uint8_t b);
uint8_t gate_or(uint8_t a, uint8_t b);
uint8_t gate_nor(uint8_t a, uint8_t b);
uint8_t gate_xor(uint8_t a, uint8_t b);
uint8_t gate_xnor(uint8_t a, uint8_t b);
uint8_t gate_not(uint8_t a);

// Plonck-1 specialized gates
uint8_t gate_orcd(uint8_t acc, uint8_t data);  // OR Complement Data
uint8_t gate_orcr(uint8_t acc, uint8_t data);  // OR Complement Result

#endif // LOGIC_GATES_H
