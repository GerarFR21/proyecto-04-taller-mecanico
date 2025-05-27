// trabajos.h
#ifndef TRABAJOS_H
#define TRABAJOS_H

struct Trabajo {
    char placaVehiculo[10];
    char duiDueno[10];
    char seriesRepuestos[5][20]; // Hasta 5 repuestos por trabajo
    int cantidadRepuestos;
    char fechaHora[20];
    char descripcion[100];
    float total;
};

void agregarTrabajo();
void buscarTrabajoPorPlaca();
void listarTrabajos();

#endif
