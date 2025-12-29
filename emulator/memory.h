// memory.h
#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

// Memory configuration
#define MEMORY_SIZE 16      // 4-bit address = 16 locations
#define DATA_WIDTH 1        // 1-bit data width

// Memory operations
uint8_t memory_read(uint8_t address);
void memory_write(uint8_t address, uint8_t data);

//void memory_dump(void);     // Print memory contents
//void memory_init(void);     // Initializes memory contents to 0

#endif // MEMORY_H
