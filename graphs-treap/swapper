#include <iostream>
#include <string>
#include <set>
#include <cstdint>

struct Node {
    int64_t value = 0;
    int priority = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    int64_t sum = 0;
    int64_t size = 1;

    Node(int64_t value_) : value(value_), sum(value_) {
        priority = rand();
    }
};

int64_t GetSum(Node* v) {
    if (v == nullptr) {
        return 0;
    }
    return v->sum;
}

int64_t GetValue(Node* v) {
    if (v == nullptr) {
        return 0;
    }
    return v->value;
}

int64_t GetSize(Node* v) {
    if (v == nullptr) {
        return 0;
    }
    return v->size;
}

void RenewSum(Node* v) {
    if (v == nullptr) {
        return;
    }
    v->sum = GetSum(v->left) + v->value + GetSum(v->right);
}

void RenewSize(Node* v) {
    if (v == nullptr) {
        return;
    }
    v->size = GetSize(v->left) + 1 + GetSize(v->right);
}

std::pair<Node*, Node*> Split(Node* v, int64_t number) {
    std::pair<Node*, Node*> result;
    if (v == nullptr) {
        result = { nullptr, nullptr };
    }
    else if (GetSize(v->left) + 1 <= number) {
        result = Split(v->right, number - GetSize(v->left) - 1);
        v->right = result.first;
        result.first = v;
    }
    else {
        result = Split(v->left, number);
        v->left = result.second;
        result.second = v;
    }

    RenewSum(result.first);
    RenewSum(result.second);
    RenewSize(result.first);
    RenewSize(result.second);
    return result;
}

Node* Merge(Node* v_1, Node* v_2) {
    Node* result;
    if (v_1 == nullptr) {
        result = v_2;
    }
    else if (v_2 == nullptr) {
        result = v_1;
    }
    else if (v_1->priority < v_2->priority) {
        v_1->right = Merge(v_1->right, v_2);
        result = v_1;
    }
    else {
        v_2->left = Merge(v_1, v_2->left);
        result = v_2;
    }
    RenewSum(result);
    RenewSize(result);
    return result;
}

int64_t Sum(Node* even_root, Node* odd_root, int64_t left, int64_t right) {
    int number_odd_elems = (right - left + 1) / 2;
    int number_even_elems = (right - left + 1) / 2;

    if ((right - left) % 2 == 0) {
        if (left % 2 == 0) {
            ++number_even_elems;
        }
        else {
            ++number_odd_elems;
        }
    }

    std::pair<Node*, Node*> split_result_first = Split(odd_root, left / 2);
    std::pair<Node*, Node*> split_result_second = Split(split_result_first.second, number_odd_elems);

    int64_t sum = GetSum(split_result_second.first);

    odd_root = Merge(split_result_second.first, split_result_second.second);
    odd_root = Merge(split_result_first.first, odd_root);

    split_result_first = Split(even_root, (left - 1) / 2);
    split_result_second = Split(split_result_first.second, number_even_elems);

    sum += GetSum(split_result_second.first);

    even_root = Merge(split_result_second.first, split_result_second.second);
    even_root = Merge(split_result_first.first, even_root);
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int number = 0;
    int number_questions = 0;
    int counter = 1;

    std::cin >> number >> number_questions;
    while (number != 0) {
        if (counter != 1) {
            std::cout << '\n';
        }

        Node* even_root = nullptr;
        Node* odd_root = nullptr;

        std::cout << "Swapper " << counter << ":" << '\n';

        int64_t element = 0;
        for (int i = 0; i < number; ++i) {
            std::cin >> element;
            if (i % 2 == 1) {
                even_root = Merge(even_root, new Node{ element });
            }
            else {
                odd_root = Merge(odd_root, new Node{ element });
            }
        }

        int task = 0;
        int64_t left = 0;
        int64_t right = 0;
        int64_t sum = 0;
        for (int i = 0; i < number_questions; ++i) {
            std::cin >> task >> left >> right;
            if (task == 1) {
                std::pair<Node*, Node*> split_result_first_odd = Split(odd_root, left / 2);
                std::pair<Node*, Node*> split_result_second_odd = Split(split_result_first_odd.second, (right - left + 1) / 2);

                std::pair<Node*, Node*> split_result_first_even = Split(even_root, (left - 1) / 2);
                std::pair<Node*, Node*> split_result_second_even = Split(split_result_first_even.second, (right - left + 1) / 2);

                even_root = Merge(split_result_second_odd.first, split_result_second_even.second);
                even_root = Merge(split_result_first_even.first, even_root);

                odd_root = Merge(split_result_second_even.first, split_result_second_odd.second);
                odd_root = Merge(split_result_first_odd.first, odd_root);
            } else {
               int number_odd_elems = (right - left + 1) / 2;
               int number_even_elems = (right - left + 1) / 2;

               if ((right - left) % 2 == 0) {
                  if (left % 2 == 0) {
                      ++number_even_elems;
                  } else {
                      ++number_odd_elems;
                  }
               }

               std::pair<Node*, Node*> split_result_first = Split(odd_root, left / 2);
               std::pair<Node*, Node*> split_result_second = Split(split_result_first.second, number_odd_elems);

               sum = GetSum(split_result_second.first);

               odd_root = Merge(split_result_second.first, split_result_second.second);
               odd_root = Merge(split_result_first.first, odd_root);
               
               split_result_first = Split(even_root, (left - 1) / 2);
               split_result_second = Split(split_result_first.second, number_even_elems);

               sum += GetSum(split_result_second.first);

               even_root = Merge(split_result_second.first, split_result_second.second);
               even_root = Merge(split_result_first.first, even_root);
 
               std::cout << sum << '\n';
               sum = 0;
            }
        }

        ++counter;

        std::cin >> number >> number_questions;
    }
    return 0;
}
