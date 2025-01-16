#include <iostream>
#include <vector>

using namespace std;

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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head)
            return NULL;
        if (!head->next)
            return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;

        for (int i = 0; i < left - 1; i++)
            prev = prev->next;
        ListNode *curr = prev->next;

        for (int i = 0; i < right - left; i++)
        {
            ListNode *forw = curr->next;
            curr->next = forw->next;
            forw->next = prev->next;
            prev->next = forw;
        }
        return dummy->next;
    }
};

int main()
{
    ListNode *a = new ListNode(3);
    ListNode *b = new ListNode(5);
    a->next = b;
    b->next = NULL;
    ListNode *temp = a;
    while (temp)
    {
        cout << temp->val;
        temp = temp->next;
    }
    Solution sol;
    ListNode *result = sol.reverseBetween(a, 1, 1);
    while (result)
    {
        cout << result->val;
        result = result->next;
    }
    return 0;
}