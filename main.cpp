//
//  Función main
//  Tarea2ED
//
//  Creado por Felipe Benavides y Nathaniel Motykiewicz
//

#include <iostream>
#include <cstdlib>
#include <string> // Incluir la cabecera para string
#include "List.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "DLinkedList.h"

using namespace std; // Usar esto para evitar escribir std::

// Función para generar un número aleatorio entre min y max
int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    setlocale(LC_CTYPE, "Spanish");

    string tipoList;
    List<int>* L = nullptr;

    while (true) {
        cout << "¿Qué desea utilizar, ArrayList, LinkedList o DLinkedList? (A/L/D)" << endl;
        cout << "¿Cuál sería su opción?: ";
        getline(cin, tipoList);

        // Según la selección del usuario:
        if (tipoList == "A") { // Crear ArrayList
            L = new ArrayList<int>();
            break;
        }
        else if (tipoList == "L") { // Crear LinkedList
            L = new LinkedList<int>();
            break;
        }
        else if (tipoList == "D") { // Crear DLinkedList
            L = new DLinkedList<int>();
            break;
        }
        else {
            cout << "Por favor ingrese una opción válida" << endl;
        }
    }

    while (true) {
        string menu = "Las operaciones que se pueden realizar son:\n insert, append, remove, clear, getElement, goToStart, goToEnd, goToPos, next, previous, atStart, atEnd, getPos, getSize, indexOf, contains, cargarLista y salir\n ¿Qué opción desea realizar?: ";

        cout << menu;
        string respuestaMenu;
        getline(cin, respuestaMenu);

        if (respuestaMenu == "insert") {
            cout << "¿Cuál número desea insertar?: ";
            string numAInsert;
            cin >> numAInsert;

            try {
                int numeroInsert = stoi(numAInsert); // Intentar convertir el string a un número entero

                L->insert(numeroInsert);
            }
            catch (const invalid_argument& e) { // Capturar la excepción si la conversión falla
                cout << "Error: Debe ingresar un número entero válido." << endl;
            }
        }
        else if (respuestaMenu == "append") {
            cout << "¿Cuál número desea insertar?: ";
            string numAppend;
            cin >> numAppend;

            try {
                int numeroAppend = stoi(numAppend); // Intentar convertir el string a un número entero

                L->append(numeroAppend);
            }
            catch (const invalid_argument& e) { // Capturar la excepción si la conversión falla
                cout << "Error: Debe ingresar un número entero válido." << endl;
            }
        }
        else if (respuestaMenu == "remove") {
            try {
                L->remove();
                cout << "Se eliminó el elemento actual\nUse enter para continuar" << endl;
            }
            catch (const runtime_error& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (respuestaMenu == "clear") { 
            L->clear();
            cout << "Se ha limpiado la lista\nUse enter para continuar" << endl;
        }
        else if (respuestaMenu == "getElement") {
            try {
                int elementoPos = L->getElement();
                cout << "El elemento de la posición actual es: " << elementoPos << endl;
                cout << "Use enter para continuar" << endl;
            }
            catch (const runtime_error& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (respuestaMenu == "goToStart") { 
            L->goToStart();
            cout << "Se ha vuelto al inicio de la lista\nUse enter para continuar" << endl;
        }
        else if (respuestaMenu == "goToEnd") { 
            L->goToEnd();
            cout << "Se ha ido al final de la lista\nUse enter para continuar" << endl;
        }
        else if (respuestaMenu == "goToPos") {
            cout << "A qué posición desea ir: ";
            string numPos;
            cin >> numPos;

            try {
                int numeroPosicion = stoi(numPos); // Intentar convertir el string a un número entero

                L->goToPos(numeroPosicion);
                cout << "Se ha ido a la posición " << numeroPosicion << endl;
            }
            catch (const invalid_argument& e)  { // Capturar la excepción si la conversión falla
                cout << "Error: Debe ingresar un número entero válido.\nUse enter para continuar" << endl;
            }
            catch (const runtime_error& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (respuestaMenu == "next") {
            if (!L->atEnd()) { // Verificar si no se ha llegado al final de la lista
                L->next();
                cout << "Se ha movido a la siguiente posición\nUse enter para continuar" << endl;
            }
            else {
                cout << "Ya se ha llegado al final de la lista\nUse enter para continuar" << endl;
            }
        }
        else if (respuestaMenu == "previous") {
            if (!L->atStart()) { // Verificar si no se ha llegado al inicio de la lista
                L->previous();
                cout << "Se ha movido a la posición anterior\nUse enter para continuar" << endl;
            }
            else {
                cout << "Ya se ha llegado al inicio de la lista\nUse enter para continuar" << endl;
            }
        }
        else if (respuestaMenu == "atStart") { 
            bool boolAtStart = L->atStart();
            if (boolAtStart == true) {
                cout << "Te encuentras en la primera posicion\nUse enter para continuar" << endl;
            }
            else {
                cout << "NO te encuentras en la primera posición\nUse enter para continuar" << endl;
            }
        }
        else if (respuestaMenu == "atEnd") { 
            bool boolAtEnd = L->atEnd();
            if (boolAtEnd == true) {
                cout << "Te encuentras en la última posición\nUse enter para continuar" << endl;
            }
            else {
                cout << "NO te encuentras en la última posición\nUse enter para continuar" << endl;
            }
        }
        else if (respuestaMenu == "getPos") { 
            int pos = L->getPos();
            cout << "Estás en la posición: " << pos << endl;
            cout << "Use enter para continuar" << endl;
        }
        else if (respuestaMenu == "getSize") { 
            int sizeLista = L->getSize();
            cout << "El tamaño de la lista es de: " << sizeLista << endl;
            cout << "Use enter para continuar" << endl;
        }
        else if (respuestaMenu == "indexOf") {
            cout << "Para qué número desea averiguar su índice?: ";
            string indice;
            cin >> indice;

            try {
                int numeroIndice = stoi(indice); // Intentar convertir el string a un número entero

                int indiceNum = L->indexOf(numeroIndice);
                cout << "El índice del número " << numeroIndice << " es " << indiceNum << endl;
            }
            catch (const invalid_argument& e) { // Capturar la excepción si la conversión falla
                cout << "Error: Debe ingresar un número entero válido." << endl;
            }
        }
        else if (respuestaMenu == "contains") {
            cout << "Qué número desea saber si está en la lista?: " << endl;
            string numContains;
            cin >> numContains;

            try {
                int numeroContains = stoi(numContains); // Intentar convertir el string a un número entero

                bool contieneNum = L->contains(numeroContains);

                if (contieneNum) {
                    cout << "El número " << numeroContains << " está en la lista" << endl;
                }
                else {
                    cout << "El número " << numeroContains << " NO está en la lista" << endl;
                }
            }
            catch (const invalid_argument& e) { // Capturar la excepción si la conversión falla
                cout << "Error: Debe ingresar un número entero válido." << endl;
            }
        }
        else if (respuestaMenu == "cargarLista") {
            cout << "Con cuántos números aleatorios desea cargar la lista?: ";
            string numLista;
            cin >> numLista;

            try {
                int cantidadNumeros = stoi(numLista); // Intentar convertir el string a un número entero

                for (int i = 0; i < cantidadNumeros; i++) {
                    int numeroRandom = random(1, 1000); // Función para generar números aleatorios
                    L->append(numeroRandom);
                }
                cout << "Se ha cargado la lista con éxito\n" << endl;
            }
            catch (const invalid_argument& e) { // Capturar la excepción si la conversión falla
                cout << "Error: Debe ingresar un número entero válido." << endl;
            }
        }
        else if (respuestaMenu == "salir") { 
            cout << "Gracias por usar nuestro programa" << endl;
            break;
            }
        else {
                cout << "\nPor favor ingrese una opción válida\nUse enter para continuar";
                }

                cin.ignore();
                L->print();
                L->getPos();
                cout << "\n";
    }

    delete L;
    return 0;
}
