#define _POSIX_C_SOURCE 199309L // Apparently needed to do nanosleep idk
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#define CLOCK 10        // Clock frequency in Hz
#define MEMORY_SIZE 4   // Memory address space
#define ROM_SIZE 16     // ROM address space

uint8_t ROM[1 << ROM_SIZE];
uint16_t pc = 0;
size_t rom_size = 0;

bool RAM[1 << MEMORY_SIZE] = {0};
bool data = 0;
bool acc = 0;

// Instructions
uint8_t address;
uint8_t opcode;
bool control;

void fetch(){
  control = (ROM[pc] & 0x80) >> 7; // 0b10000000 used as HLT for now
  opcode = (ROM[pc] & 0x70) >> 4;  // 0b01110000
  address = (ROM[pc] & 0x0F);      // 0b00001111

  pc++;
}

void execute(uint8_t operation){
  if(control == true) data = true;
  else data = RAM[address];

  switch (operation) {
    case 0:
      acc = acc & data;
      break;

    case 1:
      acc = !(acc ^ data);
      break;

    case 2:
      break;

    case 3:
      acc = acc | (!data);
      break;

    case 4:
      acc = data;
      break;

    case 5:
      acc = (!acc) | data;
      break;

    case 6:
      acc = acc | data;
      break;

    case 7:
      RAM[address] = acc;
      break;
  }
}

void print(){
  printf("Program Counter: %d \tControl: %d \tOpcode: %d \tAddress: %d \t\tData: %d \tAccumulator: %d\n", pc-1, control, opcode, address, data, acc);
}

int main() {

  // Read the program.hex file
  FILE* f = fopen("program.hex", "rb");
  rom_size = fread(ROM, 1, sizeof(ROM), f);
  fclose(f);

  while (true){
    struct timespec delay = {0, 999999999 / CLOCK};  // nanoseconds
    nanosleep(&delay, NULL);
    fetch();
    if(control == true && opcode == 0b111) {
      printf("Memory Content: \t");
      for(int i = 0; i<(1<<MEMORY_SIZE); i++) {
        printf("%d", RAM[i]);
      }
      printf("\n");
      break;
    }
    execute(opcode);
    print();
  }
  return 0;
}
