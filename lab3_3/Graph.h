#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

class Edge;

class Node {
public:
	Node(vector<Edge> new_edges, int new_id) {
		id = new_id;
		edges = new_edges;
	}

	Node() {}

	vector<Edge>* get_edges() {
		return &(this->edges);
	}

	int get_id() {
		return this->id;
	}

	void set_id(int new_id) {
		id = new_id;
	}

	bool operator==(Node* node) {
		return this->id == node->id;
	}

	bool operator!=(Node* node) {
		return this->id != node->id;
	}
private:
	vector<Edge> edges; // from
	int id = -1;
};

class Edge {
public:
	Edge() {
		start = new Node();
		end = new Node();
	}

	Edge(Node* start_node, Node* end_node, int data, int new_id) {
		start = start_node;
		end = end_node;
		value = data;
		id = new_id;
	}

	Edge(Node* start_node, Node* end_node, int data) {
		start = start_node;
		end = end_node;
		value = data;
	}

	Node* get_start() {
		return this->start;
	}

	Node* get_end() {
		return this->end;
	}

	int get_value() {
		return this->value;
	}

	int get_id() {
		return this->id;
	}

	void set_id(int new_id) {
		id = new_id;
	}

	bool IsIncidentTo(Edge* edge) const
	{
		return this->end == edge->start || edge->end == this->start;
	}

	bool operator==(Edge *edge) {
		return this->id == edge->id;
	}

	bool operator!=(Edge *edge) {
		return this->id != edge->id;
	}

	bool operator==(Edge edge) {
		return this->id == edge.id;
	}

	bool operator!=(Edge edge) {
		return this->id != edge.id;
	}
private:
	Node* start;
	Node* end;
	int value = -1;
	int id = -1;
};

class Graph {
public:
	Graph() {}

	void add_node(Node *vertex) {
		int num = id_const();
		vertex->set_id(num);
		nodes.push_back(*vertex);
	}

	void add_edge(Edge *new_edge) {
		int num = id_const();
		new_edge->set_id(num);
		edges[num] = *new_edge;
	}

	vector<Node>* get_list_nodes() {
		return &nodes;
	}

	map<int, Edge>* get_list_edges() {
		return &edges;
	}

	Node* get_node(int id_node) {
		assert(count(nodes.begin(), nodes.end(), id_node));
		for (int i = 0; i < nodes.size(); ++i) {
			if (nodes[i].get_id() == id_node) {
				return &(nodes[i]);
			}
		}
	}

	Edge* get_edge(int id_edge) {
		assert(edges.count(id_edge) == 1);
		return &edges[id_edge];
	}

	//void remove_edge(int id_edge) {
	//	auto v = this->get_edge(id_edge);
	//	auto u = v->get_start();
	//	auto buff_edges = u->get_edges();
	//	int i_v;
	//	for (int i = 0; i < buff_edges->size(); ++i) {
	//		if ((*buff_edges)[i] == v) {
	//			i_v = i;
	//		}
	//	}
	//	u->get_edges()->erase(i_v);
	//	edges.erase(id_edge);
	//}

	//void remove_node(int id_node) {

	//}

private:
	vector<Node> nodes;
	//map<int, Node> nodes;
	map<int, Edge> edges;

	int id_const() {
		static int a = 1;
		return a++;
	}
};