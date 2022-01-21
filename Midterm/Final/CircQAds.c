#include "CircQAds.h"


typedef struct{
    uint8_t front; // Queue pointer
    uint8_t back;
    uint8_t count;
    uint8_t* items;
} CircQ;

static uint8_t CircQ_MAX = 40;
static CircQ c;

void CircQ_Init(void){
    uint8_t* i = malloc(sizeof(40 * sizeof(uint8_t)));
    c.items = i;
    c.front = -1;
    c.back = -1;
    c.count = 0;
}

bool CircQ_IsEmpty(void){
    return c.count == 0;
}

bool CircQ_IsFull(void){
    return c.count == 40;
}

void CircQ_Add(uint8_t byte) {
    if(!CircQ_IsFull()){
        c.items[c.front%CircQ_MAX] = byte;
        c.count++;
        c.front = (c.front+1)%CircQ_MAX;
    }
}

uint8_t CircQ_Remove(void)      {
    if(CircQ_IsEmpty()){
        return;
    } else {
        c.count--;
        c.back = (c.back+1)%CircQ_MAX;
        return c.items[c.back];
    }

}