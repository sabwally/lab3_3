#pragma once
#include <queue>
#include <stack>
#include "Graph.h"
#include <algorithm>
//��������

//vector<int> Dijkstra(Graph graph, int id_start, int id_end) {
//    //fill(dist, dist + n, INF);
//    map<int, int> dist; // ��������� �� �������
//    for (int i = 0; i < graph.get_nodes().size(); ++i) {
//        dist[graph.get_nodes()[i].get_id()] = 1000000;
//    }
//    vector<int> path;
//    map<int, int> p;  //�� ����� ���� ������ � �������
//    dist[id_start] = 0;
//    priority_queue<pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
//    q.push(make_pair(0, id_start));
//    while (!q.empty()) {
//        pair<int, int> current = q.top();
//        q.pop();
//        if (current.first > dist[current.second]) continue;
//        vector<Edge>* edges = graph.get_node(current.second).get_edges();
//        if (!edges->empty()) {
//            for (int i = 0; i < edges->size(); ++i) {
//                int v = (*edges)[i].get_end()->get_id();
//                int len = (*edges)[i].get_value();
//                if (dist[v] > dist[current.second] + len || dist[v] == -1) {
//                    p[v] = (*edges)[i].get_id(); // change
//                    dist[v] = dist[current.second] + len;
//                    q.push(make_pair(dist[v], v));
//                }
//            }
//        }        
//    }
//
//    //change
//    int buff = id_end;
//    int ch = 0;
//    while (buff != id_start && ch < graph.get_nodes().size()) {
//        int id_edge = p[buff];
//        path.push_back(id_edge);
//        buff = graph.get_edge(id_edge).get_start()->get_id();
//        ch++;
//    }
//    reverse(path.begin(), path.end());
//
//    return path;
//}

vector<int> Dijkstra(Graph graph, int id_start, int id_end) {
    int INF = 1000000;
    map<int, int> dist; // ��������� �� �������
    map<int, int> p;  //�� ��������
    map<int, bool> used;
    for (int i = 0; i < graph.get_nodes().size(); ++i) {
        dist[graph.get_nodes()[i].get_id()] = INF;
        p[graph.get_nodes()[i].get_id()] = -1;
        used[graph.get_nodes()[i].get_id()] = false;

    }
    dist[id_start] = 0;
    p[id_start] = id_start;

    for (int i = 0; i < graph.get_nodes().size(); ++i) {
        int v = -1;
        for (int j = 0; j < graph.get_nodes().size(); j++) {
            int id = graph.get_nodes()[j].get_id();
            if (!used[id] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
            if (dist[v] == INF) break;
            used[v] = true;
            auto next = graph.get_node(v);

        }
    }


    vector<int> path; //�� ����� ���� ������ � �������
    //change
    int buff = id_end;
    int ch = 0;
    while (buff != id_start && ch < graph.get_nodes().size()) {
        int id_edge = p[buff];
        path.push_back(id_edge);
        buff = graph.get_edge(id_edge).get_start()->get_id();
        ch++;
    }
    reverse(path.begin(), path.end());

    return path;
}

//�������������� ������������

//class Graph
//{
//    int V;	// ���������� ������
//
//    //  ��������� �� ������, ���������� ������ ���������
//    list<int>* adj;
//
//    // �������, ������������ topologicalSort
//    void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);
//public:
//    Graph(int V);   // �����������
//
//    // ������� ��� ���������� ����� � ����
//    void addEdge(int v, int w);
//
//    // ������� �������������� ���������� �����
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
//    adj[v].push_back(w); // Add w to v�s list.
//}

//void topologicalSortUtil(Graph graph, int id, int v, bool visited[], stack<int>& Stack)
//{
//    // �������� ������� ���� ��� ����������
//    visited[v] = true;
//
//    // ���������� �������� ������� ��� ���� ������� ������
//    list<int>::iterator i;
//    for (i = adj[v].begin(); i != adj[v].end(); ++i)
//        if (!visited[*i])
//            topologicalSortUtil(*i, visited, Stack);
//
//    // ��������� ������� ������� � ���� � �����������
//    Stack.push(v);
//}
//
//// ������� ��� ������ �������������� ����������. 
//// ���������� ���������� topologicalSortUtil()
//void topologicalSort(Graph graph) {
//    stack<int> Stack;
//
//    // �������� ��� ������� ��� ������������
//    int size = graph.get_nodes().size();
//    bool* visited = new bool[size];
//    for (int i = 0; i < size; i++) {
//        visited[i] = false;
//    }
//
//    // �������� ����������� ��������������� ������� 
//    // ��� ������ �������������� ���������� ��� ������ �������
//    for (int i = 0; i < size; i++) {
//        if (visited[i] == false) {
//            topologicalSortUtil(graph, graph.get_nodes()[i].get_id(), i, visited, Stack);
//        }
//    }
//
//    // ������� ���������� �����
//    while (Stack.empty() == false)
//    {
//        cout << Stack.top() << " ";
//        Stack.pop();
//    }
//}

