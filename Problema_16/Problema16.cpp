// Grupo TAIS36, Ruben y Jaime
// Ejercicio 16
// Generamos un grafo Valorado con las islas como vetices, y todos los puentes posibles como aristas valoradas
// Recorremos el grafo con el algoritmo de Prim extrayendo el menos coste con el que conectar todas las islas , si es posible

#include <iostream>
#include <fstream>

#include "GrafoValorado.h"
#include "IndexPQ.h"

using namespace std;

class comprobarPuentes
{
private:
    
    const GrafoValorado<int> _G;
    
    vector<Arista<int>> arista;     // Array de aristas para recorrer adyacentes a un vertice
    vector<int> distancia;          // Array de coste entre vertice origen
    vector<bool> visitado;			// Array de vertice visitado
    IndexPQ<int> pq;                // Lista prioritaria de adyacentes y su coste
    
    void visita(const GrafoValorado<int> &G, int vActual){
        
        visitado[vActual] = true;
        
        for(Arista<int> a : _G.adj(vActual)){
            
            auto w = a.otro(vActual);
            if(visitado[w])
                continue;
            if(a.valor() < distancia[w]){
                
                arista[w] = a;
                distancia[w] = a.valor();
                pq.update(w, distancia[w]);
                
            }
        }
    }
    
    // Muestra la suma de los costes del camino con coste minimo o la salida en caso de que no existan puentes sufucientes
    void resultado(){
        
        bool faltaPuente = false;
        
        int res = 0;
        
        for(size_t i = 0; i < _G.V(); i++){
            res = res + distancia[i];
            
            if(!visitado[i])
                faltaPuente = true;
        }
        
        if(faltaPuente)
            cout << "No hay puentes suficientes" << '\n';
        else
            cout << res << '\n';
        
    }
    
public:
    
    comprobarPuentes(const GrafoValorado<int> &g) : _G{ g }, arista(g.V()), distancia(g.V(), 1000000000), visitado(g.V(), false), pq(g.V())
    {
        
        distancia[0] = 0;
        pq.push(0, 0);          // Inicializamos pq distancia 0, coste 0 (ya que estamos en el mismo vertice).
        
        while (!pq.empty()){
            
            // Sacamos el adyacente mas prioritario de la lista para visitarlo
            auto v = pq.top().elem;
            pq.pop();
            visita(_G, v);
        }
        
        resultado();
    }
    
};

//E + Log E
bool resuelveCaso() {
    
    int nIslas, nPuentes;
    
    cin >> nIslas;
    cin >> nPuentes;
    
    //Fin de entrada
    if (!cin){
        return false;
    }
    else{
        //Para los demas casos...
        
        int isla1, isla2, coste;
        
        //Construimos y rellenamos el grafo
        GrafoValorado<int> g = GrafoValorado<int>(nIslas);
        
        for(int i = 0; i < nPuentes; i++){
            
            cin >> isla1;
            cin >> isla2;
            cin >> coste;
            
            Arista<int> arista = Arista<int>((isla1 - 1), (isla2 - 1), coste);
            
            g.ponArista(arista);
        }
        
        comprobarPuentes ca = comprobarPuentes(g);
        
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
