#include "ExpressionTree.h"
#include <iostream>
#include <sstream>                  // stringstream: splits the tokens
#include <stack>                    // std::stack: Week 4's Stack, any type
#include <stdexcept>                // runtime_error
using namespace std;

bool isOperator(const string& token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

// ============================ Q8 ============================
ExprNode* buildFromPostfix(const string& postfix)
{
    stack<ExprNode*> st;            // holds finished subtrees
    stringstream ss(postfix);
    string token;
    while (ss >> token) {           // one token at a time: "3", "4", "+"
        ExprNode* node = new ExprNode;
        node->data  = token;
        node->left  = nullptr;
        node->right = nullptr;

        if (isOperator(token)) {
            if (st.size() < 2) {    // "3 +" -> not enough operands
                delete node;
                while (!st.empty()) { destroyExpr(st.top()); st.pop(); }
                throw runtime_error("Invalid postfix expression");
            }
            node->right = st.top(); st.pop();   // first pop = right operand
            node->left  = st.top(); st.pop();   // second pop = left operand
        }
        st.push(node);
    }
    if (st.size() != 1) {           // "3 4" -> operands left over
        ExprNode* result = st.empty() ? nullptr : st.top();
        while (!st.empty()) { destroyExpr(st.top()); st.pop(); }
        (void)result;
        throw runtime_error("Invalid postfix expression");
    }
    return st.top();
}

void printPrefix(const ExprNode* node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";      // operator first: Polish notation
    printPrefix(node->left);
    printPrefix(node->right);
}

void printPostfix(const ExprNode* node)
{
    if (node == nullptr)
        return;
    printPostfix(node->left);
    printPostfix(node->right);
    cout << node->data << " ";      // operator last: reverse Polish
}

// ============================ Q9 ============================
void printInfix(const ExprNode* node)
{
    if (node == nullptr)
        return;
    if (!isOperator(node->data)) {  // leaf: a number
        cout << node->data;
        return;
    }
    cout << "(";
    printInfix(node->left);
    cout << " " << node->data << " ";
    printInfix(node->right);
    cout << ")";
}

double evaluate(const ExprNode* node)
{
    if (node == nullptr)
        throw runtime_error("Empty expression");

    if (!isOperator(node->data))
        return stod(node->data);    // leaf: convert the text to a number

    double leftValue  = evaluate(node->left);   // postorder: children first
    double rightValue = evaluate(node->right);

    if (node->data == "+") return leftValue + rightValue;
    if (node->data == "-") return leftValue - rightValue;
    if (node->data == "*") return leftValue * rightValue;

    // node->data == "/"
    if (rightValue == 0.0)
        throw runtime_error("Division by zero");
    return leftValue / rightValue;
}

void destroyExpr(ExprNode* node)
{
    if (node == nullptr)
        return;
    destroyExpr(node->left);
    destroyExpr(node->right);
    delete node;
}
