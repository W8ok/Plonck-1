#include <stdio.h>
#include "logic_gates.h"

int main() {
    printf("Testing logic gates...\n");
    printf("AND(1,1) = %d\n", gate_and(1, 1));  // Should be 1
    printf("ORCD(0,1) = %d\n", gate_orcd(0, 1)); // NOT(1) OR 0 = 0 OR 0 = 0
    printf("ORCR(1,0) = %d\n", gate_orcr(1, 0)); // 0 OR NOT(1) = 0 OR 0 = 0
    return 0;
}
