#include "Bala.h"

void Bala::disparo(int &pos_b_x, int &pos_b_y,int direccion)
{
    origen_b_x = pos_x;
    origen_b_y = pos_y;

    if(direccion == 0){
        if(key[KEY_SPACE]){
            pos_b_x = origen_b_x;
            pos_b_y = origen_b_y;
        }
        pos_b_x -= 30;
        if(mapa[pos_b_y/30][pos_b_x/30] == 'M'  || mapa[pos_b_y/30][pos_b_x/30] == 'F' )
            pos_b_x = 30*100;
    }

    if(direccion == 1){
        if(key[KEY_SPACE]){
            pos_b_x = origen_b_x;
            pos_b_y = origen_b_y;
        }
        pos_b_x += 30;
        if(mapa[pos_b_y/30][pos_b_x/30] == 'M'  ||  mapa[pos_b_y/30][pos_b_x/30] == 'F'  ){
            pos_b_x = 30*100;
    }
    }
    if(direccion == 2){
        if(key[KEY_SPACE]){
            pos_b_x = origen_b_x;
            pos_b_y = origen_b_y;
        }
        pos_b_y -= 30;
        if(mapa[pos_b_y/30][pos_b_x/30] == 'M'   ||  mapa[pos_b_y/30][pos_b_x/30] == 'F'){
            pos_b_x = 30*100;
      }
    }

    if(direccion == 3){
        if(key[KEY_SPACE]){
            pos_b_x = origen_b_x;
            pos_b_y = origen_b_y;
        }
        pos_b_y += 30;
        if(mapa[pos_b_y/30][pos_b_x/30] == 'M'  ||  mapa[pos_b_y/30][pos_b_x/30] == 'F'){
            pos_b_x = 30*100;
       }
    }
}

void Bala::CrearSprite()
{
    draw_sprite(buffer, bala, pos_b_x, pos_b_y);
}

Juego *Juego::instancia = 0;
