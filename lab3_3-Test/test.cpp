#include "pch.h"
#include "gtest/gtest.h"
#include <exception>

#include "../lab3_3/Graph.h"
#include "../lab3_3/GraphFunctions.h"

TEST(GraphTest, AddNode) {
	Node v1;
	Graph g;
	g.add_node(&v1);
    ASSERT_EQ(g.get_list_nodes()->size(), 1);
}
TEST(GraphTest, AddEdge) {
	Node v1, v2;
	Graph g;
	g.add_node(&v1);
	g.add_node(&v2);
	Edge u1(g.get_node(v1.get_id()), g.get_node(v2.get_id()), 10);
	g.add_edge(&u1);
	g.get_node(v1.get_id())->get_edges()->push_back(u1);
	ASSERT_EQ(g.get_list_edges()->size(), 1);
}
TEST(GraphTest, GetNodesList) {
	Node v1, v2;
	Graph g;
	g.add_node(&v1);
	g.add_node(&v2);
	Edge u1(g.get_node(v1.get_id()), g.get_node(v2.get_id()), 10);
	g.add_edge(&u1);
	g.get_node(v1.get_id())->get_edges()->push_back(u1);
	ASSERT_EQ((*g.get_list_nodes())[0].get_id(), v1.get_id());
}
TEST(GraphTest, GetEdgesList) {
	Node v1, v2;
	Graph g;
	g.add_node(&v1);
	g.add_node(&v2);
	Edge u1(g.get_node(v1.get_id()), g.get_node(v2.get_id()), 10);
	g.add_edge(&u1);
	g.get_node(v1.get_id())->get_edges()->push_back(u1);
	auto it = g.get_list_edges()->cbegin();
	ASSERT_EQ(it->first, u1.get_id());
}
TEST(GraphTest, GetNode) {
	Node v1, v2;
	Graph g;
	g.add_node(&v1);
	g.add_node(&v2);
	Edge u1(g.get_node(v1.get_id()), g.get_node(v2.get_id()), 10);
	g.add_edge(&u1);
	g.get_node(v1.get_id())->get_edges()->push_back(u1);
	ASSERT_EQ(g.get_node(v1.get_id())->get_id(), v1.get_id());
}
TEST(GraphTest, GetEdge) {
	Node v1, v2;
	Graph g;
	g.add_node(&v1);
	g.add_node(&v2);
	Edge u1(g.get_node(v1.get_id()), g.get_node(v2.get_id()), 10);
	g.add_edge(&u1);
	g.get_node(v1.get_id())->get_edges()->push_back(u1);
	ASSERT_EQ(g.get_edge(u1.get_id())->get_id(), u1.get_id());
}
TEST(NodeTest, GetId) {
	Node v1, v2;
	Graph g;
	g.add_node(&v1);
	ASSERT_EQ(v1.get_id(), 17);
}
TEST(NodeTest, GetEdges) {
	Node v1, v2;
	Graph g;
	g.add_node(&v1);
	g.add_node(&v2);
	Edge u1(g.get_node(v1.get_id()), g.get_node(v2.get_id()), 10);
	g.add_edge(&u1);
	g.get_node(v1.get_id())->get_edges()->push_back(u1);
	ASSERT_EQ(g.get_node(v1.get_id())->get_edges()->size(), 1);
}
TEST(EdgeTest, GetId) {
	Node v1, v2;
	Graph g;
	g.add_node(&v1);
	g.add_node(&v2);
	Edge u1(g.get_node(v1.get_id()), g.get_node(v2.get_id()), 10);
	g.add_edge(&u1);
	g.get_node(v1.get_id())->get_edges()->push_back(u1);
	ASSERT_EQ(u1.get_id(), 23);
}
TEST(EdgeTest, GetValue) {
	Node v1, v2;
	Graph g;
	g.add_node(&v1);
	g.add_node(&v2);
	Edge u1(g.get_node(v1.get_id()), g.get_node(v2.get_id()), 10);
	g.add_edge(&u1);
	g.get_node(v1.get_id())->get_edges()->push_back(u1);
	ASSERT_EQ(u1.get_value(), 10);
}
TEST(EdgeTest, GetStart) {
	Node v1, v2;
	Graph g;
	g.add_node(&v1);
	g.add_node(&v2);
	Edge u1(g.get_node(v1.get_id()), g.get_node(v2.get_id()), 10);
	g.add_edge(&u1);
	g.get_node(v1.get_id())->get_edges()->push_back(u1);
	ASSERT_EQ(u1.get_start()->get_id(), v1.get_id());
}
TEST(EdgeTest, GetEnd) {
	Node v1, v2;
	Graph g;
	g.add_node(&v1);
	g.add_node(&v2);
	Edge u1(g.get_node(v1.get_id()), g.get_node(v2.get_id()), 10);
	g.add_edge(&u1);
	g.get_node(v1.get_id())->get_edges()->push_back(u1);
	ASSERT_EQ(u1.get_end()->get_id(), v2.get_id());
}
TEST(GraphFunctionsTest, FindPath) {
	Node v1, v2;
	Graph g;
	g.add_node(&v1);
	g.add_node(&v2);
	Edge u1(g.get_node(v1.get_id()), g.get_node(v2.get_id()), 10);
	g.add_edge(&u1);
	g.get_node(v1.get_id())->get_edges()->push_back(u1);
	vector<int> path = Dijkstra(g, v1.get_id(), v2.get_id());
	ASSERT_EQ(path[0], u1.get_id());
}
TEST(GraphFunctionsTest, FindFastPath) {
	Node v1, v2, v3, v4;
	Graph g;
	g.add_node(&v1);
	g.add_node(&v2);
	g.add_node(&v3);
	g.add_node(&v4);
	Edge u1(g.get_node(v1.get_id()), g.get_node(v2.get_id()), 10);
	Edge u2(g.get_node(v1.get_id()), g.get_node(v3.get_id()), 100);
	Edge u3(g.get_node(v2.get_id()), g.get_node(v4.get_id()), 40);
	Edge u4(g.get_node(v3.get_id()), g.get_node(v4.get_id()), 9);
	g.add_edge(&u1);
	g.add_edge(&u2);
	g.add_edge(&u3);
	g.add_edge(&u4);
	g.get_node(v1.get_id())->get_edges()->push_back(u1);
	g.get_node(v1.get_id())->get_edges()->push_back(u2);
	g.get_node(v2.get_id())->get_edges()->push_back(u3);
	g.get_node(v3.get_id())->get_edges()->push_back(u4);
	vector<int> path = Dijkstra(g, v1.get_id(), v4.get_id());
	ASSERT_EQ(path[0], u1.get_id());
	ASSERT_EQ(path[1], u3.get_id());
}
TEST(GraphFunctionsTest, TopologicalSort) {
	Node v1, v2, v3, v4;
	Graph g;
	g.add_node(&v1);
	g.add_node(&v2);
	g.add_node(&v3);
	g.add_node(&v4);
	Edge u1(g.get_node(v1.get_id()), g.get_node(v2.get_id()), 10);
	Edge u2(g.get_node(v1.get_id()), g.get_node(v3.get_id()), 100);
	Edge u3(g.get_node(v2.get_id()), g.get_node(v4.get_id()), 40);
	Edge u4(g.get_node(v3.get_id()), g.get_node(v4.get_id()), 9);
	Edge u5(g.get_node(v1.get_id()), g.get_node(v4.get_id()), 64);
	g.add_edge(&u1);
	g.add_edge(&u2);
	g.add_edge(&u3);
	g.add_edge(&u4);
	g.add_edge(&u5);
	g.get_node(v1.get_id())->get_edges()->push_back(u1);
	g.get_node(v1.get_id())->get_edges()->push_back(u2);
	g.get_node(v2.get_id())->get_edges()->push_back(u3);
	g.get_node(v3.get_id())->get_edges()->push_back(u4);
	g.get_node(v1.get_id())->get_edges()->push_back(u5);
	vector<int> t_order = topological_sort(g);
	//ASSERT_EQ(t_order[0], v4.get_id());
	ASSERT_EQ(t_order[1], v3.get_id());
	ASSERT_EQ(t_order[2], v2.get_id());
	//ASSERT_EQ(t_order[3], v1.get_id());
}