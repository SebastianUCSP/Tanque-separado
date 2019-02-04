#include "Juego.h"
#include <allegro.h>
void Juego::crearMapa()
{
   for(int fila = 0; fila < ancho; fila++)
    {
        for(int columna = 0; columna < alto; columna++)
        {
            if(mapa[fila][columna] == 'M')
            {
                draw_sprite(buffer, ladrillo, columna*30, fila*30);
            }
             else if(mapa[fila][columna] == 'F')
            {
                draw_sprite(buffer, bloque_falso, columna*30, fila*30);
            }
            else if(mapa[fila][columna] == 'o')
            {
                draw_sprite(buffer, trofeo, columna*30, fila*30);
            }
        }
   }
}


bool Juego::finJuego()
{
   for(int fila = 0; fila < ancho; fila++)
    {
        for(int columna = 0; columna < alto; columna++)
        {
            if(mapa[fila][columna] == 'o')
            {
                return true;
            }
        }
   }
   return false;
}


void Juego::imprimirSprite()
{
   blit(buffer, screen, 0,0,0,0,880,630);
}

void Juego::Inicializar()
{
    buffer = create_bitmap(880, 630);
    ladrillo = load_bitmap("bloque.bmp",NULL);
    tanquebmp = load_bitmap("tanque.bmp",NULL);
    bloque_falso = load_bitmap("bloque_falso.bmp",NULL);
    tanque = create_bitmap(33, 33);
    trofeo = load_bitmap("trofeo.bmp",NULL);
    bala = load_bitmap("bala.bmp",NULL);
    muertebmp = load_bitmap("muerte.bmp", NULL);

}
