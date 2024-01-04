#include "header.h"

int menu_first(ALLEGRO_DISPLAY* display_1,ALLEGRO_EVENT_QUEUE *event_queue_1,struct ResourcePic Pic,struct ResourceAudio Audio) 
{
    al_clear_to_color(al_map_rgb(255, 255, 255));
 
    bool buttonPressed = true;

    int menu=0;
    while (buttonPressed) {

        ALLEGRO_EVENT ev;//用以儲存al_get_next_event所取出的事件
        if (al_get_next_event(event_queue_1, &ev)) 
        {
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
            {
                break;

            } else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                int mouseX = ev.mouse.x;
                int mouseY = ev.mouse.y;
                // Check if the mouse click is within the button area (for simplicity, a rectangle)
                if (mouseX >= DISPLAY_WIDTH/2 - 100 && mouseX <= DISPLAY_WIDTH/2 +100 && mouseY >= DISPLAY_HEIGHT/2 - 225 && mouseY <= DISPLAY_HEIGHT/2 - 150) 
                {
                    al_play_sample(Audio.button, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL);
                    menu=1;
                    break;
                    
                }
                if (mouseX >= DISPLAY_WIDTH/2 - 100 && mouseX <= DISPLAY_WIDTH/2 +100 && mouseY >=DISPLAY_HEIGHT/2 - 75 && mouseY <= DISPLAY_HEIGHT/2) 
                {
                    al_play_sample(Audio.button, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL);
                    //buttonPressed = false;
                    menu=2;
                    break;
                    
                }
                if (mouseX >= DISPLAY_WIDTH/2 - 100 && mouseX <= DISPLAY_WIDTH/2 +100 && mouseY >= DISPLAY_HEIGHT/2 + 75 && mouseY <= DISPLAY_HEIGHT/2 + 150) 
                {
                    al_play_sample(Audio.button, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL);
                    buttonPressed = false;
                    menu=3;
                    break;
                    
                }
                if (mouseX >= 0 && mouseX <= 75 && mouseY >= 0 && mouseY <= 75) 
                {
                    al_play_sample(Audio.button, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL);
                    game_instruction(display_1,event_queue_1,Pic,Audio);
                    
                }
            } 
        }
        al_draw_bitmap(Pic.back,0, 0, 0);
        al_draw_bitmap(Pic.background,DISPLAY_WIDTH/2 -250 , DISPLAY_HEIGHT/2 - 300 , 0);
        al_draw_bitmap(Pic.restartbutton,DISPLAY_WIDTH/2 -100, DISPLAY_HEIGHT/2 - 225, 0);
        al_draw_bitmap(Pic.contiune,DISPLAY_WIDTH/2 -100, DISPLAY_HEIGHT/2 - 75, 0);
        al_draw_bitmap(Pic.exit,DISPLAY_WIDTH/2 -100, DISPLAY_HEIGHT/2 + 75, 0);
        al_draw_bitmap(Pic.question,10, 10, 0);
        al_flip_display();    
    }

    return menu;

}

int menu_second(ALLEGRO_DISPLAY*display,ALLEGRO_EVENT_QUEUE *event_queue,struct ResourcePic Pic,struct ResourceAudio Audio) 
{

    bool buttonPressed = true;

    int menu=0;
    while (buttonPressed) {

        ALLEGRO_EVENT ev;//用以儲存al_get_next_event所取出的事件
        if (al_get_next_event(event_queue, &ev)) 
        {
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
            {
                break;

            } else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                int mouseX = ev.mouse.x;
                int mouseY = ev.mouse.y;
                // Check if the mouse click is within the button area (for simplicity, a rectangle)
                if (mouseX >= DISPLAY_WIDTH/2 -163 && mouseX <= DISPLAY_WIDTH/2 -87 && mouseY >= DISPLAY_HEIGHT/2 - 225 && mouseY <= DISPLAY_HEIGHT/2 - 150) 
                {

                    al_play_sample(Audio.start, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL);
                    buttonPressed = false;
                    menu = 1;

                }
                if (mouseX >= DISPLAY_WIDTH/2 -38 && mouseX <= DISPLAY_WIDTH/2 +37 && mouseY >= DISPLAY_HEIGHT/2 - 225 && mouseY <= DISPLAY_HEIGHT/2 - 150) 
                {
                    al_play_sample(Audio.start, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL);
                    buttonPressed = false;
                    menu = 2;
                }
                if (mouseX >= DISPLAY_WIDTH/2 +87 && mouseX <= DISPLAY_WIDTH/2 +162 && mouseY >= DISPLAY_HEIGHT/2 - 225 && mouseY <= DISPLAY_HEIGHT/2 - 150) 
                {   
                    al_play_sample(Audio.start, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL);
                    buttonPressed = false;
                    menu = 3;
                    
                }
                if (mouseX >= DISPLAY_WIDTH/2 - 100 && mouseX <= DISPLAY_WIDTH/2 +100 && mouseY >= DISPLAY_HEIGHT/2 - 75 && mouseY <= DISPLAY_HEIGHT/2) 
                {   
                    al_play_sample(Audio.button, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL);
                    buttonPressed = false;
                    menu= 4;
                }
                if (mouseX >= DISPLAY_WIDTH/2 - 100 && mouseX <= DISPLAY_WIDTH/2 +100 && mouseY >= DISPLAY_HEIGHT/2 + 75 && mouseY <= DISPLAY_HEIGHT/2 + 150) 
                {
                    menu = 5;

                    buttonPressed = false;
                }
                if (mouseX >= 0 && mouseX <= 75 && mouseY >= 0 && mouseY <= 75) 
                {
                    al_play_sample(Audio.button, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL);
                    game_instruction(display,event_queue,Pic,Audio);

                    
                }
            } 
        }
        //al_clear_to_color(al_map_rgb(255, 255, 255));
        // Draw the button
        al_draw_bitmap(Pic.back,0, 0, 0);
        al_draw_bitmap(Pic.background,DISPLAY_WIDTH/2 -250, DISPLAY_HEIGHT/2 - 300, 0);
        al_draw_bitmap(Pic.level1,DISPLAY_WIDTH/2 -163, DISPLAY_HEIGHT/2 - 225 , 0);
        al_draw_bitmap(Pic.level2,DISPLAY_WIDTH/2 -38, DISPLAY_HEIGHT/2 - 225 , 0);
        al_draw_bitmap(Pic.level3,DISPLAY_WIDTH/2 +87, DISPLAY_HEIGHT/2 - 225 , 0);
        al_draw_bitmap(Pic.historybutton,DISPLAY_WIDTH/2 -100, DISPLAY_HEIGHT/2 - 75, 0);
        al_draw_bitmap(Pic.exit,DISPLAY_WIDTH/2 -100, DISPLAY_HEIGHT/2 + 75 , 0);
        al_draw_bitmap(Pic.question,10, 10, 0);
        al_flip_display();
    }

    return menu;
}

int returnfirstmenu(ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_DISPLAY *display,int*positionx,int*positiony,struct ResourcePic Pic,struct ResourceAudio Audio)
{
    ALLEGRO_EVENT ev;
    int menu=0;
    al_peek_next_event(event_queue, &ev);
    
    if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_LSHIFT)
    {       
            menu = menu_first(display,event_queue,Pic,Audio);
            if(menu==1)
            {
                *positionx = 340 ;
                *positiony = 0;
                menu=1;
            }
            else if(menu==2)
            {
                menu=0;
            }
            else if(menu==3)
            {
                menu=3;
            }

        }
    
    return menu;      
}

void endgame(ALLEGRO_DISPLAY*display,ALLEGRO_EVENT_QUEUE *event_queue,struct ResourcePic Pic,struct ResourceAudio Audio,int CurrentScore,int MaxScore,int stageNumber,int* highestScore,struct ResourceFont Font) 
{

    bool buttonPressed = true;
    ALLEGRO_BITMAP* end_plane = NULL;

    if(CurrentScore <= MaxScore/3)
    {
    end_plane = al_load_bitmap("zero star.png");
    }
    if(CurrentScore > MaxScore/3 && CurrentScore <= 2*MaxScore/3)
    {
    end_plane = al_load_bitmap("one star.png");
    }
    if(CurrentScore > 2*MaxScore/3 && CurrentScore <= MaxScore)
    {
    end_plane = al_load_bitmap("two star.png");
    }
    if(CurrentScore == MaxScore)
    {
    end_plane = al_load_bitmap("three star.png");
    }
    if(CurrentScore > highestScore[stageNumber-1]){

    highestScore[stageNumber-1] = CurrentScore;
            
    }

 
 //   int menu=0;
    while (buttonPressed) {

        ALLEGRO_EVENT ev;//用以儲存al_get_next_event所取出的事件
        if (al_get_next_event(event_queue, &ev)) 
        {
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
            {
                break;

            } else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                int mouseX = ev.mouse.x;
                int mouseY = ev.mouse.y;

                if (mouseX >= DISPLAY_WIDTH/2 - 100 && mouseX <= DISPLAY_WIDTH/2 +100 && mouseY >=DISPLAY_HEIGHT/2 - 75 && mouseY <= DISPLAY_HEIGHT/2) 
                {
                    al_play_sample(Audio.button, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL);

                    break;
                    
                }

            } 
        }

        al_draw_bitmap(Pic.back,0, 0, 0);
        
        al_draw_bitmap(end_plane,DISPLAY_WIDTH/2 -250, DISPLAY_HEIGHT/2 - 300, 0); 
        al_draw_bitmap(Pic.contiune,DISPLAY_WIDTH/2 - 100, DISPLAY_HEIGHT/2 - 75, 0); 
        al_draw_filled_rectangle(DISPLAY_WIDTH/2 -100, 400, DISPLAY_WIDTH/2 +100, 450, al_map_rgb(100, 65, 0));
        ScoreDisplay(Font.fontSmall,CurrentScore,DISPLAY_WIDTH/2 -70,410);
        al_flip_display();    
    }
        ScoreFileSave (highestScore);
        al_destroy_bitmap(end_plane);

        

}

void displayLoadingScreen(ALLEGRO_FONT *font, struct ResourcePic Pic, int cycles) {
    const int maxDots = 4; 

    for (int cycle = 0; cycle < cycles; ++cycle) {
        for (int dots = 1; dots <= maxDots; ++dots) {
            al_draw_bitmap(Pic.back, 0, 0, 0);
            al_draw_filled_rectangle(400, 300, 700, 390, al_map_rgb(100, 65, 0));

            
            char loadingText[20];
            sprintf(loadingText, "Loading%s", dots == 1 ? "" : (dots == 2 ? "." : (dots == 3 ? ".." : "...")));

            al_draw_text(font, al_map_rgb(240, 240, 240), 410, 310, ALLEGRO_ALIGN_LEFT, loadingText);

            al_flip_display();
            al_rest(0.3); 
        }
    }
}

void game_instruction(ALLEGRO_DISPLAY* display_1,ALLEGRO_EVENT_QUEUE *event_queue_1,struct ResourcePic Pic,struct ResourceAudio Audio) 
{
    bool buttonPressed = true;
    while (buttonPressed) 
    {
        al_draw_bitmap(Pic.back,0, 0, 0);
        al_draw_bitmap(Pic.exit,30, 20, 0);
        al_draw_bitmap(Pic.GameInstructions,70, 100, 0);
        ALLEGRO_EVENT ev;//用以儲存al_get_next_event所取出的事件
        if (al_get_next_event(event_queue_1, &ev)) 
        {
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
            {
                break;

            } else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) 
            {
                int mouseX = ev.mouse.x;
                int mouseY = ev.mouse.y;
                // Check if the mouse click is within the button area (for simplicity, a rectangle)
                if (mouseX >= 0 && mouseX <= 200&& mouseY >= 0 && mouseY <= 65) 
                {
                    al_play_sample(Audio.button, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL);
                    buttonPressed = false;
                    
                }
               
            } 
        }
        
        al_flip_display();    
    }
    
}

void historygame(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, struct ResourcePic Pic, struct ResourceAudio Audio, int *highestScore, struct ResourceFont Font) {
    bool buttonPressed = true;
    char ScoreText[3][10];
    int i;

    while (buttonPressed) {
        ALLEGRO_EVENT ev;

        // Wait for the next event
        if (al_get_next_event(event_queue, &ev)) {
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                break;  // Break out of the loop if the display is closed
            } else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                int mouseX = ev.mouse.x;
                int mouseY = ev.mouse.y;

                if (mouseX >= 0 && mouseX <= 200 && mouseY >= 0 && mouseY <= 65) {
                    // Handle button press in the top left corner
                    al_play_sample(Audio.button, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    break;
                }

                if (mouseX >= 1000 && mouseX <= 1200 && mouseY >= 545 && mouseY <= 605) {
                    // Handle button press for clearing history
                    al_play_sample(Audio.button, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    ScoreFileClear();
                    break;
                }

                if (highestScore[1] >= 40 && highestScore[2] >= 40 && highestScore[3] >= 40) {
                    if (mouseX >= 1064 && mouseX <= 1134 && mouseY >= 375 && mouseY <= 450) {
                        // Handle button press for level 4 if conditions are met
                        al_play_sample(Audio.start, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                        player(display, event_queue, 4, Pic, Audio, Font, highestScore);
                        break;
                    }
                }
            }
        }

        // Drawing graphics
        al_draw_bitmap(Pic.back, 0, 0, 0);
        al_draw_filled_rectangle(DISPLAY_WIDTH / 2 - 250, DISPLAY_HEIGHT / 2 - 300, DISPLAY_WIDTH / 2 + 250, DISPLAY_HEIGHT / 2 + 300, al_map_rgb(180, 135, 65));
        al_draw_bitmap(Pic.level1, DISPLAY_WIDTH / 2 - 240, DISPLAY_HEIGHT / 2 - 225, 0);
        al_draw_bitmap(Pic.level2, DISPLAY_WIDTH / 2 - 240, DISPLAY_HEIGHT / 2 - 25, 0);
        al_draw_bitmap(Pic.level3, DISPLAY_WIDTH / 2 - 240, DISPLAY_HEIGHT / 2 + 175, 0);

        al_draw_bitmap(Pic.contiune, 30, 20, 0);

        if (highestScore[1] >= 40 && highestScore[2] >= 40 && highestScore[3] >= 40) {
            al_draw_bitmap(Pic.level4, 1064, 375, 0);
        }

        al_draw_filled_rectangle(1000, 545, 1200, 605, al_map_rgb(100, 65, 0));
        al_draw_text(Font.fontSmall, al_map_rgb(240, 240, 240), 1100, 555, ALLEGRO_ALIGN_CENTER, "Clear History");

        for (i = 0; i < 3; i++) {
            snprintf(ScoreText[i], sizeof(ScoreText[i]), "%d", highestScore[i]);
            al_draw_text(Font.fontBig, al_map_rgb(240, 240, 240), DISPLAY_WIDTH / 2 - 90, DISPLAY_HEIGHT / 2 - 223 + 200 * i, ALLEGRO_ALIGN_LEFT, ScoreText[i]);
        }

        al_flip_display();  // Flip the display to show the updated graphics
        al_rest(0.02); // Adjust the delay as needed to control the frame rate

    }
}
