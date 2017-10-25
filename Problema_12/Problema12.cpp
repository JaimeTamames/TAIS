// Grupo TAIS36, Ruben y Jaime
// Recorreremos todas las operaciones posible hasta encontrar el destino, simulando que recorremos un Grafo en anchura
// En realidad no usamos ning˙n grafo porque no es necesario ya que teniendo las operaciones que se generan en cada vertice
// sabemos cual son los tres vertices que tienen arista desde el vÈrtice actual

#include <algorithm>
#include <iostream>
#include <fstream>
#include "Grafo.h"


class comprobarResultado
{
private:
    std::vector<bool> _marked;     // marked[v] = hay camino s-v?
    std::vector<size_t> distTo;   // distTo[v] = n˙mero de aristas en el camino s-v m·s corto
    bool encontrado = false;
    int contador = 0;
    int nivel = 0;
    
    
    void bfs(int inicio, int destino) {
        
        // Enteros que usaremos para almacenar el valor de la operaciones
        int o;
        int o1;
        int o2;
        std::queue<int> q;							// cola de vertices que estamos visitando
        distTo[inicio] = 0;							// distancia en la posicion del vertice del que partimos es 0
        _marked[inicio] = true;						// marcamos a true el vertice de inicio
        q.push(inicio);								// agregamos el vertice del que partimos a la cola
        while (!encontrado) {						// Mientras no hayamos encontrado el destino
            
            nivel = q.front();
            o = op(q.front());
            o1 = op2(q.front());
            o2 = op3(q.front());
            
            
            if (!_marked[o]) {								// si el vertice que visitamos no est· marcado
                distTo[o] = distTo[nivel] + 1;				// Aumentamos la distancia en un nivel
                _marked[o] = true;							// Marcamos la operaciÛn como camino visitado
                if (o == destino)encontrado = true;			// Comprobamos si hemos encontraod el destino
                
                q.push(o);									// AÒadimos el vÈrtice a la cola, de forma que lo usaremos mas adelante para seguir generando soluciones
            }
            if (!_marked[o1] && !encontrado) {
                distTo[o1] = distTo[nivel] + 1;
                _marked[o1] = true;
                if (o1 == destino)encontrado = true;
                
                q.push(o1);
                
            }
            
            if (!_marked[o2] && !encontrado) {
                distTo[o2] = distTo[nivel] + 1;
                _marked[o2] = true;
                if (o2 == destino)encontrado = true;
                
                q.push(o2);
                
            }
            q.pop();										// Sacamos el VÈrtice de la cola ya que hemos visitado todas su posibilidades
        }
        
        contador = distTo[destino];									// Una vez salimos del While es porque hemos encontrado el destino
        
        
    }
    
public:
    
    comprobarResultado(int ini, int des) : _marked(10000, false), distTo(10000) {
        
        bfs(ini, des);
        
    }
    
    
    
    int op(int a){ //op +1
        
        a = (a+1) % 10000;     // AÒadimos a todas la operaciones el "%10000" para no salirnos del rango preestablecido por el problema
        
        return a;
        
    }
    
    int op2(int a){//op *2
        
        return (a * 2) %10000;
        
    }
    
    int op3(int a){//op /3
        
        return (a / 3) %10000;
        
    }
    
    
    int caminoMasCorto(){
        
        return contador;
        
    }
    
};


//Resuelve un caso de prueba

//O(V + E)  V el numero de vertices que generamos durante las operaciones, E el numero de Aristas que recorremos hasta llegar a la soluciÛn
bool resuelveCaso() {
    
    int inicio = 0;
    int destino = 0;
    
    std::cin >> inicio;
    std::cin >> destino;
    
    if (!std::cin){
        return false;
    }
    
    if (inicio == destino){
        
        std::cout << "0" << std::endl;
    }
    else {
        
        comprobarResultado CR(inicio, destino);
        
        
        std::cout << CR.caminoMasCorto() << std::endl;
    }
    
    return true;
}

int main() {
    
    
    // ajustes para que cin extraiga directamente de un fichero
    #ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif
    
    while (resuelveCaso());
    
    #ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
    #endif
    
    
    return 0;
}
