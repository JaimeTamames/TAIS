// Grupo TAIS36, Jaime

#include <iostream>
#include "Bipartito.h"

using namespace std;

bool resuelveCaso() {
    
    size_t nAristas, nVertices;
    
    cin >> nVertices;
    cin >> nAristas;
    
    //Fin de entrada de casos
    if (!cin){
       
        return false;
    }
    //Para los demas casos...
    else{
    
        Grafo grafo(nVertices);
        
        for (size_t i = 0; i < nAristas; i++) {
            
            size_t a, b;
            
            cin >> a >> b;
            
            grafo.ponArista(a, b);
            
        }
        
        Bipartito bi(grafo);
        
        if(bi.esBipartito()){
            
            cout << "SI" << endl;
        }
        else{
            
            cout << "NO" << endl;
        }
    }
    
    return true;
    
}

int main() {
    
    while (resuelveCaso());
    
    return 0;
}
