#pragma once

#define SIZE 20

class Graph {
public:
    Graph();
    // добавление вершины
    void addVertex(int vnumber);
    // добавление ребра
    void addEdge(int v1, int v2, int weight);
    // удаление вершины
    void delVertex(int vnumber);
    // удаление ребра
    void delEdge(int v1, int v2);

    friend bool test(const Graph& g);
    void dummy1(int vnumber);
    void dummy2(int v1, int v2);
private:
    bool edgeExists(int v1, int v2);
    bool vertexExists(int v);

    int matrix[SIZE][SIZE]; // матрица смежности

    int vertexes[SIZE]; // хранилище вершин
    int vertexCount; // количество добавленных вершин
};