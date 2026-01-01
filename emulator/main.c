#define _POSIX_C_SOURCE 199309L // Apparently needed to do nanosleep idk
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#define CLOCK 1         // Clock frequency in Hz
#define MEMORY_SIZE 4   // Memory address space

const uint8_t ROM[] = {
  0b00010000,
  0b01110000,
  0b00000000,
  0b01110001,
  0b01000010,
  0b11100010,
};

bool RAM[1 << MEMORY_SIZE];
bool data;
bool acc;
uint8_t pc = 0;

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
  data = RAM[address];
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
  printf("Program Counter: %d \tControl: %d \tOpcode: %d \tAddress: %d \t\tData: %d \tAccumulator: %d\n", pc, control, opcode, address, data, acc);
}

int main() {
  while (true){
    struct timespec delay = {0, 999999999 / CLOCK};  // nanoseconds
    nanosleep(&delay, NULL);
    fetch();
    execute(opcode);
    print();
    if(control == true) break;
  }
  return 0;
}
