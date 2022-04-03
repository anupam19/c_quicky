/* Demonstrates initializers */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t main()
{
    uint8_t i = 0;
    uint8_t a[6] = {[2] = 3, [3] = 9, [0] = 1}; /* initialize at index */
    uint8_t b[] = {[0 ... 5] = 4, [1 ... 2] = 6, [8 ... 10] = 2}; /* initialize multiple elements */
    
    for(i = 0; i < sizeof(a); i++)
        printf("\narr a[%d] = %d", i, a[i]);
        
    for(i = 0; i < sizeof(b); i++)
        printf("\narr a[%d] = %d", i, b[i]);

    return 0;
}
