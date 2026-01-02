# The Plonck-1 Computer

A silly goofy little 1-bit computer that im writing an emulator for.  
And also my first ever C project and the goal isnt to make the best thing ever, but to just to get used to the C syntax.  
  
Inspired by the MC14500 ICU and Usagi Electric's 24 vacuum tube SBC variant.  
https://github.com/Nakazoto/UE-0.1/tree/main  

## Architecture
LU integrated into instruction decoder  
Arbitrary expandable ROM/RAM just like the MC14500.  
Data is almost always equal to memory or input.  
Machine code is written in the format: DOOOAAAA, where D is Data, O is opcode and A is address.  

**Look at the included .asm files for example assembly code and syntax.**  
To assemble a program, pipe your .asm file into the assembler.py,  
In Linux, cd into the programs directory and do: `cat test.asm | assembler.py`  
this will create a hexfile in the emulator directory.  
The computer will execute it automatically, so long as you dont somehow, for some reason write a program more than 64kB large.  
To run the computer enter the emulator directory and run: `make run` and watch it go at a default of 10Hz.  
At the end of every program please use the function "**HALT**", this tells the computer to halt and output its memory content.  

## ISA
|**Opcode**|**Mnemonic**|**Operation**|**Notes**
|:---:|:---|:---|:---|
|`000`|**AND**|`Data AND ACC → ACC`||
|`001`|**XNOR**|`Data XNOR ACC → ACC`||
|`010`|**NOP**|`No Operation`||
|`011`|**ORCD**|`NOT(Data) OR ACC → ACC`||
|`100`|**LD**|`Data → ACC`||
|`101`|**ORCR**|`Data OR NOT(ACC) → ACC`||
|`110`|**OR**|`Data OR ACC → ACC`||
|`111`|**STO**|`ACC → Memory`|If the Data signal is also high it results in a Halt operation|


## Languages
C  
Python  
Custom Assembly / Machine Code  

## Status
ISA - Finished  
Emulator - Finished prototype  
Assembler - Finished prototype  
