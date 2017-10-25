// Grupo TAIS36, Ruben y Jaime
// Ejercicio 24
// Coste O(n) o O(nlog n) si tenemos en cuenta que hay que ordenar primero el vector

#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

struct Edificio{

    size_t empieza;
    size_t termina;
    
    bool operator < (const Edificio& str) const
    {
        return (termina < str.termina);
    }
    
};

// Recorremos el array de edificios, ordenados de menor a mayor por el elemento "termina", teniendo un edificio de referencia
// para cada tunel con el valor de su final comprobamos que los siguientes edificios no empiecen despues o en el mismo sitio.
// Cuando esto sucede se coloca un tunel y se cambia de edificio de referencia.
int resuelve(vector<Edificio> &vEdicios){
    
    int sol = 0;
    bool ok;
    size_t finalPrimerEdificio, aux;

    for(size_t i = 0; i < vEdicios.size(); i++){
        
        ok = true;
        
        finalPrimerEdificio = vEdicios[i].termina;
        
        do{
            
            aux = i + 1;
            
            if(vEdicios[aux].empieza < finalPrimerEdificio && aux < vEdicios.size()){
                
                i++;
            }
            else{
                
                ok = false;
                sol++;
            }
            
        }while(ok);
    }
    
    return sol;
}

// O(n)
bool resuelveCaso() {
    
    int nEdificios;
    
    cin >> nEdificios;
    
    //Fin de entrada de casos
    if (nEdificios == 0){
        return false;
    }
    //Para los demas casos...
    else{
        
        vector<Edificio> vEdicios(nEdificios);
        
        for(int i = 0; i < nEdificios; i++){
            
            cin >> vEdicios[i].empieza;
            cin >> vEdicios[i].termina;
            
        }
        
        sort(vEdicios.begin(), vEdicios.end());
        
        cout << resuelve(vEdicios) << '\n';
        
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
