#ifndef TANQUE_H
#define TANQUE_H

#include <allegro.h>
#include <Sprite.h>
#include <Enemigo.h>
#include <Juego.h>
#include <Bala.h>



class Tanque: public Sprite, public Juego
{
    public:
        bool activo;
        void CrearSprite();
        void direccionamiento(int &, int &, int &);
};

#endif // TANQUE_H
