#include "hal_MM.h"
#include "BargraphHAL.h"

void memory_viewer(Bargraph b, uint8_t freeblocks){
    uint8_t occupiedblocks = ByteMapSize - freeblocks; // Get occupied blocks
    if(occupiedblocks >= ByteMapSize*0.25 && occupiedblocks < ByteMapSize*0.5){
        // turn on 3 leds if the number of occupied blocks are more than 25%
        // of available memory
        hal_Bargraph_Set(b, 0);
        _delay_ms(500);
        hal_Bargraph_Clear(b, 0);
        _delay_ms(500);
    } else if (occupiedblocks >= ByteMapSize*0.5 && occupiedblocks < ByteMapSize*0.75){
        // turn on 3 leds if the number of occupied blocks are more than 50%
        // of available memory
        hal_Bargraph_Set(b, 0);
        hal_Bargraph_Set(b, 1);
        _delay_ms(500);
        hal_Bargraph_Clear(b, 0);
        hal_Bargraph_Clear(b, 1);
        _delay_ms(500);
    } else if (occupiedblocks >= ByteMapSize*0.75 && occupiedblocks < ByteMapSize){
        // turn on 3 leds if the number of occupied blocks are more than 75%
        // of available memory
        hal_Bargraph_Set(b, 0);
        hal_Bargraph_Set(b, 1);
        hal_Bargraph_Set(b, 2);
        _delay_ms(500);
        hal_Bargraph_Clear(b, 0);
        hal_Bargraph_Clear(b, 1);
        hal_Bargraph_Clear(b, 2);
        _delay_ms(500);
    } else if (occupiedblocks == ByteMapSize){
        // turn on all leds if all blocks are used
        hal_Bargraph_Set(b, 0);
        hal_Bargraph_Set(b, 1);
        hal_Bargraph_Set(b, 2);
        hal_Bargraph_Set(b, 3);
        _delay_ms(500);
        hal_Bargraph_Clear(b, 0);
        hal_Bargraph_Clear(b, 1);
        hal_Bargraph_Clear(b, 2);
        hal_Bargraph_Clear(b, 3);
        _delay_ms(500);
    }else{
        // if its less than 25%, then no leds are lit
        _delay_ms(1000);
    }
}


int main(int argc, char* argv[]) {

    Bargraph b = hal_Bargraph_New(4);

    uint8_t* mp[10];

    hal_MM_Init();
    hal_MM_PrintByteMap();

    mp[0] = hal_MM_GetSegment(106);
    hal_MM_PrintByteMap();
    printf("main:FreeBlocks[%u]\n---\n", bsl_MM_GetNumberOfFreeBlocks());
    memory_viewer(b, bsl_MM_GetNumberOfFreeBlocks());

    mp[1] = hal_MM_GetSegment(143);
    hal_MM_PrintByteMap();
    printf("main:FreeBlocks[%u]\n---\n", bsl_MM_GetNumberOfFreeBlocks());
    memory_viewer(b, bsl_MM_GetNumberOfFreeBlocks());

    mp[2] = hal_MM_GetSegment( 34);
    hal_MM_PrintByteMap();
    printf("main:FreeBlocks[%u]\n---\n", bsl_MM_GetNumberOfFreeBlocks());
    memory_viewer(b, bsl_MM_GetNumberOfFreeBlocks());

    mp[3] = hal_MM_GetSegment(213);
    hal_MM_PrintByteMap();
    printf("main:FreeBlocks[%u]\n---\n", bsl_MM_GetNumberOfFreeBlocks());
    memory_viewer(b, bsl_MM_GetNumberOfFreeBlocks());

    mp[4] = hal_MM_GetSegment( 42);
    hal_MM_PrintByteMap();
    printf("main:FreeBlocks[%u]\n---\n", bsl_MM_GetNumberOfFreeBlocks());
    memory_viewer(b, bsl_MM_GetNumberOfFreeBlocks());

    mp[5] = hal_MM_GetSegment(215);
    hal_MM_PrintByteMap();
    printf("main:FreeBlocks[%u]\n---\n", bsl_MM_GetNumberOfFreeBlocks());
    memory_viewer(b, bsl_MM_GetNumberOfFreeBlocks());

    mp[6] = hal_MM_GetSegment(15);
    hal_MM_PrintByteMap();
    printf("main:FreeBlocks[%u]\n---\n", bsl_MM_GetNumberOfFreeBlocks());
    memory_viewer(b, bsl_MM_GetNumberOfFreeBlocks());

    printf("main:** Start freeing segments and defragmentation\n");
    for (int n = 0; n < 7; n++) {
        printf("\nmain:** Free segment #%d\n", n);
        hal_MM_FreeSegment(mp[n]);
        hal_MM_PrintByteMap();
        printf("main: Before defrag - FreeBlocks[%u]\n", bsl_MM_GetNumberOfFreeBlocks());
        memory_viewer(b, bsl_MM_GetNumberOfFreeBlocks());

        hal_MM_Defrag();
        hal_MM_PrintByteMap();
        printf("main: After  defrag - FreeBlocks[%u]\n", bsl_MM_GetNumberOfFreeBlocks());
        memory_viewer(b, bsl_MM_GetNumberOfFreeBlocks());
    }
    printf("\nmain: Exit - FreeBlocks[%u]\n", bsl_MM_GetNumberOfFreeBlocks());
    return 0;
}