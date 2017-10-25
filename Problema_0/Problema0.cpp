// Grupo XYZ, Rubén y Jaime

// recorremos el arbol de forma recursiva desde los hijos izquierdos a los derechos,
// quedándonos con la altura máxima despues de todo el recorrido

#include <algorithm>
#include <iostream>
#include "BinTree.h"

// leemos el arbol

BinTree<char> leerArbol() {
	char raiz;
	std::cin >> raiz;
	if (raiz == '.') { // es vacío
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol();
		auto dr = leerArbol();
		return{ iz, raiz, dr };
	}
}

// calculamos su altura en el número N de nodos del árbol, O(N)

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
