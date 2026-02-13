#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

const int INF = 1e9;

struct Edge {
	int begin = 0;
	int end = 0;
	int capacity = 0;
	int flow = 0;
};

int DFS(int vertex, int finish, int min_capacity, std::vector<char>& used, std::vector<std::vector<int>>& graph, std::vector<Edge>& edges) {
	used[vertex] = '1';

	if (vertex == finish) {
		return min_capacity;
	}

	for (auto v : graph[vertex]) {
		if (used[edges[v].end] == '0' && edges[v].capacity - edges[v].flow > 0) {
			int delta = DFS(edges[v].end, finish, std::min(min_capacity, edges[v].capacity - edges[v].flow), used, graph, edges);
			if (delta > 0) {
				edges[v].flow += delta;
				edges[v ^ 1].flow -= delta;
				return delta;
			}
		}
	}

	return 0;
}

void DFS_min_cut(int vertex, std::vector<char>& cut, std::vector<char>& used, std::vector<std::vector<int>>& graph, std::vector<Edge>& edges) {
	used[vertex] = '1';
	cut[vertex] = 's';
	for (int i : graph[vertex]) {
		if (used[edges[i].end] == '0' && edges[i].flow != edges[i].capacity) {
			DFS_min_cut(edges[i].end, cut, used, graph, edges);
		}
	}
}

void FordFulkerson(int number_man, int number_woman, std::vector<std::vector<int>>& graph, std::vector<Edge>& edges, std::vector<std::vector<char>>& neighbours) {
	int start = 0;
	int finish = number_man + number_woman + 1;

	std::vector<char> used(number_man + number_woman + 2, '0');

	while (DFS(start, finish, INF, used, graph, edges)) {
		used.assign(number_man + number_woman + 2, '0');
	}
	used.assign(number_man + number_woman + 2, '0');

	std::vector<char> cut(number_man + number_woman + 2, 't');
	DFS_min_cut(start, cut, used, graph, edges);

	std::set<int> man;
	std::set<int> woman;

	for (int i = 0; i < edges.size(); ++i) {
		if (edges[i].begin > 0 && edges[i].begin <= number_man && edges[i].end > number_man && edges[i].end <= number_man + number_woman) {
			if (cut[edges[i].begin] == 's') {
				man.insert(edges[i].begin);
			}
			if (cut[edges[i].end] == 't') {
				woman.insert(edges[i].end - number_man);
			}
		}
	}

	for (int i = 0; i < number_man; ++i) {
		int counter = 0;
		for (int j = 0; j < number_woman; ++j) {
			if (neighbours[i][j] == '0') {
				++counter;
			}
		}
		if (counter == number_woman) {
			man.insert(i + 1);
		}
	}

	for (int i = 0; i < number_woman; ++i) {
		int counter = 0;
		for (int j = 0; j < number_man; ++j) {
			if (neighbours[j][i] == '0') {
				++counter;
			}
		}
		if (counter == number_man) {
			woman.insert(i + 1);
		}
	}

	std::cout << static_cast<int>(man.size() + woman.size()) << '\n';

	std::cout << static_cast<int>(man.size()) << " " << static_cast<int>(woman.size()) << '\n';

	for (auto& el : man) {
		std::cout << el << " ";
	}
	std::cout << '\n';

	for (auto& el : woman) {
		std::cout << el << " ";
	}
	std::cout << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int number_tests = 0;

	std::cin >> number_tests;

	std::vector<std::vector<int>> graph;
	std::vector<Edge> edges;

	int number_man = 0;
	int number_woman = 0;

	std::vector<std::vector<char>> neighbours;

	for (int i = 0; i < number_tests; ++i) {
		neighbours.clear();
		graph.clear();
		edges.clear();

		std::cin >> number_man >> number_woman;
		graph.resize(number_man + number_woman + 2);

		neighbours.assign(number_man, std::vector<char>(number_woman, '1'));

		int element = -1;

		for (int j = 0; j < number_man; ++j) {
			std::cin >> element;
			while (element != 0) {
				neighbours[j][element - 1] = '0';
				std::cin >> element;
			}
		}

		for (int j = 0; j < number_man; ++j) {
			edges.push_back(Edge{ 0, j + 1, 1 });
			graph[0].push_back(static_cast<int>(edges.size() - 1));
			edges.push_back(Edge{ j + 1, 0, 0 });
			graph[j + 1].push_back(static_cast<int>(edges.size() - 1));

		}

		for (int j = 0; j < number_woman; ++j) {
			edges.push_back(Edge{ number_man + j + 1, number_man + number_woman + 1, 1 });
			graph[number_man + j + 1].push_back(static_cast<int>(edges.size() - 1));
			edges.push_back(Edge{ number_man + number_woman + 1, number_man + j + 1, 0 });
			graph[number_woman + number_man + 1].push_back(static_cast<int>(edges.size() - 1));

		}

		for (int j = 0; j < number_man; ++j) {
			for (int k = 0; k < number_woman; ++k) {
				if (neighbours[j][k] == '1') {
					edges.push_back(Edge{ j + 1, number_man + k + 1, INF });
					graph[j + 1].push_back(static_cast<int>(edges.size() - 1));
					edges.push_back(Edge{ number_man + k + 1, j + 1, 0 });
					graph[number_man + k + 1].push_back(static_cast<int>(edges.size() - 1));
				}
			}
		}

		FordFulkerson(number_man, number_woman, graph, edges, neighbours);

		std::cout << '\n';
	}

	return 0;
}
