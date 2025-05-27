// vehiculos.h
#ifndef VEHICULOS_H
#define VEHICULOS_H

struct Vehiculo {
    char marca[30];
    char modelo[30];
    int anio;
    char placa[10];
};

void agregarVehiculo();
void buscarVehiculo();
void editarVehiculo();
void listarVehiculos();

#endif
