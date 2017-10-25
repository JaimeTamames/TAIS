

#ifndef BIPARTITO_H_
#define BIPARTITO_H_

#include "Grafo.h"


class Bipartito
{
public:
    Bipartito(Grafo const& g):marked(g.V(),false), esbipar(true),colores(g.V(),false){
        
        for (int i = 0; i < g.V(); i++)
        {
            if(!marked[i])
                dfs(g, i, true);
        }
        
        
    }
    bool esBipartito() {
        
        return esbipar;
    }
    
    
private:
    
    std::vector<bool> marked;
    std::vector<bool> colores;
    bool esbipar;
    
    void dfs(Grafo const& g, int v,bool color) {
        
        marked[v] = true;
        colores[v] = color;
        if (esbipar) {
            
            for (auto w : g.adj(v)) {
                
                if (!marked[w]) {
                    dfs(g, w, !color);
                }
                else if (colores[w] == colores[v]) {
                    esbipar = false;
                    
                }
                
            }
        }
    }
};

#endif 



