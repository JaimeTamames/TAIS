// Grupo TAIS36, Ruben y Jaime
// Ejercicio 26
// Coste O(n) o O(nlog n) si tenemos en cuenta que hay que ordenar primero el vector

#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
#include <math.h>

using namespace std;

struct Restaurante{
    
    int empieza;
    int termina;
    
    bool operator < (const Restaurante& str) const
    {
        return (empieza < str.empieza);
    }
};

// Comprueba que el inicio y el final de la calle esten cubiertos. Ademas se recorre el array en busca del edificio que cumpla
// la condicion de empezar antes o en el mismo punto que se ha fijado y que tenga el alcance maximo, cuando se encuentra
// se fija el punto con ese alcance maximo en busqueda de los siguientes edificios.
int resuelve(vector<Restaurante> &vEdicios, int longitudCalle, int nRestaurantes){
    
    int sol = nRestaurantes, punto = 0, max = 0;
    
    bool ok;
    
    //Caso en el que no hay edificios que alcancen el principio de la calle
    if(vEdicios[0].empieza != 0)
        return -1;
    
    for(size_t i = 0; i < vEdicios.size(); i++){
        
        ok = true;
        
        do{
        
            if(vEdicios[i].empieza <= punto){
                
                //Actualizamos restaurante que mas cubre respecto al anterior
                if(vEdicios[i].termina > max)
                    max = vEdicios[i].termina;
                
                //Cuando encontramos una solucion que cubre desde el edificio anterior hasta el final
                if(longitudCalle == max){
                    sol--;
                    return sol;
                }
                
                i++;

            }//Comprobamos que no hay huecos libres entre restaurantes
            else if(vEdicios[i].empieza <= max){

                ok = false;
                sol--;
                punto = max;
                i--;
            }
            else{
            
                return -1;
            }
        
        }while(ok);
    }
    
    //Comprobamos que se cubre hasta el final de la calle
    if(max == longitudCalle)
        return sol;
    else
        return -1;
}

// O(n)
bool resuelveCaso() {
    
    int longitudCalle, nRestaurantes;
    
    cin >> longitudCalle;
    cin >> nRestaurantes;
    
    //Fin de entrada de casos
    if (!cin){
        return false;
    }
    //Para los demas casos...
    else{
        
        vector<Restaurante> vRestaurantes(nRestaurantes);
        
        int auxPos, auxRad;
        
        for(int i = 0; i < nRestaurantes; i++){
            
            cin >> auxPos;
            cin >> auxRad;
            
            if((auxPos - auxRad) < 0)
                vRestaurantes[i].empieza = 0;
            else
                vRestaurantes[i].empieza = (auxPos - auxRad);
            
            if((auxPos + auxRad) > longitudCalle)
                vRestaurantes[i].termina = longitudCalle;
            else
                vRestaurantes[i].termina = (auxPos + auxRad);
            
        }
        
        sort(vRestaurantes.begin(), vRestaurantes.end());
        
        if(nRestaurantes == 0)
            cout << -1 << '\n';
        else
            cout << resuelve(vRestaurantes, longitudCalle, nRestaurantes) << '\n';
        
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
