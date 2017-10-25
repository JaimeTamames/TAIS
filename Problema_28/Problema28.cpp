// Grupo TAIS36, Ruben y Jaime
// resolvemos el problema utilizando un algoritmo similar al de las trasparencias con el que resolucionar el prblema de la mochila de AlÌ Bab·

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include "Matriz.h"

using namespace std;

void cofres_pd(vector<int>const &profundidad, vector<int>const &valor, int tBotella, int &oroTotal, vector<bool> &cuales, int &numCofres){
    
    size_t n = profundidad.size() - 1;
    Matriz<int> tesoro(n + 1, tBotella + 1, 0);
    
    //rellenamos la matriz
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= tBotella; ++j){
            
            if (profundidad[i] > j)
                tesoro[i][j] = tesoro[i - 1][j];
            else
                tesoro[i][j] = max(tesoro[i - 1][j], tesoro[i - 1][j - profundidad[i]] + valor[i]);
        }
    }
    
    oroTotal = tesoro[n][tBotella];
    
    //Calculamos los cofres que podemos coger
    
    int resto = tBotella;
    
    for (size_t i = n; i >= 1; --i){
        
        if (tesoro[i][resto] == tesoro[i - 1][resto])
        {
            
            //no cogemos el objeto
            cuales[i] = false;
        }
        else
        {
            //si cogemos el objeto
            cuales[i] = true;
            numCofres++;
            resto = resto - profundidad[i];
        }
    }
}

//Resuelve un caso de prueba
//coste O(n * tBotella) lineal
bool resuelveCaso() {
    
    int tBotella = 0;
    int cofres = 0;
    
    
    cin >> tBotella;
    cin >> cofres;
    
    if (!cin){
        return false;
    }
    
    vector<int> profundidad(cofres+1);
    vector<int> valor(cofres+1);
    
    for (int i = 1; i <= cofres; i++){
        
        cin >> profundidad[i];
        cin >> valor[i];
        
    }
    
    for (int i = 1; i <= cofres; i++){
        
        profundidad[i] = 3 * profundidad[i]; //multiplicamos por 3 el tiempo que invertira la botella de oxigeno
        
    }
    
    //Resolvemos el problema a traves de una funcion auxiliar
    vector<bool> resultado(cofres+1);
    int oroTotal = 0;
    int numCofres = 0;
    
    cofres_pd(profundidad, valor, tBotella, oroTotal, resultado, numCofres);
    
    if (oroTotal == 0){
        
        cout << 0 << endl;
        cout << 0 << endl;
        cout << "----" << endl;
        
    }
    else {
        
        cout << oroTotal << endl;
        cout << numCofres << endl;
        
        for (int i = 1; i <= cofres; i++){
            
            if (resultado[i])
            {
                cout << (profundidad[i] / 3) << " ";
                cout << valor[i] << endl;
            }			
            
        }
        cout << "----" << endl;
        
    }
    
    return true;
}

int main() {
    
    while (resuelveCaso());
    
    return 0;
}


