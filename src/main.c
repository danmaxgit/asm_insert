#include "stdio.h"



int main()
{
    unsigned int n=4, sum = 0, index = 0;
    scanf("%d", &n);
    // printf("%d\n", n);
    asm(" \
    movl %0, %%edx; \
    movl %1, %%ecx; \
    mainloop: \
    movl %2, %%eax; \
    incl %%eax; \
    mull %2; \
    movl $2, %%ebx; \
    divl %%ebx, %%eax; \
    incl %%eax; \
    addl %%eax, %%edx; \
    movl %%eax, %%edx; \
    movl %2, %%eax;\
    incl %%eax;\
    movl %%eax, %2; \
    loopl mainloop; \
    movl %%edx, %0;"
    
    : "=r" (sum)
    : "r" (n), "r" (index)
    : "eax", "ebx", "edx", "ecx"
    );
    //!TODO не сохраняется сумма
    printf("sum = %d\n", sum);
    return 0;
}

