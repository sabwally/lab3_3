#pragma once
#include <iostream>
#include <string.h>
#include "Sequence.h"

using namespace std;

//add set?
//id - static int

template <typename TData, typename TElements> class Node {
public:
	Node(Sequence<Edge<TData, TElements>> *new_edges, TData value, int new_id) {
		data = value;
		id = new_id;
		edges = new_edges;
	}

	Sequence<Edge<TData, TElements>>* get_edges() {
		return this->edges;
	}

	TData get_data() {
		return data;
	}

	int get_id() {
		return this->id;
	}

	bool operator==(Node<TData, TElements>* node) {
		return this->id == node->id;
	}

	bool operator!=(Node<TData, TElements>* node) {
		return this->id != node->id;
	}
private:
	Sequence<Edge<TData, TElements>>* edges;
	TData data;
	int id;
};

template <typename TData, typename TElements> class Edge {
public:
	Edge(Node<TData, TElements>* start_node, Node<TData, TElements>* end_node, TElements data, int new_id) {
		start = start_node;
		end = end_node;
		value = data;
		id = new_id;
	}

	Node<TData, TElements>* get_start() {
		return this->start;
	}

	Node<TData, TElements>* get_end() {
		return this->end;
	}

	TElements get_value() {
		return this->value;
	}

	int get_id() {
		return this->id;
	}

	bool IsIncidentTo(Edge<TData, TElements>* edge) const
	{
		return this->end == edge->start || edge->end == this->start;
	}

private:
	Node<TData, TElements>* start;
	Node<TData, TElements>* end;
	TElements value;
	int id;
};

template <typename TData, typename TElements> class Graph {
public:
	Graph() {
		nodes = new Sequence<Node<TData, TElements>>;
	}

	Graph(Sequence<Node<TData, TElements>> seq) {
		nodes = seq;
	}

	void Add(Node<TData, TElements> vertex) {
		nodes->Append(vertex);
	}

	void Remove(Node<TData, TElements> vertex) {
		//nodes->Append(vertex);
	}

	//ReadonlySequence<TNode>* GetNodes() const = 0;
	//ReadonlySequence<TEdge>* GetEdges() const = 0;
	//ReadonlySequence<TEdge>* GetInboundEdges(TNode node) const = 0;
	//ReadonlySequence<TEdge>* GetOutboundEdges(TNode node) const = 0;
	//IOrientedGraph<TIdentifier, TNode, TEdge>* Add(TNode node) = 0;
	//IOrientedGraph<TIdentifier, TNode, TEdge>* Remove(TNode node) = 0;
	//IOrientedGraph<TIdentifier, TNode, TEdge>* Add(TEdge edge) = 0;
	//IOrientedGraph<TIdentifier, TNode, TEdge>* Remove(TEdge edge) = 0;

private:
	Sequence<Node<TData, TElements>> *nodes;
};