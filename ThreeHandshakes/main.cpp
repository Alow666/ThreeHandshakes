#include <iostream>
#include "Graph.h"

int main() {
	setlocale(LC_ALL, "rus");

	Graph a;
	a.addVertex("Dima");
	a.addVertex("Igor");
	a.addVertex("Sasha");
	a.addVertex("Misha");
	a.addVertex("Andrey");

	a.addVertex("Anton");
	a.addVertex("Denis");
	a.addVertex("Artem");
	a.addVertex("Stas");


	a.addEdge("Dima", "Igor");
	a.addEdge("Igor", "Sasha");
	a.addEdge("Sasha", "Misha");
	a.addEdge("Misha", "Andrey");

	a.addEdge("Dima", "Anton");
	a.addEdge("Anton", "Denis");
	a.addEdge("Denis", "Artem");
	a.addEdge("Artem", "Stas");



	a.threeHandshakes("Dima");


	return 0;
}