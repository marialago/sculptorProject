#include <iostream>
#include "Sculptor.h"

int main()
{
    Sculptor m(2, 2, 2);
    m.putVoxel(1, 1, 1);
    m.putVoxel(2, 2, 2);
    m.putVoxel(1, 1, 2);
    m.imprimeMatriz();

    m.~Sculptor();

    return 0;
}
