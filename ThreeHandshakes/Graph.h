#pragma once
#include <iostream>
#include <vector>

#define SIZE 20

class Graph {
public:
    Graph();
    // ���������� �������
    void addVertex(std::string newName);
    // ���������� �����
    void addEdge(std::string firstName, std::string secondName);
    // �������� �������
    void delVertex(std::string _name);
    // �������� �����
    void delEdge(std::string firstName, std::string secondName);
    //����� ���� �����������
    void threeHandshakes(std::string _name);

private:
    //������ ����� 
    int getIndex(std::string _name);
    bool edgeExists(std::string firstName, std::string secondName);
    bool vertexExists(std::string _name);
    void depthInner(std::string current, bool visited[], int a);

    int matrix[SIZE][SIZE]; // ������� ���������

    int vertexCount; // ���������� ����������� ������
    std::string vertexName[SIZE] = {"noName"};
};