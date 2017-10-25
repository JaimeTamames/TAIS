// Grupo TAIS36, Ruben y Jaime
// Todas las personas seran representadas como vertices de un Grafo, los grupos de amigos seran relacionados entre si
// a traves de aristas entre los vertices, de manera que con un recorrido recursivo de los vertices adyacentes podremos contar
// el numero maximo de amigos.


#include <algorithm>
#include <iostream>
#include "Grafo.h"

using namespace std;

class comprobarAmigos
{
private:
    vector<bool> _marked;
    const Grafo _G;
    int contador = 1;
    int contadorMax = 0;
    
    void dfs(const Grafo &_G, int v)
    {
        _marked[v] = true;
        for (int w : _G.adj(v))
            if (!_marked[w]){
                dfs(_G, w);
                contador++;
            }
    }
    
public:
    
    comprobarAmigos(const Grafo &g) : _G{g}, _marked(g.V(),false) {
        
        int contadorActual = 0;
        
        for (int i = 0; i < _G.V(); i++){
            
            dfs(_G, i);
            contadorActual = contador;
            contador = 1;
            
            if (contadorActual > contadorMax){
                
                contadorMax = contadorActual;
                
            }
        }
    }
    
    int getContadorMax() {
        
        return contadorMax;
        
    }
};

//Resuelve un caso de prueba

//O(V+E) V - numero de personas y E - las relaciones entre ellas
void resuelveCaso() {
    
    size_t v = -1;
    int pares = -1;
    int num1 = -1;
    int num2 = -1;
    int i = 0;
    
    cin >> v;
    cin >> pares;
    
    Grafo g = Grafo(v);
    
    while (i < pares){
        
        cin >> num1;
        cin >> num2;
        
        g.ponArista(num1 - 1, num2 - 1);
        
        i++;
    }
    
    comprobarAmigos ca = comprobarAmigos(g);
    cout << ca.getContadorMax() << endl;
    
}


int main() {
    
    numCasos = -1;
    cin >> numCasos;
    
    // Mientras no se introduzca un 0 el programa sigue
    while (numCasos != 0){
        
        resuelveCaso();
        numCasos--;
        
    }
    
    return 0;
}


