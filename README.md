# The Plonck-1 Computer

A silly goofy little 1-bit computer that im emulating as hardware accurate as i can  
And also my first ever C project :3  


## ISA
|**Opcode**|**Mnemonic**|**Operation**|**Notes**
|:---:|:---|:---|:---|
|`X000`|**AND**|`Data AND ACC → ACC`||
|`X001`|**XNOR**|`Data XNOR ACC → ACC`||
|`X010`|**NOP**|`No Operation`||
|`X011`|**ORCD**|`NOT(Data) OR ACC → ACC`||
|`X100`|**LD**|`Data → ACC`||
|`X101`|**ORCR**|`Data OR NOT(ACC) → ACC`||
|`X110`|**OR**|`Data OR ACC → ACC`||
|`X111`|**STO**|`ACC → Memory`|Memory OE gets ignored|
|`0XXX`|**Memory OE**|`No Memory Output`||
|`1XXX`|**Memory OE**|`Memory → Data`||

## Architecture
Inspired by the MC14500 ICU and Usagi Electric's 24 vacuum tube SBC variant  
LU integrated into instruction decoder  
Arbitrary expandable ROM/RAM just like the MC14500  

## Languages
C  
Python  
Custom Assembly / Machine Code  

## Status
ISA - ✅  
Core - WIP  
CPU - WIP  
Auxiliary - WIP  
Assembler - WIP  
