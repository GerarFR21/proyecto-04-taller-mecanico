// main.cpp
#include <iostream>
#include "vehiculos.h"
#include "duenos.h"
using namespace std;

int main() {
    
    int opcion;
    do
    {
       cout << "-----------SISTEMA DE ADMINISTRACION DE TRABAJOS \"LA CARCACHA DE SELENA\"----------\n";
       cout << "1. Gestionar Vehiculos\n";
       cout << "2. Gestionar Duenios\n";
       cout << "0. Salir\n";
       cin >> opcion;

       switch (opcion)
       {
       case 1:
            int opcion;
            do {
                cout << "\n--- MENU VEHICULOS ---\n";
                cout << "1. Agregar Vehiculo\n";
                cout << "2. Buscar Vehiculo\n";
                cout << "3. Editar Vehiculo\n";
                cout << "4. Listar Vehiculos\n";
                cout << "0. Salir\n";
                cout << "Seleccione una opcion: ";
                cin >> opcion;

                switch(opcion) {
                    case 1: agregarVehiculo(); break;
                    case 2: buscarVehiculo(); break;
                    case 3: editarVehiculo(); break;
                    case 4: listarVehiculos(); break;
                    case 0: cout << "Saliendo...\n"; break;
                    default: cout << "Opcion invalida.\n"; break;
                }
            } while(opcion != 0);
        break;
       
       case 2:
            
            do {
                cout << "\n--- MENU DUEÑOS ---\n";
                cout << "1. Agregar Duenio\n";
                cout << "2. Buscar Duenio\n";
                cout << "3. Editar Duenio\n";
                cout << "4. Listar Duenios\n";
                cout << "0. Salir\n";
                cout << "Seleccione una opcion: ";
                cin >> opcion;

                switch(opcion) {
                    case 1: agregarDueno(); break;
                    case 2: buscarDueno(); break;
                    case 3: editarDueno(); break;
                    case 4: listarDuenos(); break;
                    case 0: cout << "Saliendo...\n"; break;
                    default: cout << "Opcion invalida.\n"; break;
                }
            } while(opcion != 0);
        break;

        case 0: cout << "Saliendo...\n"; break;

        default: cout << "Opcion invalida.\n"; break;
       }

    } while (opcion != 0);
    
}

