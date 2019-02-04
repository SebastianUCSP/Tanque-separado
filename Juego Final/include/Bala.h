#ifndef BALA_H
#define BALA_H

#include <iostream>
#include <cstdlib>
#include <allegro.h>
#include <Sprite.h>
#include <Enemigo.h>
#include <Juego.h>
#include <Tanque.h>



class Bala: public  Sprite, public Juego{
    public:
        void disparo(int &, int&,int );
        void CrearSprite();

};

#endif // BALA_H
