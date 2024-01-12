#include "header.h"
void door(int stageNumber,int*bullet_x,int*bullet_y,int*bullet_dir )
{
        if(stageNumber==4 && *bullet_x==440 && *bullet_y==400)
        {
            *bullet_x=740;
            *bullet_y=150;

        }else if (stageNumber==4 && *bullet_x==740 && *bullet_y==150)
        {
            *bullet_x=440;
            *bullet_y=400;
        }
        if(stageNumber==4 && *bullet_x==490 && *bullet_y==250)
        {
            *bullet_x=540;
            *bullet_y=500;
            if(*bullet_dir == 1)
            {
                *bullet_dir = 3;
            }

        }else if (stageNumber==4 && *bullet_x==540 && *bullet_y==500)
        {
            *bullet_x=490;
            *bullet_y=250;
        }
    
}