#include <iostream>
#include <vector>
#include <cstdint>
#include <set>

struct Edge {
	int begin = 0;
	int end = 0;
	int64_t weight = 0;

	bool operator!=(Edge other) {
		return begin != other.begin || end != other.end || weight != other.weight;
	}
};

void Dijkstra(int number_vertices, const std::vector<std::vector<Edge>>& graph, std::vector<int64_t>& distances, std::vector<int>& prev) {
	const int64_t kBig = 1e18;
	for (int i = 0; i < number_vertices + 1; ++i) {
		distances[i] = kBig;
		prev[i] = 0;
	}
	distances[1] = 0;

	std::set<std::pair<int64_t, int>> queue;
	queue.insert({ distances[1], 1 });

	while (!queue.empty()) {
		auto vertex = queue.begin()->second;
		queue.erase(queue.begin());

		for (const auto& edge : graph[vertex]) {
			if (distances[edge.begin] + edge.weight < distances[edge.end]) {
				queue.erase({ distances[edge.end], edge.end });
				distances[edge.end] = distances[edge.begin] + edge.weight;
				prev[edge.end] = edge.begin;
				queue.insert({ distances[edge.end], edge.end });
			}
		}
	}
}


void Compute(int number_vertices, std::vector<std::vector<Edge>>& graph) {
	const int64_t kBig = 1e18;
	std::vector<int64_t> distances(number_vertices + 1, kBig);
	std::vector<int> prev(number_vertices + 1, 0);

	Dijkstra(number_vertices, graph, distances, prev);
	int64_t first_distance = distances[number_vertices];

	std::vector<Edge> path;
	int current = number_vertices;
	while (current != 1) {
		path.push_back(Edge{ prev[current], current, distances[current] - distances[prev[current]] });
		current = prev[current];
	}

	int64_t second_distance = 0;
	for (auto& edge : path) {
		int first_index = 0;
		while (edge != graph[edge.begin][first_index]) {
			++first_index;
		}

		int second_index = 0;
		while (edge.end != graph[edge.end][second_index].begin || edge.begin != graph[edge.end][second_index].end || edge.weight != graph[edge.end][second_index].weight) {
			++second_index;
		}

		graph[edge.begin][first_index].weight *= 2;
		graph[edge.end][second_index].weight *= 2;

		Dijkstra(number_vertices, graph, distances, prev);
		graph[edge.begin][first_index].weight /= 2;
		graph[edge.end][second_index].weight /= 2;

		if (distances[number_vertices] > second_distance) {
			second_distance = distances[number_vertices];
		}
	}

	std::cout << second_distance - first_distance << '\n';
}

int main() {
	int number_vertices = 0;
	int number_edges = 0;

	std::cin >> number_vertices >> number_edges;

	std::vector<std::vector<Edge>> graph(number_vertices + 1);

	for (int i = 0; i < number_edges; ++i) {
		int begin = 0;
		int end = 0;
		int weight = 0;
		std::cin >> begin >> end >> weight;

		graph[begin].push_back(Edge{ begin, end, weight });
		graph[end].push_back(Edge{ end, begin, weight });
	}

	Compute(number_vertices, graph);
	return 0;
}
