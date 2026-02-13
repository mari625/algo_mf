#include <iostream>
#include <vector>
#include <string>

struct DSU {
	DSU(int number) {
		prev.resize(number);
		next.resize(number + 1);

		for (int i = 0; i < number; ++i) {
			prev[i] = i;
			next[i] = i;
		}

		size.resize(number);
	}

	int Get(int v) {
		return v == prev[v] ? v : prev[v] = Get(prev[v]);
	}

	void Unite(int v, int u) {
		v = Get(v);
		u = Get(u);

		if (v == u) {
			return;
		}

		if (size[v] > size[u]) {
			std::swap(v, u);
		}

		prev[v] = u;
		size[u] = size[v] + size[u];
	}

	void UniteInterval(int v, int u) {
		int w = v;
		while (w <= u) {
			Unite(v, w);

			if (next[w] == w) {
				++next[w];
			}
			w = next[w];
		}

		int u_1 = v;
		int u_2 = u_1;
		while (u_1 < w) {
			u_1 = next[u_1];
			next[u_2] = w;
			u_2 = u_1;
		}
	}

	std::vector<int> prev;
	std::vector<int> size;
	std::vector<int> next;
};

void Complete(int number_vertices, int number_questions) {
	DSU dsu(number_vertices + 1);
	
	int task = 0;
	int first = 0;
	int second = 0;
	for (int i = 0; i < number_questions; ++i) {
		std::cin >> task >> first >> second;
		if (task == 1) {
			dsu.Unite(first, second);
		} else if (task == 2) {
			dsu.UniteInterval(first, second);
		} else {
			if (dsu.Get(first) == dsu.Get(second)) {
				std::cout << "YES" << '\n';
			} else {
				std::cout << "NO" << '\n';
			}
		}
	}
}

int main() {
	int number = 0;
	int number_questions = 0;

	std::cin >> number >> number_questions;

	Complete(number, number_questions);

	return 0;
}
