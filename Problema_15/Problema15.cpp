// Grupo TAIS36, Ruben y Jaime
// Ejercicio 15
// Comentario y coste... ?

#include <iostream>
#include <fstream>

#include "Matriz.h"
#include "ConjuntosDisjuntos.h"


using namespace std;

class CjtoDisjSize : public ConjuntosDisjuntos {
public:
    CjtoDisjSize(size_t N) : ConjuntosDisjuntos(N) {}
    int tam(size_t p) const {
        return -id[buscar(p)];
    }
};

//Dada una coordenada traduce esta a su correspondiente posicion en el array de conjuntos
int traduce(int f, int c){
    
    return (((f * 10) + c) - (2 * f));
}

//Dada una cordenada busca manchas adyacentes para unir conjuntos
void buscarAdyacentes(const Matriz<int> &mapa, ConjuntosDisjuntos &cd, int fila, int columna, int const nFilas, int const nColumnas){

    int incrFilas[] = { -1, 0, 1 };
    
    int incrColumnas[] = { -1, 0, 1 };
    
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            
            if (fila + incrFilas[i] >= 0 && // Comprobamos que no nos salimos de la matriz por la izquierda
                fila + incrFilas[i] < nFilas && // Comprobamos que no nos salimos de la matriz por la derecha
                columna + incrColumnas[j] >= 0 && // Comprobamos que no nos salimos de la matriz por arriba
                columna + incrColumnas[j] < nColumnas) // Comprobamos que no nos salimos de la matriz por la abajo
            {
                
                if (mapa.at(fila + incrFilas[i], columna + incrColumnas[j]) == 1){
                    
                    cd.unir(traduce(fila + incrFilas[i], columna + incrColumnas[j]), traduce(fila, columna)) ;
                }
            }
        }
    }

}

//Dada una matriz y una coordenada de esta busca una mancha de petroleo en su totalidad y crea un conjunto de esta de forma recursiva.
void buscarMancha(int fila, int columna, int const nFilas, int const nColumnas, const Matriz<int> &mapa, Matriz<int> &mapaAux, int &tamanio,  ConjuntosDisjuntos &cd){
    
    int incrFilas[] = { -1, 0, 1 };
    
    int incrColumnas[] = { -1, 0, 1 };
    
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            
            if (fila + incrFilas[i] >= 0 && // Comprobamos que no nos salimos de la matriz por la izquierda
                fila + incrFilas[i] < nFilas && // Comprobamos que no nos salimos de la matriz por la derecha
                columna + incrColumnas[j] >= 0 && // Comprobamos que no nos salimos de la matriz por arriba
                columna + incrColumnas[j] < nColumnas) // Comprobamos que no nos salimos de la matriz por la abajo
            {
                
                //Si esa posicion contiene petroleo la limpiamos, contabilizamos, saltamos a ella y comprobamos sus adyacentes de nuevo
                if (mapaAux.at(fila + incrFilas[i], columna + incrColumnas[j]) == 1){
                    
                    mapaAux.at(fila + incrFilas[i], columna + incrColumnas[j]) = 0;
                    
                    tamanio++;
                    
                    cd.unir(traduce(fila + incrFilas[i], columna + incrColumnas[j]), traduce(fila, columna)) ;
                        
                    buscarMancha(fila + incrFilas[i], columna + incrColumnas[j], nFilas, nColumnas, mapa, mapaAux, tamanio, cd);
                }
            }
        }
    }
}

//Recorre la matriz en busqueda de las manchas, devuelve el tamanio de la mancha mas grande
int mapaToConjunto(const Matriz<int> &mapa, int const nFilas, int const nColumnas, ConjuntosDisjuntos &cd){
    
    //Copiamos el mapa a uno auxiliar que manipularemos
    Matriz<int> mapaAux = mapa;
    
    int manchaMax = 0, manchaAux = 0;
    
    //Comprobamos manchas
    for(int f = 0; f < nFilas; f++){
        for(int c = 0; c < nColumnas; c++){
            
            if(mapaAux.at(f, c) == 1){
                
                buscarMancha(f, c, nFilas, nColumnas, mapa, mapaAux, manchaAux, cd);
                
                if (manchaAux > manchaMax){
                    manchaMax = manchaAux;
                }
                
                manchaAux = 0;
            }
        }
    }
    return manchaMax;
}
    
//Resuelve un caso
bool resuelveCaso(){
    
    int nFila, nColumna, nuevasManchas;
    
    int filaAux, columnaAux;
    
    cin >> nFila;
    cin >> nColumna;
    
    //Fin de entrada
    if (!cin){
        return false;
    }
    else{
        //Para los demas casos...
        
        char in;
        
        //Creamos y rellenamos la matriz
        Matriz<int> mapa = Matriz<int>(nFila, nColumna, 0);
        
        for(int f = 0; f < nFila; f++){
            
            cin.get();
            
            for(int c = 0; c < nColumna; c++){
                
                in = cin.get();
                
                if(in == '#'){
                    
                    mapa.at(f, c) = 1;
                }
            }
        }
        
        cin >> nuevasManchas;
        
        //Creamos los conjuntos
        CjtoDisjSize cd = CjtoDisjSize(nFila * nColumna);
        
        int tamanioMax = mapaToConjunto(mapa, nFila, nColumna, cd);
        
        cout << tamanioMax << " ";
        
        //Introducimos las nuevas manchas y comprobamos si se unen conjuntos
        for(int i = 0; i < nuevasManchas; i++){
            
            cin >> filaAux;
            cin >> columnaAux;
            
            mapa.at(filaAux - 1, columnaAux - 1) = 1;
            
            buscarAdyacentes(mapa, cd, filaAux - 1, columnaAux - 1, nFila, nColumna);
            
            int aux = cd.tam(traduce(filaAux - 1, columnaAux - 1));
            
            //Actualizamos el valor de la mancha mas grande
            if(aux > tamanioMax)
                tamanioMax = aux;
            
            cout << tamanioMax << " ";
            
        }
        
        cout << '\n';
        
        return true;
    }
    
}

int main(int argc, const char * argv[]) {
    
    // Ajustes para que cin extraiga directamente de un fichero
    //    #ifndef DOMJUDGE
    //        ifstream in("casos.txt");
    //        auto cinbuf = cin.rdbuf(in.rdbuf());
    //    #endif
    
    while (resuelveCaso());
    
    // Para dejar todo como estaba al principio
    //    #ifndef DOMJUDGE
    //        cin.rdbuf(cinbuf);
    //        system("PAUSE");
    //    #endif
    
    return 0;
}
