#include "config.h"
#include "clearScreen.h"
#include "clearGameArray.h"
#include "arrays.h"
#include "splashScreen.h"
#include "writeMatrix.h"
uchar gameState(uchar state)
{
    uchar row, col=0;
    switch(state)
    {
        case 0:
            state = 1;
            break;
        case 1:
            clearScreen();
            splashScreen(splishR, splishL);
            __delay_ms(2000);
             clearScreen();
            state = 2;
            break;
        case 2 :
            state = 3;
            break;
        case 3:
            
            writeMatrix();
           
            
             //state = 5;
            break;
           
        case 4:
            break;
        case 5:
            
            break;
            
    }   
    return state;
}
