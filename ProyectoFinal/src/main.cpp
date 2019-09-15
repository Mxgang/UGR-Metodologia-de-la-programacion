

#include "miniwin.h"
#include <ctime>
#include <iostream>
#include "particula.h"
#include "definiciones.h"
#include "ConjuntoParticulas.h"
#include "simulador.h"

using namespace miniwin;
using namespace std;

void pintaNube(ConjuntoParticulas & miConjunto) {
    int N = miConjunto.getUtiles();
    Particula p;
    for (int i = 0; i < N; i++) {
        p = miConjunto.ObtieneParticula(i);
        color(p.getColor());
        circulo_lleno(p.getX(), p.getY(), RADIO);
    }

}

int main() {
    srand(time(0));

    int ancho = 800;
    int alto = 600;

    int opcion;

    cout << "\n  Opcion a probar: ";
    cin >> opcion;

    switch (opcion) {

        case 1:
        {
            cout << "\n** Prueba sobrecarga de operadores **" << endl;
            //vredimensiona(100, 100);
            ConjuntoParticulas a1;
            ConjuntoParticulas b1(4,true);

            cout << b1;

            Particula x;
            a1.AgregaParticula(x);
            x.Mover(ancho, alto);
            a1.AgregaParticula(x);
            cout << a1;

            b1.Mover(ancho, alto);
            a1 = a1 + b1;
            cout << a1;
            ConjuntoParticulas cc = a1 + b1;
            ConjuntoParticulas xx(cc);
            cout << xx;
            cout << endl;

            vcierra();

            break;
        }

        case 2:
        {
            cout << "\n** Prueba Conjunto Particulas ** " << endl;
            int NRO = 20;
            vredimensiona(ancho, alto);
            ConjuntoParticulas rojas(NRO,true);
            ConjuntoParticulas verdes(NRO,true);
            ConjuntoParticulas blancas;
            Particula p;


            for (int i = 0; i < NRO; i++) {
                p = rojas.ObtieneParticula(i);
                p.setColor(ROJO);
                rojas.ReemplazaParticula(i, p);

                p = verdes.ObtieneParticula(i);
                p.setColor(VERDE);
                verdes.ReemplazaParticula(i, p);
            }

            ConjuntoParticulas aux;
            for (int i = 0; i < 200; i++) {
                rojas.Mover(ancho, alto);
                verdes.Mover(ancho, alto);
                blancas.Mover(ancho, alto);
                aux = rojas + verdes + blancas;

                borra();
                pintaNube(aux);

                if (i % 10 == 0) {
                    Particula p;
                    p.setColor(BLANCO);
                    blancas.AgregaParticula(p);
                    rojas.BorraParticula(rand() % rojas.getUtiles());
                    verdes.BorraParticula(rand() % verdes.getUtiles());

                }

                refresca();
                espera(35);
            }
            vcierra();

            break;
        }

        case 3:
        {
            cout << "\n**************  Probando Simulador ****************\n";
            ConjuntoParticulas base(30,true);
            ConjuntoParticulas otro(10,true);
            ConjuntoParticulas aux;
            int contador = 0;

            Simulador game(base, otro, ancho, alto);

            while (contador < 500) {
                game.Step();
                game.Pintar();
                contador++;
            }
            break;
        }

    };

    return 0;
}
