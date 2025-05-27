// trabajos.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "trabajos.h"
#include "vehiculos.h"
#include "duenos.h"
#include "repuestos.h"
using namespace std;

const char* RUTA_TRABAJOS = "data/trabajos.dat";
const char* RUTA_DE_REPUESTOS = "data/repuestos.dat";

float obtenerPrecioRepuesto(const char serie[]) {
    ifstream fin(RUTA_DE_REPUESTOS, ios::binary);
    Repuesto r;
    while (fin.read((char*)&r, sizeof(Repuesto))) {
        if (strcmp(r.serie, serie) == 0) {
            fin.close();
            return r.precio;
        }
    }
    fin.close();
    return 0.0; // No encontrado
}

void agregarTrabajo() {
    Trabajo t;
    cout << "Placa del vehiculo: ";
    cin.ignore(); cin.getline(t.placaVehiculo, 10);

    cout << "DUI del duenio: ";
    cin.getline(t.duiDueno, 10);

    cout << "Cantidad de repuestos usados (max 5): ";
    cin >> t.cantidadRepuestos;
    cin.ignore();

    t.total = 0;
    for (int i = 0; i < t.cantidadRepuestos; ++i) {
        cout << "Serie del repuesto " << i + 1 << ": ";
        cin.getline(t.seriesRepuestos[i], 20);
        float precio = obtenerPrecioRepuesto(t.seriesRepuestos[i]);
        if (precio == 0.0) {
            cout << "Repuesto no encontrado, se asignara precio 0.\n";
        }
        t.total += precio;
    }

    cout << "Fecha y hora (ej: 2025-05-27 10:00): ";
    cin.getline(t.fechaHora, 20);

    cout << "Descripcion del trabajo: ";
    cin.getline(t.descripcion, 100);

    ofstream fout(RUTA_TRABAJOS, ios::binary | ios::app);
    fout.write((char*)&t, sizeof(Trabajo));
    fout.close();

    cout << "Trabajo registrado exitosamente. Total: $" << fixed << setprecision(2) << t.total << "\n";
}

void buscarTrabajoPorPlaca() {
    char placaBuscada[10];
    cout << "Ingrese la placa del vehiculo: ";
    cin.ignore(); cin.getline(placaBuscada, 10);

    ifstream fin(RUTA_TRABAJOS, ios::binary);
    Trabajo t;
    bool encontrado = false;

    while (fin.read((char*)&t, sizeof(Trabajo))) {
        if (strcmp(t.placaVehiculo, placaBuscada) == 0) {
            cout << "\nTrabajo encontrado:\n";
            cout << "Placa: " << t.placaVehiculo << "\n";
            cout << "Duenio (DUI): " << t.duiDueno << "\n";
            cout << "Repuestos usados:\n";
            for (int i = 0; i < t.cantidadRepuestos; ++i) {
                float precio = obtenerPrecioRepuesto(t.seriesRepuestos[i]);
                cout << "  - " << t.seriesRepuestos[i] << " ($" << fixed << setprecision(2) << precio << ")\n";
            }
            cout << "Fecha/Hora: " << t.fechaHora << "\n";
            cout << "Descripcion: " << t.descripcion << "\n";
            cout << "Total: $" << fixed << setprecision(2) << t.total << "\n";
            cout << "-----------------------------\n";
            encontrado = true;
        }
    }

    fin.close();

    if (!encontrado) {
        cout << "No se encontraron trabajos para la placa ingresada.\n";
    }
}


void listarTrabajos() {
    ifstream fin(RUTA_TRABAJOS, ios::binary);
    Trabajo t;
    cout << "\n=== HISTORIAL DE TRABAJOS REALIZADOS ===\n";

    while (fin.read((char*)&t, sizeof(Trabajo))) {
        cout << "\nVehiculo (placa): " << t.placaVehiculo;
        cout << "\nDuenio (DUI): " << t.duiDueno;
        cout << "\nRepuestos usados:\n";
        for (int i = 0; i < t.cantidadRepuestos; ++i) {
            float precio = obtenerPrecioRepuesto(t.seriesRepuestos[i]);
            cout << "  - " << t.seriesRepuestos[i] << " ($" << fixed << setprecision(2) << precio << ")\n";
        }
        cout << "Fecha/Hora: " << t.fechaHora << "\n";
        cout << "Descripcion: " << t.descripcion << "\n";
        cout << "Total: $" << fixed << setprecision(2) << t.total << "\n";
        cout << "-------------------------------\n";
    }

    fin.close();
}
