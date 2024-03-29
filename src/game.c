#include "header.h"

void player(ALLEGRO_DISPLAY *display,ALLEGRO_EVENT_QUEUE *event_queue,int stageNumber,struct ResourcePic Pic,struct ResourceAudio Audio,struct ResourceFont Font,int* highestScore,int* MaxScore)
{   

    int stage [40][40];
    struct barrier barrier[144];
    int positionx = 340;
    int positiony = 0  ;
    int bullet_x = 1000;
    int bullet_y = 1000;
    int bullet_dir = -1; // -1 表示沒有子彈
    int transbomb=0;

    int arrowR_x = 340 ;
    int arrowR_y = 800 ;
    int arrowL_x = 890 ;
    int arrowL_y = 800 ;
    int arrowU_x = 1280;
    int arrowU_y = 600 ;    
    int arrowD_x = 1280;
    int arrowD_y = 50  ;
    int score = 0;
    int CurrentScore = 0;
    int bombNUM[3];

    initial_array(barrier);
    stagefile(stage,barrier,stageNumber,bombNUM,&Pic);

    MaxScore[stageNumber-1] = StageChanged( stage );
    int previousScore = MaxScore[stageNumber-1];
    int menu =0;

    displayLoadingScreen(Font.fontBig,Pic,1);
    
    
    while ( menu != 3 )
    {
        
        al_draw_bitmap(Pic.back, 0, 0, 0);
        al_draw_bitmap(Pic.map, 290, 0, 0);
        al_draw_bitmap(Pic.BombType, 45, 50, 0);

        al_draw_filled_rectangle(1025 , 50 , 1245 ,400,al_map_rgb(180, 135, 65));
        al_draw_text(Font.fontSmall, al_map_rgb(240, 240, 240), 1045, 115, ALLEGRO_ALIGN_LEFT, "Next:");
        LevelDisplay(Font.fontSmall,stageNumber);
        BombTypeDisplay(Font.fontSmall,bombNUM,Pic);



        stageprint(stage,Pic.bitmapstone,Pic.redfish,Pic.yellowfish,Pic.bluefish,Pic.grass);
        al_draw_bitmap(Pic.playerPic, positionx, positiony, 0);
        if(transbomb==0 && bombNUM[0] >= 0)
        {
            al_draw_bitmap(Pic.bomp, bullet_x, bullet_y, 0);
            al_draw_bitmap(Pic.bomp, 1135, 110, 0);
        }
        else if(transbomb==1 && bombNUM[1] >= 0)
        {
            al_draw_bitmap(Pic.bomp2, bullet_x, bullet_y, 0);
            al_draw_bitmap(Pic.bomp2, 1135, 110, 0); 
        }
        else if(transbomb==2 && bombNUM[2] >= 0)
        {
            al_draw_bitmap(Pic.bomp3, bullet_x, bullet_y, 0);
            al_draw_bitmap(Pic.bomp3, 1135, 110, 0);
        }
        al_draw_bitmap(Pic.bitmap_right,arrowR_x,arrowR_y,0);
        al_draw_bitmap(Pic.bitmap_left,arrowL_x,arrowL_y,0);
        al_draw_bitmap(Pic.bitmap_up,arrowU_x,arrowU_y,0);
        al_draw_bitmap(Pic.bitmap_down,arrowD_x,arrowD_y,0);
        ScoreDisplay(Font.fontSmall,CurrentScore,MaxScore,stageNumber,1040,60);

        menu = returnfirstmenu(event_queue,display,&positionx,&positiony,Pic,Audio);
        if(menu==1)
        {
            stagefile(stage,barrier,stageNumber,bombNUM,&Pic);
        }
        DetonateBomb(event_queue, &bullet_x, &bullet_y, &bullet_dir, &transbomb,Pic.bitmapexplosion,stage,bombNUM,Audio);
        moveplayer(event_queue,&positionx, &positiony,&bullet_x,&bullet_y,&bullet_dir,&transbomb,bombNUM,Audio);
        
        if(bullet_x > 290 && bullet_x < 940 && bullet_y > 0 && bullet_y < 650 )
        {
            detectbarrier(barrier,&bullet_x,&bullet_y,&bullet_dir,&transbomb,Pic.bitmapexplosion,stage,bombNUM,Audio);
        }

        renew_arrow(&positionx,&positiony,&arrowD_x,&arrowU_x,&arrowR_y,&arrowL_y);
        renew_bullet(&bullet_dir,&bullet_x,&bullet_y);
        score = StageChanged( stage );

        if (score != previousScore)
        {
            CurrentScore = MaxScore[stageNumber-1] - score;    
            previousScore = score;
        }

        if(bombNUM[0] == 0 && bombNUM[1] == 0 && bombNUM[2] == 0)
        {
            menu = endgame(display,event_queue,Pic,Audio,CurrentScore,MaxScore,stageNumber,highestScore,Font);
            stagefile(stage,barrier,stageNumber,bombNUM,&Pic);
        }

        //第四關小改造
        door(stageNumber,&bullet_x,&bullet_y,&bullet_dir );

        fresharray(stage,barrier);
        al_rest(0.01);
        
        // 繪製畫面
        
        al_flip_display();
        al_rest(0.01);
    }

    displayLoadingScreen(Font.fontBig,Pic,1);

    // Cleanup
    
}