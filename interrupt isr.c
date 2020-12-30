#include "config.h"
#include "arrays.h"
#include "clearScreen.h"
#include "paddleMove.h"
#include "writeMatrix.h"
void interrupt isr(void)
{
   if(INTCONbits.TMR0IF == HI)
  //  if(INTCONbits.TMR0IF == HI)
   {
       uchar col, row;
       char colSpeed, rowSpeed;
       if(g==HI)
       {
       if(col>=14)
       {
           colSpeed = -1;
       }
       else if(col<=1)
       {
           colSpeed = 1;
       }
       if(row>7)
       {
           rowSpeed = -1;
       }
       else if(row<1)
       {
           rowSpeed = 1;
       }
       col = col + colSpeed;
       row = row + rowSpeed;
       g = LO;
       gameArray[row][col] = 1;
       writeMatrix();
        
       for(irow = 0; irow<8; irow++)
            {
                for(icol=1; icol<15;icol++)
                {
                    if(gameArray[irow][icol]==1)
                    { 
                        gameArray[irow][icol] = 0x00;// clear row 0 of previous paddle position data
                    }
                    else
                    {
                        continue;
                    }
                }
            } 
       }
       else
       {
           g=HI;
       }
        DIAGNOSTIC_LED = ~DIAGNOSTIC_LED;
        TMR0=0x00;   
        
        INTCONbits.TMR0IF = LO;
   }
   
    if(PIR1bits.TMR1IF==HI)// paddles
    { 
        for(irow = 0; irow<8; irow++)
        {
            for(icol=0; icol<1;icol++)
                {
                    if(gameArray[irow][icol]==1)
                    { 
                        gameArray[irow][icol] = 0x00;// clear row 0 of previous paddle position data
                    }
                    else
                    {
                        continue;
                    }
                }
        }
           
    
  
        
       // DIAGNOSTIC_LED = ~DIAGNOSTIC_LED;
        TMR1H = 0x7f;
                              // preload TMR1 to generate a 125ms interrupt
        TMR1L = 0x00;
       
        PIR1bits.TMR1IF = LO;   
    }   
}
