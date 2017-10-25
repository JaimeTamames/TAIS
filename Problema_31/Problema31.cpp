// Grupo TAIS36, Ruben y Jaime
// Ejercicio 31
// Comentario y coste... ?

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//
bool resuelveCaso() {
    
    int nSimbolos, mensaje;
    
    cin >> nSimbolos;
    
    //Si llegamos al caso 0 salimos
    if (nSimbolos == 0){
        return false;
    }
    else{
        
         vector<int> vCodigos(nSimbolos);
    
        //Para los demas casos...
        for(int i = 0; i < nSimbolos; i++){
            
            cin >> vCodigos[i];
            
        }
        
        cin >> mensaje;
        
        return true;
    }
}

int main(int argc, const char * argv[]) {
    
    // Ajustes para que cin extraiga directamente de un fichero
    //    #ifndef DOMJUDGE
    //        ifstream in("casos.txt");
    //        auto cinbuf = cin.rdbuf(in.rdbuf());
    //    #endif
    
    while (resuelveCaso());
    
    // Para dejar todo como estaba al principio
    //    #ifndef DOMJUDGE
    //        cin.rdbuf(cinbuf);
    //        system("PAUSE");
    //    #endif
    
    return 0;
}
