#include <iostream>
#include <string>
#include <set>
#include <cstdint>

struct Node {
    uint64_t value = 0;
    int priority = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    uint64_t sum = 0;

    Node(uint64_t value_) : value(value_), sum(value_) {
        priority = rand();
    }
};

uint64_t GetSum(Node* v) {
    if (v == nullptr) {
        return 0;
    }
    return v->sum;
}

uint64_t GetValue(Node* v) {
    if (v == nullptr) {
        return 0;
    }
    return v->value;
}

void RenewSum(Node* v) {
    if (v == nullptr) {
        return;
    }
    v->sum = GetSum(v->left) + v->value + GetSum(v->right);
}

std::pair<Node*, Node*> Split(Node* v, uint64_t key) {
    std::pair<Node*, Node*> result;
    if (v == nullptr) {
        result = { nullptr, nullptr };
    }
    else if (GetValue(v) <= key) {
        result = Split(v->right, key);
        v->right = result.first;
        result.first = v;
    } else {
        result = Split(v->left, key);
        v->left = result.second;
        result.second = v;
    }

    RenewSum(result.first);
    RenewSum(result.second);
    return result;
}

Node* Merge(Node* v_1, Node* v_2) {
    Node* result;
    if (v_1 == nullptr) {
        result = v_2;
    } else if (v_2 == nullptr) {
        result = v_1;
    } else if (v_1->priority < v_2->priority) {
        v_1->right = Merge(v_1->right, v_2);
        result = v_1;
    } else {
        v_2->left = Merge(v_1, v_2->left);
        result = v_2;
    }
    RenewSum(result);
    return result;
}

uint64_t Sum(Node* v, uint64_t left, uint64_t right) {
    std::pair<Node*, Node*> split_result_first = Split(v, left);
    std::pair<Node*, Node*> split_result_second = Split(split_result_first.second, right);
    uint64_t sum = GetSum(split_result_second.first);
    v = Merge(split_result_second.first, split_result_second.second);
    v = Merge(split_result_first.first, v);
    return sum;
}

int main() {
    int number = 0;

    std::string str;
    std::getline(std::cin, str);
    number = std::stoi(str);

    Node* root = nullptr;
    std::set<uint64_t> included;

    uint64_t last = 0;
    for (int i = 0; i < number; ++i) {
        std::getline(std::cin, str);
        if (str[0] == '+') {
            uint64_t value = (std::stoi(str.substr(1)) + last) % 1'000'000'000;
            last = 0;

            if (included.find(value) == included.end()) {
                std::pair<Node*, Node*> split_result = Split(root, value);
                root = Merge(split_result.first, new Node{ value });
                root = Merge(root, split_result.second);
                
                included.insert(value);
            }
        } else {
            str = str.substr(str.find(' ') + 1);
            uint64_t left = std::stoi (str.substr(0, str.find(' ')));
            uint64_t right = std::stoi(str.substr(str.find(' ') + 1));
            
            if (left > 0) {
                left -= 1;
            }
            
            if (left > right) {
                last = 0;
            } else {
                last = Sum(root, left, right);
            }
            
            std::cout << last << '\n';
        }
    }
}
