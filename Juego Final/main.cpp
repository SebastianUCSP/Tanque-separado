#include <iostream>
#include <cstdlib>
#include <allegro.h>
#include <fstream>
#include <algorithm>
#include <Sprite.h>
#include <Enemigo.h>
#include <Juego.h>
#include <Tanque.h>
#include <Bala.h>


using namespace std;

template<typename T>
void quicksort(T *arr,int primero, int ultimo,bool (*pf)(T,T))
{
    int i=primero,j = ultimo;
    T auxi;
    T pivote  = arr[(primero + ultimo)/2];
    do
    {
        while((*pf)(pivote,arr[i]))i++;
            while((*pf)(arr[j],pivote))j--;
                if(i<=j)
                {
                    auxi = arr[i];
                    arr[i] = arr[j],
                    arr[j]=auxi;
                    i++;
                    j--;
                }
    }
        while(i<=j);
            if(primero<j)
                quicksort(arr,primero,j,pf);
            if(ultimo>i)
                quicksort(arr,i,ultimo,pf);
}

bool ascendente(char *a, char *b)
{
return *a > *b;
}

bool descendente(char *a, char *b)
{
return *a < *b;
}

void mostrar(int arr[], int len){
for(int i=0; i<len; i++)
        cout<< len-i << "º " << arr[i] << endl;
}

int main()
{

    allegro_init();
	install_keyboard();
	install_mouse();

	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 880, 630, 0, 0);


	Juego *configuracion = Juego::getInstancia();
    configuracion->Inicializar();

    Enemigo *A = new Enemigo(30*13, 30*5);
    Enemigo *B = new Enemigo(30*14, 30*5);
    Enemigo *C = new Enemigo(30*15, 30*5);
    Enemigo *D = new Enemigo(30*16, 30*5);
    Enemigo *E = new Enemigo;
    Enemigo *F = new Enemigo;
    Enemigo *G = new Enemigo;
    Enemigo *H = new Enemigo;
    Enemigo *I = new Enemigo;
    Enemigo *J = new Enemigo;


    Tanque *tan = new Tanque;
    Bala *balin = new Bala;
    bool nivel1 = true;
    bool nivel2 = false;


	//define variables del menu
	BITMAP *buffer2 = create_bitmap(880, 630);
	BITMAP *fondo1;
	BITMAP *fondo2;
	BITMAP *fondo3;
	BITMAP *cursor;

	// inicializa las variables del menu
	fondo1 = load_bitmap("Menu1.bmp",NULL);
	fondo2 = load_bitmap("Menu2.bmp",NULL);
	fondo3 = load_bitmap("Menu3.bmp",NULL);
	cursor = load_bitmap("cursor.bmp",NULL);

    bool salida = false;

	while ( !salida )
	{
         // posicion del boton
         if ( mouse_x > 377 && mouse_x < 530 &&
              mouse_y > 387 && mouse_y < 428)
         {
            blit(fondo2, buffer2, 0, 0, 0, 0, 880, 630);

            // se ha pulsado el boton del raton
            if ( mouse_b & 1 )
            {
                salida=true;
            }
         }

         else if ( mouse_x > 377 && mouse_x < 530 &&
              mouse_y > 430 && mouse_y < 471)
         {
            blit(fondo3, buffer2, 0, 0, 0, 0, 880, 630);

            // se ha pulsado el boton del raton
            if ( mouse_b & 1 )
            {
                allegro_exit();
            }
         }else{
            blit(fondo1, buffer2, 0, 0, 0, 0, 880, 630);
         }


         // pinta el cursor
         masked_blit(cursor, buffer2, 0, 0, mouse_x, mouse_y, 13,22);

         // se muestra todo por pantalla
	     blit(buffer2, screen, 0, 0, 0, 0, 880, 630);

    }
    // libera memoria quitando las imagenes

	clear(buffer2);
	clear(fondo1);
	clear(fondo2);
	clear(fondo3);
	clear(cursor);

    while(!key[KEY_ESC] && configuracion->finJuego() && vida && nivel1){

       anterior_pos_x = pos_x;
       anterior_pos_y = pos_y;

       tan->direccionamiento(direccion, pos_x, pos_y);
       balin->disparo(pos_b_x, pos_b_y,direccion_bala);


       clear(buffer);
	   configuracion->crearMapa();
	   tan->CrearSprite();
	   balin->CrearSprite();


	   A->movimientoEnemigo();
	   B->movimientoEnemigo();
	   C->movimientoEnemigo();
	   D->movimientoEnemigo();

	   configuracion->imprimirSprite();
	   rest(20);

	   clear(tanque);
       configuracion->imprimirSprite();
       rest(70);

       if(score_1 == 40){
        nivel1 = false;
       }

       ofstream guardar_puntaje;
       guardar_puntaje.open("Puntuacion_obtenida_1.txt");

       guardar_puntaje << "Tu puntuacion fue:" << score_1;
       guardar_puntaje.close();
    }

    if(nivel1 == false)
        nivel2 = true;

    while(!key[KEY_ESC] && configuracion->finJuego() && vida && nivel2){

       anterior_pos_x = pos_x;
       anterior_pos_y = pos_y;

       tan->direccionamiento(direccion, pos_x, pos_y);
       balin->disparo(pos_b_x, pos_b_y,direccion_bala);


       clear(buffer);
	   configuracion->crearMapa();
	   tan->CrearSprite();
	   balin->CrearSprite();


	   E->movimientoEnemigo();
	   F->movimientoEnemigo();
	   G->movimientoEnemigo();
	   H->movimientoEnemigo();
	   I->movimientoEnemigo();
	   J->movimientoEnemigo();

	   configuracion->imprimirSprite();
	   rest(20);

	   clear(tanque);
       configuracion->imprimirSprite();
       rest(60);

       score_2 = score_1-40;

       if(score_1 == 100){
        nivel1 = false;
       }

       ofstream guardar_puntaje;
       guardar_puntaje.open("Puntuacion_obtenida_2.txt");

       guardar_puntaje << "Tu puntuacion fue:" << score_2;
       guardar_puntaje.close();
    }

    allegro_exit();

    char *nombres[4] = {"rodrigo","sebastian","yhon"};
    int  puntajes[4] = {60,40,30};

    string nombre;
    cout<<"\t\t*   GAME OVER  *"<<endl;
    cout<<"\t\t***"<<endl;
    cout<<"\t\t*INGRESE SU NOMBRE  *"<<endl;
    cout<<"\t\t***"<<endl;
    cout<<">>";
    cin>>nombre;

    cout << "Jugadores anteriores: " << endl;
    quicksort<char*>(nombres,0,2,descendente);
    cout<<endl<<endl;
    cout << "descendente :" << endl;
    for(int i=0; i<3; i++)
        cout<< nombres[i] << endl;

    quicksort<char*>(nombres,0,2,ascendente);
    cout<<endl<<endl;
    cout << "ascendente :" << endl;
    for(int i=0; i<3; i++)
        cout<< nombres[i] << endl;

    cout << endl;

    cout << "Puntuaciones mas altas: " << endl;

    sort(puntajes,puntajes+3);
    mostrar(puntajes, 3);

    cout << endl;

    cout << "Tu puntuacion: " << endl;
    cout << nombre << " " << score_1;



	return 0;
}
END_OF_MAIN();
