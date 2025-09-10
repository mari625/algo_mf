#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
	int begin = 0;
	int end = 0;
	int weight = 0;

	bool operator==(const Edge& other) const {
		return weight == other.weight;
	}

	bool operator<(const Edge& other) const {
		return weight < other.weight;
	}
};

struct DSU {
	DSU(int number_) : number(number_) {
		prev.resize(number_);

		for (int i = 0; i < number_; ++i) {
			prev[i] = i;
		}

		size.assign(number_, 1);
	}

	int Get(int v) {
		return v == prev[v] ? v : prev[v] = Get(prev[v]);
	}

	bool Unite(int v, int u) {
		v = Get(v);
		u = Get(u);

		if (v == u) {
			return false;
		}

		if (size[v] > size[u]) {
			std::swap(v, u);
		}

		prev[v] = u;
		size[u] = size[u] + size[v];

		return true;
	}

	void Renew() {
		for (int i = 0; i < number; ++i) {
			prev[i] = i;
			size[i] = 1;
		}
	}

	bool Check() {
		for (int i = 2; i < number; ++i) {
			if (Get(1) != Get(i)) {
				return false;
			}
		}
		return true;
	}

	std::vector<int> prev;
	std::vector<int> size;
	int number = 0;
};

void Complete(int number_vertices, int number_edges, std::vector<Edge>& edges) {
	int min_dif = 2e9 + 5;

	if (number_edges < number_vertices - 1) {
		std::cout << "NO" << '\n';
		return;
	}

	DSU dsu(number_vertices + 1);
	std::sort(edges.begin(), edges.end());

	int first = 0;
	while (first != number_edges) {
		int min_weight = edges[first].weight;
		int max_weight = 0;

		for (int i = first; i < number_edges; ++i) {
			if (dsu.Unite(edges[i].begin, edges[i].end)) {
				max_weight = edges[i].weight;
			}
		}

		bool exist = dsu.Check();

		if (first ==  0 && exist == false) {
			std::cout << "NO" << '\n';
			return;
		}

		if (exist == true && min_dif > max_weight - min_weight) {
			min_dif = max_weight - min_weight;
		}

		dsu.Renew();

		++first;
	}

	std::cout << "YES" << '\n' << min_dif << '\n';
}

int main() {
	int number_vertices = 0;
	int number_edges = 0;

	std::cin >> number_vertices >> number_edges;

	std::vector<Edge> edges(number_edges);

	for (int i = 0; i < number_edges; ++i) {
		std::cin >> edges[i].begin >> edges[i].end >> edges[i].weight;
	}

	Complete(number_vertices, number_edges, edges);

	return 0;
}
