#!/usr/bin/env python3
import sys
import os

# Prep the hexfile
output_dir = '../emulator'
output_file = os.path.join(output_dir, 'program.hex')

cleaned_lines = []

# Read all input from stdin (what you pipe in)
input_text = sys.stdin.read()

# Split into lines
lines = input_text.split('\n')

# First pass, removes comments and handles any other compiler stuff
for line in lines:
    # Comments
    if ';' in line:
        line = line.split(';')[0]
    
    # Remove all unneeded spaces
    line = line.strip()
    
    # Create a list of all words in the assembly code
    if line:
        cleaned_lines.append(line)
        #print(line)


# Second pass, converts the assembly to HEX
with open(output_file, 'wb') as f:
    for line in cleaned_lines:
        # Default values
        control = "0"
        address = "0000"
        opcode = "000"

        # Mnemonics = first word per line and is turned to all uppercase
        parts = line.split()
        mnemonic = parts[0].upper()

        match mnemonic:
            case "AND":
                opcode = "000"
            case "XNOR":
                opcode = "001"
            case "NOP":
                opcode = "010"
            case "ORCD":
                opcode = "011"
            case "LD":
                opcode = "100"
            case "ORCR":
                opcode = "101"
            case "OR":
                opcode = "110"
            case "STO":
                opcode = "111"
            case "HALT":
                control = "1"
                opcode = "111"  # STO opcode for HALT
            case _:
                print(f"Error: Unknown instruction '{mnemonic}'")
                control = "1"
                opcode = "111"  # Default to HALT on error

        # Checks for arguments like memory address and direct data input
        if len(parts) > 1:
            argument = parts[1].upper()
            match argument:
                case "1":
                    control = "1"
                case "A0":
                    address = "0000"
                case "A1":
                    address = "0001"
                case "A2":
                    address = "0010"
                case "A3":
                    address = "0011"
                case "A4":
                    address = "0100"
                case "A5":
                    address = "0101"
                case "A6":
                    address = "0110"
                case "A7":
                    address = "0111"
                case "A8":
                    address = "1000"
                case "A9":
                    address = "1001"
                case "A10":
                    address = "1010"
                case "A11":
                    address = "1011"
                case "A12":
                    address = "1100"
                case "A13":
                    address = "1101"
                case "A14":
                    address = "1110"
                case "A15":
                    address = "1111"
                case _:
                    print(f"Error: Invalid argument '{argument}'")
        
        # Instruction formating
        instruction = control+opcode+address
        #print(f"0b{instruction},")
        
        # Create hexfile
        hex_instruction = int(instruction, 2)
        f.write(bytes([hex_instruction]))
        #print(f"0x{hex_instruction},")
