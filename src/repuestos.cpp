// repuestos.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include "repuestos.h"
using namespace std;

const char* RUTA_REPUESTOS = "data/repuestos.dat";

void agregarRepuesto() {
    Repuesto r;
    cout << "Tienda: ";
    cin.ignore(); cin.getline(r.tienda, 50);
    cout << "Marca: ";
    cin.getline(r.marca, 30);
    cout << "Nombre: ";
    cin.getline(r.nombre, 40);
    cout << "Serie: ";
    cin.getline(r.serie, 20);
    cout << "Garantia: ";
    cin.getline(r.garantia, 20);
    cout << "Precio: ";
    cin >> r.precio;

    // Validar que no se repita la serie
    ifstream fin(RUTA_REPUESTOS, ios::binary);
    Repuesto temp;
    while (fin.read((char*)&temp, sizeof(Repuesto))) {
        if (strcmp(temp.serie, r.serie) == 0) {
            cout << "Error: Ya existe un repuesto con esa serie.\n";
            fin.close();
            return;
        }
    }
    fin.close();

    ofstream fout(RUTA_REPUESTOS, ios::binary | ios::app);
    fout.write((char*)&r, sizeof(Repuesto));
    fout.close();

    cout << "Repuesto agregado exitosamente.\n";
}

void buscarRepuesto() {
    char serieBuscada[20];
    cout << "Ingrese la serie del repuesto: ";
    cin.ignore(); cin.getline(serieBuscada, 20);

    ifstream fin(RUTA_REPUESTOS, ios::binary);
    Repuesto r;
    bool encontrado = false;

    while (fin.read((char*)&r, sizeof(Repuesto))) {
        if (strcmp(r.serie, serieBuscada) == 0) {
            cout << "Repuesto encontrado:\n";
            cout << "Tienda: " << r.tienda << "\n";
            cout << "Marca: " << r.marca << "\n";
            cout << "Nombre: " << r.nombre << "\n";
            cout << "Serie: " << r.serie << "\n";
            cout << "Garantia: " << r.garantia << "\n";
            cout << "Precio: $" << r.precio << "\n";
            encontrado = true;
            break;
        }
    }
    fin.close();

    if (!encontrado)
        cout << "Repuesto no encontrado.\n";
}

void editarRepuesto() {
    char serieBuscada[20];
    cout << "Ingrese la serie del repuesto a editar: ";
    cin.ignore(); cin.getline(serieBuscada, 20);

    fstream archivo(RUTA_REPUESTOS, ios::binary | ios::in | ios::out);
    Repuesto r;
    bool encontrado = false;

    while (!archivo.eof()) {
        streampos pos = archivo.tellg();
        archivo.read((char*)&r, sizeof(Repuesto));

        if (archivo && strcmp(r.serie, serieBuscada) == 0) {
            cout << "Repuesto encontrado. Ingrese los nuevos datos:\n";
            cout << "Tienda: "; cin.getline(r.tienda, 50);
            cout << "Marca: "; cin.getline(r.marca, 30);
            cout << "Nombre: "; cin.getline(r.nombre, 40);
            cout << "Garantia: "; cin.getline(r.garantia, 20);
            cout << "Precio: "; cin >> r.precio;
            cin.ignore();

            archivo.seekp(pos);
            archivo.write((char*)&r, sizeof(Repuesto));
            encontrado = true;
            cout << "Repuesto actualizado.\n";
            break;
        }
    }
    archivo.close();

    if (!encontrado)
        cout << "Repuesto no encontrado.\n";
}

void listarRepuestos() {
    ifstream fin(RUTA_REPUESTOS, ios::binary);
    Repuesto r;
    cout << "\n--- Lista de Repuestos ---\n";
    while (fin.read((char*)&r, sizeof(Repuesto))) {
        cout << "Tienda: " << r.tienda << ", Marca: " << r.marca
             << ", Nombre: " << r.nombre << ", Serie: " << r.serie
             << ", Garantia: " << r.garantia << ", Precio: $" << r.precio << "\n";
    }
    fin.close();
}
