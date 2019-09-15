
#include "miniwin.h"
#include <iostream>
using namespace miniwin;


const int RADIO = 10;

struct Pelota {
   float x, y;
   float dx, dy;
   Color c;
};

/* "Color" es un tipo enumerado definido en Miniwin.h.
Una variable de tipo Color puede tomar los siguientes valores:
NEGRO, ROJO, VERDE, AZUL, AMARILLO, MAGENTA, CYAN, BLANCO

*/

void pinta_pelota(const Pelota& P) {
   color(P.c);
   circulo_lleno(P.x, P.y, RADIO);

}

void mueve_pelota(Pelota& P) {
   const float factor = 0.95;
   P.x += P.dx;
   P.y += P.dy;
   if (P.x > vancho() - RADIO) {
      P.dx = -P.dx * factor;
      P.x = vancho() - RADIO;
   }
    else if (P.x < RADIO) {
      P.dx = -P.dx * factor;
      P.x = RADIO;
   }
    else if (P.y > valto() - RADIO) {
      P.dy = -P.dy * factor;
      P.y = valto() - RADIO;
   }
    else if (P.y < RADIO) {
      P.dy = -P.dy * factor;
      P.y = RADIO;
   }
   
   // si queremos simular gravedad, incrementar dy
  // P.dy += 0.1;
}

int main() {
   int X = 800, Y=600; 
    
   vredimensiona(X, Y);
   Pelota A = { X/2, Y/2, 4.0, 4.0, VERDE};
   Pelota B = { X/2, Y/2, -4.0, -4.0, ROJO};

   while (tecla() != ESCAPE) {
    borra();
    mueve_pelota(A);
    mueve_pelota(B);
    pinta_pelota(A);
    pinta_pelota(B);
    refresca();
    espera(15);
   }
   vcierra();
   return 0;
}
