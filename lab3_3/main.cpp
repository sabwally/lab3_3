#include <iostream>
#include "GraphFunctions.h"

#include <string>

using namespace std;

void print_menu_main() {
	cout << "1) Enter graph" << endl;
	cout << "2) Exit" << endl;
	cout << "> ";
}

void print_menu_graph() {
	cout << "1) The shortest path" << endl;
	cout << "2) Topological sort" << endl;
	cout << "3) Return" << endl;
	cout << "> ";
}

int check_number(string s) {
	int num = 0;
	int l = s.length();
	int ch_num = 0;
	int check = 0;
	for (int i = 0; i < l; ++i) {
		if (s[i] != ' ') {
			if ('0' <= (int)s[i] && (int)s[i] <= '9') {
				num *= 10;
				num += (int)s[i] - (int)'0';
				if (ch_num == 0) {
					++check;
				}
				ch_num = 1;
			}
			else {
				check = 2;
			}
		}
		else if (s[i] == ' ') {
			ch_num = 0;
		}
		if (check > 1) {
			num = -1;
			break;
		}
	}
	return num;
}

int get_choice(int count) {
	int choice = -1, c_first = 0;
	string s;

	while (choice < 1 || choice > count) {
		if (c_first) {
			printf("Incorrect input. Try again\n> ");
		}
		else {
			c_first = 1;
		}
		getline(cin, s);
		if (!s.empty()) {
			choice = check_number(s);
		}
	}

	return choice;
}

int get_size(int count) {
	int size = -1, c_first = 0;
	string s;

	while (size < count) {
		if (c_first) {
			printf("Incorrect input. Try again\n> ");
		}
		else {
			c_first = 1;
		}
		getline(cin, s);
		if (!s.empty()) {
			size = check_number(s);
		}
	}

	return size;
}

void menu_graph(Graph g) {
	int choice;
	do {
		print_menu_graph();
		choice = get_choice(3);

		if (choice == 1) {
			int id_start;
			cout << "Enter id of start node: ";
			cin >> id_start;
			int id_end;
			cout << "Enter id of start node: ";
			cin >> id_end;
			cin.ignore();
			vector<int> path = Dijkstra(g, id_start, id_end);
			if (!path.size()) {
				cout << "There is no path between these nodes :(" << endl;
			}else {
				for (int i = 0; i < path.size(); ++i) {
					cout << path[i] << " ";
				}
				cout << endl;
			}
		}
		else if (choice == 2) {
			vector<int> t_order = topological_sort(g);
			for (int i = 0; i < t_order.size(); ++i) {
				cout << t_order[i] << " ";
			}
			cout << endl;
		}

	} while (choice != 3);
}

int main() {

	int ch_main;
	do {
		print_menu_main();
		ch_main = get_choice(2);

		if (ch_main != 2) {
			Graph g;
			int count_node;
			cout << "Enter number of nodes: ";
			cin >> count_node;
			for (int i = 0; i < count_node; ++i) {
				Node v;
				g.add_node(&v);
			}

			int count_edge;
			cout << "Enter number of edges: ";
			cin >> count_edge;
			if(count_edge) {
				cout << "Enter edges (begin, end, weight):" << endl;
				for (int i = 0; i < count_edge; ++i) {
					cout << i + 1 << ") ";
					int i_start, i_end, value;
					cin >> i_start >> i_end >> value;
					i_start--;
					i_end--;
					Edge u(&(*g.get_list_nodes())[i_start], &(*g.get_list_nodes())[i_end], value);
					g.add_edge(&u);
					(*g.get_list_nodes())[i_start].get_edges()->push_back(u);
				}
			}
			cin.ignore();
			//print id
			cout << "Id of nodes and edges:" << endl;
			cout << "---Nodes---" << endl;
			for (int i = 0; i < count_node; ++i) {
				cout << "id v"<<i+1<<" = "<< (*g.get_list_nodes())[i].get_id() << endl;
			}
			cout << "---Edges---" << endl;
			int a = 1;
			for (auto it = g.get_list_edges()->cbegin(); it != g.get_list_edges()->cend(); ++it) {
				cout << "id u" << a++ << " = " << it->first << endl;
			}
			menu_graph(g);
		}
	} while (ch_main != 2);

	return 0;
}
