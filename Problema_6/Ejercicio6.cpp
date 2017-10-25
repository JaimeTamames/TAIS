// Grupo TAIS36, Jaime
// Ejercicio 6

#include <iostream>
#include <fstream>

#include "PriorityQueue.h"
#include "ColaUrgencias.h"

using namespace std;

struct Paciente{
    
    int gravedad;
    string nombre;
    
    bool operator > (const Paciente& str) const
    {
        return (gravedad > str.gravedad);
    }
    
};

//
bool resuelveCaso() {
    
    PriorityQueue<Tpar, ColaUrgencias> cola;
    Tpar p;
    
    int nEventos;
    
    char accion;
    
    cin >> nEventos;
    
    //Si llegamos al caso 0 salimos
    if (nEventos == 0)
        return false;
    
    //Para los demas casos...
    for(int i = 0; i < nEventos; i++){
        
        cin >> accion;
        
        //Ingreso paciente
        if(accion == 'I'){
            
            cin >> p.nombre;
            cin >> p.gravedad;
            p.llegada = i;
        
            cola.push(p);
        }
        //Alta paciente
        else{
           
            if(!cola.empty()){

                cola.pop(p);
                
                cout << p.nombre << endl;
            }
        }
    }
    
    cout << "----" << endl;
    
    return true;
}

int main(int argc, const char * argv[]) {
    
    while (resuelveCaso());
    
    return 0;
}
