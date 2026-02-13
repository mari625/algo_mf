#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
#include <algorithm>

struct Edge {
	int begin = 0;
	int end = 0;
	char weight;
};

struct Char {
	char weight;
	int vertex;
	size_t priority;
	int prev;

	bool operator==(const Char& other) const {
		return weight == other.weight && vertex == other.vertex && priority == other.priority && prev == other.prev;
	}

	bool operator<(const Char& other) const {
		if (weight == other.weight) {
			return priority < other.priority;
		}

		return weight < other.weight;
	}
};

void BFS(int number_vertices, int number_edges, const std::vector<std::vector<Edge>>& graph) {
	std::vector<int> distances(number_vertices + 1, 0);
	std::vector<int> previous(number_vertices + 1, 0);
	std::vector<char> visited(number_vertices + 1, '0');
	std::vector<char> symbol_distances(number_vertices + 1, ' ');
	distances[number_vertices] = 0;
	symbol_distances[number_vertices] = ' ';

	std::vector<Char> neighbours(number_vertices + number_edges + 1);
	std::vector<Char> queue(number_vertices + number_edges + 1);

	neighbours[0].weight = ' ';
	neighbours[0].vertex = number_vertices;
	neighbours[0].priority = 1;
	neighbours[0].prev = 0;

	size_t length = 1;
	while (length != 0) {
		for (int i = 0; i < length; ++i) {
			queue[i] = neighbours[i];
		}

		std::sort(queue.begin(), queue.begin() + length);

		size_t queue_length = length;
		length = 0;
		size_t position = 0;
		while (position != queue_length) {
			if (visited[queue[position].vertex] == '0') {
				for (const auto& edge : graph[queue[position].vertex]) {
					if (visited[edge.end] == '0') {
						if (length > neighbours.size()) {
							neighbours.resize(neighbours.size() * 2);
							queue.resize(queue.size() * 2);
						}

						neighbours[length].weight = edge.weight;
						neighbours[length].vertex = edge.end;
						neighbours[length].priority = position;
						neighbours[length].prev = queue[position].vertex;
						++length;
					}
				}

				previous[queue[position].vertex] = queue[position].prev;
				distances[queue[position].vertex] = distances[queue[position].prev] + 1;
				symbol_distances[queue[position].vertex] = queue[position].weight;
				visited[queue[position].vertex] = '1';
			}
			++position;
		}
	}

	int current = 1;
	std::vector<int> path(distances[1]);
	path[0] = 1;

	int counter = 1;
	while (current != number_vertices) {
		current = previous[current];
		path[counter] = current;
		++counter;
	}

	std::cout << path.size() - 1 << '\n';

	for (size_t i = 0; i < path.size(); ++i) {
		std::cout << path[i] << " ";
	}
	std::cout << '\n';

	for (size_t i = 0; i < path.size() - 1; ++i) {
		std::cout << symbol_distances[path[i]];
	}
	std::cout << '\n';
}

int main() {
	int number_vertices = 0;
	int number_edges = 0;

	std::cin >> number_vertices >> number_edges;

	std::vector<std::vector<Edge>> graph(number_vertices + 1);

	for (int i = 0; i < number_edges; ++i) {
		int begin = 0;
		int end = 0;
		char weight;
		std::cin >> begin >> end >> weight;

		graph[begin].push_back(Edge{ begin, end, weight });
		graph[end].push_back(Edge{ end, begin, weight });
	}

	BFS(number_vertices, number_edges, graph);
	return 0;
}
