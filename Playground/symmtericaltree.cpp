#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to check if two subtrees are mirror images of each other
bool isMirror(TreeNode *t1, TreeNode *t2)
{

    if (t1 == NULL && t2 == NULL)
    {
        return true;
    }
    if (t1 == NULL || t2 == NULL)
    {
        return false;
    }
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Function to check if the tree is symmetric
bool isSymmetric(TreeNode *root)
{
    return isMirror(root, root);
}

// Function to build the binary tree from level order input
TreeNode *buildTree(vector<string> &nodes)
{
    if (nodes.empty() || nodes[0] == "null")
        return nullptr;

    TreeNode *root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size())
    {
        TreeNode *curr = q.front();
        q.pop();

        // Left child
        if (i < nodes.size() && nodes[i] != "null")
        {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != "null")
        {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i];
    }

    TreeNode *root = buildTree(nodes);

    // Check if the tree is symmetric
    if (isSymmetric(root))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}