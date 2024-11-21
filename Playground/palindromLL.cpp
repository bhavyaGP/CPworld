// C++ program to check if a linked list is palindrome
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

// Function to reverse a linked list
Node *reverse(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *next;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to check if two lists are identical
bool isIdentical(Node *n1, Node *n2)
{
    for (; n1 && n2; n1 = n1->next, n2 = n2->next)
        if (n1->data != n2->data)
            return 0;

    // returning 1 if data at all nodes are equal.
    return 1;
}
bool isPalindrome(Node *head)
{

    if (!head)
    {
        return true;
    }
    vector<int> arr;
    Node *temp = head;
    while (temp)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    vector<int> rarr = arr;
    reverse(rarr.begin(), rarr.end());
    return (rarr == arr);
}

int main()
{

    // Linked list : 1->2->3->2->1
    Node head(1);
    head.next = new Node(2);
    head.next->next = new Node(3);
    head.next->next->next = new Node(2);
    head.next->next->next->next = new Node(1);

    bool result = isPalindrome(&head);

    if (result)
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
