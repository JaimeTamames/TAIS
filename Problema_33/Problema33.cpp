// Grupo TAIS36, Ruben y Jaime
// Ejercicio 33
// Al introducir las personas se almacenan en un array y se devuelve el numero que se le ha asignado, si ya esta en el array devuelve su valor, al
// tener un numero para cada persona se almacena en la matriz la relacion entre ambos con coste 1 entre los dos. Despues se calcula el camino
// minimo entre cada par de vertices. Para mostrar el resultado se examina la matriz que almacena las distancias entre cada par de vertices del
// grafo, se devuelve el valor maximo, si este es "ininito" la red estara desconectada.
// El coste del algoritmo de Floid es O(n^3)

#include <iostream>
#include <fstream>
#include <vector>
#include "Matriz.h"


using namespace std;

// Coste O(n^3)
void resuelve(Matriz<int> const& grafo, Matriz<int> & C, Matriz<size_t> & camino){

    size_t n = grafo.numfils() - 1;
    // inicialización
    C = grafo;
    camino = Matriz<size_t>(n+1,n+1,0);
    // actualizaciones de la matriz
    for (size_t k = 1; k <= n; ++k)
        for (size_t i = 1; i <= n; ++i)
            for (size_t j = 1; j <= n; ++j) {
                
                int temp = C[i][k] + C[k][j];
                
                if (temp < C[i][j]) { // es mejor pasar por k
                    
                    C[i][j] = temp;
                    camino[i][j] = k;
                }
            }
}

// Convierte las personas en numeros de vertice y devuelve su valor
int numeraPersonas(string persona, vector<string>& vPersona, vector<int>& vNumero){

    int num = 1;
    bool ok = false;
    
    while(!ok){
    
        // Devuelve numero de vertice de la persona
        if(vPersona[num] == persona){
        
            ok = true;
        }
        
        // Ingresa la persona, le asigna un valor de vertice y lo devuelve
        if(vNumero[num] == -1){
        
            vPersona[num] = persona;
            vNumero[num] = num;
            
            ok = true;
        }
        
        num++;
    }
    
    return num - 1;
}

//
bool resuelveCaso() {
    
    int nPersonas, nRelaciones;
    
    cin >> nPersonas;
    cin >> nRelaciones;
    
    //Fin de entrada de casos
    if (!cin){
        return false;
    }
    //Para los demas casos...
    else{
        
        // Inicializamos el grafo con coste infinito
        Matriz<int> grafo(nPersonas + 1, nPersonas + 1, 1000000000);
        
        // Ponemos a 0 el coste de cada vertice consigo mismo
        for(size_t i = 0; i <= nPersonas; i++){
        
            grafo[i][i] = 0;
        }
        
        vector<string> vPersona(nPersonas + 1);
        vector<int> vNumero(nPersonas + 1, -1);
        
        string persona1, persona2;
        
        int p1, p2;
        
        // Rellenamos el coste que siempre sera 1 en las relaciones conocidas entre los vertices
        for(int j = 0; j < nRelaciones; j++){
        
            cin >> persona1;
            cin >> persona2;
            
            p1 = numeraPersonas(persona1, vPersona, vNumero);
            p2 = numeraPersonas(persona2, vPersona, vNumero);
            
            grafo[p1][p2] = 1;
            grafo[p2][p1] = 1;
            
        }
        
        Matriz<int> C(0,0);
        Matriz<size_t> camino(0,0);
        resuelve(grafo, C, camino);
        
        int j = 2, aux = 2, sol = 0;
        
        // Obtiene la solucion final
        for(int i = 1; i < nPersonas + 1; i++){
            for(j; j < nPersonas + 1; j++){
                
                if(C[i][j] > sol){
                
                    sol = C[i][j];
                }
            }
            
            aux++;
            j = aux;
        }

        // Muestra solucion por pantalla
        if(sol == 1000000000){
            
            cout << "DESCONECTADA" << "\n";
        }else{
        
            cout << sol << "\n";
        }
        
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
