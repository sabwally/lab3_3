#include <iostream>
#include "GraphFunctions.h"

using namespace std;

int main() {

	Node v1, v2, v3;
	Edge u1(&v1, &v2, 10);
	Edge u2(&v1, &v3, 100);
	Graph g;
	g.add_edge(&u1);
	g.add_edge(&u2);
	v1.get_edges()->push_back(u1);
	v1.get_edges()->push_back(u2);
	g.add_node(&v1);
	g.add_node(&v2);
	g.add_node(&v3);

	//vector<int> path = Dijkstra(g, v1.get_id(), v2.get_id());

	for (int i = 0; i < g.get_nodes().size(); ++i) {
		cout << g.get_nodes()[i].get_id() << endl;
	}

	/*for (int i = 0; i < path.size(); ++i) {
		cout << path[i] << endl;
	}*/

	return 0;
}