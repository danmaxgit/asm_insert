#include "stdio.h"
#include "stdint.h"


int main() {
   uint64_t n = 4, sum = 0, index = 0;
    scanf("%ld", &n);
    printf("%ld\n", n);
    asm ("\
        movq $0, %3; \
        movq %1, %%rcx; \
    mainloop: \
        movq %2, %%rax; \
        incq %%rax; \
        mulq %2; \
        movq $2, %%rbx; \
        divq %%rbx, %%rax; \
        incq %%rax; \
        movq %3, %%rbx; \
        addq %%rax, %%rbx; \
        movq %%rbx, %3; \
        movq %2, %%rax; \
        incq %%rax; \
        movq %%rax, %2; \
    loopq mainloop; \
        movq %3, %%rax; \
        movq %%rax, %0;"
    
    : "=r" (sum)
    : "r" (n), "r" (index), "r" (sum)
    : "rax", "rbx", "rcx", "rdx"
    );
    //!TODO не сохраняется сумма
    printf("sum = %ld\n", sum);
    return 0;
}

