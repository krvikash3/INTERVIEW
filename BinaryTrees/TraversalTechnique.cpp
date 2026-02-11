#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> lot;
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

    void recursiveLevelOrderTraversal(TreeNode *root)
    {
        lot.clear();
        if (root == NULL)
            return;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
                level.push_back(node->data);
            }
            lot.push_back(level);
        }
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

    void levelorder(TreeNode *root)
    {
        result.clear();
        recursiveLevelOrderTraversal(root);
    }

    // get vector
    vector<vector<int>> getLevelResult()
    {
        return lot;
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

    vector<int> res = tree.getResult();
    vector<vector<int>> ans = tree.getLevelResult();
    // Print Nodes->>>
    for (int el : res)
    {
        cout << el << " ";
    }

    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
        {
            cout << ans[i][j] << " ";
        }
    }

    return 0;
}