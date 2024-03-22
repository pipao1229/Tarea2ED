//
//  main.cpp
//  Tarea2ED
//
//  Creado por Felipe Benavides y Nathaniel Motykiewicz
//

#include <iostream>
#include <cstdlib>
#include "List.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "DLinkedList.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::find;
using std::boolalpha;

// Función para generar un número aleatorio entre min y max
int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    setlocale(LC_CTYPE, "Spanish");
    
    string tipoList;
        List<int>* L = nullptr;

        while (true) { //sirve
            cout << "Que desea utilizar, ArrayList, LinkedList o DLinkedList? (A/L/D) \nCual sería su opción?: ";
            getline(cin, tipoList);

            if (tipoList == "A") {
                L = new ArrayList<int>();
                break;
            } else if (tipoList == "L") {
                L = new LinkedList<int>();
                break;
            } else if (tipoList == "D") {
                L = new DLinkedList<int>();
                break;
            } else {
                cout << "Por favor ingrese una opción válida" << endl;
            }
        }
    
    while (true) { //sirve
    string menu = "las operaciones que se pueden realizar son:\n insert, append, remove, clear, getElement,goToStart, goToEnd, goToPos, next, previous, atStart, atEnd, getPos, getSize, indexOf, contains, cargarLista y salir \nCual opcion desea realizar?: ";
    
    cout << menu;
    string respuestaMenu;
    getline(cin, respuestaMenu);
    
    
    if (respuestaMenu == "insert"){ //este sirve bien
        cout << "cual numero desea insertar?: " << endl;
        int numeroInsert;
        cin >> numeroInsert;
        if (numeroInsert % 1 != 0){
            menu = "error"; }
        L->insert(numeroInsert);
    }
    
    else if (respuestaMenu == "append"){ //este sirve bien
        cout << "cual numero desea insertar?: " << endl;
        int numeroAppend;
        cin >> numeroAppend;
        if (numeroAppend % 1 != 0){
            menu = "error"; }
        L->append(numeroAppend);
    }
    
    else if (respuestaMenu == "remove"){ //sirve pero hay que darle enter dos veces no se pq
        L->remove();
    }
    
    else if (respuestaMenu == "clear"){ // sirve bien igual hay que hacer el doble enter
        L->clear();
        cout << "se ha limpiado la lista" << endl;
    }
    
    else if (respuestaMenu == "getElement"){ // sirve bien
        int elementoPos = L->getElement();
        cout << "el elemento de la posicion actual es: " << elementoPos << endl;
    }
    
    else if (respuestaMenu == "goToStart"){ //sirve bien
        L->goToStart();
        cout << "se ha vuelto al inicio de la lista" << endl;
    }
    
    else if (respuestaMenu == "goToEnd"){ //sirve bien
        L->goToEnd();
        cout << "se ha ido al final de la lista" << endl;
    }
    
    else if (respuestaMenu == "goToPos"){ //sirve bien
        cout << "a que posicion desea ir: " << endl;
        int numeroPosicion;
        cin >> numeroPosicion;
        if (numeroPosicion % 1 != 0){
            menu = "error"; }
        L->goToPos(numeroPosicion);
        cout << "se ha ido a la posicion" << numeroPosicion << endl;
    }
    
    else if (respuestaMenu == "next"){ //sirve bien
        L->next();
        cout << "se ha movido a la siguiente posicion" << endl;
    }
    
    else if (respuestaMenu == "previous"){ //sirve bien
        L->previous();
        cout << "se ha movido a la posicion anterior";
    }
    
    else if (respuestaMenu == "atStart"){ // sirve con bool
        bool boolAtStart = L->atStart();
        if (boolAtStart == 1){
            boolAtStart = true; }
        else{
            boolAtStart = false;
        }
        cout << "la posicion está al inicio: " << boolAtStart << endl;
    }
    
    else if (respuestaMenu == "atEnd"){ // sirve
        bool boolAtEnd = L->atEnd();
        if (boolAtEnd == 1){
            boolAtEnd = true; }
        else{
            boolAtEnd = false;
        }
        cout << "la posicion está al final : " << boolAtEnd << endl;
    }
    
    else if (respuestaMenu == "getPos"){ // sirve
        int pos = L->getPos();
        cout << "esta en la posición: " << pos << endl;
    }
    
    else if (respuestaMenu == "getSize"){ // sirve
        int sizeLista = L->getSize();
        cout << "el tamaño de la lista es de:" << sizeLista << endl;
        
    }
    
    else if (respuestaMenu == "indexOf"){ // sirve
        cout << "para que numero le desea averiguar su indice?: " << endl;
        int numeroIndice;
        cin >> numeroIndice;
        int indiceNum = L->indexOf(numeroIndice);
        if (numeroIndice % 1 != 0){
            menu = "error"; }
        cout << "el indice de el numero " << numeroIndice << " es " << indiceNum << endl;
    }
    
    else if (respuestaMenu == "contains"){ // no retorna el bool, sino 1 o 0, no se como cambiarlo
        cout << "que numero desea saber si está en la lista? : " << endl;
        int numeroContains;
        cin >> numeroContains;
        bool contieneNum = L->contains(numeroContains);
        if (numeroContains % 1 != 0){
            menu = "error";}
        if (contieneNum == 1){
            contieneNum = true; }
        else {
            contieneNum = false;
        }
        cout << "el numero " << numeroContains << " está en la lista: " << contieneNum << endl;
            
    }
    else if (respuestaMenu == "cargarLista"){ //sirve bien
        cout << "con cuantos numero aleatorios desea cargar la lista? :";
        int cantidadNumeros;
        cin >> cantidadNumeros;
        for (int i = 0; i < cantidadNumeros; i++ ) {
            int numeroRandom = random(1,1000); //funcion en la linea 22
            L->append(numeroRandom);
        }
        cout << "se ha cargado la lista con exito\n" << endl;
        
    }
            
    else if (respuestaMenu == "salir"){
        cout << "gracias por usar nuestro programa" << endl;
        break; // solo con salir se ejecuta el break
        }
            
        
    else {
        cout << "\npor favor ingrese una opcion valida\nuse enter para continuar";
    }
            
        cin.ignore(); // si se ingresa una opcion no valida se borra y se vuelve a ejecutar el while
        L->print();
        L->getPos();
        cout << "\n";
        
    } //while del menu principal
    
    delete L; //sacar estos dos del while que sino se borra la lista
    return 0;
}
