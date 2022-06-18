#include <iostream>
#include "Sculptor.h"

int main()
{
    Sculptor bola(100, 100, 100);

    // RODAS
    //bola.setColor(0, 0, 0, 1);
    /*bola.putEllipsoid(10, 50, 50, 5, 20, 20);
    bola.putEllipsoid(85, 50, 50, 5, 20, 20);

    // CORPO
    bola.setColor(0.5, 0.5, 0.5, 1);
    bola.putBox(14, 80, 40, 75, 20, 80);
    bola.cutBox(14, 80, 40, 75, 20, 25);*/

    // OLHOS
    bola.setColor(1, 1, 1, 1);
    //bola.cutSphere(37, 57, 80, 7);
    //bola.cutSphere(57, 57, 80, 7);
    bola.putSphere(37, 57, 80, 7);
    bola.putSphere(57, 57, 80, 7);
    /*bola.setColor(0, 0, 0, 1);
    bola.cutEllipsoid(37, 57, 85, 4, 4, 2);
    bola.cutEllipsoid(57, 57, 85, 4, 4, 2);
    bola.putEllipsoid(37, 57, 85, 4, 4, 2);
    bola.putEllipsoid(57, 57, 85, 4, 4, 2);*/
    bola.writeOFF("bola.off");
    bola.~Sculptor();

    return 0;
}
