#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

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

void FordFulkerson(int number_notes, std::vector<std::vector<int>>& graph, std::vector<Edge>& edges) {
	int start = 0;
	int finish = number_notes + 1;

	std::vector<char> used(number_notes + 2, '0');

	while (DFS(start, finish, INF, used, graph, edges)) {
		used.assign(number_notes + 2, '0');
	}
	used.assign(number_notes + 2, '0');

	int answer = 0;

	for (int vertex : graph[0]) {
		answer += edges[vertex].flow;
	}

	std::cout << answer << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int number_notes = 0;
	int low = 0;
	int high = 0;
	int length = 0;

	std::cin >> number_notes >> low >> high >> length;

	std::vector<std::vector<int>> graph(number_notes + 2);
	std::vector<Edge> edges;

	std::vector<int> song(length);

	for (int i = 0; i < length; ++i) {
		std::cin >> song[i];
	}

	for (int i = 1; i < low; ++i) {
		edges.push_back(Edge{ 0, i, INF });
		graph[0].push_back(static_cast<int>(edges.size() - 1));
		edges.push_back(Edge{ i, 0, 0 });
		graph[i].push_back(static_cast<int>(edges.size() - 1));
	}

	for (int i = high + 1; i <= number_notes; ++i) {
		edges.push_back(Edge{ i, number_notes + 1, INF });
		graph[i].push_back(static_cast<int>(edges.size() - 1));
		edges.push_back(Edge{ number_notes + 1, i, 0 });
		graph[number_notes + 1].push_back(static_cast<int>(edges.size() - 1));
	}

	for (int i = 0; i < length - 1; ++i) {
		int first = std::min(song[i], song[i + 1]);
		int second = std::max(song[i], song[i + 1]);
		if (first < low || second > high) {
			edges.push_back(Edge{ first, second, 1 });
			graph[first].push_back(static_cast<int>(edges.size() - 1));
			edges.push_back(Edge{ second, first, 0 });
			graph[second].push_back(static_cast<int>(edges.size() - 1));
		}
		else {
			edges.push_back(Edge{ song[i], song[i + 1], 1 });
			graph[song[i]].push_back(static_cast<int>(edges.size() - 1));
			edges.push_back(Edge{ song[i + 1], song[i], 0 });
			graph[song[i + 1]].push_back(static_cast<int>(edges.size() - 1));

			edges.push_back(Edge{ song[i], song[i + 1], 0 });
			graph[song[i]].push_back(static_cast<int>(edges.size() - 1));
			edges.push_back(Edge{ song[i + 1], song[i], 1 });
			graph[song[i + 1]].push_back(static_cast<int>(edges.size() - 1));
		}
	}

	FordFulkerson(number_notes, graph, edges);

	return 0;
}

