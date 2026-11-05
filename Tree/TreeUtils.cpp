#include "TreeUtils.h"
#include <iostream>
#include <queue>                    // std::queue: the library version of
#include <cstdlib>                  // std::abs
using namespace std;                // Week 4's Queue, for any type

TreeNode* makeNode(int value)
{
    TreeNode* node = new TreeNode;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// ============================ Q2 ============================
void preorder(const TreeNode* node)
{
    if (node == nullptr)            // base case first, always
        return;
    cout << node->data << " ";      // node
    preorder(node->left);           // left
    preorder(node->right);          // right
}

void inorder(const TreeNode* node)
{
    if (node == nullptr)
        return;
    inorder(node->left);            // left
    cout << node->data << " ";      // node
    inorder(node->right);           // right
}

void postorder(const TreeNode* node)
{
    if (node == nullptr)
        return;
    postorder(node->left);          // left
    postorder(node->right);         // right
    cout << node->data << " ";      // node
}

int countNodes(const TreeNode* node)
{
    if (node == nullptr)
        return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int countLeaves(const TreeNode* node)
{
    if (node == nullptr)
        return 0;
    if (node->left == nullptr && node->right == nullptr)
        return 1;                   // a leaf: no children
    return countLeaves(node->left) + countLeaves(node->right);
}

// ============================ Q3 ============================
int height(const TreeNode* node)
{
    if (node == nullptr)
        return -1;                  // empty tree
    int leftHeight  = height(node->left);
    int rightHeight = height(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void levelOrder(const TreeNode* node)
{
    if (node == nullptr)
        return;
    queue<const TreeNode*> q;
    q.push(node);
    while (!q.empty()) {
        const TreeNode* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left  != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}

// ============================ Q6 ============================
// Single postorder pass: returns the height, or -2 for "not balanced".
static int checkBalance(const TreeNode* node)
{
    if (node == nullptr)
        return -1;
    int leftHeight = checkBalance(node->left);
    if (leftHeight == -2)
        return -2;
    int rightHeight = checkBalance(node->right);
    if (rightHeight == -2)
        return -2;
    if (abs(leftHeight - rightHeight) > 1)
        return -2;
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isBalanced(const TreeNode* node)
{
    return checkBalance(node) != -2;
}

// ============================ memory ============================
void destroy(TreeNode* node)
{
    if (node == nullptr)
        return;
    destroy(node->left);            // children first ...
    destroy(node->right);
    delete node;                    // ... the node last (postorder)
}
