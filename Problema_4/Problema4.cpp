// Grupo TAIS36, Ruben y Jaime
// vamos agregando capitulos al arbol con el instante en el que se emite
// y si ya ha sido emitido cogemos el instante en el que se emitiÛ y si ha sido el ultimo capitulo emitido
// calcularemos la diferencia  y asÌ sacaremos un contador final con el segmento de capitulos distintos


#include <algorithm>
#include <iostream>
#include "TreeMap_AVL.h"


//Resuelve un caso de prueba

//O(n)

void resuelveCaso() {
    
    int numCapitulos;
    std::cin >> numCapitulos;
    TreeMap<int, int> arbol;  // el arbol contendr· el capitulo y el dia que se emitiÛ y si ya est· los dÌas que hace que se repitiÛ
    int capitulo = 0;
    int contadortotal = 0;
    int contador = 0;
    int antnumcomprobado = 0;
    
    for (int i = 1; i <= numCapitulos; i++){
        
        std::cin >> capitulo;
        
        if (arbol.contains(capitulo)){
            
            int aux = arbol.at(capitulo);
            
            if (aux > antnumcomprobado){ //si el numero que nos encontramos esta por detr·s del anterior repetido lo ignoramos
                
                antnumcomprobado = aux;
                
                int diff = i - aux;
                
                contador = diff;
                
                if (contadortotal < diff)contadortotal = diff;
            }
            else {
                
                contador++;
                if (contadortotal < contador) contadortotal = contador;
                
            }
            
            
            
        }
        else {
            
            contador++;
            if (contadortotal < contador) contadortotal = contador;
            
        }
        
        arbol.insert(capitulo, i);
        
    }
    
    
    std::cout << contadortotal << std::endl;
    
}

int main() {
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    //system("PAUSE");
    return 0;
}
