# The Plonck-1 Computer

A silly goofy little 1-bit computer that im making using descrete components and emulating as hardware accurate as i can.  
And also my first ever C project :3  


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
|`111`|**STO**|`ACC → Memory`||

## Architecture
Inspired by the MC14500 ICU and Usagi Electric's 24 vacuum tube SBC variant  
LU integrated into instruction decoder  
Arbitrary expandable ROM/RAM just like the MC14500  
Data is almost always equal to memory or input

## Languages
C  
Python  
Custom Assembly / Machine Code  

## Status
ISA - ✅  
CPU Circuit - WIP  
Memory Circuit - WIP  
CPU Emulator - WIP  
Memory Emulator - WIP  
Assembler - WIP  
