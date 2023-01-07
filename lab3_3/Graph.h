#pragma once
#include <iostream>
#include <string.h>
#include "Sequence.h"

using namespace std;

//add set?

template <typename TData, typename TElements, typename TId> class Node {
public:
	Node(Sequence<Edge<TData, TElements, TId>> *edges, TData value, TId new_id) {
		data = value;
		id = new_id;
		edge_sequence = edges;
	}

	Sequence<Edge<TData, TElements, TId>>* get_edges() {
		return this->edge_sequence;
	}

	TData get_data() {
		return data;
	}

	TId get_id() {
		return this->id;
	}

private:
	Sequence<Edge<TData, TElements, TId>>* edge_sequence;
	TData data;
	TId id;
};

template <typename TData, typename TElements, typename TId> class Edge {
public:
	Edge(Node<TData, TElements, TId>* start, Node<TData, TElements, TId>* end, TElements data, TId new_id) {
		start_node = start;
		end_node = end;
		value = data;
		id = new_id;
	}

	Node<TData, TElements, TId>* get_start() {
		return this->start_node;
	}

	Node<TData, TElements, TId>* get_end() {
		return this->end_node;
	}

	TElements get_value() {
		return this->value;
	}

	TId get_id() {
		return this->id;
	}

private:
	Node<TData, TElements, TId>* start_node;
	Node<TData, TElements, TId>* end_node;
	TElements value;
	TId id;
};

template <typename TData, typename TElements, typename TId> class Graph {
public:
	Graph() {
		node_sequence = new Sequence<Node<TData, TElements, TId>>;
	}

	Graph(Sequence<Node<TData, TElements, TId>> seq) {
		node_sequence = seq;
	}

	void Add(Node<TData, TElements, TId> vertex) {
		node_sequence->Append(vertex);
	}

private:
	Sequence<Node<TData, TElements, TId>> *node_sequence;
};