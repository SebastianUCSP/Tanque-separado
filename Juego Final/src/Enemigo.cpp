#include "Enemigo.h"
#include <allegro.h>
Enemigo::Enemigo()
{
    pos_x_e = 30*14;
    pos_y_e = 30*8;
    direccion_enemigo = rand()%4;
    enemigo = create_bitmap(30, 30);
    enemigobmp = load_bitmap("enemigo1.bmp",NULL);
}


Enemigo::Enemigo(int x, int y)
{
    pos_x_e = x;
    pos_y_e = y;
    direccion_enemigo = rand()%4;
    enemigo = create_bitmap(30, 30);
    enemigobmp = load_bitmap("enemigo2.bmp",NULL);
}
Enemigo::~Enemigo(){
    delete enemigo;
}


void Enemigo::CrearSprite()
{
    blit(enemigobmp, enemigo, 0,0,0,0,30,30);
    draw_sprite(buffer, enemigo, pos_x_e, pos_y_e);
}


void Enemigo::Colision()
{
    if((pos_y == pos_y_e && pos_x == pos_x_e) || (pos_y_e == anterior_pos_y && pos_x_e == anterior_pos_x)){
        for(int i = 0; i <= 5; i++){
            clear(tanque);
            clear(buffer);
            crearMapa();

            blit(muertebmp, tanque, i*33,0,0,0,33,33);
            draw_sprite(buffer, tanque,pos_x, pos_y);

            imprimirSprite();
            rest(80);
            vida = false;
        }
    }

    if((pos_b_y == pos_y_e && pos_b_x == pos_x_e)){
        pos_x_e = 30*50;
        pos_y_e = 30*50;
        score_1 += 10;
    }

    if(pos_x_e == 30*14 && pos_y_e == 30*19){
        vida = false;
    }
}

void Enemigo::movimientoEnemigo()
{
   CrearSprite();
   Colision();

   if(mapa[pos_y_e/30][pos_x_e/30] == '|')
    {
           direccion_enemigo = rand()%4;
    }
   if(direccion_enemigo == 0)
    {
       if((mapa[pos_y_e/30][(pos_x_e-30)/30] != 'M' ) && (mapa[pos_y_e/30][(pos_x_e-30)/30] != 'F' ))
       {
           pos_x_e -= 30;
       }
       else direccion_enemigo = rand()%4;
   }
   if(direccion_enemigo == 1)
   {
       if((mapa[pos_y_e/30][(pos_x_e+30)/30] != 'M') && (mapa[pos_y_e/30][(pos_x_e+30)/30] != 'F' ))
       {
           pos_x_e += 30;
       }
       else direccion_enemigo = rand()%4;
   }
   if(direccion_enemigo == 2)
   {
       if((mapa[(pos_y_e-30)/30][pos_x_e/30] != 'M')&& (mapa[(pos_y_e-30)/30][(pos_x_e)/30] != 'F' ))
       {
           pos_y_e -= 30;
       }
       else direccion_enemigo = rand()%4;
   }
   if(direccion_enemigo == 3)
   {
       if((mapa[(pos_y_e+30)/30][pos_x_e/30] != 'M')&&(mapa[(pos_y_e+30)/30][(pos_x_e)/30] != 'F' ))
       {
           pos_y_e += 30;
       }
       else direccion_enemigo = rand()%4;
   }
}
