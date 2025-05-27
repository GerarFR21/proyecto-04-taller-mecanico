// repuestos.h
#ifndef REPUESTOS_H
#define REPUESTOS_H

struct Repuesto {
    char tienda[50];
    char marca[30];
    char nombre[40];
    char serie[20];
    char garantia[20];
    float precio;
};

void agregarRepuesto();
void buscarRepuesto();
void editarRepuesto();
void listarRepuestos();

#endif
