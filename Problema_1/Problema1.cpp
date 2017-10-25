// Grupo TAIS36, Ruben y Jaime
// Recorremos el arbol de forma recursiva en postOrden desde los hijos izquierdos a los derechos,
// realizando las comparaciones necesarias para saber si el arbol esta equilibrado.

#include <algorithm>
#include <iostream>
#include "BinTree.h"

//Leemos el arbol

BinTree<char> leerArbol() {
    char raiz;
    std::cin >> raiz;
    if (raiz == '.') { //Es vac’o
        return{};
    }
    else { //Leer recursivamente los hijos
        auto iz = leerArbol();
        auto dr = leerArbol();
        return{ iz, raiz, dr };
    }
}


bool esEquilibrado(BinTree<char> const& arbol, bool &equilibrado, int &alt){
    
    //Recorremos el arbol en PostOrden
    
    //Variable local para cada nodo con la altura de sus hijos
    int auxAHI = 0;
    int auxAHD = 0;
    
    if (!arbol.empty() && equilibrado){
  
        //FINAL
        if(arbol.left().empty() && arbol.right().empty()){
            
            alt = 0;
        }
        else{
            
            //IZQUIERDA
            if (!arbol.left().empty()){

                esEquilibrado(arbol.left(), equilibrado, alt);
                
                auxAHI = alt + 1;
            }
            
            //DERECHA
            if (!arbol.right().empty()){

                esEquilibrado(arbol.right(), equilibrado, alt);

                auxAHD = alt + 1;
            }

            //RAIZ
            if (abs(auxAHI - auxAHD) > 1){
                
                equilibrado = false;
            }
            else{
            
                //MAX
                alt = std::max(auxAHD, auxAHI);
            }
        }
    }

    return equilibrado;
}

//Resuelve un caso de prueba

void resuelveCaso() {
    
    auto arbol = leerArbol();
    
    bool equilibrado = true;
    int alt = -1;
    
    if (esEquilibrado(arbol, equilibrado, alt))
        std::cout << "SI" << "\n";
    else
        std::cout << "NO" << "\n";
    
}

int main() {
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    system("PAUSE");
    return 0;
}
