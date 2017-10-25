// Grupo TAIS36, Ruben y Jaime
// Ejercicio 20
// Coste O(n) o O(nlog n) si tenemos en cuenta que hay que ordenar primero el vector

#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

// Recorre el array de los precios de libros ya ordenados de mayor a menor y cada 3 libros acumula el valor en el resultado
int resuelve(vector<int> const &lista){
    
    int sol = 0, cont = 0;
    
    for(size_t i = 0; i < lista.size(); i++){
        
        if(cont == 2){
            sol = sol + lista[i];
            cont = -1;
        }
        
        cont++;
    }
    
    return sol;
}

// O(n)
bool resuelveCaso() {
    
    int nLibros;
    
    cin >> nLibros;
    
    //Fin de entrada de casos
    if (!cin){
        return false;
    }
    //Para los demas casos...
    else{
        
        vector<int> lista = vector<int>(nLibros);
        
        for(int i = 0; i < nLibros; i++){
            
            cin >> lista[i];
            
        }
        
        sort(lista.begin(), lista.end(), greater<int>());
        
        cout << resuelve(lista) << '\n';

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
