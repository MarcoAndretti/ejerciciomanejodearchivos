#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void mostrarMenu() {
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Crear archivo" << endl;
    cout << "2. Abrir archivo" << endl;
    cout << "3. Editar archivo" << endl;
    cout << "4. Eliminar archivo" << endl;
    cout << "5. Salir" << endl;
    cout << ":";
}

int main() {
    string nombreArchivo, contenidoArchivo, rutaArchivo, escritorio;
    char opcion;
    char* escritorioTemp = getenv("USERPROFILE");
    escritorio = string(escritorioTemp) + "\\Desktop\\";

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case '1': {
                cout << "Ingrese el nombre del archivo (con extension .txt): ";
                cin >> nombreArchivo;

                rutaArchivo = escritorio + nombreArchivo;

                cout << "Ingrese el contenido del archivo (presione 0 cuando termine):" << endl;
                cin.ignore(); // Ignorar el salto de línea después de leer la opción

                getline(cin, contenidoArchivo, '0'); // Leer hasta encontrar el carácter '0'

                // Crear y escribir en el archivo
                ofstream archivo(rutaArchivo);
                if (archivo.is_open()) {
                    archivo << contenidoArchivo;
                    archivo.close();
                    cout << "Archivo creado exitosamente en el escritorio." << endl;
                } else {
                    cout << "Error al crear el archivo." << endl;
                }
                break;
            }

            case '2': {
                cout << "Ingrese el nombre del archivo (con extension .txt): ";
                cin >> nombreArchivo;

                rutaArchivo = escritorio + nombreArchivo;

                ifstream archivo(rutaArchivo);
                if (archivo.is_open()) {
                    cout << "Contenido del archivo:" << endl;
                    string linea;
                    while (getline(archivo, linea)) {
                        cout << linea << endl;
                    }
                    archivo.close();
                } else {
                    cout << "Error al abrir el archivo." << endl;
                }
                break;
            }

            case '3': {
                cout << "Ingrese el nombre del archivo (con extension .txt): ";
                cin >> nombreArchivo;

                rutaArchivo = escritorio + nombreArchivo;

                cout << "Ingrese el nuevo contenido del archivo (presione 0 cuando termine):" << endl;
                cin.ignore(); // Ignorar el salto de línea después de leer la opción

                getline(cin, contenidoArchivo, '0'); // Leer hasta encontrar el carácter '0'

                // Abrir el archivo en modo escritura y sobreescribir su contenido
                ofstream archivo(rutaArchivo, ios::trunc);
                if (archivo.is_open()) {
                    archivo << contenidoArchivo;
                    archivo.close();
                    cout << "Archivo editado exitosamente." << endl;
                } else {
                    cout << "Error al editar el archivo." << endl;
                }
                break;
            }

            case '4': {
                cout << "Ingrese el nombre del archivo (con extension .txt): ";
                cin >> nombreArchivo;

                rutaArchivo = escritorio + nombreArchivo;

                if (remove(rutaArchivo.c_str()) == 0) {
                    cout << "Archivo eliminado exitosamente." << endl;
                } else {
                    cout << "Error al eliminar el archivo." << endl;
                }
                break;
            }

            case '5':
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }

    } while (opcion != '5');

    return 0;
}