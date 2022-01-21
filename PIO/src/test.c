#include <avr/io.h>

int main(){
    int val = 0;
    PORTB = (1<<PB7) | (1<<PB6) | (1<<PB1) | (1<<PB0);
    DDRB = (1<<DDB3) | (1<<DDB2) | (1<<DDB1) | (1<<DDB0);
    val = PINB;
    return 0;
}