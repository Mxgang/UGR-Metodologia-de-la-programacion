#ifndef _MYIO_
#define _MYIO_

#include <iostream>
#include <string>

class MyIO{

  public:

    void    error(const char* mensaje);

    bool    filtro(int elemento, int min, int max);
    bool    filtro(char elemento, char min, char max);

    int     leeFiltrado(int min, int max);

    int     leeNumeroFiltrado(int min, int max);
    float   leeNumeroFiltrado(float min, float max);
    double  leeNumeroFiltrado(double min, double max);

    void    imprimeVector(char *v, int n, int col=5);
    void    imprimeVector(int *v, int n, int col=5);
    void    imprimeVector(float *v, int n, int col=5);
    void    imprimeVector(double *v, int n, int col=5);

    void    imprimeMatriz(char **m, int fil, int col);
    void    imprimeMatriz(int **m, int fil, int col);
    void    imprimeMatriz(float **m, int fil, int col);
    void    imprimeMatriz(double **m, int fil, int col);

    int     menu(std::string opciones[], int n);

};

#endif