// Grupo TAIS36, Ruben y Jaime
// Ejercicio 3
// Obtenemos numero de lineas del parrafo introducimos linea por linea y palabra por palabra (palabras de mas de 2 letras) en el arbol, despues
// imprimimos el resultado de cada caso. El coste de este algoritmo es de O(n).

#include <sstream>
#include <vector>
#include "TreeMap_AVL.h"

using namespace std;

// O(n)
void imprimeArbol(TreeMap<string, vector<int>> arbol){
    
    //Recorreo el arbol en inOrden imprimiendo la clave y los valores del vector valor
    for (auto const& cv : arbol) {
        
        cout << cv.clave << " ";
        
        for (int i = 0; i < cv.valor.size(); i++){
        
            cout << cv.valor[i] << " ";
        }
        
        cout << '\n';
    }
    
    cout << "----" << '\n';
}

void insertaLinea(int nlinea, TreeMap<string, vector<int>> &arbol){
    
    string linea, palabra;
    vector<int> parrafos(nlinea);
    
    //Obtenemos la linea
    getline(cin, linea);
    
    //Transformamos a minuscula
    transform(linea.begin(), linea.end(), linea.begin(), ::tolower);
    
    stringstream ss(linea);
    
    //Avanzamos palabra por palabra en la linea hasta el final
    while (ss >> palabra) {
        
        
        //Comprobamos que la palabra contenga mas de dos letras
        if(palabra.size() > 2){
            
            //Comprobamos si el arbol ya tiene la palabra
            if(arbol.contains(palabra)){
                
                //Comprobamos si la palabra ya ha sido leida en esa linea
                if(arbol.at(palabra)[nlinea - 1] != nlinea){
                    
                    //Insertamos la palabra pero actualizando el vector con la nueva linea
                    parrafos = arbol.at(palabra);
                    parrafos.push_back(nlinea);
                    
                    arbol.insert(palabra, parrafos);
                }
            }
            else { //Si no, es una palabra nueva y hay que insertarla
                
                parrafos.clear();
                parrafos.insert(parrafos.begin(), nlinea);
                
                arbol.insert(palabra, parrafos);
            }
        }
    }
}

// O(n)
void resuelveCaso(int numLineas){
    
    TreeMap<string, vector<int>> arbol;
    
    //Inserta una linea del parrafo en el arbol
    for (int i = 0; i < numLineas; ++i){
        insertaLinea(i + 1, arbol);
    }
    
    imprimeArbol(arbol);
}

int main() {
    
    int num = -1;
    
    cin >> num;
    cin.ignore();
    
    do{
        resuelveCaso(num);
        cin >> num;
        cin.ignore();
        
    }while (num != 0);
        
    return 0;
}
