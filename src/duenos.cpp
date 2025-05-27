// duenos.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include "duenos.h"
using namespace std;

const char* RUTA_DUENOS = "data/duenos.dat";

void agregarDueno() {
    Dueno d;
    cout << "Nombre: ";
    cin.ignore(); cin.getline(d.nombre, 50);
    cout << "Direccion: ";
    cin.getline(d.direccion, 100);
    cout << "DUI: ";
    cin.getline(d.dui, 10);
    cout << "Telefono: ";
    cin.getline(d.telefono, 15);

    // Verificar si ya existe ese DUI
    ifstream fin(RUTA_DUENOS, ios::binary);
    Dueno temp;
    while (fin.read((char*)&temp, sizeof(Dueno))) {
        if (strcmp(temp.dui, d.dui) == 0) {
            cout << "Error: Duenio con ese DUI ya existe.\n";
            fin.close();
            return;
        }
    }
    fin.close();

    ofstream fout(RUTA_DUENOS, ios::binary | ios::app);
    fout.write((char*)&d, sizeof(Dueno));
    fout.close();

    cout << "Duenio agregado exitosamente.\n";
}

void buscarDueno() {
    char duiBuscado[10];
    cout << "Ingrese el DUI del duenio: ";
    cin.ignore(); cin.getline(duiBuscado, 10);

    ifstream fin(RUTA_DUENOS, ios::binary);
    Dueno d;
    bool encontrado = false;

    while (fin.read((char*)&d, sizeof(Dueno))) {
        if (strcmp(d.dui, duiBuscado) == 0) {
            cout << "Duenio encontrado:\n";
            cout << "Nombre: " << d.nombre << "\n";
            cout << "Direccion: " << d.direccion << "\n";
            cout << "DUI: " << d.dui << "\n";
            cout << "Telefono: " << d.telefono << "\n";
            encontrado = true;
            break;
        }
    }
    fin.close();

    if (!encontrado)
        cout << "Duenio no encontrado.\n";
}

void editarDueno() {
    char duiBuscado[10];
    cout << "Ingrese el DUI del duenio a editar: ";
    cin.ignore(); cin.getline(duiBuscado, 10);

    fstream archivo(RUTA_DUENOS, ios::binary | ios::in | ios::out);
    Dueno d;
    bool encontrado = false;

    while (!archivo.eof()) {
        streampos pos = archivo.tellg();
        archivo.read((char*)&d, sizeof(Dueno));

        if (archivo && strcmp(d.dui, duiBuscado) == 0) {
            cout << "Duenio encontrado. Ingrese los nuevos datos:\n";
            cout << "Nombre: "; cin.getline(d.nombre, 50);
            cout << "Direccion: "; cin.getline(d.direccion, 100);
            cout << "Telefono: "; cin.getline(d.telefono, 15);

            archivo.seekp(pos);
            archivo.write((char*)&d, sizeof(Dueno));
            encontrado = true;
            cout << "Duenio actualizado.\n";
            break;
        }
    }
    archivo.close();

    if (!encontrado)
        cout << "Duenio no encontrado.\n";
}

void listarDuenos() {
    ifstream fin(RUTA_DUENOS, ios::binary);
    Dueno d;
    cout << "\n--- Lista de Duenios ---\n";
    while (fin.read((char*)&d, sizeof(Dueno))) {
        cout << "Nombre: " << d.nombre << ", Direccion: " << d.direccion
             << ", DUI: " << d.dui << ", Telefono: " << d.telefono << "\n";
    }
    fin.close();
}
