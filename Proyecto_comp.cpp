#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct cadena {
    char *contenido = nullptr;
};


struct Nodo {
    cadena dato;
    Nodo *siguiente = nullptr;
};

struct Queue {
    Nodo *frente = nullptr;
    Nodo *final  = nullptr;
};


void guardarCadena(Queue *q, const char *texto) {
    Nodo *nuevo = new Nodo();

    nuevo->dato.contenido = new char[strlen(texto) + 1];
    strcpy(nuevo->dato.contenido, texto);
    nuevo->siguiente = nullptr;

    if (q->final == nullptr) {
        q->frente = nuevo;
        q->final  = nuevo;
    } else {
        q->final->siguiente = nuevo;
        q->final = nuevo;
    }
}


void liberarQueue(Queue *q) {
    while (q->frente != nullptr) {
        Nodo *temp = q->frente;
        q->frente  = q->frente->siguiente;
        delete[] temp->dato.contenido;
        delete temp;
    }
    q->final = nullptr;
}

int main() {
    Queue q;
    string entrada;

    cout << "Ingresa la cadena: ";
    getline(cin, entrada);

    guardarCadena(&q, entrada.c_str());

    cout << "Cadena guardada: " << q.frente->dato.contenido << endl;

    liberarQueue(&q);
    return 0;
}
