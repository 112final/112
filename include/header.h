#ifndef HEADER_H//.h檔中一定要使用flag避免各個檔案間重複宣告
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>//new 1
#include <allegro5/allegro_image.h>
#include <time.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define DISPLAY_WIDTH   1280
#define DISPLAY_HEIGHT  700
#define RIGHT_BOUNDARY  940
#define LEFT_BOUNDARY  290
#define UPPER_BOUNDARY  50
#define LOWER_BOUNDARY  650
#define MOVEMENT_STEP  50



struct bomb
{
    int type_1;
    int type_2;
    int type_3;
};

struct barrier
{
    int initial_x;
    int initial_y;
};

struct ResourcePic
{
    ALLEGRO_BITMAP *map ;
    ALLEGRO_BITMAP *playerPic ;
    ALLEGRO_BITMAP *bomp ;
    ALLEGRO_BITMAP *bomp2 ;
    ALLEGRO_BITMAP *bomp3 ;
    ALLEGRO_BITMAP *bitmapexplosion ;
    ALLEGRO_BITMAP *bitmapstone ;
    ALLEGRO_BITMAP *redfish ;
    ALLEGRO_BITMAP *yellowfish ;
    ALLEGRO_BITMAP *bluefish ;
    ALLEGRO_BITMAP *grass ;
    ALLEGRO_BITMAP *bitmap_right ;
    ALLEGRO_BITMAP *bitmap_left ;
    ALLEGRO_BITMAP *bitmap_up ;
    ALLEGRO_BITMAP *bitmap_down ;
    ALLEGRO_BITMAP *back ;
    ALLEGRO_BITMAP *contiune ;
    ALLEGRO_BITMAP *exit ;
    ALLEGRO_BITMAP *background ;
    ALLEGRO_BITMAP *restartbutton ;
    ALLEGRO_BITMAP *level1 ;
    ALLEGRO_BITMAP *level2 ;
    ALLEGRO_BITMAP *level3 ;
    ALLEGRO_BITMAP *level4 ;
    ALLEGRO_BITMAP *historybutton ;
    ALLEGRO_BITMAP *question ;
    ALLEGRO_BITMAP *GameInstructions;
    ALLEGRO_BITMAP *BombType;
    ALLEGRO_BITMAP *award;
    ALLEGRO_BITMAP *box;


};

struct ResourceAudio
{
    ALLEGRO_SAMPLE* start;
    ALLEGRO_SAMPLE* button;
    ALLEGRO_SAMPLE* boom;
    ALLEGRO_SAMPLE* flying;
    ALLEGRO_SAMPLE* background;

};

struct ResourceFont
{
    ALLEGRO_FONT *fontBig;
    ALLEGRO_FONT *fontSmall;


};

//function
void initial_src();//new4
void initial_array(struct barrier [144]);
int menu_first(ALLEGRO_DISPLAY*,ALLEGRO_EVENT_QUEUE *,struct ResourcePic ,struct ResourceAudio);//new2
int menu_second(ALLEGRO_DISPLAY*,ALLEGRO_EVENT_QUEUE *,struct ResourcePic,struct ResourceAudio);//new3
int endgame(ALLEGRO_DISPLAY*,ALLEGRO_EVENT_QUEUE *,struct ResourcePic ,struct ResourceAudio,int,int*,int,int*,struct ResourceFont );
int returnfirstmenu(ALLEGRO_EVENT_QUEUE *,ALLEGRO_DISPLAY *,int*,int*,struct ResourcePic,struct ResourceAudio);
void player(ALLEGRO_DISPLAY*,ALLEGRO_EVENT_QUEUE *,int stageNumber,struct ResourcePic,struct ResourceAudio,struct ResourceFont,int*,int*);
void moveplayer(ALLEGRO_EVENT_QUEUE *,int * ,int *,int *,int *,int*,int*,int[3],struct ResourceAudio);
void stagefile(int [40][40], struct barrier[144] ,int stageNumber ,int [3],struct ResourcePic* Pic);
void stageprint(int [40][40],ALLEGRO_BITMAP *,ALLEGRO_BITMAP *,ALLEGRO_BITMAP *,ALLEGRO_BITMAP *,ALLEGRO_BITMAP *);
void renew_bullet(int *,int*,int*);
void renew_arrow(int *,int*,int*,int*,int*,int*);
void detectbarrier(struct barrier [144],int *,int *,int*,int*,ALLEGRO_BITMAP *,int [40][40],int[3],struct ResourceAudio);
void detectexplosion(struct barrier*,int [40][40],int);
void fresharray(int [40][40],struct barrier [144]);
void DetonateBomb(ALLEGRO_EVENT_QUEUE *,int *,int *,int*,int*,ALLEGRO_BITMAP *,int [40][40],int[3],struct ResourceAudio);
int StageChanged(int [40][40]);
void displayLoadingScreen(ALLEGRO_FONT *font , struct ResourcePic ,int);
void ScoreDisplay(ALLEGRO_FONT *font,int,int*,int,int,int);
void LevelDisplay(ALLEGRO_FONT *font,int);
void BombTypeDisplay(ALLEGRO_FONT *font,int [3],struct ResourcePic);
void game_instruction(ALLEGRO_DISPLAY*,ALLEGRO_EVENT_QUEUE *,struct ResourcePic ,struct ResourceAudio ) ;
void historygame(ALLEGRO_DISPLAY*,ALLEGRO_EVENT_QUEUE *,struct ResourcePic ,struct ResourceAudio,int*,struct ResourceFont,int *);

void ScoreFileLoad (int* ,int* );
void ScoreFileSave (int* ,int* );
void ScoreFileClear (int* );

//特殊關卡設置
void door(int ,int*,int*,int*);
void award(struct ResourcePic);

//炸彈種類
void cross(int *,int *,ALLEGRO_BITMAP* ,int*,int [40][40] );
void bigcross(int *,int *,ALLEGRO_BITMAP* ,int*,int [40][40]);
void square(int *,int *,ALLEGRO_BITMAP* ,int* ,int [40][40]);

void resourceInitPic(struct ResourcePic* );       /* Initial resources */
void resourceLoadPic(struct ResourcePic* );
void resourceDestoryPic(struct ResourcePic* ); 
void resourceInitAudio(struct ResourceAudio* );
void resourceLoadAudio(struct ResourceAudio* );
void resourceDestoryAudio(struct ResourceAudio* );
void resourceInitFont(struct ResourceFont* );
void resourceLoadFont(struct ResourceFont* );
void resourceDestoryFont(struct ResourceFont* );


#endif