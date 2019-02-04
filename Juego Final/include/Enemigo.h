#ifndef ENEMIGO_H
#define ENEMIGO_H


#include <cstdlib>
#include <allegro.h>
#include <Sprite.h>
#include <Juego.h>




class Enemigo: public Sprite, public Juego
{
    public:
        Enemigo();
        Enemigo(int, int);
        ~Enemigo();
        void CrearSprite();
        void Colision();
        void movimientoEnemigo();



    private:
        BITMAP *enemigobmp;
        BITMAP *enemigo;
        //pos enemigo
        int direccion_enemigo = 0;
        int pos_x_e = 30*14;
        int pos_y_e = 30*15;
        int anterior_pos_x_e;
        int anterior_pos_y_e;
};


#endif // ENEMIGO_H
