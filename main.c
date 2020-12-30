/*
 * File:   main.c
 * Author: Phil Glazzard
 *
 * Created on 13 November 2020, 18:52
 */


#include "config.h"
#include "configPorts.h"
#include "configOsc.h"
#include "configSPI.h"
#include "configTMR1.h"
#include "configTMR0.h"
#include "init1_max7219.h"
#include "init2Max7219.h"
#include "configUsart.h"
#include "sendSPIbyte.h"
#include "sendNoSPIbyte.h"
#include "clearScreen.h"
#include "splashScreen.h"
#include "arrays.h"
#include "gameState.h"
#include "pong.h"
#include "writeMatrix.h"
#include "paddleMove.h"
void main(void) 
{
   
   // uchar col, row = 0;
    configPorts();
    configOsc();
    configSPI();
    init1_max7219();
    init2Max7219();
    configUsart();
    configTMR1();
    configTMR0();
    printf("Hello Phil\n");
    uchar state = 0;
    uchar boardWidth = 14;
    uchar boardHeight = 8;
    uchar paddlePos = 4;// paddlePos can be 1-6, low lowest position, 6 highest position
    uchar x = 1;
    clearScreen();
    
    
   /* uchar row, col;
    for(row = 0; row<8; row++)
    {
       for(col = 0; col<16; col++) 
       {
           printf("%d ", gameArray[row][col]);
       }
       printf("\n");
    }*/
    
while(1)
{
   // state = gameState(state);
    
    paddleMove(paddlePos);
    if(RPB ==LO && LPB==HI && paddlePos<6 && paddlePos>=0)
    {
        while(RPB!=HI);
        paddlePos++;            // paddle moves up
    }
    else if(LPB ==LO && RPB==HI && paddlePos<=6 && paddlePos>1)
    {
        while(LPB!=HI);
        paddlePos--;            // paddle moves down
    }
    
     
    
   
}
}
    

   
