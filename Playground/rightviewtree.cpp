#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *create(int val)
{
    TreeNode *newNode = new TreeNode();
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode *insert(TreeNode *root, int val)
{
    if (root == NULL)
    {
        return create(val);
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        else
        {
            temp->left = create(val);
            return root;
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = create(val);
            return root;
        }
    }
    return root;
}

int maxLevel = -1;

void solveright(TreeNode *root, vector<int> &result, int height)
{
    if (root == NULL)
    {
        return;
    }

    if (height > maxLevel)
    {
        result.push_back(root->val);
        maxLevel++;
    }

    solveright(root->right, result, height + 1);
    solveright(root->left, result, height + 1);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> result;
    solveright(root, result, 0);
    return result;
}

void solveleft(TreeNode *root, vector<int> &result, int height)
{
    if (root == NULL)
    {
        return;
    }

    if (height > maxLevel)
    {
        result.push_back(root->val);
        maxLevel++;
    }

    solveleft(root->left, result, height + 1);
    solveleft(root->right, result, height + 1);
}

vector<int> leftview(TreeNode *root)
{
    vector<int> result;
    solveleft(root, result, 0);
    return result;
}

int main()
{

    TreeNode *root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->right = create(5);
    root->right->right = create(4);
    vector<int> rightresult = rightSideView(root);
    vector<int> leftresult = leftview(root);

    for (auto x : rightresult)
    {
        cout << x << " ";
    }

    for (auto x : leftresult)
    {
        cout << x << " ";
    }
}
