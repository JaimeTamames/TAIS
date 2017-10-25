// Grupo TAIS36, Ruben y Jaime
// Creamos un grafo dirigido valorado con los costes de la carga de la pagina y la llegada a la siguiente
// usamos el metodo dijkstra para sacar el camino mas eficiente


#include <algorithm>
#include <iostream>
#include <fstream>
#include "IndexPQ.h"
#include "GrafoDirigidoValorado.h"
using namespace std;

class DijkstraSP
{
private:
    
    vector<int> distTo;
    IndexPQ<int> pq;
    GrafoDirigidoValorado<int> _G;
    bool paginaConectada = false;
    int ult;
    
    void relax(AristaDirigida<int> &e){
        
        
        int v = e.from();
        int w = e.to();
        
        if (w == ult)paginaConectada = true;
        
        if (distTo[w] > (distTo[v] + e.valor()))
        {
            
            
            distTo[w] = distTo[v] + e.valor();
            
            pq.update(w, distTo[w]);
            
        }
        
    }
public:
    
    DijkstraSP(GrafoDirigidoValorado<int> &g, int s, int ultimo) : _G{ g }, distTo(g.V(), 100000), pq(g.V()), ult{ ultimo }
    {
        
        
        distTo[0] = 0;
        pq.push(s, 0);
        
        while (!pq.empty()){
            
            int v = pq.top().elem;
            pq.pop();
            for (AristaDirigida<int> e : _G.adj(v)){
                
                relax(e);
                
            }
            
        }
        
        
    }
    
    // Muestra la suma de los costes del camino con coste minimo o la salida en caso de que no existan puentes sufucientes
    int resultado(){
        
        if (!paginaConectada)
            cout << "IMPOSIBLE" << '\n';
        else
        {
            
            int res = distTo[ult];
            
            
            return res;
        }
        
        return -1;
        
        
    }
    
    
    
};





//Resuelve un caso de prueba

//O(V + E)  V el numero de vertices que generamos durante las operaciones, E el numero de Aristas que recorremos hasta llegar a la soluciÛn
bool resuelveCaso() {
    
    int nPaginas = 0;
    int enlaces = 0;
    
    
    std::cin >> nPaginas;
    
    if (nPaginas == 0){
        return false;
    }
    
    // Vamos a coger el tiempo de carga de todas la paginas
    std::vector<int> cargas(nPaginas);
    
    for (int i = 0; i < nPaginas; i++){
        
        std::cin >> cargas[i];
        
    }
    
    // Ahora cogemos el numero de enlace que tenemos
    
    std::cin >> enlaces;
    
    // Generamos todos los enlaces con los correspondientes costes en un grafo dirigido valorado
    
    GrafoDirigidoValorado<int> g = GrafoDirigidoValorado<int>(nPaginas);
    
    for (int i = 0; i < enlaces; i++){
        
        int a;
        int b;
        int coste;
        
        std::cin >> a;
        std::cin >> b;
        std::cin >> coste;
        
        coste = coste + cargas[(a - 1)];
        
        if (a != b){
            AristaDirigida<int> arista((a - 1), (b - 1), coste);  // El coste de ir de la pagina A a B, es el tiempo de carga de A mas el tiempo de clicar en la pagina B
            
            g.ponArista(arista);
        }
        
        
    }
    
    DijkstraSP CR(g, 0, (nPaginas-1));
    
    int t = CR.resultado();
    
    if (t != -1){  // Significa que es posible llegar a la pagina
        
        cout << t + cargas[nPaginas - 1] << endl;
        
        
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


