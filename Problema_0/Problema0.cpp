// Grupo XYZ, Rub�n y Jaime

// recorremos el arbol de forma recursiva desde los hijos izquierdos a los derechos,
// qued�ndonos con la altura m�xima despues de todo el recorrido

#include <algorithm>
#include <iostream>
#include "BinTree.h"

// leemos el arbol

BinTree<char> leerArbol() {
	char raiz;
	std::cin >> raiz;
	if (raiz == '.') { // es vac�o
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol();
		auto dr = leerArbol();
		return{ iz, raiz, dr };
	}
}

// calculamos su altura en el n�mero N de nodos del �rbol, O(N)

int altura(BinTree<char> const& arbol){
	if (arbol.empty()) {
		return 0;
	}
	else {
		return 1 + std::max(altura(arbol.left()), altura(arbol.right()));
	}
}

// resuelve un caso de prueba

void resuelveCaso() {
	auto arbol = leerArbol();
	int sol = altura(arbol);
	std::cout << sol << "\n";
}

int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
