#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

class TreeOperations
{
private:
    vector<int> result;

    // Recursive Helpers
    void recusiveinorderHelper(TreeNode *root)
    {
        if (root == nullptr)
            return;
        recusiveinorderHelper(root->left);
        result.push_back(root->data);
        recusiveinorderHelper(root->right);
    }

    void recursivepreorderHelper(TreeNode *root)
    {
        if (root == nullptr)
            return;
        result.push_back(root->data);
        recursivepreorderHelper(root->left);
        recursivepreorderHelper(root->right);
    }

    void recursivepostorderHelper(TreeNode *root)
    {
        if (root == nullptr)
            return;
        recursivepostorderHelper(root->left);
        recursivepostorderHelper(root->right);
        result.push_back(root->data);
    }

public:
    //!!here Create Node->>

    TreeNode *createNode(int val)
    {
        TreeNode *newNode = new TreeNode();
        newNode->data = val;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    void inorder(TreeNode *root)
    {
        result.clear();
        recusiveinorderHelper(root);
    }

    void preorder(TreeNode *root)
    {
        result.clear();
        recursivepreorderHelper(root);
    }

    void postorder(TreeNode *root)
    {
        result.clear();
        recursivepostorderHelper(root);
    }
    // get vector
    vector<int> getResult()
    {
        return result;
    }
};

int main()
{
    TreeOperations tree;
    TreeNode *root = tree.createNode(1);
    root->left = tree.createNode(2);
    root->right = tree.createNode(3);
    root->left->left = tree.createNode(4);
    root->left->right = tree.createNode(5);

    tree.inorder(root);
    vector<int> res = tree.getResult();
    // Print Nodes->>>
    for (int el : res)
    {
        cout << el << " ";
    }

    return 0;
}