#pragma once
#include <utility>
#include <queue>
#include <stack>
#include "Graph.h"
#include <algorithm>
//проверки

vector<int> Dijkstra(Graph graph, int id_start, int id_end) {
    int INF = 1000000;
    map<int, int> dist; // растояние до вершины
    map<int, int> p;  //по какой дуге попали в вершину
    for (int i = 0; i < graph.get_list_nodes()->size(); ++i) {
        dist[(*graph.get_list_nodes())[i].get_id()] = INF;
        p[(*graph.get_list_nodes())[i].get_id()] = -1;
    }
    vector<int> path;
    dist[id_start] = 0;
    priority_queue<pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
    q.push(make_pair(0, id_start));
    while (!q.empty()) {
        pair<int, int> current = q.top();
        q.pop();
        if (current.first > dist[current.second]) continue;
        //vector<Edge> *edges = graph.get_node(current.second)->get_edges();
        if (graph.get_node(current.second)->get_edges()->size() != 0) { //!edges->empty()
            for (int i = 0; i < graph.get_node(current.second)->get_edges()->size(); ++i) {
                int v = (*graph.get_node(current.second)->get_edges())[i].get_end()->get_id();
                int len = (*graph.get_node(current.second)->get_edges())[i].get_value();
                if (dist[v] > dist[current.second] + len) {
                    p[v] = (*graph.get_node(current.second)->get_edges())[i].get_id(); // change
                    dist[v] = dist[current.second] + len;
                    q.push(make_pair(dist[v], v));
                }
            }
        }
    }
    int buff = id_end;
    int ch = 0;
    while (buff != id_start && ch < (*graph.get_list_nodes()).size()) {
        int id_edge = p[buff];
        if (id_edge == -1) {
            path.clear();
            break;
        }
        path.push_back(id_edge);
        buff = graph.get_edge(id_edge)->get_start()->get_id();
        ch++;
    }
    reverse(path.begin(), path.end());

    return path;
}

//Топологическое упорядочение

//class Graph
//{
//    int V;	// Количество вершин
//
//    //  Указатель на массив, содержащий список смежности
//    list<int>* adj;
//
//    // Функция, используемая topologicalSort
//    void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);
//public:
//    Graph(int V);   // Конструктор
//
//    // Функция для добавления ребра в граф
//    void addEdge(int v, int w);
//
//    // Выводит топологическую сортировку графа
//    void topologicalSort();
//};
//
//Graph::Graph(int V)
//{
//    this->V = V;
//    adj = new list<int>[V];
//}
//
//void Graph::addEdge(int v, int w)
//{
//    adj[v].push_back(w); // Add w to v’s list.
//}

void topologicalSortUtil(Graph graph, int id, map<int, bool>* visited, stack<int>* stack)
{
    // Помечаем текущий узел как посещенный
    (*visited)[id] = true;

    // Рекурсивно вызываем функцию для всех смежных вершин
    for (int i = 0; i < graph.get_node(id)->get_edges()->size(); ++i) {
        int tmp_id = (*graph.get_node(id)->get_edges())[i].get_end()->get_id();
        if ((*visited)[tmp_id] == false) {
            topologicalSortUtil(graph, tmp_id, visited, stack);
        }
    }

    // Добавляем текущую вершину в стек с результатом
    stack->push(id);
}

// Функция для поиска топологической сортировки. 
// Рекурсивно использует topologicalSortUtil()
void topologicalSort(Graph graph) {
    stack<int> stack;

    // Помечаем все вершины как непосещенные
    int size = graph.get_list_nodes()->size();
    map<int, bool>* visited = new map<int, bool>();
    for (int i = 0; i < graph.get_list_nodes()->size(); ++i) {
        (*visited)[(*graph.get_list_nodes())[i].get_id()] = false;
    }

    // Вызываем рекурсивную вспомогательную функцию 
    // для поиска топологической сортировки для каждой вершины
    for (int i = 0; i < size; i++) {
        if ((*visited)[i] == false) {
            topologicalSortUtil(graph, (*graph.get_list_nodes())[i].get_id(), visited, &stack);
        }
    }

    // Выводим содержимое стека
    while (stack.empty() == false)
    {
        cout << stack.top() << " ";
        stack.pop();
    }
}

