#include <iostream>
#include "GraphFunctions.h"

using namespace std;

int main() {

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

	vector<int> path = Dijkstra(g, v1.get_id(), v2.get_id());
	//cout << "fevuwycb " << g.get_node(v1.get_id())->get_edges()->size() << endl;
	cout << "vbibn " << path.size() << endl;
	for (int i = 0; i < path.size(); ++i) {
		cout << path[i] << " ";
	}
	cout << endl;
	cout << "cbkdn" << endl;
	vector<int> path2 = Dijkstra(g, v1.get_id(), v4.get_id());
	cout << "rbek " << path2.size() << endl;
	for (int i = 0; i < path2.size(); ++i) {
		cout << path2[i] << " " ;
	}
	cout << endl;
	cout << "dsvsdc" << endl;
	//for (int i = 0; i < g.get_list_nodes()->size(); ++i) {
	//	cout << (*g.get_list_nodes())[i].get_id() << endl;
	//}

	//for (auto it = g.get_list_edges()->cbegin(); it != g.get_list_edges()->cend(); ++it) {
	//	std::cout << it->first << "\n";
	//}

	vector<int> t_order = topological_sort(g);
	for (int i = 0; i < t_order.size(); ++i) {
		cout << t_order[i] << " ";
	}
	cout << endl;
	return 0;
}