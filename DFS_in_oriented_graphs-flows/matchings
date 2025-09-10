#include <iostream>
#include <vector>
#include <algorithm>

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

void FordFulkerson(int number_vertices_a, int number_vertices_b, std::vector<std::vector<int>>& graph, std::vector<Edge>& edges) {
	int start = 0;
	int finish = number_vertices_a + number_vertices_b + 1;

	std::vector<char> used(number_vertices_a + number_vertices_b + 2, '0');

	while (DFS(start, finish, INF, used, graph, edges)) {
		used.assign(number_vertices_a + number_vertices_b + 2, '0');
	}
	used.assign(number_vertices_a + number_vertices_b + 2, '0');

	int answer = 0;

	for (int vertex : graph[0]) {
		answer += edges[vertex].flow;
	}

	std::cout << answer << '\n';

	for (int i : graph[0]) {
		if (edges[i].flow == 1 && edges[i + 1].flow == -1) {
			for (int j : graph[edges[i].end]) {
				if (edges[j].flow == 1 && edges[j + 1].flow == -1 && edges[j].end != 0) {
					std::cout << edges[i].end << " " << edges[j].end - number_vertices_a << '\n';
					break;
				}
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int number_vertices_a = 0;
	int number_vertices_b = 0;

	std::cin >> number_vertices_a >> number_vertices_b;

	std::vector<std::vector<int>> graph(number_vertices_a + number_vertices_b + 2);
	std::vector<Edge> edges;

	for (int i = 0; i < number_vertices_a; ++i) {
		edges.push_back(Edge{ 0, i + 1, 1 });
		graph[0].push_back(static_cast<int>(edges.size() - 1));
		edges.push_back(Edge{ i + 1, 0, 0 });
		graph[i + 1].push_back(static_cast<int>(edges.size() - 1));

	}

	for (int i = 0; i < number_vertices_b; ++i) {
		edges.push_back(Edge{ number_vertices_a + i + 1,number_vertices_a + number_vertices_b + 1, 1 });
		graph[number_vertices_a + i + 1].push_back(static_cast<int>(edges.size() - 1));
		edges.push_back(Edge{ number_vertices_a + number_vertices_b + 1, number_vertices_a + i + 1, 0 });
		graph[number_vertices_a + number_vertices_b + 1].push_back(static_cast<int>(edges.size() - 1));

	}

	int end = -1;
	for (int i = 0; i < number_vertices_a; ++i) {
		std::cin >> end;
		while (end != 0) {
			edges.push_back(Edge{ i + 1, number_vertices_a + end, 1 });
			graph[i + 1].push_back(static_cast<int>(edges.size() - 1));
			edges.push_back(Edge{ number_vertices_a + end, i + 1, 0 });
			graph[number_vertices_a + end].push_back(static_cast<int>(edges.size() - 1));
			std::cin >> end;
		}
	}

	FordFulkerson(number_vertices_a, number_vertices_b, graph, edges);

	return 0;
}
