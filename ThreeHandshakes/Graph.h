#pragma once
#include <iostream>
#include <vector>

#define SIZE 20

class Graph {
public:
    Graph();
    // добавление вершины
    void addVertex(std::string newName);
    // добавление ребра
    void addEdge(std::string firstName, std::string secondName);
    // удаление вершины
    void delVertex(std::string _name);
    // удаление ребра
    void delEdge(std::string firstName, std::string secondName);
    //поиск трех рукопожатий
    void threeHandshakes(std::string _name);

private:
    //индекс имени 
    int getIndex(std::string _name);
    bool edgeExists(std::string firstName, std::string secondName);
    bool vertexExists(std::string _name);
    void depthInner(std::string current, bool visited[], int a);

    int matrix[SIZE][SIZE]; // матрица смежности

    int vertexCount; // количество добавленных вершин
    std::string vertexName[SIZE] = {"noName"};
};