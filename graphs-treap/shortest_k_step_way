#include <iostream>
#include <vector>
#include <cstdint>
#include <set>

struct Edge {
	int begin = 0;
	int end = 0;
	int weight = 0;
};

struct SteppedDistance {
	int64_t distance = 0;
	int step = 0;

	bool operator == (SteppedDistance other) const {
		return distance == other.distance;
	}

	bool operator < (SteppedDistance other) const {
		return distance < other.distance;
	}
};

void Dijkstra(int number_vertices, const std::vector<std::vector<Edge>>& graph, int number_steps, int begin) {
	const int64_t kBig = 1e18;
	std::vector<std::vector<int64_t>> distances(number_vertices + 1, std::vector<int64_t>(number_steps + 1, kBig));
	distances[begin][0] = 0;

	std::set<std::pair<SteppedDistance, int >> queue;
	queue.insert({ SteppedDistance{0, 0}, begin });

	while (!queue.empty()) {
		auto vertex = queue.begin()->second;
		auto step = queue.begin()->first.step;
		queue.erase(queue.begin());

		for (const auto& edge : graph[vertex]) {
			if (step < number_steps && distances[edge.begin][step] + edge.weight < distances[edge.end][step + 1]) {
				queue.erase({ SteppedDistance{distances[edge.end][step + 1], step + 1}, edge.end });
				distances[edge.end][step + 1] = distances[edge.begin][step] + edge.weight;
				queue.insert({ SteppedDistance{distances[edge.end][step + 1], step + 1}, edge.end });
			}
		}
	}

	for (int i = 1; i < number_vertices + 1; ++i) {
		if (distances[i][number_steps] == kBig) {
			std::cout << -1 << '\n';
		} else {
			std::cout << distances[i][number_steps] << '\n';
		}
	} 
}

int main() {
	int number_vertices = 0;
	int number_edges = 0;
	int number_steps = 0;
	int begin = 0;

	std::cin >> number_vertices >> number_edges >> number_steps >> begin;

	std::vector<std::vector<Edge>> graph(number_vertices + 1);

	for (int i = 0; i < number_edges; ++i) {
		int begin = 0;
		int end = 0;
		int weight = 0;
		std::cin >> begin >> end >> weight;

		graph[begin].push_back(Edge{ begin, end, weight });
	}

	Dijkstra(number_vertices, graph, number_steps, begin);
	return 0;
}
