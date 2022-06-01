#ifndef SCULPTOR_H
#define SCULPTOR_H

#ifndef PROJETOESCULTOR_H_INCLUDED
#define PROJETOESCULTOR_H_INCLUDED

struct Voxel
{
  float r, g, b; // Colors
  float a;
  // Transparency
  bool isOn; // Included or not
};

class Sculptor
{
protected:
  Voxel ***v;
  // 3D matrix
  int nx, ny, nz;   // Dimensions
  float r, g, b, a; // Current drawing color
public:
  Sculptor(int _nx, int _ny, int _nz);                         // FEITO
  ~Sculptor();                                                 // FEITO
  void setColor(float r, float g, float b, float alpha);       // FEITO
  void putVoxel(int x, int y, int z);                          // FEITO
  void cutVoxel(int x, int y, int z);                          // FEITO
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1); // FEITO
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1); // FEITO
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);  // FEITO
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);  // FEITO
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); // FEITO
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); // FEITO
  void writeOFF(const char *filename); // FEITO

};

#endif // PROJETOESCULTOR_H_INCLUDED

#endif // SCULPTOR_H