#include "BST.h"
#include "TreeUtils.h"
#include <iostream>
using namespace std;

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    destroy(root);                  // postorder delete of every node
}

// ============================ Q4 ============================
bool BST::insert(int value)
{
    bool inserted = false;
    root = insertInto(root, value, inserted);
    return inserted;
}

TreeNode* BST::insertInto(TreeNode* node, int value, bool& inserted)
{
    if (node == nullptr) {          // empty spot: the new node goes here
        inserted = true;
        return makeNode(value);
    }
    if (value < node->data)
        node->left = insertInto(node->left, value, inserted);
    else if (value > node->data)
        node->right = insertInto(node->right, value, inserted);
    // equal: duplicate, change nothing
    return node;                    // always return the subtree root
}

// ============================ Q5 ============================
bool BST::find(int value) const
{
    const TreeNode* current = root;
    while (current != nullptr) {
        if (value == current->data)
            return true;
        if (value < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return false;                   // every path ends in a return
}

bool BST::findMin(int& value) const
{
    if (root == nullptr)
        return false;
    const TreeNode* current = root;
    while (current->left != nullptr)
        current = current->left;    // leftmost node
    value = current->data;
    return true;
}

bool BST::findMax(int& value) const
{
    if (root == nullptr)
        return false;
    const TreeNode* current = root;
    while (current->right != nullptr)
        current = current->right;   // rightmost node
    value = current->data;
    return true;
}

// ============================ Q7 ============================
bool BST::remove(int value)
{
    bool removed = false;
    root = removeFrom(root, value, removed);
    return removed;
}

TreeNode* BST::removeFrom(TreeNode* node, int value, bool& removed)
{
    if (node == nullptr)
        return nullptr;             // not found: removed stays false

    if (value < node->data) {
        node->left = removeFrom(node->left, value, removed);
        return node;
    }
    if (value > node->data) {
        node->right = removeFrom(node->right, value, removed);
        return node;
    }

    // found it
    removed = true;

    if (node->left == nullptr && node->right == nullptr) {   // leaf
        delete node;
        return nullptr;
    }
    if (node->left == nullptr || node->right == nullptr) {   // one child
        TreeNode* child = (node->left != nullptr) ? node->left : node->right;
        delete node;
        return child;
    }

    // two children: take the inorder successor
    TreeNode* successor = node->right;
    while (successor->left != nullptr)
        successor = successor->left;
    node->data = successor->data;
    node->right = removeFrom(node->right, successor->data, removed);
    return node;
}

// ============================ wrappers ============================
void BST::preorder() const   { ::preorder(root); }
void BST::inorder() const    { ::inorder(root); }
void BST::postorder() const  { ::postorder(root); }
int  BST::height() const     { return ::height(root); }
bool BST::isBalanced() const { return ::isBalanced(root); }
bool BST::isEmpty() const    { return root == nullptr; }
