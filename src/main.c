#include "header.h"

int main ()
{   
    
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    initial_src();
    struct ResourcePic Pic;
    struct ResourceAudio Audio;
    struct ResourceFont Font;
    int highestScore[4];
    int MaxScore[4];
    resourceInitPic(&Pic);
    resourceInitAudio(&Audio);
    resourceInitFont(&Font);
    resourceLoadPic(&Pic);
    resourceLoadAudio(&Audio);
    resourceLoadFont(&Font);

    ScoreFileLoad (highestScore,MaxScore);

    display = al_create_display(DISPLAY_WIDTH,DISPLAY_HEIGHT);
    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    displayLoadingScreen(Font.fontBig,Pic,3);
    al_play_sample(Audio.background, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

    int menu=0;
    while(1)
    {
     
        menu=0;
        menu=menu_second(display,event_queue,Pic,Audio);
        if(menu==1)
        {
            player(display,event_queue,1,Pic,Audio,Font,highestScore,MaxScore);
           
        }else if(menu==2)
        {
            player(display,event_queue,2,Pic,Audio,Font,highestScore,MaxScore);
            
        }else if (menu==3)
        {
            player(display,event_queue,3,Pic,Audio,Font,highestScore,MaxScore);
            
            
        }else if (menu==4)
        {   
            ScoreFileLoad (highestScore,MaxScore);
            historygame(display,event_queue,Pic,Audio,highestScore,Font,MaxScore);
            
        }else if(menu==5)
        {
            break;
        }
    }
  al_destroy_display(display);
  al_destroy_event_queue(event_queue);
  resourceDestoryPic(&Pic);
  resourceDestoryAudio(&Audio);
  resourceDestoryFont(&Font);
  return 0;
}