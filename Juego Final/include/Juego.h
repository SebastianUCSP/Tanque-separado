#ifndef JUEGO_H
#define JUEGO_H

#include <allegro.h>
#include <iostream>

BITMAP *buffer;
BITMAP *muertebmp;
BITMAP *tanquebmp;
BITMAP *tanque;
BITMAP *ladrillo;
BITMAP *bloque_falso;
BITMAP *trofeo;
BITMAP *bala;

//pos inicial tanque
int direccion = 0; // tanque y disparo
int direccion_bala;
int pos_x = 30*14; // enemigo tanke bala
int pos_y = 30*15; // enemigo tanque bala

int anterior_pos_x; // enemigo
int anterior_pos_y; // enemigo

//puntaje
int score_1 = 0; // enemigo
int score_2 = 0;
int score_3 = 0;

//estado del jugador
bool vida = true; // enemigo

//mapa
int const ancho = 21; // juego
int const alto = 31; // juego

//bala

int pos_b_x; // enemigo  y bala
int pos_b_y; // enemigo  y bala
int origen_b_x;  // bala
int origen_b_y;  // bala

class Juego{

public:
    static Juego *getInstancia(){
            if(instancia == 0)
                instancia = new Juego();
            return instancia;
        }
    void crearMapa();
    bool finJuego();
    void imprimirSprite();
    void Inicializar();

protected:
    char mapa[ancho][alto]={
       "MMMMMMMMMMMMMMMMMMMMMMMMMMMMM",
       "M            | |            M",
       "M                           M",
       "M      M    FFFFF    M      M",
       "M      M             M      M",
       "M      M             M      M",
       "M|     M             M     |M",
       "M    MMMMM         MMMMM    M",
       "M             M             M",
       "M             M             M",
       "M      |      M      |      M",
       "M         MMMMMMMMM         M",
       "M             M             M",
       "M        |    M    |        M",
       "MMMMMM        M        MMMMMM",
       "M    F                 F    M",
       "M    F                 F    M",
       "M    F      MMMMM      F    M",
       "M                           M",
       "M             o             M",
       "MMMMMMMMMMMMMMMMMMMMMMMMMMMMM",
    };
    private:
        static Juego *instancia;
};


#endif // JUEGO_H
