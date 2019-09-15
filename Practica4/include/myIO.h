#ifndef _MYIO_
#define _MYIO_

#include <iostream>
#include <string>

class MyIO{

  public:

    void    error(const char* mensaje);

    bool filtro(int elemento, int min, int max);
    bool filtro(char elemento, char min, char max);

    int     leeNumeroFiltrado(int min, int max);
    float   leeNumeroFiltrado(float min, float max);
    double  leeNumeroFiltrado(double min, double max);


    void    imprimeVector(int *v, int n, int col=5);
    void    imprimeVector(float *v, int n, int col=5);
    void    imprimeVector(double *v, int n, int col=5);

};

#endif