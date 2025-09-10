#include <iostream>
#include <vector>
#include <iomanip>

struct Edge {
	int begin = 0;
	int end = 0;
	double weight = 0;
	int number = 0;
};

bool BellmanFordCheck(int number_vertices, const std::vector<Edge>& edges, double value) {
	const double kBig = 2e6;
	std::vector<double> distances(number_vertices + 1, kBig);
	distances[0] = 0;

	for (int i = 0; i < number_vertices - 1; ++i) {
		for (auto& edge : edges) {
			if (distances[edge.begin] != kBig && distances[edge.begin] + edge.weight - value < distances[edge.end]) {
				distances[edge.end] = distances[edge.begin] + edge.weight - value;
			}
		}
	}

	for (auto& edge : edges) {
		if (distances[edge.begin] != kBig && distances[edge.begin] + edge.weight - value < distances[edge.end]) {
			return true;
		}
	}

	return false;
}

void BellmanFordAnswer(int number_vertices, const std::vector<Edge>& edges, double value, std::vector<int>& prev) {
	const double kBig = 2e6;
	std::vector<double> distances(number_vertices + 1, kBig);
	distances[0] = 0;

	std::vector<int> prev_edges(number_vertices + 1, 0);

	for (int i = 0; i < number_vertices - 1; ++i) {
		for (auto& edge : edges) {
			if (distances[edge.begin] != kBig && distances[edge.begin] + edge.weight - value < distances[edge.end]) {
				distances[edge.end] = distances[edge.begin] + edge.weight - value;
				prev[edge.end] = edge.begin;
				prev_edges[edge.end] = edge.number;
			}
		}
	}

	if (number_vertices == 2) {
		prev_edges[0] = 1;
	}

	std::vector<bool> visited(number_vertices + 1, false);

	std::vector<int> answer;

	for (auto& edge : edges) {
		if (distances[edge.begin] != kBig && distances[edge.begin] + edge.weight - value < distances[edge.end]) {

			visited[edge.end] = true;

			int vertex = edge.begin;
			while (!visited[vertex]) {
				visited[vertex] = true;
				vertex = prev[vertex];
			}

			answer.push_back(vertex);

			int v = prev[vertex];
			while (v != vertex) {
				answer.push_back(v);
				v = prev[v];
			}

			std::cout << std::fixed << std::setprecision(11) << value << '\n';

			std::cout << answer.size() << '\n';

			for (int i = static_cast<int>(answer.size()) - 1; i >= 0; --i) {
				std::cout << prev_edges[answer[i]] << " ";
			}
			std::cout << '\n';

			return;
		}
	}
}

void FindCycle(int number_vertices, const std::vector<Edge>& edges) {
	std::vector<int> prev(number_vertices + 1, -1);

	const double kEps = 1e-10;
	double left = -2e6;
	double right = 2e6;
	double middle = 0;

	int start = 0;
	while (right - left > kEps) {
		middle = (right + left) / 2;
		if (!BellmanFordCheck(number_vertices, edges, middle)) {
			left = middle;
		}
		else {
			right = middle;
		}
	}

	BellmanFordAnswer(number_vertices, edges, right, prev);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int number_vertices = 0;
	int number_edges = 0;

	std::cin >> number_vertices >> number_edges;

	std::vector<Edge> edges(number_edges);

	for (int i = 0; i < number_edges; ++i) {
		std::cin >> edges[i].begin >> edges[i].end >> edges[i].weight;
		edges[i].number = i + 1;
	}

	for (int i = 1; i <= number_vertices; ++i) {
		edges.push_back(Edge{ 0, i, 0, 0 });
	}

	FindCycle(number_vertices, edges);

	return 0;
}
