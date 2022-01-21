#include <stdio.h>
#include <stdint.h>

int main(){
    
    int memory[] = {
        443, 1, 1, 0, 0, 406, 84, 474, 406, 101, 474, 406, 115, 474, 406, 116, 474, 406, 32,
        474, 406, 102, 474, 406, 48, 474, 476, 406, 48, 474, 476, 406, 0, 473, 476, 415, 412, -1
    };

    printf("%d\n", *memory);
    printf("%d\n", *memory >> 1);
    printf("%d\n", *memory << 1);
}