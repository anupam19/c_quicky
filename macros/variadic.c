#include <stdio.h>

#define DEBUG(...) {printf(__VA_ARGS__);}

int main()
{
    DEBUG("%x %x %x", 5, 7, 8);
    return 0;
}
