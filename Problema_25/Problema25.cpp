// Grupo TAIS36, Jaime
// Ejercicio 25

#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>

#include "PriorityQueue.h"

using namespace std;

struct Conferencia{
    
    long long int empieza;
    long long int termina;
    
    bool operator < (const Conferencia& str) const
    {
        return (empieza < str.empieza);
    }
};

unsigned long resuelve(vector<Conferencia> &vConferencias){
    
    PriorityQueue<long long int, less<long long int>> cola;
    cola.push(-1);
    
    for(size_t i = 0; i < vConferencias.size(); i++){
        
        //Si esta conferencia empieza despues de la que primero termina se puede dar en esa sala.
        if(vConferencias[i].empieza >= cola.top()){
        
            cola.pop();
            cola.push(vConferencias[i].termina);
        }
        //Por el contrario necesitara una nueva sala para esta conferencia.
        else{
        
            cola.push(vConferencias[i].termina);
        }
    }
    
    return cola.size();
}


bool resuelveCaso() {
    
    int nConferencias;
    
    cin >> nConferencias;
    
    //Fin de entrada de casos
    if (nConferencias == 0){
        return false;
    }
    //Para los demas casos...
    else{
        
        vector<Conferencia> vConferencias(nConferencias);
        
        for(int i = 0; i < nConferencias; i++){
            
            cin >> vConferencias[i].empieza;
            cin >> vConferencias[i].termina;
            
        }
        
        sort(vConferencias.begin(), vConferencias.end());
        
        cout << resuelve(vConferencias) << endl;
        
        return true;
    }
}

int main(int argc, const char * argv[]) {
    
    while (resuelveCaso());
    
    return 0;
}
