#include "Tanque.h"
#include <allegro.h>
void Tanque::direccionamiento(int &direccion, int &pos_x, int &pos_y)
{

       if(key[KEY_LEFT]){
           direccion = direccion_bala = 0;
            activo = true;
        }
       else if(key[KEY_RIGHT]){
           direccion = direccion_bala = 1;
            activo = true;
        }
       else if(key[KEY_UP]){
           direccion = direccion_bala = 2;
            activo = true;
        }
       else if(key[KEY_DOWN]){
           direccion =direccion_bala =  3;
            activo = true;
        }
           if(direccion == 0 && activo == true){
                 if((mapa[pos_y/30][(pos_x-30)/30] != 'M') && (mapa[pos_y/30][(pos_x-30)/30] != 'F')){
                   pos_x -= 30;
                   activo = false;
                }
                else
                    direccion = 0;
           }

           if(direccion == 1 && activo == true){
                if((mapa[pos_y/30][(pos_x+30)/30] != 'M')&&(mapa[pos_y/30][(pos_x+30)/30] != 'F')){
                   pos_x += 30;
                    activo = false;
                }
                else
                    direccion = 1;
           }

           if(direccion == 2 && activo == true){
                if((mapa[(pos_y-30)/30][pos_x/30] != 'M')&&(mapa[(pos_y-30)/30][pos_x/30] != 'F')){
                  pos_y -= 30;
                  activo = false;
                }
                else
                    direccion = 2;
           }

           if(direccion == 3 && activo == true){
                if((mapa[(pos_y+30)/30][pos_x/30] != 'M')&&(mapa[(pos_y+30)/30][pos_x/30] != 'F') ){
                   pos_y += 30;
                   activo = false;
                }
                else
                    direccion = 3;
           }
}

void Tanque::CrearSprite()
{
    blit(tanquebmp, tanque, direccion*33,0,0,0,33,33);
    draw_sprite(buffer, tanque, pos_x, pos_y);
}
