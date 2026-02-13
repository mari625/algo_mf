#include <iostream>
#include <vector>
#include <set>

struct Categories {
    std::set<int> income;
    std::set<int> outcome;
};

void DFS(const std::vector<Categories>& graph, int vertex_number,
    std::vector<char>& colour, std::vector<int>& answer) {
    colour[vertex_number] = 'g';

    for (auto& new_vertex_number : graph[vertex_number].outcome) {
        if (colour[new_vertex_number] == 'w') {
            DFS(graph, new_vertex_number, colour, answer);
        }
    }

    colour[vertex_number] = 'b';
    answer.push_back(vertex_number);
}

void FindCompany(std::vector<Categories>& graph, int vertex_number) {
    std::vector<char> colour(vertex_number, 'w');
    std::vector<int> answer;

    for (int i = 0; i < vertex_number; ++i) {
        if (colour[i] == 'w') {
            DFS(graph, i, colour, answer);
        }
    }

    int sink = answer[0];
    for (int i = 1; i < vertex_number; ++i) {
        if (graph[answer[i]].outcome.size() == 0) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    int used = 1;
    std::vector<int> candidates;
    while (used != vertex_number) {
        for (auto& v : graph[sink].income) {
            graph[v].outcome.erase(sink);
            if (graph[v].outcome.size() == 0) {
                candidates.push_back(v);
            }
        }

        if (candidates.size() != 1) {
            std::cout << "NO" << '\n';
            return;
        } else {
            sink = candidates[0];
            candidates.clear();
        }

        ++used;
    }

    std::cout << "YES" << '\n';
}

int main() {
    int vertex_number = 0;
    int edge_number = 0;

    std::cin >> vertex_number >> edge_number;

    std::vector<Categories> graph(vertex_number);

    for (int i = 0; i < edge_number; ++i) {
        int first = 0;
        int second = 0;
        std::cin >> first >> second;

        graph[first - 1].outcome.insert(second - 1);
        graph[second - 1].income.insert(first - 1);
    }

    FindCompany(graph, vertex_number);

    return 0;
}
