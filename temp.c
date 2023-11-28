#include <stdio.h>
#include <stdlib.h>

int main() {
    int rifat;
    char turjo [10];
    
    rifat = 123456789;
    
    itoa (rifat, turjo, 10);
    
    puts(turjo);

    return 0;
}