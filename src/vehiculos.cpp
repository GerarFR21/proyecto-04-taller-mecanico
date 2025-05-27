// vehiculos.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include "vehiculos.h"
using namespace std;

void agregarVehiculo() {
    Vehiculo v;
    cout << "Marca: ";
    cin.ignore(); cin.getline(v.marca, 30);
    cout << "Modelo: ";
    cin.getline(v.modelo, 30);
    cout << "Anio: ";
    cin >> v.anio;
    cout << "Placa: ";
    cin.ignore(); cin.getline(v.placa, 10);

    // Validar que no se repita la placa
    ifstream fin("vehiculos.dat", ios::binary);
    Vehiculo temp;
    while (fin.read((char*)&temp, sizeof(Vehiculo))) {
        if (strcmp(temp.placa, v.placa) == 0) {
            cout << "Error: Vehiculo con esa placa ya existe.\n";
            fin.close();
            return;
        }
    }
    fin.close();

    ofstream fout("vehiculos.dat", ios::binary | ios::app);
    fout.write((char*)&v, sizeof(Vehiculo));
    fout.close();

    cout << "Vehiculo agregado exitosamente.\n";
}

void buscarVehiculo() {
    char placaBuscada[10];
    cout << "Ingrese la placa del vehiculo: ";
    cin.ignore(); cin.getline(placaBuscada, 10);

    ifstream fin("vehiculos.dat", ios::binary);
    Vehiculo v;
    bool encontrado = false;

    while (fin.read((char*)&v, sizeof(Vehiculo))) {
        if (strcmp(v.placa, placaBuscada) == 0) {
            cout << "Vehiculo encontrado:\n";
            cout << "Marca: " << v.marca << "\n";
            cout << "Modelo: " << v.modelo << "\n";
            cout << "Anio: " << v.anio << "\n";
            cout << "Placa: " << v.placa << "\n";
            encontrado = true;
            break;
        }
    }
    fin.close();

    if (!encontrado)
        cout << "Vehiculo no encontrado.\n";
}

void editarVehiculo() {
    char placaBuscada[10];
    cout << "Ingrese la placa del vehiculo a editar: ";
    cin.ignore(); cin.getline(placaBuscada, 10);

    fstream archivo("vehiculos.dat", ios::binary | ios::in | ios::out);
    Vehiculo v;
    bool encontrado = false;

    while (!archivo.eof()) {
        streampos pos = archivo.tellg();
        archivo.read((char*)&v, sizeof(Vehiculo));

        if (archivo && strcmp(v.placa, placaBuscada) == 0) {
            cout << "Vehiculo encontrado. Ingrese los nuevos datos:\n";
            cout << "Marca: "; cin.getline(v.marca, 30);
            cout << "Modelo: "; cin.getline(v.modelo, 30);
            cout << "Anio: "; cin >> v.anio;
            cin.ignore();

            archivo.seekp(pos);
            archivo.write((char*)&v, sizeof(Vehiculo));
            encontrado = true;
            cout << "Vehiculo actualizado.\n";
            break;
        }
    }
    archivo.close();

    if (!encontrado)
        cout << "Vehiculo no encontrado.\n";
}

void listarVehiculos() {
    ifstream fin("vehiculos.dat", ios::binary);
    Vehiculo v;
    cout << "\n--- Lista de Vehiculos ---\n";
    while (fin.read((char*)&v, sizeof(Vehiculo))) {
        cout << "Marca: " << v.marca << ", Modelo: " << v.modelo
             << ", Año: " << v.anio << ", Placa: " << v.placa << "\n";
    }
    fin.close();
}
