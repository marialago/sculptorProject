#include "Sculptor.h"
#include <iostream>


//CONSTRUTOR
Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    //inicializando os instâncias do obj
    nx = _nx;
    ny = _ny;
    nz = _nz;
    r = 0;
    g = 0;
    b = 0;
    a = 0;

    //alocando memória para o ponteiro para voxel
    v  = new Voxel** [nx];
    for (unsigned int i=0; i<nx; i++)
    {
        v[i] = new Voxel*[ny];
        for (unsigned int j=0; j<ny; j++)
        {
            v[i][j] = new Voxel[nz];
        }
    }
    matrizIgualZero(v);
}

//DESTRUTOR
Sculptor::~Sculptor()
{
    for(unsigned int i=0; i<nx; i++)
    {
        for(unsigned int j=0; j<ny; j++)
        {
           delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v;
}

//FUNÇÃO AUXILIAR PARA INICIALIZAR A MATRIZ COM 0 PARA isOn
void Sculptor::matrizIgualZero(Voxel ***_v)
{
    for(unsigned int i=0; i<nx; i++)
    {
        for(unsigned int j=0; j<ny; j++)
        {
            for(unsigned int k=0; k<nz; k++)
            {
                v[i][j][k].isOn = 0;
                v[i][j][k].r = 0;
                v[i][j][k].g = 0;
                v[i][j][k].b = 0;
                v[i][j][k].a = 0;
            }
        }
    }
}

void Sculptor::putVoxel(int x, int y, int z)
{
    //VERIFICAR SE OS VALORES DO PONTO SÃO VÁLIDOS
    verificaPonto(x, nx);
    verificaPonto(y, ny);
    verificaPonto(z, nz);

    //ESCREVER O VALOR NA POSIÇÃO E CORES.
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].isOn = true;

}

//FUNÇÃO AUXILIAR PARA VERIFICAR SE O PONTO ESTÁ DENTRO DO TAMNHO DA MATRIZ
void Sculptor::verificaPonto(int &p, int np)
{
    if(p > np){
        p = np-1;
    }else if(p < 0)
    {
        p=0;
    }else
    {
        p = p-1;
    }
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    verificaPonto(x, nx);
    verificaPonto(y, ny);
    verificaPonto(z, nz);
    v[x][y][z].isOn = false;
}
//void Sculptor::writeOFF(const char* filename);

void Sculptor::imprimeMatriz()
{
    for(unsigned int i=0; i<nx; i++)
    {
        for(unsigned int j=0; j<ny; j++)
        {
            for(unsigned int k=0; k<nz; k++)
            {
                std::cout<< v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << " " << v[i][j][k].isOn<< std::endl;
            }
            std::cout<<std::endl;
        }
    std::cout << std::endl;
    }
}
