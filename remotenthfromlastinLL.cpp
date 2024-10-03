#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// Function to print the linked list
void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// Function to delete the Nth node
// from the end of the linked list
Node *DeleteNthNodefromEnd(Node *head, int N)
{
        Node *temp=head;
        int length=0;
        while(temp){
            length++;
            temp=temp->next;
        }
        if(length==N){
            return head->next;
        }
        int nth=length-N;
        temp=head;
        Node *prev=NULL;
        while(nth--){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    // Delete the Nth node from the end
    // and print the modified linked list
    head = DeleteNthNodefromEnd(head, N);
    printLL(head);
}
