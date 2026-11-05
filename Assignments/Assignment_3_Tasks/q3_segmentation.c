#include <stdio.h>

/* 
 * Q3: Segmentation Simulation
 * Segment table: base and limit
 */
struct seg { 
    const char *name; 
    unsigned base;
    unsigned limit; 
};

struct seg st[] = {
    {"code", 1400, 1000}, 
    {"data", 6300, 400}, 
    {"stack", 4300, 1100}, 
    {"heap", 3200, 500}
};

int main(void)
{
    unsigned s[] = {0, 0, 1, 1, 2, 2, 3, 3, 4};
    unsigned o[] = {53, 1000, 0, 399, 1099, 1100, 499, 600, 10};

    printf("--- Q3: Segmentation - Address Translation ---\n");
    for (int i = 0; i < 9; i++) {
        printf("(%u, %4u) : ", s[i], o[i]);
        if (s[i] >= 4) { 
            printf("invalid segment number -> trap\n"); 
            continue; 
        }
        if (o[i] >= st[s[i]].limit)
            printf("offset >= limit (%u) in %s -> trap (segmentation fault)\n", st[s[i]].limit, st[s[i]].name);
        else
            printf("%-5s physical %u + %u = %u\n", st[s[i]].name, st[s[i]].base, o[i], st[s[i]].base + o[i]);
    }
    return 0;
}
