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
int getheight(TreeNode *root)
{

    if (!root)
    {
        return 0;
    }
    int leftheight = getheight(root->left) + 1;
    int rightheight = getheight(root->right) + 1;

    return (max(leftheight, rightheight));
}
int main()
{
    TreeNode *root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);
    root->left->right->right = create(6);
    root->left->right->right->right = create(7);

    int height = getheight(root);
    cout << height;
}
