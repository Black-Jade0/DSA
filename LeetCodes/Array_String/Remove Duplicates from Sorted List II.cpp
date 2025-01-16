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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }
        ListNode *prev = new ListNode(-101, head);
        ListNode *temp = head;
        while (temp && temp->next)
        {
            ListNode *forward = temp->next;
            if (forward->val > temp->val)
            {
                prev = temp;
                temp = temp->next;
            }
            else
            {
                while (forward && forward->val == temp->val)
                {
                    forward = forward->next;
                }
                prev->next = forward;
                if (temp == head)
                {
                    head = forward;
                }
                temp = forward;
            }
        }
        return head;
    }
};

int main()
{

    return 0;
}