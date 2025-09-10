#include <iostream>
#include <stack>

std::string Check(const std::string& sequence) {
    std::stack<char> container;

    for (char symbol: sequence) {
        if (symbol == '(' || symbol == '[' || symbol == '{') {
            container.push(symbol);
        } else if (symbol == ')' || symbol == '}' || symbol == ']'){
            if (container.empty()) {
                return "NO";
            }

            if ((symbol == ')' && container.top() != '(') || (symbol == ']' && container.top() != '[') || (symbol == '}' && container.top() != '{')) {
                return "NO";
            }

            
            container.pop();
        }
    }

    if (!container.empty()) {
        return "NO";
    }
    
    return "YES";
}

int main() {
    std::string sequence;

    std::cin >> sequence;

    std::cout << Check(sequence) << '\n';
    return 0;
}
