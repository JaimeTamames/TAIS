// Grupo TAIS36, Ruben y Jaime
// creamos una estructura con el periodo en el que se repetir· cada id, y los segundos
// siguientes en los que se repetir·, y los insertamos en una cola que se ordenar· por los segundos
// de las estructuras que componen la cola


#include <algorithm>
#include <iostream>
#include "PriorityQueue.h"


//Estructura Base del problema

typedef struct {
    
    int id;
    int segs;
    int periodo;
    
} tstructura;


//O(n)
//Resuelve cada caso de prueba

void resuelveCaso(PriorityQueue<tstructura> &cola) {
    
    int numCasos = 0;
    int contador = 0;
    int periodo = 0;
    
    std::cin >> numCasos;
    
    // Mientras el contador no imprima las vecs necesarias el periodo seguira corriendo
    while(contador < numCasos){
        
        while (periodo == cola.top().segs && contador < numCasos){
            
            // Imprimimos el id
            std::cout << cola.top().id << std::endl;
            
            // Variables para actualizar la prioridad en la cola
            tstructura user;
            user.id = cola.top().id;
            user.segs = cola.top().periodo + periodo;
            user.periodo = cola.top().periodo;
            
            // Eliminamos el elemento de la cola
            cola.pop();
            
            // metemos el elemento con el nuevo periodo
            cola.push(user);
            
            // Contamos una impresion
            contador++;
            
        }
        
        // Actualizamos el periodo
        periodo++;
        
    }
    
    
}

int main() {
    
    
    int numCasos = -1;
    tstructura user;
    std::cin >> numCasos;
    
    while (numCasos != 0){
        
        PriorityQueue<tstructura> cola;
        int i = 0;
        
        while (i < numCasos){
            
            std::cin >> user.id;
            std::cin >> user.segs;
            user.periodo = user.segs;
            
            cola.push(user);
            
            i++;
            
        }
        
        resuelveCaso(cola);
        
        std::cout << "----" << std::endl;
        
        std::cin >> numCasos;
        
    }
    
    return 0;
}


bool operator<(tstructura a, tstructura b){
    
    int bolean = true;
    
    if (a.segs < b.segs){
        
        return bolean;
        
    } else {
        
        bolean = false;
    }
    
    if (a.segs == b.segs){
        
        if (a.id < b.id)
            bolean = true;
        else
            bolean = false;
    }
    
    return bolean;
    
}
