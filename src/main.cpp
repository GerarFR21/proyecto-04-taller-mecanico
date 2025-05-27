// main.cpp
#include <iostream>
#include "vehiculos.h"
#include "duenos.h"
#include "repuestos.h"
#include "trabajos.h"
using namespace std;

int main() {
    
    int opcion;
    do
    {
       cout << "-----------SISTEMA DE ADMINISTRACION DE TRABAJOS \"LA CARCACHA DE SELENA\"----------\n";
       cout << "1. Gestionar Vehiculos\n";
       cout << "2. Gestionar Duenios\n";
       cout << "3. Gestionar Repuestos\n";
       cout << "4. Gestionar Trabajos\n";
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
                cout << "\n--- MENU DUENIOS ---\n";
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

        case 3:
            
            do {
                cout << "\n--- MENU REPUESTOS ---\n";
                cout << "1. Agregar Repuesto\n";
                cout << "2. Buscar Repuesto\n";
                cout << "3. Editar Repuesto\n";
                cout << "4. Listar Repuestos\n";
                cout << "0. Salir\n";
                cout << "Seleccione una opcion: ";
                cin >> opcion;

                switch(opcion) {
                    case 1: agregarRepuesto(); break;
                    case 2: buscarRepuesto(); break;
                    case 3: editarRepuesto(); break;
                    case 4: listarRepuestos(); break;
                    case 0: cout << "Saliendo...\n"; break;
                    default: cout << "Opcion invalida.\n"; break;
                }
            } while(opcion != 0);
        break;

        case 4:
            
            do {
                cout << "\n--- MENU TRABAJOS ---\n";
                cout << "1. Agregar Trabajo\n";
                cout << "2. Listar Trabajo\n";
                cout << "3. Buscar Trabajo por Placa\n";
                cout << "0. Salir\n";
                cout << "Seleccione una opcion: ";
                cin >> opcion;

                switch(opcion) {
                    case 1: agregarTrabajo(); break;
                    case 2: listarTrabajos(); break;
                    case 3: buscarTrabajoPorPlaca(); break;
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

