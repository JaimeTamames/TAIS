// Grupo TAIS36, Ruben y Jaime
// El problema recoge los numeros introducidos por el usuario y los va introduciendo en dos colas
// de forma que ambas queden ordenadas de menos a mayor si las unimos, llevamos una cola de menos a mayor
// y otra de mayor a menor, asi conseguimos obtener facilmente los elementos que deberian estar en el medio
// del vector de numeros introducidos y calcular la mediana.

#include <algorithm>
#include <iostream>
#include "PriorityQueue.h"

//O(log n)
int medianaPar(PriorityQueue<int, std::greater<int>> &cola1, PriorityQueue<int> &cola2){
    
    
    int num1;
    int num2;
    int mediana;
    
    num1 = cola1.top();
    num2 = cola2.top();
    
    // Ahora que tenemos los dos numero sde la mediana, calculamos la media y multiplicaos por 2
    
    mediana = num1 + num2;
    
    return mediana;
}


//O(log n)
int medianaImpar(PriorityQueue<int, std::greater<int>> &cola){
    
    int num1;
    int mediana;
    
    num1 = cola.top();
    
    // Ahora que tenemos el numero de la mediana, multiplicaos por 2
    
    mediana = num1 * 2;
    
    return mediana;
}

//O(log n)
int medianaImpar2(PriorityQueue<int, std::less<int>> &cola){
    
    int num1;
    int mediana;
    
    num1 = cola.top();
    
    // Ahora que tenemos el numero de la mediana, multiplicaos por 2
    
    mediana = num1 * 2;
    
    return mediana;
}

//Resuelve un caso de prueba

//O(n)
void resuelveCaso(PriorityQueue<int, std::less<int>> &cola2, PriorityQueue<int, std::greater<int>> &cola1) {
    
    // Distingimos si el tamaÒo de la cola es par o impar
    if (cola1.size() == cola2.size()){
        
        std::cout << medianaPar(cola1, cola2) << " ";
        
    }
    else if (cola1.size() > cola2.size()){
        
        std::cout << medianaImpar(cola1) << " ";
        
    }
    else {
        
        std::cout << medianaImpar2(cola2) << " ";
        
    }
    
}

//O(n)
void ordenarColas(PriorityQueue<int, std::less<int>> &cola2, PriorityQueue<int, std::greater<int>> &cola1){
    
    while (cola1.size() < cola2.size()){
        
        cola1.push(cola2.top());
        cola2.pop();
        
    }
    
    if (cola2.size() < cola1.size() - 1){
        
        while (cola2.size() < cola1.size()){
            
            cola2.push(cola1.top());
            cola1.pop();
            
        }
        
    }
    
    
    
}

int main() {
    
    
    int numCasos = -1;
    std::cin >> numCasos;
    int num;
    
    // Mientras no se introduzca un 0 el programa sigue
    while (numCasos != 0){
        
        int i = 0;
        PriorityQueue<int, std::less<int>> cola2;
        PriorityQueue<int, std::greater<int>> cola1;
        
        // Leer· todos los numeros que se introduzcan, y hayar· la Mediana seg˙n van incrementando las colas
        while (i < numCasos && numCasos != 0){
            
            std::cin >> num;
            
            if (cola1.size() == 0){
                
                cola1.push(num);
                
            }
            
            else if (cola2.size() == 0){
                
                if (cola1.top() > num){ //si el numero de la izq es mayor que el de la derecha ordenamos
                    
                    cola2.push(cola1.top());
                    cola1.pop();
                    cola1.push(num);
                    
                }
                else {
                    
                    cola2.push(num);
                    
                }
                
            }
            else {
                
                if (num > cola1.top()) {
                    
                    cola2.push(num);
                    
                }
                
                else {
                    
                    cola1.push(num);
                    
                }
            }
            
            ordenarColas(cola2, cola1);
            
            resuelveCaso(cola2, cola1);
            
            i++;
            
        }
        
        std::cout << std::endl;
        
        std::cin >> numCasos;
        
    }
    
    return 0;
}
