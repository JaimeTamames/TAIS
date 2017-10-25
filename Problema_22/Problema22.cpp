// Grupo TAIS36, Ruben y Jaime
// Ejercicio 22
// Coste O(n) o O(nlog n) si tenemos en cuenta que hay que ordenar primero los vectores

#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

// Recorre los dos arrais ya ordenados y acumula los puntos de mas en la solucion en los resultados positivos
int resuelve(vector<int> const &boston, vector<int> const &rival){
    
    int sol = 0, aux;
    
    for(size_t i = 0; i < boston.size(); i++){
        
        aux = boston[i] - rival[i];
        
        if(aux > 0)
            sol = sol + aux;
    }
    
    return sol;
}

// O(n)
bool resuelveCaso() {
    
    int nPartidos;
    
    cin >> nPartidos;
    
    //Fin de entrada de casos
    if (nPartidos == 0){
        return false;
    }
    //Para los demas casos...
    else{
        
        vector<int> boston = vector<int>(nPartidos);
        
        vector<int> rival = vector<int>(nPartidos);
        
        for(int i = 0; i < nPartidos; i++){
            
            cin >> rival[i];
            
        }
        
        for(int i = 0; i < nPartidos; i++){
            
            cin >> boston[i];
            
        }
        
        sort(boston.begin(), boston.end(), greater<int>());
        
        sort(rival.begin(), rival.end(), less<int>());
        
        cout << resuelve(boston, rival) << '\n';
        
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
