#include "Graph.h"

Graph::Graph() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    vertexCount = 0;
}
// ���������� �������
void Graph::addVertex(std::string newName){
    vertexName[vertexCount] = newName;
    vertexCount++;
}
// ���������� �����
void Graph::addEdge(std::string firstName, std::string secondName){
    int v1 = -1, v2 = -1;

    for (int i = 0; i < vertexCount; i++) {
        if (vertexName[i] == firstName) {
            v1 = i;
            break;
        }
    }

    for (int i = 0; i < vertexCount; i++) {
        if (vertexName[i] == secondName) {
            v2 = i;
            break;
        }
    }

    if (v1 == -1 || v2 == -1) return;

    matrix[v1][v2] = 1;
    matrix[v2][v1] = 1;
}
// �������� ������������� �����
bool Graph::edgeExists(std::string firstName, std::string secondName){
    int v1 = -1, v2 = -1;

    for (int i = 0; i < vertexCount; i++) {
        if (vertexName[i] == firstName) {
            v1 = i;
            break;
        }
    }

    for (int i = 0; i < vertexCount; i++) {
        if (vertexName[i] == secondName) {
            v2 = i;
            break;
        }
    }

    if (v1 == -1 || v2 == -1) return 0;
    return matrix[v1][v2] > 0;
}
// �������� ������������� �������
bool Graph::vertexExists(std::string _name){
    for (int i = 0; i < vertexCount; i++)
        if (vertexName[i] == _name)
            return true;
    return false;
}
//������� �������
void Graph::delVertex(std::string _name){
   
    int v1 = -1;

    for (int i = 0; i < vertexCount; i++) {
        if (vertexName[i] == _name) {
            v1 = i;
            break;
        }
    }

    if (v1 == -1) return;

    vertexCount--;

    for (int i = 0; i < SIZE; i++)
    {
        matrix[i][v1] = 0;
        matrix[v1][i] = 0;
    }
    
    for (int i = v1; i < vertexCount; i++)
    {
        vertexName[i] = vertexName[i + 1];
    }
}
//������� �����
void Graph::delEdge(std::string firstName, std::string secondName){
    int v1 = -1, v2 = -1;

    for (int i = 0; i < vertexCount; i++) {
        if (vertexName[i] == firstName) {
            v1 = i;
            break;
        }
    }

    for (int i = 0; i < vertexCount; i++) {
        if (vertexName[i] == secondName) {
            v2 = i;
            break;
        }
    }

    if (v1 == -1 || v2 == -1) return;

    matrix[v1][v2] = 0;
    matrix[v2][v1] = 0;
}
//����� ���� �����������
void Graph::threeHandshakes(std::string _name) {
    int count = 0;
    bool visited[SIZE]; // ������ ���������� ������
    for (int i = 0; i < SIZE; i++)
        visited[i] = false; // �������������� ��� ������������
    
    depthInner(_name, visited, count); // ������ ��������� 

   
};
//������ ����� 
int Graph::getIndex(std::string _name) {
    for (int i = 0; i < vertexCount; i++) {
        if (vertexName[i] == _name) return i;
    }
};

void Graph::depthInner(std::string current, bool visited[], int a)
{
    visited[getIndex(current)] = true; // �������� ��� ����������
    std::cout << current << "  ";
    a++;
    if (a == 4) {
        std::cout << "\n";
        return;
    }
    for (int i = 0; i < SIZE; i++)
    {
        if (edgeExists(current, vertexName[i]) && !visited[i])
            depthInner(vertexName[i], visited, a); // ���� ���������� ����� � ������� �� ����������, �� ������� �� ���� � ������� �������

    }
}