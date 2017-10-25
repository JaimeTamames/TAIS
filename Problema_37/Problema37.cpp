// Grupo TAIS36, Ruben y Jaime
// Ejercicio 37
// Coste y comentario...?

#include <iostream>
#include <fstream>
#include <vector>

#include "Matriz.h"

using namespace std;

Matriz<int> pascal(int n, int r) {
    
    Matriz<int> C(n + 1, r + 1, 0);
    
    C[0][0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        
        C[i][0] = 1;
        
        for (int j = 1; j <= r; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    
    return C;
}

void calcula(int nElem, Matriz<int> &C, Matriz<int> &Aux){

    if(nElem > 2){
    
        for(int i = 1; i <= nElem; i++){
        
            if(Aux[nElem - 1][i] == 0){
            
                calcula(nElem - i, C, Aux);
                
                if(nElem - i > 1){
                    
                    for(int j = 1; j <= nElem - i; j++){
                        
                        if(Aux[nElem - i][j] == 0){
                            
                            Aux[nElem][i] = Aux[nElem][i] + (C[nElem][i] * C[nElem - i][j]);
                        }else{
                            
                            Aux[nElem][i] = Aux[nElem][i] + (C[nElem][i] * Aux[nElem - i][j]);
                        }
                    }
                }else{
                    
                    Aux[nElem][i] = C[nElem][i];
                }
            }else{
            
                Aux[nElem][i] = Aux[nElem][i] + (C[nElem][i] * Aux[nElem - i][i]);
            }
            
            

        }
    }
}

int resuelve(int nCaracoles){
    
    Matriz<int> Comb = pascal(nCaracoles, nCaracoles);
    
    Matriz<int> Aux(nCaracoles + 1, nCaracoles + 1, 0);
    
    calcula(nCaracoles, Comb, Aux);

    cout << "hola" << "\n";
    
    return (5);
}

//
bool resuelveCaso() {
    
    int nCaracoles;
    
    cin >> nCaracoles;
    
    //Fin de entrada de casos
    if (!cin){
        return false;
    }
    //Para los demas casos...
    else{
        
        cout << resuelve(nCaracoles) << "\n";
        
        return true;
    }
}

int main(int argc, const char * argv[]) {
    
    // Ajustes para que cin extraiga directamente de un fichero
    //        #ifndef DOMJUDGE
    //            ifstream in("casos.txt");
    //            auto cinbuf = cin.rdbuf(in.rdbuf());
    //        #endif
    
    while (resuelveCaso());
    
    // Para dejar todo como estaba al principio
    //        #ifndef DOMJUDGE
    //            cin.rdbuf(cinbuf);
    //            system("PAUSE");
    //        #endif
    
    return 0;
}
