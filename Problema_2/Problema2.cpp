// Grupo TAIS36, Ruben y Jaime
// Recorremos el arbol de forma recursiva en postOrden desde los hijos izquierdos a los derechos,
// realizando las comparaciones necesarias para saber si el arbol esta equilibrado y llevamos el valor maximo de los hijos
//segun vamos recorriendo el árbol con el fin de saber si es AVL.



#include <algorithm>
#include <iostream>
#include "BinTree.h"

// leemos el arbol

BinTree<int> leerArbol() {
    int raiz;
    std::cin >> raiz;
    if (raiz == -1) { //Es vacio
        return{};
    }
    else { //Leer recursivamente los hijos
        auto iz = leerArbol();
        auto dr = leerArbol();
        return{ iz, raiz, dr };
    }
}

//Coste lineal O(n)

bool esEquilibrado(BinTree<int> const& arbol, bool &equilibrado, int &alt){
    
    //Recorremos el arbol en PostOrden
    
    //Variable local para cada nodo con la altura de sus hijos
    int auxAHI = -1;
    int auxAHD = -1;
    
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
            else{
                
                auxAHI = 0;
            }
            
            //DERECHA
            if (!arbol.right().empty()){
                
                esEquilibrado(arbol.right(), equilibrado, alt);
                
                auxAHD = alt + 1;
            }
            else{
                
                auxAHD = 0;
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

//Coste lineal O(n)
bool esAVL(BinTree<int> const& arbol, bool &avl, int &hijoMax, int &hijoMin){
    
    if(!arbol.empty() && avl){
        
        //FINAL
        if(arbol.left().empty() && arbol.right().empty()){
            
            hijoMin = arbol.root();
            hijoMax = arbol.root();
            
        }
        else{
            
            int aux = -100;
            
            //IZQUIERDA
            if (!arbol.left().empty()){
                
                esAVL(arbol.left(), avl, hijoMax, hijoMin);
                
                if(hijoMax >= arbol.root())
                    avl = false;
                else hijoMax = arbol.root();
                aux = hijoMin;
            }
            
            //DERECHA
            if (!arbol.right().empty()){
                
                esAVL(arbol.right(), avl, hijoMax, hijoMin);
                
                if(hijoMin <= arbol.root())
                    avl = false;
                if (aux != -100)
                    hijoMin = aux;
                else hijoMin = arbol.root();
            }
            
            
        }
    }
    return avl;
}

//Resuelve un caso de prueba

void resuelveCaso() {
    
    auto arbol = leerArbol();
    
    bool equilibrado = true;
    int alt = -1;
    
    bool avl = true;
    int hijoMax = -100;
    int hijoMin = 1000;
    
    if (esEquilibrado(arbol, equilibrado, alt) && esAVL(arbol, avl, hijoMax, hijoMin))
        std::cout << "SI" << "\n";
    else
        std::cout << "NO" << "\n";
    
}

int main() {
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    //system("PAUSE");
    return 0;
}
