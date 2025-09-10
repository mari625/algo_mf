#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

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

void DFS_find_way(int vertex, int finish, std::vector<char>& used, std::vector<char>& used_edges, std::vector<std::vector<int>>& graph, std::vector<Edge>& edges, std::vector<int>& way) {
	used[vertex] = '1';
	way.push_back(vertex);

	if (vertex == finish) {
		throw std::runtime_error("finish");
		return;
	}

	for (auto v : graph[vertex]) {
		if (used_edges[v] == '0' && used[edges[v].end] == '0' && edges[v].flow == 1) {
			used_edges[v] = '1';
			DFS_find_way(edges[v].end, finish, used, used_edges, graph, edges, way);
		}
	}
}

void FordFulkerson(int number_vertices, std::vector<std::vector<int>>& graph, std::vector<Edge>& edges, int start, int finish) {
	std::vector<char> used(number_vertices + 2, '0');

	while (DFS(0, number_vertices + 1, INF, used, graph, edges)) {
		used.assign(number_vertices + 2, '0');
	}
	used.assign(number_vertices + 2, '0');

	int answer = 0;

	for (int vertex : graph[0]) {
		answer += edges[vertex].flow;
	}

	if (answer != 2) {
		std::cout << "NO" << '\n';
		return;
	}

	std::cout << "YES" << '\n';

	std::vector<char> used_edges(edges.size(),'0');
	std::vector<int> way;

	try {
		DFS_find_way(start, finish, used, used_edges, graph, edges, way);
	}
	catch (const std::runtime_error& er) {
		for (size_t i = 0; i < way.size(); ++i) {
			std::cout << way[i] << " ";
			}
		std::cout << '\n';
	}

	used.assign(number_vertices + 2, '0');

	way.clear();

	try {
		DFS_find_way(start, finish, used, used_edges, graph, edges, way);
	}
	catch (const std::runtime_error& er) {
		for (size_t i = 0; i < way.size(); ++i) {
			std::cout << way[i] << " ";
		}
		std::cout << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int number_vertices = 0;
	int number_edges = 0;
	int start = 0;
	int finish = 0;
	std::cin >> number_vertices >> number_edges >> start >> finish;

	std::vector<std::vector<int>> graph(number_vertices + 2);
	std::vector<Edge> edges;

	int begin = 0;
	int end = 0;
	for (int i = 0; i < number_edges; ++i) {
		std::cin >> begin >> end;
		edges.push_back(Edge{ begin, end, 1 });
		graph[begin].push_back(static_cast<int>(edges.size() - 1));
		edges.push_back(Edge{ end, begin, 0 });
		graph[end].push_back(static_cast<int>(edges.size() - 1));

	}

	edges.push_back(Edge{ 0, start, 2 });
	graph[0].push_back(static_cast<int>(edges.size() - 1));
	edges.push_back(Edge{ start, 0, 0 });
	graph[start].push_back(static_cast<int>(edges.size() - 1));

	edges.push_back(Edge{ finish, number_vertices + 1, 2 });
	graph[finish].push_back(static_cast<int>(edges.size() - 1));
	edges.push_back(Edge{ number_vertices + 1, finish, 0 });
	graph[number_vertices + 1].push_back(static_cast<int>(edges.size() - 1));

	FordFulkerson(number_vertices, graph, edges, start, finish);

	return 0;
}
