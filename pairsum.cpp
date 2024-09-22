#include<bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        stack<int> st;
        ListNode *temp=head;
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }
        int n=st.size();
        temp=head;
        int sum=0,count=1;
        while (count<=n/2)
        {
            sum=max(sum,temp->val+st.top());
            count++;
            st.pop();
            temp=temp->next;
        }
        return sum;
    }
};

// Function to create a linked list from a vector of integers
ListNode *createLinkedList(const vector<int> &nums)
{
    if (nums.empty())
        return nullptr;

    ListNode *head = new ListNode(nums[0]);
    ListNode *current = head;
    for (size_t i = 1; i < nums.size(); ++i)
    {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

int main()
{
    // Read input values
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    // Create linked list from input values
    ListNode *head = createLinkedList(nums);

    // Calculate the maximum twin sum
    Solution solution;
    int result = solution.pairSum(head);

    // Print the result
    cout << result << endl;

    // Clean up linked list
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}