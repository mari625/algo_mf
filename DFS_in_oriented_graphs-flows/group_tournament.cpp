#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

const int INF = 1e9;

struct Edge {
	int begin = 0;
	int end = 0;
	int capacity = 0;

	int number_a = -1;
	int number_b = -1;

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

void FordFulkerson(int number_vertices, std::vector<std::vector<int>>& graph, std::vector<Edge>& edges, std::vector<std::vector<char>>& matches) {
	int start = number_vertices * (number_vertices + 1) / 2;
	int finish = number_vertices * (number_vertices + 1) / 2 + 1;

	std::vector<char> used(number_vertices * (number_vertices + 1) / 2 + 2, '0');

	while (DFS(start, finish, INF, used, graph, edges)) {
		used.assign(number_vertices * (number_vertices + 1) / 2 + 2, '0');
	}
	used.assign(number_vertices * (number_vertices + 1) / 2 + 2, '0');

	int answer = 0;

	for (int vertex : graph[number_vertices * (number_vertices + 1) / 2]) {
		answer += edges[vertex].flow;
	}

	for (size_t i = 0; i < edges.size(); ++i) {
		if (edges[i].flow >= 0 && edges[i].begin < number_vertices && edges[i].number_a != -1) {
			if (edges[i].flow == 3) {
				matches[edges[i].number_a][edges[i].number_b] = 'W';
				matches[edges[i].number_b][edges[i].number_a] = 'L';
			}
			else if (edges[i].flow == 2) {
				matches[edges[i].number_a][edges[i].number_b] = 'w';
				matches[edges[i].number_b][edges[i].number_a] = 'l';
			}
			else if (edges[i].flow == 1) {
				matches[edges[i].number_a][edges[i].number_b] = 'l';
				matches[edges[i].number_b][edges[i].number_a] = 'w';
			}
			else {
				matches[edges[i].number_a][edges[i].number_b] = 'L';
				matches[edges[i].number_b][edges[i].number_a] = 'W';
			}

		}
	}

	for (int i = 0; i < number_vertices; ++i) {
		for (int j = 0; j < number_vertices; ++j) {
			std::cout << matches[i][j];
		}
		std::cout << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int number_vertices = 0;

	std::cin >> number_vertices;

	std::vector<std::vector<int>> graph(number_vertices * (number_vertices + 1) / 2 + 2);
	std::vector<Edge> edges;

	std::vector<std::vector<char>> matches(number_vertices, std::vector<char>(number_vertices));

	for (int i = 0; i < number_vertices; ++i) {
		for (int j = 0; j < number_vertices; ++j) {
			std::cin >> matches[i][j];
		}
	}

	std::vector<int> results(number_vertices);

	for (int i = 0; i < number_vertices; ++i) {
		std::cin >> results[i];
	}

	for (int i = 0; i < number_vertices; ++i) {
		for (int j = i + 1; j < number_vertices; ++j) {
			if (matches[i][j] != '.') {
				if (matches[i][j] == 'W') {
					results[i] -= 3;
				}
				if (matches[i][j] == 'w') {
					results[i] -= 2;
					results[j] -= 1;
				}
				if (matches[i][j] == 'l') {
					results[i] -= 1;
					results[j] -= 2;
				}
				if (matches[i][j] == 'L') {
					results[j] -= 3;
				}
			}
		}
	}

	for (int i = 0; i < number_vertices; ++i) {
		// from begin to player
		edges.push_back(Edge{ number_vertices * (number_vertices + 1) / 2, i, results[i] });
		graph[number_vertices * (number_vertices + 1) / 2].push_back(static_cast<int>(edges.size() - 1));
		edges.push_back(Edge{ i, number_vertices * (number_vertices + 1) / 2, 0 });
		graph[i].push_back(static_cast<int>(edges.size() - 1));
	}


	for (int i = 0; i < number_vertices; ++i) {
		for (int j = i + 1; j < number_vertices; ++j) {
			if (matches[i][j] == '.') {
				//from game to end
				edges.push_back(Edge{ (number_vertices - 1) * (i + 1) - (i * (i + 1)) / 2 + j, number_vertices * (number_vertices + 1) / 2 + 1, 3, i, j });
				graph[(number_vertices - 1) * (i + 1) - (i * (i + 1)) / 2 + j].push_back(static_cast<int>(edges.size() - 1));
				edges.push_back(Edge{ number_vertices * (number_vertices + 1) / 2 + 1,(number_vertices - 1) * (i + 1) - (i * (i + 1)) / 2 + j, 0, i, j });
				graph[number_vertices * (number_vertices + 1) / 2 + 1].push_back(static_cast<int>(edges.size() - 1));

				//from first player to game
				edges.push_back(Edge{ i, (number_vertices - 1) * (i + 1) - (i * (i + 1)) / 2 + j, 3, i, j });
				graph[i].push_back(static_cast<int>(edges.size() - 1));
				edges.push_back(Edge{ (number_vertices - 1) * (i + 1) - (i * (i + 1)) / 2 + j, i, 0, i, j });
				graph[(number_vertices - 1) * (i + 1) - (i * (i + 1)) / 2 + j].push_back(static_cast<int>(edges.size() - 1));

				//from second player to game
				edges.push_back(Edge{ j, (number_vertices - 1) * (i + 1) - (i * (i + 1)) / 2 + j, 3, j, i });
				graph[j].push_back(static_cast<int>(edges.size() - 1));
				edges.push_back(Edge{ (number_vertices - 1) * (i + 1) - (i * (i + 1)) / 2 + j, j, 0, j, i });
				graph[(number_vertices - 1) * (i + 1) - (i * (i + 1)) / 2 + j].push_back(static_cast<int>(edges.size() - 1));
			}
		}
	}

	FordFulkerson(number_vertices, graph, edges, matches);

	return 0;
}
