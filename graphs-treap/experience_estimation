#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

struct DSU {
	DSU(int number) {
		prev.resize(number);

		for (int i = 0; i < number; ++i) {
			prev[i] = i;
		}

		size.assign(number, 1);
		sum.assign(number, 0);
	}

	std::pair<int, int> GetSum(int v) {
		int w = v;
		int sum_0 = sum[v];
		while (w != prev[w]) {
			w = prev[w];
			sum_0 += sum[w];
		}

		int u_1 = v;
		int u_2 = u_1;
		int cur_sum = 0;
		int prev_sum = 0;
		while (u_1 != prev[u_1]) {
			prev_sum = sum[u_1];
			if (prev[u_1] != prev[prev[u_1]]) {
				sum[u_1] = sum_0 - cur_sum - sum[w];
				cur_sum += prev_sum;
			}

			u_2 = u_1;
			u_1 = prev[u_1];
			prev[u_2] = w;

		}

		return std::make_pair(w, (v != prev[v] ? sum[v] + sum[w] : sum[v]));
	}

	void Unite(int v, int u) {
		v = GetSum(v).first;
		u = GetSum(u).first;

		if (v == u) {
			return;
		}

		if (size[v] > size[u]) {
			std::swap(v, u);
		}

		prev[v] = u;
		size[u] = size[u] + size[v];
		sum[v] = sum[v] - sum[u];
	}

	void Add(int v, int el) {
		sum[GetSum(v).first] += el;

	}

	std::vector<int> prev;
	std::vector<int> size;
	std::vector<int> sum;
};

void Complete(int number_vertices, int number_questions) {
	DSU dsu(number_vertices + 1);

	std::string str;
	int first = 0;
	int second = 0;
	char task;
	for (int i = 0; i < number_questions; ++i) {
		std::getline(std::cin, str);
		task = str[0];
		str = str.substr(str.find(' ') + 1);
		if (task == 'g') {
			first = std::stoi(str);
			std::cout << dsu.GetSum(first).second << '\n';
		}
		else {
			first = std::stoi(str.substr(0, str.find(' ')));
			second = std::stoi(str.substr(str.find(' ') + 1));
			if (task == 'j') {
				dsu.Unite(first, second);
			}
			else {
				dsu.Add(first, second);
			}
		}
	}

}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int number_vertices = 0;
	int number_questions = 0;
	std::string str;

	std::getline(std::cin, str);

	number_vertices = std::stoi(str.substr(0, str.find(' ')));
	number_questions = std::stoi(str.substr(str.find(' ') + 1));

	Complete(number_vertices, number_questions);

	return 0;
}
