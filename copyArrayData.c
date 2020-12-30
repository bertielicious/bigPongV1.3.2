#include "config.h"
#include "arrays.h"
void copyArrayData(uchar data, uchar row)
{
    uchar col = 0;
    gameArray[row][col] = gameArray[row][col]|data;
   // printf("%d  %d    %d\n", data, row, gameArray[row][col]);
}
