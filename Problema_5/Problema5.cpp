// Grupo TAIS36, Ruben y Jaime
// Ejercicio 5
// Vamos sacando los dos elementos mas prioritarios para sumarlos, el resultado es introducido en la cola de nuevo para su posterior suma.
// El resultado de las sumas se va sumando al acumulado, es decir la solucion.
// El coste de este algoritmo es de O(n).

#include <iostream>
#include <fstream>

#include "PriorityQueue.h"

using namespace std;

//O(n)
long long int resuelve(PriorityQueue<long long int> cola){
    
    long long int op1 = 0, op2 = 0, resultado = 0, sol = 0;
    
    do{
        //Si la cola no esta vacia sacamos el elemento mas prioritario, si no lo igualamos a 0
        if(!cola.empty())
            cola.pop(op1);
        else
            op1 = 0;
        
        //Si la cola no esta vacia sacamos el elemento mas prioritario, si no lo igualamos a 0
        if(!cola.empty())
            cola.pop(op2);
        else
            op2 = 0;
        
        //Sumamos los dos elementos mas prioritarios
        resultado = op1 + op2;
        
        //Si la cola no esta vacia insertamos el resultado en la cola para su posterior suma
        if(!cola.empty())
            cola.push(resultado);
        
        //Sumamos el coste de cada suma a la solucion
        sol += resultado;
        
        //Log
        //cout << op1 << " + " << op2 << " = " << resultado << "   Acum: " << sol << '\n';
        
    }while(!cola.empty());
    
    return sol;
}

//O(n)
bool resuelveCaso() {
    
    PriorityQueue<long long int> cola;
    
    long long int nSumandos, aux;
    
    cin >> nSumandos;
    
    //Si llegamos al caso 0 salimos
    if (nSumandos == 0){
        return false;
    }
    else{
    
        //Para los demas casos...
        //Rellenamos la cola de menor a mayor
        for(int i = 0; i < nSumandos; i++){
            
            cin >> aux;
            cola.push(aux);
        }
        
        //Caso en el que solo hay un solo sumando
        if(cola.size() == 1)
            cout << 0 << '\n';
        else
            cout << resuelve(cola) << '\n';
        
        return true;
    }
}

int main(int argc, const char * argv[]) {
    
    while (resuelveCaso());
    
    return 0;
}
