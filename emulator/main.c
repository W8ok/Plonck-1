#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>

#define Clock 1         // Clock frequency in Hz
#define Memory_size 4   // Memory address space

const uint8_t ROM[] = {

};

bool RAM[1 << Memory_size];
bool data, acc;
uint8_t pc = 0;

// Instructions
uint8_t address;
uint8_t opcode;
bool control;

int main() {
  while (true){
    usleep(1000000 / Clock);
    fetch();
    execute(opcode);
  }
}

void fetch(){
  control = (ROM[pc] & 0x80) >> 7; // 0b10000000 not used atm :3
  opcode = (ROM[pc] & 0x70) >> 4;  // 0b01110000
  address = (ROM[pc] & 0x0F);      // 0b00001111

  pc++;
}


void execute(uint8_t operation){
  switch (operation) {
    case 0:
      acc = acc & data;
      break;

    case 1:
      acc = ~(acc ^ data);
      break;

    case 2:
      break;

    case 3:
      acc = acc | (~data);
      break;

    case 4:
      acc = data;
      break;

    case 5:
      acc = (~acc) | data;
      break;

    case 6:
      acc = acc | data;
      break;

    case 7:
      RAM[address] = acc = data;
      break;
  }
}
