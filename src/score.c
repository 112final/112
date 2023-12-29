#include "header.h"

int StageChanged(int stage[40][40]) {
    static int previousStage[40][40] = {{0}}; // 設一個previousStage來計算當前場上分數 
    int score = 0;
    for (int j = 0; j < 12; j++) {
        for (int i = 0; i < 12; i++) {
            if (stage[j][i] != previousStage[j][i]) {
                if(stage[j][i] == 1){
                    score = score + 1;
                }
                if(stage[j][i] == 2){
                    score = score + 2;
                }
                if(stage[j][i] == 3){
                    score = score + 3;
                }
            }
        }
    }
    return score; 
}
 
void ScoreDisplay(ALLEGRO_FONT *font,int score){
    char scoreText[10];
    snprintf(scoreText, sizeof(scoreText), "Score: %d", score);
    al_draw_text(font, al_map_rgb(240, 240, 240), 1045, 60, ALLEGRO_ALIGN_LEFT, scoreText);
}

void LevelDisplay(ALLEGRO_FONT *font,int level){
    char LevelText[10];
    snprintf(LevelText, sizeof(LevelText), "Level %d", level);
    al_draw_text(font, al_map_rgb(240, 240, 240), 1045, 355, ALLEGRO_ALIGN_LEFT, LevelText);
}

void BombTypeDisplay(ALLEGRO_FONT *font,int bombNum[3],struct ResourcePic Pic){

    int i;
    char BombNumText[10];
    al_draw_bitmap(Pic.bomp, 1045, 170, 0);
    al_draw_bitmap(Pic.bomp2, 1045, 230, 0);
    al_draw_bitmap(Pic.bomp3, 1045, 290, 0);
    for(i = 0 ;i < 3;i++){
        snprintf(BombNumText, sizeof(BombNumText), " x %d", bombNum[i]);
        al_draw_text(font, al_map_rgb(240, 240, 240), 1100, 175 + 60*i, ALLEGRO_ALIGN_LEFT, BombNumText);
    }

}

void historygame(ALLEGRO_DISPLAY*display,ALLEGRO_EVENT_QUEUE *event_queue,struct ResourcePic Pic,struct ResourceAudio Audio,int* highestScore,struct ResourceFont Font) 
{
    bool buttonPressed = true;
    char ScoreText[3][10];
    int i;
    

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

                if (mouseX >= 0 && mouseX <= 200 && mouseY >= 0 && mouseY <= 65) 
                {
                    al_play_sample(Audio.button, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL);

                    break;
                    
                }

            } 
        }

        al_draw_bitmap(Pic.back,0, 0, 0);
        al_draw_filled_rectangle(DISPLAY_WIDTH/2 -250 , DISPLAY_HEIGHT/2 - 300 , DISPLAY_WIDTH/2 +250 ,DISPLAY_HEIGHT/2 + 300,al_map_rgb(180, 135, 65));
        al_draw_bitmap(Pic.level1,DISPLAY_WIDTH/2 -240, DISPLAY_HEIGHT/2 - 225 , 0);
        al_draw_bitmap(Pic.level2,DISPLAY_WIDTH/2 -240, DISPLAY_HEIGHT/2 - 25 , 0);
        al_draw_bitmap(Pic.level3,DISPLAY_WIDTH/2 -240, DISPLAY_HEIGHT/2 + 175, 0);
        al_draw_bitmap(Pic.contiune,30, 20, 0);

        for( i=0 ; i<3 ; i++)
        {
            snprintf(ScoreText[i], sizeof(ScoreText), "%d", highestScore[i]);
            al_draw_text(Font.fontBig, al_map_rgb(240, 240, 240), DISPLAY_WIDTH/2 -100 , DISPLAY_HEIGHT/2 - 223 +200*i, ALLEGRO_ALIGN_LEFT,ScoreText[i]);
        }
         

        al_flip_display();    
    }

       

}