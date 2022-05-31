#include "Sculptor.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

//CONSTRUTOR
Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    //inicializando os instancias do obj
    nx = _nx;
    ny = _ny;
    nz = _nz;
    r = 0;
    g = 0;
    b = 0;
    a = 0;

    //alocando memoria para o ponteiro para voxel
    v  = new Voxel** [nx];
    for (unsigned int i=0; i<nx; i++)
    {
        v[i] = new Voxel*[ny];
        for (unsigned int j=0; j<ny; j++)
        {
            v[i][j] = new Voxel[nz];
        }
    }

    //INICIA A MATRIZ COM 0 PARA AS PROPRIEDADES DE CADA ELEMENTO
    for(unsigned int i=0; i<nx; i++)
    {
        for(unsigned int j=0; j<ny; j++)
        {
            for(unsigned int k=0; k<nz; k++)
            {
                v[i][j][k].isOn = 0;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
            }
        }
    }
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

void Sculptor::putVoxel(int x, int y, int z)
{
    //VERIFICAR SE OS VALORES DO x PONTO SAO VALIDOS
    if(x > nx){
        x = nx-1;
    }else if(x < 0)
    {
        x=0;
    }else
    {
        x = x-1;
    }

    //VERIFICAR SE OS VALORES DO y PONTO SAO VALIDOS
    if(y > ny){
        y = ny-1;
    }else if(y < 0)
    {
        y=0;
    }else
    {
        y = y-1;
    }

    //VERIFICAR SE OS VALORES DO z PONTO SAO VALIDOS
    if(z > nz){
        z = nz-1;
    }else if(z < 0)
    {
        z=0;
    }else
    {
        z = z-1;
    }

    //ESCREVER O VALOR NA POSIÇÃO E CORES.
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].isOn = true;

}

void Sculptor::cutVoxel(int x, int y, int z)
{
    //VERIFICAR SE OS VALORES DO x PONTO SAO VALIDOS
    if(x > nx){
        x = nx-1;
    }else if(x < 0)
    {
        x=0;
    }else
    {
        x = x-1;
    }

    //VERIFICAR SE OS VALORES DO y PONTO SAO VALIDOS
    if(y > ny){
        y = ny-1;
    }else if(y < 0)
    {
        y=0;
    }else
    {
        y = y-1;
    }

    //VERIFICAR SE OS VALORES DO z PONTO SAO VALIDOS
    if(z > nz){
        z = nz-1;
    }else if(z < 0)
    {
        z=0;
    }else
    {
        z = z-1;
    }
    v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    int aux;
    //VERIFICA OS INTERVALOS DE X
    if(x0 <= 0){
        x0 = 0;
    }

    if(x1 >= nx)
    {
        x1 = nx-1;
    }

    if(x0 > x1)
    {
        aux = x1;
        x1 = x0;
        x0 = aux;
    }else{
        x0 = x0;
        x1 = x1;
    }

    //VERIFICA OS INTERVALOS DE Y
    if(y0 <= 0){
        y0 = 0;
    }

    if(y1 >= ny)
    {
        y1 = ny-1;
    }

    if(y0 > y1)
    {
        aux = y1;
        y1 = y0;
        y0 = aux;
    }else{
        y0 = y0;
        y1 = y1;
    }

    //VERIFICA OS INTERVALOS DE Z
    if(z0 <= 0){
        z0 = 0;
    }

    if(z1 >= nz)
    {
        z1 = nz-1;
    }

    if(z0 > z1)
    {
        aux = z1;
        z1 = z0;
        z0 = aux;
    }else{
        z0 = z0;
        z1 = z1;
    }

    //ATIVA OS VOXELS NO INTERVALO DO BOX
    for(unsigned int i=x0; i<x1; i++)
    {
        for(unsigned int j=y0; j<y1; j++)
        {
            for(unsigned int k=z0; k<z1; k++)
            {
                v[i][j][k].isOn = 1;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
            }
        }
    }

}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    int aux;
    //VERIFICA OS INTERVALOS DE X
    if(x0 <= 0){
        x0 = 0;
    }

    if(x1 >= nx)
    {
        x1 = nx-1;
    }

    if(x0 > x1)
    {
        aux = x1;
        x1 = x0;
        x0 = aux;
    }else{
        x0 = x0;
        x1 = x1;
    }

    //VERIFICA OS INTERVALOS DE Y
    if(y0 <= 0){
        y0 = 0;
    }

    if(y1 >= ny)
    {
        y1 = ny-1;
    }

    if(y0 > y1)
    {
        aux = y1;
        y1 = y0;
        y0 = aux;
    }else{
        y0 = y0;
        y1 = y1;
    }

    //VERIFICA OS INTERVALOS DE Z
    if(z0 <= 0){
        z0 = 0;
    }

    if(z1 >= nz)
    {
        z1 = nz-1;
    }

    if(z0 > z1)
    {
        aux = z1;
        z1 = z0;
        z0 = aux;
    }else{
        z0 = z0;
        z1 = z1;
    }

    //ATIVA OS VOXELS NO INTERVALO DO BOX
    for(unsigned int i=x0; i<x1; i++)
    {
        for(unsigned int j=y0; j<y1; j++)
        {
            for(unsigned int k=z0; k<z1; k++)
            {
                v[i][j][k].isOn = 0;
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for (int i = -radius; i <= radius; i++)
            for (int j = -radius; j <= radius; j++)
                for (int k = -radius; k <= radius; k++)
                    if (((xcenter + i) < 0 || (xcenter + i) >= nx) || ((ycenter + j) < 0 || (ycenter + j) >= ny) || ((zcenter + k) < 0 || (zcenter + k) >= nz)) {
                    }
                    else {
                        if (i * i + j * j + k * k < radius * radius)
                            putVoxel(xcenter + i, ycenter + j, zcenter + k);
                    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for (int i = -radius; i <= radius; i++)
            for (int j = -radius; j <= radius; j++)
                for (int k = -radius; k <= radius; k++)
                    if (((xcenter + i) < 0 || (xcenter + i) >= nx) || ((ycenter + j) < 0 || (ycenter + j) >= ny) || ((zcenter + k) < 0 || (zcenter + k) >= nz)) {
                    }
                    else {
                        if (i * i + j * j + k * k < radius * radius)
                            cutVoxel(xcenter + i, ycenter + j, zcenter + k);
                            //v[i][j][k].isOn = false;
                    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    double x, y, z;

	for (int i = 0; i < nx; i++)
		for (int j = 0; j < ny; j++)
			for (int k = 0; k < nz; k++) {
				x = ((double)(i - xcenter) * (double)(i - xcenter)) / (rx * rx);
				y = ((double)(j - ycenter) * (double)(j - ycenter)) / (ry * ry);
				z = ((double)(k - zcenter) * (double)(k - zcenter)) / (rz * rz);

				if ((x + y + z) < 1)
					putVoxel(i, j, k);
			}
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    double x, y, z;

	for (int i = 0; i < nx; i++)
		for (int j = 0; j < ny; j++)
			for (int k = 0; k < nz; k++) {
				x = ((double)(i - xcenter) * (double)(i - xcenter)) / (rx * rx);
				y = ((double)(j - ycenter) * (double)(j - ycenter)) / (ry * ry);
				z = ((double)(k - zcenter) * (double)(k - zcenter)) / (rz * rz);

				if ((x + y + z) < 1)
					cutVoxel(i, j, k);
			}
}

void Sculptor::writeOFF(const char* offname)
{
    std::ofstream off;

    off.open(offname);

    off << "OFF" << std::endl;

    int faces = 0;
    int voxel = 0;

    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                if (v[i][j][k].isOn == true)
                {
                    voxel++;
                }
            }
        }
    }

    //ESCREVE NUMERO DE VERTICES, NUM. DE FACES E ARESTAS(0)
    off << 8 * voxel << " " << 6 * voxel << " " << 0 << std::endl;

    //ESCREVE CADA POSIÇÃO DE CADA VERTICE DE CADA VOXEL
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                if (v[i][j][k].isOn == true)
                {
                    off << -0.5 + i << " " << 0.5 + j << " " << -0.5 + k << std::endl;
                    off << -0.5 + i << " " << -0.5 + j << " " << -0.5 + k << std::endl;
                    off << 0.5 + i << " " << -0.5 + j << " " << -0.5 + k << std::endl;
                    off << 0.5 + i << " " << 0.5 + j << " " << -0.5 + k << std::endl;
                    off << -0.5 + i << " " << 0.5 + j << " " << 0.5 + k << std::endl;
                    off << -0.5 + i << " " << -0.5 + j << " " << 0.5 + k << std::endl;
                    off << 0.5 + i << " " << -0.5 + j << " " << 0.5 + k << std::endl;
                    off << 0.5 + i << " " << 0.5 + j << " " << 0.5 + k << std::endl;
                }
            }
        }
    }

    //MOSTRA COM APENAS UMA CASA DECIMAL
    off << std::fixed << std::setprecision(1);

    //DEFINE, DE ACORDO COM A REGRA DA MÃO DIREITA, CADA FACE NO ARQUIVO .
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                if (v[i][j][k].isOn == true)
                {
                    off << "4 " << 0 + faces * 8 << " " << 3 + faces * 8 << " " << 2 + faces * 8 << " " << 1 + faces * 8 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    off << "4 " << 4 + faces * 8 << " " << 5 + faces * 8 << " " << 6 + faces * 8 << " " << 7 + faces * 8 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    off << "4 " << 0 + faces * 8 << " " << 1 + faces * 8 << " " << 5 + faces * 8 << " " << 4 + faces * 8 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    off << "4 " << 0 + faces * 8 << " " << 4 + faces * 8 << " " << 7 + faces * 8 << " " << 3 + faces * 8 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    off << "4 " << 3 + faces * 8 << " " << 7 + faces * 8 << " " << 6 + faces * 8 << " " << 2 + faces * 8 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    off << "4 " << 1 + faces * 8 << " " << 2 + faces * 8 << " " << 6 + faces * 8 << " " << 5 + faces * 8 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    faces++;
                }
            }
        }
    }

    off.close();
}

void Sculptor::setColor(float _r, float _g, float _b, float _alpha)
{
    r = _r;
    g = _g;
    b = _b;
    a = _alpha;
}

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
