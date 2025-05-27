// duenos.h
#ifndef DUENOS_H
#define DUENOS_H

struct Dueno {
    char nombre[50];
    char direccion[100];
    char dui[10];
    char telefono[15];
};

void agregarDueno();
void buscarDueno();
void editarDueno();
void listarDuenos();

#endif
