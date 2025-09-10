#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

struct Edge {
	int begin = 0;
	int end = 0;
};

struct SourcedVertex {
	int vertex = 0;
	int source = 0;
};

void BFS(int number_vertices, const std::vector <std::vector<Edge>>& graph, int number_exits, const std::vector<int>& exits) {
	std::vector<char> visited(number_vertices, '0');
	std::vector<int> distance(number_vertices, 0);
	std::vector<int> source(number_vertices, 0);
	std::queue<SourcedVertex> neighbours;

	for (int exit : exits) {
		neighbours.push(SourcedVertex{ exit, exit });
		source[exit] = exit;
		visited[exit] = '1';
	}

	while (!neighbours.empty()) {
		SourcedVertex current = neighbours.front();
		neighbours.pop();

		for (const Edge& edge : graph[current.vertex]) {
			if (visited[edge.end] == '0') {
				neighbours.push(SourcedVertex{ edge.end, current.source });
				distance[edge.end] = distance[current.vertex] + 1;
				source[edge.end] = current.source;
				visited[edge.end] = '1';
			}
		}
	}

	for (int i = 1; i < number_vertices; ++i) {
		std::cout << distance[i] << " ";
	}
	std::cout << '\n';

	for (int i = 1; i < number_vertices; ++i) {
		std::cout << source[i] << " ";
	}
	std::cout << '\n';
}

int main() {
	int number_vertices = 0;
	int number_exits = 0;
	std::cin >> number_vertices >> number_exits;
	++number_vertices;
	
	std::vector<int> exits(number_exits);

	for (int i = 0; i < number_exits; ++i) {
		std::cin >> exits[i];
	}

	std::sort(exits.begin(), exits.end());

	int number_edges = 0;
	std::cin >> number_edges;

	std::vector<std::vector<Edge>> graph(number_vertices);

	for (int i = 0; i < number_edges; ++i) {
		int begin = 0;
		int end = 0;
		std::cin >> begin >> end;

		graph[begin].push_back(Edge{ begin, end });
		graph[end].push_back(Edge{ end, begin });
	}

	BFS(number_vertices, graph, number_exits, exits);
	return 0;
}
