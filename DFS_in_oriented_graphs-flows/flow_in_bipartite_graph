#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1e9;

struct Edge {
	int begin = 0;
	int end = 0;
};

void DFS(int vertex, int number_vertices, std::vector<char>& used, std::vector<std::vector<Edge>>& graph, std::vector<int>& left_component, std::vector<int>& right_component) {
	used[vertex] = '1';

	for (auto& v : graph[vertex]) {
		if (used[v.end] == '0') {
			DFS(v.end, number_vertices, used, graph, left_component, right_component);
		}
	}

	if (vertex < number_vertices) {
		left_component.push_back(vertex);
	} else {
		right_component.push_back(vertex);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int number_vertices = 0;
	int number_edges = 0;

	std::cin >> number_vertices >> number_edges;

	std::vector<int> left(number_vertices);
	std::vector<int> right(number_vertices);

	int capacity = 0;
	for (int i = 0; i < number_vertices; ++i) {
		std::cin >> left[i];
	}

	for (int i = 0; i < number_vertices; ++i) {
		std::cin >> right[i];
	}

	std::vector<std::vector<Edge>> graph(2 * number_vertices);

	int begin = 0;
	int end = 0;
	for (int i = 0; i < number_edges; ++i) {
		std::cin >> begin >> end;
		--begin;
		--end;
		end += number_vertices;
		graph[begin].push_back(Edge{begin, end});
		graph[end].push_back(Edge{ end, begin });
	}

	std::vector<char> used(number_vertices * 2, '0');
	std::vector<std::vector<int>> left_components;
	std::vector<std::vector<int>> right_components;

	for (int i = 0; i < number_vertices * 2; ++i) {
		if (used[i] == '0') {
			std::vector<int> left_component;
			std::vector<int> right_component;

			DFS(i, number_vertices, used, graph, left_component, right_component);
			left_components.push_back(left_component);
			right_components.push_back(right_component);
		}
	}

	int max_flow = 0;
	int left_sum = 0;
	int right_sum = 0;

	for (size_t i = 0; i < left_components.size(); ++i) {
		left_sum = 0;
		for (size_t j = 0; j < left_components[i].size(); ++j) {
			left_sum += left[left_components[i][j]];
		}

		right_sum = 0;
		for (size_t j = 0; j < right_components[i].size(); ++j) {
			right_sum += right[right_components[i][j] - number_vertices];
		}

		max_flow += std::min(left_sum, right_sum);
	}

	std::cout << max_flow << '\n';

	return 0;
}
