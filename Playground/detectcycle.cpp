#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
bool detectLoop(Node *head)
{
    // Brute force(O(n),O(n))
    //  unordered_map<Node *, int> mp;
    //  Node *temp = head;
    //  while (temp)
    //  {

    //     if (mp.find(temp) != mp.end())
    //     {
    //         return true;
    //     }
    //     mp[temp] = 1;
    //     temp = temp->next;
    // }
    // return false;

    // optimal (O(n),O(1))
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third;
    if (detectLoop(head))
    {
        cout << "Loop detected in the linked list." << endl;
    }
    else
    {
        cout << "No loop detected in the linked list." << endl;
    }
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}
