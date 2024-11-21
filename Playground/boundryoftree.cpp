#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

Node *buildTree()
{
    int data;
    cin >> data;

    if (data == -1)
        return nullptr;

    Node *root = newNode(data);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        int leftData, rightData;

        cin >> leftData;

        if (leftData != -1)
        {
            current->left = newNode(leftData);
            q.push(current->left);
        }

        cin >> rightData;

        if (rightData != -1)
        {
            current->right = newNode(rightData);
            q.push(current->right);
        }
    }

    return root;
}
void printLeaves(Node *root)
{
    if (root == nullptr)
        return;

    printLeaves(root->left);

    if (!(root->left) && !(root->right))
        cout << root->data << " ";

    printLeaves(root->right);
}
void printBoundaryLeft(Node *root)
{
    if (root == nullptr)
        return;

    if (root->left)
    {
        cout << root->data << " ";
        printBoundaryLeft(root->left);
    }
    else if (root->right)
    {
        cout << root->data << " ";
        printBoundaryLeft(root->right);
    }
}

void printBoundaryRight(Node *root)
{
    if (root == nullptr)
        return;

    if (root->right)
    {

        printBoundaryRight(root->right);
        cout << root->data << " ";
    }
    else if (root->left)
    {
        printBoundaryRight(root->left);
        cout << root->data << " ";
    }
}
void printBoundary(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    printBoundaryLeft(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printBoundaryRight(root->right);
}

int main()
{
    Node *root = buildTree();

    printBoundary(root);

    return 0;
}