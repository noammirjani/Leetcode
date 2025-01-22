#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

class Node {
public:
    virtual double evaluate() const = 0;
    virtual ~Node() = default;
};

class OperandNode : public Node {
    double value;
public:
    OperandNode(double val) : value(val) {}
    double evaluate() const override {
        return value;
    }
};

class OperatorNode : public Node {
    char op;
    std::unique_ptr<Node> left, right;
public:
    OperatorNode(char sign, std::unique_ptr<Node> l, std::unique_ptr<Node> r)
        : op(sign), left(std::move(l)), right(std::move(r)) {}
    double evaluate() const override {
        double l_val = left->evaluate();
        double r_val = right->evaluate();
        switch (op) {
            case '+': return l_val + r_val;
            case '-': return l_val - r_val;
            case '*': return l_val * r_val;
            case '/': return l_val / r_val;
            default: throw std::invalid_argument("Invalid operator");
        }
    }
};

int main() {
    auto left = std::make_unique<OperandNode>(3);
    auto right = std::make_unique<OperandNode>(4);
    auto root = std::make_unique<OperatorNode>('+', std::move(left), std::move(right));
    std::cout << "Result: " << root->evaluate() << std::endl; // Output: Result: 7
    std::cout << "Result: " << root->evaluate() << std::endl; // Output: Result: 7
    return 0;
}