#include <iostream>
#include <vector>
#include <cstdint>
#include <queue>

struct Edge {
	int begin = 0;
	int end = 0;
	int weight = 0;
};

void BFS(int number_vertices, const std::vector<std::vector<Edge>>& graph, const std::vector<std::vector<Edge>>& reversed_graph, std::vector<short>& reachable) {
	std::queue<int> neighbours;
	neighbours.push(number_vertices);
	reachable[number_vertices] = 1;

	while (!neighbours.empty()) {
		int vertex = neighbours.front();
		neighbours.pop();

		for (auto& edge : reversed_graph[vertex]) {
			if (reachable[edge.end] == 0) {
				neighbours.push(edge.end);
				++reachable[edge.end];
			}
		}
	}

	++reachable[1];

	neighbours.push(1);
	while (!neighbours.empty()) {
		int vertex = neighbours.front();
		neighbours.pop();

		for (auto& edge : graph[vertex]) {
			if (reachable[edge.end] == 1) {
				neighbours.push(edge.end);
				++reachable[edge.end];
			}
		}
	}
}

void BellmanFord(int number_vertices, const std::vector<std::vector<Edge>>& graph, const std::vector<std::vector<Edge>>& reversed_graph) {
	const int64_t kBig = 1'000'000'000;
	std::vector<int64_t> distances(number_vertices + 1, kBig);
	distances[1] = 0;

	std::vector<short> reachable(number_vertices + 1, 0);

	BFS(number_vertices, graph, reversed_graph, reachable);

	if (reachable[number_vertices] != 2) {
		std::cout << ":(" << '\n';
		return;
	}

	for (int i = 0; i < number_vertices; ++i) {
		for (int j = 0; j <= number_vertices; ++j) {
			for (auto& edge : graph[j]) {
				if (reachable[edge.begin] == 2 && reachable[edge.end] == 2 && distances[edge.begin] + edge.weight < distances[edge.end]) {
					distances[edge.end] = distances[edge.begin] + edge.weight;
				}
			}
		}
	}

	for (int j = 0; j <= number_vertices; ++j) {
		for (auto& edge : graph[j]) {
			if (reachable[edge.begin] == 2 && reachable[edge.end] == 2 && distances[edge.begin] + edge.weight < distances[edge.end]) {
				std::cout << ":)" << '\n';
				return;
			}
		}
	}

	std::cout << -distances[number_vertices] << '\n';
}

int main() {
	int number_vertices = 0;
	int number_edges = 0;

	std::cin >> number_vertices >> number_edges;

	std::vector<std::vector<Edge>> reversed_graph(number_vertices + 1);
	std::vector<std::vector<Edge>> graph(number_vertices + 1);

	for (int i = 0; i < number_edges; ++i) {
		int begin = 0;
		int end = 0;
		int weight = 0;
		std::cin >> begin >> end >> weight;
		graph[begin].push_back(Edge{ begin, end, -weight });
		reversed_graph[end].push_back(Edge{ end, begin, weight });
	}

	BellmanFord(number_vertices, graph, reversed_graph);

	return 0;
}
