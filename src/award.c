#include "header.h"
void award(struct ResourcePic Pic)
{
    al_draw_bitmap(Pic.award,0, 0, 0);
    al_flip_display();
    al_rest(1);
}