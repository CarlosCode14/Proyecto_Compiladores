#include <iostream>
#include <string>
#include <cstring>
using namespace std;
/////////////////////////////
struct cadena {
    char *contenido;   //es solo ejemplo de puntero a 
};
////////////////////////
int main() {
    cadena oracion;
    string entrada;

    cout << "Ingresa la cadena: ";
    getline(cin, entrada);   // Lee toda la línea completa

    // Reservar memoria dinámica exacta
    oracion.contenido = new char[entrada.size() + 1];
    // Copiar el contenido de string a char*
    strcpy(oracion.contenido, entrada.c_str());

    cout << "La cadena guardada es: " << oracion.contenido << endl;

    // Liberar memoria
    delete[] oracion.contenido;

    return 0;
}
